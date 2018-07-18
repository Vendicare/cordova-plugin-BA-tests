//
//  SLVIDCardPDF417.h
//  MobbScanSDK-iOS
//
//  Created by Juan Andrés Borrallo Domínguez on 29/6/18.
//  Copyright © 2018 Mobbeel Solutions. All rights reserved.
//

#import "IDDocumentPDF417.h"

/**
 This class represents the El Salvador document information extracted from PDF417 br code.
 */

@interface SLVIDCardPDF417 : IDDocumentPDF417

/** Nit number */
@property (nonatomic, strong) NSString* nit;
/** State of residence */
@property (nonatomic, strong) NSString* state;
/** City of residence */
@property (nonatomic, strong) NSString* city;
/** Zipcode */
@property (nonatomic, strong) NSString* zipCode;
@end
