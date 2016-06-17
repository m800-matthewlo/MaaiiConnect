//
//  MaaiiProfileStore.h
//  MaaiiConnect_2.2
//
//  Created by Kevin Lo on 27/6/13.
//
//

#import <Foundation/Foundation.h>
#import "MA_Profile.h"
#import "MASuggestedProfile.h"

extern NSString *const USER_PROFILE_ATTRIBUTE_NAME;
extern NSString *const USER_PROFILE_ATTRIBUTE_VERIFIED;
extern NSString *const USER_PROFILE_ATTRIBUTE_SEX;
extern NSString *const USER_PROFILE_ATTRIBUTE_IMAGE;
extern NSString *const USER_PROFILE_ATTRIBUTE_IMAGE_URL;
extern NSString *const USER_PROFILE_ATTRIBUTE_IMAGE_THUMB_URL;
extern NSString *const USER_PROFILE_ATTRIBUTE_BIRTHDAY;
extern NSString *const USER_PROFILE_ATTRIBUTE_AGE;
extern NSString *const USER_PROFILE_ATTRIBUTE_EMAIL;
extern NSString *const USER_PROFILE_ATTRIBUTE_PLATFORM;
extern NSString *const USER_PROFILE_ATTRIBUTE_APPLICATION_VERSION;
extern NSString *const USER_PROFILE_ATTRIBUTE_VIDEO;
extern NSString *const USER_PROFILE_ATTRIBUTE_VIDEO_URL;
extern NSString *const USER_PROFILE_ATTRIBUTE_VIDEO_THUMB_URL;
extern NSString *const USER_PROFILE_ATTRIBUTE_COVER_IMAGE;
extern NSString *const USER_PROFILE_ATTRIBUTE_COVER_IMAGE_URL;

extern NSString *const kMaaiiProfileApplicationPlatformIOS;
extern NSString *const kMaaiiProfileApplicationPlatformAndroid;

extern NSString *const kUserProfileDateOfBirthFormat;

typedef enum {
    MaaiiUserProfileFileTypeProfileImageSource = 0,
    MaaiiUserProfileFileTypeProfileImageThumbnail,
    MaaiiUserProfileFileTypeBanner,
    MaaiiUserProfileFileTypeMaaiiMeVideo,
    MaaiiUserProfileFileTypeMaaiiMeVideoThumbnail
} MaaiiUserProfileFileType;

typedef enum {
    MaaiiProfileFriendSuggestionTypeRecommendation,
    MaaiiProfileFriendSuggestionTypeLocation,
    MaaiiProfileFriendSuggestionTypeCustomSearch
} MaaiiProfileFriendSuggestionType;

typedef enum {
    MaaiiProfileUserSearchAttributeTypePhoneNumber,
    MaaiiProfileUserSearchAttributeTypePIN,
    MaaiiProfileUserSearchAttributeTypeEmail
} MaaiiProfileUserSearchAttributeType;

typedef enum {
    MaaiiProfileFieldName,
    MaaiiProfileFieldEmail,
    MaaiiProfileFieldDateOfBirth,
    MaaiiProfileFieldGender
} MaaiiProfileFieid;

#pragma mark - MaaiiProfileDelegate

@protocol MaaiiProfileDelegate <NSObject>

@optional
- (void)profileDidUpdateForJID:(NSString *)jid;

@end

#pragma mark - MaaiiProfileStore

@interface MaaiiProfileStore : NSObject {
    NSManagedObjectContext *_workerManagedObjectContext;
    NSManagedObjectContext *_readOnlyBackgroundContext;
    id _multicaseDelegate;
    NSMutableDictionary *_cachedProfiles;
    NSMutableDictionary *_cachedSuggestedProfiles;
}

@property (readonly, nonatomic) NSString *username;
@property (readonly, nonatomic) NSString *carrierName;

+ (MaaiiProfileStore *)sharedInstance;

- (void)initializeForUsername:(NSString *)username
                    onCarrier:(NSString *)carrierName;

#pragma mark - Reset All

- (void)resetAll;

#pragma mark - Delegate

- (void)addDelegate:(id<MaaiiProfileDelegate>)delegate;

- (void)removeDelegate:(id<MaaiiProfileDelegate>)delegate;

#pragma mark - Profile Operation

- (MA_Profile *)profileForJID:(NSString *)jid;

- (MA_Profile *)profileForJID_background:(NSString *)jid;

