package com.xinlan.jnicreate.model;

import java.io.Serializable;

/**
 * Created by panyi on 16/11/26.
 */

public class Contact implements Serializable {
    private String name;
    private String fullName;
    private String remarkName;
    private String uid;
    private String email;
    private String status;
    private String department;
    private String mobile;
    private String age;
    private String sex;
    private String height;
    private String desc;
    private String hobby;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getFullName() {
        return fullName;
    }

    public void setFullName(String fullName) {
        this.fullName = fullName;
    }

    public String getRemarkName() {
        return remarkName;
    }

    public void setRemarkName(String remarkName) {
        this.remarkName = remarkName;
    }

    public String getUid() {
        return uid;
    }

    public void setUid(String uid) {
        this.uid = uid;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public String getMobile() {
        return mobile;
    }

    public void setMobile(String mobile) {
        this.mobile = mobile;
    }

    public String getAge() {
        return age;
    }

    public void setAge(String age) {
        this.age = age;
    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public String getHeight() {
        return height;
    }

    public void setHeight(String height) {
        this.height = height;
    }

    public String getDesc() {
        return desc;
    }

    public void setDesc(String desc) {
        this.desc = desc;
    }

    public String getHobby() {
        return hobby;
    }

    public void setHobby(String hobby) {
        this.hobby = hobby;
    }

    @Override
    public String toString() {
        return "Contact{" +
                "name='" + name + '\'' +
                ", fullName='" + fullName + '\'' +
                ", remarkName='" + remarkName + '\'' +
                ", uid='" + uid + '\'' +
                ", email='" + email + '\'' +
                ", status=" + status +
                ", department='" + department + '\'' +
                ", mobile='" + mobile + '\'' +
                ", age=" + age +
                ", sex='" + sex + '\'' +
                ", height=" + height +
                ", desc='" + desc + '\'' +
                ", hobby='" + hobby + '\'' +
                '}';
    }

}//end class
