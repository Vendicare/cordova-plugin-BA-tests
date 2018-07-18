@protocol MobbScanVideoInterfaceProtocol <NSObject>

@property (nonatomic, strong) NSString *scanId;
@property (nonatomic, copy) void (^videoDidFinish)(MobbScanVideoResult, MobbScanVideoResultData *, NSError *);

@end
