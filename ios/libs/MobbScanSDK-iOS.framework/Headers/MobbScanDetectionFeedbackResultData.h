//
//  MobbScanDetectionFeedbackResultData.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 3/11/17.
//  Copyright © 2017 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDDocument.h"
#import <UIKit/UIKit.h>

@interface MobbScanDetectionFeedbackResultData : NSObject

@property (nonatomic, strong) NSString *mrz;
@property (nonatomic, assign) BOOL mrzValid;
@property (nonatomic, strong) IDDocument *document;
@property (nonatomic, strong) UIImage *documentImage;

@end
