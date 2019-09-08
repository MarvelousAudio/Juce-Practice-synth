/*
  ==============================================================================

    Filter.cpp
    Created: 5 Sep 2019 1:32:13pm
    Author:  ben haywood

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Filter.h"

//==============================================================================
Filter::Filter(Practicesynth01AudioProcessor& p) :  processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setSize(200, 200);
    filterCutoffParameter.setSliderStyle(Slider::SliderStyle::LinearVertical);
    filterCutoffParameter.setRange(0.1f, 100.0f);
    filterCutoffParameter.setValue(50.0f);
    filterCutoffParameter.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    // attackParameter.addListener(this);
    addAndMakeVisible(&filterCutoffParameter);
    
    filterResParameter.setSliderStyle(Slider::SliderStyle::LinearVertical);
    filterResParameter.setRange(0.1f, 100.0f);
    filterResParameter.setValue(0.1f);
    filterResParameter.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    // attackParameter.addListener(this);
    addAndMakeVisible(&filterResParameter);
    
    filterCutoffTree = std::make_unique< AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "filtercutoff", filterCutoffParameter);
    filterResTree = std::make_unique< AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "filterres", filterResParameter);
}

Filter::~Filter()
{
}

void Filter::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
    //g.fillAll (Colours::black);   // clear the background
//
//    g.setColour (Colours::grey);
//    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
//
//    g.setColour (Colours::white);
//    g.setFont (14.0f);
//    g.drawText ("Filter", getLocalBounds(),
//                Justification::centred, true);   // draw some placeholder text
    juce::Rectangle<int> titleArea (0, 10, getWidth(), 20);
    
    g.fillAll (Colours::black);
    g.setColour(Colours::white);
    g.drawText("Filter", titleArea, Justification::centredTop);
    
    //static positioning for now due to time, make dynamic later
    g.drawText ("Cutoff", 53, 250, 20, 20, Justification::centredTop);
    g.drawText ("Resenance", 77, 250, 20, 20, Justification::centredTop);
    juce::Rectangle <float> area (25, 25, 150, 150);
    
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Filter::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    Rectangle<int> area = getBounds().reduced(40);
    filterCutoffParameter.setBounds(53, 150, 40, 100);
    filterResParameter.setBounds(77, 150, 40, 100);
}
