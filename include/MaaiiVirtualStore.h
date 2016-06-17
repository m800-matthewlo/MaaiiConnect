//
//  MaaiiVirtualStore.h
//  MaaiiConnect_2.2
//
//  Created by Kevin Lo on 9/9/13.
//
//

#import <Foundation/Foundation.h>
#import "MAStoreItemCategory.h"
#import "MAStoreItem.h"
#import "MATransaction.h"
#import "MATransactionItemCategory.h"
#import "MAPreviewItemEnumerator.h"
#import "MaaiiVirtualStoreDelegate.h"
#import "MAGiftee.h"

typedef NS_ENUM(NSUInteger, MaaiiVirtualStoreCheckoutFailure) {
    MaaiiVirtualStoreCheckoutFailureUserCancelled,
    MaaiiVirtualStoreCheckoutFailureAppStoreRegionChanged,
    MaaiiVirtualStoreCheckoutFailureItemAlreadyOwned,
    MaaiiVirtualStoreCheckoutFailureInsufficientInformation,
    MaaiiVirtualStoreCheckoutFailureInvalidTransactionState,
    MaaiiVirtualStoreCheckoutFailurePermissionDenied,
    MaaiiVirtualStoreCheckoutFailureUnknown
};

/*!
 @class MaaiiVirtualStore
 
 @abstract
 The operation class of the whole Maaii virtual store front component, act as an interface for accessing store items and making purchases.
 */
@interface MaaiiVirtualStore : NSObject

/*!
 @property
 
 @abstract
 ISO language code which match with the ISO 639-1 standard. This is for sending request to the server to request for localized content
 
 @discussion
 Special note: For simplified and traditional Chinese, the language code will be zh-cn and zh-tw respectively.
 */
@property (nonatomic, strong) NSString *langaugeISO;

/*!
 @property
 
 @abstract
 Only used for making unit testing. When this flag is enabled, some method will not access the IM and just return some hard coded data directly to make a method unitable.
 */
@property (nonatomic, assign) BOOL unitTesting;

/*!
 @property
 
 @abstract
 Only used for making functional testing. When this flag is enabled, the user (tester) will be prompted after making a successful payment.
 */
@property (nonatomic, assign) BOOL testFlagForPaidPurchase;

@property (nonatomic, strong, readonly) NSManagedObjectContext *workingContext;

/*!
 @method
 
 @abstract
 Query all the visible categories from the server
 
 @param completion A block with an instance of NSArray as paramater. The array is a collection of the MAStoreItemCategory instances of the queried category data
 @param failure A block with an NSError instance for error handling
 */
- (void)queryItemCategoriesWithCompletion:(void(^)(NSArray *itemCategories))completion
                                  failure:(void(^)(NSError *error))failure;

/*!
 @method
 
 @abstract
 Query a category with the specific identifier on demand
 
 @param completion A block with an instance of MAStoreItemCategory as the query result
 @param failure A block with an NSError instance for error handling
 */
- (void)queryItemCategoryWithIdentifier:(NSString *)identifier
                             completion:(void (^)(MAStoreItemCategory *))completion
                                failure:(void (^)(NSError *))failure;

/*!
 @method
 
 @abstract
 Query all the items of a specific category from the server
 
 @param categoryIdentifier
 The identifier of the required category
 
 @param offset
 The index from which you want to start query with, zero based.
 
 @param limit
 Amount of item fetched for this query from the offset
 
 @param completion
 The block takes three arguments. "items": An array of MAStoreItem instances "totalItemsCount": The total number of item in this category, including those which are not queried "invalidItemsCount": The number of the feteched item which appears to be invalid, i.e. Paid item but cannot find any information about it in iTune Connect
 
 @param failure A block with an NSError instance for error handling
 */
- (void)queryItemsForCategoryWithIdentifier:(NSString *)categoryIdentifier
                                     offset:(NSUInteger)offset
                                      limit:(NSUInteger)limit
                                 completion:(void(^)(NSArray *items, NSUInteger totalItemsCount, NSUInteger invalidItemsCount))completion
                                    failure:(void (^)(NSError *))failure;


