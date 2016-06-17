//
//  MaaiiUser.h
//  MaaiiConnect
//
//  Created by Cyrus on 5/9/12.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "ExtendedManagementObject.h"

@class MANativeContact;
@class MA_Profile;

@interface MaaiiUser : MA_ExtendedManagedObject

@property (nonatomic, retain) NSNumber *contactId;
@property (nonatomic, retain) NSString *jid;
@property (nonatomic, retain) NSString *phone;
@property (nonatomic, retain) NSString *normalizedPhone;
@property (nonatomic, retain) NSString *carrier;
@property (nonatomic, retain) NSString *status;
@property (nonatomic, retain) MANativeContact *nativeContact;
@property (nonatomic, retain) NSNumber *verified;
@property (nonatomic, retain) NSNumber *blocked;

//@@@ Cyrus AddOn
@property (nonatomic, retain) NSString * primitiveJid;
@property (nonatomic, retain) NSString * primitivePhone;
@property (nonatomic, retain) NSString * primitiveNormalizedPhone;
@property (nonatomic, retain) NSString * primitiveCarrier;

@end

@interface MaaiiUser (CoreDataGeneratedAccessors)

- (void)addMyContacts:(NSSet *)values;
- (void)removeMyContacts:(NSSet *)values;

@end
