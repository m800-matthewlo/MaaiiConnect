//
//  SocialContact.h
//  MaaiiConnect
//
//  Created by Cyrus on 5/9/12.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "MAContact.h"

@class MASocialNetwork;

@interface MASocialContact : MAContact

@property (nonatomic, retain) NSString * email;
@property (nonatomic, retain) NSString * firstNameOrFullName;
@property (nonatomic, retain) NSString * lastName;
@property (nonatomic, retain) NSString * middleName;
@property (nonatomic, retain) NSString * pictureUrl;
@property (nonatomic, retain) NSString * pictureSquareUrl;
@property (nonatomic, retain) NSString * profileUrl;
@property (nonatomic, retain) NSString * coverImageUrl;
@property (nonatomic, retain) NSString * sex;
@property (nonatomic, retain) NSString * socialId;
@property (nonatomic, retain) NSString * socialName;
@property (nonatomic, retain) MASocialNetwork *socialNetwork;
@property (nonatomic, retain) NSNumber * verified;

@property(nonatomic, readonly) NSString *displayName;

@end
