//
//  MAGiftee.h
//  MaaiiConnect
//
//  Created by Kevin Lo on 28/8/14.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class MATransaction;

/*!
 @typedef
 
 @abstract The possible values of the state of MATransaction
 */
typedef enum : NSUInteger {
    MAGifteeTypeMaaii = 0,
    MAGifteeTypeFacebook = 1
} MAGifteeType;

@interface MAGiftee : NSManagedObject

@property (nonatomic, retain) NSString * userId;
@property (nonatomic, retain) NSNumber * userIdType;
@property (nonatomic, retain) NSSet *transaction;
@end

@interface MAGiftee (CoreDataGeneratedAccessors)

- (void)addTransactionObject:(MATransaction *)value;
- (void)removeTransactionObject:(MATransaction *)value;
- (void)addTransaction:(NSSet *)values;
- (void)removeTransaction:(NSSet *)values;

@end
