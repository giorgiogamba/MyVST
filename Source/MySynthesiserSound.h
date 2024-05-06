/*
  ==============================================================================

    MySynthesiserSound.h
    Created: 3 May 2024 5:14:20pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class MySynthesiserSound : public SynthesiserSound
{
    virtual bool appliesToNote (int midiNoteNumber)
    {
        return true;
    }

    virtual bool appliesToChannel (int midiChannel)
    {
        return true;
    }
};
