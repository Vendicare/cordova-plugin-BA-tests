package com.mobbeel.mobbscan;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.media.AudioManager;
import android.os.Bundle;
import android.support.constraint.ConstraintLayout;
import android.view.View;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import com.mobbeel.mobbscan.api.MobbScanAPIError;
import com.mobbeel.mobbscan.video.MobbScanVideoAPI;
import com.mobbeel.mobbscan.video.MobbScanVideoView;
import com.mobbeel.mobbscan.video.result.MobbScanVideoListener;
import com.mobbeel.mobbscan.video.result.MobbScanVideoResult;
import com.mobbeel.mobbscan.video.result.MobbScanVideoResultData;

import com.mobbeel.mobbscan.R;

public class MobbScanVideoInterface extends Activity {
    private MobbScanVideoView localVideo;
    private MobbScanVideoView remoteVideo;
    private ConstraintLayout remoteVideoCover;

    private MobbScanVideoAPI videoAPI;
    private AudioManager audioManager;
    private HeadsetReceiver receiver;
    private TextView textLoading;
    private ProgressBar iconLoading;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        videoAPI = MobbScanVideoAPI.getInstance();
        configureAudio();
        setAPIVideoListener();
        setContentView(R.layout.mobbscan_video);
        initElements();
        setVideoApiContainers();
        startAPIVideo();
    }

    @Override
    protected void onDestroy() {
        this.unregisterReceiver(receiver);
        videoAPI.setListener(null);
        videoAPI.stop();
        super.onDestroy();
    }

    private void initElements(){
        Button closeButton = findViewById(R.id.videoCloseButton);
        closeButton.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                onCloseButtonClicked();
            }
        });

        textLoading =  (TextView)findViewById(R.id.textLoading);
        iconLoading =  (ProgressBar)findViewById(R.id.iconLoading);
        localVideo = findViewById(R.id.localVideoPlaceholder);
        remoteVideo = findViewById(R.id.remoteVideoPlaceholder);
        remoteVideoCover = findViewById(R.id.remoteVideoPlaceholderCover);
    }

    private void onCloseButtonClicked(){
        showConfirmationClosedDialog();
    }

    private void setVideoApiContainers(){
        videoAPI.setRemoteVideoContainer(remoteVideo);
        videoAPI.setLocalVideoContainer(localVideo);
    }

    private void startAPIVideo(){
        String scanId = getIntent().getStringExtra(MobbScan.SCAN_ID_KEY);
        videoAPI.start(scanId);
    }

    private void setAPIVideoListener() {
        videoAPI.setListener(new MobbScanVideoListener() {
            @Override
            public void onVideoEvent(MobbScanVideoResult mobbScanVideoResult, MobbScanVideoResultData mobbScanVideoResultData, MobbScanAPIError mobbScanAPIError) {
                handleVideoStatus(mobbScanVideoResult, mobbScanVideoResultData, mobbScanAPIError);
            }
        });
    }

    private void handleVideoStatus(MobbScanVideoResult mobbScanVideoResult, MobbScanVideoResultData mobbScanVideoResultData, MobbScanAPIError mobbScanAPIError) {
        if (mobbScanVideoResult == MobbScanVideoResult.WAITING) {
            iconLoading.setVisibility(View.VISIBLE);
            textLoading.setVisibility(View.VISIBLE);
            handleVideoStatusWaiting(mobbScanVideoResultData);
        } else if (mobbScanVideoResult == MobbScanVideoResult.ON_PROCESS) {
            iconLoading.setVisibility(View.GONE);
            textLoading.setVisibility(View.GONE);
            handleVideoStatusOnProcess();
        } else if (mobbScanVideoResult == MobbScanVideoResult.FINISHED) {
            iconLoading.setVisibility(View.GONE);
            textLoading.setVisibility(View.GONE);
            handleVideoStatusFinished(false);
        } else if (mobbScanVideoResult == MobbScanVideoResult.ERROR) {
            iconLoading.setVisibility(View.GONE);
            textLoading.setVisibility(View.GONE);
            handleVideoStatusError(mobbScanAPIError);
        }
    }

    private void handleVideoStatusWaiting(MobbScanVideoResultData mobbScanVideoResultData) {
        String resultAsString = MobbScanVideoResult.WAITING.toString();
        String message = resultAsString + ": " + mobbScanVideoResultData.getWaitTime();
        Toast.makeText(this, message, Toast.LENGTH_SHORT).show();
    }

    private void handleVideoStatusOnProcess() {
        String message = MobbScanVideoResult.ON_PROCESS.toString();
        Toast.makeText(this, message, Toast.LENGTH_SHORT).show();
        remoteVideoCover.setVisibility(View.GONE);
    }

    private void handleVideoStatusFinished(Boolean finishedByClient) {
        Intent resultIntent = new Intent();
        resultIntent.putExtra(MobbScan.VIDEO_RESULT_KEY, MobbScanVideoResult.FINISHED);
        resultIntent.putExtra(MobbScan.VIDEO_RESULT_FINISHED_BY_CLIENT_KEY, finishedByClient.toString());
        setResult(MobbScan.VIDEO_ACTIVITY_REQUEST_CODE, resultIntent);
        finish();
    }

    private void handleVideoStatusError(MobbScanAPIError mobbScanAPIError) {
        Intent resultIntent = new Intent();
        resultIntent.putExtra(MobbScan.VIDEO_RESULT_KEY, MobbScanVideoResult.ERROR);
        resultIntent.putExtra(MobbScan.VIDEO_RESULT_ERROR_API_KEY, mobbScanAPIError);
        setResult(MobbScan.VIDEO_ACTIVITY_REQUEST_CODE, resultIntent);
        finish();
    }

    private void configureAudio() {
        audioManager = (AudioManager) this.getSystemService(Context.AUDIO_SERVICE);
        IntentFilter receiverFilter = new IntentFilter(Intent.ACTION_HEADSET_PLUG);
        receiver = new HeadsetReceiver();
        this.registerReceiver(receiver, receiverFilter);
        audioManager.setSpeakerphoneOn(true);
    }

    private void showConfirmationClosedDialog(){
        AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(
                this);
        alertDialogBuilder.setTitle("Close ")
                .setMessage("¿Está seguro de que desea cerrar la videconferencia?")
                .setPositiveButton(android.R.string.yes, new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int which) {
                        handleVideoStatusFinished(true);
                    }
                })
                .setNegativeButton(android.R.string.no, new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int which) {
                        // do nothing
                    }
                })
                .setIcon(android.R.drawable.ic_dialog_alert)
                .show();
    }

    class HeadsetReceiver extends BroadcastReceiver {
        @Override
        public void onReceive(Context context, Intent intent) {
            int state = intent.getIntExtra("state", -1);
            if (state == 0) {
                audioManager.setSpeakerphoneOn(true);
            } else {
                audioManager.setSpeakerphoneOn(false);
            }
        }
    }
}
