/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Oscillator.h"
#include "Envelope.h"
#include "Filter.h"

//==============================================================================
/**
*/
class Practicesynth01AudioProcessorEditor  : public AudioProcessorEditor
{
public:
    Practicesynth01AudioProcessorEditor (Practicesynth01AudioProcessor&);
    ~Practicesynth01AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
//    void sliderValueChanged(Slider* slider) override;
private:
    
    Envelope envGui;
    Filter filtGui;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Practicesynth01AudioProcessor& processor;
//    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> attackTree;
//    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> releaseTree;
    Oscillator oscGui;
//    Slider attackParameter;
//    Slider decayParameter;
//    Slider sustainParameter;
//    Slider releaseParameter;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Practicesynth01AudioProcessorEditor)
    

//    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> attackTree;
//    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> decayTree;
//    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sustainTree;
//    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> releaseTree;
    //JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Practicesynth01AudioProcessorEditor)
    
    //Oscillator oscGui;
};
