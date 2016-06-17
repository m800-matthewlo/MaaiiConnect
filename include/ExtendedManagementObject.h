//
//  ExtendedManagementObject.h
//  MaaiiConnect
//
//  Created by Dima Gutzeit on 10/10/12.
//
//

#import <Foundation/Foundation.h>

@interface MA_ExtendedManagedObject : NSManagedObject {
    BOOL traversed;
}

@property (nonatomic, assign) BOOL traversed;

- (NSDictionary*) toDictionary;
- (void) populateFromDictionary:(NSDictionary*)dict;
+ (MA_ExtendedManagedObject* ) createManagedObjectFromDictionary:(NSDictionary*)dict
                                                   inContext:(NSManagedObjectContext*)context;

@end
