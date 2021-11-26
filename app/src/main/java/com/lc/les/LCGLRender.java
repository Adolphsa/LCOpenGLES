package com.lc.les;

import android.content.Context;
import android.content.res.AssetManager;
import android.opengl.GLSurfaceView;

import java.util.PrimitiveIterator;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by lucas on 2021/11/22.
 */
public class LCGLRender implements GLSurfaceView.Renderer {

    private Context mGLContext;

    LCGLRender(Context context){
        mGLContext = context;
    }

    static {
        System.loadLibrary("LCOpenGLRender");
    }

    private native void ndkInit(AssetManager assetManager);
    private native void ndkPaintGL();
    private native void ndkResizeGL(int width, int height);

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        AssetManager assetManager = mGLContext.getAssets();
        ndkInit(assetManager);
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        ndkResizeGL(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        ndkPaintGL();
    }

}
