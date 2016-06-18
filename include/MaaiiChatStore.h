//
//  MaaiiChatDataAccess.h
//  MaaiiConnect
//
//  Created by Dima Gutzeit on 7/9/12.
//
//

#import <Foundation/Foundation.h>
#import "MA_Room.h"
#import "MAMediaItem.h"
#import "MaaiiIdentity.h"
#import "MABroadcast.h"
#import "NSFetchedResultsControllerWithPagination.h"
#import "MaaiiGeoLocation.h"
#import <CoreGraphics/CoreGraphics.h>

@class MaaiiChatStore;
@class DummyRoomMessagePayload;

// Lifecycle for outgoing messages -- 1. DELIVERY, 2. SERVERRECEIVED, 3. CLIENTRECEIVED
// Lifecycle for incoming messages -- 1. RECEIVED, 2. READ, 3. EXPIRED (for ephemeral messages only)

#pragma mark - Message Direction
#define MAAIICONNECT_INCOMING [NSNumber numberWithBool:TRUE]
#define MAAIICONNECT_OUTGOING [NSNumber numberWithBool:FALSE]

#pragma mark - Message status for deleted messages
#define MAAIICONNECT_DELETED_MESSAGE [NSNumber numberWithInt:-3]

#pragma mark - Message status for incoming messages
#define MAAIICONNECT_READ [NSNumber numberWithInt:-2]
#define MAAIICONNECT_RECEIVED [NSNumber numberWithInt:-1]
#define MAAIICONNECT_EXPIRED [NSNumber numberWithInt:2]
#define MAAIICONNECT_MEDIA_PLAYED [NSNumber numberWithInt:3]

#pragma mark - Message status for outgoing messages
#define MAAIICONNECT_UPLOAD_FAILED [NSNumber numberWithInt:-2]
#define MAAIICONNECT_UPLOADING [NSNumber numberWithInt:-1]
#define MAAIICONNECT_DELIVERY [NSNumber numberWithInt:0]
#define MAAIICONNECT_SERVERRECEIVED [NSNumber numberWithInt:1]
#define MAAIICONNECT_CLIENTRECEIVED [NSNumber numberWithInt:2]
#define MAAIICONNECT_DELIVERY_FAILED [NSNumber numberWithInt:3]
#define MAAIICONNECT_DISPLAY_RECEPT_RECEIVED [NSNumber numberWithInt:4]

#pragma mark - Message File operation status (fileOpDone) constants
#define MAAIICONNECT_FILEOP_FAILED [NSNumber numberWithInt:-1]
#define MAAIICONNECT_FILEOP_INITIAL [NSNumber numberWithInt:0]
#define MAAIICONNECT_FILEOP_IN_PROGESS [NSNumber numberWithInt:2]
#define MAAIICONNECT_FILEOP_DONE [NSNumber numberWithInt:1]
// TODO: When database schema changed, make numeric value of MAAIICONNECT_FILEOP_DONE largest for easy comparison

#pragma mark - Message type
#define MAAIICONNECT_MESSAGE_NORMAL                 [NSNumber numberWithInt:0]
#define MAAIICONNECT_MESSAGE_STRUCTURED             [NSNumber numberWithInt:1]
#define MAAIICONNECT_MESSAGE_FEATURE_NOT_SUPPORTED  [NSNumber numberWithInt:-2]
#define MAAIICONNECT_MESSAGE_ASSET_ANIMATION        [NSNumber numberWithInt:MaaiiChatAssetCategoryAnimation]
#define MAAIICONNECT_MESSAGE_ASSET_STICKER          [NSNumber numberWithInt:MaaiiChatAssetCategorySticker]
#define MAAIICONNECT_MESSAGE_ASSET_VOICE_STICKER    [NSNumber numberWithInt:MaaiiChatAssetCategoryVoiceSticker]
#define MAAIICONNECT_MESSAGE_MEDIA_ITEM             [NSNumber numberWithInt:2]

