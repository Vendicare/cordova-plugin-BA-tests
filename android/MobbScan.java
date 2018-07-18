package com.mobbeel.mobbscan;

import android.Manifest;
import android.app.Activity;
import android.content.ActivityNotFoundException;
import android.content.ComponentName;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.util.Base64;
import android.util.Log;

import com.google.gson.Gson;
import com.mobbeel.mobbscan.api.MobbScanAPI;
import com.mobbeel.mobbscan.api.MobbScanAPI.MobbScanAPIMode;
import com.mobbeel.mobbscan.api.MobbScanAPIError;
import com.mobbeel.mobbscan.api.MobbScanAPIErrorCode;
import com.mobbeel.mobbscan.api.MobbScanDocumentSide;
import com.mobbeel.mobbscan.api.MobbScanDocumentType;
import com.mobbeel.mobbscan.api.MobbScanOperationMode;
import com.mobbeel.mobbscan.api.MobbScanValidationState;
import com.mobbeel.mobbscan.api.face.MobbScanFaceValidationMode;
import com.mobbeel.mobbscan.api.face.listener.FaceAcquisitorListener;
import com.mobbeel.mobbscan.api.listener.IDDocumentScanListener;
import com.mobbeel.mobbscan.api.listener.LicenseStatusListener;
import com.mobbeel.mobbscan.api.listener.MobbScanVerificationProcessResultListener;
import com.mobbeel.mobbscan.api.listener.ScanStartListener;
import com.mobbeel.mobbscan.api.listener.ValidationCheckListener;
import com.mobbeel.mobbscan.api.result.MobbScanFaceAcquisitorData;
import com.mobbeel.mobbscan.api.result.MobbScanFaceAcquisitorResult;
import com.mobbeel.mobbscan.api.result.MobbScanLicenseResult;
import com.mobbeel.mobbscan.api.result.MobbScanScanResult;
import com.mobbeel.mobbscan.api.result.MobbScanScanResultData;
import com.mobbeel.mobbscan.api.result.MobbScanStartScanResult;
import com.mobbeel.mobbscan.api.result.MobbScanValidationResultData;
import com.mobbeel.mobbscan.api.result.MobbScanVerificationProcessResult;
import com.mobbeel.mobbscan.api.result.MobbScanVerificationProcessResultData;
import com.mobbeel.mobbscan.document.IDDocument;
import com.mobbeel.mobbscan.utils.DetectedImage;
import com.mobbeel.mobbscan.utils.MobbScanCallbackContext;
import com.mobbeel.mobbscan.video.MobbScanVideoAPI;
import com.mobbeel.mobbscan.video.result.MobbScanVideoResult;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaInterface;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CordovaWebView;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.ByteArrayOutputStream;
import java.lang.reflect.Field;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

import static android.content.pm.ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE;

public class MobbScan extends CordovaPlugin implements IDDocumentScanListener, MobbScanVerificationProcessResultListener {
    public static final int DETECT_DOCUMENT_ACTIVITY_REQUEST_CODE = 0;
    public static final int VIDEO_ACTIVITY_REQUEST_CODE = 1;
    public static final String SCAN_ID_KEY = "SCAN_ID_KEY";
    public static final String DOCUMENT_SIDE_KEY = "DOCUMENT_SIDE";
    public static final String VIDEO_RESULT_KEY = "VIDEO_RESULT_KEY";
    public static final String VIDEO_RESULT_FINISHED_BY_CLIENT_KEY = "VIDEO_RESULT_FINISHED_BY_CLIENT_KEY";
    public static final String VIDEO_RESULT_ERROR_API_KEY = "VIDEO_RESULT_ERROR_API_KEY";
    public static final String FACE_ACQUIRED_KEY = "faces";

    private Activity cordovaActivity;
    private MobbScanCallbackContext callbackContext;
    private MobbScanCallbackContext scanDocumentImageCallbackContext;
    private MobbScanCallbackContext scanDocumentDataCallbackContext;
    private MobbScanCallbackContext validateFaceAcquisitorListenerCallbackContext;    

