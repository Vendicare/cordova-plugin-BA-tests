//
//  MobbIDSDKIdentificationParameters.h
//  MobbIDSDK_Core
//
//  Created by Maria Luz Mateo Moreno on 02/02/2018.
//  Copyright © 2018 Mobbeel Solutions, SLL. All rights reserved.
//

#import <MobbIDSDK_Core/MobbIDSDKRecognitionParameters.h>


@interface MobbIDSDKIdentificationRecognitionParameters : MobbIDSDKRecognitionParameters

/** List of userIds the identification process will use to try to identify the user from. It it is nil, the identification will search among all enroll users */
@property (nonatomic, strong) NSArray<NSString *> *userIds;

@end
