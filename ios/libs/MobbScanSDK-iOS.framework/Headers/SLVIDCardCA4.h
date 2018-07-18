//
//  SLVIDCardCA4.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 19/5/17.
//  Copyright © 2017 Mobbeel Solutions. All rights reserved.
//

#import "IDDocumentTD1.h"

/**
 This class represents the El Salvador national document of identity, version 1 (Date Issued: November 2001).
 */
@interface SLVIDCardCA4 : IDDocumentTD1

/**
 Address of residence.
 */
@property (nonatomic, strong) NSString *address;

/**
 City of residence.
 */
@property (nonatomic, strong) NSString *city;

/**
 State of residence.
 */
@property (nonatomic, strong) NSString *state;

/**
 Tax identification number.
 */
@property (nonatomic, strong) NSString *nit;

/**
 ZIP code associated.
 */
@property (nonatomic, strong) NSString *zipCode;

@end
