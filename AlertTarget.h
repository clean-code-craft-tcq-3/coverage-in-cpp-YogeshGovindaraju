#ifndef ALERTTARGET
#define ALERTTARGET

class EmailAlert;

typedef void (EmailAlert::*SendAlert)(const char*);
typedef std::map<BreachType, SendAlert> BreachAlertList;

struct BreachAlert
{
    BreachAlert(BreachAlertList::const_iterator& breachIterator)
     : breachType(breachIterator->first), sendEmailAlert(breachIterator->second) {}
    BreachType breachType;
    SendAlert sendEmailAlert;
};

class AlertTarget
{
    AlertAcknowledgement alertAcknowledgement;
    
    public:
    virtual ~AlertTarget(){}
    virtual void sendAlert(BreachType) = 0;
    
    void setAlertAcknowledgement(AlertAcknowledgement alertAcknowledgement)
    {
        this->alertAcknowledgement = alertAcknowledgement;
    }
    
    AlertAcknowledgement getAlertAcknowledgement()
    {
        return alertAcknowledgement;
    }
};

class ControllerAlert : public AlertTarget
{
    public:
    void sendAlert(BreachType breachType)
    {
        const unsigned short header = 0xfeed;
        std::cout << header << " : " << breachType << std::endl;
        setAlertAcknowledgement(CONTROLLER_ALERT);
    }
};

class EmailAlert : public AlertTarget
{
    public:
    void sendAlert(BreachType breachType)
    {
        const char* recepient = "a.b@c.com";
        BreachAlertList breachAlertList;
        breachAlertList.insert({TOO_LOW, sendTooLowAlert});
        breachAlertList.insert({TOO_HIGH, sendTooHighAlert});
        breachAlertList.insert({NORMAL, sendNormalBreachStatus});
        BreachAlertList::const_iterator breachIterator = breachAlertList.find(breachType);
        assert(breachIterator != breachAlertList.end());
        (this->*(BreachAlert(breachIterator).sendEmailAlert))(recepient);
    }
    
    void sendTooLowAlert(const char* recepient)
    {
        std::cout << "To: " << recepient << std::endl;
        std::cout << "Hi, the temperature is too low\n";
        setAlertAcknowledgement(TOO_LOW_EMAIL_ALERT);
    }
    
    void sendTooHighAlert(const char* recepient)
    {
        std::cout << "To: " << recepient << std::endl;
        std::cout << "Hi, the temperature is too high\n";
        setAlertAcknowledgement(TOO_HIGH_EMAIL_ALERT);
    }
    
    void sendNormalBreachStatus(const char* recepient)
    {
        (void)recepient;
        /* As of now, not required to send Normal Breach status */
        setAlertAcknowledgement(NORMAL_EMAIL_ALERT);
    }
};

#endif