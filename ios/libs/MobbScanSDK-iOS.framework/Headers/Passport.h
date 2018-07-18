//
//  Passport.h
//  MobbScanSDK-iOS
//
//  Created by Patri de la Rica on 7/7/16.
//  Copyright © 2016 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IDDocumentTD1.h"

/**
 This class represents a passport
 */
@interface Passport : IDDocumentTD1

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
