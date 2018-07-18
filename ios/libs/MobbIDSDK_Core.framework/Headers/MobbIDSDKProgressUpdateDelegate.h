//
//  MobbIDProgressUpdateDelegate.h
//  MobbIDFramework
//
//  Created by Rodrigo Sánchez González on 06/08/13.
//  Copyright (c) 2013 Mobbeel Solutions, SLL. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 The protocol to be used if you want to be updated with the progress of the biometric recognition process.
 */
@protocol MobbIDSDKProgressUpdateDelegate <NSObject>

/**
 This method is invoked each time a new biometric sample has been analyzed, informing of the progress of the full recognition process.
 
 @param progressOK the percentage of advance, it gets to 100 when the current enrollment/verification finishs sucessfully.
 @param progressKO the percentage of 'wrong advance', it gets to 100 when the maximum number of invalid samples has been received,
 producing a failure in the enrollment/verification/identification process.
 */
- (void)progressUpdateWithProgressOK:(float)progressOK progressKO:(float)progressKO;

@end
