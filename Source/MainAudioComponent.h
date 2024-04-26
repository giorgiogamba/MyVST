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
    
    void SetFrequency(const double newFrequency);
    
    void SetAmplitude(const double newAmplitude);

private:
    
    // Wavetable representing a sine function
    Array<float> SineWavetable;
    
    // Size of the sine wavetable
    float SineWavetableSize;
    
    // Frequency of the sine of the wavetable
    double frequency;
    
    // Current phase of the size
    double phase;
    
    // How much we have to increment the current wavetable value compared with the frequency
    double increment = 0;
    
    // Amplitude applied to the wave
    double amplitude;
    
    double currentSampleRate;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainAudioComponent)
};
