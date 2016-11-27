package com.xinlan.jnicreate;

import com.xinlan.jnicreate.model.Contact;
import com.xinlan.jnicreate.model.Student;

import java.util.ArrayList;

/**
 * Created by panyi on 2016/11/24.
 */

public class NativeLib {
    static {
        System.loadLibrary("createobj");
    }

    public native static Student createStudent(String name, int age, char sex);


    public native static Student parseJSON(String src);

    public native static ArrayList<Contact> parseList(final String src);

}//end class
