//
//  MobbIDSDKOperationCaptureResultData.h
//  MobbIDSDK_Core
//
//  Created by Maria Luz Mateo Moreno on 30/05/2018.
//  Copyright © 2018 Mobbeel Solutions, SLL. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MobbIDSDKTypes.h"


/**
 Object that holds the information returned by the capture process.
 */
@interface MobbIDSDKOperationCaptureResultData : NSObject

/** The user unique identification of the user which template is to be captured. */
@property (nonatomic, copy) NSString *userId;

/** The biometric method for the user's capture. */
@property (nonatomic, assign) MobbIDSDKBiometricMethod method;

/** The captured biometric template. */
@property (nonatomic, copy) NSData *biometricTemplate;

@end
