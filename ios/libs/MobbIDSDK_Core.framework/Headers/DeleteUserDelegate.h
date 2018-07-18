//
//  DeleteUserDelegate.h
//  MobbIDAPI
//
//  Created by Abraham Holgado on 22/04/13.
//
//

#import <Foundation/Foundation.h>

/** 
 Possible return values for the [DeleteUserDelegate deleteUserFinished:forUser:error:] operation.
 */
typedef NS_ENUM(NSInteger, MobbIDAPIDeleteUserDelegateResult)  {
    /** User has been deleted */
    MobbIDAPIDeleteUserDelegateResult_OK,
    /** There has been some error with the operation. */
    MobbIDAPIDeleteUserDelegateResult_ERROR
};

/** 
 Delegate to inform of the result of the [MobbIDManagementAPI deleteUser:delegate] 
 */
@protocol DeleteUserDelegate <NSObject>

/**
 Sent to the delegate when the delete user operation is completed.
 
 @param result Possibles values of the result of the operation. @see MobbIDAPIDeleteUserDelegateResult
 @param userId The identifier of the user that has been deleted.
 @param errorOccurred If an error has occurred, all the information will be available here. Possible error codes for this operation are (@see MobbIDAPIErrorCode):
 
 - MobbIDAPIErrorCode.ERROR_USER_FIELD_REQUIRED The userId is mandatory.
 - MobbIDAPIErrorCode.ERROR_USER_DOES_NOT_EXIST The userId specified does not belong to any registered user.

 */
- (void)deleteUserFinished:(MobbIDAPIDeleteUserDelegateResult)result forUser:(NSString*)userId error:(NSError *)errorOccurred;

@end
