//
//  MobbIDSDKFaceTypes.h
//  MobbIDSDK-Face
//
//  Created by Maria Luz Mateo Moreno on 19/09/2017.
//  Copyright © 2017 Mobbeel Solutions, SLL. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  @enum MobbIDSDKFaceLivenessDetectionMode
 *  @brief  All posible modes for the liveness detection for face recognition.
 *
 *  @since 4.7.0
 */
typedef NS_ENUM(NSInteger, MobbIDSDKFaceLivenessDetectionMode) {
    /**
     * Liveness detection for face biometric method base on head movement. The system will ask the user to turn his/her head to confirm liveness.
     */
    MobbIDSDKFaceLivenessDetectionMode_HeadMovement = 0,
    /**
     * Liveness detection for face biometric method base on the user's smile. The system will ask the user to smile during the recognition process.
     */
    MobbIDSDKFaceLivenessDetectionMode_SmileDetection,
    /**
     * No Liveness detection for face biometric is applied.
     */
    MobbIDSDKFaceLivenessDetectionMode_None,
};
/** Return MobbIDSDKFaceLivenessDetectionMode enum values as NSString */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDSDKFaceLivenessDetectionMode(MobbIDSDKFaceLivenessDetectionMode value);

/**
 Block type for selfie capture callback
 */
typedef void (^SelfieCaptureBlock)(NSArray *);
