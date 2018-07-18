//
//  MobbScanFaceValidationParams.h
//  MobbScanSDK-iOS
//
//  Copyright © 2018 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MobbScanAPITypes.h"

/**
 Class to customize the type of face validation to be perfomed.
 */
@interface MobbScanFaceValidationParams : NSObject

/** The type of face validation to be performed. */
@property (nonatomic, assign) MobbScanFaceValidationMode faceValidationMode;

/** To select the camera to be used for the validation. */
@property (nonatomic, assign) MobbScanCameraType cameraType;

@end
