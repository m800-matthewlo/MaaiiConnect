//
//  MaaiiSignupResult.h
//  MaaiiConnect
//
//  Created by Cyrus on 8/8/12.
//
//

#import <Foundation/Foundation.h>
#import "MaaiiProvisionInformation.h"
#import "MaaiiCreditInfo.h"

@interface MaaiiSignupResult : NSObject {
    NSArray  *_socialIdentities;
    NSArray  *_additionalIdentities;
    NSString *_signupResult; // One of  IDENTITY_PROMOTED, DEVICE_REPLACED, NONE
    NSString *_carrierName;
    NSString *_maaiiId;
    NSString *_userName;
    NSString *_password;
    NSString *_e164PhoneNumber;
    NSString *_deviceSecret;
    MaaiiProvisionInformation *_provisionInfo;
    MaaiiCreditInfo *_creditInfo;
    NSString *_ssoToken;
    NSString *_capsig;
    NSNumber *_expires;
    NSString *_capabilities;
    NSArray  *_preferences;
    NSDictionary *_userProfile;
    BOOL _verified;
}

@property (nonatomic, readonly) NSArray  *socialIdentities;
@property (nonatomic, readonly) NSArray  *additionalIdentities;
@property (nonatomic, readonly) NSString *signupResult;
@property (nonatomic, readonly) NSString *carrierName;
@property (nonatomic, readonly) NSString *maaiiId;
@property (nonatomic, readonly) NSString *userName;
@property (nonatomic, readonly) NSString *password;
@property (nonatomic, readonly) NSString *e164PhoneNumber;
@property (nonatomic, readonly) NSString *deviceSecret;
@property (nonatomic, readonly) MaaiiProvisionInformation *provisionInfo;
@property (nonatomic, readonly) MaaiiCreditInfo   *creditInfo;
@property (nonatomic, readonly) NSString *ssoToken;
@property (nonatomic, readonly) NSString *capsig;
@property (nonatomic, readonly) NSNumber *expires;
@property (nonatomic, readonly) NSString *capabilities;
@property (nonatomic, readonly) NSArray  *preferences;
@property (nonatomic, readonly) NSDictionary *userProfile;
@property (nonatomic, readonly) BOOL verified;

-(id) init;
-(id) initWithJson:(NSString *)jsonStr;
-(id) initWithDictionary:(NSDictionary *)dict;

@end
