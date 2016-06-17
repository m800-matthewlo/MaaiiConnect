//
//  MaaiiConnectLogging.h
//  MaaiiConnect
//
//  Created by Cyrus Lo on 15/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#ifndef MaaiiConnect_MaaiiConnectLogging_h
#define MaaiiConnect_MaaiiConnectLogging_h

#include "MA_DDLog.h"

extern int maaiiConnectLogLevel;

#ifndef MAAII_CONNECT_LOGGING_ENABLED
#define MAAII_CONNECT_LOGGING_ENABLED 1
#endif

#define MAAII_CONNECT_FLAG_ERROR    (1 << 0)  // 0...00001
#define MAAII_CONNECT_FLAG_WARN     (1 << 1)  // 0...00010
#define MAAII_CONNECT_FLAG_INFO     (1 << 2)  // 0...00100
#define MAAII_CONNECT_FLAG_VERBOSE  (1 << 3)  // 0...01000
#define MAAII_CONNECT_FLAG_TRACE    (1 << 4)  // 0...10000

#define MAAII_CONNECT_LOG_OFF     0
#define MAAII_CONNECT_LOG_ERROR   (MAAII_CONNECT_FLAG_ERROR)                                                          // 0...0001
#define MAAII_CONNECT_LOG_WARN    (MAAII_CONNECT_FLAG_ERROR | MAAII_CONNECT_FLAG_WARN)                                        // 0...0011
#define MAAII_CONNECT_LOG_INFO    (MAAII_CONNECT_FLAG_ERROR | MAAII_CONNECT_FLAG_WARN | MAAII_CONNECT_FLAG_INFO)                      // 0...0111
#define MAAII_CONNECT_LOG_VERBOSE (MAAII_CONNECT_FLAG_ERROR | MAAII_CONNECT_FLAG_WARN | MAAII_CONNECT_FLAG_INFO | MAAII_CONNECT_FLAG_VERBOSE) // 0...1111
#define MAAII_CONNECT_LOG_ALL     (MAAII_CONNECT_FLAG_ERROR | MAAII_CONNECT_FLAG_WARN | MAAII_CONNECT_FLAG_INFO | MAAII_CONNECT_FLAG_VERBOSE | MAAII_CONNECT_FLAG_TRACE) // 0...11111

#define MAAII_CONNECT_LOG_TRACE   (MAAII_CONNECT_FLAG_TRACE) // 0...10000

#if DEBUG
#define MAAII_CONNECT_ASYNC_ENABLED  NO
#else
#define MAAII_CONNECT_ASYNC_ENABLED  YES
#endif

#define MAAII_CONNECT_ASYNC_ERROR   ( NO && MAAII_CONNECT_ASYNC_ENABLED)
#define MAAII_CONNECT_ASYNC_WARN    (YES && MAAII_CONNECT_ASYNC_ENABLED)
#define MAAII_CONNECT_ASYNC_INFO    (YES && MAAII_CONNECT_ASYNC_ENABLED)
#define MAAII_CONNECT_ASYNC_VERBOSE (YES && MAAII_CONNECT_ASYNC_ENABLED)
#define MAAII_CONNECT_ASYNC_TRACE   (YES && MAAII_CONNECT_ASYNC_ENABLED)
#define MAAII_CONNECT_ASYNC_ALL     (YES && MAAII_CONNECT_ASYNC_ENABLED)

