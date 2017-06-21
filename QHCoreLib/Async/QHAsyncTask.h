//
//  QHAsyncTask.h
//  QHCoreLib
//
//  Created by Tony Tang on 2017/6/12.
//  Copyright © 2017年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <QHCoreLib/QHBase.h>


QH_EXTERN NSString * const QHAsyncTaskErrorDomain;

typedef NS_ENUM(NSUInteger, QHAsyncTaskError) {
    QHAsyncTaskErrorInvalidResult = 1000,
};

typedef NS_ENUM(NSUInteger, QHAsyncTaskState) {
    QHAsyncTaskStateNone,
    QHAsyncTaskStateLoading,
    QHAsyncTaskStateFinished,
    QHAsyncTaskStateCancelled,
};

@class QHAsyncTask;
typedef void (^QHAsyncTaskSuccessBlock)(QHAsyncTask *task, NSObject *result);
typedef void (^QHAsyncTaskFailBlock)(QHAsyncTask *task, NSError *error);

#define QH_ASYNC_TASK_DECL(TASK_TYPE, RESULT_TYPE) \
- (void)startWithSuccess:(void (^)(TASK_TYPE *task, RESULT_TYPE *result))success \
                    fail:(void (^)(TASK_TYPE *task, NSError *error))fail; \
- (Class)resultClass;

@interface QHAsyncTask : NSObject

@property (nonatomic, assign, readonly) QHAsyncTaskState state;

/**
 * the queue to do the real job,
 * default `nil` which use global queue for `QOS_CLASS_DEFAULT`
 */
@property (nonatomic, strong) dispatch_queue_t workQueue;

/**
 * the queue on which callback invoked,
 * default `nil` which use main queue
 */
@property (nonatomic, strong) dispatch_queue_t completionQueue;

/**
 * the queue on which the callback blocks disposed,
 * default `nil` which use main queue
 */
@property (nonatomic, strong) dispatch_queue_t disposeQueue;


QH_ASYNC_TASK_DECL(QHAsyncTask, NSObject);


- (BOOL)isLoading;

/**
 * clear callback blocks but keep task running
 */
- (void)clear;

/**
 * clear callback blocks and stop task running
 */
- (void)cancel;

@end

#define QH_ASYNC_TASK_IMPL_DIRECT(TASK_TYPE, RESULT_TYPE) \
QH_ASYNC_TASK_IMPL_INDIRECT(TASK_TYPE, RESULT_TYPE, QHAsyncTask, NSObject)

#define QH_ASYNC_TASK_IMPL_INDIRECT(TASK_TYPE, RESULT_TYPE, SUPER_TASK_TYPE, SUPER_RESULT_TYPE) \
- (void)startWithSuccess:(void (^)(TASK_TYPE *task, RESULT_TYPE *result))success \
                    fail:(void (^)(TASK_TYPE *task, NSError *error))fail \
{ \
    [super startWithSuccess:(void (^)(SUPER_TASK_TYPE *api, SUPER_RESULT_TYPE *result))success \
                       fail:(void (^)(SUPER_TASK_TYPE *api, NSError *error))fail]; \
} \
- (Class)resultClass \
{ \
    return [RESULT_TYPE class]; \
}