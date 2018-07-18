//
//  MobbIDBaseView.h
//  MobbIDFramework
//
//  Created by Abraham Holgado García on 24/07/12.
//  Copyright (c) 2012 Mobbeel. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <MobbIDSDK_Core/MobbIDSDKTypes.h>
#import "BiometricMethodDelegate.h"
#import "MobbIDSDKRecognitionParameters.h"

/**
 Base class for all biometric recognition views of the MobbID Framework
 
 @warning **All subclass must override startRecognition and stopRecognition methods.**
 */
@interface MobbIDSDKBaseView : UIView

/**
 The delegate that will be informed of the result from the biometric recognition view.
 */
@property (nonatomic, weak) id<BiometricMethodDelegate> delegate;

/**
 This method kicks off the recognition process in the recognition mode (MobbIDSDKRecognitionMode) specified for the given userId.
 
 The result of the recognition operation will sent to the delegate object.
 
 @param mode Recognition mode (enrollment, verification or identification)
 @param parameters Recognition parameters for the subsequent enrollment/verification.
 
 @exception NSInternalInconsistencyException if this method in invoked other that in a subclass.
 @exception NSInvalidArgumentException if the provided param "securityKey" does not comply with the specifications.
 
 @warning *Important*: This method must be overriden by the extending subclass.
 */
- (void)startRecognitionIn:(MobbIDSDKRecognitionMode)mode withParameters:(MobbIDSDKRecognitionParameters*)parameters;

/**
 This method should be used if the recognition operation should be stopped.
 @exception NSInternalInconsistencyException if this method in invoked other that in a subclass.
 
 @warning *Important*: This method must be overriden by the extending subclass.
 */
- (void)stopRecognition;

@end
