package com.xinlan.jnicreate;

import android.net.Uri;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONArray;
import com.xinlan.jnicreate.model.Contact;
import com.xinlan.jnicreate.model.MyList;
import com.xinlan.jnicreate.model.Student;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    private View mCreateBtn;
    private TextView mText;

    public static final String src = "{\"name\":\"maolilan毛利兰\"}";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mCreateBtn = findViewById(R.id.create);
        mText = (TextView) findViewById(R.id.stu);

        mCreateBtn.setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        //Student stu = NativeLib.createStudent("毛利兰", 21, 'm');
        //Student stu  = NativeLib.parseJSON(src);

        //mText.setText(stu.toString());
        new FasrJavaParse().execute(1);
    }


    private final class FasrJavaParse extends AsyncTask<Integer, Void, MyList> {
        private long time = 0;

        @Override
        protected MyList doInBackground(Integer... origin) {


            InputStream is = null;

            String src = null;
            try {
                is = MainActivity.this.getAssets().open("json2.txt");

                int BUFF_SIZE = 10 * 1024;
                byte[] buffer = new byte[BUFF_SIZE];
                StringBuffer sb = new StringBuffer();
                int readInt = 0;
                while ((readInt = is.read(buffer, 0, BUFF_SIZE)) != -1) {
                    sb.append(new String(buffer, 0, readInt));
                }//end while


                src = sb.toString();


            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    if (is != null)
                        is.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

            if (src != null) {
                long t1 = System.currentTimeMillis();
                //MyList list = JSON.parseObject(src, MyList.class);
                //MyList list = parseNormal(src);
                MyList list = nativeList(src);
                long t2 = System.currentTimeMillis();
                time = t2 - t1;

                return list;
            }

            return null;
        }

        @Override
        protected void onPostExecute(MyList myList) {
            super.onPostExecute(myList);

            mText.setText("解析json对象" + myList.getList().size() + "\n 耗时 " +time+"\n"+
            myList.getList().get(0).toString());
        }
    }//end inner class

    private MyList nativeList(final String src) {
        MyList list = new MyList();
        ArrayList<Contact> contacts = NativeLib.parseList(src);
        list.setList(contacts);
        return list;
    }

    private MyList parseNormal(final String src) {
        MyList list = new MyList();
        List<Contact> conList = new ArrayList<Contact>();

        try {
            JSONObject obj = new JSONObject(src);
            org.json.JSONArray array = obj.getJSONArray("list");

            for (int i = 0; i < array.length(); i++) {
                Contact contact = new Contact();
                JSONObject jsonObject = array.getJSONObject(i);


                contact.setName(jsonObject.getString("name"));
                conList.add(contact);
            }//end for i

            list.setList(conList);
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return list;
    }
}//end class
