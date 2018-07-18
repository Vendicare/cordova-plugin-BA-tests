/*global cordova, module*/
/**
 * Enum for MobbScan's validation state.
 * @readonly
 * @enum {string}
 * @memberof MobbScanAPI
 */
var MobbScanValidationState = {
    /**Not checked */
    NOT_CHECKED: { value: "NOT_CHECKED" },
    /**Not valid */
    NOT_VALID: { value: "NOT_VALID" },
    /**Valid */
    VALID: { value: "VALID" }
};

module.exports = MobbScanValidationState;
