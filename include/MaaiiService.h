//
//  MaaiiService.h
//  MaaiiConnect
//
//  Created by Cyrus Lo on 8/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "MaaiiCreditInfo.h"
#import "MaaiiProvisionInformation.h"
#import "MaaiiConnectErrorCode.h"
@class MaaiiLoginResponse;

/**
 * 2.3-20131115-739 by Justin
 Add this version description.
 
 * 2.3-20131115-738 by Justin
 1. Implement file logger with encryption.
 2. Add encryption/decryption method for NSData with algorithm DES/ECB algorithm. see <link>NSData(DES)</link>.
 */
#define MaaiiConnectCurrentVersion @"2.3-20131115-739"


// Notifications sent by the XMPP Reconnect module to notify the application about current connection status
FOUNDATION_EXPORT NSString *const XMPP_STREAM_AUTHENTICATED;
FOUNDATION_EXPORT NSString *const XMPP_STREAM_DISCONNECTED;
FOUNDATION_EXPORT NSString *const XMPP_STREAM_PING_ARRIVED;

FOUNDATION_EXPORT NSString *const MAII_SERVICE_STATE_CHANGED_NOTIFICATION;

#ifndef MaaiiService_h
#define MaaiiService_h

//service secert
#define KEYCHAIN_SSO_SERVICE                    @"MaaiiChanelSSO"
#define KEYCHAIN_DEVICE_SECRET_SERVICE          @"MaaiiChanelDeviceSecret"
#define KEYCHAIN_IDENTIFIER_GENERATION_TYPE     @"MaaiiDeviceIdentifierGenerationMethod"
#define SSOTOKEN                         @"ssoToken"
#define DEVICESECRET                     @"deviceSecret"
#define CAPS_KEY                 @"%@_CAPS"
#define CAPSIGN_KEY              @"%@_CAPSIGN"
#define EXPIRES_KEY              @"%@_EXPIRES"
#define DEVSEC_KEY               @"%@_DEVSEC"
#define DEFAULT_CAPS             @"SGINUP_V15"

#define NOT_CONNECTED_ERROR [NSError errorWithDomain:@"MaaiiConnect" code:1005 userInfo:[NSDictionary dictionaryWithObject:@"Not connected" forKey:@"reason"]]

@protocol MaaiiServiceDelegate;

extern NSString *const kMaaiiServiceConnectPrimaryResourceSuccessfulNotification;
extern NSString *const kMaaiiServiceConnectPrimaryResourceFailedNotification;
extern NSString *const kMaaiiServiceConnectSecondaryResourceSuccessfulNotification;
extern NSString *const kMaaiiServiceConnectSecondaryResourceFailedNotification;
extern NSString *const kMaaiiServiceReconnectionAttemptNotification;

extern NSString *const kMaaiiServiceDidReadyNotification;

enum MaaiiConnectionState
{
	STATE_DISCONNECTED,
	STATE_CONNECTING,
	STATE_CONNECTED
};
typedef enum MaaiiConnectionState MaaiiConnectionState;

@interface MaaiiService : NSObject
{
    NSString *_username;
    NSString *_password;
    NSString *_carrierName;
    NSString *_ssoToken;
    NSString *_appKey;
    NSString *_developerKey;
    NSArray  *_version;
    NSString *_identifier;
    NSString *_status;
    dispatch_queue_t _serviceQueue;
    NSDate *_lastBackgroundedDate;
    MaaiiConnectionState _currentConnectionState;
    NSDate *_lastConnectedDate;
    NSString *_displayName;
    NSString *_simulatedSourceIp;
}

#pragma mark - User Credentials

@property (retain, nonatomic) NSString *username;
@property (retain, nonatomic) NSString *password;
@property (retain, nonatomic) NSString *carrierName;

@property (nonatomic, readonly) NSString *myJid;
@property (nonatomic, readonly) NSString *deviceID;
@property (nonatomic, readonly) NSArray *additionalIdentities;

@property (nonatomic, copy, readonly) NSString *userStatusText;

#pragma mark - XMPP Authentication related

@property (retain, nonatomic) NSString *ssoToken;
@property (retain, nonatomic) NSString *appKey;
@property (retain, nonatomic) NSString *capSig;
@property (retain, nonatomic) NSString *developerKey;
@property (retain, nonatomic) NSString *carrier;
@property (retain, nonatomic) NSArray  *version;
@property (retain, nonatomic) NSString *identifier;
@property (retain, nonatomic) NSString *displayName;

@property (retain, nonatomic) NSString *simulatedSourceIp;
@property (copy, nonatomic) NSURL *trustedCertificateURL;
@property (nonatomic, assign) BOOL enabledSlimMessaging;
@property (readonly, copy) NSString *appGroupIdentifier;

#pragma mark - Misc

@property (nonatomic, readonly) dispatch_queue_t serviceQueue;
@property (nonatomic, readonly) dispatch_queue_t notificationsQueue;

#pragma mark - Connection State

@property (assign, readonly) MaaiiConnectionState currentConnectionState;

#pragma mark - IM Resource

@property (retain, nonatomic) NSString *ip;
@property (assign, nonatomic) NSUInteger port;
@property (readonly, nonatomic) BOOL secure;

@property (copy) NSString *simulatedResourceHost;
@property (assign) NSUInteger simulatedResourcePort;

#pragma mark - Default (Sign up) resource

@property (nonatomic, readonly) BOOL cannotFailover;

@property (copy) NSString *defaultPrimaryIMHost;
@property (assign) NSUInteger defaultPrimaryIMPort;
@property (readonly) NSURL *defaultPrimaryIMResource;

