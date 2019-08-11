#ifndef PMCHANNEL_H
#define PMCHANNEL_H
#include "parameter.h"
#include <QVector>

class PMChannel
{
public:
    QString Name;
    QVector<Parameter*> VecPrmrs;

    PMChannel(QString);
    ~PMChannel();

    void addParameter(QString,int);
};

#endif // PMCHANNEL_H
