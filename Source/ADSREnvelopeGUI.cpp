/*
  ==============================================================================

    ADSREnvelopeGUI.cpp
    Created: 8 May 2024 4:37:09pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#include "ADSREnvelopeGUI.h"

ADSREnvelopeGUI::ADSREnvelopeGUI(ADSREnvelope* adsrEnvelope)
{
    adsr = adsrEnvelope;
    
    attackSlider = new Slider();
    decaySlider = new Slider();
    sustainSlider = new Slider();
    releaseSlider = new Slider();
    
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
    sustainSlider->setBounds(90, 10, 30, 60);
    releaseSlider->setBounds(130, 10, 30, 60);
}

void ADSREnvelopeGUI::setupSlidersStyle()
{
    createSlider(attackSlider);
    createSlider(decaySlider);
    createSlider(sustainSlider);
    createSlider(releaseSlider);
}

void ADSREnvelopeGUI::createSlider(Slider* slider)
{
    if (!slider)
        return;
    
    slider->setSliderStyle(Slider::SliderStyle::LinearVertical);
    slider->setRange(0.1f, 1.f);
    slider->setValue(0.1f);
    slider->setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    slider->addListener(this);
    addAndMakeVisible(slider);
}
