//
//  MobbScanError.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 17/5/17.
//  Copyright © 2017 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MobbScanError : NSObject

+ (NSError*)errorWithCode:(NSInteger)code;
+ (NSError*)errorWithCode:(NSInteger)code userInfo:(NSDictionary*)userInfo;

@end
