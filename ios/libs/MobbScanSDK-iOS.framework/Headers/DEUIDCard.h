//
//  DEUIDCard.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 19/5/17.
//  Copyright © 2017 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDDocumentTD1.h"

/**
 This class represents the Deutschland national document of identity.
 */
@interface DEUIDCard : IDDocumentTD1

/** Zip code */
@property (nonatomic, strong) NSString* zipCode;
/** Address of residence */
@property (nonatomic, strong) NSString* address;
/** City of residence */
@property (nonatomic, strong) NSString* city;
@end
