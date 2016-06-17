//
//  StoreItem.h
//  MaaiiConnect_2.2
//
//  Created by Kevin Lo on 11/9/13.
//
//

#import <Foundation/Foundation.h>
@class SKProduct;

typedef NS_ENUM(NSUInteger, MAStoreItemProductType) {
    
    MAStoreItemProductTypeFeature,
    MAStoreItemProductTypeMinute,
    MAStoreItemProductTypeDownload,
    MAStoreItemProductTypeCredit,
    MAStoreItemProductTypeUnknown
    
};
@interface MAStoreItem : NSObject

@property (nonatomic, readonly) NSString *identifier;
@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSString *itemDescription;
@property (nonatomic, readonly) NSString *publisher;
@property (nonatomic, readonly) NSString *iconImagePath;
@property (nonatomic, readonly) NSString *previewFilePath;
@property (nonatomic, readonly) NSSet *categories;
@property (nonatomic, readonly) NSUInteger display;
@property (nonatomic, readonly) NSDictionary *attributes;
@property (nonatomic, readonly) BOOL isFree;
@property (nonatomic, readonly) NSString *priceString;
@property (nonatomic, readonly) BOOL isConsumable;
@property (nonatomic, readonly) MAStoreItemProductType productType;
@property (nonatomic, readonly) NSString *detailsText;
@property (nonatomic, readonly) NSString *copyrightText;

@property (nonatomic, retain) SKProduct *product;

@property (nonatomic, readonly) NSURL *iconImageURL;
@property (nonatomic, readonly) NSURL *previewFileURL;

- (id)initWithDictionary:(NSDictionary *)itemDic;
+ (instancetype)itemWithDictionary:(NSDictionary *)itemDic;
- (NSString*)productTypeString;

@end
