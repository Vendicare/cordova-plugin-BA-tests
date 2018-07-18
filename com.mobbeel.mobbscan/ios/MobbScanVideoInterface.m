#import "MobbScanVideoInterface.h"


@interface MobbScanVideoInterface ()

@property (weak, nonatomic) MobbScanVideoAPI *mobbscanVideoAPI;
@property (weak, nonatomic) IBOutlet MobbScanVideoView *localVideoView;
@property (weak, nonatomic) IBOutlet MobbScanVideoView *remoteVideView;
@property (weak, nonatomic) IBOutlet UILabel *toastLabel;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *waitingSpinner;
@property (weak, nonatomic) IBOutlet UILabel *statusLabel;
@end


@implementation MobbScanVideoInterface

- (void)viewDidLoad {
    [super viewDidLoad];
    [self hideToast];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    self.mobbscanVideoAPI = [MobbScanVideoAPI getInstance];
    __unsafe_unretained MobbScanVideoInterface *weakSelf = self;
    self.mobbscanVideoAPI.listener = ^(MobbScanVideoResult result, MobbScanVideoResultData *_Nullable resultData, NSError *_Nullable error) {
        [weakSelf videoStartResult:result withResultData:resultData withError:error withWeakSelf:weakSelf];
    };
    self.mobbscanVideoAPI.localVideoContainer = self.localVideoView;
    self.mobbscanVideoAPI.remoteVideoContainer = self.remoteVideView;
    [self.mobbscanVideoAPI startWithScanId:self.scanId];
}

- (void)videoStartResult:(MobbScanVideoResult)result withResultData:(MobbScanVideoResultData *)resultData withError:(NSError *)error withWeakSelf:(MobbScanVideoInterface *)weakSelf {
    if (result == MobbScanVideoResult_WAITING) {
        self.waitingSpinner.hidden = NO;
        self.statusLabel.hidden = NO;
        NSString *resultAsString = NSStringFromMobbScanVideoResultResult(result);
        NSString *message = [NSString stringWithFormat:@"%@: %f", resultAsString, resultData.waitTime];
        [weakSelf makeToast:message];
    } else if (result == MobbScanVideoResult_ON_PROCESS) {
        self.waitingSpinner.hidden = YES;
        self.statusLabel.hidden = NO;
        self.statusLabel.text = @"Conecting video...";
        NSString *message = NSStringFromMobbScanVideoResultResult(result);
        [weakSelf makeToast:message];
    } else if ((result == MobbScanVideoResult_FINISHED) || (result == MobbScanVideoResult_ERROR)) {
        self.waitingSpinner.hidden = YES;
        self.statusLabel.hidden = YES;
        [self dismissViewControllerAnimated:YES
                                 completion:^{
                                     [self.mobbscanVideoAPI stop];
                                     self.videoDidFinish(result, resultData, error);
                                 }];
    }
}

- (IBAction)stopTouched:(UIButton *)sender {
    [self showConfirmationCloseDialog];
}
- (void) closeVideoConf{
    [self dismissViewControllerAnimated:YES
                             completion:^{
                                 [self.mobbscanVideoAPI stop];
                                 MobbScanVideoResultData *resultData = [[MobbScanVideoResultData alloc] init];
                                 resultData.finishedByClient = YES;
                                 self.videoDidFinish(MobbScanVideoResult_FINISHED, resultData, nil);
                             }];
}

- (void) showConfirmationCloseDialog{
    UIAlertController* closeDialogAlert = [UIAlertController alertControllerWithTitle:@""
                                                                   message:@"¿Está seguro de que desea cerrar la videoconferencia?"
                                                            preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction* cancelAction = [UIAlertAction actionWithTitle:@"No" style:UIAlertActionStyleDefault
                                                          handler:^(UIAlertAction * action) {}];
    
    UIAlertAction* closeAction = [UIAlertAction actionWithTitle:@"Si" style:UIAlertActionStyleDefault
                                                          handler:^(UIAlertAction * action) {
                                                              [self closeVideoConf];
                                                          }];
    
    [closeDialogAlert addAction:cancelAction];
    [closeDialogAlert addAction:closeAction];
    [self presentViewController:closeDialogAlert animated:YES completion:nil];
}

- (void)makeToast:(NSString *)message {
    self.toastLabel.text = message;
    self.toastLabel.hidden = NO;
    [NSTimer scheduledTimerWithTimeInterval:3.0
                                     target:self
                                   selector:@selector(hideToast)
                                   userInfo:nil
                                    repeats:NO];
}

- (void)hideToast {
    self.toastLabel.text = @"";
    self.toastLabel.hidden = YES;
}

@end
