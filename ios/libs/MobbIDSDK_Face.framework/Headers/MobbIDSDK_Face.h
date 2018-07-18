//
//  MobbIDSDK_Face.h
//  MobbIDSDK_Face
//
//  Created by Maria Luz Mateo Moreno on 14/12/2017.
//  Copyright © 2017 Mobbeel Solutions, SLL. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for MobbIDSDK_Face.
FOUNDATION_EXPORT double MobbIDSDK_FaceVersionNumber;

//! Project version string for MobbIDSDK_Face.
FOUNDATION_EXPORT const unsigned char MobbIDSDK_FaceVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <MobbIDSDK_Face/PublicHeader.h>

/// Common types for the Face SDK
#import <MobbIDSDK_Face/MobbIDSDKFaceTypes.h>

/// Biometric view
#import <MobbIDSDK_Face/FaceView.h>

// Face specific features
#import <MobbIDSDK_Face/FaceFeedbackDelegate.h>
#import <MobbIDSDK_Face/FaceCaptureSampleDelegate.h>
#import <MobbIDSDK_Face/MobbIDAPIFaceDetectionResult.h>
#import <MobbIDSDK_Face/MobbIDSDKFaceDetectionResult.h>

#import <MobbIDSDK_Face/MobbIDFaceSynchronization.h>