@property (copy) NSString *defaultSecondaryIMHost;
@property (assign) NSUInteger defaultSecondaryIMPort;
@property (readonly) NSURL *defaultSecondaryIMResource;

#pragma mark - Online presence

@property (nonatomic, assign) BOOL explicitTypeAttributeForOnlinePresence;

#pragma mark - Public methods

+ (NSUserDefaults *)userDefaults;
+ (void)setUserDefaults:(NSUserDefaults *)userDefaults;

+ (NSString *)appGroupIdentifier;
+ (void)setAppGroupIdentifier:(NSString *)newVal;

+(MaaiiService *) currentService;

+ (void) setResourceBundle:(NSBundle *)bundle;

+ (void)initializeService:(NSString *)appKey
                   devKey:(NSString *)devKey
                  version:(NSArray *)version
               identifier:(NSString *)identifier
                  carrier:(NSString *)carrier
               completion:(void(^)(MaaiiService *service))completion;

+ (void)initializeService:(NSString *)appKey
                   devKey:(NSString *)devKey
                  version:(NSArray *)version
               identifier:(NSString *)identifier
                  carrier:(NSString*)carrier
                   capSig:(NSString*)capSig
                    async:(BOOL)async
               completion:(void(^)(MaaiiService *service))completion;

- (void)addDelegate:(id <MaaiiServiceDelegate>)objects;
- (void)removeDelegate:(id <MaaiiServiceDelegate>)objects;


+ (void)resetAllServices;
- (void)resetAll;
- (void)onResetFinish;

+ (void)startFileLog;
+ (void)stopFileLog;
+ (void)startConsoleLog;
+ (void)stopConsoleLog;
+ (void)logLevel:(int)level format:(NSString *)format, ...;
+ (id)getFileLogger;

// TODO: Move to private header
- (void)storeAllocationsWithProvisionInformation:(MaaiiProvisionInformation *)provisionInfo;
- (void)setAdditionalIdentities:(NSArray *)additionalIdentities;

- (void)simluateIncomingPacketWithXMLString:(NSString *)xmlString;

- (NSURL *)currentlyConnectedResource;

-(BOOL) connectWithUser:(NSString *)jid
               password:(NSString *)password
               complete:(void (^)(NSString*))completeBlock 
             disconnect:(void (^)(NSString*))disconnectBlock
                  error:(void(^)(NSString *, NSString *, NSError *))errorBlock;


-(BOOL) connectWithUser:(NSString *)jid
               password:(NSString *)password
                     ip:(NSString *)ip
                   port:(unsigned int) port
               complete:(void (^)(NSString*))completeBlock 
             disconnect:(void (^)(NSString*))disconnectBlock
                  error:(void(^)(NSString *, NSString *, NSError *))errorBlock;

- (void)reconnectWithReason:(NSString *)reasonForReconnection;

- (NSDictionary *) getDeviceInfo;

- (void)login:(void(^)(MaaiiProvisionInformation *, MaaiiCreditInfo *))completeBlock
        error:(void(^)(NSString *, NSString *, NSError *))errorBlock;

- (void)getCreditPackage:(void(^)(NSArray *))completeBlock
                   error:(void(^)(NSString *, NSString *, NSError *))errorBlock;

- (void)updatePushToken:(NSString *)deviceToken
               complete:(void (^)(NSString *apnsToken))completeBlock
                  error:(void (^)(NSError *error))errorBlock;

- (void)updatePushToken:(NSString *)deviceToken
              voipToken:(NSString *)voipToken
               complete:(void (^)(NSString *apnsToken, NSString *voipToken))completeBlock
                  error:(void (^)(NSError *error))errorBlock;

- (BOOL)isConnected;
- (void)disconnect;
- (void)disconnectChannelForIdentifier:(NSString *)identifier;

-(void) goOnline:(void (^)()) completeBlock error:(void (^)(NSError*)) errorBlock;
-(void) goOnlineWithStatus:(NSString *) status complete:(void (^)()) completeChange error:(void (^)(NSError*)) errorBlock; 
-(void) goOffline:(void (^)()) completeBlock error:(void (^)(NSError*)) errorBlock;
-(void) errorNotify:(void(^)(NSError*)) errorBlock  user:(NSString *)username;

-(void) incomingNotificationWithUserInfo:(NSDictionary *)userInfo;

@end

@protocol MaaiiServiceDelegate <NSObject>

@optional

- (void)incomingServerNotificationWithType:(NSString *)type nameSpace:(NSString *)nameSpace info:(NSDictionary *)info;
- (void)provisioningInformationDidUpdate:(MaaiiProvisionInformation *)provisionInfo;
- (void)maaiiCreditInfoDidUpdate:(MaaiiCreditInfo *)creditInfo;
- (void)additionIdentitiesDidUpdate:(NSArray *)identities;

// Callbacks for XMPP life cycle
- (void)maaiiService:(MaaiiService *)service connectionStateDidChange:(MaaiiConnectionState)state;
- (void)maaiiService:(MaaiiService *)service authenticationDidFailWithError:(NSError *)error;
- (void)maaiiService:(MaaiiService *)service userDidUpdateStatusText:(NSString *)statusText;
- (void)maaiiService:(MaaiiService *)service didLoginWithResponse:(MaaiiLoginResponse *)loginResponse;

// Whether the XMPP stream should send on the presence when it was expected to
- (BOOL)maaiiServiceShouldGoOnline:(MaaiiService *)service;

@end

#endif