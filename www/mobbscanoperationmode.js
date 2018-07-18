/*global cordova, module*/
/**
 * Enum with the MobbScan's operation modes.
 * @readonly
 * @enum {string}
 * @memberof MobbScanAPI
 */
var MobbScanOperationMode = {
    /**If you only want to scan the document's front side */
    SCAN_ONLY_FRONT: { value: "SCAN_ONLY_FRONT" },
    /**If you only want to scan the document's back side */
    SCAN_ONLY_BACK: { value: "SCAN_ONLY_BACK" },
    /**If you only want to scan the document's both side */
    SCAN_BOTH_SIDES: { value: "SCAN_BOTH_SIDES" }
};

module.exports = MobbScanOperationMode;
