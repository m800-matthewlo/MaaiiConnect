//
//  MA_Profile.h
//  MaaiiConnect
//
//  Created by Dima Gutzeit on 17/1/13.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "ExtendedManagementObject.h"


@interface MA_Profile : MA_ExtendedManagedObject

@property (nonatomic, retain) NSString *jid;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *image;
@property (nonatomic, retain) NSString *imageURL;
@property (nonatomic, retain) NSString *imageThumbURL;
@property (nonatomic, retain) NSString *email;
@property (nonatomic, retain) NSDate *lastUpdateDate;
@property (nonatomic, retain) NSDate *birthDate;
@property (nonatomic, retain) NSString *gender;
@property (nonatomic, retain) NSNumber *verified;
@property (nonatomic, retain) NSString *appVersion;
@property (nonatomic, retain) NSString *appPlatform;
@property (nonatomic, retain) NSString *coverImage;
@property (nonatomic, retain) NSString *coverImageURL;
@property (nonatomic, retain) NSString *video;
@property (nonatomic, retain) NSString *videoThumbURL;
@property (nonatomic, retain) NSString *videoURL;
@property (nonatomic, readonly) NSNumber *age;

@end
