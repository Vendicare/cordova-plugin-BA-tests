//
//  CheckOperationAuthorizationDelegate.h
//  MobbIDAPI
//
//  Created by Abraham Holgado on 22/04/13.
//
//

#import <Foundation/Foundation.h>

/** 
 Possible return values for the [CheckOperationAuthorizationDelegate checkOperationAuthorizationFinished:forUser:methods:methodsCombination:operationType:operationId:error:] operation. 
 */
typedef NS_ENUM(NSInteger, MobbIDAPICheckOperationAuthorizationResult) {
    /** The user is authorized to perform the operation */
    MobbIDAPICheckOperationAuthorizationResult_USER_IS_AUTHORIZED,
    /** The user is not authorized to perform the operation */
    MobbIDAPICheckOperationAuthorizationResult_USER_IS_NOT_AUTHORIZED,
    /** There has been some error with the operation. */
    MobbIDAPICheckOperationAuthorizationResult_ERROR
};

/** 
 This enum indicates the biometric method combination (AND,OR) that the user must meet in order to be able to perform the operation.
 */
typedef NS_ENUM(NSInteger,MobbIDAPIBiometricMethodsCombination) {
    /** The user must be verified in every method indicated in the operation */
    MobbIDAPIBiometricMethodsCombination_AND,
    /** The user must be verified in one method indicated in the operation */
    MobbIDAPIBiometricMethodsCombination_OR
};

/** 
 Delegate to inform of the result of the [MobbIDManagementAPI checkOperationAuthorization:operationType:delegate:] 
 */
@protocol CheckOperationAuthorizationDelegate <NSObject>

/**
 Sent to the delegate when the check operation authorization is completed.
 
 @param result Possibles values of the result of the operation. See MobbIDAPICheckOperationAuthorizationResult
 @param userId The identifier of the user that has been checked.
 @param methods The list of biometric methods in which the user must be verified to be able to perform the operation. Possible values are (Constants in MobbIDBaseAPI):
 
 - kMobbIDAPI_BiometricMethod_Signature
 - kMobbIDAPI_BiometricMethod_Iris
 - kMobbIDAPI_BiometricMethod_Face
 - kMobbIDAPI_BiometricMethod_Voice
 
 @param combination The combination of the biometric methods needed to perform the operation. The possible values are:
 
 - MobbIDAPIBiometricMethodsCombination_AND: The user must be verified in all the methods returned in "methods"
 - MobbIDAPIBiometricMethodsCombination_OR: The user must be verified in one of the methods returned in "methods"
 
 @param operationType The identifier of the operation type that has been checked.
 @param errorOccurred If an error has occurred, all the information will be available here. Possible error codes for this operation are (@see MobbIDAPIErrorCode):
 
 - MobbIDAPIErrorCode.ERROR_USER_FIELD_REQUIRED The userId is mandatory.
 - MobbIDAPIErrorCode.ERROR_USER_DOES_NOT_EXIST The userId specified does not belong to any registered user.
 - MobbIDAPIErrorCode.ERROR_OPERATION_TYPE_DOES_NOT_EXIST The operation type does not exist
 - MobbIDAPIErrorCode.ERROR_OPERATION_TYPE_FIELD_NOT_VALID The operation type format is not valid
 
 */
- (void)checkOperationAuthorizationFinished:(MobbIDAPICheckOperationAuthorizationResult)result
                                    forUser:(NSString*)userId
                                    methods:(NSArray*)methods
                         methodsCombination:(MobbIDAPIBiometricMethodsCombination)combination
                              operationType:(NSString*)operationType
                                      error:(NSError *)errorOccurred;

@end
