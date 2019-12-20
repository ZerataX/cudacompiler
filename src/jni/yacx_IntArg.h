/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class yacx_IntArg */

#ifndef _Included_yacx_IntArg
#define _Included_yacx_IntArg
#ifdef __cplusplus
extern "C" {
#endif
#undef yacx_IntArg_SIZE_BYTES
#define yacx_IntArg_SIZE_BYTES 4L
/*
 * Class:     yacx_IntArg
 * Method:    createValue
 * Signature: (I)Lyacx/KernelArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_IntArg_createValue
  (JNIEnv *, jclass, jint);

/*
 * Class:     yacx_IntArg
 * Method:    create
 * Signature: (Lyacx/IntArg;Z)Lyacx/IntArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_IntArg_create
  (JNIEnv *, jclass, jobject, jboolean);

/*
 * Class:     yacx_IntArg
 * Method:    createInternal
 * Signature: ([IZ)Lyacx/IntArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_IntArg_createInternal
  (JNIEnv *, jclass, jintArray, jboolean);

/*
 * Class:     yacx_IntArg
 * Method:    createOutputInternal
 * Signature: (I)Lyacx/IntArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_IntArg_createOutputInternal
  (JNIEnv *, jclass, jint);

/*
 * Class:     yacx_IntArg
 * Method:    asIntArray
 * Signature: ()[I
 */
JNIEXPORT jintArray JNICALL Java_yacx_IntArg_asIntArray
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
