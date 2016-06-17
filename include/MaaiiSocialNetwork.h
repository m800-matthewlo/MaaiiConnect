//
//  MaaiiSocialNetwork.h
//  MaaiiConnect
//
//  Created by Dima Gutzeit on 28/8/12.
//
//

#import <Foundation/Foundation.h>

@interface MaaiiSocialNetwork : NSObject <NSCoding> {
    NSString *_networkType; // One of: FACEBOOK, WEIBO, TWITTER, LINKEDIN, GOOGLE, FOURSQUARE
    NSString *_integrationMethod; // One of: CLIENT, SERVER
    NSArray *_attributes;
}

@property (nonatomic, readonly) NSString *networkType;
@property (nonatomic, readonly) NSString *integrationMethod;
@property (nonatomic, readonly) NSArray *attributes;

-(id) init;
-(id) initWithDictionary:(NSDictionary *)dict;

@end
