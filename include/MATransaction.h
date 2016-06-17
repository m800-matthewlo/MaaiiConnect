//
//  MATransaction.h
//  MaaiiConnect_2.3
//
//  Created by Kevin Lo on 6/12/13.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class MAGiftee;
@class MAStoreItemCategory;

/*!
 @typedef
 
 @abstract The possible values of the state of MATransaction
 */
typedef enum {
    MATransactionStateInvalid = -1,
    MATransactionStateCheckedOut = 0,
    MATransactionStatePurchased = 1,
    MATransactionStateClaimed = 2,
    MATransactionStateDownloading = 3,
    MATransactionStateDownloaded = 4,
    MATransactionStateRestored = 5
} MATransactionState;

/*!
 @typedef
 
 @abstract The possible values of the productType of MATransaction
 */
typedef enum {
    MATransactionProductTypeUnknown = -1,
    MATransactionProductTypeFeature = 0,
    MATransactionProductTypeDownload = 1,
    MATransactionProductTypeMinute = 2
} MATransactionProductType;

@interface MATransaction : NSManagedObject

@property (nonatomic, retain) NSString * appStoreTransactionId;
@property (nonatomic, retain) NSNumber * isDownloaded;
@property (nonatomic, retain) NSDate * downloadDate;
@property (nonatomic, retain) NSString * downloadedContentPath;
@property (nonatomic, retain) NSString * itemId;
@property (nonatomic, retain) NSDictionary * localizedNames;
@property (nonatomic, retain) NSString * previewImagePath;
@property (nonatomic, retain) NSDate * purchaseDate;
@property (nonatomic, retain) NSString * receiptData;
@property (nonatomic, retain) NSNumber * state;
@property (nonatomic, retain) NSString * transactionId;
@property (nonatomic, retain) NSNumber * productType;
@property (nonatomic, retain) NSNumber * isPending;
@property (nonatomic, retain) NSNumber * isConsumable;
@property (nonatomic, retain) NSNumber * isOutgoingGift;
@property (nonatomic, retain) NSSet *categories;

@property (nonatomic, retain) MAGiftee *giftee;

@property (nonatomic, readonly) NSURL * previewImageURL;

@end

@interface MATransaction (CoreDataGeneratedAccessors)

- (void)addCategoriesObject:(MAStoreItemCategory *)value;
- (void)removeCategoriesObject:(MAStoreItemCategory *)value;
- (void)addCategories:(NSSet *)values;
- (void)removeCategories:(NSSet *)values;

@end
