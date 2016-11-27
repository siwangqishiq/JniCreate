//
// Created by panyi on 2016/11/24.
//
#include "createobj.h"
#include "parson.h"

void setContactFieldValue(JNIEnv *env,jobject contact,const char *key_value,
                              JSON_Object *json_obj,jfieldID name_fid){

    char * c_value_str =  json_object_get_string(json_obj,key_value);

    //__android_log_print(ANDROID_LOG_INFO, "panyi", "desc  = %s", c_value_str);

    jstring j_value_str = (*env)->NewStringUTF(env, c_value_str);

    (*env)->SetObjectField(env, contact, name_fid, j_value_str);

    (*env)->ReleaseStringUTFChars(env, j_value_str, c_value_str);

    (*env)->DeleteLocalRef(env,j_value_str);
}



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

    (*env)->CallVoidMethod(env, stu_ojb, setNameMethId, (*env)->NewStringUTF(env, name));

    __android_log_print(ANDROID_LOG_INFO, "panyi", "setName complete");

    (*env)->ReleaseStringUTFChars(env, j_str, c_str);

    json_value_free(jsonValue);

    return stu_ojb;
}


JNIEXPORT jobject JNICALL Java_com_xinlan_jnicreate_NativeLib_parseList
        (JNIEnv *env, jclass clazz, jstring j_str) {
    char *c_str = NULL;

    c_str = (*env)->GetStringUTFChars(env, j_str, 0);
    if (c_str == NULL) {
        __android_log_print(ANDROID_LOG_INFO, "panyi", "c_str is null");
        return NULL;
    }

    //__android_log_print(ANDROID_LOG_INFO, "panyi", "c_str is %s",c_str);

    JSON_Value *jsonRoot = json_parse_string(c_str);
    if (jsonRoot == NULL) {
        __android_log_print(ANDROID_LOG_INFO, "panyi", "c_str json parse ERROR");
        return NULL;
    }

    JSON_Array *jsonArray = json_object_get_array(json_object(jsonRoot), "list");

    if (jsonArray == NULL) {
        __android_log_print(ANDROID_LOG_INFO, "panyi", "c_str array parse ERROR");
        return NULL;
    }

    size_t arrayCount = json_array_get_count(jsonArray);

    //__android_log_print(ANDROID_LOG_INFO, "panyi", "c_str array size = %d",arrayCount);

    jclass array_list_clazz = (*env)->FindClass(env, "java/util/ArrayList");

    jmethodID array_list_construct_mid = (*env)->GetMethodID(env, array_list_clazz, "<init>",
                                                             "()V");

    jobject array_list = (*env)->NewObject(env, array_list_clazz, array_list_construct_mid);

    jmethodID array_list_add_mid = (*env)->GetMethodID(env, array_list_clazz, "add",
                                                       "(Ljava/lang/Object;)Z");

    jclass contact_clazz = (*env)->FindClass(env, "com/xinlan/jnicreate/model/Contact");
    jmethodID contact_constract_mid = (*env)->GetMethodID(env, contact_clazz, "<init>", "()V");

    jfieldID name_fid =  (*env)->GetFieldID(env, contact_clazz, "name", "Ljava/lang/String;");
    jfieldID fullName_fid =  (*env)->GetFieldID(env, contact_clazz, "fullName", "Ljava/lang/String;");
    jfieldID remarkName_fid =  (*env)->GetFieldID(env, contact_clazz, "remarkName", "Ljava/lang/String;");
    jfieldID uid_fid =  (*env)->GetFieldID(env, contact_clazz, "uid", "Ljava/lang/String;");
    jfieldID email_fid =  (*env)->GetFieldID(env, contact_clazz, "email", "Ljava/lang/String;");
    jfieldID status_fid =  (*env)->GetFieldID(env, contact_clazz, "status", "Ljava/lang/String;");
    jfieldID department_fid =  (*env)->GetFieldID(env, contact_clazz, "department", "Ljava/lang/String;");
    jfieldID mobile_fid =  (*env)->GetFieldID(env, contact_clazz, "mobile", "Ljava/lang/String;");
    jfieldID age_fid =  (*env)->GetFieldID(env, contact_clazz, "mobile", "Ljava/lang/String;");
    jfieldID sex_fid =  (*env)->GetFieldID(env, contact_clazz, "sex", "Ljava/lang/String;");
    jfieldID height_fid =  (*env)->GetFieldID(env, contact_clazz, "height", "Ljava/lang/String;");
    jfieldID desc_fid =  (*env)->GetFieldID(env, contact_clazz, "desc", "Ljava/lang/String;");
    jfieldID hobby_fid =  (*env)->GetFieldID(env, contact_clazz, "hobby", "Ljava/lang/String;");


    for (size_t index = 0; index < arrayCount; index++) {
        JSON_Object *obj = json_array_get_object(jsonArray, index);
        if (obj == NULL) {
            __android_log_print(ANDROID_LOG_INFO, "panyi", "%d index array parse ERROR", index);
            continue;
        }

        jobject contact = (*env)->NewObject(env, contact_clazz, contact_constract_mid);

        setContactFieldValue(env,contact,"name",obj,name_fid);
        setContactFieldValue(env,contact,"fullName",obj,fullName_fid);
        setContactFieldValue(env,contact,"remarkName",obj,remarkName_fid);
        setContactFieldValue(env,contact,"uid",obj,uid_fid);
        setContactFieldValue(env,contact,"email",obj,email_fid);
        setContactFieldValue(env,contact,"status",obj,status_fid);
        setContactFieldValue(env,contact,"department",obj,department_fid);
        setContactFieldValue(env,contact,"mobile",obj,mobile_fid);
        setContactFieldValue(env,contact,"age",obj,age_fid);
        setContactFieldValue(env,contact,"sex",obj,sex_fid);
        setContactFieldValue(env,contact,"height",obj,height_fid);
        setContactFieldValue(env,contact,"desc",obj,desc_fid);
        setContactFieldValue(env,contact,"hobby",obj,hobby_fid);


        (*env)->CallBooleanMethod(env, array_list,array_list_add_mid, contact);

        (*env)->DeleteLocalRef(env,contact);
    }//end for i

    (*env)->ReleaseStringUTFChars(env, j_str, c_str);
    return array_list;
}





