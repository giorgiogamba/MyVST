/*
  ==============================================================================

    MainAudioComponent.cpp
    Created: 25 Apr 2024 1:11:16pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MainAudioComponent.h"

//==============================================================================
MainAudioComponent::MainAudioComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setAudioChannels(2, 2);
}

MainAudioComponent::~MainAudioComponent()
{
    shutdownAudio();
}

void MainAudioComponent::prepareToPlay (int samplesPerBlock, double sampleRate)
{
    frequency = 440;
    phase = 0;
    SineWavetableSize = 1024;
    amplitude = 0;
    
    increment = frequency * SineWavetableSize / sampleRate;
    
    currentSampleRate = sampleRate;
    
    // Fill up wavetable with one cycle of sine wave
    for (int i = 0; i < SineWavetableSize; i ++)
    {
        SineWavetable.insert(i, sin(2.0 * juce::MathConstants<double>::pi * i / SineWavetableSize));
    }
}

void MainAudioComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill)
{
    if (!bufferToFill.buffer)
        return;
    
//    // Create a white random noise
//    for (int channelIdx = 0; channelIdx < bufferToFill.buffer->getNumChannels(); ++ channelIdx)
//    {
//        // Retrives the first index in the buffer
//        float* buffer = bufferToFill.buffer->getWritePointer(channelIdx, bufferToFill.startSample);
//        
//        for (int sampleIdx = 0; sampleIdx < bufferToFill.numSamples; ++sampleIdx)
//        {
//            buffer[sampleIdx] = (juce::Random::getSystemRandom().nextFloat() * 2.f - 1.f) * 0.25f;
//        }
//    }
    
    // Creates a sine
    
    // Get speakers
    float* const leftSpeaker = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
    float* const rightSpeaker = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);
    
    for (int sampleIdx = 0; sampleIdx < bufferToFill.numSamples; sampleIdx ++)
    {
        // Put the same wavetable signal on both speakers
        leftSpeaker[sampleIdx] = SineWavetable[(int)phase] * amplitude;
        rightSpeaker[sampleIdx] = SineWavetable[(int)phase] * amplitude;
        
        // Updates phase remaining in the limits of the table
        phase = fmod(phase + increment, SineWavetableSize);
    }
    
    
}

void MainAudioComponent::releaseResources()
{
    SineWavetable.clear();
}

void MainAudioComponent::SetFrequency(const double newFrequency)
{
    frequency = newFrequency;
    increment = frequency * SineWavetableSize / currentSampleRate;
    phase = fmod(phase + increment, SineWavetableSize);
}

void MainAudioComponent::SetAmplitude(const double newAmplitude)
{
    amplitude = newAmplitude;
}
