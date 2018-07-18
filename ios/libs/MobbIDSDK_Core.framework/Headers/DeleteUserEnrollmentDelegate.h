//
//  DeleteUserEnrollmentDelegate.h
//  MobbIDAPI
//
//  Created by Abraham Holgado Garcia on 25/01/16.
//
//

#ifndef DeleteUserEnrollmentDelegate_h
#define DeleteUserEnrollmentDelegate_h

/**
 Possible return values for the [DeleteUserEnrollmentDelegate deleteUserEnrollmentFinished:forUser:error:] operation.
 */
typedef NS_ENUM(NSInteger, MobbIDAPIDeleteUserEnrollmentDelegateResult)  {
    /** User's biometric enrollment has been deleted */
    MobbIDAPIDeleteUserEnrollmentDelegateResult_OK,
    /** There has been some error with the operation. */
    MobbIDAPIDeleteUserEnrollmentDelegateResult_ERROR
};

/**
 Delegate to inform of the result of the [MobbIDManagementAPI deleteUserEnrollment:method:delegate]
 */
@protocol DeleteUserEnrollmentDelegate <NSObject>

/**
 Sent to the delegate when the delete enrollment operation is completed.
 
 @param result Possibles values of the result of the operation. @see MobbIDAPIDeleteUserEnrollmentDelegateResult
 @param userId The identifier of the user that has been deleted.
 @param errorOccurred If an error has occurred, all the information will be available here. (@see MobbIDAPIErrorCode)
 */
- (void)deleteUserEnrollmentFinished:(MobbIDAPIDeleteUserEnrollmentDelegateResult)result
                             forUser:(NSString*)userId
                               error:(NSError *)errorOccurred;

@end



#endif /* DeleteUserEnrollmentDelegate_h */
