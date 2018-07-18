/*global cordova, module*/
/**
 * Enum for MobbScan's face acquisitor result.
 * @readonly
 * @enum {string}
 * @memberof MobbScanAPI
 */
var MobbScanFaceAcquisitorResult = {
    /**Face acquired */
    FACE_ACQUIRED: { value: "FACE_ACQUIRED" },
    /**Error */
    ERROR: { value: "ERROR" }
};

module.exports = MobbScanFaceAcquisitorResult;
