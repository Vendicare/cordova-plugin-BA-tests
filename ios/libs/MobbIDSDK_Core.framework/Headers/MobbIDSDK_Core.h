//
//  MobbIDSDK_Core.h
//  MobbIDSDK_Core
//
//  Created by Maria Luz Mateo Moreno on 14/12/2017.
//  Copyright © 2017 Mobbeel Solutions, SLL. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for MobbIDSDK_Core.
FOUNDATION_EXPORT double MobbIDSDK_CoreVersionNumber;

//! Project version string for MobbIDSDK_Core.
FOUNDATION_EXPORT const unsigned char MobbIDSDK_CoreVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <MobbIDSDK_Core/PublicHeader.h>

/// Configuration Singleton for the SDK.
#import <MobbIDSDK_Core/MobbIDAPI.h>

/// User's management API
#import <MobbIDSDK_Core/MobbIDManagementAPI.h>

/// Common types for the Framework
#import <MobbIDSDK_Core/MobbIDSDKTypes.h>

/// Biometric delegate that should be adopted by any class performing biometric recognition.
#import <MobbIDSDK_Core/BiometricMethodDelegate.h>

/// Operations result data
#import <MobbIDSDK_Core/MobbIDSDKOperationEnrollmentResultData.h>
#import <MobbIDSDK_Core/MobbIDSDKOperationVerificationResultData.h>
#import <MobbIDSDK_Core/MobbIDSDKExtraResultData.h>
#import <MobbIDSDK_Core/MobbIDSDKOperationCaptureResultData.h>

/// Biometric views.
#import <MobbIDSDK_Core/MobbIDSDKBaseView.h>
#import <MobbIDSDK_Core/MobbIDSDKRecognitionParameters.h>
#import <MobbIDSDK_Core/MobbIDSDKIdentificationRecognitionParameters.h>

/// User-management related delegates
#import <MobbIDSDK_Core/CreateUserDelegate.h>
#import <MobbIDSDK_Core/ConfirmUserDelegate.h>
#import <MobbIDSDK_Core/CheckCreateUserDelegate.h>
#import <MobbIDSDK_Core/CheckOperationAuthorizationDelegate.h>
#import <MobbIDSDK_Core/DeleteUserDelegate.h>
#import <MobbIDSDK_Core/RetrieveUserInformationDelegate.h>
#import <MobbIDSDK_Core/LogoutUserDelegate.h>
#import <MobbIDSDK_Core/CheckLicenseDelegate.h>
#import <MobbIDSDK_Core/DeleteUserEnrollmentDelegate.h>

/// Utils
#import <MobbIDSDK_Core/MobbIDSDKUtils.h>
#import <MobbIDSDK_Core/MobbIDCoreResourceManager.h>
#import <MobbIDSDK_Core/MobbIDSynchronization.h>
#import <MobbIDSDK_Core/MobbIDUser.h>

#import <MobbIDSDK_Core/MobbIDSDKProgressUpdateDelegate.h>


