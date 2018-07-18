/*global cordova, module*/
/** @namespace MobbScanVideoAPI */
var MobbScanVideoAPI = {
    /**
     * Inits the mobbscan video api
     * @method init
     * @param {successCallback} successCallback - The success callback.
     * @param {errorCallback} errorCallback - The error callback. 
     * @memberOf MobbScanVideoAPI
     */
    init: function (successCallback, errorCallback) {
        cordova.exec(successCallback, errorCallback, "MobbScan", "initVideo", []);
    },
    /**
     * Sets the MobbScan agent's base url.
     * @method setBaseURL
     * @param {string} baseURL - Your MobbScan agent's server url.
     * @param {successCallback} successCallback - The success callback.
     * @param {errorCallback} errorCallback - The error callback. 
     * @memberOf MobbScanVideoAPI
     */
    setBaseURL: function (baseURL, successCallback, errorCallback) {
        cordova.exec(successCallback, errorCallback, "MobbScan", "setVideoBaseURL", [baseURL]);
    },
    /**
     * Sets the video interface, if you do not want to use the interface provided by the API.
     * @method setVideoInterface
     * @param {string} videoInterfaceName - Your custom interface class name. Example "com.yourEnterprise.packageName.CustomDetectionInterface".
     * @param {successCallback} successCallback - The success callback.
     * @param {errorCallback} errorCallback - The error callback. 
     * @memberOf MobbScanVideoAPI
     */
    setVideoInterface: function (videoInterfaceName, successCallback, errorCallback) {
        cordova.exec(successCallback, errorCallback, "MobbScan", "setVideoInterface", [videoInterfaceName]);
    },
    /**
     * Starts the video conference.
     * @method start
     * @param {string} scanId - The scanId obtained on startScanForDocumentType.
     * @param {successCallback} successCallback - The success callback.
     * @param {errorCallback} errorCallback - The error callback. 
     * @memberOf MobbScanVideoAPI
     */
    start: function (scanId, successCallback, errorCallback) {
        cordova.exec(successCallback, errorCallback, "MobbScan", "videoStart", [scanId]);
    }
};

module.exports = MobbScanVideoAPI;
