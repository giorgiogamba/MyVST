/*
  ==============================================================================

    Oscillator.h
    Created: 6 May 2024 11:24:50am
    Author:  Giorgio Gamba

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class Oscillator
{
public:
    
    Oscillator()
        : currentAngle(0.0f)
        , deltaAngle(0.0f)
    {}
    
    void setFrequency(const float inFrequency, const float inSampleRate);
    
    float getNextSample();
    
private:
    
    void updateAngle();
    
    float currentAngle;
    float deltaAngle;
    float frequency;
    float sampleRate;
    
};
