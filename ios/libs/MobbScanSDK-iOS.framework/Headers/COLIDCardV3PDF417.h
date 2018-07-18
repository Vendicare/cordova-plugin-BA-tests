//
//  COLIDCardV3PDF417.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 19/5/17.
//  Copyright © 2017 Mobbeel Solutions. All rights reserved.
//

#import "IDDocumentPDF417.h"

/**
 This class represents the Colombian national identity card, version 3 (Date Issued: 01.05.2000).
 */
@interface COLIDCardV3PDF417 : IDDocumentPDF417

/**
 * Personal number.
 */
@property (nonatomic, strong) NSString *personalNumber;

/**
 * First surname.
 */
@property (nonatomic, strong) NSString *firstSurname;
/**
 * Second surname.
 */
@property (nonatomic, strong) NSString *secondSurname;

@end
