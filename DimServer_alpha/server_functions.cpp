#include "server_functions.h"
#include "parameter_structure.h"
#include <QDebug>



SetParCommand::SetParCommand(Parameter* par,const char* format):DimCommand(qPrintable("SET "+par->Name),format){
    pPrmr = par;
};

void SetParCommand::commandHandler(){
    pPrmr->newData = getInt();
//    qDebug() << pPrmr->Name << " " << pPrmr->newData;
}



void serve_parameter(Parameter* pPrmr) {
    if(pPrmr->isReadOnly()){
        DimService* serv = new DimService(qPrintable("GET "+pPrmr->Name),pPrmr->Data);
    }
    else{
        DimService* serv = new DimService(qPrintable("GET "+pPrmr->Name),pPrmr->Data);
        SetParCommand* cmd = new SetParCommand(pPrmr,"I:1");
    }
}


void serve_pm(PM* pm){
    foreach(PMChannel* pChnl,pm->vChannel){
        foreach(Parameter* pPrmr,pChnl->vParameter){
            serve_parameter(pPrmr);
        }
    }

}
