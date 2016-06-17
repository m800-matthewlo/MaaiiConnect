//
//  MASMSDeliveryResult.h
//  MaaiiConnect
//
//  Created by Kevin Lo on 26/9/14.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class MA_Message;

@interface MASMSReceipt : NSManagedObject

@property (nonatomic) BOOL isSuccessful;
@property (nonatomic) int32_t segmentTotalCount;
@property (nonatomic) int32_t segmentFailCount;
@property (nonatomic) double costInDollar;
@property (nonatomic, retain) NSString *errorReason;
@property (nonatomic, retain) MA_Message *message;

@end