    private static final String DETECTION_RESULT_DOCUMENT_SIDE_KEY = "documentSide";
    private static final String DETECTION_RESULT_IMAGE_KEY = "image";
    private static final int PERMISSIONS = 0;
    private static final String DEFAULT_DOCUMENT_DETECTION_INTERFACE_CLASS_NAME = "com.mobbeel.mobbscan.MobbScanDocumentDetectionInterface";
    private static final String DEFAULT_VIDEO_INTERFACE_CLASS_NAME = "com.mobbeel.mobbscan.MobbScanVideoInterface";
    private static final String LICENSE_DATE_FORMAT = "yyyy-MM-dd";
    private static final String LOG_TAG = "[MobbScanCordova]";

    private String scanId = "";
    private MobbScanAPI mobbScanAPI;
    private MobbScanVideoAPI videoAPI;
    private String documentDetectionInterfaceName = "";
    private String documentOtherDetectionInterfaceName = "";
    private String videoInterfaceName = "";
    private MobbScanDocumentType documentType;
    private int previousOrientation = SCREEN_ORIENTATION_LANDSCAPE;

    // region Plugin management

    @Override
    public void initialize(CordovaInterface cordova, CordovaWebView webView) {
        logCurrentMethod(new Object(){});
        callbackContext = new MobbScanCallbackContext();
        scanDocumentImageCallbackContext = new MobbScanCallbackContext();
        scanDocumentDataCallbackContext = new MobbScanCallbackContext();
        validateFaceAcquisitorListenerCallbackContext = new MobbScanCallbackContext();
        super.initialize(cordova, webView);
        mobbScanAPI = MobbScanAPI.getInstance();
        videoAPI = MobbScanVideoAPI.getInstance();
        cordovaActivity = cordova.getActivity();
    }

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext withCallbackContext) throws JSONException {
        switch (action) {
            case "initAPIWithLicense":
                callbackContext.setCallbackContext(withCallbackContext);
                initAPIWithLicense(args.getString(0));
                return true;
            case "setAPIMode":
                callbackContext.setCallbackContext(withCallbackContext);
                setAPIMode(args.getString(0));
                return true;
            case "setBaseURL":
                callbackContext.setCallbackContext(withCallbackContext);
                setBaseURL(args.getString(0));
                return true;
            case "startScanForDocumentType":
                callbackContext.setCallbackContext(withCallbackContext);
                startScanForDocumentType(args.getString(0), args.getString(1));
                return true;
            case "scanDocumentForSide":
                callbackContext.setCallbackContext(withCallbackContext);
                scanDocumentForSide(args.getString(0), args.getString(1));
                return true;
            case "setScanDocumentImageCallback":
                scanDocumentImageCallbackContext.keepCallback();
                setScanDocumentImageCallback(withCallbackContext);
                return true;
            case "setScanDocumentDataCallback":
                scanDocumentDataCallbackContext.keepCallback();
                setScanDocumentDataCallback(withCallbackContext);
                return true;
            case "initVideo":
                callbackContext.setCallbackContext(withCallbackContext);
                initVideo();
                return true;
            case "setVideoBaseURL":
                callbackContext.setCallbackContext(withCallbackContext);
                setVideoBaseURL(args.getString(0));
                return true;
            case "videoStart":
                callbackContext.setCallbackContext(withCallbackContext);
                videoStart(args.getString(0));
                return true;
            case "checkVerificationProcessResult":
                callbackContext.setCallbackContext(withCallbackContext);
                checkVerificationProcessResult(args.getString(0));
                return true;
            case "setDocumentDetectionInterface":
                callbackContext.setCallbackContext(withCallbackContext);
                setDocumentDetectionInterface(args.getString(0));
                return true;
            case "setOtherDocumentDetectionInterface":
                callbackContext.setCallbackContext(withCallbackContext);
                setOtherDocumentDetectionInterface(args.getString(0));
                return true;
            case "setVideoInterface":
                callbackContext.setCallbackContext(withCallbackContext);
                setVideoInterface(args.getString(0));
                return true;
            case "validateFace":
                callbackContext.setCallbackContext(withCallbackContext);
                validateFace(args.getString(0), args.getString(1));
                return true;
            case "setFaceAcquisitorCallback":
                validateFaceAcquisitorListenerCallbackContext.keepCallback();
                setFaceAcquisitorCallback(withCallbackContext);
                return true;
        }
        return false;
    }

    private void configureOrientation() {
        previousOrientation = cordovaActivity.getRequestedOrientation();
        cordovaActivity.setRequestedOrientation(SCREEN_ORIENTATION_LANDSCAPE);
    }

    // endregion

    // region MobbScanAPI methods

    private void initAPIWithLicense(final String withLicense) {
        logCurrentMethod(new Object(){});
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                mobbScanAPI.initAPI(withLicense, cordovaActivity, new LicenseStatusListener() {
                    @Override
                    public void onLicenseStatusChecked(MobbScanLicenseResult licenseResult, Date licenseValidTo) {
                        initAPIWithLicenseResult(licenseResult, licenseValidTo);
                    }
                });
                // TODO This should be exposed as part as the Cordova API
                mobbScanAPI.configurePDF417DetectionStep(true, 15);
            }
        });
    }

    private void setBaseURL(final String withBaseURL) {
        logCurrentMethod(new Object(){});
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                mobbScanAPI.setBaseUrl(withBaseURL);
                setBaseURLResult(withBaseURL);
            }
        });
    }

    private void setAPIMode(final String withApiMode) {
        logCurrentMethod(new Object(){});
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                MobbScanAPIMode apiMode = MobbScanAPIMode.valueOf(withApiMode);
                mobbScanAPI.setApiMode(apiMode);
                setAPIModeResult(apiMode);
            }
        });
    }

    private void setDocumentDetectionInterface(final String withDocumentDetectionInterfaceName) {
        logCurrentMethod(new Object(){});
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                documentDetectionInterfaceName = withDocumentDetectionInterfaceName;
                setDocumentDetectionInterfaceResult(documentDetectionInterfaceName);
            }
        });
    }

    private void setOtherDocumentDetectionInterface(final String withDocumentDetectionInterfaceName) {
        logCurrentMethod(new Object(){});
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                documentOtherDetectionInterfaceName = withDocumentDetectionInterfaceName;
                setOtherDocumentDetectionInterfaceResult(documentOtherDetectionInterfaceName);
            }
        });
    }


    private void startScanForDocumentType(final String withDocumentType, final String withOperationMode) {
        logCurrentMethod(new Object(){});
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                askForPermissions();
                documentType = MobbScanDocumentType.getMobbScanDocumentType(withDocumentType);
                Log.d(LOG_TAG, "- MobbScanDocumentType: " + documentType.toString());
                MobbScanOperationMode operationMode = MobbScanOperationMode.valueOf(withOperationMode);
                Log.d(LOG_TAG, "- MobbScanOperationMode: " + operationMode.toString());
                mobbScanAPI.startScan(documentType, operationMode,
                        new ScanStartListener() {
                            @Override
                            public void onScanStarted(MobbScanStartScanResult result, String scanId, MobbScanAPIError mobbScanAPIError) {
                                startScanForDocumentTypeResult(result, scanId, mobbScanAPIError);
                            }
                        });
            }
        });
    }

    private void setScanDocumentImageCallback(final CallbackContext withCallbackContext) {
        logCurrentMethod(new Object(){});
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                scanDocumentImageCallbackContext.setCallbackContext(withCallbackContext);
            }
        });
    }

    private void setScanDocumentDataCallback(final CallbackContext withCallbackContext) {
        logCurrentMethod(new Object(){});
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                scanDocumentDataCallbackContext.setCallbackContext(withCallbackContext);
            }
        });
    }

    private void scanDocumentForSide(final String withDocumentSide, final String withScanId) {
        logCurrentMethod(new Object(){});
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                if (!mobbScanAPI.isApiInitializationDone()) {
                    MobbScanAPIError error = new MobbScanAPIError(MobbScanAPIErrorCode.API_NOT_INITIALIZED_ERROR);
                    callbackContext.sendErrorMessage(error.toString());
                } else if ((withScanId == null) || (withScanId.equals(""))) {
                    MobbScanAPIError error = new MobbScanAPIError(MobbScanAPIErrorCode.WRONG_PARAMETERS_ERROR);
                    callbackContext.sendErrorMessage(error.toString());
                } else {
                    loadDocumentDetectionInterface(withDocumentSide, withScanId);
                }
            }
        });
    }

    private void loadDocumentDetectionInterface(String withDocumentSide, String withScanId) {
        configureOrientation();
        scanId = withScanId;

        String packageName = cordova.getActivity().getPackageName();
        String className = packageName + "." + documentDetectionInterfaceName;
        if(documentType == MobbScanDocumentType.OTHIDCard){
            className = packageName + "." + documentOtherDetectionInterfaceName;
        }
        try {
            Class.forName(className);
        } catch (ClassNotFoundException e) {
            className = DEFAULT_DOCUMENT_DETECTION_INTERFACE_CLASS_NAME;
        }
        ComponentName componentName = new ComponentName(packageName, className);

        MobbScanDocumentSide documentSide = MobbScanDocumentSide.valueOf(withDocumentSide);

        final Intent documentDetectionIntent = new Intent();
        documentDetectionIntent.putExtra(DOCUMENT_SIDE_KEY, documentSide);
        documentDetectionIntent.setComponent(componentName);

        cordova.setActivityResultCallback(this);

        Log.d(LOG_TAG, "- MobbScanDocumentSide: " + withDocumentSide);
        Log.d(LOG_TAG, "- scanId: " + scanId);
        Log.d(LOG_TAG, "- DocumentDetectionInterface: " + className);

        try {
            cordova.getActivity().runOnUiThread(new Runnable() {
                public void run() {
                    cordovaActivity.startActivityForResult(documentDetectionIntent, DETECT_DOCUMENT_ACTIVITY_REQUEST_CODE);
                }
            });
        } catch (ActivityNotFoundException e) {
            callbackContext.sendErrorMessage("Document detection interface " + className + " does not exist.");
        }
    }

    private void checkVerificationProcessResult(final String withScanId) {
        logCurrentMethod(new Object(){});
        final MobbScanVerificationProcessResultListener mobbScanVerificationProcessResultListener = this;
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                mobbScanAPI.checkVerificationProcessResult(withScanId, mobbScanVerificationProcessResultListener);
            }
        });
    }

    // endregion

    // region MobbScanVideoAPI methods

    private void initVideo() {
        logCurrentMethod(new Object(){});
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                videoAPI.initAPI(cordovaActivity);
                initVideoResult();
            }
        });
    }

    private void setVideoBaseURL(final String withUrl) {
        logCurrentMethod(new Object(){});
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                videoAPI.setBaseURL(withUrl);
                setVideoBaseURLResult(withUrl);
            }
        });
    }

    private void setVideoInterface(final String withVideoInterfaceName) {
        logCurrentMethod(new Object(){});
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                videoInterfaceName = withVideoInterfaceName;
                setVideoInterfaceResult(withVideoInterfaceName);
            }
        });
    }

    private void videoStart(final String withScanId) {
        logCurrentMethod(new Object(){});
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                askForPermissions();
                Log.d("videoStart", "VIDEO_SCAN_ID: " + withScanId);
                if (!mobbScanAPI.isApiInitializationDone() || !videoAPI.isApiInitializationDone()) {
                    MobbScanAPIError error = new MobbScanAPIError(MobbScanAPIErrorCode.API_NOT_INITIALIZED_ERROR);
                    callbackContext.sendErrorMessage(error.toString());
                } else if ((withScanId == null) || (withScanId.equals(""))) {
                    MobbScanAPIError error = new MobbScanAPIError(MobbScanAPIErrorCode.WRONG_PARAMETERS_ERROR);
                    callbackContext.sendErrorMessage(error.toString());
                } else {
                    loadVideoInterface(withScanId);
                }
            }
        });
    }

    private void loadVideoInterface(String scanId) {
        String packageName = cordova.getActivity().getPackageName();
        String className = packageName + "." + videoInterfaceName;
        try {
            Class.forName(className);
        } catch( ClassNotFoundException e ) {
            className = DEFAULT_VIDEO_INTERFACE_CLASS_NAME;
        }
        ComponentName componentName = new ComponentName(packageName, className);

        final Intent videoIntent = new Intent();
        videoIntent.putExtra(SCAN_ID_KEY, scanId);
        videoIntent.setComponent(componentName);

        cordova.setActivityResultCallback (this);

        Log.d(LOG_TAG, "- DocumentDetectionInterface: " + className);

        try {
            cordova.getActivity().runOnUiThread(new Runnable() {
                public void run() {
                    cordovaActivity.startActivityForResult(videoIntent, VIDEO_ACTIVITY_REQUEST_CODE);
                }
            });
        } catch (ActivityNotFoundException e) {
            callbackContext.sendErrorMessage("Video interface " + className + " does not exist.");
        }
    }

    // endregion

    // regiong MobbScanAPI face validation methods

    private void validateFace(final String withScanId, final String withFaceValidationMode) {
        logCurrentMethod(new Object(){});
        scanId = withScanId;
        final MobbScanVerificationProcessResultListener mobbScanVerificationProcessResultListener = this;
        final MobbScanFaceValidationMode faceValidationMode = MobbScanFaceValidationMode.valueOf(withFaceValidationMode);
        cordova.getThreadPool().execute(new Runnable(){        
            @Override
            public void run() {
                // only configure FaceAcquisitorListener if the callback is set up from the JS layer
                mobbScanAPI.validateFace(withScanId, faceValidationMode, new FaceAcquisitorListener(){
                    @Override
                    public void onFaceAcquired(MobbScanFaceAcquisitorResult result, MobbScanFaceAcquisitorData data, MobbScanAPIError error) {
                        try {
                            if (result == MobbScanFaceAcquisitorResult.ERROR) {
                                Log.d(LOG_TAG, "- FaceAcquisitorListener: No face has been acquired");
                                JSONObject faceAcquisitorResponse = new JSONObject();
                                faceAcquisitorResponse.put("result", result.toString());
                                faceAcquisitorResponse.put("scanId", scanId);
                                JSONObject errorResponse = new JSONObject();
                                errorResponse.put("errorCode", error.getErrorCode());
                                if (error.getExtraInfo() != null) {
                                    errorResponse.put("errorDetails", error.getExtraInfo().get(MobbScanAPIError.ERROR_KEY));
                                }
                                faceAcquisitorResponse.put("error", errorResponse);
                                validateFaceAcquisitorListenerCallbackContext.sendErrorMessage(faceAcquisitorResponse);
                                return;
                            }
                            if (data.getFaces() != null && !data.getFaces().isEmpty()) {
                                Log.d(LOG_TAG, "- FaceAcquisitorListener: " + data.getFaces().size() + " face(s) have been acquired");
                                // Build a JSON structure that mimics the "standard" MobbScan API response
                                JSONObject faceAcquisitorResponse = new JSONObject();
                                faceAcquisitorResponse.put("result", result.toString());
                                faceAcquisitorResponse.put("scanId", scanId);
                                JSONArray faceImages = new JSONArray();
                                /*
                                for (Bitmap faceImage : data.getFaces()) {
                                    faceImages.put(convertImageToBase64(faceImage));
                                }
                                */                                
                                faceImages.put(convertImageToBase64(data.getFaces().get(0)));
                                JSONObject resultData = new JSONObject();
                                resultData.put(FACE_ACQUIRED_KEY, faceImages);
                                faceAcquisitorResponse.put("resultData", resultData);
                                validateFaceAcquisitorListenerCallbackContext.sendOkMessage(faceAcquisitorResponse);
                            } else {
                                Log.w(LOG_TAG, "- FaceAcquisitorListener: The acquisitor returns OK but faces are missing. This should not happens");
                                JSONObject faceAcquisitorResponse = new JSONObject();
                                faceAcquisitorResponse.put("result", MobbScanFaceAcquisitorResult.ERROR.toString());
                                faceAcquisitorResponse.put("scanId", scanId);
                                JSONObject errorResponse = new JSONObject();
                                errorResponse.put("errorCode", MobbScanAPIErrorCode.CAPTURE_FACE_ERROR.toString());
                                faceAcquisitorResponse.put("error", errorResponse);
                                validateFaceAcquisitorListenerCallbackContext.sendErrorMessage(faceAcquisitorResponse);
                            }
                        } catch (JSONException e) {
                            e.printStackTrace();
                            String errorMessage = "{ \"result\": \"ERROR\", \"scanId\": \"" + scanId + "\", \"error\" : { \"errorCode\" : \"CAPTURE_FACE_ERROR\", \"errorDetails\" : \"" + e.getMessage() + "\" } }";
                            callbackContext.sendErrorMessage(errorMessage);
                        }
                    }
                }, new ValidationCheckListener() {
                    @Override
                    public void onValidationChecked(MobbScanValidationState result, MobbScanValidationResultData resultData, MobbScanAPIError error) {
                        sendValidationResult(result, resultData, error);
                    }
                });
            }
        });        

    }

    private void sendValidationResult(MobbScanValidationState result, MobbScanValidationResultData resultData, MobbScanAPIError mobbScanAPIError) {
        Log.d(LOG_TAG, "MobbScanValidateFaceResult: " + result.toString() + " for scanId:" + scanId);
        try {
            // Build a JSON structure that mimics the "standard" MobbScan API response
            JSONObject faceValidatedResponse = new JSONObject();
            faceValidatedResponse.put("result", result.toString());
            // Also append the scandId just for convenience
            faceValidatedResponse.put("scanId", scanId);
            if (mobbScanAPIError != null) {
                // result == MobbScanValidationState.NOT_CHECKED ??
                Log.w(LOG_TAG, "Error: " + mobbScanAPIError.toString());
                JSONObject errorResponse = new JSONObject();
                errorResponse.put("errorCode", mobbScanAPIError.getErrorCode().toString());
                if (mobbScanAPIError.getExtraInfo() != null) {
                    errorResponse.put("errorDetails", mobbScanAPIError.getExtraInfo().get(MobbScanAPIError.ERROR_KEY));
                }
                faceValidatedResponse.put("error", errorResponse);
                callbackContext.sendErrorMessage(faceValidatedResponse);
            } else {
                // result == MobbScanValidationState.VALID || result == MobbScanValidationState.NOT_VALID
                JSONObject resultDataResponse = new JSONObject();
                resultDataResponse.put("mobbScanValidationType", resultData.getMobbScanValidationType().toString());
                resultDataResponse.put("score", resultData.getScore());
                resultDataResponse.put("face", convertImageToBase64(resultData.getFaceBitmap()));
                faceValidatedResponse.put("resultData", resultDataResponse);
                callbackContext.sendOkMessage(faceValidatedResponse);
            }
        } catch (JSONException e) {
            Log.e(LOG_TAG, "Error processing json response: " + e.getMessage());
            String errorMessage = "{ \"result\": \"NOT_VALID\", \"scanId\": \"" + scanId + "\", \"error\" : { \"errorCode\" : \"UNEXPECTED_ERROR\", \"errorDetails\" : \"" + e.getMessage() + "\" } }";
            callbackContext.sendErrorMessage(errorMessage);
        }
    }
    
    private void setFaceAcquisitorCallback(final CallbackContext withCallbackContext) {
        logCurrentMethod(new Object(){});
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                validateFaceAcquisitorListenerCallbackContext.setCallbackContext(withCallbackContext);
            }
        });
    }

    // endregion

    // region MobbScanAPI methods result handling

    private void initAPIWithLicenseResult(MobbScanLicenseResult licenseResult, Date licenseValidTo) {
        Log.d(LOG_TAG, "- MobbScanLicenseResult: " + licenseResult.toString());
        Log.d(LOG_TAG, "- Date: " + dateAsStringWithFormat(licenseValidTo, LICENSE_DATE_FORMAT));
        if ((licenseResult == MobbScanLicenseResult.VALID) || (licenseResult == MobbScanLicenseResult.GRACE_PERIOD)) {
            String message = "License check result: " + licenseResult.toString();
            callbackContext.sendOkMessage(message);
        } else {
            String message = "License check result: " + licenseResult.toString();
            callbackContext.sendErrorMessage(message);
        }
    }

    private void setBaseURLResult(String baseURL) {
        Log.d(LOG_TAG, "- baseURL: " + baseURL);
        String message = "Base URL: " + baseURL;
        callbackContext.sendOkMessage(message);
    }

    private void setAPIModeResult(MobbScanAPIMode apiMode) {
        Log.d(LOG_TAG, "- MobbScanAPIMode: " + apiMode.toString());
        String message = "API mode: " + apiMode.toString();
        callbackContext.sendOkMessage(message);
    }

    private void setDocumentDetectionInterfaceResult(String documentDetectionInterfaceName) {
        Log.d(LOG_TAG, "- documentDetectionInterfaceName: " + documentDetectionInterfaceName);
        String packageName = cordova.getActivity().getPackageName();
        String className = packageName + "." + documentDetectionInterfaceName;
        String message = "Document detection interface name: " + className;
        callbackContext.sendOkMessage(message);
    }

    private void setOtherDocumentDetectionInterfaceResult(String documentOtherDetectionInterfaceName) {
        Log.d(LOG_TAG, "- documentDetectionInterfaceName: " + documentOtherDetectionInterfaceName);
        String packageName = cordova.getActivity().getPackageName();
        String className = packageName + "." + documentOtherDetectionInterfaceName;
        String message = "Document detection interface name: " + className;
        callbackContext.sendOkMessage(message);
    }

    private void startScanForDocumentTypeResult(MobbScanStartScanResult result, String scanId, MobbScanAPIError mobbScanAPIError) {
        Log.d(LOG_TAG, "- MobbScanStartScanResult: " + result.toString());
        Log.d(LOG_TAG, "- scanId: " + scanId);
        if (mobbScanAPIError != null) {
            Log.d(LOG_TAG, "- error: " + mobbScanAPIError.toString());
        }
        if (result == MobbScanStartScanResult.OK) {
            callbackContext.sendOkMessage(scanId);
        } else if (result == MobbScanStartScanResult.ERROR) {
            String message = "Start scan result: " + result.toString();
            callbackContext.sendErrorMessage(message);
        }
    }

    private void onDocumentDetected(MobbScanDocumentSide documentSide) {
        String documentSideStr = documentSide.toString().toUpperCase();
        String base64Image = convertImageToBase64(DetectedImage.getInstance().getImage());
        Log.d(LOG_TAG, "- MobbScanDetectionResultData.image: " + base64Image.substring(0, 19) + "...");
        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put(DETECTION_RESULT_DOCUMENT_SIDE_KEY, documentSideStr);
            jsonObject.put(DETECTION_RESULT_IMAGE_KEY, base64Image);
        } catch (JSONException e) {
            e.printStackTrace();
            String message = e.getLocalizedMessage();
            callbackContext.sendErrorMessage(message);
        }
        scanDocumentImageCallbackContext.sendOkMessage(jsonObject);

    }

    @Override
    public void onIDDocumentScanned(MobbScanScanResult mobbScanScanResult, MobbScanScanResultData mobbScanScanResultData, MobbScanAPIError mobbScanAPIError) {
        Log.d(LOG_TAG, "- MobbScanDetectionResult: " + mobbScanScanResult.toString());
        if (mobbScanScanResult != MobbScanScanResult.ERROR) {
            JSONObject jsonObject = getJsonObjectRepresentation(mobbScanScanResultData.getIdDocument());
            Log.d(LOG_TAG, "- MobbScanScanResultData.idDocument: " + jsonObject);
            scanDocumentDataCallbackContext.sendOkMessage(jsonObject);

            String message = "Scan document for side result: " + mobbScanScanResult.toString();
            callbackContext.sendOkMessage(message);
        } else {
            String message = "Scan document for side result: " + mobbScanScanResult.toString();
            callbackContext.sendErrorMessage(message);
        }
    }

    @Override
    public void onVerificationProcessFinished(MobbScanVerificationProcessResult mobbScanVerificationProcessResult, MobbScanVerificationProcessResultData mobbScanVerificationProcessResultData, MobbScanAPIError mobbScanAPIError) {
        Log.d(LOG_TAG, "- MobbScanVerificationProcessResult: " + mobbScanVerificationProcessResult.toString());
        if (mobbScanVerificationProcessResult != MobbScanVerificationProcessResult.ERROR) {
            String message = mobbScanVerificationProcessResult.toString();
            callbackContext.sendOkMessage(message);
        } else {
            Log.d(LOG_TAG, "- error: " + mobbScanAPIError.toString());
            String message = mobbScanAPIError.toString();
            callbackContext.sendErrorMessage(message);
        }
    }

    // endregion

    // region MobbScanVideoAPI methods result handling

    private void initVideoResult() {
        String message = "Video API initialized";
        callbackContext.sendOkMessage(message);
    }

    private void setVideoBaseURLResult(String baseURL) {
        Log.d(LOG_TAG, "- baseURL: " + baseURL);
        String message = "Base URL: " + baseURL;
        callbackContext.sendOkMessage(message);
    }

    private void setVideoInterfaceResult(String videoInterfaceName) {
        Log.d(LOG_TAG, "- videoInterfaceName: " + videoInterfaceName);
        String packageName = cordova.getActivity().getPackageName();
        String className = packageName + "." + videoInterfaceName;
        String message = "Video interface name: " + className;
        callbackContext.sendOkMessage(message);
    }

    // endregion

    // region Activity management

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (requestCode == DETECT_DOCUMENT_ACTIVITY_REQUEST_CODE) {
            cordovaActivity.setRequestedOrientation(previousOrientation);
            if (data != null) {
                MobbScanDocumentSide documentSide = (MobbScanDocumentSide) data.getSerializableExtra(DOCUMENT_SIDE_KEY);
                mobbScanAPI.scanDocument(documentSide, scanId, DetectedImage.getInstance().getImage(), this);
                onDocumentDetected(documentSide);
            }
        } else if(requestCode == VIDEO_ACTIVITY_REQUEST_CODE) {
            if (data != null) {
                MobbScanVideoResult mobbScanVideoResult = (MobbScanVideoResult) data.getSerializableExtra(VIDEO_RESULT_KEY);
                if (mobbScanVideoResult == MobbScanVideoResult.FINISHED) {
                    String message = (String) data.getSerializableExtra(VIDEO_RESULT_FINISHED_BY_CLIENT_KEY);
                    Log.d(LOG_TAG, "- MobbScanVideoResult: " + mobbScanVideoResult.toString());
                    Log.d(LOG_TAG, "- MobbScanVideoResultData.finishedByClient: " + message);
                    callbackContext.sendOkMessage(message);
                } else if (mobbScanVideoResult == MobbScanVideoResult.ERROR) {
                    MobbScanAPIError mobbScanAPIError = (MobbScanAPIError) data.getSerializableExtra(VIDEO_RESULT_ERROR_API_KEY);
                    Log.d(LOG_TAG, "- error: " + mobbScanAPIError.toString());
                    String message = mobbScanAPIError.toString();
                    callbackContext.sendErrorMessage(message);
                }
            }
        }
    }

    // endregion

    // region Helper methods

    private void askForPermissions() {
        if (!checkCameraPermission()) {
            ActivityCompat.requestPermissions(cordovaActivity,
                    new String[]{Manifest.permission.CAMERA, Manifest.permission.RECORD_AUDIO},
                    PERMISSIONS
            );
        }
    }

    private boolean checkCameraPermission() {
        return ContextCompat.checkSelfPermission(cordovaActivity, Manifest.permission.CAMERA) == PackageManager.PERMISSION_GRANTED &&
                ContextCompat.checkSelfPermission(cordovaActivity, Manifest.permission.RECORD_AUDIO) == PackageManager.PERMISSION_GRANTED;
    }

    private String convertImageToBase64(Bitmap image) {
        ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
        image.compress(Bitmap.CompressFormat.JPEG, 100, byteArrayOutputStream);
        byte[] byteArray = byteArrayOutputStream.toByteArray();
        return Base64.encodeToString(byteArray, Base64.DEFAULT);
    }

    private JSONObject getJsonObjectRepresentation(IDDocument idDocument) {
        Gson gson = new Gson();
        JSONObject jsonObject = null;
        try {
            jsonObject = new JSONObject(gson.toJson(idDocument));
        } catch (JSONException e) {
            Log.e(LOG_TAG, "- error marshalling json object: " + e.getMessage());                        
        }
        return jsonObject;        
    }

    private Map<String, String> mapRepresentation(IDDocument idDocument, Class idDocumentClass) {
        Map<String, String> map = new HashMap<>();
        Field[] fields = idDocumentClass.getDeclaredFields();

        for (Field field : fields) {
            try {
                field.setAccessible(true);
                String fieldName = field.getName();
                Object fieldFromObject = field.get(idDocument);
                if (fieldFromObject != null) {
                    String fieldValue = fieldFromObject.toString();
                    map.put(fieldName, fieldValue);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return map;
    }

    private String dateAsStringWithFormat(Date date, String dateFormat) {
        String dateAsString = "";
        try {
            SimpleDateFormat simpleDateFormat = new SimpleDateFormat(dateFormat, Locale.getDefault());
            dateAsString = simpleDateFormat.format(date);
        } catch (Exception exception) {
            Log.d("", exception.getLocalizedMessage());
        }
        return dateAsString;
    }

    private void logCurrentMethod(Object object) {
        Log.d(LOG_TAG, object.getClass().getEnclosingMethod().getName());
    }

    // endregion
}
