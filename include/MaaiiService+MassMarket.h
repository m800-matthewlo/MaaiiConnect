//
//  MaaiiService+MassMarket.h
//  MaaiiConnect
//
//  Created by Cyrus Lo on 25/7/12.
//  Copyright (c) 2012 Maaii Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MaaiiService.h"
#import "MaaiiSignupResult.h"
#import "MaaiiCreditInfo.h"
#import "MaaiiPreferenceAttribute.h"
#import "MA_Profile.h"

FOUNDATION_EXPORT NSString *const SOCIAL_SHARING_EVENT_TYPE_POST_WALL;
FOUNDATION_EXPORT NSString *const SOCIAL_SHARING_EVENT_TYPE_DIRECT_MESSAGE;
FOUNDATION_EXPORT NSString *const SOCIAL_SHARING_EVENT_TYPE_POST_STATUS;

FOUNDATION_EXPORT NSString *const SOCIAL_NETWORK_FACEBOOK;
FOUNDATION_EXPORT NSString *const SOCIAL_NETWORK_WEIBO;

FOUNDATION_EXPORT NSString *const EARN_CREDIT_EMAIL;
FOUNDATION_EXPORT NSString *const EARN_CREDIT_FACEBOOK;
FOUNDATION_EXPORT NSString *const EARN_CREDIT_TWITTER;
FOUNDATION_EXPORT NSString *const EARN_CREDIT_WEIBO;
FOUNDATION_EXPORT NSString *const EARN_CREDIT_RANDOM_RETENTION;
FOUNDATION_EXPORT NSString *const EARN_CREDIT_RATE_US;

@interface MaaiiService (MassMarket)

-(void) validateNumber:(NSString *)number
               country:(NSString *)country
              language:(NSString*) lang
             validType:(NSString *)type
              complete:(void(^)(NSString *validateCode)) completeBlock
                 error:(void(^)(NSString *mimsIP, NSString *phoneNumber, NSError *error))errorBlock;

-(void) signup:(NSString *)number
  validateCode:(NSString *)validateCode
       smsCode:(NSString *)smsCode
          name:(NSString *)name
       carrier:(NSString *)carrier
passiveValidation:(NSString *) isPassiveValidation
      complete:(void(^)(MaaiiSignupResult *signupResult))completeBlock
         error:(void(^)(NSString *mimsIP, NSString *phoneNumber, NSError *error))errorBlock;

-(void) verify:(NSString *) number
       country:(NSString *) country
  validateCode:(NSString *) validateCode
       smsCode:(NSString *) smsCode
       carrier:(NSString *) carrier
      complete:(void(^)(NSDictionary *result))completeBlock
         error:(void(^)(NSString *mimsIP, NSString *phoneNumber, NSError *error))errorBlock;


/*!
 @abstract
 Register a new account. This is created because of Bolt,
 Might need further fine-tuning for applying to Maaii and other White Labels
 
 @param number Phone number in e164 format.
 @param country Country code that the number belongs to.
 @param name Name of the user, as provided by the user.
 @param email Email of the user, as provided by the user.
 @param idNumber IdNumber of the user, as provided by the user, e.g. passport number.
 @param carrier Name of the carrier.
 @param completeBlock Block that will be invoked on operation finished.
 @discussion Nothing to add.
 */
- (void)boltRegister:(NSString *)number
       country:(NSString *)country
          name:(NSString *)name
         email:(NSString *)email
      idNumber:(NSString *)idNumber
       carrier:(NSString *)carrier
      complete:(void(^)(BOOL success, NSError *error))completeBlock;


/*!
 @abstract
 Sign in the App with Bolt ID and password, this will call UserSignupRequest
 
 @param boltId Bolt ID.
 @param password Password for login to Bolt network
 @param carrier Name of the carrier.
 @param completeBlock Block that will be invoked on operation finished.
 @discussion After this request, we need to call additional IdentifySignupRequest to add user's number
 */