#pragma mark - MUC Control message type
#define MAAIICONNECT_MESSAGE_MUC_CONTROL_JOIN               [NSNumber numberWithInt:100]
#define MAAIICONNECT_MESSAGE_MUC_CONTROL_LEAVE              [NSNumber numberWithInt:101]
#define MAAIICONNECT_MESSAGE_MUC_CONTROL_PROPERTY           [NSNumber numberWithInt:102]
#define MAAIICONNECT_MESSAGE_MUC_CONTROL_SUBJECT            [NSNumber numberWithInt:103]
#define MAAIICONNECT_MESSAGE_MUC_CONTROL_THEME              [NSNumber numberWithInt:104]
#define MAAIICONNECT_MESSAGE_MUC_CONTROL_GROUPIMAGE         [NSNumber numberWithInt:105]
#define MAAIICONNECT_MESSAGE_MUC_CONTROL_CHANGE_ROLE_ADMIN  [NSNumber numberWithInt:106]
#define MAAIICONNECT_MESSAGE_MUC_CONTROL_CHANGE_ROLE_MEMBER [NSNumber numberWithInt:107]

#pragma mark - Channel Control message type
#define MAAIICONNECT_MESSAGE_CHANNEL_CONTROL_CHANGE_ROLE_ADMIN  [NSNumber numberWithInt:108]
#define MAAIICONNECT_MESSAGE_CHANNEL_CONTROL_CHANGE_ROLE_MEMBER [NSNumber numberWithInt:109]

#pragma mark - MWIDGET Control message type
#define MAAIICONNECT_MESSAGE_MWIDGET_CONTROL_AGENT_JOIN             [NSNumber numberWithInt:200]
#define MAAIICONNECT_MESSAGE_MWIDGET_CONTROL_INQUIRY_TERMINATED     [NSNumber numberWithInt:201]


#pragma mark - Participant status
#define MAAIICONNECT_PARTICIPANT_JOINED         [NSNumber numberWithInt:1]
#define MAAIICONNECT_PARTICIPANT_LEFT           [NSNumber numberWithInt:2]

#pragma mark - Chatroom type
#define MAAIICONNECT_CHATTYPE_NATIVE    @"NATIVE"
#define MAAIICONNECT_CHATTYPE_FACEBOOK  @"FACEBOOK"
#define MAAIICONNECT_CHATTYPE_WEIBO     @"WEIBO"
#define MAAIICONNECT_CHATTYPE_SYSTEM    @"SYSTEM"
#define MAAIICONNECT_CHATTYPE_UNKNOWN   @"UNKNOWN"

#pragma mark - Chatroom type NSNumber constants
#define MAAIICONNECT_NATIVE             [NSNumber numberWithInt:0]
#define MAAIICONNECT_FACEBOOK_TYPE      [NSNumber numberWithInt:1]
#define MAAIICONNECT_WEIBO_TYPE         [NSNumber numberWithInt:2]
#define MAAIICONNECT_SYSTEM             [NSNumber numberWithInt:3]
#define MAAIICONNECT_UNKNOWN_TYPE       [NSNumber numberWithInt:-1]
#define MAAIICONNECT_MULTIUSER_MIXED    [NSNumber numberWithInt:10]

// Channel related
#define MAAIICONNECT_CHANNEL_PRIVATE     [NSNumber numberWithInt:20]
#define MAAIICONNECT_CHANNEL_PUBLIC      [NSNumber numberWithInt:21]
#define MAAIICONNECT_CHANNEL_ROBOTPUBLIC [NSNumber numberWithInt:22]

// MISC
typedef NS_OPTIONS(NSUInteger,generateDummyRoomMessageDirection)
{
    generateDummyRoomIncoming,
    generateDummyRoomOutgoing,
    generateDummyRoomAlternating
};

#pragma mark - System room ready notification
#define SYSTEM_ROOMS_READY_NOTIFICATION     @"com.maaii.chat.store.system.rooms.ready"

#pragma mark - File Mime Types

extern NSString *const kMaaiiChatFileMimeTypeImage;
extern NSString *const kMaaiiChatFileMimeTypeAudio;
extern NSString *const kMaaiiChatFileMimeTypeVideo;

#pragma mark - Group Attribute Name

