//
//  MaaiiSocialContactStore.h
//  MaaiiConnect
//
//  Created by Dima Gutzeit on 3/9/12.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "MASocialContact.h"
#import "MaaiiIdentity.h"

@interface MaaiiSocialContactStore : NSObject {
    
    NSString *_username;
    NSString *_carrierName;
    dispatch_queue_t _backgroundQueue;
    NSFetchedResultsController *_fetchedResultsController;
    
}

@property (nonatomic, readonly) dispatch_queue_t backgroundQueue;

- (NSFetchedResultsController *) fetchedResultsController;
- (NSFetchedResultsController *) fetchedResultsControllerExceptJids:(NSArray *)jids;
- (NSFetchedResultsController *) fetchedResultsControllerExceptJids:(NSArray *)jids excludeOtherDomain:(BOOL)excludeOtherDomain;
- (NSFetchedResultsController *) searchFetchedResultsController:(NSString *)search;
- (NSFetchedResultsController *) searchFetchedResultsController:(NSString *)search exceptJids:(NSArray *)jids;
- (NSFetchedResultsController *) searchFetchedResultsController:(NSString *)search exceptJids:(NSArray *)jids excludeOtherDomain:(BOOL)excludeOtherDomain;

/*!
 @abstract
 Please initialize username and carrier before using this service.
 
 @param username Name of the user on behalf of which the requests will be made.
 
 @param carrierName Name of the carrier on behalf of which the requests will be made.
 
 @discussion Nothing to add.
 */
-(void) initializeForUsername:(NSString *) username onCarrier:(NSString *) carrierName;

/*!
 @abstract
 Attempts to locate a known social contact give the JID (user@domain)
 
 @param jid JID of the target contact
 
 @discussion Nothing to add.
 */
-(MASocialContact *) getSocialContactsByJid:(NSString *) jid onNetwork:(NSString *) networkType;

-(MASocialContact *) getSocialContactsByJid_background:(NSString *) jid onNetwork:(NSString *) networkType;


/*!
 @abstract
 Attempts to locate a known social contact by identity
 
 @param identity Identity of the target contact
 
 @discussion Nothing to add.
 */
-(MASocialContact *) getSocialContactByIdentity:(MaaiiIdentity *) identity;


/*!
 @abstract
 Sends a social roster request, stores the result in internal database for future access and returns the data.
 
 @param networkType Name of the network to query
 
 @param socialId Id on the target network to get the contacts of.
 
 @param applicationUserOnly If TRUE only the application users will be synced.
 
 @param complete Complete block that will be executed upon completion. The array will include all SocialContact elements found.
 
 @param error Error block. Will be invoked with NSError explaining the problem.
 
 @discussion Nothing to add.
 */

// TODO: Support paging ... We need to add another method that will get the contacts directly, without updating internal store.
-(void) refreshSocialContactsOfNetwork:(NSString *) networkType withId:(NSString *) socialId applicationUserOnly:(BOOL) applicationUserOnly
                              complete:(void(^)(NSArray *    /*array of socialContacts*/
                                                )) completeBlock
                                 error:(void(^)(NSError *)) errorBlock;

/*!
 @abstract
 Returns the count of users for a specific network type and social id.
 
 @param networkType Name of the network to query
 
 @param socialId Id on the target network to get the contacts of.
  
 @discussion Nothing to add.
 */
-(NSNumber *) socialContactsCountForNetwork:(NSString *) networkType andId:(NSString *) socialId;

-(NSNumber *) socialContactsCountForNetwork:(NSString *) networkType andId:(NSString *) socialId exceptJids:(NSArray *) jids;

/*!
 @abstract
 Deletes all known social user for some network.
 
 @param networkType Name of the network to query
 
 @param socialId Id on the target network to get the contacts of.
 
 @discussion Nothing to add.
 */
-(void) clearSocialStoreContentsForNetwork:(NSString *) networkType withId:(NSString *) socialId;

/*!
 @abstract
 Deletes all known social user of all networks.
 
 @discussion Nothing to add.
 */
-(void) clearSocialStoreContents;

+ (MaaiiSocialContactStore *) sharedInstance;

@end
