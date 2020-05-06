package com.example.ssadola;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class ImageStudioActivity extends AppCompatActivity {
    TextView test;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_image_studio);

        test = findViewById(R.id.tv_test);
        Intent intent = getIntent();
        Bundle bundle = intent.getExtras();
        String plc_nm = bundle.getString("plc_nm");
        test.setText(plc_nm);
    }
}