extern NSString *const kMaaiiChatRoomAttributeKeyNotification;
extern NSString *const kMaaiiChatRoomAttributeKeySmartNotification;
extern NSString *const kMaaiiChatRoomAttributeKeySubject;
extern NSString *const kMaaiiChatRoomAttributeKeyGroupImage;
extern NSString *const kMaaiiChatRoomAttributeKeyTheme;
extern NSString *const kMaaiiChatRoomAttributeKeyBroadcastOnly;

extern NSString *const kMaaiiChatRoomAttributeValueNotificationOn;
extern NSString *const kMaaiiChatRoomAttributeValueNotificationOff;
extern NSString *const kMaaiiChatRoomAttributeValueNotificationSilent;

#pragma mark - Maaii Chat Asset Type

typedef enum  {
    MaaiiChatAssetCategoryAnimation = 50,
    MaaiiChatAssetCategorySticker = 51,
    MaaiiChatAssetCategoryVoiceSticker = 52,
    MaaiiChatAssetCategoryTheme = 53
} MaaiiChatAssetCategory;

#pragma mark - Maaii Chat Remote Resource Type

typedef enum {
    MaaiiChatMessageResourceTypeRemote
} MaaiiChatMessageResourceType;

#pragma mark - Maaii Chat Remote Resource Network Type

extern NSString *const kMaaiiChatRemoteResourceNetworkTypeYouku;
extern NSString *const kMaaiiChatRemoteResourceNetworkTypeYoutube;
extern NSString *const kMaaiiChatRemoteResourceNetworkTypeItunes;

#pragma mark - NSNotification name for certain events

extern NSString *const kMaaiiChatFileUploadSuccessfulNotification;
extern NSString *const kMaaiiChatFileUploadFailedNotification;
extern NSString *const kMaaiiChatFileDownloadSuccessfulNotification;
extern NSString *const kMaaiiChatFileDownloadFailedNotification;
extern NSString *const kMaaiiChatFileAllocationSuccessfulNotification;
extern NSString *const kMaaiiChatFileAllocationFailedNotification;
extern NSString *const kMaaiiChatFileAllocationFailedUnsupportedFeatureNotification;
extern NSString *const kMaaiiChatMessageFromUserDeliverySuccessfulNotification;
extern NSString *const kMaaiiChatMessageFromUserDeliveryFailedNotification;

#pragma mark - Displayed Receipts
extern BOOL kMaaiiChatDisplayedReceiptsEnabledForGroupChat;

#pragma mark - MaaiiChatListener

@protocol MaaiiChatListener <NSObject>
@required

@optional
-(void) incomingMessage:(MA_Message *)message inRoom:(MA_Room *)room isOfflineMessage:(BOOL)isOfflineMessage;
-(void) roomUpdated:(MA_Room *)room;

-(void) willFileStartDownload:(NSString *)roomId msgId:(NSString *)msgId fileDownloadURL:(NSString *)url;
-(void) didDownloadFile:(NSString *)roomId msgId:(NSString *)msgId alreadyDownload:(NSNumber *)alreadyDownload;
-(void) didFinishFileDownload:(NSString *)roomId  msgId:(NSString *)msgId filePath:(NSString *)filePath;
-(void) didDownloadError:(NSString *)roomId  msgId:(NSString *)msgId error:(NSError *)error;

@end

#pragma mark - MaaiiChatSystemNotificationsListener

@protocol MaaiiChatSystemNotificationsListener <NSObject>

@required

/*!
 @abstract
 Invoke when there is any incoming system message in a chatroom.
 
 @param store 
 The MaaiiChatStore instance delivering the message.
 
 @param type
 The type of the notification
 
 @param attributes
 The parsed attributes of the system notification
 
 @param body
 The body of the message which is expected to be displayed
 
 @param messageDate
 The delivered time of the message
 
 @param expectedBody
 The reference of the body text which is desired to display. Setting a value to its referee will override the body of the message
 
 @param expectedChatType
 The reference of the desired chat type. Setting a value to its referee will override the type of the room this message is delivered.
 
 @discussion
 Refer to the page at http://issuetracking.maaii.com:8090/display/MAAIIP/MP0001+-+Platform+Notifications for details about the type and attributes of the system message.
 
 */
