//
//  NSFetchedResultsControllerWithPagination.h
//  MaaiiConnect
//
//  Created by Dima Gutzeit on 1/10/12.
//
//

#import <Foundation/Foundation.h>

@interface NSFetchedResultsControllerWithPagination : NSObject {
    NSFetchedResultsController *fetchedResultsController;
    int currentPageNumber; // Number of pages that controller has, from the end.
    int remainingPages; // How many pages remain
    int totalItems; // Total number of items
}

@property(nonatomic, retain) NSFetchedResultsController *fetchedResultsController;
@property(nonatomic, assign) int currentPageNumber;
@property(nonatomic, assign) int remainingPages;
@property(nonatomic, assign) int totalItems;

@end
