//
//  MAAssetPackage.h
//  MaaiiConnect_2.3
//
//  Created by Kevin Lo on 28/11/13.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface MAAssetPackage : NSManagedObject

@property (nonatomic, retain) NSString *category;
@property (nonatomic, retain) NSString *encryptedAssetsList;
@property (nonatomic, retain) UIImage *icon;
@property (nonatomic, retain) NSString *identifier;
@property (nonatomic, retain) NSDictionary *localizedNames;
@property (nonatomic, retain) NSNumber *sortOrder;
@property (nonatomic, retain) NSNumber *isBundled;
@property (nonatomic, retain) NSString *imageURL;
@property (nonatomic, retain) NSOrderedSet *assets;
@end

@interface MAAssetPackage (CoreDataGeneratedAccessors)

#pragma mark -  Core data generated headers
- (void)insertObject:(NSManagedObject *)value inAssetsAtIndex:(NSUInteger)idx;
- (void)removeObjectFromAssetsAtIndex:(NSUInteger)idx;
- (void)insertAssets:(NSArray *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeAssetsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInAssetsAtIndex:(NSUInteger)idx withObject:(NSManagedObject *)value;
- (void)replaceAssetsAtIndexes:(NSIndexSet *)indexes withAssets:(NSArray *)values;
- (void)addAssetsObject:(NSManagedObject *)value;
- (void)removeAssetsObject:(NSManagedObject *)value;
- (void)addAssets:(NSOrderedSet *)values;
- (void)removeAssets:(NSOrderedSet *)values;
@end
