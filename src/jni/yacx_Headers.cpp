#include "yacx_Headers.h"
#include "Handle.h"
#include "../../include/yacx/Logger.hpp"
#include "../../include/yacx/Headers.hpp"

using yacx::Headers;

jobject Java_yacx_Headers_createHeaders (JNIEnv* env, jclass cls){
    BEGIN_TRY
        auto headersPtr = new Headers{};

        return createJNIObject(env, cls, headersPtr);
    END_TRY_R("creating headers", NULL)
}

void Java_yacx_Headers_insertInternal (JNIEnv* env, jobject obj, jobjectArray jheaderPathArray){
    BEGIN_TRY
        CHECK_NULL(jheaderPathArray, );

        auto headersPtr = getHandle<Headers>(env, obj);
    	CHECK_NULL(headersPtr, )

        int length = env->GetArrayLength(jheaderPathArray);

        CHECK_BIGGER(length, 0, "illegal array length", )

        for (int i = 0; i < length; i++) {
            auto jheaderPath = static_cast<jstring> (env->GetObjectArrayElement(jheaderPathArray, i));

            CHECK_NULL(jheaderPath, );

            auto headerPathPtr = env->GetStringUTFChars(jheaderPath, nullptr);

            headersPtr->insert(headerPathPtr);

            env->ReleaseStringUTFChars(jheaderPath, headerPathPtr);
        }
    END_TRY("inserting headers")
}

jint Java_yacx_Headers_getSize (JNIEnv* env, jobject obj){
    BEGIN_TRY
        auto headersPtr = getHandle<Headers>(env, obj);
    	CHECK_NULL(headersPtr, 0)
        auto size = headersPtr->numHeaders();

        return size;
    END_TRY_R("getting size of headers", 0)
}

jobjectArray Java_yacx_Headers_names (JNIEnv* env, jobject obj){
    BEGIN_TRY
        auto headersPtr = getHandle<Headers>(env, obj);
    	CHECK_NULL(headersPtr, NULL)
        auto size = headersPtr->numHeaders();
        auto names = headersPtr->names();

        return createStringArray(env, names, size);
    END_TRY_R("getting names of headers", NULL)
}

jobjectArray Java_yacx_Headers_content (JNIEnv* env, jobject obj){
    BEGIN_TRY
        auto headersPtr = getHandle<Headers>(env, obj);
    	CHECK_NULL(headersPtr, NULL)
        auto size = headersPtr->numHeaders();
        auto content = headersPtr->content();

        return createStringArray(env, content, size);
    END_TRY_R("getting content of headers", NULL)
}
