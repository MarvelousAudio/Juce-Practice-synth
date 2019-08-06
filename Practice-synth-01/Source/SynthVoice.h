/*
  ==============================================================================

    SynthVoice.h
    Created: 31 Jul 2019 10:30:20pm
    Author:  ben haywood

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "maximilian.h"


class SynthVoice : public SynthesiserVoice
{
public:
    
    bool canPlaySound (SynthesiserSound* sound)
    {
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    
    //=================================================
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
    {
        level = velocity;
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
       // std::cout << midiNoteNumber << std::endl;
    }
    //==================================================
    
    void stopNote (float velocity, bool allowTailOff)
    {
        level = 0;
    }
    //====================================================
    
    void pitchWheelMoved (int newPitchWheelValue)
    {
        
    }
    //====================================================
    void controllerMoved (int controllerNumber, int newControllerValue)
    {
        
    }
    //====================================================
    void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
    {
        
        for (int sample = 0; sample < numSamples; sample++)
        {
            double theWave = osc1.sinewave(440) * level;
            for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++)
            {
                outputBuffer.addSample(channel, startSample, theWave);
                
            }
            startSample++;
        }
        
    }
    //====================================================
private:
    double level;
    double frequency;
    maxiOsc osc1;
};
