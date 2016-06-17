//
//  PreviewItemEnumerator.h
//  MaaiiConnect_2.3
//
//  Created by Kevin Lo on 7/11/13.
//
//

#import <Foundation/Foundation.h>

/*!
 @class MAPreviewItemEnumerator
 
 @abstract
 A class for providing a interface to loop through each MAPreviewItem. As this is a subclass of NSEnumeration, 
 it can be enumerated with a for-in loop with each object as an instance MAPreviewItem
 */
@interface MAPreviewItemEnumerator : NSEnumerator

@property (nonatomic, readonly) NSURL *previewItemDirectoryURL;

/*!
 @method
 
 @abstract
 Load the preview file locally after it is downloaded. Return nil if there is anything wrong with the content.
 
 @discussion
 The content of the preview ZIP file has to confirm with the specification at http://issuetracking.maaii.com:8090/display/MAAIIP/Store+Front+Item+Deployment.
 
 @param url
 The file URL of the preview file directory.
 
 @return An instance of MAPreviewItemEnumerator for the preview item inside that directory. Return nil if it cannot be loaded.
 */
+ (instancetype)previewEnumeratorForItemsAtURL:(NSURL *)url;

@end

/*!
 @class MAPreviewItem
 
 @abstract
 A container class of a single preview item of a product
 */
@interface MAPreviewItem : NSObject

@property (nonatomic, readonly) NSString *type;
@property (nonatomic, readonly) UIImage *image;
@property (nonatomic, readonly) NSString *resourceIdentifier;

@end
