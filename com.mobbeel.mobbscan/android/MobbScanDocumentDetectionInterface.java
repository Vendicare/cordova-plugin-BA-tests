package com.mobbeel.mobbscan;

import android.content.Intent;
import android.graphics.Color;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.GradientDrawable;
import android.graphics.drawable.LayerDrawable;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.constraint.ConstraintLayout;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

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
import com.mobbeel.mobbscan.utils.DetectedImage;

import com.mobbeel.mobbscan.R;

public class MobbScanDocumentDetectionInterface extends AppCompatActivity {
    private MobbScanDocumentDetectionTrack detectionTrack;
    private MobbScanDocumentSide documentSide;
    private TextView feedbackMessage;
    private ViewGroup cameraViewContainer;
    private ConstraintLayout borders;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        readExtras();
        configureViews();
        configureDetector();
        startDetection();
    }

    private void readExtras() {
        documentSide = (MobbScanDocumentSide) getIntent().getSerializableExtra(MobbScan.DOCUMENT_SIDE_KEY);
    }

    private void configureViews() {
        setContentView(R.layout.mobbscan_document_detection);
        cameraViewContainer = (ViewGroup) findViewById(R.id.cameraViewContainer);
        feedbackMessage = (TextView) findViewById(R.id.feedbackMessage);
        borders = (ConstraintLayout) findViewById(R.id.borders);
        borders.setVisibility(View.GONE);
        feedbackMessage.setVisibility(View.GONE);
    }

    private void configureDetector() {
        detectionTrack = new MobbScanDocumentDetectionTrack(cameraViewContainer);
        MobbScanAPI.getInstance().setDocumentDetectionTrack(detectionTrack);
        MobbScanAPI.getInstance().setIdDocumentDetectionFeedbackListener(getIdDocumentDetectionFeedbackListener());
    }
    private void startDetection() {
        cameraViewContainer.post(new Runnable() {
            @Override
            public void run() {
                MobbScanAPI.getInstance().detectDocument(documentSide, getScanListener());
                borders.setVisibility(View.VISIBLE);
                feedbackMessage.setVisibility(View.VISIBLE);
            }
        });
    }

    @NonNull
    private IDDocumentDetectionFeedbackListener getIdDocumentDetectionFeedbackListener() {
        return new IDDocumentDetectionFeedbackListener() {
            @Override
            public void onIDDocumentDetection(MobbScanDetectionFeedbackResult result, MobbScanDetectionFeedbackResultData resultData, MobbScanAPIError error) {
                processDetectionEvent(result);
            }
        };
    }

    private IDDocumentDetectionListener getScanListener() {
        return new IDDocumentDetectionListener() {
            @Override
            public void onIDDocumentDetected(MobbScanDetectionResult result, MobbScanDetectionResultData resultData, MobbScanAPIError error) {
                processScanEvent(resultData);
            }
        };
    }

    private void processDetectionEvent(MobbScanDetectionFeedbackResult result) {
        if (documentIsDetected(result)) {
            processDetectedEvent();
        } else if (documentIsNotDetected(result)) {
            processNotDetectedEvent();
        }
    }

    private void processScanEvent(MobbScanDetectionResultData resultData) {
        DetectedImage.getInstance().setImage(resultData.getImage());
        Intent resultIntent = new Intent();
        resultIntent.putExtra(MobbScan.DOCUMENT_SIDE_KEY, documentSide);
        setResult(MobbScan.DETECT_DOCUMENT_ACTIVITY_REQUEST_CODE, resultIntent);
        finish();
    }
    private boolean documentIsDetected(MobbScanDetectionFeedbackResult result) {
        return result == MobbScanDetectionFeedbackResult.DOCUMENT_DETECTED_HOLD_ON;
    }

    private boolean documentIsNotDetected(MobbScanDetectionFeedbackResult result) {
        return result == MobbScanDetectionFeedbackResult.DOCUMENT_NOT_DETECTED;
    }

    private void processDetectedEvent() {
        setBorderColor(ContextCompat.getColor(this, R.color.mobbscan_document_detected));
        feedbackMessage.setTextColor(Color.GREEN);
        feedbackMessage.setText(R.string.mobbscan_preparing_capture);
    }

    private void processNotDetectedEvent() {
        setBorderColor(ContextCompat.getColor(this, R.color.mobbscan_document_not_detected));
        feedbackMessage.setTextColor(Color.WHITE);
        updateFeedbackMessageForNotDetectedEvent();
    }

    private void updateFeedbackMessageForNotDetectedEvent() {
        if (documentSide == MobbScanDocumentSide.FRONT) {
            feedbackMessage.setText(R.string.mobbscan_searching_borders_front);
        } else if (documentSide == MobbScanDocumentSide.BACK) {
            feedbackMessage.setText(R.string.mobbscan_searching_borders_back);
        } else {
            feedbackMessage.setText(R.string.mobbscan_searching_borders);
        }
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

    private void setBorderColor(int color) {
        int borderStrokeWidth = (int) getResources().getDimension(R.dimen.mobbscan_border_stroke_width);
        int borderDashWidth = (int) getResources().getDimension(R.dimen.mobbscan_border_stroke_dash_width);
        int borderDashGap = (int) getResources().getDimension(R.dimen.mobbscan_border_stroke_dash_gap);
        int borderCornerStrokeWidth = (int) getResources().getDimension(R.dimen.mobbscan_border_corner_stroke_width);

        Drawable borderDrawable = ContextCompat.getDrawable(this, R.drawable.mobbscan_document_detection_border);
        LayerDrawable borderLayerDrawable = (LayerDrawable) borderDrawable;
        GradientDrawable borderGradientDrawable = (GradientDrawable) borderLayerDrawable.findDrawableByLayerId(R.id.border);
        borderGradientDrawable.setStroke(borderStrokeWidth, color, borderDashWidth, borderDashGap);
        ConstraintLayout constraintLayout = (ConstraintLayout) findViewById(R.id.borders);
        constraintLayout.setBackground(borderDrawable);

        setCornersColor(borderCornerStrokeWidth, color);
    }

    private void setCornersColor(int width, int color) {
        setTopStartCornerStroke(width, color);
        setTopEndCornerStroke(width, color);
        setBottomStartCornerStroke(width, color);
        setBottomEndCornerStroke(width, color);
    }

    private void setTopStartCornerStroke(int width, int color) {
        LayerDrawable topStartCornerLayerDrawable = (LayerDrawable) ContextCompat.getDrawable(this, R.drawable.mobbscan_document_detection_top_start_corner);
        GradientDrawable topStartCornerTopGradientDrawable = (GradientDrawable) topStartCornerLayerDrawable.findDrawableByLayerId(R.id.top_start_corner_top);
        topStartCornerTopGradientDrawable.setStroke(width, color);
        GradientDrawable topStartCornerStartGradientDrawable = (GradientDrawable) topStartCornerLayerDrawable.findDrawableByLayerId(R.id.top_start_corner_start);
        topStartCornerStartGradientDrawable.setStroke(width, color);
        ConstraintLayout constraintLayout = (ConstraintLayout) findViewById(R.id.topStartCorner);
        constraintLayout.setBackground(topStartCornerLayerDrawable);
    }

    private void setTopEndCornerStroke(int width, int color) {
        LayerDrawable topEndCornerLayerDrawable = (LayerDrawable) ContextCompat.getDrawable(this, R.drawable.mobbscan_document_detection_top_end_corner);
        GradientDrawable topEndCornerTopGradientDrawable = (GradientDrawable) topEndCornerLayerDrawable.findDrawableByLayerId(R.id.top_end_corner_top);
        topEndCornerTopGradientDrawable.setStroke(width, color);
        GradientDrawable topEndCornerEndGradientDrawable = (GradientDrawable) topEndCornerLayerDrawable.findDrawableByLayerId(R.id.top_end_corner_end);
        topEndCornerEndGradientDrawable.setStroke(width, color);
        ConstraintLayout constraintLayout = (ConstraintLayout) findViewById(R.id.topEndCorner);
        constraintLayout.setBackground(topEndCornerLayerDrawable);
    }

    private void setBottomStartCornerStroke(int width, int color) {
        LayerDrawable bottomStartCornerLayerDrawable = (LayerDrawable) ContextCompat.getDrawable(this, R.drawable.mobbscan_document_detection_bottom_start_corner);
        GradientDrawable bottomStartCornerBottomGradientDrawable = (GradientDrawable) bottomStartCornerLayerDrawable.findDrawableByLayerId(R.id.bottom_start_corner_bottom);
        bottomStartCornerBottomGradientDrawable.setStroke(width, color);
        GradientDrawable bottomStartCornerStartGradientDrawable = (GradientDrawable) bottomStartCornerLayerDrawable.findDrawableByLayerId(R.id.bottom_start_corner_start);
        bottomStartCornerStartGradientDrawable.setStroke(width, color);
        ConstraintLayout constraintLayout = (ConstraintLayout) findViewById(R.id.bottomStartCorner);
        constraintLayout.setBackground(bottomStartCornerLayerDrawable);
    }

    private void setBottomEndCornerStroke(int width, int color) {
        LayerDrawable bottomEndCornerLayerDrawable = (LayerDrawable) ContextCompat.getDrawable(this, R.drawable.mobbscan_document_detection_bottom_end_corner);
        GradientDrawable bottomEndCornerBottomGradientDrawable = (GradientDrawable) bottomEndCornerLayerDrawable.findDrawableByLayerId(R.id.bottom_end_corner_bottom);
        bottomEndCornerBottomGradientDrawable.setStroke(width, color);
        GradientDrawable bottomEndCornerEndGradientDrawable = (GradientDrawable) bottomEndCornerLayerDrawable.findDrawableByLayerId(R.id.bottom_end_corner_end);
        bottomEndCornerEndGradientDrawable.setStroke(width, color);
        ConstraintLayout constraintLayout = (ConstraintLayout) findViewById(R.id.bottomEndCorner);
        constraintLayout.setBackground(bottomEndCornerLayerDrawable);
    }
}
