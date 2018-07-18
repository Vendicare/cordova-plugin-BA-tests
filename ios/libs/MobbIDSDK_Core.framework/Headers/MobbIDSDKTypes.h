//
//  MobbIDSDKTypes.h
//  MobbIDSDKTypes
//
//  Created by Abraham Holgado García on 25/07/12.
//  Copyright (c) 2012 Mobbeel. All rights reserved.
//

#import <Foundation/Foundation.h>


/** Constant with the name of the domain for the errors returned by the SDK operations */
extern NSString * const kMobbIDSDKDomainError;

/** Key used to retrieve the user from the user's NSArray for the identification operation. */
extern NSString * const kMobbIDFramework_IdentificationUserKey;

/** Key used to retrieve the score of the user from the user's NSArray for the identification operation. */
extern NSString * const kMobbIDFramework_IdentificationScoreKey;

/// User language
extern NSString * const kMobbIDAPI_Language_English;
extern NSString * const kMobbIDAPI_Language_Spanish;
extern NSString * const kMobbIDAPI_Language_German;
extern NSString * const kMobbIDAPI_Language_French;
extern NSString * const kMobbIDAPI_Language_Russian;
extern NSString * const kMobbIDAPI_Language_Italian;

// User gender
extern NSString * const kMobbIDAPI_Gender_Male;
extern NSString * const kMobbIDAPI_Gender_Female;

// Enrolment security key expected size
extern const NSInteger kEXPECTED_SIZE_KEY;

/**
 Different types of recognition modes available when working with the biometric recognition views avaiable in the MobbID Framework.
 
 @warning *Important:* Identification mode (MobbIDSDKRecognitionMode_Identification) is only available for the FaceView and SignatureView recognition view.
 */
typedef NS_ENUM(NSInteger, MobbIDSDKRecognitionMode) {
    /** Recognition mode used for the enrollment operation */
    MobbIDSDKRecognitionMode_Enrollment,
    /** Recognition mode used for the verification operation */
    MobbIDSDKRecognitionMode_Verification,
    /** Recognition mode used for the identification operation */
    MobbIDSDKRecognitionMode_Identification,
    /** Recognition mode used to capture samples from the user */
    MobbIDSDKRecognitionMode_Capture
};
/** Return MobbIDSDKRecognitionMode enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDSDKRecognitionMode(MobbIDSDKRecognitionMode value);

/**
 This enum is used internally to specify the type of attempt the user is performing in every verification.
 
 @warning This is used for debug and test purposes and only when the `debug mode` is enabled. *It is not take into account in the actual biometric recognition.*
 */
typedef NS_ENUM(NSInteger, MobbIDSDKVerificationSampleAttempt) {
    /** The verification attempt is unknown. */
    MobbIDSDKVerificationSampleAttempt_Unknown,
    /** The verification attempt is perform by same user who has been previously been enrolled. */
    MobbIDSDKVerificationSampleAttempt_GenuineUser,
    /** The verification attempt is perform by an attacker. */
    MobbIDSDKVerificationSampleAttempt_CasualForgery,
    /** The verification attempt is perform by an skilled attacker */
    MobbIDSDKVerificationSampleAttempt_SkilledForgery
};
/** Return MobbIDSDKVerificationSampleAttempt enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDSDKVerificationSampleAttempt(MobbIDSDKVerificationSampleAttempt value);

/**
 All possible operation results from MobbIDFramework enrollment operation.
 */
typedef NS_ENUM(NSInteger, MobbIDSDKOperationEnrollmentResult) {
    /** The user has been properly enrolled. */
    MobbIDSDKOperationEnrollmentResult_USER_ENROLLED,
    /** There has been some error on the operation. */
    MobbIDSDKOperationEnrollmentResult_ERROR
};
/** Return MobbIDSDKOperationEnrollmentResult enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDSDKOperationEnrollmentResult(MobbIDSDKOperationEnrollmentResult value);

/**
 All possible operation results from MobbIDFramework verification operation.
 */
