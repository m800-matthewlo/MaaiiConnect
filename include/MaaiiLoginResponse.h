//
//  MaaiiLoginResponse.h
//  MaaiiConnect
//
//  Created by Kevin Lo on 27/8/15.
//
//

#import <Foundation/Foundation.h>
@class MaaiiProvisionInformation;
@class MaaiiCreditInfo;

@interface MaaiiLoginResponse : NSObject

@property (nonatomic, readonly) MaaiiProvisionInformation *provisionalInformation;

@property (nonatomic, readonly) MaaiiCreditInfo *creditInfo;

@property (nonatomic, copy, readonly) NSString *chargingRateEtag;

@property (nonatomic, copy, readonly) NSString *exchangeRateEtag;

@property (nonatomic, copy, readonly) NSString *capabilities;

@property (nonatomic, copy, readonly) NSString *capsig;

@property (nonatomic, copy, readonly) NSString *expires;

@property (nonatomic, copy, readonly) NSArray *additionalIdentities;

@property (nonatomic, copy, readonly) NSDictionary *rateTable;

@property (nonatomic, copy, readonly) NSString *ssoToken;

@end
