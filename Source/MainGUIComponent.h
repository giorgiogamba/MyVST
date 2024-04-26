#pragma once

#include <JuceHeader.h>

#include "MainAudioComponent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainGUIComponent  : public juce::Component, public Slider::Listener
{
public:
    
    MainGUIComponent();
    ~MainGUIComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    MainAudioComponent audioComponent;
    
    // This function response to every slider action
    void sliderValueChanged(Slider* slider);
    
    Slider frequencySlider;
    Label frequencyLabel;
    
    Slider amplitudeSlider;
    Label amplitudeLabel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainGUIComponent)
};
