//
//  PRTIDCard.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 19/5/17.
//  Copyright © 2017 Mobbeel Solutions. All rights reserved.
//

#import "IDDocumentTD1.h"

/**
 This class represents the Portuguese identity card.
 */
@interface PRTIDCard : IDDocumentTD1

/**
 Name of parents.
 */
@property (nonatomic, strong) NSString *parents;

@end
