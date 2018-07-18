#import "MobbScanDocumentDetectionInterface.h"
#import "BorderView.h"


@interface MobbScanDocumentDetectionInterface ()

@property (nonatomic, strong) MobbScanAPI *mobbScanAPI;
@property (nonatomic, strong) MobbScanDocumentDetectionTrack *detectionTrack;

@property (weak, nonatomic) IBOutlet UIView *cameraViewContainer;
@property (weak, nonatomic) IBOutlet UILabel *feedbackLabel;
@property (nonatomic, strong) CAShapeLayer *fillLayer;
@property (weak, nonatomic) IBOutlet UIButton *cancelButton;

@property (weak, nonatomic) IBOutlet BorderView *border;

@property (nonatomic, strong) UIColor *notDetectedColor;
@property (nonatomic, strong) UIColor *detectedColor;

@end


@implementation MobbScanDocumentDetectionInterface

#pragma mark - View Controller methods

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    self.mobbScanAPI = [MobbScanAPI getInstance];
    self.detectionTrack = [[MobbScanDocumentDetectionTrack alloc] init];
    [self.detectionTrack setCameraViewContainer:self.cameraViewContainer];
    [self.mobbScanAPI setDocumentDetectionTrack:self.detectionTrack];
    [self.mobbScanAPI configurePDF417DetectionStep:YES];
    __weak __typeof(self) weakSelf = self;
    [self.mobbScanAPI setDocumentDetectionFeedback:^(MobbScanDetectionFeedbackResult result, MobbScanDetectionFeedbackResultData *_Nullable resultData, NSError *_Nullable error) {
        NSLog(@"Detection state: %@", NSStringFromMobbScanDetectionFeedbackResult(result));
        [weakSelf reportFeedbackResult:result];
    }];
    
    [self.mobbScanAPI detectDocumentSide:self.documentSide
                     withDetectionResult:^(MobbScanDetectionResult result, MobbScanDetectionResultData *_Nullable resultData, NSError *_Nullable error) {
                         self.detectionResult(result, resultData, error);
                         [self.mobbScanAPI destroyDetectionTrack];
                         [self.detectionTrack onPause];
                         [self dismissViewControllerAnimated:YES completion:nil];
                     }];
    
    if ([self.mobbScanAPI shouldScanSpecialCodeBeforeDocumentDetectionForSide:self.documentSide andDocumentType:MobbScanDocumentType_SLVIDCardV1]){
        [self addPDF417CodeOverview];
    } else {
        [self.border setHidden:NO];
    }
    
    self.notDetectedColor = [UIColor colorWithRed:0.05 green:0.48 blue:0.96 alpha:1.0];
    self.detectedColor = [UIColor colorWithRed:0.16 green:0.76 blue:0.09 alpha:1.0];
    self.border.strokeColor = self.notDetectedColor;
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskLandscapeRight;
}

- (BOOL)shouldAutorotate {
    return YES;
}

#pragma mark - Detection feedback

- (void)reportFeedbackResult:(MobbScanDetectionFeedbackResult)result {
    switch (result) {
        case MobbScanDetectionFeedbackResult_NOT_DETECTED:
            if (self.documentSide == MobbScanDocumentSide_FRONT) {
                [self.feedbackLabel setText:@"Looking for document edges...\n(FRONT side)"];
                [self.border changeStrokeColor:self.notDetectedColor];
            } else if (self.documentSide == MobbScanDocumentSide_BACK) {
                [self.feedbackLabel setText:@"Looking for document edges...\n(BACK side)"];
                [self.border changeStrokeColor:self.notDetectedColor];
            } else {
                [self.border changeStrokeColor:self.notDetectedColor];
            }
            self.feedbackLabel.textColor = [UIColor whiteColor];
            break;
        case MobbScanDetectionFeedbackResult_DETECTED:
            [self.feedbackLabel setText:@"Preparing to take picture, stay still..."];
            self.feedbackLabel.textColor = [UIColor greenColor];
            [self.border changeStrokeColor:self.detectedColor];
            break;
        case MobbScanDetectionFeedbackResult_PDF417_DETECTED:
        case MobbScanDetectionFeedbackResult_PDF417_TIMEOUT:
            [self removePDF417CodeOverview];
            break;
        case MobbScanDetectionFeedbackResult_PDF417_NOT_DETECTED:
            [self.feedbackLabel setText:@"Buscando código de barras..."];
            break;
    }
}
#pragma mark - Visual detection
- (void)removePDF417CodeOverview{
    [self.border setHidden:NO];
    [self.fillLayer removeFromSuperlayer];
}
- (void)addPDF417CodeOverview {
    float width = 400;
    float height = 50;
    self.feedbackLabel.frame = CGRectMake(self.view.bounds.size.width / 2 - width / 2, self.view.bounds.size.height / 2 - height / 2, width, height);
    self.feedbackLabel.textColor = [UIColor whiteColor];
    self.view.layer.backgroundColor = [[UIColor colorWithWhite:0.0f alpha:0.5f] CGColor];
    self.feedbackLabel.numberOfLines = 3;
    self.feedbackLabel.textAlignment = NSTextAlignmentCenter;
    self.feedbackLabel.lineBreakMode = NSLineBreakByClipping;
    self.feedbackLabel.font = [UIFont fontWithName:@"Courier" size:14];
    [self addAlphaForWidth:width andHeignt:height];
    
    [self.view addSubview:self.feedbackLabel];
    [self.view bringSubviewToFront:self.feedbackLabel];
}
- (void)addAlphaForWidth:(float)width andHeignt:(float)height{
    UIBezierPath *overlayPath = [UIBezierPath bezierPathWithRect:self.view.bounds];
    
    UIBezierPath *transparentPath = [UIBezierPath bezierPathWithRect:CGRectMake(self.view.bounds.size.width / 2 - width / 2, self.view.bounds.size.height / 4 - height / 4, width, height)];
    [overlayPath appendPath:transparentPath];
    [overlayPath setUsesEvenOddFillRule:YES];
    
    self.fillLayer = [CAShapeLayer layer];
    self.fillLayer.path = overlayPath.CGPath;
    self.fillLayer.fillRule = kCAFillRuleEvenOdd;
    self.fillLayer.fillColor = [[UIColor colorWithWhite:0.0f alpha:0.5f] CGColor];
    
    [self.view.layer addSublayer:self.fillLayer];
}

#pragma mark - User interaction

- (IBAction)cancelButtonTouched:(id)sender {
    [self.mobbScanAPI destroyDetectionTrack];
    [self.detectionTrack onPause];
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
