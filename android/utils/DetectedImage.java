package com.mobbeel.mobbscan.utils;

import android.graphics.Bitmap;

public class DetectedImage {
    private Bitmap image;

    public void setImage(Bitmap image) {
        this.image = image;
    }

    public Bitmap getImage() {
        return image;
    }

    private static DetectedImage ourInstance = new DetectedImage();

    public static DetectedImage getInstance() {
        return ourInstance;
    }

    private DetectedImage() {
    }
}
