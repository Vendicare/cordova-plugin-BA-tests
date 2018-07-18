#import <UIKit/UIKit.h>
#import <MobbScanSDK-iOS/MobbScanSDK-iOS.h>
#import "MobbScanDocumentDetectionInterfaceProtocol.h"


@interface MobbScanOtherDocumentDetectionInterface : UIViewController <MobbScanDocumentDetectionInterfaceProtocol>

@property (nonatomic, strong) NSString *scanId;
@property (nonatomic, assign) MobbScanDocumentSide documentSide;
@property (nonatomic, copy) IDDocumentDetected detectionResult;
@property (nonatomic, copy) IDDocumentScanned scanResult;

@end
