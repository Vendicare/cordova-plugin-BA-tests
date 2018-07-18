/*global cordova, module*/
/**
 * Enum for MobbScan's video result.
 * @readonly
 * @enum {string}
 * @memberof MobbScanVideoAPI
 */
var MobbScanVideoResult = {
    /**Waiting on agent or client's connection */
    WAITING: { value: "WAITING" },
    /**Video conference started */
    ON_PROCESS: { value: "ON_PROCESS" },
    /**Videoconference has finished */
    FINISHED: { value: "FINISHED" },
    /**Error */
    ERROR: { value: "ERROR" }
};

module.exports = MobbScanVideoResult;
