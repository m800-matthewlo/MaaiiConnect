//
//  MACountry.h
//  MaaiiConnect
//
//  Created by Cullen Sun on 16/9/14.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
@class MARate;
@class MACountryLocalization;

@interface MACountry : NSManagedObject

@property (nonatomic, retain) NSString * callCode;
@property (nonatomic, retain) NSString * code2A;
@property (nonatomic, retain) NSString * code3A;
@property (nonatomic, retain) NSString * mcc;
@property (nonatomic, retain) NSSet *countryLocalization;
@property (nonatomic, retain) NSSet *rates;

@end

@interface MACountry (CoreDataGeneratedAccessors)

- (void)addCountryLocalizationObject:(MACountryLocalization *)value;
- (void)removeCountryLocalizationObject:(MACountryLocalization *)value;
- (void)addCountryLocalization:(NSSet *)values;
- (void)removeCountryLocalization:(NSSet *)values;


- (void)addRateObject:(MARate *)value;
- (void)removeRateObject:(MARate *)value;

@end
