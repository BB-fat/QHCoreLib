//
//  QHNetworkImageApi.h
//  QHCoreLib
//
//  Created by Tony Tang on 2017/6/8.
//  Copyright © 2017年 Tencent. All rights reserved.
//

#import <QHCoreLib/QHNetworkHttpApi.h>

@class UIImage;
@class QHNetworkImageApiResult;

@interface QHNetworkImageApi : QHNetworkHttpApi

QH_NETWORK_API_DECL(QHNetworkImageApi, QHNetworkImageApiResult);

@end

@interface QHNetworkImageApiResult : QHNetworkHttpApiResult

QH_NETWORK_API_RESULT_DECL(QHNetworkImageApi, QHNetworkImageApiResult);

@property (nonatomic, readonly) UIImage *image;

@end