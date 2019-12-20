/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class yacx_Kernel */

#ifndef _Included_yacx_Kernel
#define _Included_yacx_Kernel
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     yacx_Kernel
 * Method:    configureInternal
 * Signature: (IIIIII)V
 */
JNIEXPORT void JNICALL Java_yacx_Kernel_configureInternal
  (JNIEnv *, jobject, jint, jint, jint, jint, jint, jint);

/*
 * Class:     yacx_Kernel
 * Method:    launchInternal
 * Signature: ([Lyacx/KernelArg;)Lyacx/KernelTime;
 */
JNIEXPORT jobject JNICALL Java_yacx_Kernel_launchInternal___3Lyacx_KernelArg_2
  (JNIEnv *, jobject, jobjectArray);

/*
 * Class:     yacx_Kernel
 * Method:    launchInternal
 * Signature: (Lyacx/Device;[Lyacx/KernelArg;)Lyacx/KernelTime;
 */
JNIEXPORT jobject JNICALL Java_yacx_Kernel_launchInternal__Lyacx_Device_2_3Lyacx_KernelArg_2
  (JNIEnv *, jobject, jobject, jobjectArray);

/*
 * Class:     yacx_Kernel
 * Method:    launchInternal
 * Signature: (Ljava/lang/String;[Lyacx/KernelArg;)Lyacx/KernelTime;
 */
JNIEXPORT jobject JNICALL Java_yacx_Kernel_launchInternal__Ljava_lang_String_2_3Lyacx_KernelArg_2
  (JNIEnv *, jobject, jstring, jobjectArray);

#ifdef __cplusplus
}
#endif
#endif
