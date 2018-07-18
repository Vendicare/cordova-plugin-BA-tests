//
//  MobbIDSDKRecognitionParameters.h
//  MobbIDFramework
//
//  Created by Rodrigo Sanchez on 28/9/16.
//  Copyright © 2016 Mobbeel Solutions, SLL. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MobbIDSDKRecognitionParameters : NSObject

/** Unique identifier for the user about to be enroll or verified. 
 If the mode is MobbIDSDKRecognitionMode_Identification its value must be nil. */
@property (nonatomic, strong) NSString *userId;
/** A recovery key of 256 bits to be provided only if the mode is MobbIDSDKRecognitionMode_Enrollment. */
@property (nonatomic, strong) NSData *securityKey;
/** If low-level start call has been performed, this field contains the correspondant enrollmentId, verificationId or identificationId */
@property (nonatomic, strong) NSString *operationId;
/** In a PKI approach, this contains the challenge string to be signed as a result of the verification step */
@property (nonatomic, strong) NSString *challenge;

@end
