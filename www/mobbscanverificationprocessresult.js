/*global cordova, module*/
/**
 * Enum for MobbScan's verification process result.
 * @readonly
 * @enum {string}
 * @memberof MobbScanAPI
 */
var MobbScanVerificationProcessResult = {
    /**Verified */
    VERIFIED: { value: "VERIFIED" },
    /**Not verified */
    NOT_VERIFIED: { value: "NOT_VERIFIED" },
    /**Pending */
    PENDING: { value: "PENDING" },
    /**Error */
    ERROR: { value: "ERROR" }
};

module.exports = MobbScanVerificationProcessResult;
