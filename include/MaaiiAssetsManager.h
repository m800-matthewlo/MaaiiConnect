//
//  MaaiiAssetsManager.h
//  MaaiiConnect_2.3
//
//  Created by Kevin Lo on 26/11/13.
//
//

#import <Foundation/Foundation.h>
#import "MAAssetPackage.h"
#import "MAAsset.h"
#import "MAAssetContent.h"
#import "MaaiiAssetsManagerProtocol.h"

#pragma mark - MaaiiAssetsManager

/*!
 @class MaaiiAssetsManager
 
 @abstract
 The operation class for handling locally saved asset packages and assets.
 */
@interface MaaiiAssetsManager : NSObject

/*!
 @property
 
 @abstract
 Return the concret instance of MaaiiAssetParser for parsing the asset packages and assets. Refer to the protocol <MaaiiAssetParser> for more details.
 
 @discussion
 If this property is assigned a nil value, the getter will still return the default asset parser
 
 */
@property (nonatomic, strong) id<MaaiiAssetParser> assetParser;

/*!
 @property
 
 @abstract
 The context to store the MAAsset and MAAssetPackage. It will be 
 
 @discussion
 If this property is assigned a nil value, the getter will still return the default NSManagedObjectContext
 
 */
@property (nonatomic, strong) NSManagedObjectContext *storageContext;
@property (nonatomic, readonly) NSManagedObjectContext *workingContext;

/*!
 @property
 
 @abstract
 The file path for storing the downloaded files of assets contents
 
 */
@property (readonly, copy) NSString *pathForAssetContentDirectory;

/*!
 @method
 
 @abstract
 Return NSFetchedResultsController with an array of MAAssetPackage of the specified category for displaying as a list of reorderable items
 
 @param category
 The category of the required list of MAAssetPackage
 
 @return
 The NSFetchedResultsController with an array of MAAssetPackage of the specified category, sorted by "sortOrder" of each MAAssetPackage
 
 */
- (NSFetchedResultsController *)fetchedResultControllerForAssetPackagesWithCategory:(NSString *)cagtegory;

/*!
 @method
 
 @abstract
 Return MAAssetPackage with the speicifed identifier
 
 @param packageIdentifier
 The identifier of MAAssetPackage
 
 @return
 MAAssetPackage with the speicifed identifier
 
 */
- (MAAssetPackage *)assetPackageWithIdentifier:(NSString *)packageIdentifier;

/*!
 @method
 
 @abstract
 This method allow the sorting order of list of MAAssetPackage returned by the method "fetehcedResultControllerForAssetPackagesWithCategory:" to be changed
 
 @param package
 The MAAssetPackage to change it order
 
 @param index
 The destination index of the moved MAAssetPackage
 
 */
- (void)moveAssetPackage:(MAAssetPackage *)package
                 toIndex:(NSUInteger)index;

/*!
 @method
 
 @abstract
 Save the asset package with its contents to parse located at the specified local URL.
 
 @discussion
 The saved MAAssetPackage will be appended to the collection.
 
 @param packageDirecotryURL
 The file URL of the file to parse the MAAssetPackage
 
 @param localizedNames
 The key-value pair of the localized names of this package.
 The key is the ISO 639-1 language code of a language, and the value is the actual name string.
 
 @param imageURL
 The remote URL of the package image
 
 @param bundled
 The isBundled flag of the saved MAAssetPackage. 
 This is used to indicate whether this package is saved when the application first launch, or saved upon some events.
 
 */
- (void)saveAssetPackageWithContentAtURL:(NSURL *)packageDirecotryURL
                              identifier:(NSString *)identifier
                          localizedNames:(NSDictionary *)localizedNames
                                imageURL:(NSURL *)imageURL
                               isBundled:(BOOL)bundled;

/*!
 @method
 
 @abstract
 Save the asset package with its contents to parse according to the parased interface of MaaiiAssetPackage.
 
 @discussion
 The saved MAAssetPackage will be appended to the collection.
 
 @param dataSource
 The concret instance of MaaiiAssetPackage of the MAAssetPackage to be parsed
 
 @param identifier
 
 @param localizedNames
 The key-value pair of the localized names of this package.
 The key is the ISO 639-1 language code of a language, and the value is the actual name string.
 
 @param imageURL
 The remote URL of the package image
 
 @param bundled
 The isBundled flag of the saved MAAssetPackage.
 This is used to indicate whether this package is saved when the application first launch, or saved upon some events.
 
 */
