/*
  ==============================================================================

    Envelope.cpp
    Created: 3 Sep 2019 5:37:44pm
    Author:  ben haywood

  ==============================================================================
*/
// to do Delete commented stuff!
#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope.h"

//==============================================================================
Envelope::Envelope(Practicesynth01AudioProcessor& p) :  processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    //=======================================================================
    //attack GUI!
    setSize(200, 200);
    attackParameter.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackParameter.setRange(0.1f, 5000.0f);
    attackParameter.setValue(0.1f);
    attackParameter.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
   // attackParameter.addListener(this);
    addAndMakeVisible(&attackParameter);
    
    
    //==========================================================================
    //decay GUI
    decayParameter.setSliderStyle(Slider::SliderStyle::LinearVertical);
    decayParameter.setRange(0.1f, 500.0f);
    decayParameter.setValue(0.1f);
    decayParameter.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
   // decayParameter.addListener(this);
    addAndMakeVisible(&decayParameter);
    
    
    //==========================================================================
    //sustain GUI
    sustainParameter.setSliderStyle(Slider::SliderStyle::LinearVertical);
    sustainParameter.setRange(0.1f, 0.8f);
    sustainParameter.setValue(0.8f);
    sustainParameter.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    //sustainParameter.addListener(this);
    addAndMakeVisible(&sustainParameter);
    //==========================================================================
    //release GUI
    releaseParameter.setSliderStyle(Slider::SliderStyle::LinearVertical);
    releaseParameter.setRange(0.1f, 5000.0f);
    releaseParameter.setValue(0.1f);
    releaseParameter.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    //releaseParameter.addListener(this);
    addAndMakeVisible(&releaseParameter);
    
    //    releaseTree = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "release", releaseParameter);
    
    
    attackTree = std::make_unique< AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "attack", attackParameter);
    decayTree = std::make_unique< AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "decay", decayParameter);
    sustainTree = std::make_unique< AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "sustain", sustainParameter);
    
    releaseTree = std::make_unique< AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "release", releaseParameter);

}

Envelope::~Envelope()
{
}

void Envelope::paint (Graphics& g)
{
    juce::Rectangle<int> titleArea (0, 10, getWidth(), 20);
    
    g.fillAll (Colours::black);
    g.setColour(Colours::white);
    g.drawText("Envelope", titleArea, Justification::centredTop);
    
    //static positioning for now due to time, make dynamic later
    g.drawText ("A", 53, 150, 20, 20, Justification::centredTop);
    g.drawText ("D", 77, 150, 20, 20, Justification::centredTop);
    g.drawText ("S", 103, 150, 20, 20, Justification::centredTop);
    g.drawText ("R", 128, 150, 20, 20, Justification::centredTop);
    
    juce::Rectangle <float> area (25, 25, 150, 150);
    
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

//    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background
//
//    g.setColour (Colours::grey);
//    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
//
//    g.setColour (Colours::white);
//    g.setFont (14.0f);
//    g.drawText ("Envelope", getLocalBounds(),
//                Justification::centred, true);   // draw some placeholder text
}

void Envelope::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    Rectangle<int> area = getBounds().reduced(40);
    attackParameter.setBounds(53, 50, 40, 100);
    decayParameter.setBounds(77, 50, 40, 100);
    sustainParameter.setBounds(103, 50, 40, 100);
    releaseParameter.setBounds(128, 50, 40, 100);
}
//void Envelope::sliderValueChanged(Slider* slider)
//{
//    //    if (slider == &attackParameter){
//    //        processor.attackTime = attackParameter.getValue();
//    //
//    //        DBG("attackTime: " << processor.attackTime);
//    //    }
//    //    if (slider == &releaseParameter){
//    //        processor.releaseTime = releaseParameter.getValue();
//    //
//    //        DBG("releaseTime: " << processor.releaseTime);
//    //    }
//}
