//
//  MaaiiAddressBookManager.h
//  Maaii
//
//  Created by Kevin Lo on 3/2/15.
//
//

#import <Foundation/Foundation.h>
#import "MA_ABContact.h"

@interface MaaiiAddressBookManager : NSObject

@property (nonatomic, retain) NSString *countryCode2A;

- (MA_ABContact *)getAddressBookInfo:(ABRecordID)recordID inAddressBook:(ABAddressBookRef)addressBook;

- (NSArray *)addressBookContactsForPhoneNumber:(NSString *)phoneNumber inAddressBook:(ABAddressBookRef)addressBookRef;

- (UIImage *)thumbnailForAddressBookRecordID:(ABRecordID)recordID inAddressBook:(ABAddressBookRef)addressBookRef;

- (UIImage *)thumbnailForAddressBookContact:(MA_ABContact *)addressBookContact;

#pragma mark - Backgrounr Thead API

- (UIImage *)thumbnailForAddressBookRecordID_background:(ABRecordID)recordID;

- (NSString *)findFirstJidAmongMultipleJids_background:(NSDictionary *)jidToPhones forAddressBookRecordID:(ABRecordID)recordID;

- (NSComparisonResult)compareByModificationDateWithRecordID_background:(ABRecordID)recordID1 toRecordID:(ABRecordID)recordID2;


#pragma mark - Public helpers

- (NSString *)formatE164PhoneNumber:(NSString *)phoneNumber;

#pragma mark - Singleton

+ (instancetype)sharedInstance;

@end
