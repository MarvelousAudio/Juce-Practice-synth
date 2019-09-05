/*
  ==============================================================================

    Filter.h
    Created: 5 Sep 2019 1:32:13pm
    Author:  ben haywood

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Filter    : public Component
{
public:
    Filter(Practicesynth01AudioProcessor&);
    ~Filter();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Filter)
    Practicesynth01AudioProcessor& processor;
};
