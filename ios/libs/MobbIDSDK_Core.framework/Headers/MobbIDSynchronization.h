//
//  MobbIDSynchronization.h
//  MobbIDSDK_Core
//
//  Created by Maria Luz Mateo Moreno on 31/01/2018.
//  Copyright © 2018 Mobbeel Solutions, SLL. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MobbIDUser.h"


typedef void (^SynchronizationSuccessBlock)(MobbIDUser *);
typedef void (^SynchronizationFailureBlock)(NSError *);

@interface MobbIDSynchronization : NSObject

- (void) synchronizeUser:(NSData *)rawUserTemplate
             securityKey:(NSData *)securityKey
            successBlock:(SynchronizationSuccessBlock)successBlock
            failureBlock:(SynchronizationFailureBlock)failureBlock;

@end
