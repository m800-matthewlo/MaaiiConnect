//
//  MediaItem.h
//  MaaiiConnect_2.2
//
//  Created by Kevin Lo on 11/7/13.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class MA_Message;

@interface MAMediaItem : NSManagedObject

@property (nonatomic, retain) NSNumber * type;
@property (nonatomic, retain) NSString * resourceNetwork;
@property (nonatomic, retain) NSString * roomID;
@property (nonatomic, retain) NSString * embededResourceJSON;
@property (nonatomic, retain) MA_Message *message;

@end
