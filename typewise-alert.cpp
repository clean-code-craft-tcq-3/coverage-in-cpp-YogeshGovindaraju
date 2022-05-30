#include "typewise-alert.h"

TypewiseAlert::TypewiseAlert(AlertTarget *alertTarget, CoolingType *coolingType, double temperatureInCelsius)
{
    this->alertTarget = alertTarget;
    this->coolingType = coolingType;
    coolingType->updateLimit();
    inferBreach(temperatureInCelsius);
    alertTarget->sendAlert(getBreachType());
}

AlertTarget* TypewiseAlert::getAlertTargetInstance()
{
    return alertTarget;
}

void TypewiseAlert::setBreachType(BreachType breachType)
{
    this->breachType = breachType;
}

BreachType TypewiseAlert::getBreachType()
{
    return breachType;
}

void TypewiseAlert::inferBreach(double temperatureInCelsius)
{
    setBreachType(NORMAL);
    updateBreachForLowerLimit(temperatureInCelsius);
    updateBreachForUpperLimit(temperatureInCelsius);
}

void TypewiseAlert::updateBreachForLowerLimit(double temperatureInCelsius)
{
    if(temperatureInCelsius < coolingType->getLowerLimit())
    {
        setBreachType(TOO_LOW);
    }
}

void TypewiseAlert::updateBreachForUpperLimit(double temperatureInCelsius)
{
    if(temperatureInCelsius > coolingType->getUpperLimit())
    {
        setBreachType(TOO_HIGH);
    }
}