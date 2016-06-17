//
//  FriendFindingProfile.h
//  MaaiiConnect_2.2
//
//  Created by Kevin Lo on 3/7/13.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "MA_Profile.h"

@class MA_Profile;

@interface MASuggestedProfile : MA_Profile

@property (nonatomic, retain) NSString *reason;
@property (nonatomic, retain) NSNumber *distanceInKilometer;
@property (nonatomic, retain) NSNumber *promoted;
@property (nonatomic, retain) NSNumber *type;
@property (nonatomic, retain) NSNumber *sequence;
@property (nonatomic, retain) NSSet *relatedUsers;

@end

@interface MASuggestedProfile (CoreDataGeneratedAccessors)

- (void)addRelatedUsersObject:(MA_Profile *)value;
- (void)removeRelatedUsersObject:(MA_Profile *)value;
- (void)addRelatedUsers:(NSSet *)values;
- (void)removeRelatedUsers:(NSSet *)values;

@end
