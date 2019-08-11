#include "pm.h"

PM::PM(QString name)
{
    Name = name;
    addChannel("CHANNEL 1");
    addChannel("CHANNEL 2");
    addChannel("CHANNEL 3");
}

PM::~PM(){
    foreach(PMChannel* pChnl,VecChnls){
        delete pChnl;
    }
}

void PM::addChannel(QString name){
    PMChannel* pChnl;
    pChnl = new PMChannel(name);
    VecChnls.push_back(pChnl);
}
