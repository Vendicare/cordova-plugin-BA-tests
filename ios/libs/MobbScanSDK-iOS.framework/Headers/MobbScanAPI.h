//
//  MobbScanAPI.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 16/06/15.
//  Copyright (c) 2015 Mobbeel Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IDDocument.h"
#import "MobbScanAPITypes.h"
#import "MobbScanDetectionResultData.h"
#import "MobbScanValidationResultData.h"
#import "MobbScanDetectionFeedbackResultData.h"
#import "MobbScanVerificationProcessResultData.h"
#import "MobbScanScanResultData.h"
#import "MobbScanPDF417Reader.h"
#import "MobbScanDocumentDetectionTrack.h"
#import "MobbScanCaptureSessionTakenPictureDelegate.h"
#import "MobbScanFaceAcquisitorData.h"
#import "MobbScanFaceValidationParams.h"

/** Block called when init operation is called and license key is checked.

 - *result* <MobbScanLicenseResult> - Current state of the license validity.
 - *licenseValidTo* - Date until the license expires
 */
typedef void (^LicenseStatusChecked)(MobbScanLicenseResult result, NSDate *_Nonnull licenseValidTo);

/** Block called when start operation returns with a result.

 - *result* <MobbScanStartScanResult> - Indicates if the start operation completed successfully or with some error.
 - *scanId* NSString - If operation succeed, this parameter contains an UUID representing the started operation.
 - *error* NSError - Informed only if result was an error, to indicate the actual error occurred.
 */
typedef void (^ScanStarted)(MobbScanStartScanResult result, NSString *_Nullable scanId, NSError *_Nullable error);

/** Block called when a document is detected while using the scan operation.

 - *result* <MobbScanStartScanResult> - Indicates if the detection succeed or there was an error.
 - *resultData* <MobbScanDetectionResultData> - The result object, containing the isolated and perspective corrected image detected by MobbScan.
 - *error* NSError - Informed only if result was an error, to indicate the actual error occurred.
 */
typedef void (^IDDocumentDetected)(MobbScanDetectionResult result, MobbScanDetectionResultData *_Nullable resultData, NSError *_Nullable error);

/** Block called when document information is extracted using the scan operation.

 - *result* <MobbScanDetectionResult> - Indicates if the extraction of the document succeed or there was some error.
 - *resultData* <MobbScanScanResultData> - If operation succeed, this parameter contains the result object containing the document document filled with the extracted fields.
 - *error* NSError - Informed only if result was an error, to indicate the actual error occurred.
 */
typedef void (^IDDocumentScanned)(MobbScanScanResult result, MobbScanScanResultData *_Nullable resultData, NSError *_Nullable error);

/** Block called when a validation on a document finished.

 - *result* <MobbScanValidationState> - Indicates if the result of the validation is valid, invalid, or not yet checked due to some problem or error.
 - *resultData* <MobbScanValidationResultData> - If operation succeed, this parameter contains extra information about the validation, as evidences.
 - *error* NSError - Informed only if result was not checked, to indicate the actual error occurred.
 */
typedef void (^ValidationChecked)(MobbScanValidationState result, MobbScanValidationResultData *_Nullable resultData, NSError *_Nullable error);

/** Block called when the scan component is presented modally on the View.*/
typedef void (^OnScanComponentPresented)(void);

/** Block called during document detection when using a custom view for detection.

 - *result* <MobbScanDetectionFeedbackResult> - Indicates the detection status, if engine is detecting a document on the stream or not.
 - *resultData* <MobbScanDetectionFeedbackResultData> - Extra information related to the detection feedback.
 - *error* NSError - Informed if there's an error during the document detection.
 */
typedef void (^MobbScanDocumentDetectionFeedback)(MobbScanDetectionFeedbackResult result, MobbScanDetectionFeedbackResultData *_Nullable resultData, NSError *_Nullable error);

/** Block called when the current status of the verification process is retrieved.
 
 - *result* <MobbScanVerificationProcessResult> - The current status of the verification process.
 - *resultData* <MobbScanVerificationProcessResultData> - Extra information about the verification process status.
 - *error* NSError - Set only if result is ERROR, to indicate the actual error occurred.
 */
typedef void (^MobbScanVerificationProcessResultListener)(MobbScanVerificationProcessResult result, MobbScanVerificationProcessResultData *_Nullable resultData, NSError *_Nullable error);

