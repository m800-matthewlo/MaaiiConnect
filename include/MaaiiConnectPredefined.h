//
//  MaaiiConnectPredefined.h
//  MaaiiConnect
//
//  Created by Cyrus Lo on 11/6/12.
//  Copyright (c) 2012 Maaii Limited. All rights reserved.
//

#ifndef MaaiiConnect_MaaiiConnectPredefined_h
#define MaaiiConnect_MaaiiConnectPredefined_h

#include <CoreData/CoreData.h>

#define MA_SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define MA_SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define MA_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define MA_SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define MA_SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)


#define MAAII_CONNECT_VALIDATE_TYPE_IVR     "IVR"
#define MAAII_CONNECT_VALIDATE_TYPE_PASSIVE "PASSIVE"
#define MAAII_CONNECT_VALIDATE_TYPE_SMS     "SMS"

#endif
