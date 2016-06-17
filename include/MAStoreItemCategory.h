//
//  StoreItemCategory.h
//  MaaiiConnect_2.2
//
//  Created by Kevin Lo on 11/9/13.
//
//

#import <Foundation/Foundation.h>

@interface MAStoreItemCategory : NSObject

@property (nonatomic, readonly) NSString *identifier;
@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSString *categoryDescription;
@property (nonatomic, readonly) NSString *parentCategoryIdentifier;
@property (nonatomic, readonly) NSString *iconImagePath;
@property (nonatomic, readonly) NSUInteger display;
@property (nonatomic, readonly) NSDictionary *attributes;

@property (nonatomic, readonly) NSURL *iconImageURL;

- (id)initWithDictionary:(NSDictionary *)categoryDic;
+ (instancetype)categoryWithDictionary:(NSDictionary *)categoryDic;

@end