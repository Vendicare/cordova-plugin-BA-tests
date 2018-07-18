//
//  MobbScanDocumentDetectionTrack.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 3/11/17.
//  Copyright © 2017 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol MobbScanDocumentDetectionTrackListener <NSObject>

- (void)onResume;
- (void)onPause;
- (void)onDestroy;

@end

@interface MobbScanDocumentDetectionTrack : NSObject

@property (nonatomic, weak) UIView *cameraViewContainer;
@property (nonatomic, weak) id<MobbScanDocumentDetectionTrackListener> listener;

- (void)onResume;
- (void)onPause;

@end
