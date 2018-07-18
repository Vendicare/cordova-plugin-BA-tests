#import "MobbScan.h"
#import <MobbScanSDK-iOS/MobbScanSDK-iOS.h>
#import "MobbScanInvokedUrlCommand.h"
#import "UIImage+MobbScan.h"
#import "IDDocument+MobbScan.h"
#import "MobbScanDocumentDetectionInterfaceProtocol.h"
#import "MobbScanDocumentDetectionInterface.h"
#import "MobbScanVideoInterfaceProtocol.h"
#import "MobbScanVideoInterface.h"
#import "NSDate+MobbScan.h"

#define DEFAULT_DOCUMENT_DETECTION_INTERFACE_CLASS_NAME @"MobbScanDocumentDetectionInterface"
#define DEFAULT_VIDEO_INTERFACE_CLASS_NAME @"MobbScanVideoInterface"
#define DETECTION_RESULT_DOCUMENT_SIDE_KEY @"documentSide"
#define DETECTION_RESULT_IMAGE_KEY @"image"
#define LOG_TAG @"[MobbScanCordova]"

#define logCurrentMethod() NSLog(@"%@ %@", LOG_TAG, NSStringFromSelector(_cmd))


@interface MobbScan ()

@property (strong, nonatomic) MobbScanAPI *mobbscanAPI;
@property (strong, nonatomic) MobbScanVideoAPI *mobbscanVideoAPI;
@property (strong, nonatomic) MobbScanInvokedUrlCommand *command;
@property (strong, nonatomic) MobbScanInvokedUrlCommand *scanDocumentImageCallbackCommand;
@property (strong, nonatomic) MobbScanInvokedUrlCommand *scanDocumentDataCallbackCommand;
@property (strong, nonatomic) MobbScanInvokedUrlCommand *videoCallbackCommand;
@property (strong, nonatomic) MobbScanInvokedUrlCommand *validateFaceAcquisitorListenerCallbackContext;
@property (assign, nonatomic) MobbScanDocumentType currentDocumentType;
@property (strong, nonatomic) NSString *documentDetectionInterfaceName;
@property (strong, nonatomic) NSString *videoInterfaceName;

@end


@implementation MobbScan

#pragma mark - Plugin management

- (void)pluginInitialize {
    logCurrentMethod();
    [super pluginInitialize];
    self.mobbscanAPI = [MobbScanAPI getInstance];
    self.mobbscanVideoAPI = [MobbScanVideoAPI getInstance];
}

#pragma mark - MobbScanAPI methods

- (void)initAPIWithLicense:(CDVInvokedUrlCommand *)command {
    logCurrentMethod();
    [self.commandDelegate runInBackground:^{
        self.command = [[MobbScanInvokedUrlCommand alloc] initWithCommand:command withCommandDelegate:self.commandDelegate];
        NSString *license = [[command arguments] objectAtIndex:0];
        [self.mobbscanAPI initAPIWithLicense:license
                                      result:^(MobbScanLicenseResult result, NSDate *date) {
                                          [self initAPIWithLicenseResult:result withDate:date];
                                      }];
    }];
}

- (void)setBaseURL:(CDVInvokedUrlCommand *)command {
    logCurrentMethod();
    [self.commandDelegate runInBackground:^{
        self.command = [[MobbScanInvokedUrlCommand alloc] initWithCommand:command withCommandDelegate:self.commandDelegate];
        NSString *baseURL = [[command arguments] objectAtIndex:0];
        self.mobbscanAPI.baseURL = baseURL;

        [self setBaseURLResult:baseURL];
    }];
}

- (void)setAPIMode:(CDVInvokedUrlCommand *)command {
    logCurrentMethod();
    [self.commandDelegate runInBackground:^{
        self.command = [[MobbScanInvokedUrlCommand alloc] initWithCommand:command withCommandDelegate:self.commandDelegate];
        NSString *APIModeAsString = [[command arguments] objectAtIndex:0];
        MobbScanAPIMode APIMode = [MobbScanAPITypes mobbScanAPIModeFrom:APIModeAsString];
        [self.mobbscanAPI setAPIMode:APIMode];

        [self setAPIModeResult:APIMode];
    }];
}

