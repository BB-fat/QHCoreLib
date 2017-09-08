//
//  QHListCommonData+protected.h
//  QHCoreLib
//
//  Created by changtang on 2017/9/7.
//  Copyright © 2017年 Tencent. All rights reserved.
//

#import <QHCoreLib/QHListCommonData.h>
#import <QHCoreLib/QHListSimpleData+protected.h>

NS_ASSUME_NONNULL_BEGIN

@interface QHListCommonData ()// (protected)

@property (nonatomic, assign, readwrite) QHListDataRequestType requestType;

@property (nonatomic, assign, readwrite) BOOL hasMore;

// subclasses should implements
- (BOOL)p_isLoading;

- (void)p_doLoadFirst;          // called by load, dirtyLoad, reload
- (void)p_doLoadNext;           // called by loadNext

- (void)p_doCancel;

// subclasses callback
- (void)p_loadSucceed:(NSArray *)list
             userInfo:(NSDictionary * _Nullable)userInfo;

- (void)p_loadFailed:(NSError * _Nullable)error
            userInfo:(NSDictionary * _Nullable)userInfo;

@end

NS_ASSUME_NONNULL_END
