/*
 Erica Sadun, http://ericasadun.com
 iPhone Developer's Cookbook, 3.0 Edition
 BSD License, Use at your own risk
 */

#import <AddressBook/AddressBook.h>
#import <AddressBookUI/AddressBookUI.h>
#import "MA_ABContact.h"

@interface MA_ABGroup : NSObject 
{
	ABRecordRef record;
}

+ (id) group;
+ (id) groupWithRecord: (ABRecordRef) record;
+ (id) groupWithRecordID: (ABRecordID) recordID;
- (BOOL) removeSelfFromAddressBook: (NSError **) error;

@property (nonatomic, readonly) ABRecordRef record;
@property (nonatomic, readonly) ABRecordID recordID;
@property (nonatomic, readonly) ABRecordType recordType;
@property (nonatomic, readonly) BOOL isPerson;

- (NSArray *) membersWithSorting: (ABPersonSortOrdering) ordering;
- (BOOL) addMember: (MA_ABContact *) contact withError: (NSError **) error;
- (BOOL) removeMember: (MA_ABContact *) contact withError: (NSError **) error;

@property (nonatomic, assign) NSString *name;
@property (nonatomic, readonly) NSArray *members; 

@end
