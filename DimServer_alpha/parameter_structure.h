#ifndef PARAMETER_STRUCTURE_H
#define PARAMETER_STRUCTURE_H
#include <QString>
#include <QVector>

class Parameter
{
public:
    QString Name;
    int Data;
    int newData;
    bool bReadOnly;

    Parameter(QString,int,bool);

    bool isUpdated();
    bool isReadOnly();
};



class PMChannel
{
public:
    QString Name;
    QVector<Parameter*> vParameter;

    PMChannel(QString);
    ~PMChannel();

    void addParameter(QString,int,bool);
};



class PM
{
public:
    QString Name;
    QVector<PMChannel*> vChannel;

    PM(QString);
    ~PM();

    void addChannel(QString);
};





#endif // PARAMETER_STRUCTURE_H
