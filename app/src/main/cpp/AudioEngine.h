//
// Created by Andhika Yuana on 27/10/18.
//

#ifndef SIMPLE_SYNTHESIZER_AUDIOENGINE_H
#define SIMPLE_SYNTHESIZER_AUDIOENGINE_H

#include <oboe/Oboe.h>
#include "Oscillator.h"

using namespace oboe;

class AudioEngine : public AudioStreamCallback {
public:
    void start();

    DataCallbackResult onAudioReady(AudioStream *oboeStream, void *audioData, int32_t numFrames) override;

    void setToneOn(bool isOn);

private:
    Oscillator oscillator;
};


#endif //SIMPLE_SYNTHESIZER_AUDIOENGINE_H
