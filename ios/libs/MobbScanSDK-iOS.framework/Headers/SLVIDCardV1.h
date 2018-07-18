//
//  SLVIDCardV1.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 19/5/17.
//  Copyright © 2017 Mobbeel Solutions. All rights reserved.
//

#import "IDDocumentTD1.h"
#import "SLVIDCardPDF417.h"
/**
 This class represents the El Salvador national document of identity, version 1 (Date Issued: November 2001).
 */
@interface SLVIDCardV1 : IDDocumentTD1

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

/**
 Document data extracted from PDF417 bar code.
 */
@property (nonatomic, strong) SLVIDCardPDF417* pdf417;

@end