/*!
 @method
 
 @abstract
 Query all the items of a specific category from the server
 
 @param categoryIdentifier
 The identifier of the required category
 
 @param offset
 The index from which you want to start query with, zero based.
 
 @param limit
 Amount of item fetched for this query from the offset
 
 @param intermediateResult
 The block is intermediate result of completion block, while the result of this block does not query Apple to improve response time.
 
 @param completion
 The block takes three arguments. "items": An array of MAStoreItem instances "totalItemsCount": The total number of item in this category, including those which are not queried "invalidItemsCount": The number of the feteched item which appears to be invalid, i.e. Paid item but cannot find any information about it in iTune Connect
 
 @param failure A block with an NSError instance for error handling
 */
- (void)queryItemsForCategoryWithIdentifier:(NSString *)categoryIdentifier
                                     offset:(NSUInteger)offset
                                      limit:(NSUInteger)limit
                         intermediateResult:(void(^)(NSArray *items, NSUInteger totalItemsCount, NSUInteger invalidItemsCount))intermediateResult
                                 completion:(void(^)(NSArray *items, NSUInteger totalItemsCount, NSUInteger invalidItemsCount))completion
                                    failure:(void (^)(NSError *))failure;

/*!
 @method
 
 @abstract
 Query the full details of a single item
 
 @discussion
 If the items is a paid item according to the server, but we cannot find any record in iTune Connect via StoreKit, this query request is regarded as a failure.
 
 @param itemIdentifier
 The identifier of the required category
 
 @param completion
 The block takes one argument. "item": The item.
 
 @param failure A block with an NSError instance for error handling
 */
- (void)queryDetailsForItemWithIdentifier:(NSString *)itemIdentifier
                               completion:(void(^)(MAStoreItem *item))completion
                                  failure:(void(^)(NSError *error))failure;

/*!
 @method
 
 @abstract
 Check out an item from server
 
 @discussion
 If the item is a paid item, we will go through an Apple in-app purchase procedure.
 On successful check out, we will also claim the item from server
 
 @param item
 The item to be checked out
 
 @param completion
 The block takes a boolean
 
 return YES to automatically trigger item download
 else return NO
 
 @param failure A block with an NSError instance for error handling
 */
- (void)checkoutItem:(MAStoreItem *)item
          completion:(BOOL(^)(MATransactionState state))completion
             failure:(void(^)(NSError *error, MaaiiVirtualStoreCheckoutFailure failureType))failure;

/*!
 @method
 
 @abstract
 Gift an item to a maaii user
 
 @discussion
 Only free items can be gifted.
 On successful check out, we will also claim the item from server
 
 @param item
 The item to be gifted
 
 @param jid
 The jid of the giftee
 
 @param completion
 The block takes a <MATransactionState> parameter, that reflect the purchase state of the item upon successful gift
 
 @param failure A block with an NSError instance for error handling
 */
- (void)giftItem:(MAStoreItem *)item
     toMaaiiUser:(NSString *)jid
      completion:(void (^)(MATransactionState state))completion
         failure:(void (^)(NSError *error, MaaiiVirtualStoreCheckoutFailure falureType))failure;

/*!
 @method
 
 @abstract
 Gift an item to a Facebook friend
 
 @discussion
 Only free items can be gifted.
 On successful check out, we will also claim the item from server
 
 @param item
 The item to be gifted
 
 @param gifteeId
 Facebook Id of the giftee
 
 @param gifteeSocialName
 Facebook name of the giftee
 
 @param gifterId
 Facebook Id of the gifter
 
 @param gifterSocialName
 Facebook name of the gifter
 
 @param completion
 The block takes a <MATransactionState> parameter, that reflect the purchase state of the item upon successful gift
 
 @param failure A block with an NSError instance for error handling
 */
- (void)giftItem:(MAStoreItem *)item
  toFacebookUser:(NSString *)gifteeId
gifteeSocialName:(NSString *)gifteeSocialName
gifterFacebookId:(NSString *)gifterId
gifterSocialName:(NSString *)gifterSocialName
      completion:(void (^)(MATransactionState state))completion
         failure:(void (^)(NSError *error, MaaiiVirtualStoreCheckoutFailure failureType))failure;

