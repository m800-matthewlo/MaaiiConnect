//
//  Contact.h
//  MaaiiConnect
//
//  Created by Cyrus on 5/9/12.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "ExtendedManagementObject.h"


@interface MAContact : MA_ExtendedManagedObject

@property (nonatomic, retain) NSNumber * isMaaiiUser;
@property (nonatomic, retain) NSString * jid;
@property (nonatomic, retain) NSString * type;

@end
