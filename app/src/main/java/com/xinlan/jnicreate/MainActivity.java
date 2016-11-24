package com.xinlan.jnicreate;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.xinlan.jnicreate.model.Student;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    private View mCreateBtn;
    private TextView mText;

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
        Student stu = NativeLib.createStudent("毛利兰", 21, 'm');

        mText.setText(stu.toString());
    }
}//end class
