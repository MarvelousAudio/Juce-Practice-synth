/*
  ==============================================================================

    Oscillator.h
    Created: 27 Aug 2019 3:36:16pm
    Author:  ben haywood

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Oscillator    : public Component,
private ComboBox::Listener
{
public:
    Oscillator(Practicesynth01AudioProcessor&);
    ~Oscillator();

    void paint (Graphics&) override;
    void resized() override;
    void comboBoxChanged(ComboBox*) override;

private:
    ComboBox oscMenu;
    Practicesynth01AudioProcessor& processor;
    std::unique_ptr <AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;
   // ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};
