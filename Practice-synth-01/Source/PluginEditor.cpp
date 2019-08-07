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
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    //attack slider!
    attackParameter.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackParameter.setRange(0.1f, 5000);
    attackParameter.setValue(0.1f);
    attackParameter.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    attackParameter.addListener(this);
    addAndMakeVisible(&attackParameter);
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
    attackParameter.setBounds(0, 0, 40, 100);
}

void Practicesynth01AudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (slider == &attackParameter){
        processor.attackTime = attackParameter.getValue();
        //DBG(processor.attackTime);
    }
}
