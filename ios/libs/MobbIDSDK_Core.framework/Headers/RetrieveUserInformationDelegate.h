//
//  RetrieveUserInformationDelegate.h
//  MobbIDAPI
//
//  Created by Abraham Holgado on 22/04/13.
//
//

#import <Foundation/Foundation.h>

/** 
 Possible return values for the [RetrieveUserInformationDelegate retrieveUserInformationFinished:forUser:enrolledMethods:authenticatedMethods:grantedMethods:error:] operation.
 */
typedef NS_ENUM(NSInteger, MobbIDAPIRetrieveUserInformationResult)  {
    /** Operation finished propertly */
    MobbIDAPIRetrieveUserInformationResult_OK,
    /** There has been some error with the operation. */
    MobbIDAPIRetrieveUserInformationResult_ERROR
};


/** 
 Delegate to inform of the result of the [MobbIDManagementAPI retrieveUserInfo:delegate:] 
 */
@protocol RetrieveUserInformationDelegate <NSObject>

/**
 Sent to the delegate when the retrieve user's information is completed.
 
 @param result Possibles values of the result of the operation. @see MobbIDAPIRetrieveUserInformationResult
 @param userId The identifier of the user to be checked.
 @param enrolledMethods The list of biometric methods that the user is enrolled in. The values of the NSArray will be a list of NSDictionary * with these values:
 
 - method: Indicating the enrolled method, with the following possible values:
    - kMobbIDAPI_BiometricMethod_Signature;
    - kMobbIDAPI_BiometricMethod_Iris;
    - kMobbIDAPI_BiometricMethod_Face;
    - kMobbIDAPI_BiometricMethod_Voice;
 - date: A timestamp value of the enrollment date.
 - enrollmentType: Only present for Voice enrollments, indicating the type of voice enrollment made, with the following possible values:
    - MobbIDAPIVoiceAPI_EnrollmentType_RandomNumbers;
    - MobbIDAPIVoiceAPI_EnrollmentType_Passphrase;
    - MobbIDAPIVoiceAPI_EnrollmentType_FreeSpeech;
 
 @param authenticatedMethods The list of biometric methods that the user is currently authenticated in. The values of the NSArray will be a list of NSString * with these possible values:
 
 - kMobbIDAPI_BiometricMethod_Signature;
 - kMobbIDAPI_BiometricMethod_Iris;
 - kMobbIDAPI_BiometricMethod_Face;
 - kMobbIDAPI_BiometricMethod_Voice;
 - kMobbIDAPI_BiometricMethod_VoiceFace;
 
 @param grantedMethods The list of biometric methods in which the user could be enrolled. The values of the NSArray will be a list of NSString * with these possible values:
 
 - kMobbIDAPI_BiometricMethod_Signature;
 - kMobbIDAPI_BiometricMethod_Iris;
 - kMobbIDAPI_BiometricMethod_Face;
 - kMobbIDAPI_BiometricMethod_Voice;
 
 @param errorOccurred If an error has occurred, all the information will be available here. Possible error codes for this operation are (@see MobbIDAPIErrorCode):
 
 - MobbIDAPIErrorCode.ERROR_USER_FIELD_REQUIRED The userId is mandatory.
 - MobbIDAPIErrorCode.ERROR_USER_DOES_NOT_EXIST The userId specified does not belong to any registered user.
 
 */
- (void)retrieveUserInformationFinished:(MobbIDAPIRetrieveUserInformationResult)result
                                forUser:(NSString*)userId
                        enrolledMethods:(NSArray*)enrolledMethods
                   authenticatedMethods:(NSArray*)authenticatedMethods
                         grantedMethods:(NSArray*)grantedMethods
                                  error:(NSError *)errorOccurred;

@end
