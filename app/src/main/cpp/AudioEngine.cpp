//
// Created by Andhika Yuana on 27/10/18.
//

#include "AudioEngine.h"
#include "../../../../../oboe/src/common/OboeDebug.h"
#include <oboe/Oboe.h>

using namespace oboe;

void AudioEngine::start() {

    AudioStreamBuilder builder;

    builder.setFormat(AudioFormat::Float);
    builder.setChannelCount(1);
    builder.setCallback(this);
    builder.setPerformanceMode(PerformanceMode::LowLatency);

    AudioStream *stream = nullptr;
    Result result = builder.openStream(&stream);

    if (result == Result::OK) {

        oscillator.setSampleRate(stream->getSampleRate());


        stream->requestStart();

        AudioFormat format = stream->getFormat();
        LOGI("AudioStream format is %s", convertToText(format));

    } else {
        LOGE("Failed to create stream. Error: %s", convertToText(result));
    }

}

DataCallbackResult AudioEngine::onAudioReady(AudioStream *oboeStream, void *audioData, int32_t numFrames) {

    oscillator.render(static_cast<float *>(audioData), numFrames);

    return DataCallbackResult::Continue;
}

void AudioEngine::setToneOn(bool isOn) {
    oscillator.setWaveOn(isOn);
}
