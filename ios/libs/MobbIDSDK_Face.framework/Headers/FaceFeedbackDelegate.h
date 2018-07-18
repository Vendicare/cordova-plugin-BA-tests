//
//  FaceFeedbackDelegate.h
//  MobbIDFramework
//
//  Created by Abraham Holgado Garcia on 27/05/15.
//  Copyright (c) 2015 Mobbeel Solutions, SLL. All rights reserved.
//

#ifndef MobbIDFramework_FaceFeedbackDelegate_h
#define MobbIDFramework_FaceFeedbackDelegate_h

#import "MobbIDAPIFaceDetectionResult.h"
#import "MobbIDSDKFaceDetectionResult.h"

/**
 This delegate deals with all the feedback that you could receive as an integrator of the FaceView.
 
 You should use it when you want to build your own fully customized UI.
 */
@protocol FaceFeedbackDelegate <NSObject>

@optional

/**
 This method gets called each time a face is detected in the image.
 
 @param faceDetectionResult MobbIDSDKFaceDetectionResult object with all the information about the face detection.
 */
- (void)onFaceDetection:(MobbIDSDKFaceDetectionResult*)faceDetectionResult;

/**
 This method gets called each time a face is processed for liveness detection. It informs of the status of the liveness detection and next action that should be performed by the user regarding the liveness detection.
 
 @param status MobbIDAPIFaceLivenessDetectionStatus The current status of the liveness detection. The final value when liveness detection is enabled (for HeadMovement) will be MobbIDAPIFaceLivenessDetectionStatusCheckedCenterFinal is the user is able to finish the movement.
 @param nextAction MobbIDAPIFaceLivenessDetectionAction The next action expected from the user in order to pass the liveness detection.
 */
- (void)livenessDetectionStatus:(MobbIDAPIFaceLivenessDetectionStatus)status nextAction:(MobbIDAPIFaceLivenessDetectionAction)nextAction;

/**
 This method gets called each time a new face sample has been analyzed, informing of the progress of the full recognition process.
 
 @param progressOK the percentage of advance, it gets to 100 when the current operation (enrollment/verification/identification) has finished sucessfully.
 @param progressKO the percentage of 'wrong advance', it gets to 100 when the maximum number of invalid samples has been received (the operation will end).
 */
- (void)progressUpdateWithProgressOK:(float)progressOK progressKO:(float)progressKO;

/**
 This method gets called each time the SDK detects a change in the "overall" status of the face recognition process (enrollment/verification). It will only inform of persistent situations and one message at a time, for instance, if faces are not being detected for a while or the user is too close or too far from the camera.
 
 @param newStatus MobbIDAPIFaceFeedbackStatus The current status of the recognition process.
 */
- (void)summaryStatusUpdated:(MobbIDAPIFaceFeedbackStatus)newStatus;

@end

#endif
