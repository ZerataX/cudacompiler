/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class yacx_FloatArg */

#ifndef _Included_yacx_FloatArg
#define _Included_yacx_FloatArg
#ifdef __cplusplus
extern "C" {
#endif
#undef yacx_FloatArg_SIZE_BYTES
#define yacx_FloatArg_SIZE_BYTES 4L
/*
 * Class:     yacx_FloatArg
 * Method:    createValue
 * Signature: (F)Lyacx/KernelArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_FloatArg_createValue
  (JNIEnv *, jclass, jfloat);

/*
 * Class:     yacx_FloatArg
 * Method:    createInternal
 * Signature: ([FZ)Lyacx/FloatArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_FloatArg_createInternal
  (JNIEnv *, jclass, jfloatArray, jboolean);

/*
 * Class:     yacx_FloatArg
 * Method:    createOutputInternal
 * Signature: (I)Lyacx/FloatArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_FloatArg_createOutputInternal
  (JNIEnv *, jclass, jint);

/*
 * Class:     yacx_FloatArg
 * Method:    asFloatArray
 * Signature: ()[F
 */
JNIEXPORT jfloatArray JNICALL Java_yacx_FloatArg_asFloatArray
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
