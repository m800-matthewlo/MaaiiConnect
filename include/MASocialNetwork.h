//
//  SocialNetwork.h
//  MaaiiConnect
//
//  Created by Dima Gutzeit on 4/9/12.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "ExtendedManagementObject.h"


@interface MASocialNetwork : MA_ExtendedManagedObject

@property (nonatomic, retain) NSString * socialId;
@property (nonatomic, retain) NSString * socialType;

@end
