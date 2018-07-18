//
//  MobbScanDetectionResultData.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 18/06/15.
//  Copyright (c) 2015 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MobbScanAPITypes.h"
#import <UIKit/UIKit.h>

/** Data object returned as result of scan operation when document is detected */
@interface MobbScanDetectionResultData : NSObject

/** The side of the document that the result is referred to */
@property (nonatomic, assign) MobbScanDocumentSide documentSide;
/** Image of the isolated and perspective corrected document */
@property (nonatomic, strong) UIImage* image;

@end