typedef NS_ENUM(NSInteger, MobbIDSDKOperationVerificationResult) {
    /** The user has been verified */
    MobbIDSDKOperationVerificationResult_USER_VERIFIED,
    /** The user has not been verified */
    MobbIDSDKOperationVerificationResult_USER_NOT_VERIFIED,
    /** There has been some error on the operation. */
    MobbIDSDKOperationVerificationResult_ERROR
};
/** Return MobbIDSDKOperationVerificationResult enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDSDKOperationVerificationResult(MobbIDSDKOperationVerificationResult value);

/**
 All possible operation results from MobbIDFramework identification operation.
 */
typedef NS_ENUM(NSInteger, MobbIDSDKOperationIdentificationResult) {
    /** The user has been identified  */
    MobbIDSDKOperationIdentificationResult_USER_IDENTIFIED,
    /** The user has not been identified */
    MobbIDSDKOperationIdentificationResult_USER_NOT_IDENTIFIED,
    /** There has been some error on the operation. */
    MobbIDSDKOperationIdentificationResult_ERROR
};
/** Return MobbIDSDKOperationIdentificationResult enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDSDKOperationIdentificationResult(MobbIDSDKOperationIdentificationResult value);

/**
 All possible operation results from MobbIDFramework capture operation.
 */
typedef NS_ENUM(NSInteger, MobbIDSDKOperationCaptureResult) {
    /** The sample has been properly captured. */
    MobbIDSDKOperationCaptureResult_DATA_CAPTURED,
    /** This could happen when the app does not have the right permission to capture the sample (microphone...) */
    MobbIDSDKOperationCaptureResult_ERROR
};
/** Return MobbIDSDKOperationCaptureResult enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDSDKOperationCaptureResult(MobbIDSDKOperationCaptureResult value);

/**
 All possible errors that can happen in a MobbID Framework operation.
 */
