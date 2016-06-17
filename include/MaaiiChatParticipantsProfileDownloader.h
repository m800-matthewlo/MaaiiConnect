//
//  MaaiiChatParticipantsProfileDownloader.h
//  MaaiiConnect
//
//  Created by Cullen Sun on 7/4/16.
//
//  This class was created to download participants profiles for Group Chat, as user profiles wont come
//  with the Group membership query under new schema v2.
//
//  All it's operation is in background with a serial GCD queue
//
//  Instance of this Class is created when
//  1. Application just finished querying group chat memberships upon installation, OR
//  2, Application had finished querying group chat memberships in previous launch, now just connected
//     to IM
//
//  Destroy it when MaaiiChatStore: resetAll


#import <Foundation/Foundation.h>

@interface MaaiiChatParticipantsProfileDownloader : NSObject


/*!
 * @abstract create a instance of MaaiiChatParticipantsProfileDownloader if not yet.
 * It find all the distint MA_Participant JIDs, and futher select those we don't have profile at
 * local Core Data. 
 * Then, query those profiles by batch
 *
 */
+ (void)downloadMissingProfiles;


/*!
 * @abstract destory the downloader, this happens usually when a different user signin the app,
 * and we need to clear all the App's chatting data.
 * 
 * Then, if another user sign in, above method +(void)downloadMissingProfiles will create another
 * instance and do all the downloading work
 */
+ (void)resetDownloader;

@end
