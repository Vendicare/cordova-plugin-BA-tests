//
//  MobbIDUser.h
//  MobbIDSDK_Core
//
//  Created by Maria Luz Mateo Moreno on 31/01/2018.
//  Copyright © 2018 Mobbeel Solutions, SLL. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <MobbIDSDK_Core/MobbIDSDKTypes.h>


@interface MobbIDUser : NSObject

@property (nonatomic, strong) NSString *userId;
@property (nonatomic) MobbIDAPISupportedLanguage language;
@property (nonatomic) MobbIDAPIGender gender;

@end
