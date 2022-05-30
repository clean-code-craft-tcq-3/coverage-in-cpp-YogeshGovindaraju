#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach for Passive cooling type and Controller alert target")
{
    ControllerAlert controllerAlert;
    PassiveCooling passiveCooling;
    TypewiseAlert typewiseAlert1(&controllerAlert, &passiveCooling, -1);
    REQUIRE(typewiseAlert1.getBreachType() == TOO_LOW);
    REQUIRE(typewiseAlert1.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert2(&controllerAlert, &passiveCooling, 0);
    REQUIRE(typewiseAlert2.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert2.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert3(&controllerAlert, &passiveCooling, 35);
    REQUIRE(typewiseAlert3.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert3.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert4(&controllerAlert, &passiveCooling, 36);
    REQUIRE(typewiseAlert4.getBreachType() == TOO_HIGH);
    REQUIRE(typewiseAlert4.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
}

TEST_CASE("infers the breach for High active cooling type and Controller alert target")
{
    ControllerAlert controllerAlert;
    HighActiveCooling highActiveCooling;
    TypewiseAlert typewiseAlert1(&controllerAlert, &highActiveCooling, -1);
    REQUIRE(typewiseAlert1.getBreachType() == TOO_LOW);
    REQUIRE(typewiseAlert1.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert2(&controllerAlert, &highActiveCooling, 0);
    REQUIRE(typewiseAlert2.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert2.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert3(&controllerAlert, &highActiveCooling, 45);
    REQUIRE(typewiseAlert3.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert3.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert4(&controllerAlert, &highActiveCooling, 46);
    REQUIRE(typewiseAlert4.getBreachType() == TOO_HIGH);
    REQUIRE(typewiseAlert4.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
}

TEST_CASE("infers the breach for Medium active cooling type and Controller alert target")
{
    ControllerAlert controllerAlert;
    MediumActiveCooling mediumActiveCooling;
    TypewiseAlert typewiseAlert1(&controllerAlert, &mediumActiveCooling, -1);
    REQUIRE(typewiseAlert1.getBreachType() == TOO_LOW);
    REQUIRE(typewiseAlert1.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert2(&controllerAlert, &mediumActiveCooling, 0);
    REQUIRE(typewiseAlert2.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert2.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert3(&controllerAlert, &mediumActiveCooling, 40);
    REQUIRE(typewiseAlert3.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert3.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert4(&controllerAlert, &mediumActiveCooling, 41);
    REQUIRE(typewiseAlert4.getBreachType() == TOO_HIGH);
    REQUIRE(typewiseAlert4.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
}

TEST_CASE("infers the breach for Passive cooling type and Email alert target")
{
    EmailAlert emailAlert;
    PassiveCooling passiveCooling;
    TypewiseAlert typewiseAlert1(&emailAlert, &passiveCooling, -1);
    REQUIRE(typewiseAlert1.getBreachType() == TOO_LOW);
    REQUIRE(typewiseAlert1.getAlertTargetInstance()->getAlertAcknowledgement() == TOO_LOW_EMAIL_ALERT);
    TypewiseAlert typewiseAlert2(&emailAlert, &passiveCooling, 0);
    REQUIRE(typewiseAlert2.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert2.getAlertTargetInstance()->getAlertAcknowledgement() == NORMAL_EMAIL_ALERT);
    TypewiseAlert typewiseAlert3(&emailAlert, &passiveCooling, 35);
    REQUIRE(typewiseAlert3.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert3.getAlertTargetInstance()->getAlertAcknowledgement() == NORMAL_EMAIL_ALERT);
    TypewiseAlert typewiseAlert4(&emailAlert, &passiveCooling, 36);
    REQUIRE(typewiseAlert4.getBreachType() == TOO_HIGH);
    REQUIRE(typewiseAlert4.getAlertTargetInstance()->getAlertAcknowledgement() == TOO_HIGH_EMAIL_ALERT);
}

TEST_CASE("infers the breach for High active cooling type and Email alert target")
{
    EmailAlert emailAlert;
    HighActiveCooling highActiveCooling;
    TypewiseAlert typewiseAlert1(&emailAlert, &highActiveCooling, -1);
    REQUIRE(typewiseAlert1.getBreachType() == TOO_LOW);
    REQUIRE(typewiseAlert1.getAlertTargetInstance()->getAlertAcknowledgement() == TOO_LOW_EMAIL_ALERT);
    TypewiseAlert typewiseAlert2(&emailAlert, &highActiveCooling, 0);
    REQUIRE(typewiseAlert2.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert2.getAlertTargetInstance()->getAlertAcknowledgement() == NORMAL_EMAIL_ALERT);
    TypewiseAlert typewiseAlert3(&emailAlert, &highActiveCooling, 45);
    REQUIRE(typewiseAlert3.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert3.getAlertTargetInstance()->getAlertAcknowledgement() == NORMAL_EMAIL_ALERT);
    TypewiseAlert typewiseAlert4(&emailAlert, &highActiveCooling, 46);
    REQUIRE(typewiseAlert4.getBreachType() == TOO_HIGH);
    REQUIRE(typewiseAlert4.getAlertTargetInstance()->getAlertAcknowledgement() == TOO_HIGH_EMAIL_ALERT);
}

TEST_CASE("infers the breach for Medium active cooling type and Email alert target")
{
    EmailAlert emailAlert;
    MediumActiveCooling mediumActiveCooling;
    TypewiseAlert typewiseAlert1(&emailAlert, &mediumActiveCooling, -1);
    REQUIRE(typewiseAlert1.getBreachType() == TOO_LOW);
    REQUIRE(typewiseAlert1.getAlertTargetInstance()->getAlertAcknowledgement() == TOO_LOW_EMAIL_ALERT);
    TypewiseAlert typewiseAlert2(&emailAlert, &mediumActiveCooling, 0);
    REQUIRE(typewiseAlert2.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert2.getAlertTargetInstance()->getAlertAcknowledgement() == NORMAL_EMAIL_ALERT);
    TypewiseAlert typewiseAlert3(&emailAlert, &mediumActiveCooling, 40);
    REQUIRE(typewiseAlert3.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert3.getAlertTargetInstance()->getAlertAcknowledgement() == NORMAL_EMAIL_ALERT);
    TypewiseAlert typewiseAlert4(&emailAlert, &mediumActiveCooling, 41);
    REQUIRE(typewiseAlert4.getBreachType() == TOO_HIGH);
    REQUIRE(typewiseAlert4.getAlertTargetInstance()->getAlertAcknowledgement() == TOO_HIGH_EMAIL_ALERT);
}
