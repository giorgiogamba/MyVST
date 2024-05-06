/*
  ==============================================================================

    Oscillator.cpp
    Created: 6 May 2024 11:24:50am
    Author:  Giorgio Gamba

  ==============================================================================
*/

#include "Oscillator.h"

void Oscillator::setFrequency(const float inFrequency, const float inSampleRate)
{
    frequency = inFrequency;
    sampleRate = inSampleRate;
    
    // Computes the number of function cycles are included inside a single sample,
    // because the frequency is the number of cycles made in 1 second,
    // while the sampleRate is the number of samples in 1 second
    const float cyclesPerSample = frequency / sampleRate;
    
    // Computes the distance between following angles, because each sample executes cyclesPerSample cycles
    // and a cycle is composed by 2pi radians
    deltaAngle = cyclesPerSample * MathConstants<float>::pi * 2.0;
    
    // Compute the waveTable
    
    
}

float Oscillator::getNextSample()
{
    const float currentSample = sin(currentAngle);
    updateAngle();
    return currentSample;
}

void Oscillator::updateAngle()
{
    currentAngle += deltaAngle;
    
    // Clamp in [-1, 1]
    if (currentAngle >= MathConstants<float>::twoPi)
    {
        currentAngle -= MathConstants<float>::twoPi;
    }
}
