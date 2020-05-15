package com.example.ssadola;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.widget.Toast;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.lang.reflect.Type;
import java.net.URL;
import java.net.URLConnection;
import java.util.ArrayList;
import java.util.HashMap;

public class BookmarkActivity extends AppCompatActivity {
    ArrayList<HashMap<String, String>> arrayList;
    private RecyclerView rv;
    private LinearLayoutManager mLinearLayoutManager;
    String url = "http://pho901121.cafe24.com/login/db_get_notice_posts.php";
    StringBuilder sb;
    private static final String TAG_EMAIL="u_email";
    private static final String TAG_WRITER = "writer";
    private static final String TAG_TITLE = "title";
    private static final String TAG_DATE = "regist_day";
    private static final String TAG_CONTENT = "content";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_bookmark);

        arrayList = GetLoginData();

        if(arrayList == null){
            Toast.makeText(BookmarkActivity.this,"로그인 먼저 해주세요",Toast.LENGTH_LONG).show();
            Intent login = new Intent(BookmarkActivity.this,LoginActivity.class);
            startActivity(login);
            finish();
        }else{
            //db에서 즐찾한 여행지 정보들 가져와서 보여주기
            //유저정보를 인자로 넘겨주고 디비에서 셀렉해오기
            HashMap<String, String> LoginhashMap = arrayList.get(0);
            String mu_email = LoginhashMap.get(TAG_EMAIL);
            GetBookmark(mu_email,url);
        }
    }


    public ArrayList<HashMap<String, String>> GetLoginData() {
        SharedPreferences sharedPrefs = PreferenceManager.getDefaultSharedPreferences(getApplicationContext());
        Gson gson = new Gson();
        String json = sharedPrefs.getString("UserInfo", "EMPTY");
        if(json.equals("EMPTY")){
            //Toast.makeText(BookmarkActivity.this,"로그인 먼저 해주세요",Toast.LENGTH_LONG).show();
            return null;
        }
        Type type = new TypeToken<ArrayList<HashMap<String, String>>>() {
        }.getType();
        return gson.fromJson(json, type);
    }

    public void GetBookmark(String email, final String link){
        //유저정보 받아와서 확인해야함

        Thread mThread = new Thread() {
            public void run() {
                try {
                    URL url = new URL(link);
                    URLConnection conn = url.openConnection();

                    conn.setDoOutput(true);
                    

                    BufferedReader reader = new BufferedReader(new InputStreamReader(conn.getInputStream()));

                    sb = new StringBuilder();
                    String line = null;

                    // Read Server Response
                    while ((line = reader.readLine()) != null) {
                        sb.append(line);
                        break;
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        };

        mThread.start();
        try {
            mThread.join();
            Toast.makeText(BookmarkActivity.this,sb.toString(),Toast.LENGTH_LONG).show();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
