#ifndef COOLINGTYPE
#define COOLINGTYPE

class CoolingType
{
    int lowerLimit;
    int upperLimit;
    
    public:
    CoolingType()
    {
        lowerLimit = 0;
        upperLimit = 0;
    }
    
    virtual ~CoolingType(){}
    
    void setLowerLimit(int limit)
    {
        lowerLimit = limit;
    }
    
    int getLowerLimit()
    {
        return lowerLimit;
    }
    
    void setUpperLimit(int limit)
    {
        upperLimit = limit;
    }
    
    int getUpperLimit()
    {
        return upperLimit;
    }
    
    virtual void updateLimit() = 0;
};

class PassiveCooling : public CoolingType
{
    public:
    void updateLimit()
    {
        setLowerLimit(PASSIVE_COOLING_LOWER_LIMIT);
        setUpperLimit(PASSIVE_COOLING_UPPER_LIMIT);
    }
};

class HighActiveCooling : public CoolingType
{
    public:
    void updateLimit()
    {
        setLowerLimit(HI_ACTIVE_COOLING_LOWER_LIMIT);
        setUpperLimit(HI_ACTIVE_COOLING_UPPER_LIMIT);
    }
};

class MediumActiveCooling : public CoolingType
{
    public:
    void updateLimit()
    {
        setLowerLimit(MED_ACTIVE_COOLING_LOWER_LIMIT);
        setUpperLimit(MED_ACTIVE_COOLING_UPPER_LIMIT);
    }
};

#endif