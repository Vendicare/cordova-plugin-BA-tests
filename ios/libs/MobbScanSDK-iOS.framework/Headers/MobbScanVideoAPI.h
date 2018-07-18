//
//  MobbScanVideoAPI.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 24/10/17.
//  Copyright © 2017 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MobbScanAPITypes.h"
#import "MobbScanVideoResultData.h"
#import "MobbScanVideoView.h"

/**
 Listener called when the video verification ends. It receives the result of
 the operation, aditional data in case it's needed, and an error in case
 anything went wrong.
 */
typedef void (^MobbScanVideoListener)(MobbScanVideoResult result, MobbScanVideoResultData *_Nullable resultData, NSError *_Nullable error);

/**
 Class in charge of establishing a video conference or record an unattended
 video of the user as an extra step in your verification process.
 */
@interface MobbScanVideoAPI : NSObject

/** Configure video mode */
@property (nonatomic, assign) MobbScanVideoMode videoMode;
/** Configure url of MobbScan video back-end */
@property (nonatomic, strong) NSString *_Nullable baseURL;
/** Configure an identifier for the client connecting to the video session */
@property (nonatomic, strong) NSString *_Nullable identifier;
/** Configure container view for client video stream */
@property (nonatomic, strong) MobbScanVideoView *_Nullable localVideoContainer;
/** Configure container view for remote video stream */
@property (nonatomic, strong) MobbScanVideoView *_Nullable remoteVideoContainer;
/** Listener for video events */
@property (nonatomic, copy) MobbScanVideoListener _Nullable listener;


/**
 Obtain an instance of the MobbScanVideoAPI class.
 
 @return MobbScanVideoAPI object with the current configuration.
 */
+ (MobbScanVideoAPI *_Nonnull)getInstance;

/**
 Set up video API so it can be used.
 */
- (void)initAPI;

/**
 Check if video API is initialized.

 @return YES if initAPI was called, NO otherwise.
 */
- (BOOL)isApiInitializationDone;

/**
 Start the video associated with the specified process.
 
 @param scanId NSString - The scanId associated with the process. This has to be previously obtained using MobbScanAPI.start.
 */
- (void)startWithScanId:(NSString *_Nonnull)scanId;

/**
 Stop the video if it is runnig.
 */
- (void)stop;

/**
 Cancel the video process from client side
 */
- (void)cancel;

- (instancetype _Nullable)init __attribute__((unavailable("init not available, call getInstance instead")));


@end
