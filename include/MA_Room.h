//
//  MA_Room.h
//  MaaiiConnect
//
//  Created by Cyrus on 4/10/12.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class MA_Attribute, MA_Message, MA_Participant, UIImage;

/**
 * \class MA_Room
 */
@interface MA_Room : NSManagedObject

@property (nonatomic, retain) NSDate * creationDate;
@property (nonatomic, retain) NSDate * lastUpdate;
@property (nonatomic, retain) NSString * roomId;
@property (nonatomic, retain) NSString * themeId;
@property (nonatomic, retain) NSNumber * type;
@property (nonatomic, retain) NSNumber * readOnly;
@property (nonatomic, retain) NSNumber * groupVersion;
@property (nonatomic, retain) NSSet *attributes;
@property (nonatomic, retain) MA_Message *lastMessage;
@property (nonatomic, retain) MA_Message *lastUserMessage;
@property (nonatomic, retain) MA_Participant *owner;
@property (nonatomic, retain) NSSet *participants;

// This property denotes the last incoming message ID that was displayed to a user. Used in displayed receipts retry logic.
@property (nonatomic, retain) NSString *lastDisplayeReceiptMessageId;
// This property denotes the time that last display receipt failed to be sent. Used in displayed receipts retry logic.
@property (nonatomic, retain) NSDate *lastDisplayedReceiptFailure;

// This property denotes first outgoing message's date. Used to detect whether we need to show a stranger alert in chatroom
@property (nonatomic, retain) NSDate *firstOutgoingMessageDate;


@end

@interface MA_Room (CoreDataGeneratedAccessors)

- (void)addAttributesObject:(MA_Attribute *)value;
- (void)removeAttributesObject:(MA_Attribute *)value;
- (void)addAttributes:(NSSet *)values;
- (void)removeAttributes:(NSSet *)values;

- (void)addParticipantsObject:(MA_Participant *)value;
- (void)removeParticipantsObject:(MA_Participant *)value;
- (void)addParticipants:(NSSet *)values;
- (void)removeParticipants:(NSSet *)values;

- (UIImage *)getBase64GroupImage;
- (MA_Participant *)participantInRoomWithJid:(NSString *)jid;

@end
