//
//  MobbScanSDK-iOS.h
//  MobbScanSDK-iOS
//
//  Created by Rodrigo Sanchez on 15/06/15.
//  Copyright (c) 2015 Mobbeel Solutions. All rights reserved.
//

#ifndef MobbScanSDK_iOS_h
#define MobbScanSDK_iOS_h

#import <UIKit/UIKit.h>
#import "ESIDCard.h"
#import "ESPIDCardV1.h"
#import "ESPIDCardV2.h"
#import "ESPIDCardV2KinegramValidationResultData.h"
#import "ESPIDCardV2LaserMarkValidationResultData.h"
#import "ESPIDCardV3.h"
#import "FaceRecognitionValidationResultData.h"
#import "IDDocument.h"
#import "IDDocumentMRZ.h"
#import "IDDocumentTD1.h"
#import "TD1IDCard.h"
#import "MobbScanAPI.h"
#import "MobbScanAPITypes.h"
#import "MobbScanDetectionResultData.h"
#import "MobbScanError.h"
#import "MobbScanFaceAcquisitorData.h"
#import "MobbScanFaceValidationParams.h"
#import "MobbScanScanResultData.h"
#import "MobbScanUtils.h"
#import "MobbScanValidationResultData.h"
#import "MobbScanVideoAPI.h"
#import "MobbScanVideoResultData.h"
#import "MobbScanVideoView.h"
#import "Passport.h"
#import "NIEIDCard.h"
#import "GBRIDCard.h"
#import "HRVIDCard.h"
#import "ITAIDCard.h"
#import "BGRIDCard.h"
#import "HUNIDCard.h"
#import "POLIDCard.h"
#import "ROUIDCard.h"
#import "CHEIDCard.h"
#import "GTMIDCard.h"
#import "DEUIDCard.h"
#import "DEUIDCardAF.h"
#import "DEUIDCardV1.h"
#import "DEUIDCardV2.h"
#import "KWTPassport.h"
#import "MEXIDCard.h"
#import "COLIDCardV3.h"
#import "SLVIDCardV1.h"
#import "SLVIDCardPDF417.h"
#import "PERIDCardV1.h"
#import "PRTIDCard.h"
#import "CHLIDCardE.h"
#import "AREPassport.h"
#import "CHNPassport.h"
#import "AUTPassport.h"
#import "AUTIDCard.h"
#import "SAUPassport.h"
#import "UKRPassport.h"
#import "USAPassport.h"

//! Project version number for MobbScanSDK-iOS.
FOUNDATION_EXPORT double MobbScanSDK_iOSVersionNumber;

//! Project version string for MobbScanSDK-iOS.
FOUNDATION_EXPORT const unsigned char MobbScanSDK_iOSVersionString[];

#endif /* MobbScanSDK_iOS_h */
