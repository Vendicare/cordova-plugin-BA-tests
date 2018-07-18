//
//  MobbIDAPI.h
//  MobbIDAPI
//
//  Created by Rodrigo Sánchez González on 02/04/13.
//
//

#import <Foundation/Foundation.h>

/**
 This enum is used to indicate the working mode for the MobbIDAPI
 
 - MobbIDAPIMode_ONLINE In this mode the API will perform the operation on the server side.
 - MobbIDAPIMode_OFFLINE In this mode the API will perform the operations locally on the device.
 
 */
typedef NS_ENUM(NSInteger, MobbIDAPIMode) {
    MobbIDAPIMode_ONLINE,
    MobbIDAPIMode_OFFLINE
};

/**
 This is the configuration object (singleton) of the SDK.
 
 It must be initialized once, using the initAPIWithLicense: method, before calling the user's management methods (MobbIDManagementAPI) or perform any biometric process (FaceAPI, VoiceAPI, IrisAPI...).
 
 This could be a typical configuration for the SDK:
 
 `[[MobbIDAPI getInstance] initAPIWithLicense:license]; // license provided by Mobbeel.`
 
 `[[MobbIDAPI getInstance] setBaseURL:server]; // URL for the test server`
 
 `[[MobbIDAPI getInstance] setDebugMode:NO];// default value is NO`
 
 `[[MobbIDAPI getInstance] setApiMode:MobbIDAPIMode_ONLINE];// default value is MobbIDAPIMode_ONLINE`
 
 `[[MobbIDAPI getInstance] setSynchronizationMode:NO];// default value is NO`
 
 
 */
@interface MobbIDAPI : NSObject

/** 
 This represents the license that will be used in the SDK. It must be configured with the method [MobbIDAPI initAPIWithLicense:]
 */
@property (nonatomic, strong, readonly) NSString* licenseId;

/**
 Default value is MobbIDAPIMode_ONLINE
 
 @warning Some biometric methods are not available in offline mode. For more information see its API object (FaceAPI, VoiceAPI...)
 */
@property (nonatomic) MobbIDAPIMode apiMode;

/** 
 URL (host and port) for the biometric server. E.g: http://test3.mobbeel.com or http://192.168.1.1:8080 
 */
@property (nonatomic, strong) NSString* baseURL;

/** 
 YES if debug mode is active. The default value is NO. 
 */
@property (nonatomic) BOOL debugMode;

/**
 YES if the device is installed on a fixed place, as in in a Kiosk. The default value is NO.
 */
@property (nonatomic) BOOL kioskModeInstallation;

/**
 Method to obtain an instance of the MobbIDAPI configuration object.
 
 @return MobbIDAPI object with the current configuration.
 */
+ (MobbIDAPI*)getInstance;

/**
 This method must be used to configure the API to use your license.
 
 @param licenseId The license provided by Mobbeel.
 
 @warning If you don't initialize the API with this method you won't be able to create user nor to perform any biometric operation.
 */
- (void)initAPIWithLicense:(NSString*)licenseId;

@end
