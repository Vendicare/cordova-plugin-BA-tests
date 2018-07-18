//
//  MobbIDSDKOperationVerificationResultData.h
//  MobbIDSDK_Core
//
//  Created by Maria Luz Mateo Moreno on 13/10/2017.
//  Copyright © 2017 Mobbeel Solutions, SLL. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MobbIDSDKTypes.h"
#import "MobbIDSDKExtraResultData.h"


/**
 Object that holds the information returned by the verification process.
 
 @since 3.4
 */
@interface MobbIDSDKOperationVerificationResultData : NSObject

/** The user unique identification of the user that is being verified. */
@property (nonatomic, copy) NSString * userId;

/** The biometric method for the user's verification. */
@property (nonatomic, assign) MobbIDSDKBiometricMethod method;

/** The token returned by the operation. */
@property (nonatomic, copy) NSString * token;

/** The biometric key of the user re-generated during the verification process. Its value dependens on the server configuration (Ask the support team for more information) */
@property (nonatomic, copy) NSString * key;

/** Signed challenge in PKI approach. */
@property (nonatomic, copy) NSString * signedChallenge;

/**
 A holder for extra result data that will be specified by the different biometric SDKs (if needed)
 */
@property (nonatomic, strong) MobbIDSDKExtraResultData * extra;

@end
