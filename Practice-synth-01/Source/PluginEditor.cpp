/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
Practicesynth01AudioProcessorEditor::Practicesynth01AudioProcessorEditor (Practicesynth01AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), oscGui(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    addAndMakeVisible(&oscGui);
    //=======================================================================
    //attack GUI!
    
    attackParameter.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackParameter.setRange(0.1f, 5000.0f);
    attackParameter.setValue(0.1f);
    attackParameter.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    attackParameter.addListener(this);
    addAndMakeVisible(&attackParameter);
    
    
    //==========================================================================
    //decay GUI
    decayParameter.setSliderStyle(Slider::SliderStyle::LinearVertical);
    decayParameter.setRange(0.1f, 500.0f);
    decayParameter.setValue(0.1f);
    decayParameter.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    decayParameter.addListener(this);
    addAndMakeVisible(&decayParameter);
    
    
    //==========================================================================
    //sustain GUI
    sustainParameter.setSliderStyle(Slider::SliderStyle::LinearVertical);
    sustainParameter.setRange(0.1f, 0.8f);
    sustainParameter.setValue(0.8f);
    sustainParameter.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    sustainParameter.addListener(this);
    addAndMakeVisible(&sustainParameter);
    //==========================================================================
    //release GUI
    releaseParameter.setSliderStyle(Slider::SliderStyle::LinearVertical);
    releaseParameter.setRange(0.1f, 5000.0f);
    releaseParameter.setValue(0.1f);
    releaseParameter.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    releaseParameter.addListener(this);
    addAndMakeVisible(&releaseParameter);
    
//    releaseTree = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "release", releaseParameter);
    
    
    attackTree = std::make_unique< AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "attack", attackParameter);
    decayTree = std::make_unique< AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "decay", decayParameter);
    sustainTree = std::make_unique< AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "sustain", sustainParameter);

    releaseTree = std::make_unique< AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "release", releaseParameter);
//    DBG("releaseParameter: " << releaseTree);
//    DBG("attackParameter: " << attackTree);
    
    
}

Practicesynth01AudioProcessorEditor::~Practicesynth01AudioProcessorEditor()
{
}

//==============================================================================
void Practicesynth01AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void Practicesynth01AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    attackParameter.setBounds(0, 80, 40, 100);
    decayParameter.setBounds(20, 80, 40, 100);
    sustainParameter.setBounds(40, 80, 40, 100);
    releaseParameter.setBounds(60, 80, 40, 100);
    
    Rectangle<int> area = getLocalBounds();
    
    const int componentWidth = 200;
    const int componentHeight = 200;
    oscGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    
}

void Practicesynth01AudioProcessorEditor::sliderValueChanged(Slider* slider)
{
//    if (slider == &attackParameter){
//        processor.attackTime = attackParameter.getValue();
//        
//        DBG("attackTime: " << processor.attackTime);
//    }
//    if (slider == &releaseParameter){
//        processor.releaseTime = releaseParameter.getValue();
//
//        DBG("releaseTime: " << processor.releaseTime);
//    }
}
