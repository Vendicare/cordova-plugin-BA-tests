//
//  IDDocumentPDF417.h
//  MobbScanSDK-iOS
//
//  Created by Juan Andrés Borrallo Domínguez on 29/6/18.
//  Copyright © 2018 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IDDocument.h"
#import "Distances.h"

/**
 This class represents the generic PDF417 document data.
 */
@interface IDDocumentPDF417 : IDDocument

/** Document number */
@property (nonatomic, strong) NSString* documentNumber;
/** Personal number */
@property (nonatomic, strong) NSString* personalNumber;
/** First surname */
@property (nonatomic, strong) NSString* firstSurname;
/** Second surname */
@property (nonatomic, strong) NSString* secondSurname;
/** Surname */
@property (nonatomic, strong) NSString* surname;
/** Name */
@property (nonatomic, strong) NSString* name;
/** Gender */
@property (nonatomic, strong) NSString* gender;
/** Date of birth */
@property (nonatomic, strong) NSString* dateOfBirth;
/** Date of expiry */
@property (nonatomic, strong) NSString* dateOfExpiry;
/** Distance */
@property (nonatomic, strong) Distances* distance;


@end