#define MAAII_CONNECT_OBJC_MAYBE(async, lvl, flg, ctx, frmt, ...) \
do{ if(MAAII_CONNECT_LOGGING_ENABLED) LOG_MAYBE(async, lvl, flg, ctx, sel_getName(_cmd), frmt, ##__VA_ARGS__); } while(0)

#define MAAII_CONNECT_LOG_C_MAYBE(async, lvl, flg, ctx, frmt, ...) \
do{ if(MAAII_CONNECT_LOGGING_ENABLED) LOG_MAYBE(async, lvl, flg, ctx, __FUNCTION__, frmt, ##__VA_ARGS__); } while(0)


#define MaaiiConnectLogError(frmt, ...)   MAAII_CONNECT_OBJC_MAYBE(MAAII_CONNECT_ASYNC_ERROR,   maaiiConnectLogLevel, MAAII_CONNECT_FLAG_ERROR,   0, frmt, ##__VA_ARGS__)
#define MaaiiConnectLogWarn(frmt, ...)    MAAII_CONNECT_OBJC_MAYBE(MAAII_CONNECT_ASYNC_WARN,    maaiiConnectLogLevel, MAAII_CONNECT_FLAG_WARN,    0, frmt, ##__VA_ARGS__)
#define MaaiiConnectLogInfo(frmt, ...)    MAAII_CONNECT_OBJC_MAYBE(MAAII_CONNECT_ASYNC_INFO,    maaiiConnectLogLevel, MAAII_CONNECT_FLAG_INFO,    0, frmt, ##__VA_ARGS__)
#define MaaiiConnectLogVerbose(frmt, ...) MAAII_CONNECT_OBJC_MAYBE(MAAII_CONNECT_ASYNC_VERBOSE, maaiiConnectLogLevel, MAAII_CONNECT_FLAG_VERBOSE, 0, frmt, ##__VA_ARGS__)
#define MaaiiConnectLogTrace(frmt, ...)    MAAII_CONNECT_OBJC_MAYBE(MAAII_CONNECT_ASYNC_TRACE,   maaiiConnectLogLevel, MAAII_CONNECT_FLAG_TRACE, 0, frmt, ##__VA_ARGS__)
#define MaaiiConnectLogFull(frmt, ...)     MAAII_CONNECT_OBJC_MAYBE(MAAII_CONNECT_ASYNC_ALL,   maaiiConnectLogLevel, MAAII_CONNECT_FLAG_TRACE|MAAII_CONNECT_FLAG_VERBOSE, 0, frmt, ##__VA_ARGS__)

#define MaaiiConnectLogCError(frmt, ...)   MAAII_CONNECT_C_MAYBE(MAAII_CONNECT_ASYNC_ERROR,   maaiiConnectLogLevel, MAAII_CONNECT_FLAG_ERROR,   0, frmt, ##__VA_ARGS__)
#define MaaiiConnectLogCWarn(frmt, ...)    MAAII_CONNECTG_C_MAYBE(MAAII_CONNECT_ASYNC_WARN,   maaiiConnectLogLevel, MAAII_CONNECT_FLAG_WARN,    0, frmt, ##__VA_ARGS__)
#define MaaiiConnectLogCInfo(frmt, ...)    MAAII_CONNECT_C_MAYBE(MAAII_CONNECT_ASYNC_INFO,    maaiiConnectLogLevel, MAAII_CONNECT_FLAG_INFO,    0, frmt, ##__VA_ARGS__)
#define MaaiiConnectLogCVerbose(frmt, ...) MAAII_CONNECT_C_MAYBE(MAAII_CONNECT_ASYNC_VERBOSE, maaiiConnectLogLevel, MAAII_CONNECT_FLAG_VERBOSE, 0, frmt, ##__VA_ARGS__)
#define MaaiiConnectLogCTrace(frmt, ...)    MAAII_CONNECT_C_MAYBE(MAAII_CONNECT_ASYNC_TRACE,   maaiiConnectLogLevel, MAAII_CONNECT_FLAG_TRACE, 0, frmt, ##__VA_ARGS__)
#define MaaiiConnectLogCFull(frmt, ...)     MAAII_CONNECT_C_MAYBE(MAAII_CONNECT_ASYNC_ALL,   maaiiConnectLogLevel, MAAII_CONNECT_FLAG_TRACE|MAAII_CONNECT_FLAG_VERBOSE, 0, frmt, ##__VA_ARGS__)

#endif
