//
//  MaaiiVirtualStoreDelegate.h
//  MaaiiConnect_2.3
//
//  Created by Kevin Lo on 4/12/13.
//
//

#import <Foundation/Foundation.h>
@class MaaiiVirtualStore;
@class MATransaction;

@protocol MaaiiVirtualStoreDelegate <NSObject>

@optional

#pragma mark - Downloading purchased content call back
- (void)virtualStore:(MaaiiVirtualStore *)store willStartDownloadingContentForTransaction:(MATransaction *)transaction;
- (void)virtualStore:(MaaiiVirtualStore *)store didStartDownloadingContentForTransaction:(MATransaction *)transaction;
- (void)virtualStore:(MaaiiVirtualStore *)store didUpdateProgress:(double)progress forDownloadingContentForTransaction:(MATransaction *)transaction;
- (void)virtualStore:(MaaiiVirtualStore *)store didFinishDownloadingContentForTransaction:(MATransaction *)transaction;
- (void)virtualStore:(MaaiiVirtualStore *)store didFailDownloadingContentWithError:(NSError *)error forTransaction:(MATransaction *)transaction;
- (void)virtualStore:(MaaiiVirtualStore *)store didRemoveDownloadedContentForTransaction:(MATransaction *)transaction;

#pragma mark - MaaiiVirtualStore
- (void)virtualStoreLanguageDidChange:(MaaiiVirtualStore *)store;

#pragma mark - Gift Notification
- (void)virtualStoreDidReceiveGift:(MaaiiVirtualStore *)store;
- (void)virtualStoreDidViewGifts:(MaaiiVirtualStore *)store forCategory:(NSString *)category;

@end
