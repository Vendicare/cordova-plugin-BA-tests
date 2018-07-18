//
//  MobbScanPDF417Reader.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 23/8/17.
//  Copyright © 2017 Mobbeel Solutions. All rights reserved.
//
#import "MobbScanPDF417Reader.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol MobbScanPDF417Reader <NSObject>

+ (NSString*)readPDF417FromImage:(UIImage*)image;

@end
