package com.xinlan.jnicreate;

import com.xinlan.jnicreate.model.Student;

/**
 * Created by panyi on 2016/11/24.
 */

public class NativeLib {
    static {
        System.loadLibrary("createobj");
    }

    public native static Student createStudent(String name, int age, char sex);

    
}//end class
