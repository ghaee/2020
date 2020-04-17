package com.example.ssadola;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Adapter;
import android.widget.ListView;
import android.widget.SimpleAdapter;

import java.util.ArrayList;
import java.util.HashMap;

public class ResultActivity extends AppCompatActivity {
    private ArrayList<HashMap<String,String>> Data = new ArrayList<HashMap<String,String>>();
    private HashMap<String,String> data1 = new HashMap<>();
    private HashMap<String,String> data2 = new HashMap<>();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_result);

       ListView listView = findViewById(R.id.listView);
        data1.put("local","서울");
        data1.put("count","5개");
        Data.add(data1);
        data2.put("local","부산");
        data2.put("count","3개");
        Data.add(data2);

        SimpleAdapter adapter = new SimpleAdapter(this,Data,android.R.layout.simple_list_item_2,
                new String[]{"local","count"},new int[]{android.R.id.text1,android.R.id.text2});
        listView.setAdapter(adapter);
    }
}
