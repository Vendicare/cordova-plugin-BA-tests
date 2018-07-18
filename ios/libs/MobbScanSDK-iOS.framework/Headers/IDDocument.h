//
//  IDDocument.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 15/06/15.
//  Copyright (c) 2015 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MobbScanAPITypes.h"

/**
 This class representes a generic identification document. This may be an id card but also another type of documents such as passports.
 */
@interface IDDocument : NSObject

/**
 Personal identification number.
 */
@property (nonatomic, strong) NSString* personalNumber;

/**
 Document number.
 */
@property (nonatomic, strong) NSString* documentNumber;

/**
 The type of the document.
 */
@property (nonatomic, assign) MobbScanDocumentType documentType;

/**
 Name.
 */
@property (nonatomic, strong) NSString* name;

/**
 Surname.
 */
@property (nonatomic, strong) NSString* surname;

/**
 First surname.
 */
@property (nonatomic, strong) NSString* firstSurname;

/**
 Second surname.
 */
@property (nonatomic, strong) NSString* secondSurname;

/**
 Gender.
 */
@property (nonatomic, strong) NSString* gender;

/**
 Expiration date of the document.
 */
@property (nonatomic, strong) NSString* dateOfExpiry;

/**
 Date of birth.
 */
@property (nonatomic, strong) NSString* dateOfBirth;

/**
 Nationality.
 */
@property (nonatomic, strong) NSString* nationality;

/**
 Issuing state.
 */
@property (nonatomic, strong) NSString* issuingState;

/**
 Issuing authority.
 */
@property (nonatomic, strong) NSString* issuingAuthority;

/**
ICAO document type.
 */
@property (nonatomic, strong) NSString* icaoDocumentType;

/**
 Picture of the document's MRZ (Machine Readable Zone).
 */
@property (nonatomic, strong) NSString* mrz;

/**
 Validation: indicates if the front side of the document has the right general appearance in terms of shape, color, etc.
 */
@property (nonatomic, assign) MobbScanValidationState validationFrontAppearance;

/**
 Validation: indicates if the back side of the document has the right general appearance in terms of shape, color, etc.
 */
@property (nonatomic, assign) MobbScanValidationState validationBackAppearance;

/**
 Validation: indicates if information contained on both sides of the document is the same.
 */
@property (nonatomic, assign) MobbScanValidationState validationBothSidesMatch;

/**
 Validation: indicates if the control digits on the MRZ are correct.
 */
@property (nonatomic, assign) MobbScanValidationState validationMRZ;

/**
 Validation: indicates if the document number on the MRZ is correct.
 */
@property (nonatomic, assign) MobbScanValidationState validationMRZCheckDocumentNumber;

/**
 Personal number on MRZ is correct.
 */
@property (nonatomic, assign) MobbScanValidationState validationMRZCheckPersonalNumber;

/**
 Validation: indicates if the date of birth on the MRZ is correct.
 */
@property (nonatomic, assign) MobbScanValidationState validationMRZCheckDateOfBirth;

/**
 Validation: indicates if the date of expiry digit on the MRZ is correct.
 */
@property (nonatomic, assign) MobbScanValidationState validationMRZCheckDateOfExpiry;

/**
 Validation: indicates if the composite control digit on the MRZ is correct.
 */
@property (nonatomic, assign) MobbScanValidationState validationMRZCheckComposite;

/**
 Personal number is correct.
 */
@property (nonatomic, assign) MobbScanValidationState validationPersonalNumber;

/**
 Validation: indicates if the separator between name and surname from MRZ is correct.
 */
@property (nonatomic, assign) MobbScanValidationState validationMRZNameSurnameSeparator;

/**
 Validation: indicates if the separator between surnames from MRZ is correct.
 */
@property (nonatomic, assign) MobbScanValidationState validationMRZSurnameSeparator;

/**
 Validation: indicates if the sex letter exists and is valid.
 */
@property (nonatomic, assign) MobbScanValidationState validationSex;

/**
 Validation: indicates if the nationality code exists and is valid.
 */
@property (nonatomic, assign) MobbScanValidationState validationNationality;

/**
 Validation: indicates the appearance score of front side of the document (0-100).
 */
@property (nonatomic, assign) float validationFrontAppearanceScore;

/**
 Validation: indicates the appearance score of back side of the document (0-100).
 */
@property (nonatomic, assign) float validationBackAppearanceScore;

/**
 Validation: indicates the facial matching score between user picture and document user photo (0-100).
 */
@property (nonatomic, assign) float validationFacialMatchingScore;

/**
 Validation: indicates if the date of birth exists and is valid.
 */
@property (nonatomic, assign) MobbScanValidationState validationDateOfBirth;

/**
 Validation: indicates if the date of expiration exists and is valid.
 */
@property (nonatomic, assign) MobbScanValidationState validationDateOfExpiry;

/**
 Validation: indicates if the document has expired.
 */
@property (nonatomic, assign) MobbScanValidationState validationDocumentNotExpired;

/**
 Validation: indicates whether issuing state is correct or not
 */
@property (nonatomic, assign) MobbScanValidationState validationIssuingState;

@end
