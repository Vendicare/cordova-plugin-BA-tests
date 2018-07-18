//
//  CheckCreateUserDelegate.h
//  MobbIDAPI
//
//  Created by Abraham Holgado on 22/04/13.
//
//

#import <Foundation/Foundation.h>

/** 
 Possible return values for the [CheckCreateUserDelegate checkCreateUserFinished:forUser:error:] operation.
 */
typedef NS_ENUM(NSInteger, MobbIDAPICheckCreateUserResult)  {
    /** The user has been properly created */
    MobbIDAPICheckCreateUserResult_USER_CREATED,
    /** There has been some error with the operation. */
    MobbIDAPICheckCreateUserResult_ERROR
};

/**
 Delegate to inform of the result of the [MobbIDManagementAPI checkCreateUser:delegate:] operation
 */
@protocol CheckCreateUserDelegate <NSObject>

/**
 Sent to the delegate when a check user creation operation is completed.
 
 @param result Possibles values of the result of the operation. @see MobbIDAPICheckCreateUserResult
 @param userId The identifier of the user to be check.
 @param errorOccurred If an error has occurred, all the information will be available here. Possible error codes for this operation are (@see MobbIDAPIErrorCode):
 
 - MobbIDAPIErrorCode.ERROR_USER_FIELD_REQUIRED The userId is mandatory.
 - MobbIDAPIErrorCode.ERROR_USER_DOES_NOT_EXIST The userId specified does not belong to any registered user.
 - MobbIDAPIErrorCode.ERROR_USER_IS_NOT_ACTIVATED The user is created, but it is not activated yet.
 
 */
- (void)checkCreateUserFinished:(MobbIDAPICheckCreateUserResult)result forUser:(NSString*)userId error:(NSError *)errorOccurred;

@end
