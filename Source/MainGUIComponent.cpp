#include "MainGUIComponent.h"
#include "MainAudioComponent.h"

//==============================================================================
MainGUIComponent::MainGUIComponent()
{
    setSize (800, 1000);
    
    // Frequency Slider setup
    frequencySlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    frequencySlider.setTextValueSuffix("Hz");
    frequencySlider.setBounds(getLocalBounds());
    frequencySlider.setRange(50, 1000); // Available frequencies
    frequencySlider.addListener(this);
    
    frequencyLabel.setText("Frequency", dontSendNotification);
    frequencyLabel.attachToComponent(&frequencySlider, true);
    
    addAndMakeVisible(frequencySlider);

    // Amplitude Slider setup
    amplitudeSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    amplitudeSlider.setBounds(getLocalBounds());
    amplitudeSlider.setRange(0, 1); // Available
    amplitudeSlider.addListener(this);
    addAndMakeVisible(amplitudeSlider);
    
    amplitudeLabel.setText("Amplitude", dontSendNotification);
    amplitudeLabel.attachToComponent(&amplitudeSlider, true);
    
    // Creates audio component
    addChildComponent(audioComponent);
}

MainGUIComponent::~MainGUIComponent()
{
}

//==============================================================================
void MainGUIComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::rebeccapurple);
    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainGUIComponent::resized()
{
    const int LabelSpace = 100;
    frequencySlider.setBounds(LabelSpace, 20, getWidth() - 100, 20);
    amplitudeSlider.setBounds(LabelSpace, 50, getWidth() - 100, 50);
}

void MainGUIComponent::sliderValueChanged(Slider* slider)
{
    if (!slider)
        return;
    
    if (slider == &frequencySlider)
    {
        audioComponent.SetFrequency(slider->getValue());
    }
    else if (slider == &amplitudeSlider)
    {
        audioComponent.SetAmplitude(slider->getValue());
    }
}
