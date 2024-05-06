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
    void noteOn()
    {
        status = ADSRStatus::Attack;
    }
    
    /** Ends the ADSR envelope*/
    void noteOff()
    {
        reset();
    }
    
    void goToNextStatus()
    {
        switch (status) {
            case ADSRStatus::Attack:
                status = ADSRStatus::Decay;
                break;
                
            case ADSRStatus::Decay:
                status = ADSRStatus::Sustain;
                break;
                
            case ADSRStatus::Sustain:
                status = ADSRStatus::Release;
                break;
                
            case ADSRStatus::Release:
                status = ADSRStatus::NONE;
                break;
                
            default:
                status = ADSRStatus::NONE;
                break;
        }
    }
    
    void setSampleRate(const float inSampleRate) { sampleRate = inSampleRate; }
    
    void applyToBuffer(AudioBuffer<float>& buffer, int startSample, int numSamples)
    {
        for (int sample = 0; sample < numSamples; ++sample)
        {
            for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
            {
                buffer.getWritePointer(channel)[startSample] *= getNextSample();
            }
            
            ++startSample;
        }
    }
    
    /** Computes the different amount of gain to assign to the buffer in each step of the envelope based on times */
    float computeRate(const float amount, const float time) const
    {
        return amount / (time * sampleRate);
    }
    
    void updateRates()
    {
        attackRate = computeRate(1.f, attackTime);
        decayRate = computeRate(1.f - sustainAmount, decayTime);
        releaseRate = computeRate(sustainTime, releaseTime);
    }
    
    /** Returns the next value of the envelope based on status*/
    float getNextSample()
    {
        if (status == ADSRStatus::Attack)
        {
            value += attackRate;
            if (value >= 1.f) // Attack path completed
            {
                value = 1.f;
                goToNextStatus();
            }
        }
        else if (status == ADSRStatus::Decay)
        {
            value -= decayRate;
            if (value <= sustainAmount)
            {
                value = sustainAmount;
                goToNextStatus();
            }
        }
        else if (status == Sustain)
        {
            value = sustainAmount;
            sustainCount ++;
            if (sustainCount == sustainTime * sampleRate)
            {
                goToNextStatus();
            }
        }
        else if (status == ADSRStatus::Release)
        {
            value -= releaseRate;
            if (value <= 0.f)
            {
                value = 0.f;
                goToNextStatus();
            }
        }
        
        return value;
    }
    
    void reset()
    {
        value = 0.f;
        sustainCount = 0;
        status = ADSRStatus::NONE;
    }
    
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