/** Block called when the selfie of the user has been captured
 
 - *result* <MobbScanFaceAcquisitorResult> - The current status of the face acquisition process.
 - *resultData* <MobbScanFaceAcquisitorData> - Face(s) of the user acquired (selfies).
 - *error* NSError - Set only if result is MobbScanFaceAcquisitorResult_ERROR, to indicate the actual error occurred.
 */
typedef void (^MobbScanFaceAcquisitorListener)(MobbScanFaceAcquisitorResult result, MobbScanFaceAcquisitorData *_Nullable resultData, NSError *_Nullable error);

/**
 MobbSignAPI allows your application to scan an identity document and extract all its information, performing also some validations on the document.

 To use MobbScanAPI to scan a document you must follow these steps:

 1) Get the MobbScanAPI intance from the singleton an initialize it with the license key provided by Mobbeel

    MobbScanAPI *mobbScanAPI = [MobbScanAPI getInstance];

    [mobbScanAPI initAPIWithLicense:@"YOUR_LICENSE_HERE"
                             result:^(MobbScanLicenseResult result, NSDate* date) {
                                      NSLog(@"License check result: %@",
                                        NSStringFromMobbScanLicenseResult(result));
    }];

 2) Start the process for a document type specifying if you want to scan one or both sides of the document:

    [mobbscanAPI startScanForDocumentType:MobbScanDocumentType_ESIDCard2
                                       forMode:MobbScanOperationMode_SCAN_BOTH_SIDES
                                    withResult:^(MobbScanStartScanResult result,
                                                 NSString* scanId,
                                                 NSError* error) {
        // Your block code here
    }];

 3) Launch the document scan for each side:

 // Do the same for MobbScanDocumentSide_FRONT side.
    [mobbscanAPI scanDocumentForSide:MobbScanDocumentSide_BACK
                                forScanId:scanId
                      withDetectionResult:^(MobbScanDetectionResult result,
                                            MobbScanDetectionResultData* resultData,
                                            NSError* error) {
        // Your block code here
    }
                            andScanResult:^(MobbScanScanResult result,
                                            MobbScanScanResultData* resultData,
                                            NSError* error) {
        // Your block code here
    }];

    // Do the same for MobbScanDocumentSide_FRONT side.

 */
@interface MobbScanAPI : NSObject

/** Returns the license identifier currently in use. */
@property (nonatomic, strong, readonly) NSString *_Nullable licenseId;

/** Sets the base URL (host and port) for the MobbScan server. */
@property (nonatomic, strong) NSString *_Nonnull baseURL;

/** Configure debug mode for the API. */
@property (nonatomic, assign) BOOL debugMode;

/** Configure API mode, default vaule is MobbScanAPIMode*/
@property (nonatomic, assign) MobbScanAPIMode apiMode;

/**
 Use this property to specify a pdf417 reader implementation if you need to support a document that use this kind of code.
 */
@property (nonatomic, strong) _Nullable id<MobbScanPDF417Reader> pdf417Reader;

/**
 Use this property if you want to be informed when the scan component has been presented.
 Block definition: typedef void (^OnScanComponentPresented)();
 */
@property (nonatomic, copy, nullable) OnScanComponentPresented onScanComponentPresented;

/**
 Use this property if you are implementing your own detection view layout, to be informed of the detecting status.
 */
@property (nonatomic, copy, nullable) MobbScanDocumentDetectionFeedback documentDetectionFeedback;

/**
 Set this if you want to implement your own detection view layout. Set the container view in this view and use this object to be able to stop the detection if the user wants to.
 */
@property (nonatomic, strong) MobbScanDocumentDetectionTrack *_Nullable documentDetectionTrack;

/**
 Set this if you want to get information about the verification process.
 */
@property (nonatomic, copy, nullable) MobbScanVerificationProcessResultListener verificationProcessResultListener;

/**
 Obtain an instance of the MobbScanAPI class.

 @return MobbScanAPI object with the current configuration.
 */
+ (MobbScanAPI *_Nonnull)getInstance;

/**
 Trap method, informs init() is not available. Use getInstance() instead.
 */
- (instancetype _Nonnull)init __attribute__((unavailable("init not available, call getInstance instead")));

/**
 Init the MobbScanAPI instance with a license key.

 @param license NSString - The configured license key.
 @param result <LicenseStatusChecked> - The result block informing about the result of the license check.
 */
