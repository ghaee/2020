package com.example.ssadola;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import android.widget.Toast;


import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class RecyclerAdapter extends RecyclerView.Adapter<RecyclerAdapter.ViewHolder> {
    Context context;
    List<Item> items;
    ArrayList<HashMap<String,String>> bookmarkList; //공지사항 정보 담겨있음

    int item_layout;

    public RecyclerAdapter(Context context, List<Item> items, int item_layout) {
        this.context = context;
        this.items = items;
        this.item_layout = item_layout;
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_cardview,null);
        return new ViewHolder(v);
    }

    @Override
    public void onBindViewHolder(ViewHolder holder, int position) {
        final Item item = items.get(position);
        MyCardView cardView = holder.cardView;
        cardView.setData(item);

        cardView.setUserActionListener(new MyCardView.UserActionListener() {
            @Override
            public void onImageClicked() {
                Toast.makeText(context, "image", Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onTextClicked() {
                Toast.makeText(context, item.getTitle(), Toast.LENGTH_SHORT).show();
            }
        });
    }

    @Override
    public int getItemCount() {
        return this.items.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder {
        MyCardView cardView;

        public ViewHolder(View card) {
            super(card);
            cardView = (MyCardView)card;
        }
    }
}