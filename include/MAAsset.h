//
//  MAAsset.h
//  MaaiiConnect_2.3
//
//  Created by Kevin Lo on 28/11/13.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class MAAssetPackage;

@interface MAAsset : NSManagedObject

@property (nonatomic, retain) NSString * category;
@property (nonatomic, retain) NSString * fileHash;
@property (nonatomic, retain) NSString * identifier;
@property (nonatomic, retain) UIImage * previewImage;
@property (nonatomic, retain) NSSet *packages;
@property (nonatomic, readonly) BOOL sharable;

@end
