/**
 * Enum for MobbScan face validation mode.
 * @readonly
 * @enum {string}
 * @memberof MobbScanAPI
 */
var MobbScanFaceValidationMode = {
    /**Default */
    DEFAULT: { value: "DEFAULT" },
    /**Liveness head movement */
    LIVENESS_HEAD_MOVEMENT: { value: "LIVENESS_HEAD_MOVEMENT" },
    /**Liveness smile */
    LIVENESS_SMILE: { value: "LIVENESS_SMILE" }

};

module.exports = MobbScanFaceValidationMode;
