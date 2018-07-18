#import "NSDate+MobbScan.h"


@implementation NSDate (MobbScan)

- (NSString *)stringWithFormat:(NSString *)dateFormat {
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    dateFormatter.dateFormat = dateFormat;
    NSString *formattedDate = [dateFormatter stringFromDate:self];
    return formattedDate;
}

@end
