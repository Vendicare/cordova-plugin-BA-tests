//
//  MobbScanCaptureSessionTakenPictureDelegate.h
//  MobbScanSDK-iOS
//
//  Created by Juan Andrés Borrallo Domínguez on 20/2/18.
//  Copyright © 2018 Mobbeel Solutions. All rights reserved.
//

@protocol PictureTakenDelegate <NSObject>

- (void)onPictureTaken:(UIImage*)img;

@end
