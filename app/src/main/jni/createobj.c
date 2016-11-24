//
// Created by panyi on 2016/11/24.
//
#include "createobj.h"
#include "json.h"

JNIEXPORT jobject JNICALL Java_com_xinlan_jnicreate_NativeLib_createStudent
        (JNIEnv *env, jclass clazz, jstring name, jint age, jchar sex) {
    jclass stucls = (*env)->FindClass(env, "com/xinlan/jnicreate/model/Student"); //或得Student类引用

    jmethodID constrocMID = (*env)->GetMethodID(env, stucls, "<init>", "()V");

    jobject stu_ojb = (*env)->NewObject(env, stucls, constrocMID);  //构造一个对象，调用该类的构造函数，并且传递参数

    jmethodID setNameMethId = (*env)->GetMethodID(env, stucls, "setName", "(Ljava/lang/String;)V");

    (*env)->CallVoidMethod(env, stu_ojb, setNameMethId, name);

    return stu_ojb;
}



JNIEXPORT jobject JNICALL Java_com_xinlan_jnicreate_NativeLib_parseJSON
        (JNIEnv *env, jclass clazz, jstring src)
{
    jclass stucls = (*env)->FindClass(env, "com/xinlan/jnicreate/model/Student"); //或得Student类引用
    jmethodID constrocMID = (*env)->GetMethodID(env, stucls, "<init>", "()V");
    jobject stu_ojb = (*env)->NewObject(env, stucls, constrocMID);  //构造一个对象，调用该类的构造函数，并且传递参数



    return stu_ojb;
}

