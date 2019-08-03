/*
  ==============================================================================

    SynthSound.h
    Created: 31 Jul 2019 10:30:42pm
    Author:  ben haywood

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
  
public:
    bool appliesToNote (int /*midiNoteNumber*/)
    {
        return true;
    }
    
    bool appliesToChannel (int /*midiChannel*/)
    {
        return true;
    }
};
