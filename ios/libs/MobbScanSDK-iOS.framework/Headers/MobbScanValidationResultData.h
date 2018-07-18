//
//  MobbScanValidationResultData.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 15/07/15.
//  Copyright (c) 2015 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MobbScanAPITypes.h"
#import <UIKit/UIKit.h>

/** Data object returned as result of the check validation operation */
@interface MobbScanValidationResultData : NSObject

/** The type of validation performed */
@property (nonatomic, assign) MobbScanValidationType validationType;

/** Evidences images collected for the validation */
@property (nonatomic, assign) NSArray<UIImage*>* images;

/** Confidence score (between 0 and 100) for the validation */
@property (nonatomic, assign) float score;

/** 
 Returns the evidences images collected for the validation
 @Deprecated. Use the @property images instead
 */
- (NSArray<UIImage*>*)getImagesForValidation;
/** 
 Returns the calculated confidence score (between 0 and 100) for the validation
 @Deprecated. Use the @property score instead
 */
- (float)getScoreForValidation;

@end