- (void)setDocumentDetectionInterface:(CDVInvokedUrlCommand *)command {
    logCurrentMethod();
    [self.commandDelegate runInBackground:^{
        self.command = [[MobbScanInvokedUrlCommand alloc] initWithCommand:command withCommandDelegate:self.commandDelegate];
        NSString *documentDetectionInterfaceName = [[command arguments] objectAtIndex:0];
        self.documentDetectionInterfaceName = documentDetectionInterfaceName;
        [self setDocumentDetectionInterfaceResult:documentDetectionInterfaceName];
    }];
}

- (void)startScanForDocumentType:(CDVInvokedUrlCommand *)command {
    logCurrentMethod();
    [self.commandDelegate runInBackground:^{
        self.command = [[MobbScanInvokedUrlCommand alloc] initWithCommand:command withCommandDelegate:self.commandDelegate];
        NSString *documentTypeAsString = [[command arguments] objectAtIndex:0];
        MobbScanDocumentType documentType = [MobbScanAPITypes mobbScanDocumentTypeFrom:documentTypeAsString];
        NSLog(@"%@ - MobbScanDocumentType: %@", LOG_TAG, NSStringFromMobbScanDocumentType(documentType));
        NSString *operationModeAsString = [[command arguments] objectAtIndex:1];
        MobbScanOperationMode operationMode = [MobbScanAPITypes mobbScanOperationModeFrom:operationModeAsString];
        NSLog(@"%@ - MobbScanOperationMode: %@", LOG_TAG, NSStringFromMobbScanOperationMode(operationMode));
        self.currentDocumentType = documentType;
        [self.mobbscanAPI startScanForDocumentType:documentType
                                           forMode:operationMode
                                        withResult:^(MobbScanStartScanResult result, NSString *scanId, NSError *error) {
                                            [self startScanForDocumentTypeResult:result withScanId:scanId withError:error];
                                        }];
    }];
}

- (void)setScanDocumentImageCallback:(CDVInvokedUrlCommand *)command {
    logCurrentMethod();
    [self.commandDelegate runInBackground:^{
        self.scanDocumentImageCallbackCommand = [[MobbScanInvokedUrlCommand alloc] initWithCommand:command withCommandDelegate:self.commandDelegate];
        self.scanDocumentImageCallbackCommand.keepCallback = YES;
    }];
}

- (void)setScanDocumentDataCallback:(CDVInvokedUrlCommand *)command {
    logCurrentMethod();
    [self.commandDelegate runInBackground:^{
        self.scanDocumentDataCallbackCommand = [[MobbScanInvokedUrlCommand alloc] initWithCommand:command withCommandDelegate:self.commandDelegate];
        self.scanDocumentDataCallbackCommand.keepCallback = YES;
    }];
}

- (void)scanDocumentForSide:(CDVInvokedUrlCommand *)command {
    logCurrentMethod();
    [self.commandDelegate runInBackground:^{
        self.command = [[MobbScanInvokedUrlCommand alloc] initWithCommand:command withCommandDelegate:self.commandDelegate];
        NSString *documentSideAsString = [[command arguments] objectAtIndex:0];
        MobbScanDocumentSide documentSide = [MobbScanAPITypes mobbScanDocumentSideFrom:documentSideAsString];
        NSLog(@"%@ - MobbScanDocumentSide: %@", LOG_TAG, NSStringFromMobbScanDocumentSide(documentSide));
        NSString *scanId = [[command arguments] objectAtIndex:1];
        NSLog(@"%@ - scanId: %@", LOG_TAG, scanId);
        if ([self.mobbscanAPI isApiInitializationDone] == NO) {
            NSError *error = [MobbScanError errorWithCode:MobbScanAPIErrorCode_API_NOT_INITIALIZED];
            NSLog(@"%@ - error: %@", LOG_TAG, error);
            NSString *message = error.localizedDescription;
            [self.command sendErrorMessage:message];
        } else if ((scanId == nil) || ([scanId isEqualToString:@""])) {
            NSError *error = [MobbScanError errorWithCode:MobbScanAPIErrorCode_WRONG_PARAMETERS_ERROR];
            NSLog(@"%@ - error: %@", LOG_TAG, error);
            NSString *message = error.localizedDescription;
            [self.command sendErrorMessage:message];
        } else {
            [self loadDocumentDetectionInterfaceWithdocumentSide:documentSide withScanId:scanId];
        }
    }];
}

