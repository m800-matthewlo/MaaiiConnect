//
//  MaaiiChatStore+MaaiiChatStore_MUC.h
//  MaaiiConnect
//
//  Created by Dima Gutzeit on 15/10/12.
//
//
#import "MaaiiChatStore.h"

@interface MaaiiChatStore (MUC)

-(void) MUC_createRoom:(NSArray *) participants properties:(NSArray *) properties subject:(NSString *) subject
              complete:(void (^)(MA_Room *))completeBlock error:(void(^)(NSError *))errorBlock;
-(void) MUC_inviteToRoom:(NSArray *) participants room:(MA_Room *) room complete:(void (^)(MA_Room *))completeBlock error:(void(^)(NSError *))errorBlock;
-(void) MUC_leaveRoom:(MA_Room *) room complete:(void (^)(BOOL))completeBlock error:(void(^)(NSError *))errorBlock;
-(void) MUC_kickParticipant:(NSDictionary *) participantDictionary fromRoom:(MA_Room *) room complete:(void (^)(MA_Room *))completeBlock error:(void(^)(NSError *))errorBlock;
-(void) MUC_queryMembershipAndCreateRoomsWithNewSchema:(BOOL)isV2 completeBlock:(void (^)(BOOL))completeBlock error:(void(^)(NSError *))errorBlock;
- (void)clearGroupMemberShipQueryStatus;

// Legacy support, will be removed when all our projects upgrate to schema v2
-(void) MUC_queryMembershipAndCreateRoomsWithCompleteBlock:(void (^)(BOOL))completeBlock error:(void(^)(NSError *))errorBlock;
-(void) MUC_queryMembershipForSingleRoom:(NSString *)roomId;
-(void) MUC_setRoomProperty:(NSString *) name value:(NSString *)value data:(NSString *)data  room:(MA_Room *) room complete:(void (^)(MA_Room *room))completeBlock error:(void(^)(NSError *error))errorBlock;
-(NSString *) MUC_getRoomPropertyForRoom:(MA_Room *)room withAttributeName:(NSString *)name;

- (BOOL)MUC_isSmartNotificationEnabledInChatroom:(MA_Room *)room;

- (void)MUC_setAdmin:(BOOL)yes
                room:(MA_Room *)room
         participant:(MA_Participant *)participant
            complete:(void (^)(MA_Room *))completeBlock
               error:(void (^)(NSError *))errorBlock;


- (NSFetchedResultsController *)MUC_allParticipantsFetchedResultsController:(MA_Room *)room;

@end
