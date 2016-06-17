//
//  MaaiiPreferenceAttribute.h
//  MaaiiConnect
//
//  Created by Dima Gutzeit on 31/8/12.
//
//

#import <Foundation/Foundation.h>

@interface MaaiiPreferenceAttribute : NSObject {
    NSString *_name; 
    NSString *_value;
    NSString *_action; // One of: SET, DELETE, GET
}

@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSString *value;
@property (nonatomic, readonly) NSString *action;

- (NSDictionary *)dictionary;
- (id)initWithDictionary:(NSDictionary *)dict;
- (id)initWithName:(NSString *)name value:(id)value action:(NSString *)action;

@end
