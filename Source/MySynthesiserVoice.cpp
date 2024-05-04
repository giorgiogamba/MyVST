/*
  ==============================================================================

    MySynthesiserVoice.cpp
    Created: 3 May 2024 5:14:30pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#include "MySynthesiserVoice.h"

bool MySynthesiserVoice::canPlaySound(SynthesiserSound* sound)
{
    return dynamic_cast<SynthesiserSound*>(sound);
}

void MySynthesiserVoice::startNote(int midiNodeNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
{
    frequency = MidiMessage::getMidiNoteInHertz(midiNodeNumber);
}

void MySynthesiserVoice::stopNote(float velocity, bool allowTailOff)
{
    clearCurrentNote();
}

void MySynthesiserVoice::renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
{
    
    
}
