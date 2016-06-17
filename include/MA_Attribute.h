//
//  MA_Attribute.h
//  MaaiiConnect
//
//  Created by Cyrus on 10/9/12.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "ExtendedManagementObject.h"

@class MA_Room;

/**
 * \class MA_Attribute
 */
@interface MA_Attribute : NSManagedObject

@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSString * value;
@property (nonatomic, retain) MA_Room * room;

@end
