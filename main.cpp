#include "mainwindow.h"

#include <QApplication>
#include <QtCore>
#include <QtHttpServer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QHttpServer httpServer;
    httpServer.route("/", []() {
        return "true";
    });
    httpServer.listen(QHostAddress::Any, 4986);
    qDebug() << "Running on http://127.0.0.1:4986/ (Press CTRL+C to quit)";

    return a.exec();
}
