#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "parameter_structure.h"
#include "server_functions.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    char dnsNode[80] = "localhost.localdomain";
    char ServerName[80] = "DimServer";
    DimServer::setDnsNode(dnsNode);

    PM pm1("PM1");
    PM pm2("PM2");
    PM pm3("PM3");

//    serve_parameter(pm1.VecChnls[0]->VecPrmrs[0]);
//    serve_parameter(pm1.vChannel[1]->vParameter[3]);
    serve_pm(&pm1);
    serve_pm(&pm2);
    serve_pm(&pm3);


    DimServer::start(ServerName);

    return a.exec();
}
