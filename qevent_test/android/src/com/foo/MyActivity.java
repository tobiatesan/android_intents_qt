package com.foo;

import android.app.Notification;
import android.content.Intent;

import org.qtproject.qt5.android.bindings.QtActivity;


class Bar
{
    public static native void openUri(String uri);
}

public class MyActivity extends QtActivity {
    public void onNewIntent(Intent i) {
        if (i.getAction() == Intent.ACTION_VIEW) {
            Bar.openUri(i.getData().toString());
        }
        super.onNewIntent(i);
    }
}
