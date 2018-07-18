//
//  MobbScanAPITypes.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 17/06/15.
//  Copyright (c) 2015 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Possible modes for the scan process */
typedef NS_ENUM(NSInteger, MobbScanAPIMode) {
    /** Online mode, extraction of the data in the document is done on the server side */
    MobbScanAPIMode_ONLINE,
    /** Offline mode, extraction of the data in the document is done on the client side */
    MobbScanAPIMode_OFFLINE,
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanAPIMode(MobbScanAPIMode value);

/** Possible results for the license check */
typedef NS_ENUM(NSInteger, MobbScanLicenseResult) {
    /** The license is valid. */
    MobbScanLicenseResult_VALID = 0,
    /** The license in the grace period (fifteen days) */
    MobbScanLicenseResult_GRACE_PERIOD = 1,
    /** The license is not valid or does not exists. */
    MobbScanLicenseResult_NOT_VALID = 2,
    /** The license has expired. */
    MobbScanLicenseResult_EXPIRED = 3,
    /** The license has overcome the limit of days without reporting to the license server */
    MobbScanLicenseResult_DAYS_WITHOUT_REPORTING_OVERCOMED = 4,
    /** The maximum number of devices for the license has been exceeded */
    MobbScanLicenseResult_DEVICES_EXCEEDED = 5,
    /** The device has been deactivated for this license */
    MobbScanLicenseResult_DEVICE_DEACTIVATED = 6
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanLicenseResult(MobbScanLicenseResult value);

/** Possible sides of the document that can be scanned */
typedef NS_ENUM(NSInteger, MobbScanDocumentSide) {
    /** Front side of the document (usually the one with the user picture). In documents with just one side, this side will be the only one. */
    MobbScanDocumentSide_FRONT,
    /** Back side of the document */
    MobbScanDocumentSide_BACK
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanDocumentSide(MobbScanDocumentSide value);

/** Possible operation modes for scanning the document */
typedef NS_ENUM(NSInteger, MobbScanOperationMode) {
    /** Scan only front side of the document */
    MobbScanOperationMode_SCAN_ONLY_FRONT,
    /** Scan only back side of the document */
    MobbScanOperationMode_SCAN_ONLY_BACK,
    /** Scan both sides of the document */
    MobbScanOperationMode_SCAN_BOTH_SIDES
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanOperationMode(MobbScanOperationMode value);

/** Possible results of the start operation */
typedef NS_ENUM(NSInteger, MobbScanStartScanResult) {
    /** Operation succeed. The scanId parameter will be informed on the result block. */
    MobbScanStartScanResult_OK,
    /** Operation failed. The scanId parameter will not be informed on the result block. */
    MobbScanStartScanResult_ERROR,
    /** Operation failed becouse a bundle resource is missing. The scanId parameter will not be informed on the result block. */
    MobbScanStartScanResult_OFFLINE_RESOURCES_NOT_FOUND
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanStartScanResult(MobbScanStartScanResult value);

/** Possible type of validations to be performed on a document */
typedef NS_ENUM(NSInteger, MobbScanValidationType) {
    /** Spanish ID Card document, version 2 Kinegram that may be visible only with light inciding on it  */
    MobbScanValidationType_ESPIDCardV2_KINEGRAM,
    /** Spanish ID Card document, version 2 LaserMark that might show the user initials or the expedition date depending on the inclination of the device */
    MobbScanValidationType_ESPIDCardV2_LASER_MARK,
    /** Spanish ID Card document, version 2 Face matching between the document's picture and the user currently using the app */
    MobbScanValidationType_ESPIDCardV2_FACE,
    /** Face matching between the document's picture and the user currently using the app */
    MobbScanValidationType_FACE
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanValidationType(MobbScanValidationType value);

/** Possible results of the scan detection operation */
typedef NS_ENUM(NSInteger, MobbScanDetectionResult) {
    /** Document detected. The image parameter will be informed on the result block with the isolated image. */
    MobbScanDetectionResult_OK,
    /** A problem occurs with the document detection or the user cancels the operation. */
    MobbScanDetectionResult_ERROR
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanDetectionResult(MobbScanDetectionResult value);

/** Possible results of the scan operation */
typedef NS_ENUM(NSInteger, MobbScanScanResult) {
    /** The scan of the document has been completed. The document parameter of the result block will be informed with the extracted information. */
    MobbScanScanResult_COMPLETED,
    /** The scan of this side of the document succeed, but there is still another side to be scanned before having the result. */
    MobbScanScanResult_PENDING_OTHER_SIDE,
    /** The scan of this side of the document has failed and should be repeated. */
    MobbScanScanResult_ERROR
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanScanResult(MobbScanScanResult value);

/** Possible error codes used by response blocks as NSError codes */
typedef NS_ENUM(NSInteger, MobbScanAPIErrorCode) {
    /** The user cancelled the scanning process, no document scanned */
    MobbScanAPIErrorCode_SCANNING_PROCESS_CANCELLED,
    /** A connection error while trying to extract the document information **/
    MobbScanAPIErrorCode_CONNECTION_ERROR,
    /** The license is not valid or has not been configured **/
    MobbScanAPIErrorCode_LICENSE_ERROR,
    /** There was a problem with some of the parameters **/
    MobbScanAPIErrorCode_WRONG_PARAMETERS_ERROR,
    /** The scan process has not been started **/
    MobbScanAPIErrorCode_SCAN_PROCESS_NOT_STARTED,
    /** The scan id passed does not match the currently started scan **/
    MobbScanAPIErrorCode_SCAN_ID_DOES_NOT_MATCH,
    /** Current device does not have the minimum requirements **/
    MobbScanAPIErrorCode_DEVICE_NOT_COMPATIBLE,
    /** An unexpected error occurs during the process */
    MobbScanAPIErrorCode_UNEXPECTED_ERROR,
    /** Error if you try to use the API and it's still not propertly initialised*/
    MobbScanAPIErrorCode_API_NOT_INITIALIZED,
    /** Error if you try to use a camera without the needed specs for the validation */
    MobbScanAPIErrorCode_CAMERA_NOT_VALID_FOR_VALIDATION,
    /** Error if you try to use offline mode without including offline module to the project */
    MobbScanAPIErrorCode_MISSING_OFFLINE_MODULE,
    /** Error if you try to use a method not available in offline mode */
    MobbScanAPIErrorCode_NOT_AVAILABLE_IN_OFFLINE_MODE,
    /** Error while capturing user's face. */
    MobbScanAPIErrorCode_CAPTURE_FACE_ERROR,
    /** The antispoofing mechanism cannot ensure the user is genuine. */
    MobbScanAPIErrorCode_ANTISPOOFING_ERROR,
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanAPIErrorCode(MobbScanAPIErrorCode value);

/** Type of documents that can be scanned */
typedef NS_ENUM(NSInteger, MobbScanDocumentType) {
    /** TD1 sized ID card with MRZ-only recognition. (ICAO Doc 9303. First revision: 1996) */
    MobbScanDocumentType_TD1IDCard,
    /** Spanish national identity card, version ESP-BO-02002 (Date Issued: 03.12.2001) */
    MobbScanDocumentType_ESPIDCardV1,
    /** Spanish national identity card, version ESP-BO-03001 (Date Issued: 16.03.2006) */
    MobbScanDocumentType_ESPIDCardV2,
    /** Spanish national identity card, version ESP-BO-05001 (Date Issued: 02.01.2015) */
    MobbScanDocumentType_ESPIDCardV3,
    /** Default Spanish national identity card */
    MobbScanDocumentType_ESPIDCard,
    /** NIE (Número de Identificación de Extranjero), identification number assigned by the Spanish authorities to any foreigner, version ESP-HO-02002 (Date Issued: 10.05.2010) */
    MobbScanDocumentType_NIE,
    /** Standard TD3 International passwport */
    MobbScanDocumentType_PASSPORT_TD3,
    /** Switzerland national identity card (Date Issued: 11.2005) */
    MobbScanDocumentType_CHEIDCard,
    /** UK identity card */
    MobbScanDocumentType_GBRIDCard,
    /** Croatia national identity card (Date Issued:06.2015) */
    MobbScanDocumentType_HRVIDCard,
    /** Italy national identity card (Date Issued:01.2004) */
    MobbScanDocumentType_ITAIDCard,
    /** Bulgaria national identity card (Date Issued:03.2010) */
    MobbScanDocumentType_BGRIDCard,
    /** Hungary national identity card (Date Issued:01.2016) */
    MobbScanDocumentType_HUNIDCard,
    /** Poland national identity card (Date Issued:03.2015) */
    MobbScanDocumentType_POLIDCard,
    /** Romania national identity card (Date Issued: 01.2017) */
    MobbScanDocumentType_ROUIDCard,
    /** Deutschland default national identity card */
    MobbScanDocumentType_DEUIDCard,
    /** Deutschland foreign identity card,  (Date Issued: 09.2011) */
    MobbScanDocumentType_DEUIDCardAF,
    /** Deutschland national identity card, version 2 (Date Issued: 11.2001)*/
    MobbScanDocumentType_DEUIDCardV1,
    /** Deutschland national identity card, last version released (Date Issued: 01.11.2010) */
    MobbScanDocumentType_DEUIDCardV2,
    /** Kuwait passport*/
    MobbScanDocumentType_KWTPassport,
    /** Mexico simple alternative national identity card */
    MobbScanDocumentType_MEXIDCardLite,
    /** Mexico default national identity card */
    MobbScanDocumentType_MEXIDCard,
    /** Mexico national identity card, version C (Date Issued: 09.2008) */
    MobbScanDocumentType_MEXIDCardC,
    /** Mexico national identity card, version D (Date Issued: 25.11.2013) */
    MobbScanDocumentType_MEXIDCardD,
    /** Mexico national identity card, version E (Date Issued: 06.2014) */
    MobbScanDocumentType_MEXIDCardE,
    /** Mexico national identity card, version F */
    MobbScanDocumentType_MEXIDCardF,
    /** Mexico simple alternative national identity card, version C */
    MobbScanDocumentType_MEXIDCardCLite,
    /** Mexico simple alternative national identity card, version D, E and F */
    MobbScanDocumentType_MEXIDCardDEFLite,
    /** El Salvador national identity card, version 1 (Date Issued: 01.11.2001) */
    MobbScanDocumentType_SLVIDCardV1,
    /** El Salvador residence permit document */
    MobbScanDocumentType_SLVIDCardCA4,
    /** Colombian national identity card, version 3 (Date Issued: 01.05.2000) */
    MobbScanDocumentType_COLIDCardV3,
    /** Chilean national identity card, electronic version (Date Issued: 02.09.2013) */
    MobbScanDocumentType_CHLIDCardE,
    /** Peruvian national identity card, version 1 (Date Issued: 1997) */
    MobbScanDocumentType_PERIDCardV1,
    /** Portuguese national identity card */
    MobbScanDocumentType_PRTIDCard,
    /** Other ID Cards */
    MobbScanDocumentType_OTHIDCard,
    /** Other passports */
    MobbScanDocumentType_OTHPassport,
    /** Unknown document type */
    MobbScanDocumentType_UNKNOWN,
    /** United Arab Emirates passport */
    MobbScanDocumentType_AREPassport,
    /** China passport */
    MobbScanDocumentType_CHNPassport,
    /** Austria passport */
    MobbScanDocumentType_AUTPassport,
    /** Austria identity card */
    MobbScanDocumentType_AUTIDCard,
    /** Ukraine passport */
    MobbScanDocumentType_SAUPassport,
    /** Saudi Arabia passport */
    MobbScanDocumentType_UKRPassport,
    /** United States of America passport */
    MobbScanDocumentType_USAPassport,
    /** Generic document MRZ only */
    MobbScanDocumentType_IDDocumentMRZ,
    /** Guatemala identity card */
    MobbScanDocumentType_GTMIDCard,

};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanDocumentType(MobbScanDocumentType value);

/** Possible state for a document validation */
typedef NS_ENUM(NSInteger, MobbScanValidationState) {
    /** Validation has not been checked or is not applicable to the document */
    MobbScanValidationState_NOT_CHECKED,
    /** Validation has been checked as not correct */
    MobbScanValidationState_NOT_VALID,
    /** Validation has been checked as correct */
    MobbScanValidationState_VALID
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanValidationState(MobbScanValidationState value);

/** Possible evidence images to retrieve after a scan */
typedef NS_ENUM(NSInteger, MobbScanImageType) {
    /** Front image */
    MobbScanImageType_FRONT,
    /** Back image */
    MobbScanImageType_BACK,
    /** MRZ image */
    MobbScanImageType_MRZ,
    /** Face image */
    MobbScanImageType_FACE,
    /** Signature image */
    MobbScanImageType_SIGNATURE,
    /** Fingerprint image */
    MobbScanImageType_FINGERPRINT,
    /** PDF417 image */
    MobbScanImageType_PDF417
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanImageType(MobbScanImageType value);

/** Possible camera type to use for detection */
typedef NS_ENUM(NSInteger, MobbScanCameraType) {
    /** Back camera */
    MobbScanCameraType_BACK,
    /** Front camera */
    MobbScanCameraType_FRONT
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanCameraType(MobbScanCameraType value);

/** Possible modes for the video feature */
typedef NS_ENUM(NSInteger, MobbScanVideoMode) {
    /** Conference mode, one-to-one conversation with an agent */
    MobbScanVideoMode_CONFERENCE,
    /** Unattended mode, just recording a video with specific steps */
    MobbScanVideoMode_UNATTENDED,
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanVideoMode(MobbScanVideoMode value);

/** Possible results of the video step */
typedef NS_ENUM(NSInteger, MobbScanVideoResult) {
    /** Video step is still waiting for availability */
    MobbScanVideoResult_WAITING,
    /** Video is stablished and being processed */
    MobbScanVideoResult_ON_PROCESS,
    /** Video step has already been done */
    MobbScanVideoResult_FINISHED,
    /** A problem occurs during the video step */
    MobbScanVideoResult_ERROR
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanVideoResultResult(MobbScanVideoResult value);

/** Possible status during document detection step */
typedef NS_ENUM(NSInteger, MobbScanDetectionFeedbackResult) {
    /** MobbScan is not detecting a document in the video stream */
    MobbScanDetectionFeedbackResult_NOT_DETECTED,
    /** MobbScan has detected a document in the last frames of the video stream */
    MobbScanDetectionFeedbackResult_DETECTED,
    /** MobbScan is not detecting a PDF 417 code in the video stream */
    MobbScanDetectionFeedbackResult_PDF417_NOT_DETECTED,
    /** MobbScan has detected a PDF 417 code last frames of the video stream */
    MobbScanDetectionFeedbackResult_PDF417_DETECTED,
    /** MobbScan is not detecting a PDF 417 code in the video stream but the timeout was triggered*/
    MobbScanDetectionFeedbackResult_PDF417_TIMEOUT
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanDetectionFeedbackResult(MobbScanDetectionFeedbackResult value);

/** Possible status returned by the verification process, passed to MobbScanVerificationProcessResultListener. */
typedef NS_ENUM(NSInteger, MobbScanVerificationProcessResult) {
    /** Identity has been successfully verified. */
    MobbScanVerificationProcessResult_VERIFIED,
    /** Identity couldn't be verified. */
    MobbScanVerificationProcessResult_NOT_VERIFIED,
    /** Verification result is still not available. */
    MobbScanVerificationProcessResult_PENDING,
    /** Error trying to obtain the verification status. */
    MobbScanVerificationProcessResult_ERROR
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanVerificationProcessResult(MobbScanVerificationProcessResult value);

/** Possible face validation modes */
typedef NS_ENUM(NSInteger, MobbScanFaceValidationMode) {
    /** MobbScan will take control of the camera, detect the face and perform the matching against the picture of the face present in the scanned document. */
    MobbScanFaceValidationMode_DEFAULT,
    /**
     * It's the same as the default mode, but it will perform a liveness test using MobbID Head Movement liveness feature.
     * This feature would only be available if mobbid-extension module it's available in the project
     */
    MobbScanFaceValidationMode_LIVENESS_HEAD_MOVEMENT,
    /**
     * It's the same as the default mode, but it will perform a liveness test using MobbID Smile liveness feature.
     * This feature would only be available if mobbid-extension module it's available in the project
     */
    MobbScanFaceValidationMode_LIVENESS_SMILE
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanFaceValidationMode(MobbScanFaceValidationMode value);


/** Possible face validation modes */
typedef NS_ENUM(NSInteger, MobbScanFaceAcquisitorResult) {
    /** Face(s) Acquired. */
    MobbScanFaceAcquisitorResult_FACE_ACQUIRED,
    /** Error capturing user's face(s) */
    MobbScanFaceAcquisitorResult_ERROR,
};
FOUNDATION_EXPORT NSString *NSStringFromMobbScanFaceAcquisitorResult(MobbScanFaceAcquisitorResult value);

/** This file only contains the typedefs used by MobbScanAPI. Check the types section on appledoc documentation for typedefs definitions:

 - <MobbScanAPIMode>
 - <MobbScanLicenseResult>
 - <MobbScanDocumentSide>
 - <MobbScanOperationMode>
 - <MobbScanStartScanResult>
 - <MobbScanDetectionResult>
 - <MobbScanScanResult>
 - <MobbScanAPIErrorCode>
 - <MobbScanDocumentType>
 - <MobbScanValidationState>
 */
@interface MobbScanAPITypes : NSObject

/**
 Transforms a string into the corresponding MobbScanValidationState.

 @param state String representing the validation state.
 @return A MobbScanValidationState that corresponds to the string passed as
 parameter, MobbScanValidationState_NOT_CHECKED if not found.
 */
+ (MobbScanValidationState)mobbScanValidationStateFrom:(NSString *)state;

/**
 Transforms a string into the corresponding MobbScanDocumentType.

 @param value String representing the document type.
 @return A MobbScanDocumentType that corresponds to the string passed as
 parameter, MobbScanDocumentType_TD1IDCard if not found.
 */
+ (MobbScanDocumentType)mobbScanDocumentTypeFrom:(NSString *)value;

/**
 Transforms a string into the corresponding MobbScanAPIMode.

 @param APIModeAsString String representing the API mode.
 @return A MobbScanAPIMode that corresponds to the string passed as
 parameter, MobbScanAPIMode_ONLINE if not found.
 */
+ (MobbScanAPIMode)mobbScanAPIModeFrom:(NSString *)APIModeAsString;

/**
 Transforms a string into the corresponding MobbScanOperationMode.

 @param operationModeAsString String representing the operation mode.
 @return A MobbScanOperationMode that corresponds to the string passed as
 parameter, MobbScanOperationMode_SCAN_ONLY_FRONT if not found.
 */
+ (MobbScanOperationMode)mobbScanOperationModeFrom:(NSString *)operationModeAsString;

/**
 Transforms a string into the corresponding MobbScanDocumentSide.

 @param documentSideAsString String representing the document side.
 @return A MobbScanDocumentSide that corresponds to the string passed as
 parameter, MobbScanDocumentSide_FRONT if not found.
 */
+ (MobbScanDocumentSide)mobbScanDocumentSideFrom:(NSString *)documentSideAsString;

/**
 Transforms a string into the corresponding MobbScanScanResult.

 @param mobbScanScanResultAsString String representing the scan result.
 @return A MobbScanScanResult that corresponds to the string passed as
 parameter, MobbScanScanResult_ERROR if not found.
 */
+ (MobbScanScanResult)mobbScanScanResultFrom:(NSString *)mobbScanScanResultAsString;

/**
 Transforms a string into the corresponding MobbScanDetectionResult.

 @param mobbScanDetectionResultAsString String representing the detection result.
 @return A MobbScanDetectionResult that corresponds to the string passed as
 parameter, MobbScanDetectionResult_ERROR if not found.
 */
+ (MobbScanDetectionResult)mobbScanDetectionResultFrom:(NSString *)mobbScanDetectionResultAsString;

/**
 Transforms a string into the corresponding MobbScanVerificationProcessResult.

 @param mobbScanVerificationProcessAsString String representing the verification result.
 @return A MobbScanVerificationProcessResult that corresponds to the string passed as
 parameter, MobbScanVerificationProcessResult_PENDING if not found.
 */
+ (MobbScanVerificationProcessResult)mobbScanVerificationProcessResultFrom:(NSString *)mobbScanVerificationProcessAsString;

/**
 Transforms a string into the corresponding MobbScanFaceValidationMode.
 
 @param mobbScanFaceValidationModeAsString String representing the face validation mode.
 @return A MobbScanFaceValidationMode that corresponds to the string passed as parameter, MobbScanFaceValidationMode_DEFAULT if not found.
 */
+ (MobbScanFaceValidationMode)mobbScanFaceValidationModeFrom:(NSString *)mobbScanFaceValidationModeAsString;

@end
