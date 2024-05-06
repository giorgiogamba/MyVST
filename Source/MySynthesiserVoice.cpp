/*
  ==============================================================================

    MySynthesiserVoice.cpp
    Created: 3 May 2024 5:14:30pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#include "MySynthesiserVoice.h"
#include "Oscillator.h"

bool MySynthesiserVoice::canPlaySound(SynthesiserSound* sound)
{
    return dynamic_cast<SynthesiserSound*>(sound);
}

void MySynthesiserVoice::startNote(int midiNodeNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
{
    frequency = MidiMessage::getMidiNoteInHertz(midiNodeNumber);
    
    oscillator->setFrequency(frequency, getSampleRate());
}

void MySynthesiserVoice::stopNote(float velocity, bool allowTailOff)
{
    clearCurrentNote();
}

void MySynthesiserVoice::renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
{
    if (!oscillator)
     return;
    
    for (int sample = 0; sample < numSamples; ++sample)
    {
        for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
        {
            outputBuffer.addSample(channel, startSample, oscillator->getNextSample());
        }
        
        ++startSample;
    }
}
