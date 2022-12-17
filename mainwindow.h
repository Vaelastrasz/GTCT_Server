#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dbmanager.h"
#include "insertrecord.h"
#include "logger.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Logger* m_log = Logger::getInstance();

signals:
    void getIDs();

private slots:
    void on_rb_show1d_clicked();

    void on_rb_show1h_clicked();

    void on_rb_show1k_clicked();

    void on_tabs_currentChanged(int index);

    void showEvent(QShowEvent* event);

    void resizeEvent(QResizeEvent* event);

    void on_btn_refresh_clicked();

    void on_btn_addRecord_clicked();

    void setUniqueIDsToCombo(QStringList);

private:
    void startup();
    void fitModelToView();
    void applyAndFitModel(QSqlTableModel*);
    void fillComboIDs();

    DBManager* m_dbHnd;
    InsertRecord* m_insertRecWindow;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
