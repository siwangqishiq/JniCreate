//
// Created by panyi on 2016/11/24.
//
#include "createobj.h"
#include "parson.h"

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
        (JNIEnv *env, jclass clazz, jstring j_str) {
    jclass stucls = (*env)->FindClass(env, "com/xinlan/jnicreate/model/Student"); //或得Student类引用
    jmethodID constrocMID = (*env)->GetMethodID(env, stucls, "<init>", "()V");
    jobject stu_ojb = (*env)->NewObject(env, stucls, constrocMID);  //构造一个对象，调用该类的构造函数，并且传递参数

    char *c_str = NULL;
    c_str = (*env)->GetStringUTFChars(env, j_str, 0);

    __android_log_print(ANDROID_LOG_INFO, "panyi", "%s", c_str);

    JSON_Value *jsonValue = json_parse_string(c_str);

    if (jsonValue == NULL) {
        __android_log_print(ANDROID_LOG_INFO, "panyi", "is NULL");
    }

    const char *name = json_object_get_string(json_object(jsonValue), "name");

    jmethodID setNameMethId = (*env)->GetMethodID(env, stucls, "setName", "(Ljava/lang/String;)V");

    (*env)->CallVoidMethod(env, stu_ojb, setNameMethId, (*env)->NewStringUTF(env,name));

    __android_log_print(ANDROID_LOG_INFO, "panyi", "setName complete");

    (*env)->ReleaseStringUTFChars(env, j_str, c_str);

    json_value_free(jsonValue);

    return stu_ojb;
}

