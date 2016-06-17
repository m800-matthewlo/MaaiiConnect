//
//  MATransactionItemCategory.h
//  MaaiiConnect_2.3
//
//  Created by Kevin Lo on 10/12/13.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class MATransaction;

@interface MATransactionItemCategory : NSManagedObject

@property (nonatomic, retain) NSString * identifier;
@property (nonatomic, retain) NSSet *transactions;
@end

@interface MATransactionItemCategory (CoreDataGeneratedAccessors)

- (void)addTransactionsObject:(MATransaction *)value;
- (void)removeTransactionsObject:(MATransaction *)value;
- (void)addTransactions:(NSSet *)values;
- (void)removeTransactions:(NSSet *)values;

@end
