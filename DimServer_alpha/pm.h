#ifndef PM_H
#define PM_H
#include "pmchannel.h"

class PM
{
public:
    QString Name;
    QVector<PMChannel*> VecChnls;

    PM(QString);
    ~PM();

    void addChannel(QString);
};

#endif // PM_H