typedef NS_ENUM(NSInteger, MobbIDSDKErrorCode) {
    /** Un unexpected or uncontrolled error as happen while performing an SDK operation. */
    MobbIDSDKErrorCode_ERROR_UNEXPECTED = 0,
    /** It happens when there was an error with the connection (connection refused, time out, etc) */
    MobbIDSDKErrorCode_ERROR_CONNECTION = 1,
    /** If the license provided in the SDK's setting is invalid or has expired */
    MobbIDSDKErrorCode_ERROR_LICENSE = 2,
    /** If the userId parameter is not present in the request */
    MobbIDSDKErrorCode_ERROR_USER_ID_REQUIRED = 3,
    /** If the user specified in the operation does not exist on the system */
    MobbIDSDKErrorCode_ERROR_USER_DOES_NOT_EXIST = 4,
    /** If the user trying to enroll in the biometric method is already enrolled in it (and the biometric method does not have the adaptative enrollment enabled)*/
    MobbIDSDKErrorCode_ERROR_USER_ALREADY_ENROLLED_IN_METHOD = 5,
    /** If the user is trying to be verified in a biometric method in which he/she has not been enrolled yet */
    MobbIDSDKErrorCode_ERROR_USER_NOT_ENROLLED_ON_THIS_METHOD = 6,
    /** If the operation is not available (e.g: iris recognition in offline mode) */
    MobbIDSDKErrorCode_ERROR_NOT_AVAILABLE_IN_CURRENT_MODE = 7,
    /** If there has been some error on the biometric samples used in the biometric process */
    MobbIDSDKErrorCode_ERROR_ON_SAMPLES = 8,
        /** If the speech recognition engine has failed or it has not comply with all the specified requirements */
    MobbIDSDKErrorCode_ERROR_SPEECH_RECOGNITION_FAILED = 9,
    /** If the verification process cannot be performed in offline mode because the user's enrollment was done in online mode and the synchronization mode was disabled or because the synchronization process itself have failed */
    MobbIDSDKErrorCode_ERROR_METHOD_NOT_SYNCHRONIZED = 10,
    /** If there has been some error when customizing a Biometric View such as the value is incompatible with the property or the property specified does not exist */
    MobbIDSDKErrorCode_ERROR_CUSTOMIZATION_PROPERTY = 11,
    /** If the user cannot perform an operation. It could happen, for instance, when a biometric process cannot be done because the device does not let the SDK to use the camera or microphone...  */
    MobbIDSDKErrorCode_ERROR_PERMISSION_DENIED = 12,
    /** if the user cannot perform an enrollment because the system doesn't allow it. */
    MobbIDSDKErrorCode_ERROR_USER_NOT_ALLOWED_TO_ENROLL = 13,
    /** if the user cannot perform a verification because the system doesn't allow it. */
    MobbIDSDKErrorCode_ERROR_USER_NOT_ALLOWED_TO_VERIFY = 14,
    /** if the user cannot perform an identification because the system doesn't allow it. */
    MobbIDSDKErrorCode_ERROR_USER_NOT_ALLOWED_TO_IDENTIFY = 15,
    /** if the biometric method has been lockout and need activation. */
    MobbIDSDKErrorCode_ERROR_BIOMETRIC_LOCKOUT = 16,
    /** if the biometric operation cannot be completed within the maximun amount of time established. */
    MobbIDSDKErrorCode_ERROR_TIMEOUT = 17,
    /** if the biometric operation cannot be completed because no smile has been detected. */
    MobbIDSDKErrorCode_ERROR_SMILE_NOT_DETECTED = 18,
    /** if the enrolled fingers of the user on the device has changed since the enrollment of the user */
    MobbIDSDKErrorCode_ERROR_FINGERPRINT_CONFIGURATION_CHANGED = 19,
    /** if the give data is not properly formatted (synchronize user template) */
    MobbIDSDKErrorCode_ERROR_INVALID_FORMATTED_DATA = 20,
    /** if the user could not be saved (synchronize user template) */
    MobbIDSDKErrorCode_ERROR_USER_NOT_SYNCHRONIZED = 21,
    /** if the face template could not be saved (synchronize user template) */
    MobbIDSDKErrorCode_ERROR_FACE_METHOD_NOT_SYNCHRONIZED = 22,
    /** if the voice template could not be saved (synchronize user template) */
    MobbIDSDKErrorCode_ERROR_VOICE_METHOD_NOT_SYNCHRONIZED = 23,
    /** if the signature template could not be saved (synchronize user template) */
    MobbIDSDKErrorCode_ERROR_SIGNATURE_METHOD_NOT_SYNCHRONIZED = 24,
    /** if the face template is wrong or it is in a older format. This error means that the user should be re-enroll again */
    MobbIDSDKErrorCode_ERROR_WRONG_FACE_TEMPLATE = 25,
    /** if the user has not been activated yet */
    MobbIDSDKErrorCode_ERROR_USER_IS_NOT_ACTIVATED = 26,
    /** if liveness is not detected on user enrollment */
    MobbIDSDKErrorCode_ERROR_USER_NOT_VERIFY_LIVENESS = 27
};
/** Return MobbIDSDKErrorCode enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDSDKErrorCode(MobbIDSDKErrorCode value);

/**
 Different biometric methods available in the MobbID Framework.
 */
typedef NS_ENUM(NSInteger, MobbIDSDKBiometricMethod) {
    /// Iris method
    MobbIDSDKBiometricMethod_METHOD_IRIS,
    /// Face method
    MobbIDSDKBiometricMethod_METHOD_FACE,
    /// Signature method
    MobbIDSDKBiometricMethod_METHOD_SIGNATURE,
    /// Voice method
    MobbIDSDKBiometricMethod_METHOD_VOICE,
    /// Combination of Face and Voice methods (only for verification)
    MobbIDSDKBiometricMethod_METHOD_VOICE_FACE,
    /// Fingerprint method
    MobbIDSDKBiometricMethod_METHOD_FINGERPRINT
};
/** Return MobbIDSDKBiometricMethod enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDSDKBiometricMethod(MobbIDSDKBiometricMethod value);

/**
 Levels of security for biometric verification.
 */