- (void)loadDocumentDetectionInterfaceWithdocumentSide:(MobbScanDocumentSide)documentSide withScanId:(NSString *)scanId {
    Class class = nil;
    NSString *nibName = @"";
    if(self.currentDocumentType == MobbScanDocumentType_OTHIDCard){
        class = NSClassFromString(@"MobbScanOtherDocumentDetectionInterface");
        nibName = @"MobbScanOtherDocumentDetectionInterface";
    } else {
        if (
            (self.documentDetectionInterfaceName != nil) &&
            ([[NSBundle mainBundle] pathForResource:self.documentDetectionInterfaceName ofType:@"nib"] != nil) &&
            ([NSClassFromString(self.documentDetectionInterfaceName) conformsToProtocol:@protocol(MobbScanDocumentDetectionInterfaceProtocol)])) {
            class = NSClassFromString(self.documentDetectionInterfaceName);
            nibName = self.documentDetectionInterfaceName;
        } else {
            class = [MobbScanDocumentDetectionInterface class];
            nibName = DEFAULT_DOCUMENT_DETECTION_INTERFACE_CLASS_NAME;
        }
    }
    
    NSLog(@"%@ - DocumentDetectionInterfaceClass: %@", LOG_TAG, class);
    NSLog(@"%@ - DocumentDetectionInterfaceNib: %@", LOG_TAG, nibName);

    MobbScanDocumentDetectionInterface *documentDetectionInterface = nil;
    documentDetectionInterface = (MobbScanDocumentDetectionInterface *)[[class alloc] initWithNibName:nibName bundle:nil];
    documentDetectionInterface.scanId = scanId;
    documentDetectionInterface.documentSide = documentSide;
    documentDetectionInterface.detectionResult = [self getDetectionResultBlock];
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.viewController presentViewController:documentDetectionInterface animated:YES completion:nil];
    });
}

- (void (^)(MobbScanDetectionResult, MobbScanDetectionResultData *_Nullable, NSError *_Nullable))getDetectionResultBlock {
    return ^(MobbScanDetectionResult result, MobbScanDetectionResultData *_Nullable resultData, NSError *_Nullable error) {
        if (result == MobbScanDetectionResult_OK) {
            [self scanDocumentForSideDetectionResult:result withResultData:resultData withError:error];
            [self.mobbscanAPI scanDocumentWithImage:resultData.image
                                            forSide:resultData.documentSide
                                     withScanResult:[self getDocumentScannedBlock]];
        }
    };
}

- (void (^)(MobbScanScanResult, MobbScanScanResultData *_Nullable, NSError *_Nullable))getDocumentScannedBlock {
    return ^(MobbScanScanResult result, MobbScanScanResultData *_Nullable resultData, NSError *_Nullable error) {
        [self scanDocumentForSideScanResult:result withResultData:resultData withError:error];
    };
}

- (void)checkVerificationProcessResult:(CDVInvokedUrlCommand *)command {
    logCurrentMethod();
    [self.commandDelegate runInBackground:^{
        self.command = [[MobbScanInvokedUrlCommand alloc] initWithCommand:command withCommandDelegate:self.commandDelegate];
        NSString *scanId = [[command arguments] objectAtIndex:0];
        [self.mobbscanAPI checkVerificationProcessResultForScanId:scanId withResultListener:[self getCheckVerificationProcessResultListenerBlock]];
    }];
}

