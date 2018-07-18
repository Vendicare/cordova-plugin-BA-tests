//
//  ESIDCardV2LaserMarkValidationResultData.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 15/07/15.
//  Copyright (c) 2015 Mobbeel Solutions. All rights reserved.
//

#import "MobbScanValidationResultData.h"
#import <UIKit/UIKit.h>

/** Specific data object returned as result of the check validation with type MobbScanValidationType_ESIDCardV2_LASER_MARK */
@interface ESPIDCardV2LaserMarkValidationResultData : MobbScanValidationResultData

/** The image captured when initials are visible due to the flash light coming from the right side of the document. */
@property (nonatomic, strong) UIImage* initialsImage;
/** The image captured when expedition date is visible due to the flash light coming from the left side of the document. */
@property (nonatomic, strong) UIImage* expeditionDateImage;

/** The actual initials captured and extracted by the OCR. */
@property (nonatomic, strong) NSString* initials;
/** The actual expedition date captured and extracted by the OCR. */
@property (nonatomic, strong) NSString* expeditionDate;

/** The path to a low frame-rate video saved as an evicence of the process. */
@property (nonatomic, strong) NSString* videoPath;

@end
