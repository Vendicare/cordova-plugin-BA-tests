//
//  ConfirmUserDelegate.h
//  MobbIDAPI
//
//  Created by Abraham Holgado on 22/04/13.
//
//

#import <Foundation/Foundation.h>

/** 
 Possible return values for the [ConfirmUserDelegate confirmCreateUserFinished:forUser:error:] operation.
 */
typedef NS_ENUM(NSInteger, MobbIDAPIConfirmUserResult) {
    /** User has been confirmed */
    MobbIDAPIConfirmUserResult_OK,
    /** There has been some error confirming the user. */
    MobbIDAPIConfirmUserResult_ERROR
};

/** 
 Delegate to inform of the result of the [MobbIDManagementAPI confirmCreateUser:token:delegate:] 
 */
@protocol ConfirmUserDelegate <NSObject>

/**
 Sent to the delegate when the confirmation operation is completed.
 
 Once the user is confirmed, he can be enrolled in the available biometric methods (which ones are available depend on the client's license)
 
 @param result Possibles values of the result of the operation. See MobbIDAPIConfirmUserResult 
 @param userId The identifier of the user confirmated.
 @param errorOccurred If an error has occurred, all the information will be available here. Possible error codes for this operation are (@see MobbIDAPIErrorCode): 
 
 - MobbIDAPIErrorCode.ERROR_USER_FIELD_REQUIRED The userId is mandatory.
 - MobbIDAPIErrorCode.ERROR_USER_DOES_NOT_EXIST The userId specified does not belong to any registered user.
 - MobbIDAPIErrorCode.ERROR_TOKEN_IS_NOT_VALID The token is not the one created for the user
 - MobbIDAPIErrorCode.ERROR_TOKEN_HAS_EXPIRED The validity of the token has expired.
 - MobbIDAPIErrorCode.ERROR_USER_AND_TOKEN_COMBINATION_NOT_VALID: The combination between token and user is not valid
 
 */
- (void)confirmCreateUserFinished:(MobbIDAPIConfirmUserResult)result forUser:(NSString*)userId error:(NSError *)errorOccurred;


@end
