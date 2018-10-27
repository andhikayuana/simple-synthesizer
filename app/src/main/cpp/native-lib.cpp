#include <jni.h>

#include "AudioEngine.h"

static AudioEngine audioEngine;

extern "C" JNIEXPORT void JNICALL
Java_id_yuana_simple_synthesizer_ui_MainActivity_initAudioEngine(
        JNIEnv *env,
        jobject /* this */) {

    audioEngine.start();
}

extern "C" JNIEXPORT void JNICALL
Java_id_yuana_simple_synthesizer_ui_MainActivity_setToneOn(
        JNIEnv *env,
        jobject instance,
        jboolean isToneOn) {

    audioEngine.setToneOn(isToneOn);
}

extern "C" JNIEXPORT void JNICALL
Java_id_yuana_simple_synthesizer_ui_MainActivity_setDefaultSampleRate(
        JNIEnv *env,
        jobject instance,
        jint sampleRate
) {
    DefaultStreamValues::SampleRate = (int32_t) sampleRate;
}

extern "C" JNIEXPORT void JNICALL
Java_id_yuana_simple_synthesizer_ui_MainActivity_setDefaultFramesPerBurst(
        JNIEnv *env,
        jobject instance,
        jint framesPerBurst
) {
    DefaultStreamValues::FramesPerBurst = (int32_t) framesPerBurst;
}