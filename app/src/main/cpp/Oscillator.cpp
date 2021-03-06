//
// Created by Andhika Yuana on 26/10/18.
//

#include "Oscillator.h"
#include <math.h>

#define TWO_PI (M_PI * 2)
#define AMPLITUDE 20
#define FREQUENCY 261.62 // C4 Tone

void Oscillator::setWaveOn(bool isWaveOn) {
    isWaveOn_.store(isWaveOn);
}

void Oscillator::setSampleRate(int32_t sampleRate) {
    phaseIncrement_ = (TWO_PI * FREQUENCY) / (double) sampleRate;
}

void Oscillator::render(float *audioData, int32_t numFrames) {

    if (!isWaveOn_.load()) phase_ = 0;

    for (int i = 0; i < numFrames; i++) {

        if (isWaveOn_.load()) {

            //calculate sample
            audioData[i] = (float) (sin(phase_) * AMPLITUDE);

            //increment phase
            phase_ += phaseIncrement_;
            if (phase_ > TWO_PI) phase_ -= TWO_PI;

        } else {
            //silence
            audioData[i] = 0;
        }

    }
}
