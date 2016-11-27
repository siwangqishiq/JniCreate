package com.xinlan.jnicreate.model;

import java.io.Serializable;
import java.util.List;

/**
 * Created by panyi on 16/11/26.
 */

public class MyList implements Serializable {
    public List<Contact> getList() {
        return list;
    }

    public void setList(List<Contact> list) {
        this.list = list;
    }

    private List<Contact> list;
}
