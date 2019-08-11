#include "pmchannel.h"

PMChannel::PMChannel(QString name)
{
    Name = name;
    addParameter("PMCH_ADC_ZERO",0);
    addParameter("PMCH_ADC_DELAY",0);
    addParameter("PMCH_ADC0_OFFSET",0);
}

PMChannel::~PMChannel(){
    foreach(Parameter* pPrmr,VecPrmrs){
        delete pPrmr;
    }
}

void PMChannel::addParameter(QString name,int data){
    Parameter* pPrmr;
    pPrmr = new Parameter(name,data);
    VecPrmrs.push_back(pPrmr);
}