typedef NS_ENUM(NSInteger, MobbIDSDKSecurityRecognitionLevel) {
    /** Default. High level of security for the user's verification. */
    MobbIDSDKSecurityRecognitionLevel_HIGHLY_SECURE = 0,
    /** Compromisa between security ans user convenience for the user's verification. */
    MobbIDSDKSecurityRecognitionLevel_SECURE,
    /** Comfort level of security for the user's verification. */
    MobbIDSDKSecurityRecognitionLevel_COMFORT
};
/** Return MobbIDSDKSecurityRecognitionLevel enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDSDKSecurityRecognitionLevel(MobbIDSDKSecurityRecognitionLevel value);

/**
 Possible return values for the biometricAPI (FaceAPI, VoiceAPI, SignatureAPI...) doEnrollmentOfUser:andData:delegate: operation.
 */
typedef NS_ENUM(NSInteger, MobbIDAPIEnrollmentDelegateResult)  {
    /** User has been enrolled properly on the system. */
    MobbIDAPIEnrollmentDelegateResult_OK,
    /** The system needs more samples to complete the operation */
    MobbIDAPIEnrollmentDelegateResult_NEED_MORE_SAMPLES,
    /** There has been some error with the operation */
    MobbIDAPIEnrollmentDelegateResult_ERROR
};
/** Return MobbIDAPIEnrollmentDelegateResult enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDAPIEnrollmentDelegateResult(MobbIDAPIEnrollmentDelegateResult value);

/**
 Possible return values for the biometricAPI (FaceAPI, VoiceAPI, SignatureAPI...) doVerificationOfUser:withType:andData:delegate:
 */
typedef NS_ENUM(NSInteger, MobbIDAPIVerificationDelegateResult) {
    /** The user has been verified */
    MobbIDAPIVerificationDelegateResult_USER_VERIFIED,
    /** The user has not been verified */
    MobbIDAPIVerificationDelegateResult_USER_NOT_VERIFIED,
    /** The system needs more samples to complete the operation */
    MobbIDAPIVerificationDelegateResult_NEED_MORE_SAMPLES,
    /** There has been some error with the operation */
    MobbIDAPIVerificationDelegateResult_ERROR
};
/** Return MobbIDAPIVerificationDelegateResult enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDAPIVerificationDelegateResult(MobbIDAPIVerificationDelegateResult value);

/**
 Possible return values for the doIdentification: operation.
 */
typedef NS_ENUM(NSInteger, MobbIDAPIIdentificationDelegateResult) {
    /** The user has been identified */
    MobbIDAPIIdentificationDelegateResult_USER_IDENTIFIED,
    /** The user has not been identified */
    MobbIDAPIIdentificationDelegateResult_USER_NOT_IDENTIFIED,
    /** The process needs more samples to perform the verification */
    MobbIDAPIIdentificationDelegateResult_NEED_MORE_SAMPLES,
    /** There has been some error with the operation. */
    MobbIDAPIIdentificationDelegateResult_ERROR
};
/** Return MobbIDAPIIdentificationDelegateResult enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDAPIIdentificationDelegateResult(MobbIDAPIIdentificationDelegateResult value);

/**
 Possible return values for the doCapture: operation.
 */
typedef NS_ENUM(NSInteger, MobbIDAPICaptureDelegateResult) {
    /** The biometric data has been captured */
    MobbIDAPICaptureDelegateResult_DATA_CAPTURED,
    /** The process needs more samples to perform the full capture */
    MobbIDAPICaptureDelegateResult_NEED_MORE_SAMPLES,
    /** There has been some error with the operation. */
    MobbIDAPICaptureDelegateResult_ERROR
};
/** Return MobbIDAPICaptureDelegateResult enum values as NSStrings. */
FOUNDATION_EXPORT NSString* NSStringFromMobbIDAPICaptureDelegateResult(MobbIDAPICaptureDelegateResult value);

/**
 Gender types supported by the MobbIDAPI
 */
