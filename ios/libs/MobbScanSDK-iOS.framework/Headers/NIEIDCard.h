//
//  NIEIDCard.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 19/5/17.
//  Copyright © 2017 Mobbeel Solutions. All rights reserved.
//

#import "IDDocumentTD1.h"

/**
 * This class represents the NIE card.
 */
@interface NIEIDCard : IDDocumentTD1

/**
 Address of residence.
 */
@property (nonatomic, strong) NSString *address;

/**
 City of residence.
 */
@property (nonatomic, strong) NSString *city;

/**
 Region of residence.
 */
@property (nonatomic, strong) NSString *region;

@end
