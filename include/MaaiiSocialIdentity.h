//
//  MaaiiSocialIdentity.h
//  MaaiiConnect
//
//  Created by Dima Gutzeit on 28/8/12.
//
//

#import "MaaiiSocialContact.h"

@interface MaaiiSocialIdentity : MaaiiSocialContact {
	NSString *_authorizationToken;
	NSNumber *_authorizationTokenExpirationTimestamp;
}

@property (nonatomic, readonly) NSString *authorizationToken;
@property (nonatomic, readonly) NSNumber *authorizationTokenExpirationTimestamp;

@end
