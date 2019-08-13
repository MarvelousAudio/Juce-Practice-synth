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
    void getParam(float* attack, float* release)
    {
        env1.setAttack(double(*attack));
//        env1.setDecay(500);
//        env1.setSustain(0.8);
        
        env1.setRelease(double(*release));
        
    }
    
    //=================================================
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
    {
        env1.trigger = 1;
        level = velocity;
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
       // std::cout << midiNoteNumber << std::endl;
    }
    //==================================================
    
    void stopNote (float velocity, bool allowTailOff)
    {
        env1.trigger = 0;
        allowTailOff = true;
        if (velocity == 0){
            clearCurrentNote();
            
        }
        //level = 0;
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
        //env1.setAttack(1000);
        env1.setDecay(500);
        env1.setSustain(0.8);
//        env1.setRelease(2000);
        
        for (int sample = 0; sample < numSamples; sample++)
        {
            double theWave = osc1.sinewave(frequency);
            double theSound = env1.adsr(theWave, env1.trigger) * level;
            //double filterSound = filter1.lores(theSound, 50, 0.1);
            
            for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++)
            {
                outputBuffer.addSample(channel, startSample, theSound);
                
            }
            startSample++;
        }
        
    }
    //====================================================
private:
    double level;
    double frequency;
    maxiOsc osc1;
    maxiEnv env1;
    maxiFilter filter1;
    
//    AudioParameterFloat* mAttackParameter;
//    AudioParameterFloat* mDecayParameter;
//    AudioParameterFloat* mReleaseParameter;
};