- (void (^)(MobbScanVerificationProcessResult result, MobbScanVerificationProcessResultData *_Nullable resultData, NSError *_Nullable error))getCheckVerificationProcessResultListenerBlock {
    return ^(MobbScanVerificationProcessResult result, MobbScanVerificationProcessResultData *_Nullable resultData, NSError *_Nullable error) {
        [self checkVerificationProcessResultResult:result withResultData:resultData withError:error];
    };
}

- (void)validateFace:(CDVInvokedUrlCommand *)command {
    logCurrentMethod();
    [self.commandDelegate runInBackground:^{
        self.command = [[MobbScanInvokedUrlCommand alloc] initWithCommand:command withCommandDelegate:self.commandDelegate];
        NSString *scanId = [[command arguments] objectAtIndex:0];
        // TODO Converter
        // NSString *faceValidationModeAsString = [[command arguments] objectAtIndex:1];
        
        MobbScanFaceValidationParams* faceValidationParams = [MobbScanFaceValidationParams new];
        faceValidationParams.faceValidationMode = MobbScanFaceValidationMode_LIVENESS_HEAD_MOVEMENT;
        faceValidationParams.cameraType = MobbScanCameraType_FRONT;
        [self.mobbscanAPI validateFaceForScanId:scanId
                                         params:faceValidationParams
                       withFaceAcquisitorResult:^(MobbScanFaceAcquisitorResult result, MobbScanFaceAcquisitorData * _Nullable resultData, NSError * _Nullable error) {
                           NSLog(@"%@ - FaceAcquisitorListener: result: %@", LOG_TAG, NSStringFromMobbScanFaceAcquisitorResult(result));
                           if (self.validateFaceAcquisitorListenerCallbackContext) {
                               if (result == MobbScanFaceAcquisitorResult_ERROR) {
                                   NSMutableDictionary *faceAcquisitorResponse = [NSMutableDictionary dictionary];
                                   [faceAcquisitorResponse setObject:NSStringFromMobbScanFaceAcquisitorResult(result) forKey:@"result"];
                                   [faceAcquisitorResponse setObject:@"TODO ScanID" forKey:@"scanId"];
                                   NSMutableDictionary *errorMessage = [NSMutableDictionary dictionary];
                                   [errorMessage setObject:@(error.code) forKey:@"errorCode"];
                                   // TODO Error details
                                   [faceAcquisitorResponse setObject:errorMessage forKey:@"error"];
                                   [self.validateFaceAcquisitorListenerCallbackContext sendErrorMessage:faceAcquisitorResponse];
                               } else if (resultData && resultData.faces && [resultData.faces count] > 0) {
                                   NSLog(@"%@ - FaceAcquisitorListener: %lu face(s) have been acquired", LOG_TAG, [resultData.faces count]);
                                   // Build a JSON structure that mimics the "standard" MobbScan API response
                                   NSMutableDictionary *faceAcquisitorResponse = [NSMutableDictionary dictionary];
                                   [faceAcquisitorResponse setObject:NSStringFromMobbScanFaceAcquisitorResult(result) forKey:@"result"];
                                   [faceAcquisitorResponse setObject:@"TODO ScanID" forKey:@"scanId"];
                                   NSMutableArray* faces = [NSMutableArray array];
                                   for (UIImage* selfie in resultData.faces) {
                                       [faces addObject:[selfie convertToBase64]];
                                   }
                                   NSDictionary* selfies = @{@"faces" : faces};
                                   [faceAcquisitorResponse setObject:selfies forKey:@"resultData"];
                                   [self.validateFaceAcquisitorListenerCallbackContext sendOkMessage:faceAcquisitorResponse];
                               } else {
                                   NSLog(@"%@ - FaceAcquisitorListener: The acquisitor returns OK but faces are missing. This should not happens", LOG_TAG);
                                   NSMutableDictionary *faceAcquisitorResponse = [NSMutableDictionary dictionary];
                                   [faceAcquisitorResponse setObject:NSStringFromMobbScanFaceAcquisitorResult(MobbScanFaceAcquisitorResult_ERROR) forKey:@"result"];
                                   [faceAcquisitorResponse setObject:@"TODO ScanID" forKey:@"scanId"];
                                   NSMutableDictionary *errorMessage = [NSMutableDictionary dictionary];
                                   [errorMessage setObject:@(error.code) forKey:@"errorCode"];
                                   // TODO Error details
                                   [faceAcquisitorResponse setObject:errorMessage forKey:@"error"];
                                   [self.validateFaceAcquisitorListenerCallbackContext sendErrorMessage:faceAcquisitorResponse];
                               }
                           } else {
                               NSLog(@"%@ - FaceAcquisitorListener: No face acquisitor listener has been set up by the invoker", LOG_TAG);
                           }
                       }
                                withCheckResult:^(MobbScanValidationState result, MobbScanValidationResultData * _Nullable resultData, NSError * _Nullable error) {
                                    NSLog(@"validation result: %@", NSStringFromMobbScanValidationState(result));
                                    [self validateFaceResult:result withData:resultData andError:error];
                                }];
    }];
}