- (void)boltSignIn:(NSString *)boltId
          password:(NSString *)password
           carrier:(NSString *)carrier
            complete:(void(^)(MaaiiSignupResult *, NSError *error))completeBlock;



/*!
 @abstract
    Singup version for unverified numbers.
 
 @param number Phone number in e164 format.
 @param country Country code that the number belongs to.
 @param name Name of the user, as provided by the user.
 @param carrier Name of the carrier.
 @param completeBlock Block that will be invoked on successful operation finish.
 @param errorBlock Block that will be invoked on failure operation.
 @discussion Nothing to add.
 */
-(void) signup:(NSString *)number
       country:(NSString *)country
          name:(NSString *)name
       carrier:(NSString *)carrier
      complete:(void(^)(MaaiiSignupResult *))completeBlock
         error:(void(^)(NSString *mimsIP, NSString *phoneNumber, NSError *error))errorBlock;

/*!
 @abstract
 Sign up version for unverified numbers.
 
 @param number Phone number in e164 format.
 @param country Country code that the number belongs to.
 @param name Name of the user, as provided by the user.
 @param carrier Name of the carrier.
 @param unverifiedMode Non-verified mode flag when signing up
 @param passiveValidation Passive validation flag when signing up
 @param completeBlock Block that will be invoked on successful operation finish.
 @param errorBlock Block that will be invoked on failure operation.
 @discussion Nothing to add.
 */
-(void) signup:(NSString *)number
       country:(NSString *)country
          name:(NSString *)name
       carrier:(NSString *)carrier
    unverified:(BOOL)unverifiedMode
      passsive:(BOOL)passiveValidation
      complete:(void(^)(MaaiiSignupResult *signupResult))completeBlock
         error:(void(^)(NSString *mimsIP, NSString *phoneNumber, NSError *error))errorBlock;


#pragma mark - Additional Identity handling

/*!
 @abstract
 Adding an additional identity of phone number without verification
 
 @param phoneNumber Phone number in national format without country code
 @param countryCode Two-letter country code in ISO 3166-1 alpha-2 format (e.g. "HK")
 @param completeBlock Block that will be invoked on successful operation finish.
 @param failureBlock Block that will be invoked on failure operation.
 
 @discussion Nothing to add.
 */
- (void)addIdentityForNationalPhoneNumber:(NSString *)phoneNumber
                              countryCode:(NSString *)countryCode
                        completionHandler:(void(^)())completeBlock
                           failureHandler:(void(^)(NSError *))failureBlock;

/*!
 @abstract
 Adding an additional identity of phone number without verification
 
 @param phoneNumber Phone number in national format without country code
 @param countryCode Two-letter country code in ISO 3166-1 alpha-2 format (e.g. "HK")
 @param validateCode The validation code returned by "NumberValidationRequest"
 @param smsCode The SMS code enter by the user
 @param completeBlock Block that will be invoked on successful operation finish.
 @param failureBlock Block that will be invoked on failure operation.
 
 @discussion Nothing to add.
 */
- (void)addIdentityForNationalPhoneNumber:(NSString *)phoneNumber
                              countryCode:(NSString *)countryCode
                             validateCode:(NSString *)validateCode
                                  smsCode:(NSString *)smsCode
                        completionHandler:(void(^)())completeBlock
                           failureHandler:(void(^)(NSError *error))failureBlock;

/*!
 @abstract
 Removing an additional identity of phone number
 
 @param phoneNumber Phone number in national format without country code
 @param countryCode Two-letter country code in ISO 3166-1 alpha-2 format (e.g. "HK")
 @param completeBlock Block that will be invoked on successful operation finish.
 @param failureBlock Block that will be invoked on failure operation.
 
 @discussion Nothing to add.
 */
- (void)removeIdentityForNationalPhoneNumber:(NSString *)phoneNumber
                                 countryCode:(NSString *)countryCode
                           completionHandler:(void(^)())completeBlock
                              failureHandler:(void(^)(NSError *error))failureBlock;

#pragma mark -

