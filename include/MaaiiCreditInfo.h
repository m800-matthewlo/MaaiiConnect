//
//  MaaiiCreditInfo.h
//  MaaiiConnect
//
//  Created by Cyrus on 8/8/12.
//
//

#define ACCOUNT_OK 0
#define ACCOUNT_INEFFICIENT 1
#define ACCOUNT_OTHERFAULT  2

#define ACCOUNT_STATUS_ACTIVE   1
#define ACCOUNT_STATUS_SUSPEND  2
#define ACCOUNT_STATUS_DEACTIVE 4

#define CREDIT_STATUS_ACTIVE   1
#define CREDIT_STATUS_INACTIVE 0
#define CREDIT_STATUS_EXPIRED  0

#import <Foundation/Foundation.h>

@interface MaaiiCreditInfo : NSObject <NSCoding>

@property (nonatomic, readonly) double currentBalance;
@property (nonatomic, readonly) int currencyCode;
@property (nonatomic, readonly) int accountStatus;
@property (nonatomic, readonly) int creditStatus;
@property (nonatomic, readonly) int priority;
@property (nonatomic, readonly) long long creditExpirationTimestamp;

- (NSDate *)expirationDate;

- (id)initWithJson:(NSString *)jsonStr;
- (id)initWithDictionary:(NSDictionary *)dict;
- (NSDictionary *)dictionary;
- (NSDate *)expirationDateFromMillisecondTimestamp:(BOOL)flag;

- (int)getAccountFlagStatus;

@end