- (void)setFaceAcquisitorCallback:(CDVInvokedUrlCommand *)command {
    logCurrentMethod();
    [self.commandDelegate runInBackground:^{
        self.validateFaceAcquisitorListenerCallbackContext = [[MobbScanInvokedUrlCommand alloc] initWithCommand:command withCommandDelegate:self.commandDelegate];
        self.validateFaceAcquisitorListenerCallbackContext.keepCallback = YES;
    }];
}

#pragma mark - MobbScanVideoAPI methods

- (void)initVideo:(CDVInvokedUrlCommand *)command {
    logCurrentMethod();
    [self.commandDelegate runInBackground:^{
        self.command = [[MobbScanInvokedUrlCommand alloc] initWithCommand:command withCommandDelegate:self.commandDelegate];
        [self.mobbscanVideoAPI initAPI];
        [self initVideoResult];
    }];
}

- (void)setVideoBaseURL:(CDVInvokedUrlCommand *)command {
    logCurrentMethod();
    [self.commandDelegate runInBackground:^{
        self.command = [[MobbScanInvokedUrlCommand alloc] initWithCommand:command withCommandDelegate:self.commandDelegate];
        NSString *baseURL = [[command arguments] objectAtIndex:0];
        self.mobbscanVideoAPI.baseURL = baseURL;
        [self setVideoBaseURLResult:baseURL];
    }];
}

- (void)setVideoInterface:(CDVInvokedUrlCommand *)command {
    logCurrentMethod();
    [self.commandDelegate runInBackground:^{
        self.command = [[MobbScanInvokedUrlCommand alloc] initWithCommand:command withCommandDelegate:self.commandDelegate];
        NSString *videoInterfaceName = [[command arguments] objectAtIndex:0];
        self.videoInterfaceName = videoInterfaceName;
        [self setVideoInterfaceResult:videoInterfaceName];
    }];
}

- (void)videoStart:(CDVInvokedUrlCommand *)command {
    logCurrentMethod();
    [self.commandDelegate runInBackground:^{
        self.videoCallbackCommand = [[MobbScanInvokedUrlCommand alloc] initWithCommand:command withCommandDelegate:self.commandDelegate];
        NSString *scanId = [[command arguments] objectAtIndex:0];
        NSLog(@"%@ - scanId: %@", LOG_TAG, scanId);
        if (([self.mobbscanAPI isApiInitializationDone] == NO) || ([self.mobbscanVideoAPI isApiInitializationDone] == NO)) {
            NSError *error = [MobbScanError errorWithCode:MobbScanAPIErrorCode_API_NOT_INITIALIZED];
            NSLog(@"%@ - error: %@", LOG_TAG, error);
            NSString *message = error.localizedDescription;
            [self.videoCallbackCommand sendErrorMessage:message];
        } else if ((scanId == nil) || ([scanId isEqualToString:@""])) {
            NSError *error = [MobbScanError errorWithCode:MobbScanAPIErrorCode_WRONG_PARAMETERS_ERROR];
            NSLog(@"%@ - error: %@", LOG_TAG, error);
            NSString *message = error.localizedDescription;
            [self.videoCallbackCommand sendErrorMessage:message];
        } else {
            [self loadVideoInterfaceWithScanId:scanId];
        }
    }];
}

