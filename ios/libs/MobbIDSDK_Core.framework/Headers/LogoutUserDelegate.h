//
//  LogoutUserDelegate.h
//  MobbIDAPI
//
//  Created by Abraham Holgado on 22/04/13.
//
//

#import <Foundation/Foundation.h>

/** 
 Possible return values for the LogoutUserDelegate logoutFinished:forUser:error: operation.
 */
typedef NS_ENUM(NSInteger, MobbIDAPILogoutUserResult) {
    /** User has been logout properly */
    MobbIDAPILogoutUserResult_OK,
    /** There has been some error with the operation. */
    MobbIDAPILogoutUserResult_ERROR
};

/** 
 Delegate to inform of the result of the [MobbIDManagementAPI logoutUser:delegate:error:] operation.
 */
@protocol LogoutUserDelegate <NSObject>

/**
 Sent to the delegate when the logout operation is completed 
 
 @param result Possibles values of the result of the operation. @see MobbIDAPILogoutUserResult
 @param userId The identifier of the user that has been logged out.
 @param errorOccurred If an error has occurred, all the information will be available here. Possible error codes for this operation are (@see MobbIDAPIErrorCode):
 
 - MobbIDAPIErrorCode.ERROR_USER_FIELD_REQUIRED The userId is mandatory.
 - MobbIDAPIErrorCode.ERROR_USER_DOES_NOT_EXIST The userId specified does not belong to any registered user.
 
 */
- (void)logoutFinished:(MobbIDAPILogoutUserResult)result forUser:(NSString*)userId error:(NSError *)errorOccurred;

@end
