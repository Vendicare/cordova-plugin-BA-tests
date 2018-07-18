//
//  IDCard.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 15/06/15.
//  Copyright (c) 2015 Mobbeel Solutions. All rights reserved.
//

#import "IDDocument.h"
#import <UIKit/UIKit.h>

/**
 This class is an specific implementation of IDDocument that represents a generic id card.
 */
@interface IDDocumentTD1 : IDDocument

/** Isolated image of the front side of the document */
@property (nonatomic, strong) UIImage* frontImage;
/** Isolated image of the back side of the document */
@property (nonatomic, strong) UIImage* backImage;

@end
