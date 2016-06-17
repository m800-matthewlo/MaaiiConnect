//
//  MA_Message.h
//  MaaiiConnect
//
//  Created by Cyrus on 30/10/12.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class MA_Participant, MA_Room, MAMediaItem, MABroadcast, MASMSReceipt, MAMessageInfo;

@interface MA_Message : NSManagedObject

@property (nonatomic, retain) NSString * mediaDurationStr; // Media duration
@property (nonatomic, retain) NSString * ephemeralExpirationStr; // Ephemeral expiration
@property (nonatomic, retain) NSString * tags;
@property (nonatomic, retain) NSString * content;
@property (nonatomic, retain) NSDate * date;
@property (nonatomic, retain) NSNumber * direction;
@property (nonatomic, retain) NSDate * fileExpireDate;
@property (nonatomic, retain) NSString * fileId;
@property (nonatomic, retain) NSString * fileCId;
@property (nonatomic, retain) NSString * fileMimeType;
@property (nonatomic, retain) NSString * filename;
@property (nonatomic, retain) NSNumber * filesize;
@property (nonatomic, retain) NSString * fileThumbnail;
@property (nonatomic, retain) NSString * fileURL;
@property (nonatomic, retain) NSNumber * geoLat;
@property (nonatomic, retain) NSNumber * geoLon;
@property (nonatomic, retain) NSString * geoText;
@property (nonatomic, retain) NSString * messageId;
@property (nonatomic, retain) NSString * roomId;
@property (nonatomic, retain) NSString * sectionDate;
@property (nonatomic, retain) NSNumber * sequence;
@property (nonatomic, retain) NSNumber * status;
@property (nonatomic, retain) NSNumber * type;
@property (nonatomic, retain) NSNumber * fileOpDone;
@property (nonatomic, retain) NSString * assetPackageID;
@property (nonatomic, retain) MA_Room *room;
@property (nonatomic, retain) MA_Participant *sender;
@property (nonatomic, retain) MAMediaItem *mediaItem;
@property (nonatomic, retain) MABroadcast *broadcastOwner;
@property (nonatomic, retain) MASMSReceipt *smsReceipt;

@property (nonatomic, retain) NSSet *messageInfo;

//@@@Cyrus AddOn
@property (nonatomic, retain) NSDate   * primitiveDate;
@property (nonatomic, retain) NSString * primitiveSectionDate;

//@@@Kevin AddOn for media duration
@property (atomic, readwrite, assign) NSNumber * mediaDuration;

//@@@Kevin AddOn for epthmeral message
@property (atomic, readwrite, assign) NSNumber * ephemeralExpiration;
@property (readonly) BOOL isEphemeral;
@property (readwrite, assign) NSData* ephemeralData;

//@@@Kevin Helper
@property (readonly) NSString* localFilePath;

@property (readonly) NSString *uniqueFilePath;
@property (readonly) BOOL isControlMessage;

@end

@interface MA_Message (CoreDataGeneratedAccessors)

- (void)addMessageInfoObject:(MAMessageInfo *)values;
- (void)removeMessageInfoObject:(MAMessageInfo *)values;
- (void)addMessageInfo:(NSSet *)values;
- (void)removeMessageInfo:(NSSet *)values;

@end
