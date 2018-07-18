//
//  GTMIDCard.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 10/4/18.
//  Copyright © 2017 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDDocument.h"

/**
 This class represents the Guatemala national document of identity.
 */
@interface GTMIDCard : IDDocument

/**
 * Cui.
 */
@property (nonatomic, strong) NSString* cui;
/**
 * munBirth.
 */
@property (nonatomic, strong) NSString* munBirth;
/**
 * Department of birth.
 */
@property (nonatomic, strong) NSString* dptBirth;
@end
