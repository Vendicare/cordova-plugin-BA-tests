//
//  ESPIDCardV3.h
//  MobbScanSDK-iOS
//
//  Created by Patri de la Rica on 6/7/16.
//  Copyright © 2016 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ESIDCard.h"

/**
 This class represents the spanish card on its 3.0 version
 */
@interface ESPIDCardV3 : ESIDCard

/** Name of parents */
@property (nonatomic, strong) NSString* parents;
/** Region of residence */
@property (nonatomic, strong) NSString* region;
/** Region of birth */
@property (nonatomic, strong) NSString* regionOfBirth;
/** Address of residence */
@property (nonatomic, strong) NSString* address;
/** City of residence */
@property (nonatomic, strong) NSString* city;
/** City of birth */
@property (nonatomic, strong) NSString* cityOfBirth;
/** Picture of the user */
@property (nonatomic, strong) UIImage* imagePhoto;
/** Picture of the signature of the user */
@property (nonatomic, strong) UIImage* imageSignature;
/** Picture of the document MRZ (Machine Readable Zone) */
@property (nonatomic, strong) UIImage* imageMRZ;

@end
