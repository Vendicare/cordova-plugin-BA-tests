//
//  Distances.h
//  MobbScanSDK-iOS
//
//  Created by Juan Andrés Borrallo Domínguez on 29/6/18.
//  Copyright © 2018 Mobbeel Solutions. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 This class represents the generic PDF417 document data.
 */
@interface Distances : NSObject

/** Name */
@property (nonatomic, strong) NSString* name;
/** Surname */
@property (nonatomic, strong) NSString* surname;
/** Date of birth */
@property (nonatomic, strong) NSString* dateOfBirth;
/** Date of expiry */
@property (nonatomic, strong) NSString* dateOfExpiry;
/** Document number */
@property (nonatomic, strong) NSString* documentNumber;
/** Personal number */
@property (nonatomic, strong) NSString* personalNumber;
/** Gender */
@property (nonatomic, strong) NSString* gender;

@end
