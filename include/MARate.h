//
//  MARate.h
//  MaaiiConnect
//
//  Created by Cullen Sun on 25/8/15.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class MACountry;

typedef enum {
    RateCall = 0,
    RateSMS = 1
} RateType;


@interface MARate : NSManagedObject

@property (nonatomic, retain) NSNumber * blocked;
@property (nonatomic, retain) NSNumber * connectionFee;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSString * homeArea;
@property (nonatomic, retain) NSString * originArea;
@property (nonatomic, retain) NSString * packageId;
@property (nonatomic, retain) NSString * prefixes;
@property (nonatomic, retain) NSNumber * rate;
@property (nonatomic, retain) NSString * rateUnit;
@property (nonatomic, retain) NSNumber * type;
@property (nonatomic, retain) MACountry *country;

@end
