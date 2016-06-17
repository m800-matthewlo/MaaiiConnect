//
//  MaaiiProvisionInformation.h
//  MaaiiConnect
//
//  Created by Cyrus Lo on 26/6/12.
//  Copyright (c) 2012 Maaii Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const kMaaiiProvisionInformationAllocationIM;
extern NSString *const kMaaiiProvisionInformationAllocationFileServer;
extern NSString *const kMaaiiProvisionInformationAllocationSBC;
extern NSString *const kMaaiiProvisionInformationAllocationSBCPush;

extern NSString *const kMaaiiProvisionInformationAttributeCnSmsAsciiBytePerMsg;

@interface MaaiiProvisionInformation : NSObject <NSCoding, NSCopying>

// allocation(NSDictionary):
//       type: NSString
//       host: NSString
//       port: NSString
// expiration: NSString
//   protocol: NSString
// attributes: NSDictionary* (name/value)
@property (copy) NSArray *allocations;

// attribute(NSDictionary*) (name/value)
@property (copy) NSArray *attributes;

// agreement(NSDictionary)
//      version:NSNumber
//         type:NSString
//  fullTextUrl:NSString
// acceptanceRequired:NSNumber
@property (copy) NSArray *agreements;

// versionUpgrade(NSDictionary)
//        minor:NSNumber
//        major:NSNumber
//        patch:NSNumber
//   identifier:NSString
//     critical:NSNumber
//    updateUrl:NSString
//  releaseNote:NSString
@property (copy) NSDictionary *versionUpgrades;

// socialNetWork(NSDictionary)
//       networkType:NSString
// integrationMethod:NSString
//        attributes:NSDictionary
@property (copy) NSArray *socialNetworks;

/**
 Current country of the device, as seen by the server
 */
@property (copy) NSString *countryCode;

- (NSString *)attributeValueWithKey:(NSString *)key;

- (NSDictionary *)attributesDictionary;

+ (void)saveProvisionInformation:(MaaiiProvisionInformation*)obj;

+ (instancetype)loadProvisionInformation;

+ (void)resetProvisionInformation;

- (id)initWithJson:(NSString *)jsonStr;
- (id)initWithDictionary:(NSDictionary *)dict;

- (void)addAgreement:(NSDictionary *)agreement;
- (void)addVersionUpgrade:(NSDictionary *)version;
- (void)addAllocation:(NSDictionary *)allocation;
- (void)addAttribute:(NSString *)name value:(NSString *)value;

- (NSDictionary *)dictionary;

- (NSURL *)URLForResourceAllocationForType:(NSString *)type
                                 isPrimary:(BOOL)primary;

- (NSURL *)URLForResourceAllocationForType:(NSString *)type
                                 isPrimary:(BOOL)isPrimary
                      additionalAttributes:(out NSDictionary **)additionalAttributes;

#pragma mark - Resource overriding (For backdoor)

+ (void)addOverriddenResourceAllocationForType:(NSString *)type
                                       withURL:(NSURL *)url;

+ (void)removeOveriddenResourceAllocationForType:(NSString *)type;

+ (NSURL *)overriddenResourceAllocationForType:(NSString *)type;

@end
