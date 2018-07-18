//
//  COLIDCardV3.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 19/5/17.
//  Copyright © 2017 Mobbeel Solutions. All rights reserved.
//

#import "IDDocumentTD1.h"
#import "COLIDCardV3PDF417.h"

/**
 This class represents the Colombian national identity card, version 3 (Date Issued: 01.05.2000).
 */
@interface COLIDCardV3 : IDDocumentTD1

/**
 * Department of residence.
 */
@property (nonatomic, strong) NSString *department;

/**
 * City of residence.
 */
@property (nonatomic, strong) NSString *city;

/**
 * PDF417 document.
 */
@property (nonatomic, strong) COLIDCardV3PDF417 *pdf417;

@end
