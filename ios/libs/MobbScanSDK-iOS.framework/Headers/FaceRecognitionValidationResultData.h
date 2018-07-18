//
//  FaceRecognitionValidationResultData.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 22/10/15.
//  Copyright © 2015 Mobbeel Solutions. All rights reserved.
//

#import <MobbScanSDK-iOS/MobbScanSDK-iOS.h>

/** Specific data object returned as result of the check validation with type MobbScanValidationType_ESIDCardV2_FACE */
@interface FaceRecognitionValidationResultData : MobbScanValidationResultData

/** The image captured of the face of the current user */
@property (nonatomic, strong) UIImage *currentFace;
/** The image of the face extracted from the document */
@property (nonatomic, strong) UIImage *documentFace;

@end
