//
//  PresenceStore.h
//  MaaiiConnect
//
//  Created by Dima Gutzeit on 13/9/12.
//
//

#import <Foundation/Foundation.h>

typedef enum {
    Unknown, // Unknown state.
	Active, // Active in the chat room.
	Composing, // Compising a message
    Paused,
    Inactive,
    Gone
} ChatState;

@protocol PresenceDelegate <NSObject>
@optional
-(void) becameOnline:(NSString *) jid;
-(void) becameOffline:(NSString *) jid;
-(void) chatStateChanged:(NSString *) jid state:(ChatState) state mucRoomId:(NSString *)mucRoomId;
@end

@interface PresenceStore : NSObject {
    dispatch_queue_t _backgroundQueue;
    NSMutableDictionary *_onlineStatus;
    NSMutableDictionary *_lastActivityStatus;
    NSMutableDictionary *_chatStates;
    id       _multicastDelegate;
}

@property (nonatomic, readonly) dispatch_queue_t backgroundQueue;

+ (PresenceStore *) sharedInstance;

// Delegate
- (void)addDelegate:(id<PresenceDelegate>) delegate;
- (void)removeDelegate:(id<PresenceDelegate>) delegate;

// Methods towards the application.
- (BOOL)isOnlineUser:(NSString *)jid;
- (void)lastSeenUser:(NSString *)jid withResultBlock:(void (^)(NSString *, NSDate *))completeBlock;

- (ChatState)getCurrentState:(NSString *)jid;
- (ChatState)getCurrentState:(NSString *)jid withMUCRoomId:(NSString *)mucRoomId;

// XEP-0085
-(void) notifyChatState:(ChatState) currentState towards:(NSString *) jid;
// Notify chat state within a MUC room.
- (void)notifyChatState:(ChatState)currentState toMUCRoomWithId:(NSString *)mucRoomId;

// Chanel or service should use the following whenever a status update detected.


@end