- (void)loadVideoInterfaceWithScanId:(NSString *)scanId {
    Class class = nil;
    NSString *nibName = @"";
    if (
        (self.videoInterfaceName != nil) &&
        ([[NSBundle mainBundle] pathForResource:self.videoInterfaceName ofType:@"nib"] != nil) &&
        ([NSClassFromString(self.videoInterfaceName) conformsToProtocol:@protocol(MobbScanVideoInterfaceProtocol)])) {
        class = NSClassFromString(self.videoInterfaceName);
        nibName = self.videoInterfaceName;
    } else {
        class = [MobbScanVideoInterface class];
        nibName = DEFAULT_VIDEO_INTERFACE_CLASS_NAME;
    }
    NSLog(@"%@ - VideoInterfaceClass: %@", LOG_TAG, class);
    NSLog(@"%@ - VideoInterfaceNib: %@", LOG_TAG, nibName);

    MobbScanVideoInterface *videoInterface = nil;
    videoInterface = (MobbScanVideoInterface *)[[class alloc] initWithNibName:nibName bundle:nil];
    videoInterface.scanId = scanId;
    videoInterface.videoDidFinish = [self getVideoDidFinishBlock];
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.viewController presentViewController:videoInterface animated:YES completion:nil];
    });
}

- (void (^)(MobbScanVideoResult, MobbScanVideoResultData *_Nullable, NSError *_Nullable))getVideoDidFinishBlock {
    return ^(MobbScanVideoResult result, MobbScanVideoResultData *_Nullable resultData, NSError *_Nullable error) {
        NSLog(@"%@ - MobbScanVideoResult: %@", LOG_TAG, NSStringFromMobbScanVideoResultResult(result));
        NSLog(@"%@ - MobbScanVideoResultData.finishedByClient: %@", LOG_TAG, resultData.finishedByClient ? @"true" : @"false");
        self.mobbscanVideoAPI.listener = nil;
        if (result == MobbScanVideoResult_FINISHED) {
            NSString *message = resultData.finishedByClient ? @"true" : @"false";
            [self.videoCallbackCommand sendOkMessage:message];
        } else if (result == MobbScanVideoResult_ERROR) {
            NSLog(@"%@ - error: %@", LOG_TAG, error);
            NSString *message = error.localizedDescription;
            [self.videoCallbackCommand sendErrorMessage:message];
        }
    };
}

#pragma mark - MobbScanAPI methods result handling

- (void)initAPIWithLicenseResult:(MobbScanLicenseResult)result withDate:(NSDate *)date {
    NSLog(@"%@ - MobbScanLicenseResult: %@", LOG_TAG, NSStringFromMobbScanLicenseResult(result));
    NSLog(@"%@ - Date: %@", LOG_TAG, [date stringWithFormat:@"YYYY-MM-dd"]);
    if (result == MobbScanLicenseResult_VALID || result == MobbScanLicenseResult_GRACE_PERIOD) {
        NSString *message = [NSString stringWithFormat:@"License check result: %@", NSStringFromMobbScanLicenseResult(result)];
        [self.command sendOkMessage:message];
    } else {
        NSString *message = [NSString stringWithFormat:@"License check result: %@", NSStringFromMobbScanLicenseResult(result)];
        [self.command sendErrorMessage:message];
    }
}

- (void)setBaseURLResult:(NSString *)baseURL {
    NSLog(@"%@ - baseURL: %@", LOG_TAG, baseURL);
    NSString *message = [NSString stringWithFormat:@"Base URL: %@", baseURL];
    [self.command sendOkMessage:message];
}

