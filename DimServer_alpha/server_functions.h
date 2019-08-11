#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H
#include <../Sources/dim_include/dis.hxx>
#include "parameter_structure.h"



class SetParCommand:public DimCommand
{
public:
    Parameter* pPrmr;

    SetParCommand(Parameter*,const char*);

    void commandHandler();
};



//--------------------------------------------------------------------------

void serve_parameter(Parameter*);
void serve_pm(PM*);

#endif // SERVERHANDLER_H

