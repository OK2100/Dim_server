#include "parameter.h"

Parameter::Parameter(QString name,int data)
{
    Name = name;
    oldData = data;
    newData = data;
}

bool Parameter::isUpdated(){
    return (newData!=oldData);
}
