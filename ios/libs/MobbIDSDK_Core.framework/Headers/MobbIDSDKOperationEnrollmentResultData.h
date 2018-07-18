//
//  MobbIDSDKOperationEnrollmentResultData.h
//  MobbIDSDK_Core
//
//  Created by Maria Luz Mateo Moreno on 13/10/2017.
//  Copyright © 2017 Mobbeel Solutions, SLL. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MobbIDSDKTypes.h"


/**
 Object that holds the information returned by the enrollment process.
 
 @since 3.4
 */
@interface MobbIDSDKOperationEnrollmentResultData : NSObject

/** The user unique identification of the user that is being enrolled. */
@property (nonatomic, copy) NSString * userId;

/** The biometric method for the user's enrollment. */
@property (nonatomic, assign) MobbIDSDKBiometricMethod method;

/** The token returned by the operation. */
@property (nonatomic, copy) NSString * token;

/** The biometric key of the user generated during the enrollment process. Its value dependens on the server configuration (Ask the support team for more information) */
@property (nonatomic, copy) NSString * key;

/** Public key associated with a PKI operation mode. */
@property (nonatomic, copy) NSString * publicKey;

@end
