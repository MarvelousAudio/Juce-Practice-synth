/*
  ==============================================================================

    SynthVoice.h
    Created: 31 Jul 2019 10:30:20pm
    Author:  ben haywood

  ==============================================================================
*/
//to do reorder function memebers!

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
    void getParam(float* attack,float* decay,float* sustain, float* release)
    {
        env1.setAttack(double(*attack));
        env1.setDecay(*decay);
        env1.setSustain(*sustain);
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
    
    
    
    void getOscType(float* selection)
    {
        theWave = *selection;
        
        
    }
    //====================================================
    double setOscType()
    {
        if (theWave == 0)
        {
            return osc1.sinewave(frequency);
        }
        if (theWave == 1)
        {
            return osc1.saw(frequency);
        }
        if (theWave == 2)
        {
            return osc1.square(frequency);
        }
        else
        {
            return osc1.sinewave(frequency);
        }
    }
    
    //====================================================
    
    
    double setEnvelope()
    {
        return env1.adsr(setOscType(), env1.trigger) * level;
    }
    //====================================================
    
   
    void getFilterParams(float* filterCutOff, float* filterRes)
    {
    
//        double theSound = env1.adsr(setOscType(), env1.trigger) * level;
//
//       return filter1.lores(theSound, (double)*filterCutOff, (double)*filterRes);
        cutOff = (double)*filterCutOff;
        res = (double)*filterRes;
        DBG("cutoff: \n"<< cutOff);
        DBG("res: \n"<< res);
    }
    
    //====================================================
    double setFilter()
    {
       return filter1.lores(setEnvelope(), cutOff, res);
    }
    
    //====================================================
    void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
    {
        //env1.setAttack(1000);
        //env1.setDecay(500);
        //env1.setSustain(0.8);
//        env1.setRelease(2000);
        
        for (int sample = 0; sample < numSamples; sample++)
        {
            //double theWave = osc1.sinewave(frequency);
            //double theSound = env1.adsr(setOscType(), env1.trigger) * level;
            //double filterSound = filter1.lores(setEnvelope(), cutOff, res);
            
            for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++)
            {
                outputBuffer.addSample(channel, startSample, setFilter());
                
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
    
    int filterChoice;
    float cutOff;
    float res;
    
    int theWave;
//    AudioParameterFloat* mAttackParameter;
//    AudioParameterFloat* mDecayParameter;
//    AudioParameterFloat* mReleaseParameter;
};