- (void)initAPIWithLicense:(NSString *_Nonnull)license result:(LicenseStatusChecked _Nonnull)result;

/**
 Init the MobbScanAPI instance with a license key.
 
 @param license NSString - The configured license key.
 @param result <LicenseStatusChecked> - The result block informing about the result of the license check.
 @param licensePath The license file provided by Mobbeel that authorize you the use of the MobbScan.
 @param publicKeyPath The public key file provided by Mobbeel that is needed to verify the provided license file.
 */
- (void)initAPIWithLicense:(NSString *_Nonnull)license licensePath:(NSString *_Nullable)licensePath publicKeyPath:(NSString *_Nullable)publicKeyPath result:(LicenseStatusChecked _Nonnull)result;

/**
 Check if API is initialized.

 @return YES if initAPIWithLicense was successful, NO otherwise.
 */
- (BOOL)isApiInitializationDone;

/**
 Init the taken picture delegate with a delegate in order to implement callback method
 
 @param delegate id<PictureTakenDelegate> - delegate who implement callback method
 */
- (void)initTakenPictureDelegate:(id<PictureTakenDelegate> _Nonnull)delegate;

/**Take picture method. It requireds execute previous method in order to assign delegate and implement callback method*/
- (void)takePicture;
/**
 * Sets API mode for the MobbScanAPI instance
 * @param APIMode <MobbScanAPIMode> - The API mode to be used. Possible values: ONLINE / OFFLINE. Default is ONLINE.
 */
- (void)setAPIMode:(MobbScanAPIMode)APIMode;

/**
 * Starts a scan process for a given document type and mode. It calls back the result block with the result of the start operation.
 *
 * @param documentType <MobbScanDocumentType> - The document type to be scanned.
 * @param mode <MobbScanOperationMode> - The operation mode, that specifies if one or both sides are going to be captured.
 * @param result <ScanStarted> - The result block where the scanId will be informed if everything goes well.
 */
- (void)startScanForDocumentType:(MobbScanDocumentType)documentType
                         forMode:(MobbScanOperationMode)mode
                      withResult:(ScanStarted _Nonnull)result;

/**
 Launch a document detection for one specific side.

 @param side The side to be detect.
 @param detectionResult The detection block, that will send back the document
 image once detected. The image is returned with perspective and rotation
 corrected to be presented to the user or stored as an evidence.
 */
- (void)detectDocumentSide:(MobbScanDocumentSide)side
       withDetectionResult:(IDDocumentDetected _Nonnull)detectionResult;

/**
 * Scan a document based on an already detected image.
 * @param image The document image. It must be an isolated document, as they are returned by detectDocument method.
 * @param side The side to be deteted.
 * @param scanResult <IDDocumentScanned> - The scan block, that will send back the document information once extracted from the detected document.
 */
- (void)scanDocumentWithImage:(UIImage *_Nonnull)image
                      forSide:(MobbScanDocumentSide)side
               withScanResult:(IDDocumentScanned _Nonnull)scanResult;

/**
 * Scan a document based on an already detected image.
 * @param frontSideImage The front side document image. It must be an isolated document, as they are returned by detectDocument method.
 * @param backSideImage The back side document image. It must be an isolated document, as they are returned by detectDocument method.
 * @param scanId the scan identifier of the whole operation
 * @param scanResult <IDDocumentScanned> - The scan block, that will send back the document information once extracted from the detected document.
 */
- (void)scanDocumentWithFrontSide:(UIImage *_Nonnull)frontSideImage
                         backSide:(UIImage *_Nonnull)backSideImage
                        forScanId:(NSString *_Nonnull)scanId
                    andScanResult:(IDDocumentScanned _Nonnull)scanResult;

/**
 * Launches a document scan for one specific side and a given scanId for a previously started operation.
 *
 * @param side <MobbScanDocumentSide> - The side to be search and scanned.
 * @param scanId NSString - The identifier of the process obtained from the start operation.
 * @param detectionResult <IDDocumentDetected> - The detection block, that will send back the document image once detected. The image is returned with perspective and rotation corrected to be presented to the user or stored as an evidence.
 * @param scanResult <IDDocumentScanned> - The scan block, that will send back the document information once extracted from the detected document.
 */
