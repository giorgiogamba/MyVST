/*
  ==============================================================================

    MySynthesiserVoice.h
    Created: 3 May 2024 5:14:30pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "MySynthesiserSound.h"

class MySynthesiserVoice : public SynthesiserVoice
{
public:
    
    bool canPlaySound(SynthesiserSound* sound);
    
    void startNote(int midiNodeNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition);
    
    void stopNote(float velocity, bool allowTailOff);
    
    void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples);
    
    virtual void pitchWheelMoved (int newPitchWheelValue)
    {}

    virtual void controllerMoved (int controllerNumber, int newControllerValue)
    {}
    
private:
    
    double frequency;
    
};
