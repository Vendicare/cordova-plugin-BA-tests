#import <UIKit/UIKit.h>

IB_DESIGNABLE


@interface BorderView : UIView

@property (nonatomic, strong) IBInspectable UIColor *strokeColor;
@property (nonatomic, assign) IBInspectable CGFloat lineWidth;
@property (nonatomic, assign) IBInspectable CGFloat dashWidth;
@property (nonatomic, assign) IBInspectable CGFloat dashGap;
@property (nonatomic, assign) IBInspectable CGFloat cornerWidth;

- (void)changeStrokeColor:(UIColor *)color;

@end
