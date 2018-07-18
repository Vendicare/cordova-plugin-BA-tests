//
//  MEXIDCard.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 19/5/17.
//  Copyright © 2017 Mobbeel Solutions. All rights reserved.
//

#import "IDDocumentTD1.h"

/**
 This class represents the Mexico national document of identity, version 2.
 */
@interface MEXIDCard : IDDocumentTD1

/**
 Section of residence.
 */
@property (nonatomic, strong) NSString *section;

/**
 Unique update and receipt format.
 */
@property (nonatomic, strong) NSString *fuar;

/**
 Issue number.
 */
@property (nonatomic, strong) NSString *issueNumber;

/**
 State of residence.
 */
@property (nonatomic, strong) NSString *state;

/**
 City of residence.
 */
@property (nonatomic, strong) NSString *city;

/**
 Code of state of residence.
 */
@property (nonatomic, strong) NSString *stateCode;

/**
 Code of city of residence.
 */
@property (nonatomic, strong) NSString *cityCode;

/**
 Borough of residence.
 */
@property (nonatomic, strong) NSString *borough;

/**
 ZIP code associated.
 */
@property (nonatomic, strong) NSString *zipCode;

/**
 Address of residence.
 */
@property (nonatomic, strong) NSString *address;

/**
 State of birth.
 */
@property (nonatomic, strong) NSString *stateOfBirth;

/**
 Unique Population Registry Code.
 */
@property (nonatomic, strong) NSString *curp;

@property (nonatomic, strong) NSString *claveElector;
@property (nonatomic, strong) NSString *ocr;
@end
