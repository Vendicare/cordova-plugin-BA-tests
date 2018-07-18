#import <Cordova/CDV.h>


@interface MobbScan : CDVPlugin

- (void)initAPIWithLicense:(CDVInvokedUrlCommand *)command;
- (void)setBaseURL:(CDVInvokedUrlCommand *)command;
- (void)setAPIMode:(CDVInvokedUrlCommand *)command;
- (void)setDocumentDetectionInterface:(CDVInvokedUrlCommand *)command;
- (void)startScanForDocumentType:(CDVInvokedUrlCommand *)command;
- (void)setScanDocumentImageCallback:(CDVInvokedUrlCommand *)command;
- (void)setScanDocumentDataCallback:(CDVInvokedUrlCommand *)command;
- (void)scanDocumentForSide:(CDVInvokedUrlCommand *)command;
- (void)checkVerificationProcessResult:(CDVInvokedUrlCommand *)command;
- (void)initVideo:(CDVInvokedUrlCommand *)command;
- (void)setVideoBaseURL:(CDVInvokedUrlCommand *)command;
- (void)setVideoInterface:(CDVInvokedUrlCommand *)command;
- (void)videoStart:(CDVInvokedUrlCommand *)command;
- (void)validateFace:(CDVInvokedUrlCommand *)command;

@end
