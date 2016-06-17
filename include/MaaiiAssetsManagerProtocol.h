//
//  MaaiiAssetsManagerProtocol.h
//  MaaiiConnect_2.3
//
//  Created by Kevin Lo on 2/12/13.
//
//

#import <Foundation/Foundation.h>
@class MaaiiAssetsManager;
@class MAAssetPackage;
@class MAAssetContent;

@protocol MaaiiAssetPackage <NSObject>

@required

- (NSString *)identifier;
- (NSString *)category;
- (UIImage *)icon;
- (NSUInteger)numberOfAssets;
- (UIImage *)previewImageForAssetAtIndex:(NSUInteger)index;
- (NSString *)identifierForAssetAtIndex:(NSUInteger)index;

@end

@protocol MaaiiAssetContent <NSObject>

@required

- (NSString *)identifier;
- (UIImage *)previewImage;
- (NSString *)category;
- (NSDictionary *)manifest;

@end

@protocol MaaiiAssetParser <NSObject>

@required

- (id<MaaiiAssetContent>)assetContentAtURL:(NSURL *)directoryURL;
- (id<MaaiiAssetPackage>)assetPackageWithContentAtURL:(NSURL *)directoryURL;

@end

typedef enum : NSUInteger {
    MAAssetPackageRemovalReasonUserInvoked,
    MAAssetPackageRemovalReasonFileInvalid,
    MAAssetPackageRemovalReasonUnknown
} MAAssetPackageRemovalReason;

@protocol MaaiiAssetManagerDelegate <NSObject>

@optional
- (void)assetsManager:(MaaiiAssetsManager *)assetManager didSavePackage:(MAAssetPackage *)package;
- (void)assetsManager:(MaaiiAssetsManager *)assetManager didRemovePackageWithIdentifier:(NSString *)identifier removealReason:(MAAssetPackageRemovalReason)removalReason;
- (void)assetsManager:(MaaiiAssetsManager *)assetManager didDownloadAssetContent:(MAAssetContent *)content;

@end