- (BOOL)incomingSystemMessageInStore:(MaaiiChatStore *)store
     shouldSaveSystemMessageWithType:(NSString *)type
                          attributes:(NSDictionary *)attributes
                                body:(NSString *)body
                         messageDate:(NSDate *)messageDate
                        expectedBody:(NSString **)expectedBody
                    expectedChatType:(NSNumber **)expectChatType;

@end

#pragma mark - MaaiiIncomingMessageListener

@protocol MaaiiIncomingMessageListener <NSObject>

@optional
-(BOOL) wasMessageSeenInRoom:(MA_Room *) room;

@end

#pragma mark - MaaiiChatSender

//Interface for chatRoom owner to receive outgoing message receipts
@protocol MaaiiChatSender <NSObject>

// TODO: Update delegate name to make it grammatically correct, and expose more information in the delegate
@optional
-(void) willMessageSend:(NSString *)msgId;
-(void) didMessageSend:(NSString*) msgId;
-(void) didMessageSendingFailed:(NSString*) msgId;

-(void) willFileStartUpload:(NSString *)roomId msgId:(NSString *)msgId fileUploadURL:(NSString *)url;
-(void) didUploadFile:(NSString *)roomId msgId:(NSString *)msgId alreadyUpload:(NSNumber *)alreadyUpload;
-(void) didFinishFileUpload:(NSString *)roomId  msgId:(NSString *)msgId filePath:(NSString *)filePath;
-(void) didUploadError:(NSString *)roomId  msgId:(NSString *)msgId error:(NSError *)error;

-(void) didServerReceived:(NSString *) msgId;
-(void) didClientReceived:(NSString *) msgId;
-(void) didDisplayedReceiptReceived:(NSString *) msgId;

@end

#pragma mark - SDK 
extern BOOL MaaiiChatStoreIgnoreSystemMessages;

#pragma mark - Dummy Payload

@interface DummyRoomMessagePayload : NSObject

@property (nonatomic, strong) NSString *roomId;
@property (nonatomic, strong) NSString *messageId;
@property (nonatomic, strong) NSString *content;
@property (nonatomic, assign) NSUInteger contentLength;
@property (nonatomic, assign) CGFloat contentEmojiPercentage;
@property (nonatomic, assign) generateDummyRoomMessageDirection direction;
@property (nonatomic, strong) NSNumber *status;
@property (nonatomic, strong) NSNumber *type;
@property (nonatomic, strong) NSDate *arrivalDate;
@property (nonatomic, strong) MaaiiGeoLocation *geoLocation;
@property (nonatomic, strong) NSString *attachedCID;
@property (nonatomic, strong) NSString *attachedFileID;
@property (nonatomic, strong) NSString *attachedThumbnail;
@property (nonatomic, strong) NSString *attachURL;
@property (nonatomic, strong) NSString *attachType;
@property (nonatomic, strong) NSNumber *fileSize;
@property (nonatomic, strong) NSNumber *mediaDuration;
@property (nonatomic, strong) NSNumber *ephemeralExpiration;
@property (nonatomic, strong) NSString *expiredDate;
@property (nonatomic, strong) NSString *filename;
@property (nonatomic, strong) NSNumber *fileOpDone;
@property (nonatomic, strong) NSString *tags;
@property (nonatomic, strong) NSDictionary *senderDictionary;

+ (instancetype)createDummyRoomMessagePayload;

+ (instancetype)createDummyRoomMessageWithPayload:(DummyRoomMessagePayload *)payload;

+ (instancetype)createDummyRoomMessagePayloadWithMessageId:(NSString *)messageId
                                                   content:(NSString *)content
                                             contentLength:(NSUInteger)contentLength
                                    contentEmojiPercentage:(CGFloat)contentEmojiPercentage
                                                 direction:(generateDummyRoomMessageDirection)direction
                                                    status:(NSNumber *)status
                                                      type:(NSNumber *)type
                                               arrivalDate:(NSDate *)arrivalDate
                                                  location:(MaaiiGeoLocation *)location
                                               attachedCID:(NSString *)attachedCID
                                            attachedFileID:(NSString *)attachedFileID
                                         attachedThumbnail:(NSString *)attachedThumbnail
                                                 attachURL:(NSString *)attachURL
                                                attachType:(NSString *)attachType
                                                  fileSize:(NSNumber *)fileSize
                                             mediaDuration:(NSNumber *)mediaDuration
                                       ephemeralExpiration:(NSNumber *)ephemeralExpiration
                                               expiredDate:(NSString *)expiredDate
                                                  filename:(NSString *)filename
                                                fileOpDone:(NSNumber *)fileOpDone
                                                      tags:(NSString *)tags
                                          senderDictionary:(NSDictionary *)senderDictionary;

