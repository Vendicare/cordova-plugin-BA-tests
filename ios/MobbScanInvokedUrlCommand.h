#import <Cordova/CDV.h>

@interface MobbScanInvokedUrlCommand: NSObject

@property (assign, nonatomic) BOOL keepCallback;

- (instancetype)initWithCommand:(CDVInvokedUrlCommand *)command withCommandDelegate:(id <CDVCommandDelegate>)commandDelegate;
- (void)sendOkMessage:(NSObject *)message;
- (void)sendErrorMessage:(NSObject *)message;

@end
