//
//  IDDocumentMRZ.h
//  MobbScanSDK-iOS
//
//  Copyright © 2016 Mobbeel Solutions. All rights reserved.
//

#import "IDDocument.h"

/**
 This class represents a iddocument MRZ
 */
@interface IDDocumentMrz : IDDocument
/**
 Validation: The mrzOutputCondition validation.
 */
@property (nonatomic, assign) MobbScanValidationState mrzOutputCondition;
@end

