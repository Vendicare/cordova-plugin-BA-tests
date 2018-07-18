//
//  FaceCaptureSampleDelegate.h
//  MobbIDFramework
//
//  Created by Abraham Holgado Garcia on 27/05/15.
//  Copyright (c) 2015 Mobbeel Solutions, SLL. All rights reserved.
//

@import Foundation;
@import MobbIDSDK_Core;

#ifndef MobbIDFramework_FaceCaptureSampleDelegate_h
#define MobbIDFramework_FaceCaptureSampleDelegate_h

/**
 The delegate of a Face capture sample View (FaceView) must adopt this protocol to receive the samples of the biometric view.
 */
@protocol FaceCaptureSampleDelegate <NSObject>

@required

/**
 This method gets called each time a face is capture and use for the recognition process.
 
 If the resultCode is `MobbIDSDKOperationCaptureResult_DATA_CAPTURED` then the face sample will be avaiblable in the `face` parameter.
 
 @param resultCode MobbIDSDKOperationCaptureResult The result of the capture operation.
 @param face UIImage Image of the user's face if the result of the operation has been `MobbIDSDKOperationCaptureResult_DATA_CAPTURED`.
 @param errorOccurred NSError If an error has occurred when capturing the face all the information will be available here. For possible error codes for this operation  @see MobbIDSDKErrorCode.
 */
- (void)faceSampleCaptureFinishedWithResult:(MobbIDSDKOperationCaptureResult)resultCode
                                       face:(UIImage*)face
                                      error:(NSError*)errorOccurred;

/**
 This method gets called each time a face template is built and use for the recognition process.
 
 If the resultCode is `MobbIDSDKOperationCaptureResult_DATA_CAPTURED` then the face temaplte will be avaiblable in the `faceTemplate` parameter.
 
 @param resultCode MobbIDSDKOperationCaptureResult The result of the capture operation.
 @param faceTemplate NSData Binary representation of the user's face if the result of the operation has been `MobbIDSDKOperationCaptureResult_DATA_CAPTURED`.
 @param errorOccurred NSError If an error has occurred when capturing the face's template all the information will be available here. For possible error codes for this operation  @see MobbIDSDKErrorCode.
 */
- (void)faceSampleCaptureFinishedWithResult:(MobbIDSDKOperationCaptureResult)resultCode
                                   template:(NSData*)faceTemplate
                                      error:(NSError*)errorOccurred;

@end

#endif
