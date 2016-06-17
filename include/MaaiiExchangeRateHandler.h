//
//  MaaiiExchangeRateHandler.h
//  MaaiiConnect
//
//  Created by Kevin Lo on 26/8/15.
//
//

#import <Foundation/Foundation.h>
@class MAExchangeRate;

@interface MaaiiExchangeRateHandler : NSObject

@property (readonly) NSArray *allExchangeRates;

+ (instancetype)sharedInstance;

- (void)saveExchangeRatesDataWithPayload:(NSArray *)payload
                       fromCountryCode2A:(NSString *)fromCountryCode2A
                         toCountryCode2A:(NSString *)toCountryCode2A;

- (BOOL)isThereAnyEchangeRates;

- (double)currencyAmountWithOriginalAmount:(double)originalAmount
            convertedFromCountryWithCode2A:(NSString *)fromCountryCode2A
                       toCountryWithCode2A:(NSString *)toCountryCode2A;

- (NSString *)displayedCurrencyTextWithOriginalAmount:(double)originalAmount
                       convertedFromCountryWithCode2A:(NSString *)fromCountryCode2A
                                  toCountryWithCode2A:(NSString *)toCountryCode2A;

@end