- (void)setAPIModeResult:(MobbScanAPIMode)APIMode {
    NSLog(@"%@ - MobbScanAPIMode: %@", LOG_TAG, NSStringFromMobbScanAPIMode(APIMode));
    NSString *message = [NSString stringWithFormat:@"API mode: %@", NSStringFromMobbScanAPIMode(APIMode)];
    [self.command sendOkMessage:message];
}

- (void)setDocumentDetectionInterfaceResult:(NSString *)documentDetectionInterfaceName {
    NSLog(@"%@ - documentDetectionInterfaceName: %@", LOG_TAG, documentDetectionInterfaceName);
    NSString *message = [NSString stringWithFormat:@"Document detection interface name: %@", documentDetectionInterfaceName];
    [self.command sendOkMessage:message];
}

- (void)startScanForDocumentTypeResult:(MobbScanStartScanResult)result withScanId:(NSString *)scanId withError:(NSError *)error {
    NSLog(@"%@ - MobbScanStartScanResult: %@", LOG_TAG, NSStringFromMobbScanStartScanResult(result));
    NSLog(@"%@ - scanId: %@", LOG_TAG, scanId);
    if (error != nil) {
        NSLog(@"%@ - error: %@", LOG_TAG, error);
    }
    if (result == MobbScanStartScanResult_OK) {
        if(self.currentDocumentType == MobbScanDocumentType_OTHIDCard){
            [self setDocumentDetectionInterfaceName:@"MobbScanOtherDocumentInterface"];
        }
        NSString *message = scanId;
        [self.command sendOkMessage:message];
    } else {
        NSString *message = [NSString stringWithFormat:@"Start scan result: %@", NSStringFromMobbScanStartScanResult(result)];
        [self.command sendErrorMessage:message];
    }
}

- (void)scanDocumentForSideDetectionResult:(MobbScanDetectionResult)result withResultData:(MobbScanDetectionResultData *)resultData withError:(NSError *)error {
    NSLog(@"%@ - MobbScanDetectionResult: %@", LOG_TAG, NSStringFromMobbScanDetectionResult(result));
    if (result == MobbScanDetectionResult_OK) {
        NSString *documentSide = NSStringFromMobbScanDocumentSide(resultData.documentSide);
        NSString *base64Image = [resultData.image convertToBase64];
        NSLog(@"%@ - MobbScanDetectionResultData.image: %@...", LOG_TAG, [base64Image substringToIndex:19]);
        NSDictionary *message = @{
            DETECTION_RESULT_DOCUMENT_SIDE_KEY : documentSide,
            DETECTION_RESULT_IMAGE_KEY : base64Image
        };
        [self.scanDocumentImageCallbackCommand sendOkMessage:message];
    } else {
        NSLog(@"%@ - error: %@", LOG_TAG, error);
        NSString *message = [NSString stringWithFormat:@"Detect document for side result: %@", NSStringFromMobbScanDetectionResult(result)];
        [self.command sendErrorMessage:message];
    }
}

- (void)scanDocumentForSideScanResult:(MobbScanScanResult)result withResultData:(MobbScanScanResultData *)resultData withError:(NSError *)error {
    NSLog(@"%@ - MobbScanScanResult: %@", LOG_TAG, NSStringFromMobbScanScanResult(result));
    if (result != MobbScanScanResult_ERROR) {
        if ((result == MobbScanScanResult_PENDING_OTHER_SIDE) || (result == MobbScanScanResult_COMPLETED)) {
            NSDictionary *dictionary = [resultData.idDocument dictionaryRepresentation];
            NSLog(@"%@ - MobbScanScanResultData.idDocument: %@", LOG_TAG, dictionary);
            [self.scanDocumentDataCallbackCommand sendOkMessage:dictionary];
            NSString *message = [NSString stringWithFormat:@"Scan document for side result: %@", NSStringFromMobbScanScanResult(result)];
            [self.command sendOkMessage:message];
        } else {
            NSString *message = [NSString stringWithFormat:@"Scan document for side result: %@", NSStringFromMobbScanScanResult(result)];
            [self.command sendOkMessage:message];
        }
    } else {
        NSLog(@"%@ - error: %@", LOG_TAG, error);
        NSString *message = [NSString stringWithFormat:@"Scan document for side result: %@", NSStringFromMobbScanScanResult(result)];
        [self.command sendErrorMessage:message];
    }
}

