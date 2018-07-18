#import "BorderView.h"


@interface BorderView ()

@property (nonatomic, strong) CAShapeLayer *borderShapeLayer;
@property (nonatomic, strong) CAShapeLayer *cornersShapeLayer;

@end


@implementation BorderView

- (void)drawRect:(CGRect)rect {
    [self drawBorder];
    [self drawCorners];
}

- (void)drawBorder {
    self.borderShapeLayer = [CAShapeLayer layer];
    self.borderShapeLayer.lineWidth = self.lineWidth;
    self.borderShapeLayer.strokeColor = self.strokeColor.CGColor;
    self.borderShapeLayer.fillColor = nil;
    self.borderShapeLayer.lineDashPattern = @[
        [NSNumber numberWithDouble:self.dashWidth],
        [NSNumber numberWithDouble:self.dashGap]
    ];

    CGRect frame;
    frame.origin.x = self.lineWidth / 2 + 1;
    frame.origin.y = self.lineWidth / 2 + 1;
    frame.size.width = self.bounds.size.width - self.lineWidth - 2;
    frame.size.height = self.bounds.size.height - self.lineWidth - 2;
    self.borderShapeLayer.frame = frame;
    self.borderShapeLayer.path = [UIBezierPath bezierPathWithRect:self.borderShapeLayer.bounds].CGPath;
    [self.layer addSublayer:self.borderShapeLayer];
}

- (void)drawCorners {
    UIBezierPath *path = [UIBezierPath bezierPath];

    [path moveToPoint:CGPointMake(self.lineWidth / 2 + 1, self.cornerWidth)];
    [path addLineToPoint:CGPointMake(self.lineWidth / 2 + 1, 0)];
    [path moveToPoint:CGPointMake(0, self.lineWidth / 2 + 1)];
    [path addLineToPoint:CGPointMake(self.cornerWidth, self.lineWidth / 2 + 1)];

    [path moveToPoint:CGPointMake(self.bounds.size.width - self.cornerWidth, self.lineWidth / 2 + 1)];
    [path addLineToPoint:CGPointMake(self.bounds.size.width, self.lineWidth / 2 + 1)];
    [path moveToPoint:CGPointMake(self.bounds.size.width - self.lineWidth / 2 - 1, 0)];
    [path addLineToPoint:CGPointMake(self.bounds.size.width - self.lineWidth / 2 - 1, self.cornerWidth)];

    [path moveToPoint:CGPointMake(self.bounds.size.width - self.lineWidth / 2 - 1, self.bounds.size.height - self.cornerWidth)];
    [path addLineToPoint:CGPointMake(self.bounds.size.width - self.lineWidth / 2 - 1, self.bounds.size.height)];
    [path moveToPoint:CGPointMake(self.bounds.size.width, self.bounds.size.height - self.lineWidth / 2 - 1)];
    [path addLineToPoint:CGPointMake(self.bounds.size.width - self.cornerWidth, self.bounds.size.height - self.lineWidth / 2 - 1)];

    [path moveToPoint:CGPointMake(self.cornerWidth, self.bounds.size.height - self.lineWidth / 2 - 1)];
    [path addLineToPoint:CGPointMake(0, self.bounds.size.height - self.lineWidth / 2 - 1)];
    [path moveToPoint:CGPointMake(self.lineWidth / 2 + 1, self.bounds.size.height)];
    [path addLineToPoint:CGPointMake(self.lineWidth / 2 + 1, self.bounds.size.height - self.cornerWidth)];

    self.cornersShapeLayer = [CAShapeLayer layer];
    self.cornersShapeLayer.path = [path CGPath];
    self.cornersShapeLayer.strokeColor = self.strokeColor.CGColor;
    self.cornersShapeLayer.lineWidth = 1 + self.lineWidth + 1;

    [self.layer addSublayer:self.cornersShapeLayer];
}

- (void)changeStrokeColor:(UIColor *)color {
    self.borderShapeLayer.strokeColor = color.CGColor;
    self.cornersShapeLayer.strokeColor = color.CGColor;
}

@end
