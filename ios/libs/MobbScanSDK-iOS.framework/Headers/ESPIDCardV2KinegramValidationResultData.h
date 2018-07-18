//
//  ESIDCardV2KinegramValidationResultData.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 16/07/15.
//  Copyright (c) 2015 Mobbeel Solutions. All rights reserved.
//

#import "MobbScanValidationResultData.h"

/** Specific data object returned as result of the check validation with type MobbScanValidationType_ESIDCardV2_KINEGRAM */
@interface ESPIDCardV2KinegramValidationResultData : MobbScanValidationResultData

/** The image captured when the kinegram is visible while flash light is on, or nil if not succesfully found. */
@property (nonatomic, strong) UIImage* imageKinegramVisible;
/** The image captured when the kinegram is not visible while flash light is off, or nil if not succesfully found. */
@property (nonatomic, strong) UIImage* imageKinegramInvisible;

/** The path to a low frame-rate video saved as an evicence of the process. */
@property (nonatomic, strong) NSString* videoPath;

@end
