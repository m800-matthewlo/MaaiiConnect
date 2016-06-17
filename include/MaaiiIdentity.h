//
//  MaaiiIdentity.h
//  MaaiiConnect
//
//  Created by Dima Gutzeit on 26/9/12.
//
//

#import <Foundation/Foundation.h>

@interface MaaiiIdentity : NSObject {
    NSString *_type;
    NSString *_name;
    NSString *_identityId;
}

@property(nonatomic, retain) NSString *type;
@property(nonatomic, retain) NSString *name;
@property(nonatomic, retain) NSString *identityId;

-(id) initWithType:(NSString *) type name:(NSString *) name id:(NSString *) identityId;

@end