- (void)scanDocumentForSide:(MobbScanDocumentSide)side
                  forScanId:(NSString *_Nonnull)scanId
        withDetectionResult:(IDDocumentDetected _Nonnull)detectionResult
              andScanResult:(IDDocumentScanned _Nonnull)scanResult;

/**
 * Launches a specific validation check for a specific type of document previously scanned.
 *
 * @param type <MobbScanValidationType> - The type of validation to be performed on the document.
 * @param scanId NSString - The identifier of the process obtained from the start operation and used for the scan operation.
 * @param checkResult <ValidationChecked> - The result block, that will indicate if the validation has passed or not.
 */
- (void)checkDocumentValidationWithType:(MobbScanValidationType)type
                              forScanId:(NSString *_Nonnull)scanId
                        withCheckResult:(ValidationChecked _Nonnull)checkResult;

/**
 * Launches a specific validation check for a specific type of document previously scanned.
 *
 * @param type <MobbScanValidationType> - The type of validation to be performed on the document.
 * @param scanId NSString - The identifier of the process obtained from the start operation and used for the scan operation.
 * @param checkResult <ValidationChecked> - The result block, that will indicate if the validation has passed or not.
 * @param cameraType - When validation supports it, use this parameter to select the camera to use for this validation.
 */
- (void)checkDocumentValidationWithType:(MobbScanValidationType)type
                              forScanId:(NSString *_Nonnull)scanId
                        withCheckResult:(ValidationChecked _Nonnull)checkResult
                            usingCamera:(MobbScanCameraType)cameraType;

/**
 * Launches a face validation for a document previously scanned with the given parameters.
 *
 * @param scanId NSString - The identifier of the process obtained from the start operation and used for the scan operation.
 * @param faceValidationParams <MobbScanFaceValidationParams *> - Parameters to be applied to the validation. If nil is provided default values indicated in the MobbScanFaceValidationParams documentation will be applied;
 * @param faceAcquisitorResult <MobbScanFaceAcquisitorListener> - The face acquisition result block. It'll contain the selfie of the user as soon as it's captured. It is not required.
 * @param checkResult <ValidationChecked> - The result block, that will indicate if the validation has passed or not.
 */
- (void)validateFaceForScanId:(NSString *_Nonnull)scanId
                       params:(MobbScanFaceValidationParams* _Nullable)faceValidationParams
     withFaceAcquisitorResult:(MobbScanFaceAcquisitorListener _Nullable)faceAcquisitorResult
              withCheckResult:(ValidationChecked _Nonnull)checkResult;


/**
 * Checks the current status of a verification process, given the identifier of the operation.
 *
 * @param scanId NSString - The identifier of the process obtained from the start operation.
 * @param mobbScanVerificationProcessResultListener <MobbScanVerificationProcessResultListener> - The block called when the current status of the verification process is obtained.
 */
- (void)checkVerificationProcessResultForScanId:(NSString *_Nonnull)scanId
                             withResultListener:(MobbScanVerificationProcessResultListener _Nonnull)mobbScanVerificationProcessResultListener;

/**
 * Return an array with a list of the avaliable document types in the base URL server
 *
 * @param completionBlock - the result block that will be exectued at the end of the service execution
 */
- (void) getAvaliableDocumentTypes:(void(^)(NSArray* documentTypesArray, NSError* error))completionBlock;
/**
 * Get avaliable document offline list
 * @ Return an array with a list of the available offline document types from common code.
 */
-(NSArray*) getAvailableOnlineDocumentTypes;

/**
 * Destroy current detection track in order to avoid som bugs
 */
- (void) destroyDetectionTrack;

/**
 * Configure scaning PDF417 code step
 * @param scanPDF417CodeOnDetectionStep BOOL - Boolean parametre that specify
 * if api should launch pdf417code detection view
 */
- (void)configurePDF417DetectionStep:(BOOL)scanPDF417CodeOnDetectionStep;
/**
 * Check if ths SDK should launch PDF417 detection view before document detection
 * @param side MobbScanDocumentSide - side of the document which is going to be scanned
 * @param documentType MobbScanDocumentType - document type which is going to be scanned
 */
- (BOOL) shouldScanSpecialCodeBeforeDocumentDetectionForSide:(MobbScanDocumentSide)side andDocumentType:(MobbScanDocumentType)documentType;

- (void) enableMRZQueue:(BOOL)enable;
- (BOOL) isMRZQueueEnable;
@end
