//
//  MAStoreKitHandler.h
//  MaaiiConnect_2.3
//
//  Created by Kevin Lo on 22/10/13.
//
//

#import <Foundation/Foundation.h>
@class SKPaymentTransaction;
@class MAStoreKitHandler;

/*!
 @abstract Error codes returned by MAStoreKitHandler in NSError while making purchases.
 */
typedef enum {
    
    /*!
     The user presses "Cancel" when making purchases
     */
    MAStoreKitPurchaseFailureUserCancelled = 0,
    
    /// The operation failed because payment is not allowed probably because of parental control or something else.
    MAStoreKitPurchaseFailureNotAllowed,
    
    /// The product identifier is invalid.
    MAStoreKitPurchaseFailureReasonInvalidProductIdentifier,
    
    /// The operation failed for some unknown reason, such as network error
    MAStoreKitPurchaseFailureUnknown,
    
} MAStoreKitPurchaseFailureReason;

@protocol MAStoreKitHandlerDelegate <NSObject>

- (void)storeKitHandler:(MAStoreKitHandler *)handler didCompleteTransaction:(SKPaymentTransaction *)transaction;

@end

/*!
 @typedef MAStoreKitGetProductPriceResponseHandler
 
 @abstract
 A block that is passed to [MAStoreKitHandler queryPriceForProductsWithIdentifiers:completion:failure:]
 and called when we has received the response from Apple
 
 @param productPrices       The dictionary of price string of each product. The key is the identifier of a product, and the value is the price string of the product according to the price value and the currency locale of the product. The currency symbol ($, ¥, etc.) is included in the price string.
 
 @param invalidProductIds   A collection of product identifiers which fails to get the associated product information
 */
typedef void (^MAStoreKitGetProductPriceResponseHandler)(NSDictionary *productPrices, NSSet *invalidProductIds);

/*!
 @typedef MAStoreKitGetProductResponseHandler
 
 @abstract
 A block that is passed to [MAStoreKitHandler queryProductsWithIdentifiers:completion:failure:]
 and called when we has received the response from Apple
 
 @param productPrices       The dictionary of <SKProduct> instances representing the successfully queried products. The key is the product identifier and the value is the SKProduct instance
 
 @param invalidProductIds   A collection of product identifiers which fails to get the associated product information
 */
typedef void (^MAStoreKitGetProductResponseHandler)(NSDictionary *products, NSSet *invalidProductIds);

/*!
 @typedef MAStoreKitGetProductFailureHandler
 
 @abstract
 A block that is passed to [MAStoreKitHandler queryPriceForProductsWithIdentifiers:completion:failure:] and
 [MAStoreKitHandler queryProductsWithIdentifiers:completion:failure:] and called when 
 the product fails to check out because of error or user cancelling.
 
 @param error       The <NSError> instance to provide information for error handling
 */
typedef void (^MAStoreKitGetProductFailureHandler)(NSError *error);

/*!
 @typedef MAStoreKitPaymentResponseCompletionHandler
 
 @abstract
 A block that is passed to [MAStoreKitHandler checkOutProductWithIdentifier:applicationUserName:completion:failure:]
 and called when the product is checked out successfully with payment.
 
 @param receiptId       The base-64 encoded data of the receipt data retrieved from Apple server
 
 @param restored        If YES, this is a payment made before and this time no amount is paid for this transaction.
 */
typedef void (^MAStoreKitPaymentResponseCompletionHandler)(NSString *appStoreTransactionId, NSString *receiptData, BOOL restored);

/*!
 @typedef MAStoreKitPaymentResponseFailureHandler
 
 @abstract
 A block that is passed to [MAStoreKitHandler checkOutProductWithIdentifier:applicationUserName:completion:failure:]
 and called when the product fails to check out because of error or user cancelling.
 
 @param error           The <NSError> instance to provide information for error handling
 @param failureReason   Indicate the failure reason of the payment for better error handling.
 */
typedef void (^MAStoreKitPaymentResponseFailureHandler)(NSError *error, MAStoreKitPurchaseFailureReason failureReason);

/*!
 @class MAStoreKitHandler
 
 @abstract
 A wrapper class to the iOS StoreKit framework to handle In-App Purchase related operation, such as querying product information and making payment
 */
@interface MAStoreKitHandler : NSObject

/*!
 @property
 
 @abstract
 Only used for making unit testing. When this flag is enabled, some method will not access the network and just return some hard coded data directly to make a method unitable.
 */
@property (nonatomic, assign) BOOL unitTesting;

@property (nonatomic, weak) id<MAStoreKitHandlerDelegate> delegate;

/*!
 @method
 
 @abstract
 Query the products with the specified product identifiers
 
 @param completion The completion handler for getting the response.
 
 @param failure The failure handler when failing to get the response
 
 */
- (void)queryProductsWithIdentifiers:(NSSet *)productIdentifiers
                          completion:(MAStoreKitGetProductResponseHandler)completion
                             failure:(MAStoreKitGetProductFailureHandler)failure;

/*!
 @method
 
 @abstract
 Checkout the product for the product with specified identifier.
 
 @discussion
 According to Apple documentation, we can optionally provide a one-way hash of the user account identifier of your application, for detecting irregular activity. Please refer to https://developer.apple.com/library/IOS/documentation/NetworkingInternet/Conceptual/StoreKitGuide/Chapters/RequestPayment.html#//apple_ref/doc/uid/TP40008267-CH4-SW6.
 
 @param productIdentifier
 The identifier of the product you want to checkout
 
 @param username
 The application username provided as a one-way hash, opaque identifier of each user. Can be nil.
 
 @param completion
 The completion handler for successful checkout.
 
 @param failure
 The failure handler of the failed checkout.
 
 */
- (void)checkOutProductWithIdentifier:(NSString *)productIdentifier
                  applicationUserName:(NSString *)username
                           completion:(MAStoreKitPaymentResponseCompletionHandler)completion
                              failure:(MAStoreKitPaymentResponseFailureHandler)failure;

/*!
 @method
 
 @abstract
 Query the products with the specified product identifiers
 
 @param completion The completion handler for restoring transaction
 
 @param failure The failure handler when failing to restore transactions
 
 */
- (void)restoreCompletedTransactionWithCompletionHandler:(void (^)(NSArray *restoredTransactions))completion
                                          failureHabdler:(void (^)(NSError *error, BOOL isUserCancell))failure;

/*!
 @method
 
 @abstract
 Finish the transaction for the specific transaction identifier
 
 @discussion
 This method has to be invoked after delivering the product to the customer
 
 @param transactionIdentifier The transaction identifier of the transaction
 
 */
- (void)finishTransactionWithIdentifier:(NSString *)transactionIdentifier;

/*!
 @method
 
 @abstract
 Get the base 64 enacoded string of the receipt data for the current transaction
 
 */
+ (NSString *)base64EncodedReceiptFromTransaction:(SKPaymentTransaction *)transaction;

/*!
 @method
 
 @abstract
 Get the singleton instance for MAStoreKitHandler
 */
+ (instancetype)sharedInstance;

@end