typedef NS_ENUM(NSInteger, MobbIDAPIGender) {
    MobbIDAPIGender_Male = 0,
    MobbIDAPIGender_Female = 1
};

/**
 Current languages supported by the MobbIDAPI
 */
typedef NS_ENUM(NSInteger, MobbIDAPISupportedLanguage) {
    MobbIDAPISupportedLanguage_English = 0,
    MobbIDAPISupportedLanguage_Spanish = 1,
    MobbIDAPISupportedLanguage_German = 2,
    MobbIDAPISupportedLanguage_French = 3,
    MobbIDAPISupportedLanguage_Russian = 4,
    MobbIDAPISupportedLanguage_Italian = 5
};
FOUNDATION_EXPORT NSString* NSStringFromMobbIDAPISupportedLanguage(MobbIDAPISupportedLanguage language);

/**
 The different types of attempts that could be used in a verification
 ** This is only used for debug purposes **
 */
typedef NS_ENUM(NSInteger, MobbIDAPIVerificationSampleAttempt) {
    MobbIDAPIVerificationSampleAttempt_Unknown = -1,
    MobbIDAPIVerificationSampleAttempt_GenuineUser = 0,
    MobbIDAPIVerificationSampleAttempt_CasualForgery = 1,
    MobbIDAPIVerificationSampleAttempt_SkilledForgery = 2
};
FOUNDATION_EXPORT NSString* NSStringFromMobbIDAPIVerificationSampleAttempt(MobbIDAPIVerificationSampleAttempt attemptType);

/**
 Different types of recognition modes available when working with the biometric recognition.
 */
typedef NS_ENUM(NSInteger, MobbIDAPIRecognitionMode) {
    /** Recognition mode used for the enrollment operation */
    MobbIDAPIRecognitionMode_Enrollment,
    /** Recognition mode used for the verification operation */
    MobbIDAPIRecognitionMode_Verification,
    /** Recognition mode used for the identification operation */
    MobbIDAPIRecognitionMode_Identification,
    /** Recognition mode used for the capture operation */
    MobbIDAPIRecognitionMode_Capture
};
FOUNDATION_EXPORT NSString* NSStringFromMobbIDAPIRecognitionMode(MobbIDAPIRecognitionMode recognitionMode);

/**
 Error codes for NSError used by the MobbIDAPI
 */
