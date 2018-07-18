//
//
//  Created by Rodrigo Sánchez Gonzáleza on 02/07/14.
//  Copyright 2014 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 The possible orientations of a detected face, i.e. where the user is looking at.
 */
typedef NS_ENUM(NSInteger, MobbIDAPIFaceOrientation) {
    MobbIDAPIFaceOrientationFrontal = 0,
    MobbIDAPIFaceOrientationRight = 1,
    MobbIDAPIFaceOrientationLeft = 2,
    MobbIDAPIFaceOrientationNotDetected = 3,
};
/** Return MobbIDAPIFaceOrientation enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDAPIFaceOrientation(MobbIDAPIFaceOrientation value);

/**
 The quality of the detected face, useful for giving feedback to the user when the face doesn't have enough quality.
 */
typedef NS_ENUM(NSInteger, MobbIDAPIFaceQuality) {
    MobbIDAPIFaceAcquisitionCorrect = 0,
    MobbIDAPIFaceAcquisitionBadIlumination,
    MobbIDAPIFaceAcquisitionTooFar,
    MobbIDAPIFaceAcquisitionTooClose,
    MobbIDAPIFaceAcquisitionTooFacingRight,
    MobbIDAPIFaceAcquisitionTooFacingLeft,
    MobbIDAPIFaceAcquisitionTooCentered,
    MobbIDAPIFaceAcquisitionNotCentered,    
    MobbIDAPIFaceAcquisitionNoFace
};
/** Return MobbIDAPIFaceQuality enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDAPIFaceQuality(MobbIDAPIFaceQuality value);

/**
 The possible states of the liveness detection process. It always starts with NotStarted and it will finish with  MobbIDAPIFaceLivenessDetectionStatusCheckedCenterFinal (if the user is able to complete the whole head movement).
 
 ** Only useful with liveness detection activated **
 */
typedef NS_ENUM(NSInteger, MobbIDAPIFaceLivenessDetectionStatus) {
    MobbIDAPIFaceLivenessDetectionStatusNotStarted = 0,
    MobbIDAPIFaceLivenessDetectionStatusCheckedCenterInitial,
    MobbIDAPIFaceLivenessDetectionStatusCheckedLeft,
    MobbIDAPIFaceLivenessDetectionStatusCheckedCenterMedium,
    MobbIDAPIFaceLivenessDetectionStatusCheckedRight,
    MobbIDAPIFaceLivenessDetectionStatusCheckedCenterFinal
};
/** Return MobbIDAPIFaceLivenessDetectionStatus enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDAPIFaceLivenessDetectionStatus(MobbIDAPIFaceLivenessDetectionStatus value);

/**
 The next action to be done by the user in order to pass the liveness detection process. If ActionNone, it means that liveness detection has finished and then you could check the status for knowing if it is an impostor or a real user.
 
 ** Only useful with liveness detection activated **
 */
typedef NS_ENUM(NSInteger, MobbIDAPIFaceLivenessDetectionAction) {
    /** The user should look to the center. This is the normal user's position */
    MobbIDAPIFaceLivenessDetectionActionLookStraightAhead = 0,
    /** The user should look to his/her left */
    MobbIDAPIFaceLivenessDetectionActionLookLeft,
    /** The user should look to his/her right */
    MobbIDAPIFaceLivenessDetectionActionLookRight,
    /** The user should smile (and keep the smile on his/her face) */
    MobbIDAPIFaceLivenessDetectionActionSmile,
    /** The user should stop smiling */
    MobbIDAPIFaceLivenessDetectionActionStopSmiling
};
/** Return MobbIDAPIFaceLivenessDetectionAction enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDAPIFaceLivenessDetectionAction(MobbIDAPIFaceLivenessDetectionAction value);

/**
 The current status of the face recognition process. 
 It sums up the current state and it will only change when the situation persists during a significative amount of time.
 */
typedef NS_ENUM(NSInteger, MobbIDAPIFaceFeedbackStatus) {
    /** Everything is going as expected */
    MobbIDAPIFaceFeedbackStatusOk = 0,
    /** No faces are being detected */
    MobbIDAPIFaceFeedbackStatusNoFace,
    /** The user is placed too close to the device's camera */
    MobbIDAPIFaceFeedbackStatusLocationTooCloseMoveAway,
    /** The user is placed too far from the device's camera */
    MobbIDAPIFaceFeedbackStatusLocationTooFarMoveCloser,
    /** The samples that are being captured do not have enough quality for the face recognition process. It could be because a very strong back light, a bad ilumination, etc. */
    MobbIDAPIFaceFeedbackStatusEnvBadIllumination,
    /** The device is not placed vertical and in line with the user's face */
    MobbIDAPIFaceFeedbackStatusEnvBadAnglePitch,
    /** The user is not placed correctly. He/she should be looking straight ahead and centered within the screen*/
    MobbIDAPIFaceFeedbackStatusLocationNotCentered,
    /** The user is not placed correctly. His/her head is turned to left but he/she should be looking straight ahead*/
    MobbIDAPIFaceFeedbackStatusLocationTooFacingLeft,
    /** The user is not placed correctly. His/her head is turned to right but he/she should be looking straight ahead*/
    MobbIDAPIFaceFeedbackStatusLocationTooFacingRight,
    /** The user is not placed correctly. He/she is looking straight ahead but his/her head should be turned to the side (which side is informed using MobbIDAPIFaceLivenessDetectionAction) */
    MobbIDAPIFaceFeedbackStatusLocationShouldTurnHead
};
/** Return MobbIDAPIFaceFeedbackStatus enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDAPIFaceFeedbackStatus(MobbIDAPIFaceFeedbackStatus value);

@interface MobbIDAPIFaceDetectionResult : NSObject

@property (nonatomic) CGRect rect;
@property (nonatomic) CGRect rectMargin;
@property (nonatomic) MobbIDAPIFaceOrientation orientation;
@property (nonatomic) MobbIDAPIFaceQuality quality;
@property (nonatomic) MobbIDAPIFaceLivenessDetectionStatus currentStatus;
@property (nonatomic) MobbIDAPIFaceLivenessDetectionAction nextAction;
@property (nonatomic) int globalQuality;
@property (nonatomic) float angleYaw;
@property (nonatomic) float smileEstimation;
@property (nonatomic) float timestamp;
@property (nonatomic) BOOL hasGlasses;

@end
