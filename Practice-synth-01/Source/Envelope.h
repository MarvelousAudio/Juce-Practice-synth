/*
  ==============================================================================

    Envelope.h
    Created: 3 Sep 2019 5:37:44pm
    Author:  ben haywood

  ==============================================================================
*/
//to do delete commeneted stuff!
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Envelope    : public Component
//public Slider::Listener
{
public:
    Envelope(Practicesynth01AudioProcessor&);
    ~Envelope();

    void paint (Graphics&) override;
    void resized() override;
//    void sliderValueChanged(Slider* slider) override;
    
private:
    Practicesynth01AudioProcessor& processor;
    
    Slider attackParameter;
    Slider decayParameter;
    Slider sustainParameter;
    Slider releaseParameter;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
    
public:
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> attackTree;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> decayTree;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sustainTree;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> releaseTree;
};
