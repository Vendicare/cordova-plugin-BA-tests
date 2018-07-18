//
//  MobbScanScanResultData.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 18/06/15.
//  Copyright (c) 2015 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MobbScanAPITypes.h"
#import "IDDocument.h"

/** Data object returned as result of the scan operation */
@interface MobbScanScanResultData : NSObject

/** The side of the document that the result is referred to */
@property (nonatomic, assign) MobbScanDocumentSide documentSide;
/** The document information, only returned if the scan has finished successfully */
@property (nonatomic, strong) IDDocument* idDocument;

/**
 Get an specific image from an document with its scan identifier.

 @param scanId Identifier of scan process.
 @param type Type of the image to get.

 @return The image associated with the scan identifier if found, nil otherwise.
 */
- (UIImage *)imageForScanId:(NSString *)scanId type:(MobbScanImageType)type;

@end
