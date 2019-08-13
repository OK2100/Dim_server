#include "parameter_structure.h"

//---------------------------------------------------------

Parameter::Parameter(QString name,int data,bool isreadonly)
{
    Name = name;
    Data = data;
    newData = data;
    bReadOnly = isreadonly;
}

bool Parameter::isUpdated(){
    return (newData!=Data);
}

bool Parameter::isReadOnly(){
    return bReadOnly;
}



//-----------------------------------------------------------

PMChannel::PMChannel(QString name)
{
    Name = name;
    addParameter(Name+"/ADC_ZERO",0,0);
    addParameter(Name+"/ADC_DELAY",0,0);
    addParameter(Name+"/ADC0_OFFSET",0,0);
    addParameter(Name+"/ADC1_OFFSET",0,0);
    addParameter(Name+"/ADC0_RANGE",0,0);
    addParameter(Name+"/ADC1_RANGE",0,0);
    addParameter(Name+"/TIME_ALIN",0,0);

    addParameter(Name+"/ADC0_MEANAMPL",0,1);
    addParameter(Name+"/ADC1_MEANAMPL",0,1);
    addParameter(Name+"/ADC0_ZEROLVL",0,1);
    addParameter(Name+"/ADC1_ZEROLVL",0,1);
    addParameter(Name+"/CFD_CNT",0,1);
    addParameter(Name+"/STROBE_CNT",0,1);
    addParameter(Name+"/MEAN_CNT",0,1);
}

PMChannel::~PMChannel(){
    foreach(Parameter* pPrmr,vParameter){
        delete pPrmr;
    }
}

void PMChannel::addParameter(QString name,int data,bool isreadonly){
    Parameter* pPrmr;
    pPrmr = new Parameter(name,data,isreadonly);
    vParameter.push_back(pPrmr);

}





//---------------------------------------------------------------

PM::PM(QString name)
{
    Name = name;
    addChannel(Name+"/CH01");
    addChannel(Name+"/CH02");
    addChannel(Name+"/CH03");
    addChannel(Name+"/CH04");
    addChannel(Name+"/CH05");
    addChannel(Name+"/CH06");
    addChannel(Name+"/CH07");
    addChannel(Name+"/CH08");
    addChannel(Name+"/CH09");
    addChannel(Name+"/CH10");
    addChannel(Name+"/CH11");
    addChannel(Name+"/CH12");
}

PM::~PM(){
    foreach(PMChannel* pChnl,vChannel){
        delete pChnl;
    }
}

void PM::addChannel(QString name){
    PMChannel* pChnl;
    pChnl = new PMChannel(name);
    vChannel.push_back(pChnl);
}





//----------------------------------------------------------------