- (void)checkVerificationProcessResultResult:(MobbScanVerificationProcessResult)result withResultData:(MobbScanVerificationProcessResultData *_Nullable)resultData withError:(NSError *_Nullable)error {
    NSLog(@"%@ - MobbScanVerificationProcessResult: %@", LOG_TAG, NSStringFromMobbScanVerificationProcessResult(result));
    if (result != MobbScanVerificationProcessResult_ERROR) {
        NSString *message = NSStringFromMobbScanVerificationProcessResult(result);
        [self.command sendOkMessage:message];
    } else {
        NSLog(@"%@ - error: %@", LOG_TAG, error);
        NSString *message = error.localizedDescription;
        [self.command sendErrorMessage:message];
    }
}

- (void) validateFaceResult:(MobbScanValidationState)result
                   withData:(MobbScanValidationResultData * _Nullable)resultData
                   andError:(NSError * _Nullable)error {
    NSLog(@"%@ - MobbScanValidateFaceResult: %@", LOG_TAG, NSStringFromMobbScanValidationState(result));
    NSMutableDictionary *faceValidatedResponse = [NSMutableDictionary dictionary];
    [faceValidatedResponse setObject:NSStringFromMobbScanValidationState(result) forKey:@"result"];
    [faceValidatedResponse setObject:@"TODO ScanID" forKey:@"scanId"];    
    if (error) {
        NSMutableDictionary *errorMessage = [NSMutableDictionary dictionary];
        [errorMessage setObject:@(error.code) forKey:@"errorCode"];
        // TODO Error details
        [faceValidatedResponse setObject:errorMessage forKey:@"error"];
        [self.command sendErrorMessage:faceValidatedResponse];
    } else {
        // result == MobbScanValidationState_NOT_VALID || result == MobbScanValidationState_VALID
        if (result == MobbScanValidationState_VALID) {
            NSMutableDictionary *resultDataResponse = [NSMutableDictionary dictionary];
            [resultDataResponse setObject:NSStringFromMobbScanValidationType(resultData.validationType) forKey:@"mobbScanValidationType"];
            [resultDataResponse setObject:@(resultData.score) forKey:@"score"];
            UIImage* selfie = [resultData.images objectAtIndex:0];
            [resultDataResponse setObject:[selfie convertToBase64] forKey:@"face"];
            [faceValidatedResponse setObject:resultDataResponse forKey:@"resultData"];
            [self.command sendOkMessage:faceValidatedResponse];
        } else { // result == MobbScanValidationState_NOT_VALID || result == MobbScanValidationState_NOT_CHECKED
            NSMutableDictionary *resultDataResponse = [NSMutableDictionary dictionary];
            [resultDataResponse setObject:NSStringFromMobbScanValidationType(resultData.validationType) forKey:@"mobbScanValidationType"];
            [faceValidatedResponse setObject:resultDataResponse forKey:@"resultData"];
            [self.command sendOkMessage:faceValidatedResponse];
        }
    }
}


#pragma mark - MobbScanVideoAPI methods result handling

- (void)initVideoResult {
    NSString *message = @"Video API initializated";
    [self.command sendOkMessage:message];
}

- (void)setVideoBaseURLResult:(NSString *)baseURL {
    NSLog(@"%@ - baseURL: %@", LOG_TAG, baseURL);
    NSString *message = [NSString stringWithFormat:@"Video base URL: %@", baseURL];
    [self.command sendErrorMessage:message];
}

- (void)setVideoInterfaceResult:(NSString *)videoInterfaceName {
    NSLog(@"%@ - videoInterfaceName: %@", LOG_TAG, videoInterfaceName);
    NSString *message = [NSString stringWithFormat:@"Video interface name: %@", videoInterfaceName];
    [self.command sendOkMessage:message];
}

@end
