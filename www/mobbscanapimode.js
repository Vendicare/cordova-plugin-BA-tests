/*global cordova, module*/
/**
 * Enum for MobbScan's mode that supports.
 * @readonly
 * @enum {string}
 * @memberof MobbScanAPI
 */
var MobbScanAPIMode = {
    /** Online mode, the evidences will be scanned to the server*/
    ONLINE: { value: "ONLINE" },
    /** Offline mode, the evidences will be scanned on the device */
    OFFLINE: { value: "OFFLINE" }
};

module.exports = MobbScanAPIMode;
