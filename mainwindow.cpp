#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <QtHttpServer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QHttpServer httpServer;
    httpServer.route("/", []() {
        return "Hello world";
    });

    const auto port = httpServer.listen(QHostAddress::Any, 11035);
    if (!port) {
        qDebug() << QCoreApplication::translate("QHttpServerExample",
                                                "Server failed to listen on a port.");
    }

    qDebug() << QCoreApplication::translate("QHttpServerExample",
                                            "Running on http://127.0.0.1:%1/ (Press CTRL+C to quit)")
                        .arg(port);
}

MainWindow::~MainWindow()
{
    delete ui;
}