/*!
 @method
 
 @abstract
 Download the preview file (ZIP), unarchive it, and read the data in it
 
 @discussion
 The content of the preview ZIP file has to confirm with the specification at http://issuetracking.maaii.com:8090/display/MAAIIP/Store+Front+Item+Deployment.
 
 @param item
 An instance of <MAStoreItem> for which you want to download the preview content.
 
 @param completion
 The completion handler takes a single parameter. previewItemEnumerator is an instance of <MAPreviewItemEnumerator>. Since this is a subclass of NSEnumberator, you can use a for in loop to loop through a collection of <MAPreviewItem> instances.
 
 @param failure
 A block with an NSError instance for error handling
 
 */
- (void)fetchPreviewFilesForItem:(MAStoreItem *)item
                  withCompletion:(void(^)(MAPreviewItemEnumerator *previewItemEnumerator))completion
                         failure:(void(^)(NSError *error))failure;

/*!
 @method
 
 @abstract
 Refresh all of the transactions from the store server, and save it locally in the database.
 
 @discussion
 This method is required to be invoked in first sign-in of the application to ensure the transaction is synchronized for this account.
 
 @param completion
 The completion handler is invoked when the transactions are successfully refreshed and saved.
 
 @param failure
 A block with an NSError instance for error handling
 
 */
- (void)retrieveCompletedTransactionsWithCompletion:(void(^)())completion
                                            failure:(void(^)(NSError *error))failure;

/*
 @method
 
 @abstract
 Restore paid non-consumable transaction via Apple In-App Purchase.
 
 @param completion
 The completion handler is invoked when the transactions are successfully refreshed and saved.
 
 @param failure
 A block with an NSError instance for error handling
 
 */
- (void)restoreInAppPurchaseFromAppleIDWithCompletionHandler:(void(^)(NSArray *restoredTransactions))completion
                                              failureHandler:(void(^)(NSError *error, BOOL isUserCancelled))failure;

/*
 @method
 
 @abstract
 Retry claim the transactions which have successfully make payment with In-App purchase for non-consumable items.
 
 */
- (void)retryClaimingTransationsFinishingPayment;

/*!
 @method
 
 @abstract
 Get the NSFetchedResultsController for a list of transaction.
 
 @param category
 The identifier of the requried category of transactions. Passing nil will return all transactions.
 
 @param sortDescriptors
 The array of NSSortDescriptor instances to specify the sorting of this result NSFetchedResultsController. Can be nil.
 
 @return The NSFetchedResultsController instance of the MATransaction instances.
 
 */
- (NSFetchedResultsController *)fetchedResultsControllerForTransactionWithCategory:(NSString *)category
                                                               withSortDescriptors:(NSArray *)sortDescriptors;

/*!
 @method
 
 @abstract
 Download the content of the pruchased items for a specific item identifier
 
 @discussion
 The store item with itemIdentifier has to be successfully checked out before it can be downloaded.
 If the items has already downloaded, the download process will not be initiated.
 You should assign a delegate instance of <MaaiiVirtualStoreDelegate> to observe the state of the download process
 
 @param itemIdentifier
 The item identifier of the product you have purchased
 
 */
- (void)downloadPurchasedContentWithItemIdentifier:(NSString *)itemIdentifier;

/*!
 @method
 
 @abstract
 Download the content of the pruchased items for a specific item identifiers
 
 @discussion
 The store item with itemIdentifier has to be successfully checked out before it can be downloaded.
 If the items has already downloaded, the download process will not be initiated.
 You should assign a delegate instance of <MaaiiVirtualStoreDelegate> to observe the state of the download process
 
 @param itemIdentifiers
 The array of NSString of item itemtifier, which should be retrieved from [MATransaction itemId] or [MAStoreItem identifier]
 
 */
- (void)bulkDownloadPurchasedContentWithItemIdentifiers:(NSArray *)itemIdentifiers;

