@protocol MobbScanDocumentDetectionInterfaceProtocol <NSObject>

@property (nonatomic, strong) NSString *scanId;
@property (nonatomic, assign) MobbScanDocumentSide documentSide;
@property (nonatomic, copy) IDDocumentDetected detectionResult;
@property (nonatomic, copy) IDDocumentScanned scanResult;

@end
