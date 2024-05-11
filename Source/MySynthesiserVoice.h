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
#include "Oscillator.h"
#include "ADSREnvelope.h"

class ADSRController;

class MySynthesiserVoice : public SynthesiserVoice
{
public:
    
    MySynthesiserVoice(ADSREnvelope* adsrEnvelope)
    {
        frequency = 0.0;
        keyVelocity = 0.f;
        
        oscillator = new Oscillator();
        adsr = adsrEnvelope;
    }
    
    bool canPlaySound(SynthesiserSound* sound);
    
    void startNote(int midiNodeNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition);
    
    void stopNote(float velocity, bool allowTailOff);
    
    void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples);
    
    ADSREnvelope* getADSREnvelope() const { return adsr; }
    
    virtual void pitchWheelMoved (int newPitchWheelValue)
    {}

    virtual void controllerMoved (int controllerNumber, int newControllerValue)
    {}
    
private:
    
    double frequency;
    
    // Value that assigns an amplitude to a pressed key, in order to mute it if key unpressed
    float keyVelocity;
    
    Oscillator* oscillator;
    ADSREnvelope* adsr;
};
