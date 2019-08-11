#ifndef PARAMETER_H
#define PARAMETER_H

#include <QString>

class Parameter
{
public:
    QString Name;
    int oldData;
    int newData;

    Parameter(QString,int);

    bool isUpdated();
};

#endif // PARAMETER_H
