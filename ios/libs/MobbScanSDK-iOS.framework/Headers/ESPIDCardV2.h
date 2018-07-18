//
//  ESIDCard2.h
//  MobbScanSample-iOS
//
//  Created by Rodrigo Sánchez González on 08/08/14.
//  Copyright (c) 2014 Mobbeel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ESIDCard.h"

/**
 This class represents the spanish card, on its 2.0 version, the most extended one in Spain at this moment.
 */
@interface ESPIDCardV2 : ESIDCard

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
