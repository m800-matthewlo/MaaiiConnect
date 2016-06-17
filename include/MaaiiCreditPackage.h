//
//  MaaiiPackageInfo.h
//  MaaiiConnect
//
//  Created by Peter Ho on 15/7/15.
//
//

#import <Foundation/Foundation.h>
#import "MaaiiCreditInfo.h"

typedef enum {
    kCreditInfoSMS = 998,
    kCreditInfoMinute = 999
} CreditInfoType;

@interface MaaiiCreditPackage : NSObject <NSCoding>
{
    NSString *_packageId;
    NSString *_packageName;
    NSArray *_creditInfoArray;
    NSArray *_countries;
    NSNumber *_expirationTimestamp;
}

@property (nonatomic, readonly) NSString *packageId;
@property (nonatomic, readonly) NSString *packageName;
@property (nonatomic, readonly) NSArray *creditInfoArray;
@property (nonatomic, readonly) NSArray *countries;
@property (nonatomic, readonly) NSDate *expirationTimestamp;

- (id)init;
- (id)initWithJson:(NSString *)jsonStr;
- (id)initWithDictionary:(NSDictionary *)dict;
- (NSDictionary *)dictionary;
- (NSDate *)expirationDateFromMillisecondTimestamp:(BOOL)flag;

- (MaaiiCreditInfo *)getCreditInfoByType:(CreditInfoType)type;

@end
