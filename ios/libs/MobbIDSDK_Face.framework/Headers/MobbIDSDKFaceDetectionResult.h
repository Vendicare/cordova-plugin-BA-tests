//
//  MobbIDSDKFaceDetectionResult.h
//  MobbIDFramework
//
//  Copyright (c) 2015 Mobbeel Solutions, SLL. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MobbIDAPIFaceDetectionResult.h"

@interface MobbIDSDKFaceDetectionResult : NSObject

@property (nonatomic) CGRect rect;
@property (nonatomic) float angleYaw;
@property (nonatomic) MobbIDAPIFaceOrientation orientation;
@property (nonatomic) MobbIDAPIFaceQuality quality;
@property (nonatomic) float smileEstimation;
@property (nonatomic) float timestamp;

@end
