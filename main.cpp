#include "mainwindow.h"

#include <QApplication>
#include <QtCore>
#include <QtHttpServer>
#include "aesmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QHttpServer httpServer;
    httpServer.route("/", []() {
        return "encrypted";
    });

    httpServer.route("/commands/", [](QString encrypted) {
        AESManager manager;
        QByteArray raw = manager.decryptAES(_passphrase.toLatin1(), encrypted.toLatin1());
        QByteArray response;
        int retcode = Parser::parseCmdAndCheck(raw);
        if (retcode) {
            Logger::parseToLog(raw);
            response = RSPTrue;
        } else {
            response = RSPFalse;
        }
        return QString("%1").arg(response);
    });

    httpServer.listen(QHostAddress::Any, 4986);
    qDebug() << "Running on http://127.0.0.1:4986/ (Press CTRL+C to quit)";

    return a.exec();
}