- (MA_Profile *)profileForJID:(NSString *)jid forceLoad:(BOOL)forceLoad;

- (MA_Profile *)profileWithDictionary:(NSDictionary *)dictionary forJID:(NSString *)jid;

- (NSArray *)allProfiles;

- (void)queryProfileForJID:(NSString *)jid
                completion:(void(^)(MA_Profile *profile))completion
                   failure:(void(^)(NSError *error))failure;

- (void)queryProfileForJids:(NSArray<NSString *> *)jids
                skipIfExist:(BOOL)skipIfExist
                 completion:(void(^)(BOOL success, NSError *error))completion;

- (void)updateProfileForField:(MaaiiProfileFieid)field
                    withValue:(id)value
                   completion:(void(^)())completion
                      failure:(void(^)(NSError *error))failure;

#pragma mark - Profile File Upload Method

- (void)uploadProfileFileForType:(MaaiiUserProfileFileType)type
                        fileData:(NSData *)data
                        progress:(void (^)(long long bytesWritten, long long totalBytesWritten))progress
                      completion:(void (^)())completion
                         failure:(void (^)(NSError *error))failure;

- (void)deleteProfileFileForType:(MaaiiUserProfileFileType)type
                      completion:(void(^)())completion
                         failure:(void (^)(NSError *error))failure;

- (void)downloadProfileFileForType:(MaaiiUserProfileFileType)type
                               JID:(NSString *)jid
                          progress:(void (^)(long long bytesRead, long long totalBytesRead))progress
                        completion:(void (^)(NSData *data))completion
                          notFound:(void (^)())notFound
                           failure:(void(^)(NSError *error))failure;

- (NSURL *)urlForProfileFileWithType:(MaaiiUserProfileFileType)type
                              forJID:(NSString *)jid;

- (NSURL *)urlForProfileFileWithType:(MaaiiUserProfileFileType)type
                          forProfile:(MA_Profile *)profile;

- (void)setMaaiiMeEnabled:(BOOL)maaiiMeEnabled
               completion:(void(^)())completion
                  failure:(void(^)(NSError *error))failure;

- (void)queryMaaiiMeEnabledWithCompletion:(void(^)(BOOL maaiiMeEnabled))completion
                                  failure:(void(^)(NSError *error))failure;

#pragma mark - Friend finding

- (NSFetchedResultsController *)suggestedProfileFetchedResultsControllerByFriendRecommendationWithPageSize:(NSUInteger)pageSize
                                                                                                 pageIndex:(NSUInteger)pageIndex;

- (NSUInteger)countSuggestedProfileByFriendRecommendationForUserIsPromoted:(BOOL)isPromoted;

- (NSFetchedResultsController *)suggestedProfileFetchedResultsControllerByLocationWithPageSize:(NSUInteger)pageSize
                                                                                     pageIndex:(NSUInteger)pageIndex
                                                                             includeKnownUsers:(BOOL)includeKnownUsers;

- (NSUInteger)countSuggestedProfileByLocationWithIncludingKnownUsers:(BOOL)includeKnownUsers;

- (void)queryFriendRecommendationWithCompletion:(void(^)())completion
                                        failure:(void(^)(NSString *mimsIP, NSString *phoneNum, NSError *error))failure;

- (void)queryFriendNearbyWithlongitude:(double)longitude
                              latitude:(double)latitude
             requiredRadiusInKilometre:(NSUInteger)requiredRadiusKM
                            completion:(void(^)())completion
                               failure:(void(^)(NSString *mimsIP, NSString *phoneNum, NSError *error))failure;

- (void)removeFriendRecommendationWithJID:(NSString *)jid
                               completion:(void(^)())completion
                                  failure:(void(^)(NSString *mimsIP, NSString *phoneNum, NSError *error))failure;

- (void)querySingleUserWithAttributeType:(MaaiiProfileUserSearchAttributeType)type
                          attributeValue:(NSString *)attributeValue
                              completion:(void(^)(MASuggestedProfile *suggestProfile))completion
                                 failure:(void(^)(NSString *mimsIP, NSString *phoneNum, NSError *error))failure;

- (void)reportUserByJID:(NSString *)jid
             completion:(void(^)())completion
                failure:(void(^)(NSError *error))failure;

- (void)queryProfileForJids:(NSMutableArray *)participantJids completion:(void (^)(MA_Profile *))completion failure:(void (^)(NSError *))failure;

@end
