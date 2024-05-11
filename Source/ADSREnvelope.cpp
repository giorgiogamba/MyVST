/*
  ==============================================================================

    ADSR.cpp
    Created: 6 May 2024 4:47:45pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#include "ADSREnvelope.h"

/** Starts the ADSR envelope*/
void ADSREnvelope::noteOn()
{
    status = ADSRStatus::Attack;
}

/** Ends the ADSR envelope*/
void ADSREnvelope::noteOff()
{
    reset();
}

void ADSREnvelope::goToNextStatus()
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

/** Computes the different amount of gain to assign to the buffer in each step of the envelope based on times */
float ADSREnvelope::computeRate(const float amount, const float time) const
{
    return amount / (time * sampleRate);
}

void ADSREnvelope::updateRates()
{
    attackRate = computeRate(1.f, attackTime);
    decayRate = computeRate(1.f - sustainAmount, decayTime);
    releaseRate = computeRate(sustainTime, releaseTime);
}

/** Returns the next value of the envelope based on status*/
float ADSREnvelope::getNextSample()
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

void ADSREnvelope::reset()
{
    value = 0.f;
    sustainCount = 0;
    status = ADSRStatus::NONE;
}

void ADSREnvelope::setAttackTime(const float inValue)
{
    attackTime = inValue;
    updateRates();
}

void ADSREnvelope::setDecayTime(const float inDecay)
{
    decayTime = inDecay;
    updateRates();
}

void ADSREnvelope::setSustainTime(const float inSustain)
{
    sustainTime = inSustain;
    updateRates();
}

void ADSREnvelope::setReleaseTime(const float inRelease)
{
    releaseTime = inRelease;
    updateRates();
}
