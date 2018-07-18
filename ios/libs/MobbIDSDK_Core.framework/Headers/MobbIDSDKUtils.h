//
//  MobbIDSDKUtils.h
//  MobbIDFramework
//
//  Created by darthhyoga on 13/06/13.
//  Copyright (c) 2013 Mobbeel. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MobbIDSDKTypes.h"

/**
 Utility class with some convenience methods for the MobbIDSDK
 */
@interface MobbIDSDKUtils : NSObject

/**
 Method to get the the SDK's error from a API's error
 
 @param error NSError error from the API.
 
 @return NSError error from the SDK.
 */
+ (NSError *)sdkErrorFromAPIError:(NSError *)error;

/**
 Method to convert from the SDK's `MobbIDSDKVerificationSampleAttempt` type to the correspondant API one.
 
 @param sampleAttempt MobbIDSDKVerificationSampleAttempt
 
 @return MobbIDAPIVerificationSampleAttempt
 */
+ (MobbIDAPIVerificationSampleAttempt)apiVerificationSampleAttemptFromSdkType:(MobbIDSDKVerificationSampleAttempt)sampleAttempt;


/**
 Method to convert from the SDK's `MobbIDSDKSecurityRecognitionLevel` type to the correspondant API one.
 
 @param levelRecognition MobbIDSDKSecurityRecognitionLevel
 
 @return MobbIDAPISecurityRecognitionLevel
 */
+ (MobbIDAPISecurityRecognitionLevel)apiSecurityRecognitionLevelFrom:(MobbIDSDKSecurityRecognitionLevel)levelRecognition;

@end
