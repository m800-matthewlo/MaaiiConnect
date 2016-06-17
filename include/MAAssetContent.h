//
//  MAAssetContent.h
//  MaaiiConnect_2.3
//
//  Created by Kevin Lo on 2/12/13.
//
//

#import <Foundation/Foundation.h>
#import "MaaiiAssetsManagerProtocol.h"

@interface MAAssetContent : NSObject

@property (nonatomic, readonly) NSString *identifier;
@property (nonatomic, readonly) NSString *category;
@property (nonatomic, readonly) UIImage *previewImage;
@property (nonatomic, readonly) NSURL *directoryURL;
@property (nonatomic, readonly) NSDictionary *manifest;

/*!
 @method
 
 @abstract
 Load the image with the specified file name in for the current asset content.
 
 @discussion
 The image loaded will be locally cached as long as this object is not released.
 MaaiiAssetManager will be responsible for handling caching of instances of this class.
 
 @param fileName
 The MAAsset to check whether it is eligible to be shared
 
 @return
 The loaded image in this asset content with specified file name
 
 */
- (UIImage *)imageInAssetContentWithFileName:(NSString *)fileName;

@end
