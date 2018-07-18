//
//  CheckLicenseDelegate.h
//  MobbIDAPI
//
//  Created by Abraham Holgado on 24/04/13.
//
//

#import <Foundation/Foundation.h>

/** 
 Possible return values for the [CheckLicenseDelegate checkLicenseFinished:error:] operation. 
 */
typedef NS_ENUM(NSInteger, MobbIDAPICheckLicenseResult) {
    /** The license is valid */
    MobbIDAPICheckLicenseResult_LICENSE_IS_VALID,
    /** There has been some error with the operation */
    MobbIDAPICheckLicenseResult_ERROR
};

/**
 Delegate to inform of the result of the [MobbIDManagementAPI checkLicense:] 
 */
@protocol CheckLicenseDelegate <NSObject>

/**
 Sent to the delegate when the check license operation is completed.
 
 @param result Possibles values of the result of the operation. @see MobbIDAPICheckLicenseResult
 @param errorOccurred If an error has occurred, all the information will be available here. Possible error codes for this operation are (@see MobbIDAPIErrorCode):
 
 - MobbIDAPIErrorCode.ERROR_LICENSE_FIELD_REQUIRED licenseId required input parameter is missing.
 - MobbIDAPIErrorCode.ERROR_LICENSE_FILE_NOT_FOUND licenseId does not belong to any registered license on the server.
 - MobbIDAPIErrorCode.ERROR_LICENSE_WRONG_LICENSE_ID The license file does not correspond with the given licenseId parameter.
 - MobbIDAPIErrorCode.ERROR_LIMIT_USERS_EXCEEDED
 - MobbIDAPIErrorCode.ERROR_LICENSE_EXPIRED
 - MobbIDAPIErrorCode.ERROR_LICENSE_WRONG_FORMAT
 - MobbIDAPIErrorCode.ERROR_LICENSE_PERIOD_IS_NOT_ACTIVE_YET 

 */
- (void) checkLicenseFinished:(MobbIDAPICheckLicenseResult)result error:(NSError *)errorOccurred;

@end
