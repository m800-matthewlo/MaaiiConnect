//
//  MABroadcast.h
//  MaaiiConnect_2.3
//
//  Created by Roy HE on 10/12/13.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class MA_Message, MA_Participant;

@interface MABroadcast : NSManagedObject

@property (nonatomic, retain) NSDate * date;
@property (nonatomic, retain) NSSet *ownMessages;
@property (nonatomic, retain) NSSet *recipients;
@property (nonatomic, retain) MA_Message *templateMessage;
@end

@interface MABroadcast (CoreDataGeneratedAccessors)

- (void)addOwnMessagesObject:(MA_Message *)value;
- (void)removeOwnMessagesObject:(MA_Message *)value;
- (void)addOwnMessages:(NSSet *)values;
- (void)removeOwnMessages:(NSSet *)values;

- (void)addRecipientsObject:(MA_Participant *)value;
- (void)removeRecipientsObject:(MA_Participant *)value;
- (void)addRecipients:(NSSet *)values;
- (void)removeRecipients:(NSSet *)values;

@end
