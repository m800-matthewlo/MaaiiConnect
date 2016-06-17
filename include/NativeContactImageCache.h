//
//  NativeContactImageCache.h
//  MaaiiConnect
//
//  Created by Dima Gutzeit on 20/9/12.
//
//

#import <Foundation/Foundation.h>
#import "MA_ABContact.h"

@interface NativeContactImageCache : NSObject

+ (NativeContactImageCache *) sharedInstance;

-(void) setImage:(UIImage *) image forContact:(NSNumber *) contactId;
-(void) setImageFromContact:(MA_ABContact *) contact;
-(UIImage *) imageForContact:(NSNumber *) contactId;

@end
