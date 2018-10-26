#include <jni.h>
#include <string>

#include <oboe/Oboe.h>

extern "C" JNIEXPORT jstring JNICALL
Java_id_yuana_simple_synthesizer_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++ Yuana";
    return env->NewStringUTF(hello.c_str());
}