@end

#pragma mark - MaaiiChatStore

@interface MaaiiChatStore : NSObject {
    BOOL _fullQueryMemberShipInProgress;

    NSString *_username;
    NSString *_carrierName;
    dispatch_queue_t _backgroundQueue;
    dispatch_queue_t _notificationQueue;
    id               _multiChatDelegate;
    id               _multiChatSender;
    id<MaaiiChatSystemNotificationsListener> _systemNotificaionsListener;
    id<MaaiiIncomingMessageListener> _incomingMessageListener;

    MA_Room          *_systemRoom;

    // Main thread MOC for NSFetchedResultsControllers
    NSManagedObjectContext *_defaultManagedObjectContext;
    
    // Worker MOC for normal CRUD operations of the database
    NSManagedObjectContext *_workerManagedObjectContext;
    
    // Read only background MOC, for long running background tasks, e.g. Spotlight indexing, Bulk download Chat participants profiles
    NSManagedObjectContext *_readOnlyBackgroundContext;
    
    NSMutableDictionary *pendingMessagesForRooms;
    NSCache *_unreadCountCache; // Dictionary that keeps track of rooms - read/unread status.

}

@property (nonatomic, readonly) dispatch_queue_t backgroundQueue;
@property (nonatomic, readonly) MA_Room          *systemRoom;

-(void) resetAll;
-(void) addDelegate:(id<MaaiiChatListener>) delegate;
-(void) removeDelegate:(id<MaaiiChatListener>) delegate;
-(void) addSender:(id<MaaiiChatSender>) sender;
-(void) removeSender:(id<MaaiiChatSender>) sender;
-(void) setSystemNotificationsListener:(id<MaaiiChatSystemNotificationsListener>) listener;
-(void) setIncomingMessageListener:(id<MaaiiIncomingMessageListener>) listener;

#pragma mark - NSFetchedResultsController instances

// Justin 20150722 This method is only existing in M800SDK
-(NSFetchedResultsController *) broadcastMessagesFetchedResultsController;
// Justin 20150722 This method is only existing in M800SDK
-(NSFetchedResultsController *) messagesFetchedResultsControllerForBroadcastMessage:(MABroadcast*) broadcastMessage;

-(NSFetchedResultsController *) roomsFetchedResultsController;
-(NSFetchedResultsController *) roomsFetchedResultsController_background;
-(NSFetchedResultsController *) roomsForGroupsFetchedResultsController;
-(NSFetchedResultsController *) messagesFetchedResultsControllerForRoom:(MA_Room *) room;
- (NSFetchedResultsController *)messagesFetchedResultsControllerForRooms:(NSArray *)rooms;
- (NSFetchedResultsController *)messagesFetchedResultsControllerForRooms:(NSArray *)rooms
                                                               groupedBy:(NSString *)groupedBy
                                                                sortedBy:(NSString *)sortedBy
                                                               ascending:(BOOL)ascending;
- (NSFetchedResultsController *)messagesFetchedResultsControllerForRoom:(MA_Room *)room
                                                           withPageSize:(NSUInteger)pageSize
                                                             fetchLimit:(NSUInteger)fetchLimit
                                                            fetchOffset:(NSUInteger)fetchOffset;

-(NSFetchedResultsController *) messagesWithDisplayableMediaFetchedResultsControllerForRoom:(MA_Room *)room;
// Matthew 20160217 This method is required by LiveConnect
- (NSFetchedResultsController *)fetchedResultsControllerForMediaTypeMessagesInRooms:(NSArray *)rooms withMIMETypes:(NSArray *)mimeTypes groupedBy:(NSString *)groupedBy;
-(NSInteger) countMessagesWithDisplayableMediaForRoom:(MA_Room *)room;
-(NSFetchedResultsControllerWithPagination *) messagesFetchedResultsControllerForRoom:(MA_Room *) room pageSize:(int) pageSize numberOfPagesFromTheEnd:(int) numberOfPages;

