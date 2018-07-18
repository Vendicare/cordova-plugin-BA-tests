//
//  FaceView.h
//  MobbIDFramework
//
//  Created by Rodrigo Sanchez on 27/04/15.
//  Copyright (c) 2015 Mobbeel Solutions, SLL. All rights reserved.
//

@import Foundation;
@import MobbIDSDK_Core;

#import "FaceFeedbackDelegate.h"
#import "FaceCaptureSampleDelegate.h"
#import "MobbIDSDKFaceTypes.h"


/**
 FaceView is the Biometric Recognition View that should be used to enroll (register) or verify a user using his/her face as the biometric method.
 
 Before performing any biometric operation (enrollment or verification) please ensure that:
 
 - The user exists (@see MobbIDManagementAPI for more information)
 - The SDK must has been configured properly (@see MobbIDAPI for more information).
 
 To use the FaceView to enroll an existing user you must follow these steps:
 
 1) Create and init FaceView instance ("self" would be the ViewController you're using to integrate the biometric view)
 
 `FaceView *faceView = [[FaceView alloc] initWithFrame:self.view.bounds];`
 
 2) Set up its delegate. It must conform the BiometricMethodDelegate protocol. The delegate does not have to be the ViewController (it could be any class conforming the BiometricMethodDelegate protocol)
 
 `[faceView setDelegate:self];`
 
 3) Add the FaceView as a subview to the ViewController you want to perform the biometric process.
 
 `[self.view addSubview:faceView];`
 
 4) Kicks off the biometric recognition process using the method startRecognitionIn:forUser:
 
 `[faceView startRecognitionIn:MobbIDSDKRecognitionMode_Enrollment forUser:USERID withSecurityKey:SECURITY_KEY];`
 
 5) Stop the biometric recognition process when it is finished (method enrollmentFinishedForUser:result:method: of the BiometricMethodDelegate will be called) using the method stopRecognition:
 
 `[faceView stopRecognition];`
 
 To use the FaceView to verify a previously enrolled user you follow the previous steps:
 
 ` // faceView is init and added as a subview to the ViewController's view.`
 
 `[faceView startRecognitionIn:MobbIDSDKRecognitionMode_Verification forUser:USERID withSecurityKey:nil];`
 
 
 To use the FaceView to identify a previously enrolled user you follow the previous steps and specify the identification type:
 
 `// faceView is init and added as a subview to the ViewController's view.`
 
 `[faceView startRecognitionIn:MobbIDSDKRecognitionMode_Identification forUser:nil withSecurityKey:nil];`
 
 To use the FaceView to capture the samples you have to set up its captureDelegate, conforming the FaceCaptureSampleDelegate. The captureDelegate does not have to be the ViewController (it could be any class conforming the FaceCaptureSampleDelegate).
 
 `[faceView setCaptureDelegate:self];'
 
 If you dont want to perform the recognition you have to use the MobbIDSDKRecognitionMode_Capture in the method startRecognitionIn:forUser:
 
 `[faceView startRecognitionIn:MobbIDSDKRecognitionMode_Capture forUser:USERID withSecurityKey:nil];`
 
 */
@interface FaceView : MobbIDSDKBaseView

/**
 Set this delegate if you want to get the sample information of each face captured.
 */
@property (nonatomic, weak) id<FaceCaptureSampleDelegate> captureDelegate;

/**
 Set this delegate if you want to customized the UI and be informed of every aspect of the status of the face recognition, liveness detection, overall progress, etc. If you set it, the default UI won't be used and you must build your own.
 */
@property (nonatomic, weak) id<FaceFeedbackDelegate> faceFeedbackDelegate;

/**
 Indicates the recognition level that will be applied to the recognition process. This value is a balance between user's convenience and user's security.
 
 **warning** This property only takes effect in offline mode.
 */
@property (nonatomic, assign) MobbIDSDKSecurityRecognitionLevel securityRecognitionLevel;

/**
 Indicates the liveness detection mode that will be check in the recognition process.
 
 MobbIDSDKFaceLivenessDetectionMode_HeadMovement is the default detection mode. 
 */
@property (nonatomic, assign) MobbIDSDKFaceLivenessDetectionMode faceLivenessDetectionMode;

/**
 Enable switch camera feature. This feature should be configured before starting recognition. Default is disabled.
 */
@property (nonatomic) BOOL switchCaptureDevicePositionEnabled;

/**
 Switch between front and rear camera
 */
- (void) switchCaptureDevicePosition;

/**
 Enable selfie photos capture while face recognition
 */
- (void) enableSelfieCapture:(SelfieCaptureBlock)selfieCaptureBlock;

@end
