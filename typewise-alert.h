#ifndef TYPEWISEALERT
#define TYPEWISEALERT

#define PASSIVE_COOLING_LOWER_LIMIT 0
#define PASSIVE_COOLING_UPPER_LIMIT 35
#define HI_ACTIVE_COOLING_LOWER_LIMIT 0
#define HI_ACTIVE_COOLING_UPPER_LIMIT 45
#define MED_ACTIVE_COOLING_LOWER_LIMIT 0
#define MED_ACTIVE_COOLING_UPPER_LIMIT 40

enum BreachType {NORMAL, TOO_LOW, TOO_HIGH};
enum AlertAcknowledgement {CONTROLLER_ALERT, NORMAL_EMAIL_ALERT, TOO_LOW_EMAIL_ALERT, TOO_HIGH_EMAIL_ALERT};

#include <iostream>
#include <map>
#include <assert.h>
#include "AlertTarget.h"
#include "CoolingType.h"

class TypewiseAlert
{
    AlertTarget *alertTarget;
    CoolingType *coolingType;
    BreachType breachType;
    
    public:
    TypewiseAlert(AlertTarget *alertTarget, CoolingType *coolingType, double temperatureInCelsius);
    ~TypewiseAlert();
    AlertTarget* getAlertTargetInstance();
    void setBreachType(BreachType breachType);
    BreachType getBreachType();
    void inferBreach(double temperatureInCelsius);
    void updateBreachForLowerLimit(double temperatureInCelsius);
    void updateBreachForUpperLimit(double temperatureInCelsius);
};
#endif