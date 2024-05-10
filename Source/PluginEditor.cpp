/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "ADSREnvelopeGUI.h"

//==============================================================================
MyVSTAudioProcessorEditor::MyVSTAudioProcessorEditor (MyVSTAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    adsrController = new ADSREnvelopeGUI();
    
    setSize (400, 300);
}

MyVSTAudioProcessorEditor::~MyVSTAudioProcessorEditor()
{
}

//==============================================================================
void MyVSTAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    addAndMakeVisible(adsrController);
}

void MyVSTAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    if (adsrController)
    {
        adsrController->setBounds(0, 0, 200, 200);
    }
}