-(void) updateSocialAuthorizationTokenRequest:(NSString *) socialAuthorizationToken
                          expirationTimestamp:(NSNumber *) expirationTimestamp
                                     exchange:(BOOL) exchange
                                  networkType:(NSString *)networkType
                                     socialId:(NSString *)socialId
                    networkSpecificAttributes:(NSDictionary *) networkSpecificAttributes
                                     complete:(void(^)(BOOL))completeBlock
                                        error:(void(^)(NSString *mimsIP, NSString *phoneNumber, NSError *error))errorBlock;

-(void) disconnectSocialNetworkRequest:(NSString *)networkType
                              socialId:(NSString *)socialId
                              complete:(void(^)(BOOL))completeBlock
                                 error:(void(^)(NSString *mimsIP, NSString *phoneNumber, NSError *error))errorBlock;

/*!
 @abstract
 This method should be used when a post to social network is required. Examples are invitation messages, wall post or direct messages.
 
 @param eventType Type of the event to share. See SOCIAL_SHARING_EVENT_TYPE* contants.
 
 @param networkType Type of the target network, i.e. FACEBOOK. See SOCIAL_NETWORK* constants.
 
 @param socialId ID of the sender in the target social network.
 
 @param messageText Text of the event to post.
 
 @param destinationSocialId ID of the recepient in the target social network. Its an optional element and valid only of eventType is DIRECT_MESSAGE.
 
 @param networkSpecificAttributes Set of attributes that will be passed to the target network.
 
 @param completeBlock Block that will be invoked on successful operation finish.
 
 @param errorBlock Block that will be invoked on failure operation.
 
 @discussion Nothing to add.
 */
-(void) socialEventShareRequestForEvent:(NSString *) eventType
                            networkType:(NSString *) networkType
                               socialId:(NSString *) socialId
                            messageText:(NSString *) messageText
                    destinationSocialId:(NSString *) destinationSocialId
              networkSpecificAttributes:(NSDictionary *) networkSpecificAttributes
                               complete:(void(^)(BOOL)) completeBlock
                                  error:(void(^)(NSString *mimsIP, NSString *phoneNumber, NSError *error))errorBlock;

/*!
 @abstract
 This method should be used when an app wants to query for the most updated credit.
 
 @param completeBlock Block that will be invoked on successful operation finish.
 
 @param errorBlock Block that will be invoked on failure operation.
 
 @discussion Nothing to add.
 */
-(void) getCreditRequest:(void(^)(MaaiiCreditInfo *creditInfo))completeBlock
                   error:(void(^)(NSString *mimsIP, NSString *phoneNumber, NSError *error))errorBlock;

/*!
 @abstract
 This method should be used when an app wants to update any preference associated with a user.
 
 @param request Attributes to sent. Each array element should be an instance of MaaiiPreferenceAttribute
 
 @param completeBlock Block that will be invoked on successful operation finish.
 
 @param errorBlock Block that will be invoked on failure operation.
 
 @discussion Nothing to add.
 */
-(void) userPreferencesRequestWithData:(NSArray *)request
                              complete:(void(^)(NSArray *resultAttributes))completeBlock
                                 error:(void(^)(NSString *mimsIP, NSString *phoneNumber, NSError *error))errorBlock;

-(void) earnCreditOfType:(NSString *)earnType
                complete:(void(^)(NSDictionary *response))completeBlock // Contains parsed JSON response
                   error:(void(^)(NSString *mimsIP, NSString *phoneNum, NSError *error))errorBlock;

-(void) createInvitationRequestForNumbers:(NSArray *) phoneNumbers
                               forCountry:(NSString *) countryCode
                                 complete:(void(^)(NSDictionary *response)) completeBlock // Contains transaction ID of the invitation request.
                                    error:(void(^)(NSString *mimsIP, NSString *phoneNum, NSError *error))errorBlock;

-(void) deactivate:(void(^)(BOOL result))completeBlock
             error:(void(^)(NSString *mimsIP, NSString *phoneNumber, NSError *error))errorBlock;

@end
