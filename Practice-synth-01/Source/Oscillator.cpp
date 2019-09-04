/*
  ==============================================================================

    Oscillator.cpp
    Created: 27 Aug 2019 3:36:16pm
    Author:  ben haywood

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"
//#include "PluginProcessor.h"

//==============================================================================
Oscillator::Oscillator(Practicesynth01AudioProcessor& p) : processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setSize(200, 200);
    oscMenu.addItem("Sine", 1);
    oscMenu.addItem("Saw", 2);
    oscMenu.addItem("Square", 3);
    addAndMakeVisible(&oscMenu);
    oscMenu.addListener(this);
//    waveSelection = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "wavetype",oscMenu);
    
    
    oscMenu.setJustificationType(Justification::centred);
    
    waveSelection = std::make_unique< AudioProcessorValueTreeState::ComboBoxAttachment>(processor.tree, "wavetype", oscMenu);
    
}

Oscillator::~Oscillator()
{
}

void Oscillator::paint (Graphics& g)
{
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
//    g.drawText ("Oscillator", getLocalBounds(),
//                Justification::centred, true);   // draw some placeholder text
}

void Oscillator::resized()
{
    
    Rectangle<int> area = getLocalBounds().reduced(40);
    oscMenu.setBounds(area.removeFromTop(20));
}

void Oscillator::comboBoxChanged(ComboBox* box)
{
    
}
