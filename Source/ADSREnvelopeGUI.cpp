/*
  ==============================================================================

    ADSREnvelopeGUI.cpp
    Created: 8 May 2024 4:37:09pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#include "ADSREnvelopeGUI.h"

ADSREnvelopeGUI::ADSREnvelopeGUI()
{
    attackSlider = new Slider();
    
    
    decaySlider = new Slider();
    addAndMakeVisible(decaySlider);
    
    sustainSlider = new Slider();
    addAndMakeVisible(sustainSlider);
    
    releaseSlider = new Slider();
    addAndMakeVisible(releaseSlider);
    
    setupSlidersStyle();
    
    setSize(200, 300);
}

void ADSREnvelopeGUI::sliderValueChanged(Slider* slider)
{
    if (!slider || !adsr)
        return;
    
    const float sliderValue = slider->getValue();
    
    if (slider == attackSlider)
    {
        adsr->setAttackTime(sliderValue);
    }
    else if (slider == decaySlider)
    {
        adsr->setDecayTime(sliderValue);
    }
    else if (slider == sustainSlider)
    {
        adsr->setSustainTime(sliderValue);
    }
    else if (slider == releaseSlider)
    {
        adsr->setReleaseTime(sliderValue);
    }
}

void ADSREnvelopeGUI::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void ADSREnvelopeGUI::resized()
{
    attackSlider->setBounds(10, 10, 30, 60);
    decaySlider->setBounds(50, 10, 30, 60);
}

void ADSREnvelopeGUI::setupSlidersStyle()
{
    attackSlider->setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider->setRange(0.1f, 1.f);
    attackSlider->setValue(0.1f);
    attackSlider->setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    attackSlider->addListener(this);
    addAndMakeVisible(attackSlider);
    
    decaySlider->setSliderStyle(Slider::SliderStyle::LinearVertical);
    decaySlider->setRange(0.1f, 1.f);
    decaySlider->setValue(0.1f);
    decaySlider->setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    decaySlider->addListener(this);
}
