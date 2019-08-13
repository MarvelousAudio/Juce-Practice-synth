/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Practicesynth01AudioProcessor::Practicesynth01AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
attackTime(0.1f),
releaseTime(0.1f),
sustainTime(0.8f),
decayTime(500.0f),
tree(*this, nullptr, "PARAMETERS", createParameterLayout())
//releaseTree(*this, nullptr, "PARAMTERS", createParameterLayout())
#endif
{
    //NormalisableRange<float> attackParam (0.1f, 5000.0f);
    //tree.createAndAddParameter("attack", "Attack", "Attack", attackParam, 0.1f,nullptr,nullptr);
    
//    using Parameter = AudioProcessorValueTreeState::Parameter;
//    YourAudioProcessor()
//    : apvts (*this, &undoManager, "PARAMETERS", { std::make_unique<Parameter> (paramID1, paramName1, ...),
//        std::make_unique<Parameter> (paramID2, paramName2, ...),
//        ... })
    
    
    mySynth.clearVoices();
    for (int i = 0; i < 5; i++){
        mySynth.addVoice(new SynthVoice());
    }
    mySynth.clearSounds();
    mySynth.addSound(new SynthSound());
}

Practicesynth01AudioProcessor::~Practicesynth01AudioProcessor()
{
}

//==============================================================================
const String Practicesynth01AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Practicesynth01AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Practicesynth01AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Practicesynth01AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Practicesynth01AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Practicesynth01AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Practicesynth01AudioProcessor::getCurrentProgram()
{
    return 0;
}

void Practicesynth01AudioProcessor::setCurrentProgram (int index)
{
}

const String Practicesynth01AudioProcessor::getProgramName (int index)
{
    return {};
}

void Practicesynth01AudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Practicesynth01AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    ignoreUnused(samplesPerBlock);
    lastSampleRate = sampleRate;
    mySynth.setCurrentPlaybackSampleRate(lastSampleRate);
}

void Practicesynth01AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Practicesynth01AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void Practicesynth01AudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
//    ScopedNoDenormals noDenormals;
//    auto totalNumInputChannels  = getTotalNumInputChannels();
//    auto totalNumOutputChannels = getTotalNumOutputChannels();
//
//    // In case we have more outputs than inputs, this code clears any output
//    // channels that didn't contain input data, (because these aren't
//    // guaranteed to be empty - they may contain garbage).
//    // This is here to avoid people getting screaming feedback
//    // when they first compile a plugin, but obviously you don't need to keep
//    // this code if your algorithm always overwrites all the output channels.
//    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
//        buffer.clear (i, 0, buffer.getNumSamples());
//
//    // This is the place where you'd normally do the guts of your plugin's
//    // audio processing...
//    // Make sure to reset the state if your inner loop is processing
//    // the samples and the outer loop is handling the channels.
//    // Alternatively, you can process the samples with the channels
//    // interleaved by keeping the same state.
//    for (int channel = 0; channel < totalNumInputChannels; ++channel)
//    {
//        auto* channelData = buffer.getWritePointer (channel);
//
//        // ..do something to the data...
//    }
    for (int i = 0; i < mySynth.getNumVoices(); i++)
    {
        if (myVoice = dynamic_cast<SynthVoice*>(mySynth.getVoice(i)))
        {
            myVoice->getParam(tree.getRawParameterValue("attack"),
                              tree.getRawParameterValue("decay"),
                              tree.getRawParameterValue("sustain"),

                              tree.getRawParameterValue("release"));
        }
    }
    buffer.clear();
    mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
    
}

//==============================================================================
bool Practicesynth01AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Practicesynth01AudioProcessor::createEditor()
{
    return new Practicesynth01AudioProcessorEditor (*this);
}

//==============================================================================
void Practicesynth01AudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Practicesynth01AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}
AudioProcessorValueTreeState::ParameterLayout Practicesynth01AudioProcessor::createParameterLayout()
{
    std::vector < std::unique_ptr<RangedAudioParameter>> params;
    
    //==============================================================================
    //adsr
    params.push_back(std::make_unique<AudioParameterFloat>("attack", "Attack", NormalisableRange<float>(0.1f, 5000.0f), 0.1f));
    params.push_back(std::make_unique<AudioParameterFloat>("decay", "Decay", NormalisableRange<float>(0.1f, 500.0f), 500.0f));
    params.push_back(std::make_unique<AudioParameterFloat>("sustain", "Sustain", NormalisableRange<float>(0.1f, 0.8f), 0.8f));

    params.push_back(std::make_unique<AudioParameterFloat>("release", "Release", NormalisableRange<float>(0.1f, 5000.0f), 0.1f));
    //===============================================================================
    return { params.begin(), params.end() };
}
//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Practicesynth01AudioProcessor();
}
