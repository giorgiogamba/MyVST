/*
  ==============================================================================

    MainAudioComponent.h
    Created: 25 Apr 2024 1:11:16pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MainAudioComponent  : public juce::AudioAppComponent
{
public:
    MainAudioComponent();
    ~MainAudioComponent();
    
    virtual void prepareToPlay (int samplesPerBlock, double sampleRate) override;
    
    virtual void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;
    
    virtual void releaseResources() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainAudioComponent)
};
