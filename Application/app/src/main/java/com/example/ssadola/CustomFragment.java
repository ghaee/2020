package com.example.ssadola;

import android.graphics.Bitmap;
import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;

import yalantis.com.sidemenu.interfaces.ScreenShotable;
import yalantis.com.sidemenu.util.ViewAnimator;


public class CustomFragment extends Fragment implements ScreenShotable {
    private View containerView;
    protected ImageView mImageView;
    protected int res;
    private Bitmap bitmap;

    public static CustomFragment newInstance(int resId) {
        CustomFragment customfragment = new CustomFragment();
        Bundle bundle = new Bundle();
        bundle.putInt(Integer.class.getName(), resId);
        customfragment.setArguments(bundle);
        return customfragment;
    }

    @Override
    public void onViewCreated(View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        this.containerView = view.findViewById(R.id.container);
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        res = getArguments().getInt(Integer.class.getName());
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.fragment_custom, container, false);
        /*mImageView = (ImageView) rootView.findViewById(R.id.image_content);
        mImageView.setClickable(true);
        mImageView.setFocusable(true);
        mImageView.setImageResource(res);*/
        return rootView;
    }
    @Override
    public void takeScreenShot() {

    }

    @Override
    public Bitmap getBitmap() {
        return null;
    }
}
