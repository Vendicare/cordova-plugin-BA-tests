#import "MobbScanInvokedUrlCommand.h"

@interface MobbScanInvokedUrlCommand ()

@property (nonatomic, strong) CDVInvokedUrlCommand *command;
@property (nonatomic, weak) id <CDVCommandDelegate> commandDelegate;

@end

@implementation MobbScanInvokedUrlCommand

- (instancetype)initWithCommand:(CDVInvokedUrlCommand *)command withCommandDelegate:(id <CDVCommandDelegate>)commandDelegate {
    self = [super init];
    if (self != nil) {
        self.command = command;
        self.commandDelegate = commandDelegate;
    }
    return self;
}

- (void)sendOkMessage:(NSObject *)message {
    [self sendMessage:message withStatus:CDVCommandStatus_OK];
}

- (void)sendErrorMessage:(NSObject *)message {
    [self sendMessage:message withStatus:CDVCommandStatus_ERROR];
}

- (void)sendMessage:(NSObject *)message withStatus:(CDVCommandStatus)status {
    if ([message isKindOfClass:[NSDictionary class]]) {
        NSDictionary *dictionary = (NSDictionary *)message;
        [self sendMessageAsDictionary:dictionary withStatus:status];
    } else {
        NSString *string = [message description];
        [self sendMessageAsString:string withStatus:status];
    }
}

- (void)sendMessageAsDictionary:(NSDictionary *)message withStatus:(CDVCommandStatus)status {
    CDVPluginResult *pluginResult = [CDVPluginResult
                                     resultWithStatus:status
                                     messageAsDictionary:message];
    pluginResult.keepCallback = [NSNumber numberWithBool:self.keepCallback];

    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.command.callbackId];
}

- (void)sendMessageAsString:(NSString *)message withStatus:(CDVCommandStatus)status {
    CDVPluginResult *pluginResult = [CDVPluginResult
                                     resultWithStatus:status
                                     messageAsString:message];
    pluginResult.keepCallback = [NSNumber numberWithBool:self.keepCallback];

    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.command.callbackId];
}

@end