- (NSArray<NSString *> *)distinctChatParticipantJids_background;

#pragma mark - Accessors, Contructors and Mutators of MA_Room and MA_Message instances

- (MA_Room *)roomWithUsername:(NSString *)username
                      carrier:(NSString *)carrier
                socialNetwork:(NSString *)socialNetwork
             socialIdentifier:(NSString *)socialIdentifier
       participantDisplayName:(NSString *)participantDisplayName;

- (MA_Room *)getRoom:(NSString *) roomId;
- (MA_Room *)getRoom:(NSString *) roomId inContext:(NSManagedObjectContext *) context;
- (MA_Room *)getRoomWithURIRepresentation:(NSURL *)uri;
- (MA_Room *)roomWithJID:(NSString *)jid type:(NSNumber *)type participantDisplayName:(NSString *)displayName;
- (MA_Room *)roomWithInquiryId:(NSString *)inquiryId tagId:(NSString *)tagId;
- (void)queryOrCreateRoomWithJID:(NSString *)jid
                            type:(NSNumber *)type
          participantDisplayName:(NSString *)displayName
                      completion:(void(^)(MA_Room *room))completion;

- (MA_Message *) getMessage:(NSString *) msgId;

- (NSUInteger) getUnreadRoomsCount;
- (NSUInteger) getUnreadMessagesCount;
- (BOOL) hasUnreadMessagesInRoomForID:(NSString *)roomID;
- (void) markMessagesReadInRoomForID:(NSString *)roomID completion:(void(^)())completion;
- (NSInteger)unreadMessageCountInRoomForID:(NSString *)roomID;
- (NSInteger)unreadMessageCountInRoomForID:(NSString *)roomID forceClearCache:(BOOL)forceClearCache;
- (BOOL)hasUserEverSentMessageInRoom:(MA_Room *)room;
- (NSUInteger)numberOfMessagesInRoomForID:(NSString *)roomID;
- (MA_Message *)firstUnreadMessageInRoomForID:(NSString *)roomID;
- (NSInteger)numberOfMessagesInRoomForID:(NSString *)roomID inclusiveAfterDate:(NSDate *)date;

// msgIds is the array of messageId (NSStrings)
- (void)removeMessagesWithArray:(NSArray *)msgIds  Room:(MA_Room *) room;

- (void)deleteRoomWithIdentifier:(NSString *)roomId
           withCompletionHandler:(void (^)())completion
                  failureHandler:(void (^)(NSError *error))failure;

- (void)resendUnsentMessagesAfterDate:(NSDate *)date;
- (void)resetMessagesWithFileOpetationInProgress;

#pragma mark - Message Delivery Public methods

-(void) sendMessage:(NSString *)msg
        destRoomSet:(NSSet*)rooms
               tags:(NSString*)tags
        forIdentity:(MaaiiIdentity*)identity
    withGeoLocation:(MaaiiGeoLocation *)geoLocation;

- (void)sendMessage:(NSString *)msg
               room:(MA_Room *)room
              msgId:(NSString *)msgid
               tags:(NSString *)tags
        forIdentity:(MaaiiIdentity *)identity
    withGeoLocation:(MaaiiGeoLocation *)geoLocation;

- (void)sendMessages:(NSArray *)msgs
                room:(MA_Room *)room
         forIdentity:(MaaiiIdentity *)identity;

- (void)sendMessage:(DummyRoomMessagePayload*)messagePayload
         onComplete:(void(^)(BOOL didComplete))onComplete;

- (void)sendMessages:(NSArray <DummyRoomMessagePayload *> *)messagePayloads
          onComplete:(void(^)(BOOL didComplete))onComplete;

- (void)resendMesssage:(MA_Message *)msg
           forIdentity:(MaaiiIdentity *)identity;

-(void) resendBroadcastMessage: (MABroadcast *)broadcastMessage
                   forIdentity: (MaaiiIdentity*)identity
               withGeoLocation: (MaaiiGeoLocation*)geoLocation;

