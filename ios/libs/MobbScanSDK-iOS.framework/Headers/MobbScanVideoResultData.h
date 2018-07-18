//
//  MobbScanVideoResultData.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 24/10/17.
//  Copyright © 2017 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Aditional data returned to MobbScanVideoListener in case it's needed.
*/
@interface MobbScanVideoResultData : NSObject

/**

 Estimation of the time left until an agent is available to start the
 verification step of the enrolment.

 */
@property (nonatomic, assign) NSTimeInterval waitTime;

/**

 If the client finished the verification step its value will be YES, if the
 agent did it will be NO.

 */
@property (nonatomic, assign) BOOL finishedByClient;

@end
