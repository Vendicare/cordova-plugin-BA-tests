/*global cordova, module*/
/**
* Success callback.
* @method successCallback
* @param {string} message - The feedback message.
*/

/**
* Error callback.
* @method errorCallback
* @param {string} message - The feedback message.
*/

/** @namespace MobbScanAPI */
var MobbScanAPI = {
    /**
    * MobbScanResultData
    * @type {object}
    * @property {string} address
    * @property {string} city
    * @property {string} cityOfBirth
    * @property {string} dateOfBirth
    * @property {string} dateOfExpiry
    * @property {string} documentNumber
    * @property {string} documentType
    * @property {string} firstSurname
    * @property {string} gender
    * @property {string} issuingState
    * @property {string} mrz
    * @property {string} name
    * @property {string} nationality
    * @property {string} parents
    * @property {string} personalNumber
    * @property {string} region
    * @property {string} regionOfBirth
    * @property {string} secondSurname
    * @property {string} surname
    * @property {string} validationBackAppearance
    * @property {string} validationBackAppearanceScore
    * @property {string} validationBothSidesMatch
    * @property {string} validationDateOfBirth
    * @property {string} validationDateOfExpiry
    * @property {string} validationDocumentNotExpired
    * @property {string} validationFacialMatchingScore
    * @property {string} validationFrontAppearance
    * @property {string} validationFrontAppearanceScore
    * @property {string} validationIssuingState
    * @property {string} validationMRZ
    * @property {string} validationMRZCheckComposite
    * @property {string} validationMRZCheckDateOfBirth
    * @property {string} validationMRZCheckDateOfExpiry
    * @property {string} validationMRZCheckDocumentNumber
    * @property {string} validationMRZCheckPersonalNumber
    * @property {string} validationMRZNameSurnameSeparator
    * @property {string} validationMRZSurnameSeparator
    * @property {string} validationNationality
    * @property {string} validationPersonalNumber
    * @property {string} validationSex
    * @memberOf MobbScanAPI 
    */

    /**
     * MobbScanDetectDocumentResult
     * @type {object}
     * @property {MobbScanDocumentSide} documentSide - The document side scanned. "FRONT" OR "BACK". 
     * @property {string} image - The document's base64 image. 
     * @memberOf MobbScanAPI 
    */

    /**
     * method scanDocumentImageCallback
     * @method scanDocumentImageCallback
     * @param {MobbScanDetectDocumentResult} MobbScanDetectDocumentResult - Returns the object with the detection result
     * @memberOf MobbScanAPI 
     */

    /**
     * ScanDocumentDataCallback
     * @method ScanDocumentDataCallback
     * @param {MobbScanResultData} MobbScanResultData - Returns the object with the detection data result
     * @memberOf MobbScanAPI 
     */

    /**
    * Set your detection listener to receive the detected documents.
    * @method initAPIWithLicense
    * @param {string} license - Your MobbScan's license.
    * @param {successCallback} successCallback - The success callback. The output is "License check result: VALID".
    * @param {errorCallback} errorCallback - The error callback. The output is "License check result: NOT_VALID".
    * @memberOf MobbScanAPI
    */
    initAPIWithLicense: function (license, successCallback, errorCallback) {
        cordova.exec(successCallback, errorCallback, "MobbScan", "initAPIWithLicense", [license]);
    },
    /**
     * Sets the MobbScan's base url.
     * @method setBaseURL
     * @param {string} baseURL - Your MobbScan's server url.
     * @param {successCallback} successCallback - The success callback. The output is "Base URL: [your baseURL]".
     * @param {errorCallback} errorCallback - The error callback. 
     * @memberOf MobbScanAPI
     */
    setBaseURL: function (baseURL, successCallback, errorCallback) {
        cordova.exec(successCallback, errorCallback, "MobbScan", "setBaseURL", [baseURL]);
    },
    /**
     * Sets the api mode scan (Online or Offline).
     * @method setAPIMode
     * @param {MobbScanAPIMode} APIMode - The MobbScan's api mode.
     * @param {successCallback} successCallback - The success callback. The output is "API mode: [APIMode]".
     * @param {errorCallback} errorCallback - The error callback.
     * @memberOf MobbScanAPI
     */
    setAPIMode: function (APIMode, successCallback, errorCallback) {
        cordova.exec(successCallback, errorCallback, "MobbScan", "setAPIMode", [APIMode.value]);
    },
    /**
     * Sets the document detection interface if you do not want to use the interface provided by the API.
     * @method setDocumentDetectionInterface
     * @param {string} documentDetectionInterfaceName - Your custom interface class name. Example "com.yourEnterprise.packageName.CustomDetectionInterface".
     * @param {successCallback} successCallback - The success callback. The output is "Document detection interface name: [your documentDetectionInterfaceName]".
     * @param {errorCallback} errorCallback - The error callback.
     * @memberOf MobbScanAPI
     */
    setDocumentDetectionInterface: function (documentDetectionInterfaceName, successCallback, errorCallback) {
        cordova.exec(successCallback, errorCallback, "MobbScan", "setDocumentDetectionInterface", [documentDetectionInterfaceName]);
    },
    /**
     * Sets the other document detection interface if you do not want to use the interface provided by the API.
     * @method setOtherDocumentDetectionInterface
     * @param {string} documentDetectionInterfaceName - Your custom interface class name.Example "com.yourEnterprise.packageName.CustomDetectionInterface".
     * @param {successCallback} successCallback - The success callback. The output is "Document detection interface name: [your documentDetectionInterfaceName]".
     * @param {errorCallback} errorCallback - The error callback.
     * @memberOf MobbScanAPI
     */
    setOtherDocumentDetectionInterface: function (documentDetectionInterfaceName, successCallback, errorCallback) {
        cordova.exec(successCallback, errorCallback, "MobbScan", "setOtherDocumentDetectionInterface", [documentDetectionInterfaceName]);
    },
    /**
     * Starts scan for document type, when you call this function the API returns a new scanId.
     * @method startScanForDocumentType
     * @param {MobbScanDocumentType} documentType - The document type that user is going to scan.
     * @param {MobbScanOperationMode} operationMode - The MobbScan operation mode.
     * @param {successCallback} successCallback - The success callback. The output is "[scanId]"
     * @param {errorCallback} errorCallback - The error callback. The output is Example "Start scan result: ERROR".
     * @memberOf MobbScanAPI
     */
    startScanForDocumentType: function (documentType, operationMode, successCallback, errorCallback) {
        cordova.exec(successCallback, errorCallback, "MobbScan", "startScanForDocumentType", [documentType.value, operationMode.value]);
    },
    /**
     * Sets the scan document image callback.
     * @method setScanDocumentImageCallback
     * @param {ScanDocumentImageCallback} successCallback - The Scan Document Image callback.
     * @memberOf MobbScanAPI
     */
    setScanDocumentImageCallback: function (successCallback) {
        cordova.exec(successCallback, null, "MobbScan", "setScanDocumentImageCallback", []);
    },
    /**
     * Sets the scan document data callback.
     * @method setScanDocumentDataCallback
     * @param {ScanDocumentDataCallback} successCallback - The Scan Document Data callback.
     * @memberOf MobbScanAPI
     */
    setScanDocumentDataCallback: function (successCallback) {
        cordova.exec(successCallback, null, "MobbScan", "setScanDocumentDataCallback", []);
    },
    /**
     * This function launch the detection document activity.
     * @method scanDocumentForSide
     * @param {MobbScanOperationMode} documentSide - The MobbScan operation mode that you want to use (Scan only front, only back or both sides).
     * @param {string} scanId - The scanId obtained on startScanForDocumentType.
     * @param {successCallback} successCallback - The success callback.
     * @param {errorCallback} errorCallback - The error callback.
     * @memberOf MobbScanAPI
     */
    scanDocumentForSide: function (documentSide, scanId, successCallback, errorCallback) {
        cordova.exec(successCallback, errorCallback, "MobbScan", "scanDocumentForSide", [documentSide.value, scanId]);
    },
    /**
     * Checks verification process result after realize the video conference.
     * @method checkVerificationProcessResult
     * @param {string} scanId - The scanId obtained on startScanForDocumentType.
     * @param {successCallback} successCallback - The success callback.
     * @param {errorCallback} errorCallback - The error callback.
     * @memberOf MobbScanAPI
     */
    checkVerificationProcessResult: function (scanId, successCallback, errorCallback) {
        cordova.exec(successCallback, errorCallback, "MobbScan", "checkVerificationProcessResult", [scanId]);
    },
    /**
     * This method launch the validation face activity.
     * @method validateFace
     * @param {string} scanId - The scanId obtained on startScanForDocumentType.
     * @param {MobbScanFaceValidationMode} faceValidationMode - The MobbScan's face validation mode.
     * @param {successCallback} successCallback - The success callback.
     * @param {errorCallback} errorCallback - The error callback.
     * @memberOf MobbScanAPI
     */
    validateFace: function (scanId, faceValidationMode, successCallback, errorCallback) {
        cordova.exec(successCallback, errorCallback, "MobbScan", "validateFace", [scanId, faceValidationMode.value]);
    },
    /**
     * Sets the face acquisitor callback.
     * @param {successCallback} successCallback - The success callback.
     * @memberOf MobbScanAPI
     */
    setFaceAcquisitorCallback: function (successCallback) {
        cordova.exec(successCallback, null, "MobbScan", "setFaceAcquisitorCallback", []);
    }
};

module.exports = MobbScanAPI;