- (void)sendEphemeralMessageWithBase64EncodedImage:(NSString *)imageDataBase64
                                       destRoomSet:(NSSet *)rooms
                                          mimeType:(NSString *)mimeType
                                     mediaDuration:(NSNumber *)duration
                               ephemeralExpiration:(NSNumber *)ephemeralExpiration
                                              tags:(NSString *)tags
                                       forIdentity:(MaaiiIdentity *)identity
                                   withGeoLocation:(MaaiiGeoLocation *)geoLocation;

- (void)sendEphemeralMessageWithBase64EncodedImage:(NSString *)imageDataBase64
                                         messageId:(NSString *)msgid
                                              room:(MA_Room *)room
                                          mimeType:(NSString *)mimeType
                                     mediaDuration:(NSNumber *)duration
                               ephemeralExpiration:(NSNumber *)ephemeralExpiration
                                              tags:(NSString *)tags
                                       forIdentity:(MaaiiIdentity *)identity
                                   withGeoLocation:(MaaiiGeoLocation *)geoLocation;

- (void)fileSharingWithFileURL:(NSURL *)fileURL
                     thumbnail:(NSString *)thumbnail
                          room:(MA_Room *)room
                         msgId:(NSString *)msgid
                      fileType:(NSString*)fileType
                      fileSize:(NSNumber *)fileSize
                 mediaDuration:(NSNumber*)mediaDuration
                       expired:(NSString *)expired
                attachFileName:(NSString *)filename
                          tags:(NSString *)tags
                   forIdentity:(MaaiiIdentity *)identity
               withGeoLocation:(MaaiiGeoLocation *)geoLocation;

- (void)fileSharing:(NSData *)file
          thumbnail:(NSString *)thumbnail
               room:(MA_Room *)room
              msgId:(NSString *)msgid
           fileType:(NSString *)fileType
           fileSize:(NSNumber *)fileSize
            expired:(NSString *)expired
     attachFileName:(NSString *)filename
               tags:(NSString *)tags
        forIdentity:(MaaiiIdentity *)identity
    withGeoLocation:(MaaiiGeoLocation *)geoLocation;

/** Live Connect Usecase
 @param useSenderJID    Indicate which JID to use for MFS allocation. YES indicated sender JID will be used. NO indicated participant JID will be used.
 @param persistFile     Indicate whether the MFS should persist the file. Right now the file path is specified inside the API.
 **/
- (void)fileSharing:(NSData *)file
          thumbnail:(NSString *)thumbnail
               room:(MA_Room *)room
              msgId:(NSString *)msgid
           fileType:(NSString *)fileType
           fileSize:(NSNumber *)fileSize
            expired:(NSString *)expired
     attachFileName:(NSString *)filename
               tags:(NSString *)tags
        forIdentity:(MaaiiIdentity *)identity
    withGeoLocation:(MaaiiGeoLocation *)geoLocation
       useSenderJID:(BOOL)useSenderJID
        persistFile:(BOOL)persistFile;

- (void)fileForward:(NSString *)msgid
        newFileName:(NSString *)filename
           oldMsgid:(NSString *)oldMsgId
               room:(MA_Room *)room
        forIdentity:(MaaiiIdentity *)identity;

- (void)redoFileSharing:(MA_Room *)room
                  msgId:(NSString *)msgid
            forIdentity:(MaaiiIdentity *)identity;

/** Live Connect Usecase
 @param useSenderJID    Indicate which JID to use for MFS allocation. YES indicated sender JID will be used. NO indicated participant JID will be used.
 @param persistFile     Indicate whether the MFS should persist the file. Right now the file path is specified inside the API.
 **/
- (void)redoFileSharing:(MA_Room *)room
                  msgId:(NSString *)msgid
            forIdentity:(MaaiiIdentity *)identity
           useSenderJID:(BOOL)useSenderJID
            persistFile:(BOOL)persistFile;

-(void) redoBroadCastFileSharing:(MABroadcast*) msg
                     forIdentity:(MaaiiIdentity*)identity
                 withGeoLocation:(MaaiiGeoLocation*)geoLocation;

