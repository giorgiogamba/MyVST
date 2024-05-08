/*
  ==============================================================================

    ADSR.h
    Created: 6 May 2024 4:47:45pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

enum ADSRStatus
{
    NONE,
    Attack,
    Decay,
    Sustain,
    Release
};

/**
 * Represents an ADSR envelope
 */
class ADSREnvelope
{
public:
    
    ADSREnvelope()
    {
        sampleRate = 0.0f;
        
        value = 0.0f;
        
        status = ADSRStatus::NONE;
        
        sustainCount = 0;
        
        attackTime = 0.0f;
        decayTime = 0.0f;
        sustainTime = 0.0f;
        releaseTime = 0.0f;
        
        attackRate = 0.f;
        decayRate = 0.f;
        releaseRate = 0.f;
        
        sustainAmount = 0.f;
    }
    
    ADSREnvelope
    ( const float inSampleRate
    , const float inAttackTime
    , const float inDecayTime
    , const float inSustainTime
    , const float inReleaseTime
    , const float inSustainAmount )
    : sampleRate(inSampleRate)
    , attackTime(inAttackTime)
    , decayTime(inDecayTime)
    , sustainTime(inSustainTime)
    , releaseTime(inReleaseTime)
    , sustainAmount(inSustainAmount)
    {
        value = 0.f;
        status = ADSRStatus::NONE;
        sustainCount = 0;
        attackRate = 0.f;
        decayRate = 0.f;
        releaseRate = 0.f;
        
        updateRates();
    }
    
    /** Starts the ADSR envelope*/
    void noteOn();
    
    /** Ends the ADSR envelope*/
    void noteOff();
    
    /** Goes to the next envelope status */
    void goToNextStatus();
    
    void setSampleRate(const float inSampleRate) { sampleRate = inSampleRate; }
    
    /** Computes the different amount of gain to assign to the buffer in each step of the envelope based on times */
    float computeRate(const float amount, const float time) const;
    
    /** Computes the envelope phases' rates based on configuration values */
    void updateRates();
    
    /** Returns the next value of the envelope based on status*/
    float getNextSample();
    
    void reset();
    
private:
    
    float sampleRate;
    
    ADSRStatus status;
    
    // value assumed by the envelope in a certain time stamp
    float value;
    
    float attackTime;
    float decayTime;
    float sustainTime;
    float releaseTime;
    
    int sustainCount;
    
    float attackRate;
    float decayRate;
    float releaseRate;
    
    float sustainAmount;
    
};
