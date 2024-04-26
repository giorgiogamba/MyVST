#include "MainGUIComponent.h"
#include "MainAudioComponent.h"

//==============================================================================
MainGUIComponent::MainGUIComponent()
{
    setSize (800, 1000);
    
    // Creates audio component
    addChildComponent(new MainAudioComponent());
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
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