typedef NS_ENUM(NSInteger, MobbIDAPIErrorCode) {
    // commons
    ERROR_UNEXPECTED = 0,
    ERROR_CONNECTION = 1,
    ERROR_INTERNAL_SERVER_ERROR = 2,
    ERROR_WRONG_PARAMETERS = 3,
    ERROR_NOT_AVAILABLE_IN_CURRENT_MODE = 4,
    ERROR_USER_FIELD_REQUIRED = 5,
    ERROR_USER_DOES_NOT_EXIST = 6,
    // checkCreateUser
    ERROR_USER_IS_NOT_ACTIVATED = 7,
    // checkLicense
    ERROR_LICENSE_FIELD_REQUIRED = 8,
    ERROR_LICENSE_FILE_NOT_FOUND = 9,
    ERROR_LICENSE_WRONG_LICENSE_ID = 10,
    ERROR_LIMIT_USERS_EXCEEDED = 11,
    ERROR_LICENSE_EXPIRED = 12,
    ERROR_LICENSE_WRONG_FORMAT = 13,
    ERROR_LICENSE_PERIOD_IS_NOT_ACTIVE_YET = 14,
    // checkOperationAuthrization
    ERROR_OPERATION_TYPE_DOES_NOT_EXIST = 15,
    ERROR_OPERATION_TYPE_FIELD_NOT_VALID = 16,
    // confirmUser
    ERROR_TOKEN_IS_NOT_VALID = 17,
    ERROR_TOKEN_HAS_EXPIRED = 18,
    ERROR_USER_AND_TOKEN_COMBINATION_NOT_VALID = 19,
    // startEnrollment
    ERROR_METHOD_NOT_AVAILABLE_FOR_THIS_LICENSE = 20,
    // enrollment
    ERROR_ON_SAMPLES = 21,
    ERROR_USER_NOT_ALLOWED_TO_ENROLL = 22,
    ERROR_USER_ALREADY_ENROLLED_IN_METHOD = 23,
    // startVerification
    // verification
    ERROR_USER_NOT_ALLOWED_TO_VERIFY = 24,
    ERROR_USER_NOT_ENROLLED_ON_THIS_METHOD = 25,
    // identification
    ERROR_USER_NOT_ALLOWED_TO_IDENTIFY = 26,
    //synchronization
    ERROR_METHOD_NOT_SYNCHRONIZED = 27,
    //biometric lockout
    ERROR_BIOMETRIC_LOCKOUT = 28,
    ERROR_TIMEOUT = 29,
    ERROR_USER_IS_NOT_SMILING = 30,
    ERROR_FINGERPRINT_CONFIGURATION_CHANGED = 31,
    ERROR_MERGING_TEMPLATES_TOO_DIFFERENT = 32,
    ERROR_MERGING_TEMPLATES_INCOMPATIBLE_TEMPLATES = 33,
    ERROR_MERGING_TEMPLATES_UNEXPECTED = 34,
    // synchronize user template
    ERROR_INVALID_FORMATTED_DATA = 35,
    ERROR_USER_NOT_SYNCHRONIZED = 36,
    ERROR_FACE_METHOD_NOT_SYNCHRONIZED = 37,
    ERROR_VOICE_METHOD_NOT_SYNCHRONIZED = 38,
    ERROR_SIGNATURE_METHOD_NOT_SYNCHRONIZED = 39,
    // user creation
    ERROR_USER_ALREADY_EXIST = 40,
    ERROR_OPERATION_CANCELLED = 41,
    // enrollment liveness
    ERROR_USER_NOT_VERIFY_LIVENESS = 42
};
FOUNDATION_EXPORT NSString* NSStringFromMobbIDAPIErrorCode(MobbIDAPIErrorCode apiErrorCode);

/**
 Levels of security for the biometric verification.
 */
typedef NS_ENUM(NSInteger, MobbIDAPISecurityRecognitionLevel) {
    /** High level security for user's verification. */
    MobbIDAPISecurityRecognitionLevel_HIGHLY_SECURE,
    /** Medium level security for user's verification. */
    MobbIDAPISecurityRecognitionLevel_SECURE,
    /** Low level security for user's verification. */
    MobbIDAPISecurityRecognitionLevel_COMFORT
};

/// Values for NSError returned by the API in method errorOccurred:
extern NSString * const kMobbIDAPIDomainError;
extern NSString * const kMobbIDAPIExtraInfoKeyError;

/// Available biometric methods in the SDK.
extern NSString * const kMobbIDAPI_BiometricMethod_Signature;
extern NSString * const kMobbIDAPI_BiometricMethod_Iris;
extern NSString * const kMobbIDAPI_BiometricMethod_Face;
extern NSString * const kMobbIDAPI_BiometricMethod_Voice;
extern NSString * const kMobbIDAPI_BiometricMethod_VoiceFace;
extern NSString * const kMobbIDAPI_BiometricMethod_Fingerprint;
extern NSString * const kMobbIDAPI_BiometricMethod_Password;

/// Status code
typedef NS_ENUM(NSInteger, MobbIDHttpStatusCode) {
    kMobbIDAPI_STATUS_SERVER_NOT_REACHED_ERROR = 0,
    kMobbIDAPI_STATUS_CONNECTION_ERROR = 12,
    // HTTP
    kMobbIDAPI_STATUS_REQUEST_OK = 200,
    kMobbIDAPI_STATUS_BAD_REQUEST = 400,
    kMobbIDAPI_STATUS_FORBIDDEN_REQUEST = 403,
    kMobbIDAPI_STATUS_NOT_FOUND_REQUEST = 404,
    kMobbIDAPI_STATUS_INTERNAL_SERVER_ERROR = 500
};
