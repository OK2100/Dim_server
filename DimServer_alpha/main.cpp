#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "parameter_structure.h"
#include "server_functions.h"
#include <QProcess>
#include <QProcessEnvironment>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QProcess DNS;
    QProcess WebDid;
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();

    QString node = env.value("HOSTNAME");
//    QString node = "192.168.0.102";

    env.insert("DIM_HOST_NODE",node);
    env.insert("DIM_DNS_NODE",node);
    DNS.setProcessEnvironment(env);
    WebDid.setProcessEnvironment(env);
    DNS.start("../Sources/dns");
    WebDid.start("../Sources/did");

    char ServerName[80] = "DimServer";
    DimServer::setDnsNode(qPrintable(node));

    PM pm1("PM1");
    PM pm2("PM2");
    PM pm3("PM3");

//    serve_parameter(pm1.vChannel[1]->vParameter[3]);
    serve_pm(&pm1);
    serve_pm(&pm2);
    serve_pm(&pm3);

    DimServer::start(ServerName);

    return a.exec();
    DNS.close();
    WebDid.close();
}
