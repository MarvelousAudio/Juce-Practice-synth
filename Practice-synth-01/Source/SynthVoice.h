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

class SynthVoice : public SynthesiserVoice
{
    public:
    
        bool canPlaySound (SynthesiserSound* sound){
            
        }
    
    //=================================================
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
    {
        
    }
    //==================================================
    
    void stopNote (float velocity, bool allowTailOff)
    {
        
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
        
    }
    //====================================================
    private:
    
};
