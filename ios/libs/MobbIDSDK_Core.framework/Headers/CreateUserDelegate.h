//
//  CreateUserDelegate.h
//  MobbIDAPI
//
//  Created by Abraham Holgado on 22/04/13.
//
//

#import <Foundation/Foundation.h>

/** 
 Possible return values for the [CreateUserDelegate createUserFinished:forUser:token:error:] operation.
 */
typedef NS_ENUM(NSInteger, MobbIDAPICreateUserResult) {
    /** User has been created */
    MobbIDAPICreateUserResult_OK,
    /** There has been some error with the operation. */
    MobbIDAPICreateUserResult_ERROR
};

/** 
 Delegate to inform of the result of the [MobbIDManagementAPI createUserWithLanguage:andGender:delegate:]
 */
@protocol CreateUserDelegate <NSObject>

/**
 Sent to the delegate when the user creation operation is completed.
 
 @param result The result of the operation. @see MobbIDAPICreateUserResult
 @param userId The unique identifier for the user just created. This identifier would be needed for all the subsequent operations.
 @param token A unique identifier for the user creation operation that must be used in the confirmation process.
 @param errorOccurred If an error has occurred, all the information will be available here. Possible error codes for this operation are (@see MobbIDAPIErrorCode):
 
 - MobbIDAPIErrorCode.ERROR_USER_FIELD_REQUIRED The userId is mandatory.
 - MobbIDAPIErrorCode.ERROR_USER_DOES_NOT_EXIST The userId specified does not belong to any registered user.
 - MobbIDAPIErrorCode.ERROR_WRONG_PARAMETERS The parameters for the creation are not correct (the language or gender providded are not correct).
 
 */
- (void)createUserFinished:(MobbIDAPICreateUserResult)result forUser:(NSString*)userId token:(NSString*)token error:(NSError *)errorOccurred;

@end
