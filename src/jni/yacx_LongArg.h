/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class yacx_LongArg */

#ifndef _Included_yacx_LongArg
#define _Included_yacx_LongArg
#ifdef __cplusplus
extern "C" {
#endif
#undef yacx_LongArg_SIZE_BYTES
#define yacx_LongArg_SIZE_BYTES 8L
/*
 * Class:     yacx_LongArg
 * Method:    createValue
 * Signature: (J)Lyacx/KernelArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_LongArg_createValue
  (JNIEnv *, jclass, jlong);

/*
 * Class:     yacx_LongArg
 * Method:    create
 * Signature: (Lyacx/LongArg;Z)Lyacx/LongArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_LongArg_create
  (JNIEnv *, jclass, jobject, jboolean);

/*
 * Class:     yacx_LongArg
 * Method:    createInternal
 * Signature: ([JZ)Lyacx/LongArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_LongArg_createInternal
  (JNIEnv *, jclass, jlongArray, jboolean);

/*
 * Class:     yacx_LongArg
 * Method:    createOutputInternal
 * Signature: (I)Lyacx/LongArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_LongArg_createOutputInternal
  (JNIEnv *, jclass, jint);

/*
 * Class:     yacx_LongArg
 * Method:    asLongArray
 * Signature: ()[J
 */
JNIEXPORT jlongArray JNICALL Java_yacx_LongArg_asLongArray
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
