//
//  NativeContact.h
//  MaaiiConnect
//
//  Created by Cyrus on 5/9/12.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "MAContact.h"

@class MaaiiUser;
@class MA_ABContact;

//@@@Cyrus AddOn
@protocol ContactSectionProvider <NSObject>
@optional
- (NSString*) sectionTitle:(NSString *)name;
@end

@interface MANativeContact : MAContact

@property (nonatomic, retain) NSString * displayName;
@property (nonatomic, retain) NSString * firstName;
@property (nonatomic, retain) NSString * lastName;
@property (nonatomic, retain) NSNumber * contactId;
@property (nonatomic, retain) NSString * sortIndex;
@property (nonatomic, retain) NSString * order;
@property (nonatomic, retain) NSSet *maaiiUsers;

//@@@Cyrus AddOn
@property (nonatomic, retain) id<ContactSectionProvider> sectionProvider;
@property (nonatomic, retain) NSString * primitiveDisplayName;
@property (nonatomic, retain) NSString * primitiveSortIndex;

@end

@interface MANativeContact (CoreDataGeneratedAccessors)

- (void)addMaaiiUsersObject:(MaaiiUser *)value;
- (void)removeMaaiiUsersObject:(MaaiiUser *)value;
- (void)addMaaiiUsers:(NSSet *)values;
- (void)removeMaaiiUsers:(NSSet *)values;


//@@@Cyrus AddOn
- (void) rebuildDisplayName:(MA_ABContact *)person;
- (void) generateSectionIndex;
@end