/*!
 @method
 
 @abstract
 Cancel the download operation of the purchased content for a specific item identifier.
 
 @discussion
 You should assign a delegate instance of <MaaiiVirtualStoreDelegate> to observe the state of the download process.
 The method "virtualStore:didFailDownloadingContentWithError:forTransaction:" will be invoked if the operation is ongoing.
 
 @param itemIdentifier The item identifier of the product you have purchased
 
 */
- (void)cancelDownloadContentForItemWithIdentifier:(NSString *)itemIdentifier;

/*!
 @method
 
 @abstract
 Get the progress of the downloading operation of the purchased content for this transaction.
 
 @discussion
 This method will return 0 if there is no operation in progress.
 
 @param transaction
 The required transaction with the progress
 
 @return The progress for downloading the item for this transaction.
 
 */
- (double)progressOfDownloadingContentForTransaction:(MATransaction *)transaction;

/*!
 @method
 
 @abstract
 Check if a purchased item is waiting to be downloaded, for a specific item identifier
 
 @discussion
 This method is used to determine if an item is in a "pending" state or not
 
 @param itemIdentifier The item identifier of the product you have purchased
 
 @return Return YES if an operation matching the item identifier can be found, NO otherwise
 
 */
- (BOOL)purchasedItemIsPendingDownloadWithIdentifier:(NSString *)itemIdentifier;

/*!
 @method
 
 @abstract
 Delete a purchased item, for a specific item identifier
 
 @discussion
 This method is used to delete a specific purchased item from my collection, only non consumable items
 can be deleted
 
 @param itemIdentifier The item identifier of the product you have purchased
 
 @param completion Invoked if a correct transaction can be identified.
 The "success" parameter returned specify if the deletion on disk was successful or not
 
 @param failure Invoked if the item identifier is incorrect or if the item is consumable
 
 */
- (void)deletePurchasedItemWithIdentifier:(NSString *)itemIdentifier
                               completion:(void(^)(BOOL success))completion
                                  failure:(void(^)(void))failure;

/*!
 @method
 
 @abstract
 Save a transaction with all specified information. The pending flag of the MATransaction will be set to YES.
 
 @param itemId
 The item identifier of the product regarding the transaction
 
 @param transactionId
 The transaction identifier of the transaction
 
 @param categories
 The categories of the item. Should be an array of NSString.
 
 @param icon
 The string of the relative path of the icon for product regarding the transaction
 
 @param localizedNames
 The key-value pair of the localized names of this package.
 The key is the ISO 639-1 language code of a language, and the value is the actual name string.
 
 @param consumable
 The consumable flag indicating whether the transaction is a consumable item
 
 @param purchaseDateString
 The string of the UTC date in standard format specified in ISO-8601
 Ref: http://www.w3.org/TR/NOTE-datetime
 
 @return A flag indicating the specified information is valid.
 
 */
- (BOOL)savePendingTransactionForItemId:(NSString *)itemId
                          transactionId:(NSString *)transactionId
                             categories:(NSArray *)categories
                                   icon:(NSString *)icon
                         localizedNames:(NSDictionary *)localizedNames
                           isConsumable:(BOOL)consumable
                    purchasedDateString:(NSString *)purchaseDateString;

#pragma mark - Delegate

- (void)addDelegate:(id<MaaiiVirtualStoreDelegate>)delegate;

- (void)removeDelegate:(id<MaaiiVirtualStoreDelegate>)delegate;

- (void)invokeLanguageDidChangeCallback;

#pragma mark - Resetting method

/*!
 @method
 
 @abstract
 Remove all the saved transactions
 
 */
- (void)resetAll;

#pragma mark - Singleton

/*!
 @method
 
 @abstract Return the singleton instance of this class
 
 @return The singleton instance of this class
 
 */
+ (instancetype)sharedInstance;

#pragma mark - Purchased item helper

- (MATransactionState)purchasedItemState:(NSString *)itemIdentifier;

- (BOOL)purchasedItemIsDownloaded:(NSString *)itemIdentifier;

- (void)liftPendingItemsForCategory:(NSString *)category;

- (NSInteger)numberOfPendingGift;

+ (NSString *)stringForCheckoutFailure:(MaaiiVirtualStoreCheckoutFailure)failureType;

@end
