//
//  MaaiiSocialContact.h
//  MaaiiConnect
//
//  Created by Dima Gutzeit on 28/8/12.
//
//

#import <Foundation/Foundation.h>

@interface MaaiiSocialContact : NSObject <NSCoding> {
    NSString *_networkType; // One of: FACEBOOK, WEIBO, TWITTER, LINKEDIN, GOOGLE, FOURSQUARE
    NSString *_userId;
    NSString *_profileUrl;
    NSString *_pictureUrl;
    NSString *_pictureSquareUrl;
    NSString *_firstNameOrFullName;
    NSString *_middleName;
    NSString *_lastName;
    NSString *_sex;
    NSString *_email;
    NSString *_userType; // One of: APPLICATION_USER, CONNECTED_USER, PENDING_USER,, BLOCKED_USER, UNCONNECTED_USER, NON_APPLICATION_USER, ALL_USER
    NSArray *_networkSpecificAttributes;
    NSString *_socialName;
}

@property (nonatomic, readonly) NSString *networkType;
@property (nonatomic, readonly) NSString *userId;
@property (nonatomic, readonly) NSString *profileUrl;
@property (nonatomic, readonly) NSString *pictureUrl;
@property (nonatomic, readonly) NSString *pictureSquareUrl;
@property (nonatomic, readonly) NSString *firstNameOrFullName;
@property (nonatomic, readonly) NSString *middleName;
@property (nonatomic, readonly) NSString *lastName;
@property (nonatomic, readonly) NSString *sex;
@property (nonatomic, readonly) NSString *email;
@property (nonatomic, readonly) NSString *userType;
@property (nonatomic, readonly) NSArray *networkSpecificAttributes;
@property (nonatomic, readonly) NSString *socialName;

-(id) init;
-(id) initWithDictionary:(NSDictionary *)dict;

@end
