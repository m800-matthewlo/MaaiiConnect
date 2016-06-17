//
//  MaaiiCountryStore.h
//  MaaiiConnect
//  Created by Cullen Sun on 25/8/14.
//
//


#import <Foundation/Foundation.h>
#import "MACountry.h"
#import "MACountryLocalization.h"
#import "MARate.h"

typedef enum {
    generalCountryList,
    callRateTable,
    smsRateTable,
} FetchType;


@protocol MaaiiRatesDataDelegate <NSObject>

@optional
- (void)ratesDataUpdated;

@end



@interface MaaiiCountryStore : NSObject

@property (nonatomic, copy) NSString *preferredCountryCode2AForCurrency;

/*!
 *  @abstract Return the singleton instance of this class
 *  @return The singleton instance of this class
 */
+ (MaaiiCountryStore *)sharedInstance;


- (void)addRatesDataDelegate:(id<MaaiiRatesDataDelegate>) delegate;
- (void)RemoveRatesDataDelegate:(id<MaaiiRatesDataDelegate>) delegate;

/*!
 * @abstract process the rates updating data on the background thread and
 * @param incomingData: all the rates data
 * @param complete: call back on the main thread
 * @return void
 */

- (void)processRatesData:(NSArray *)incomingData completion:(void (^)(BOOL success))complete;

#pragma mark - Query Api

/*!
 * @abstract convenient method for return the country object with call code
 * @param callCode: 852, 86, 852...
 * @return MACountry object, nil if cannot find any matching
 */
- (MACountry *)findCountryByCallCode:(NSString *)callCode;


/*!
 * @abstract convenient method for return the country object with code2A
 * @param code: 2 char ISO country code
 * @return MACountry object, nil if cannot find any matching
 */
- (MACountry *)findCountryByCode2A:(NSString *)code;


/*!
 * @abstract convenient method for return the country object with mcc
 * @param mcc: mobile country code 454 for hong kong, 460 for china...
 * @return MACountry object, nil if cannot find any matching
 */
- (MACountry *)findCountryByMcc:(NSString *)mcc;


- (MACountry *)findCountryByRawTelNumber:(NSString *)number defaultCode2A:(NSString *)code;

- (MARate *)findRateWithCountry:(MACountry *)country withTelNumber:(NSString *)number forRateType:(RateType)type;


/*!
 * @abstract convenient method for return the countryLocalization object with code2A
 * @param localization: the language code zh-Hans, zh-Hant , en....
 * @param code: code2A, 2 char ISO country code
 * @return MACountryLocalization object, nil if cannot find any matching
 */
- (MACountryLocalization *)findCountryLocalizationFor:(NSString *)localization byCode2A:(NSString *)code;


/*!
 * @abstract get the fetchedResultsController for ViewControllers
 * @param localization: app language setting, from SelfAwareness class
 * @param type: can be for country list or sms rates or call rates
 * @return NSFetchedResultsController
 */
- (NSFetchedResultsController *)fetchedResultsControllerForLocalization:(NSString *)localization forFetchType:(FetchType)type;


#pragma mark - Cost Api

- (BOOL)isRoaming;

/*!
 * @abstract get the cost of SMS based on the text and the country Call Code
 * @param text: the text user intents to send
 * @param country: the country identified
 * @return NSDictionary the result of SMS; nil if cannot find any matching MACountry or Maaii doesn't support IM-SMS at that country yet,
 */
- (NSDictionary *)resolveSMSText:(NSString *)text
                       forNumber:(NSString *)mobileNum
                      forCountry:(MACountry *)country;


#ifdef XCTESTING
/*!
 * @abstract the real method for count sms and calculate cost
 * @param text: the text user intents to send
 * @param callCode: 852, 86, 852...
 * @param unitCost: cost per sms
 * @param isAllAscii: if we know that the string is all ascii, logic optimization. App shall always pass NO. Internally MaaiiConnect
 *        will assign YES when available during recursive calling
 * @return NSDictionary the result of SMS; 
 */
- (NSDictionary *)resolveSMSText:(NSString *)text
                     forCallCode:(NSString *)callCode
                      costPerSms:(double)unitCost
                   knownAllAscii:(BOOL)isAllAscii;

#endif

/*!
 * @abstract get the cost of Call based on the countryCallCode and timeInterval
 * @param callCode: 852, 86, 853...
 * @param code2A: CA, HK, US, this is more accurate to identify the country
 * @param duration: the call duration
 * @param type: landlineCost or mobileCost
 * @return NSNumber, nil if cannot find any matching MACountry, or Maaii doesn't support call at that country yet, other wise use floatValue to get cost.
 */

- (NSNumber *)getCallCostForRate:(MARate *)rateItem ofDuration:(NSTimeInterval)duration;

- (double)getRemainingCallMinsForRate:(MARate *)rateItem withBalance:(double)balance;

#pragma mark - Developer methods

/*!
 * @abstract clean the MACountry and MACountryLocalization Database
 */
- (void)resetAll;

@end



