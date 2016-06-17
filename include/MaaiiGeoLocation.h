//
//  MaaiiGeoLocation.h
//  MaaiiConnect
//
//  Created by Dima Gutzeit on 12/10/12.
//
//

#import <Foundation/Foundation.h>

@interface MaaiiGeoLocation : NSObject {
    double _accuracy;
    double _lat;
    double _lon;
    double _alt;
    double _bearing;
    
    NSString *_country;
    NSString *_countryCode;
    NSString *_locality;
    NSString *_area;
    NSDate *_timestamp;
    NSString *_text;
    NSString *_description;
}

@property (nonatomic, assign) double accuracy;
@property (nonatomic, assign) double lat;
@property (nonatomic, assign) double lon;
@property (nonatomic, assign) double alt;
@property (nonatomic, assign) double bearing;

@property (nonatomic, retain) NSString *country;
@property (nonatomic, retain) NSString *countryCode;
@property (nonatomic, retain) NSString *locality;
@property (nonatomic, retain) NSString *area;
@property (nonatomic, retain) NSDate *timestamp;
@property (nonatomic, retain) NSString *text;
@property (nonatomic, retain) NSString *description;

@end
