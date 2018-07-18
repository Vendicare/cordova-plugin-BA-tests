//
//  PERIDCardV1.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 19/5/17.
//  Copyright © 2017 Mobbeel Solutions. All rights reserved.
//

#import "IDDocumentTD1.h"
#import "PERIDCardV1PDF417.h"

/**
 This class represents the Peruvian national document of identity, version 1 (Date Issued: August 2009).
 */
@interface PERIDCardV1 : IDDocumentTD1

/**
 Region of residence.
 */
@property (nonatomic, strong) NSString *department;

/**
 Province of residence.
 */
@property (nonatomic, strong) NSString *province;

/**
 District of residence.
 */
@property (nonatomic, strong) NSString *district;

/**
 Address of residence.
 */
@property (nonatomic, strong) NSString *address;

/**
 PDF417 data
 */
@property (nonatomic, strong) PERIDCardV1PDF417* pdf417;
@end
