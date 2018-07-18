//
//  MobbIDCoreResourceManager.h
//  MobbIDSDK_Core
//
//  Created by Maria Luz Mateo Moreno on 21/12/2017.
//  Copyright © 2017 Mobbeel Solutions, SLL. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const kMobbIDCoreLocalizableBundleName;

@interface MobbIDCoreResourceManager : NSObject

@property (nonatomic, strong, readonly) NSBundle * bundle;

+ (MobbIDCoreResourceManager *) instance;

- (NSString *) getLocalizableStringForKey:(NSString *) key;

@end
