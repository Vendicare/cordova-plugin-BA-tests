#import "MobbScanOtherDocumentDetectionInterface.h"


@interface MobbScanOtherDocumentDetectionInterface ()

@property (nonatomic, strong) MobbScanAPI *mobbScanAPI;
@property (nonatomic, strong) MobbScanDocumentDetectionTrack *detectionTrack;

@property (weak, nonatomic) IBOutlet UIView *cameraViewContainer;
@property (weak, nonatomic) IBOutlet UIButton *cancelButton;
@property (weak, nonatomic) IBOutlet UIButton *takePhotoButton;

@end


@implementation MobbScanOtherDocumentDetectionInterface

#pragma mark - View Controller methods

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    self.mobbScanAPI = [MobbScanAPI getInstance];
    self.detectionTrack = [[MobbScanDocumentDetectionTrack alloc] init];
    [self.detectionTrack setCameraViewContainer:self.cameraViewContainer];
    [self.mobbScanAPI setDocumentDetectionTrack:self.detectionTrack];

    [self.mobbScanAPI detectDocumentSide:self.documentSide
                     withDetectionResult:^(MobbScanDetectionResult result, MobbScanDetectionResultData *_Nullable resultData, NSError *_Nullable error) {
                         self.detectionResult(result, resultData, error);
                         [self dismissViewControllerAnimated:YES completion:nil];
                     }];
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskLandscapeRight;
}

- (BOOL)shouldAutorotate {
    return YES;
}

#pragma mark - User interaction

- (IBAction)cancelButtonTouched:(id)sender {
    [self.detectionTrack onPause];
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)takePhotoButtonTouched:(id)sender {
    [self.mobbScanAPI takePicture];
    //[self dismissViewControllerAnimated:YES completion:nil];
}

@end
