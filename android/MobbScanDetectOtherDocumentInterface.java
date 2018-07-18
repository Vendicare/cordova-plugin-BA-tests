package com.mobbeel.mobbscan.cordovaplugindemo;

import android.app.Activity;
import android.content.Intent;
import android.graphics.Bitmap;
import android.hardware.Camera;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageButton;

import com.mobbeel.camera.listeners.OnPictureTakenListener;
import com.mobbeel.mobbscan.MobbScan;
import com.mobbeel.mobbscan.api.MobbScanAPI;
import com.mobbeel.mobbscan.api.MobbScanAPIError;
import com.mobbeel.mobbscan.api.MobbScanDocumentSide;
import com.mobbeel.mobbscan.api.detection.MobbScanDocumentDetectionTrack;
import com.mobbeel.mobbscan.api.listener.IDDocumentDetectionFeedbackListener;
import com.mobbeel.mobbscan.api.listener.IDDocumentDetectionListener;
import com.mobbeel.mobbscan.api.result.MobbScanDetectionFeedbackResult;
import com.mobbeel.mobbscan.api.result.MobbScanDetectionFeedbackResultData;
import com.mobbeel.mobbscan.api.result.MobbScanDetectionResult;
import com.mobbeel.mobbscan.api.result.MobbScanDetectionResultData;
import com.mobbeel.mobbscan.api.ui.Constants;
import com.mobbeel.mobbscan.cordovaplugindemo.R;
import com.mobbeel.mobbscan.utils.DetectedImage;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;


/**
 * Created by dmvioque on 1/3/18.
 */

public class MobbScanDetectOtherDocumentInterface extends Activity {

    MobbScanDocumentDetectionTrack detectionTrack;
    private MobbScanDocumentSide documentSide;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.document_detection);
        readExtras();
        configureViews();
    }

    private void readExtras() {
        documentSide = (MobbScanDocumentSide) getIntent().getSerializableExtra(MobbScan.DOCUMENT_SIDE_KEY);
    }

    private void configureViews() {
        ViewGroup cameraViewContainer = (ViewGroup) findViewById(R.id.cameraViewContainer);
        ImageButton takePhoto = (ImageButton) findViewById(R.id.takePhoto);
        takePhoto.setOnClickListener(getOnclickListener());
        detectionTrack = new MobbScanDocumentDetectionTrack(cameraViewContainer);
        MobbScanAPI.getInstance().setDocumentDetectionTrack(detectionTrack);
        MobbScanAPI.getInstance().setIdDocumentDetectionFeedbackListener(getIdDocumentDetectionFeedbackListener());
        MobbScanAPI.getInstance().detectDocument(documentSide, getIdDocumentListener());
    }

    private IDDocumentDetectionListener getIdDocumentListener(){
        return new IDDocumentDetectionListener() {
            @Override
            public void onIDDocumentDetected(MobbScanDetectionResult mobbScanDetectionResult, MobbScanDetectionResultData mobbScanDetectionResultData, MobbScanAPIError mobbScanAPIError) {
                Log.d("MOBBSCANDOCUMENT", mobbScanDetectionResult.toString());
            }
        };
    }

    private View.OnClickListener getOnclickListener(){
        return new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                MobbScanAPI.getInstance().takePhoto(getOnPictureTakenListener());
            }
        };
    }

    private OnPictureTakenListener getOnPictureTakenListener(){
        return new OnPictureTakenListener() {
            @Override
            public void onPictureTaken(Bitmap picture, Camera camera) {
                MobbScanDetectionResultData resultData = new MobbScanDetectionResultData();
                resultData.setImage(picture);
                resultData.setDocumentSide(documentSide);
                processScanEvent(resultData);
            }
        };
    }

    private void processScanEvent(MobbScanDetectionResultData resultData) {
        DetectedImage.getInstance().setImage(resultData.getImage());
        Intent resultIntent = new Intent();
        resultIntent.putExtra(MobbScan.DOCUMENT_SIDE_KEY, documentSide);
        setResult(MobbScan.DETECT_DOCUMENT_ACTIVITY_REQUEST_CODE, resultIntent);
        finish();
    }

    @NonNull
    private IDDocumentDetectionFeedbackListener getIdDocumentDetectionFeedbackListener() {
        return new IDDocumentDetectionFeedbackListener() {
            @Override
            public void onIDDocumentDetection(MobbScanDetectionFeedbackResult result, MobbScanDetectionFeedbackResultData resultData, MobbScanAPIError error) {
                Log.d("MOBBSCANDOCUMENT", result.toString());
            }
        };
    }

    @Override
    protected void onPause() {
        super.onPause();
        if (detectionTrack != null) {
            detectionTrack.onPause();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (detectionTrack != null) {
            detectionTrack.onResume();
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        if (detectionTrack != null) {
            detectionTrack.onDestroy();
        }
    }
}
