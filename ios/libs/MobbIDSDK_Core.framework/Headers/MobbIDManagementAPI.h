//
//  MobbIDManagementAPI.h
//  MobbIDManagementAPI
//
//  Created by Rodrigo Sánchez González on 04/01/12.
//  Copyright 2012 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <MobbIDSDK_Core/MobbIDSDKTypes.h>
#import "CreateUserDelegate.h"
#import "ConfirmUserDelegate.h"
#import "CheckCreateUserDelegate.h"
#import "CheckOperationAuthorizationDelegate.h"
#import "DeleteUserDelegate.h"
#import "RetrieveUserInformationDelegate.h"
#import "LogoutUserDelegate.h"
#import "CheckLicenseDelegate.h"
#import "DeleteUserEnrollmentDelegate.h"


/**
 The MobbIDManagementAPI class handles the user management in the MobbID API.
 
 This class should be used to:
 
 - Create users (create and confirm)
 - Retrieve user information
 - Check the license status
 - Check if a given user could perform an operation.
 
 All operations have their own delegates to inform of the result and are performed asynchronously.
 
 */
@interface MobbIDManagementAPI : NSObject

/**
 Operation to create a new user with a userId in the system.
 
 The creation of an user is a two-steps process:
 
 1. First the user must be created with createUserWithUserId:language:andGender:delegate:. A new user unique identifier and a token will be returned in the CreateUserDelegate.
 2. Finally the user must confirmed using confirmCreateUser:token:delegate: with the data received in the first step of the process.
 
 @param userId The userId of the user.
 @param language The language of the user.
 @param gender The gender of the user.
 @param delegate The delegate to inform the result of the operation.
 
 */
- (void)createUserWithUserId:(NSString*)userId
                    language:(MobbIDAPISupportedLanguage)language
                   andGender:(MobbIDAPIGender)gender
                    delegate:(id<CreateUserDelegate>)delegate;
/**
 Operation to create a new user in the system.
 
 The creation of an user is a two-steps process:
 
 1. First the user must be created with createUserWithLanguage:andGender:delegate:. A new user unique identifier and a token will be returned in the CreateUserDelegate.
 2. Finally the user must confirmed using confirmCreateUser:token:delegate: with the data received in the first step of the process.
 
 @param language The language of the user.
 @param gender The gender of the user.
 @param delegate The delegate to inform the result of the operation.
 
 */
- (void)createUserWithLanguage:(MobbIDAPISupportedLanguage)language
                     andGender:(MobbIDAPIGender)gender
                      delegate:(id <CreateUserDelegate>)delegate;

/**
 Operation to confirm the creation of a user on the system.
 
 This is the final step required to create an user on the system.
 
 @param userId The identifier of the user to be confirmed. This must be the userId received in the CreateUserDelegate
 @param token The unique token received received in the CreateUserDelegate.
 @param delegate The delegate to inform the result of the operation.
 */
- (void)confirmCreateUser:(NSString*)userId token:(NSString*)token delegate:(id <ConfirmUserDelegate>)delegate;

/**
 Operation to check if an specific user has been created in the system.
 
 Depending on the API's configuration the operations to create (createUser: and createUserWithLanguage:andGender:delegate:) and confirm (confirmCreateUser:token:delegate) may be private and cannot be done from the Mobile SDK, so this operation is used to check whether or not an user has been created properly or to check if he exists on the system.
 
 @param userId The identifier of the user been checked.
 @param delegate The delegate to inform the result of the operation.
 */
- (void)checkCreateUser:(NSString*)userId delegate:(id <CheckCreateUserDelegate>)delegate;

/**
 Operation to retrieve the current status of an user in the system.
 
 It will return several lists of biometric methods
 
 + Enrolled methods. Those biometric methods the user is already enrolled in.
 + Authenticated methods. Those biometric methods the user is currently authenticated in.
 + Granted methods. Those biometric methods he can be enrolled in.
 
 @param userId The identifier of the user.
 @param delegate The delegate to inform the result of the operation.
 */
- (void)retrieveUserInfo:(NSString*)userId delegate:(id <RetrieveUserInformationDelegate>)delegate;

/**
 Operation to log out a user from the system.
 
 @param userId The user to be logged out.
 @param delegate The delegate to inform the result of the operation.
 */
- (void)logoutUser:(NSString*)userId delegate:(id <LogoutUserDelegate>)delegate;

/**
 Operation to delete an user from the system.
 
 @param userId The user to be deleted.
 @param delegate The delegate to inform the result of the operation.
 */
- (void)deleteUser:(NSString*)userId delegate:(id <DeleteUserDelegate>)delegate;

/**
 Operation to delete an specific biometric enrollment from an existing user
 
 @param userId The user to delete the biometric enrollment from.
 @param biometricMethod The biometric method to delete. Use one of these values:
 
 - kMobbIDAPI_BiometricMethod_Voice
 - kMobbIDAPI_BiometricMethod_Signature
 - kMobbIDAPI_BiometricMethod_Face
 - kMobbIDAPI_BiometricMethod_Iris
 - kMobbIDAPI_BiometricMethod_Fingerprint
 
 @param delegate The delegate to inform the result of the operation.
 */
- (void)deleteUserEnrollment:(NSString*)userId forMethod:(NSString *)biometricMethod delegate:(id <DeleteUserEnrollmentDelegate>)delegate;

/**
 Operation to check the status of the configured license. The license must be configured using the [MobbIDAPI initAPIWithLicense:]
 
 @param delegate The delegate to inform the result of the operation.
 */
- (void)checkLicense:(id <CheckLicenseDelegate>)delegate;

/**
 Operation to retrieve the authorization information for an specific operation type for a given user.
 
 The result of the operation will inform whether the user is authorized to perform the operation or if he must be verified on any biometric method before performing the operation.
 
 @param userId The identifier of the user.
 @param operationType The operation type to be checked. These operations are set up and customized by the client.
 @param delegate The delegate to inform the result of the operation.
 */
- (void)checkOperationAuthorization:(NSString*)userId
                      operationType:(NSString*)operationType
                           delegate:(id <CheckOperationAuthorizationDelegate>) delegate;

/**
 Checks if the user has an offline biometric template available for the given method.
 
 @param userId The user of the biometric template.
 @param biometricMethod The biometric method to check. Use one of these values:
 
 - kMobbIDAPI_BiometricMethod_Signature
 - kMobbIDAPI_BiometricMethod_Voice
 - kMobbIDAPI_BiometricMethod_Face
 
 */
+ (BOOL)templateExistsForUser:(NSString*)userId forMethod:(NSString*)biometricMethod;

/**
 Returns the literal description of the `MobbIDAPIGender`
 
 @param gender MobbIDAPIGender
 
 @return NSString with the value of one these constants:
 
 - kMobbIDAPI_Gender_Male
 - kMobbIDAPI_Gender_Female
 */
+ (NSString *) genderValue:(MobbIDAPIGender)gender;

/**
 Returns the literal description of the `MobbIDAPISupportedLanguage`
 
 @param lang MobbIDAPISupportedLanguage
 
 @return NSString with the value of one these constants:
 
 - kMobbIDAPI_Language_English
 - kMobbIDAPI_Language_Spanish
 - kMobbIDAPI_Language_French
 - kMobbIDAPI_Language_German
 - kMobbIDAPI_Language_Russian
 - kMobbIDAPI_Language_Italian
 */
+ (NSString *) languageValue:(MobbIDAPISupportedLanguage)lang;

@end
