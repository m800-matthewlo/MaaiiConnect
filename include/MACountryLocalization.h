//
//  MACountryLocalization.h
//  MaaiiConnect
//
//  Created by Cullen Sun on 16/9/14.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class MACountry;

@interface MACountryLocalization : NSManagedObject

@property (nonatomic, retain) NSNumber * index;
@property (nonatomic, retain) NSString * localization;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSNumber * sectionIndex;
@property (nonatomic, retain) NSString * sectionName;
@property (nonatomic, retain) MACountry *country;

@end
