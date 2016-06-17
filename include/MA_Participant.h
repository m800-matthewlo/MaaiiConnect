//
//  MA_Participant.h
//  MaaiiConnect
//
//  Created by Cyrus on 11/9/12.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "ExtendedManagementObject.h"
#import "MA_Room.h"
@class MA_Profile;

@interface MA_Participant : MA_ExtendedManagedObject

@property (nonatomic, retain) NSString * jid;
@property (nonatomic, retain) NSNumber * type;
@property (nonatomic, retain) NSNumber * statusInRoom;
@property (nonatomic, retain) NSNumber * isAdmin;
@property (nonatomic, retain) NSString * identityId;
@property (nonatomic, retain) NSString * identityType;
@property (nonatomic, retain) NSString * identityDisplayName;
@property (nonatomic, retain) MA_Room * room;

@end
