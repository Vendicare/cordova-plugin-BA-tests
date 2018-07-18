/*global cordova, module*/
/**
 * Enum for MobbScan's scan document result.
 * @readonly
 * @enum {string}
 * @memberof MobbScanAPI
 */
var MobbScanScanResult = {
    /**Completed */
    COMPLETED: { value: "COMPLETED" },
    /**Pending the other side */
    PENDING_OTHER_SIDE: { value: "PENDING_OTHER_SIDE" },
    /**Error */
    ERROR: { value: "ERROR" }
};

module.exports = MobbScanScanResult;