- (void)saveAssetPackageWithDataSource:(id<MaaiiAssetPackage>)dataSource
                            identifier:(NSString *)identifier
                        localizedNames:(NSDictionary *)localizedNames
                              imageURL:(NSURL *)imageURL
                             isBundled:(BOOL)bundled;


/*!
 @method
 
 @abstract
 Remove the saved asset package for the specified category and identifier
 
 @discussion
 The sort order of each remaining MAAssetPackage will be updated accordingly.
 
 @param cagtegory
 The category of the MAAssetPackage to be removed
 
 @param identifier
 The identifier of the MAAssetPackage to be removed
 
 */
- (void)removeAssetPackageWithIdentifier:(NSString *)identifier;

/*!
 @method
 
 @abstract
 Remove the saved asset package for the specified category and identifier
 
 @param asset
 The MAAsset to check whether it is eligible to be shared
 
 @return
 Whether the asset is valid to be shared.
 
 */
- (BOOL)assetIsSharable:(MAAsset *)asset;

/*!
 @method
 
 @abstract
 Remove the all saved asset content
 
 */
- (void)clearAllDownloadedAssetContent;

#pragma mark - Assets content loading

- (MAAssetContent *)assetContentForCategory:(NSString *)category
                            assetIdentifier:(NSString *)assetIdentifier;

/*!
 @method
 
 @abstract
 Load the asset asynchronously.
 
 @discussion
 This method will take caching into account, for both in-memory and permanant storage. 
 Repeated calls to this method when the asset is not downloaded will not cause duplicated download request
 but either completionHandler or failureHandle is guaranteed to be called once for each call to this method.
 This method perform most task in background, but the completionHandler and failureHandler will be invoked on main queue.
 
 @param category
 The category of the required asset
 
 @param assetIdentifier
 The identifier of the required asset
 
 @param completion
 The block takes one argument. "assetContent": The content of the loaded assets. This block will be invoked on main queue.
 
 @param failure
 A block with an NSError instance for error handling. This block will be invoked on main queue.
 */
- (void)loadAssetContentForCategory:(NSString *)category
                    assetIdentifier:(NSString *)assetIdentifier
                  completionHandler:(void (^)(MAAssetContent *assetContent))completion
                     failureHandler:(void (^)(NSError *error))failure;

/*!
 @method
 
 @abstract
 Load the asset asynchronously.
 
 @discussion
 This method will take caching into account, for both in-memory and permanant storage.
 Repeated calls to this method when the asset is not downloaded will not cause duplicated download request
 but either completionHandler or failureHandle is guaranteed to be called once for each call to this method.
 This method perform most task in background, but the completionHandler and failureHandler will be invoked on main queue.
 If performFileValidationCheck is YES, file validation will be performed. If the file is invalid, it will be removed and re-downloaded.
 
 @param category
 The category of the required asset
 
 @param assetIdentifier
 The identifier of the required asset
 
 @param performFileValidationCheck
 Pass YES if file validation is required.
 
 @param completion
 The block takes one argument. "assetContent": The content of the loaded assets. This block will be invoked on main queue.
 
 @param failure
 A block with an NSError instance for error handling. This block will be invoked on main queue.
 */
- (void)loadAssetContentForCategory:(NSString *)category
                    assetIdentifier:(NSString *)assetIdentifier
         performFileValidationCheck:(BOOL)performFileValidationCheck
                  completionHandler:(void (^)(MAAssetContent *assetContent))completion
                     failureHandler:(void (^)(NSError *error))failure;

/*!
 @method
 
 @abstract Reset all the data in the asset manager
 
 */
- (void)resetAll;

#pragma mark - Delegate

- (void)addDelegate:(id<MaaiiAssetManagerDelegate>)delegate;

- (void)removeDelegate:(id<MaaiiAssetManagerDelegate>)delegate;

#pragma mark - Singleton

/*!
 @method
 
 @abstract Return the singleton instance of this class
 
 @return The singleton instance of this class
 
 */
+ (instancetype)sharedInstance;

@end
