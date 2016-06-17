//
//  MaaiiContact.h
//  MaaiiConnect
//
//  Created by Cyrus on 9/8/12.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import <AddressBook/AddressBook.h>
#import "MA_ABContact.h"

#define SOURCE_NATIVE @"native"
#define SOURCE_SOCIAL @"social"

@class MANativeContact;

extern NSString *const kMaaiiContactRecommendedSectionName;

@protocol MaaiiContactDelegate <NSObject>
@optional
- (void)syncAddressBookWillStart;
- (void)syncAddressBookDidStart;
- (void)syncAddressBookDidStop;
- (void)rosterFetchError:(NSError *) error;
- (void)rosterWillUpdate;
- (void)rosterDidUpdate;
- (void)blockingInformationDidUpdate;
- (void)statusDidUpdateForUserWithJID:(NSString *)jid;
@end

@interface MaaiiContactStore : NSObject
{
    NSString *_username;
    NSString *_carrierName;
    NSArray  *_deleteContacts;
    id       _multicastDelegate;    
    
    ABAddressBookRef          _addressbookNoti;
    dispatch_queue_t          _backgroundQueue;
    dispatch_queue_t          _addressBookQueue;
    dispatch_queue_t          _notificationQueue;
    BOOL                      _firstRosterUpdateDone;
   }

@property (nonatomic, readonly) NSNumber         *contactsCount;
@property (nonatomic, readonly) ABAddressBookRef addressbookNoti;
@property (nonatomic, readonly) NSNumber         *maaiiContactsCount;
@property (nonatomic, readonly) dispatch_queue_t          backgroundQueue;;

+(MaaiiContactStore *) sharedInstance;
+(ABAddressBookRef) getNativePhoneBook;

- (void)resetAll;
- (void)removeAllMaaiiUser;
- (void)removeAllAddressBookNativeContact;

-(NSNumber *) maaiiContactsCountExceptJids:(NSArray *) jids;

/*
 Method for fast resolving of jids to contacts. Implemented by lazy cache.
 */
-(NSSet *) getContactWithJID:(NSString *)jid;
-(NSSet *) getContactsWithJID_background:(NSString *)jid;

-(void) initializeForUsername:(NSString *) username onCarrier:(NSString *) carrierName;

-(void)           refreshContact:(BOOL) forceRefreshAll;
-(void)           startAddressBookMonitoring;

-(void) syncAddressBook:(BOOL)clearPreviousData
               complete:(void(^)(NSArray *updatedContacts))completeBlock
                  error:(void(^)(NSError *error)) errorBlock;

// delegate 
-(void) addDelegate:(id<MaaiiContactDelegate>) delegate;
-(void) removeDelegate:(id<MaaiiContactDelegate>) delegate;

// fetchController
-(NSFetchedResultsController *) getContactsFetchResultController;
-(NSFetchedResultsController *) getMaaiiContactsFetchResultController;
-(NSFetchedResultsController *) getMaaiiContactsFetchResultController_background;
-(NSFetchedResultsController *) getMaaiiContactsFetchResultControllerExceptJids:(NSArray *) jids;
-(NSFetchedResultsController *) getMaaiiContactsFetchResultControllerExceptJids:(NSArray *)jids includePromptionalUsers:(BOOL)includePromptionalUsers;
-(NSFetchedResultsController *) getMaaiiContactsFetchResultControllerExceptJids:(NSArray *)jids includePromptionalUsers:(BOOL)includePromptionalUsers excludeOtherDomain:(BOOL)includeOtherDomain;

-(NSFetchedResultsController *) getSearchContactsFetchResultController:(NSString *)search;
-(NSFetchedResultsController *) getSearchMaaiiContactsFetchResultController:(NSString *)search;
-(NSFetchedResultsController *) getSearchMaaiiContactsFetchResultController:(NSString *)search exceptJids:(NSArray *)jids includePromptionalUsers:(BOOL)includePromptionalUsers;
-(NSFetchedResultsController *) getSearchMaaiiContactsFetchResultController:(NSString *)search exceptJids:(NSArray *)jids includePromptionalUsers:(BOOL)includePromptionalUsers excludeOtherDomain:(BOOL)excludeOtherDomain;
-(NSFetchedResultsController *) getSearchMaaiiContactsFetchResultController:(NSString *)search exceptJids:(NSArray *) jids;

-(NSArray *) getNonMaaiiContacts;

-(MANativeContact *) getContactWithId:(NSNumber *)contactId;
- (MANativeContact *)getContactWithURIRepresentation:(NSURL *)uri;

-(MA_ABContact *) getAddressBookInfo:(NSNumber *)uid;
-(MA_ABContact *) getAddressBookInfo:(NSNumber *)uid inAddressBook:(ABAddressBookRef) addressBook;
- (NSSet *)allKnownJIDs;

-(void) refreshSectionAndDisplayOrder;

#pragma mark - Helper

- (void)updateDisplayNameForMaaiiContactWithJID:(NSString *)jid newDisplayName:(NSString *)displayName;

#pragma mark - Friend finding related features

- (void)addFriendByJID:(NSString *)jid
            completion:(void(^)())completion
               failure:(void(^)(NSError *error))failure;

- (void)removeFriendByJID:(NSString *)jid
               completion:(void(^)())completion
                  failure:(void(^)(NSError *error))failure;

- (void)blockUserByJID:(NSString *)jid
            completion:(void(^)())completion
               failure:(void(^)(NSError *error))failure;

- (void)unblockUserByJID:(NSString *)jid
              completion:(void(^)())completion
                 failure:(void(^)(NSError *error))failure;

- (BOOL)isBlockedForJID:(NSString *)jid;

- (void)refreshJIDsForBlockedFriendsWithCompletion:(void (^)())completion
                                           failure:(void (^)(NSError *error))failure;

@end