- (void)assetSharingWithMessageId:(NSString *)msgId
                             room:(MA_Room *)room
                  thumbnailBase64:(NSString *)thumbnailBase64
                         category:(MaaiiChatAssetCategory)category
                       identifier:(NSString *)assetID
                        packageID:(NSString *)packageID
                             tags:(NSString *)tags
                      forIdentity:(MaaiiIdentity *)identity
                  withGeoLocation:(MaaiiGeoLocation *)geoLocation;

- (void)shareRemoteResouceToRoom:(MA_Room *)room
                 resourceNetwork:(NSString *)network
              resourceAttributes:(NSDictionary *)resourceAttributes
                            tags:(NSString *)tags
                     forIdentity:(MaaiiIdentity *)identity
                 withGeoLocation:(MaaiiGeoLocation *)geoLocation;

#pragma mark - Specific operations to specific types of messages

- (void)setEphemeralMessageAsExpiredWithMessageId:(NSString*)msgid;

- (void)downloadAssetOfCategory:(MaaiiChatAssetCategory)assetCategory
                     identifier:(NSString *)assetId
                     completion:(void (^)(NSURL *url, NSError *error))completion;

- (void)setMediaAsPlayedForMessageWithId:(NSString *)messageId;

#pragma mark - Get the directoy of directories for storing file sharing and encrypted ephemeral data

- (void)fileDownloadForMessage:(MA_Message *)message
             completionHandler:(void(^)(MA_Message *message))completion
                failureHandler:(void(^)(MA_Message *message, NSError *error))failure
           grantFileNameUnique:(BOOL)grantFileNameUnique;

- (void)fileDownloadForMessage:(MA_Message *)message
             completionHandler:(void(^)(MA_Message *message))completion
                failureHandler:(void(^)(MA_Message *message, NSError *error))failure;

- (void)cancelFileOp:(MA_Room *)room
               msgid:(NSString *)msgid;

-(NSString *) getFileShareLocalDirectory;

-(NSString *) getEphemeralDataLocalDirectory;

#pragma mark - Misc

-(void) initializeForUsername:(NSString *) username onCarrier:(NSString *) carrierName;
-(BOOL) isSystemUser:(NSString *) jid;
-(NSString *) createSystemRoomId:(NSString *) roomName;
- (void)generateDataWithNumberOfRooms:(NSUInteger)numberOfRooms
              numberOfMessagesPerRoom:(NSUInteger)numberOfMessagesPerRoom
                       messagePayload:(DummyRoomMessagePayload *)messagePayload
                           onComplete:(void(^)(BOOL didComplete))onComplete;

#pragma mark - Getting the current progress of file upload/download operation for message

- (NSNumber*) getProgressForMessageId:(NSString*)msgId;
- (void) setProgressForMessageId:(NSString*)msgId withProgress:(CGFloat)progress;
- (void) removeProgressForMessageId:(NSString*)msgId;

#pragma mark - Displayed receipt

- (void)sendDisplayedReceiptMessage:(MA_Message *)message;

- (void)retrySendingDisplayedReceipts;

#pragma mark - Shared instance

+(MaaiiChatStore *) sharedInstance;

- (void)shareFileWithFileURL:(NSURL*)fileURL
                   thumbnail:(NSString*)thumbnail
                   roomArray:(NSArray*)roomArray
                    fileSize:(NSNumber *)fileSize
                    fileType:(NSString*)fileType
                fileDuration:(NSNumber*)mediaDuration
                     expired:(NSString *)expired
              attachFileName:(NSString *)filename
                         tag:(NSString*)tags
                 geoLocation:(MaaiiGeoLocation*)geoLocation;


- (void)shareFileWithData:(NSData*)data
                thumbnail:(NSString*)thumbnail
                roomArray:(NSArray*)roomArray
                 fileSize:(NSNumber *)fileSize
                 fileType:(NSString*)fileType
             fileDuration:(NSNumber*)mediaDuration
                  expired:(NSString *)expired
           attachFileName:(NSString *)filename
                      tag:(NSString*)tags
              geoLocation:(MaaiiGeoLocation*)geoLocation;


- (void)refreshLastMessageWithRooms:(NSArray *)rooms
                         completion:(void(^)())completion;

@end
