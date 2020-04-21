package com.example.ssadola;

import androidx.appcompat.app.AppCompatActivity;

import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.widget.TextView;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.HashMap;

public class ProfileActivity extends AppCompatActivity {
    TextView tv_name,tv_email,tv_age,tv_sex;
    ArrayList<HashMap<String, String>> arrayList;
    private static String TAG_NAME = "u_name";
    private static String TAG_AGE = "age";
    private static String TAG_SEX = "sex";
    private static String TAG_EMAIL= "u_email";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_profile);
        tv_name = (TextView)findViewById(R.id.tv_name);
        tv_age = (TextView)findViewById(R.id.tv_age);
        tv_sex = (TextView)findViewById(R.id.tv_sex);
        tv_email = (TextView)findViewById(R.id.tv_email);

        arrayList = GetLoginData();
        HashMap<String,String> hashMap = arrayList.get(0);
        tv_name.setText(hashMap.get(TAG_NAME));
        tv_age.setText(hashMap.get(TAG_AGE));
        tv_sex.setText(hashMap.get(TAG_SEX));
        tv_email.setText(hashMap.get(TAG_EMAIL));
    }


    public ArrayList<HashMap<String, String>> GetLoginData() {
        SharedPreferences sharedPrefs = PreferenceManager.getDefaultSharedPreferences(getApplicationContext());
        Gson gson = new Gson();
        String json = sharedPrefs.getString("UserInfo", "EMPTY");
        Type type = new TypeToken<ArrayList<HashMap<String, String>>>() {
        }.getType();
        return gson.fromJson(json, type);
    }
}
