#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach for Passive cooling type and Controller alert target")
{
    TypewiseAlert typewiseAlert1(new ControllerAlert(), new PassiveCooling, -1);
    REQUIRE(typewiseAlert1.getBreachType() == TOO_LOW);
    REQUIRE(typewiseAlert1.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert2(new ControllerAlert(), new PassiveCooling, 0);
    REQUIRE(typewiseAlert2.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert2.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert3(new ControllerAlert(), new PassiveCooling, 35);
    REQUIRE(typewiseAlert3.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert3.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert4(new ControllerAlert(), new PassiveCooling, 36);
    REQUIRE(typewiseAlert4.getBreachType() == TOO_HIGH);
    REQUIRE(typewiseAlert4.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
}

TEST_CASE("infers the breach for High active cooling type and Controller alert target")
{
    TypewiseAlert typewiseAlert1(new ControllerAlert(), new HighActiveCooling, -1);
    REQUIRE(typewiseAlert1.getBreachType() == TOO_LOW);
    REQUIRE(typewiseAlert1.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert2(new ControllerAlert(), new HighActiveCooling, 0);
    REQUIRE(typewiseAlert2.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert2.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert3(new ControllerAlert(), new HighActiveCooling, 45);
    REQUIRE(typewiseAlert3.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert3.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert4(new ControllerAlert(), new HighActiveCooling, 46);
    REQUIRE(typewiseAlert4.getBreachType() == TOO_HIGH);
    REQUIRE(typewiseAlert4.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
}

TEST_CASE("infers the breach for Medium active cooling type and Controller alert target")
{
    TypewiseAlert typewiseAlert1(new ControllerAlert(), new MediumActiveCooling, -1);
    REQUIRE(typewiseAlert1.getBreachType() == TOO_LOW);
    REQUIRE(typewiseAlert1.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert2(new ControllerAlert(), new MediumActiveCooling, 0);
    REQUIRE(typewiseAlert2.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert2.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert3(new ControllerAlert(), new MediumActiveCooling, 40);
    REQUIRE(typewiseAlert3.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert3.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
    TypewiseAlert typewiseAlert4(new ControllerAlert(), new MediumActiveCooling, 41);
    REQUIRE(typewiseAlert4.getBreachType() == TOO_HIGH);
    REQUIRE(typewiseAlert4.getAlertTargetInstance()->getAlertAcknowledgement() == CONTROLLER_ALERT);
}

TEST_CASE("infers the breach for Passive cooling type and Email alert target")
{
    TypewiseAlert typewiseAlert1(new EmailAlert(), new PassiveCooling, -1);
    REQUIRE(typewiseAlert1.getBreachType() == TOO_LOW);
    REQUIRE(typewiseAlert1.getAlertTargetInstance()->getAlertAcknowledgement() == TOO_LOW_EMAIL_ALERT);
    TypewiseAlert typewiseAlert2(new EmailAlert(), new PassiveCooling, 0);
    REQUIRE(typewiseAlert2.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert2.getAlertTargetInstance()->getAlertAcknowledgement() == NORMAL_EMAIL_ALERT);
    TypewiseAlert typewiseAlert3(new EmailAlert(), new PassiveCooling, 35);
    REQUIRE(typewiseAlert3.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert3.getAlertTargetInstance()->getAlertAcknowledgement() == NORMAL_EMAIL_ALERT);
    TypewiseAlert typewiseAlert4(new EmailAlert(), new PassiveCooling, 36);
    REQUIRE(typewiseAlert4.getBreachType() == TOO_HIGH);
    REQUIRE(typewiseAlert4.getAlertTargetInstance()->getAlertAcknowledgement() == TOO_HIGH_EMAIL_ALERT);
}

TEST_CASE("infers the breach for High active cooling type and Email alert target")
{
    TypewiseAlert typewiseAlert1(new EmailAlert(), new HighActiveCooling, -1);
    REQUIRE(typewiseAlert1.getBreachType() == TOO_LOW);
    REQUIRE(typewiseAlert1.getAlertTargetInstance()->getAlertAcknowledgement() == TOO_LOW_EMAIL_ALERT);
    TypewiseAlert typewiseAlert2(new EmailAlert(), new HighActiveCooling, 0);
    REQUIRE(typewiseAlert2.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert2.getAlertTargetInstance()->getAlertAcknowledgement() == NORMAL_EMAIL_ALERT);
    TypewiseAlert typewiseAlert3(new EmailAlert(), new HighActiveCooling, 45);
    REQUIRE(typewiseAlert3.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert3.getAlertTargetInstance()->getAlertAcknowledgement() == NORMAL_EMAIL_ALERT);
    TypewiseAlert typewiseAlert4(new EmailAlert(), new HighActiveCooling, 46);
    REQUIRE(typewiseAlert4.getBreachType() == TOO_HIGH);
    REQUIRE(typewiseAlert4.getAlertTargetInstance()->getAlertAcknowledgement() == TOO_HIGH_EMAIL_ALERT);
}

TEST_CASE("infers the breach for Medium active cooling type and Email alert target")
{
    TypewiseAlert typewiseAlert1(new EmailAlert(), new MediumActiveCooling, -1);
    REQUIRE(typewiseAlert1.getBreachType() == TOO_LOW);
    REQUIRE(typewiseAlert1.getAlertTargetInstance()->getAlertAcknowledgement() == TOO_LOW_EMAIL_ALERT);
    TypewiseAlert typewiseAlert2(new EmailAlert(), new MediumActiveCooling, 0);
    REQUIRE(typewiseAlert2.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert2.getAlertTargetInstance()->getAlertAcknowledgement() == NORMAL_EMAIL_ALERT);
    TypewiseAlert typewiseAlert3(new EmailAlert(), new MediumActiveCooling, 40);
    REQUIRE(typewiseAlert3.getBreachType() == NORMAL);
    REQUIRE(typewiseAlert3.getAlertTargetInstance()->getAlertAcknowledgement() == NORMAL_EMAIL_ALERT);
    TypewiseAlert typewiseAlert4(new EmailAlert(), new MediumActiveCooling, 41);
    REQUIRE(typewiseAlert4.getBreachType() == TOO_HIGH);
    REQUIRE(typewiseAlert4.getAlertTargetInstance()->getAlertAcknowledgement() == TOO_HIGH_EMAIL_ALERT);
}
