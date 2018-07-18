#import "UIImage+MobbScan.h"

@implementation UIImage (MobbScan)

- (NSString *)convertToBase64 {
    NSData *data = UIImageJPEGRepresentation(self, 1.0);
    NSString *base64Image = [NSString stringWithFormat:@"%@", [data base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength]];
    return base64Image;
}

@end
