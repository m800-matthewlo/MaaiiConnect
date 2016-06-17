//
//  SecurityUtil.h
//  MaaiiConnect
//
//  Created by Dima Gutzeit on 9/3/13.
//
//

#import <Foundation/Foundation.h>

/*! This class uses 2-level stores for security data:
 
  1. NSUserDefaults as quick access store. It is valid till user uninstall the App. Both key and value are encrypted when saving.
 
  2. NSKeychain as the back store. It is valid for longer time, and it persist even after user uninstall and re-install. However, there is case that iOS may fail to access keychain in certain situations.
  @class SecurityUtil
  @brief Wrapper class to save and retrieve user's security data
  @date 2015-11-23
*/

@interface SecurityUtil: NSObject

+ (SecurityUtil *)sharedInstance;

- (void)resetPasswordForService:(NSString *)service andUser:(NSString *)username;
- (void)resetAllPasswordsForServiceInKeyChain:(NSString *)service;
- (NSString *)getPasswordForService:(NSString *)service andUser:(NSString *)username;
- (void)storePassword:(NSString *)password forService:(NSString *)service andUser:(NSString *)username;

- (void)resetPasswordForService:(NSString *)service andUser:(NSString *)username permanentStore:(BOOL)permanentStore;
- (NSString *)getPasswordForService:(NSString *)service andUser:(NSString *)username permanentStore:(BOOL)permanentStore;
- (void)storePassword:(NSString *)password forService:(NSString *)service andUser:(NSString *)username permanentStore:(BOOL)permanentStore;

@end
