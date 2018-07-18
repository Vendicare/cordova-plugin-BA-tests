package com.mobbeel.mobbscan.utils;

import android.util.Log;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;
import org.json.JSONObject;

public class MobbScanCallbackContext {

    private boolean keepCallback = false;
    private CallbackContext callbackContext;
    private static final String LOG_TAG = "[MobbScanCordova]";

    public MobbScanCallbackContext(){

    }

    public void keepCallback() {
        this.keepCallback = true;
    }

    public void setCallbackContext(CallbackContext callbackContext) {
        this.callbackContext = callbackContext;
    }

    public void sendOkMessage(Object message) {
        sendMessage(message, PluginResult.Status.OK);
    }

    public void sendErrorMessage(Object message) {
        sendMessage(message, PluginResult.Status.ERROR);
    }

    private void sendMessage(Object message, PluginResult.Status status) {
        if (message instanceof JSONObject) {
            JSONObject jsonObject = (JSONObject) message;
            sendMessage(jsonObject, status);
        } else {
            String string = (String) message;
            sendMessage(string, status);
        }
    }

    private void sendMessage(JSONObject message, PluginResult.Status status) {
        PluginResult pluginResult = new PluginResult(status, message);
        pluginResult.setKeepCallback(this.keepCallback);
        if (this.callbackContext != null) {
            this.callbackContext.sendPluginResult(pluginResult);
        } else {
            Log.w(LOG_TAG, "No callback context available for this message. Status: " + status.toString() + ", message: " + message.toString());
        }
    }

    private void sendMessage(String message, PluginResult.Status status) {
        PluginResult pluginResult = new PluginResult(status, message);
        pluginResult.setKeepCallback(this.keepCallback);        
        if (this.callbackContext != null) {
            this.callbackContext.sendPluginResult(pluginResult);
        } else {
            Log.w(LOG_TAG, "No callback context available for this message. Status: " + status.toString() + ", message: " + message.toString());
        }
    }
}
