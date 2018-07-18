#import <UIKit/UIKit.h>
#import <MobbScanSDK-iOS/MobbScanSDK-iOS.h>
#import "MobbScanVideoInterfaceProtocol.h"

@interface MobbScanVideoInterface : UIViewController <MobbScanVideoInterfaceProtocol>

@property (strong, nonatomic) NSString *scanId;
@property (nonatomic, copy) void (^videoDidFinish)(MobbScanVideoResult, MobbScanVideoResultData *, NSError *);

@end
