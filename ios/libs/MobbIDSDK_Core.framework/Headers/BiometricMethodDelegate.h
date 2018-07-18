//
//  MobbIDBaseOperationDelegate.h
//  MobbIDAPIDemo
//
//  Created by Abraham Holgado on 24/07/12.
//  Copyright 2012 Mobbeel Solutions. All rights reserved.
//

#import <MobbIDSDK_Core/MobbIDSDKTypes.h>
#import "MobbIDSDKOperationCaptureResultData.h"
#import "MobbIDSDKOperationEnrollmentResultData.h"
#import "MobbIDSDKOperationVerificationResultData.h"


/**
 The delegate of a Biometric Recognition View (VoiceView, IrisView, SignatureView, FaceView and FaceVoiceView) must adopt this protocol to be informed of the result of the biometric operation that the biometric view is performing (enrollment, verification or identification). 
 */
@protocol BiometricMethodDelegate <NSObject>

@optional

/**
 Sent to the delegate when the enrollment operation has finished.
 
 @param resultCode MobbIDFrameworkOperationResult The result of the enrollment process performed by the biometric recognition view.
 @param data MobbIDSDKOperationEnrollmentResultData The data returned by the enrollment operation.
 @param errorOccurred NSError If an error has occurred, all the information will be available here. Possible error codes for this operation are (@see MobbIDSDKErrorCode):
 
 - MobbIDSDKErrorCode_ERROR_USER_FIELD_REQUIRED The userId is mandatory.
 - MobbIDSDKErrorCode_ERROR_USER_DOES_NOT_EXIST The userId specified does not belong to any registered user.
 
 @since 3.4
 */
- (void)enrollmentFinished:(MobbIDSDKOperationEnrollmentResult)resultCode
                      data:(MobbIDSDKOperationEnrollmentResultData *)data
                     error:(NSError *)errorOccurred;

/**
 Sent to the delegate when the verification operation has finished.
 
 @param resultCode MobbIDSDKOperationVerificationResult The result of the verification process performed by the biometric recognition view.
 @param data MobbIDSDKOperationVerificationResultData The data returned by the verification operation.
 @param errorOccurred NSError If an error has occurred, all the information will be available here. Possible error codes for this operation are (@see MobbIDSDKErrorCode):
 
 - MobbIDSDKErrorCode_ERROR_USER_FIELD_REQUIRED The userId is mandatory.
 - MobbIDSDKErrorCode_ERROR_USER_DOES_NOT_EXIST The userId specified does not belong to any registered user.
 
 @since 3.4
 */
- (void)verificationFinished:(MobbIDSDKOperationVerificationResult)resultCode
                        data:(MobbIDSDKOperationVerificationResultData *)data
                       error:(NSError *)errorOccurred;

/**
 Sent to the delegate when the identification operation has finished.
 
 @param users NSArray The array contains all candidates found with the given samples when the result is MobbIDAPIIdentificationDelegateResult_USER_IDENTIFIED, in any other case it will be nil. Each user of the array will be represented by an NSDictionary with two objects:
 
 - NSString with the userId for the key kMobbIDFramework_IdentificationUserKey
 - NSNumber with the score (float) for the key kMobbIDFramework_IdentificationScoreKey
 
 @param resultCode The result of the identification process performed by the biometric recognition view.
 @param errorOccurred NSError If an error has occurred, all the information will be available here. Possible error codes for this operation are (@see MobbIDSDKErrorCode):
 
 - MobbIDSDKErrorCode_ERROR_USER_FIELD_REQUIRED The userId is mandatory.
 - MobbIDSDKErrorCode_ERROR_USER_DOES_NOT_EXIST The userId specified does not belong to any registered user.
 
 @warning Identification mode is *only* avaiable for FaceView and SignatureView at the current version.
 @since 4.0
 */
- (void)identificationFinishedForUsers:(NSArray *)users
                                result:(MobbIDSDKOperationIdentificationResult)resultCode
                                 error:(NSError *)errorOccurred;

/**
 Sent to the delegate when the capture operation has finished.
 
 @param resultCode MobbIDSDKOperationCaptureResult The result of the capture process performed by the biometric recognition view.
 @param data MobbIDSDKOperationCaptureResultData The data returned by the capture operation.
 @param errorOccurred NSError If an error has occurred, all the information will be available here. Possible error codes for this operation are (@see MobbIDSDKErrorCode):
 
 - MobbIDSDKErrorCode_ERROR_USER_FIELD_REQUIRED The userId is mandatory.
 
*/
- (void) captureFinished:(MobbIDSDKOperationCaptureResult)resultCode
                    data:(MobbIDSDKOperationCaptureResultData *)data
                   error:(NSError *)errorOccurred;

@end
