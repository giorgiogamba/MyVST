/*
  ==============================================================================

    ADSREnvelopeGUI.h
    Created: 8 May 2024 4:37:09pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "ADSREnvelope.h"

/** Defines the GUI for a ADSR Envelope*/

class ADSREnvelopeGUI : public Component, public Slider::Listener
{

public:
    
    ADSREnvelopeGUI(ADSREnvelope* adsrEnvelope);
    
    virtual void sliderValueChanged(Slider* slider) override;
    
    void paint (juce::Graphics&) override;
    
    virtual void resized() override;
    
private:
    
    void setupSlidersStyle();
    
    void createSlider(Slider* slider);
    
    // Defines a slider for each envelope parameter
    Slider* attackSlider;
    Slider* decaySlider;
    Slider* sustainSlider;
    Slider* releaseSlider;
    
    ADSREnvelope* adsr;
    
    
};
