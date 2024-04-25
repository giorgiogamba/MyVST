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
    //Super::prepareToPlay(samplesPerBlock, sampleRate);
}

void MainAudioComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill)
{
    if (!bufferToFill.buffer)
        return;
    
    // Create a white random noise
    for (int channelIdx = 0; channelIdx < bufferToFill.buffer->getNumChannels(); ++ channelIdx)
    {
        // Retrives the first index in the buffer
        float* buffer = bufferToFill.buffer->getWritePointer(channelIdx, bufferToFill.startSample);
        
        for (int sampleIdx = 0; sampleIdx < bufferToFill.numSamples; ++sampleIdx)
        {
            buffer[sampleIdx] = (juce::Random::getSystemRandom().nextFloat() * 2.f - 1.f) * 0.25f;
        }
    }
}

void MainAudioComponent::releaseResources()
{
    //Super::releaseResources();
    
}
