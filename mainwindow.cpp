#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_dbHnd(new DBManager()),
    m_insertRecWindow(new InsertRecord),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
}

MainWindow::~MainWindow() {

    if (m_dbHnd) {
        delete m_dbHnd;
    }
    delete ui;
}

void MainWindow::startup() {

    this->setWindowTitle(TEXT("GTCT v1.0"));

    connect(m_insertRecWindow, &InsertRecord::insertNewRecord, m_dbHnd, &DBManager::addNewRecord);
    connect(m_insertRecWindow, &InsertRecord::insertNewRecord, this, &MainWindow::on_btn_refresh_clicked);
    connect(this, &MainWindow::getIDs, m_dbHnd, &DBManager::processDevicesIDRequest);
    connect(m_dbHnd, &DBManager::sendDevicesID, this, &MainWindow::setUniqueIDsToCombo);

    on_rb_show1k_clicked();
}

void MainWindow::fitModelToView() {

    int colCnt;
    if (!UI_MODEL)
        return;
    colCnt = UI_MODEL->columnCount();
    int* tableSizeArray = new int[colCnt];
    UI_TABLE->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < colCnt - 1; i++) {
        tableSizeArray[i] = UI_TABLE->horizontalHeader()->sectionSize(i);
    }

    UI_TABLE->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    for (int i = 0; i < colCnt - 1; i++) {
        emit UI_TABLE->horizontalHeader()->sectionResized(i, 0, tableSizeArray[i]);
    }

    delete[] tableSizeArray;
}

void MainWindow::applyAndFitModel(QSqlTableModel* model) {

    if (!model) return;
    UI_TABLE->setModel(model);
    fitModelToView();
}

void MainWindow::fillComboIDs() {

    emit getIDs();
}

void MainWindow::on_rb_show1d_clicked() {

    m_dbHnd->setShowRecCounter(ui->rb_show1d->text().toInt());
    applyAndFitModel(m_dbHnd->getLastRecordsModel());
}

void MainWindow::on_rb_show1h_clicked() {

    m_dbHnd->setShowRecCounter(ui->rb_show1h->text().toInt());
    applyAndFitModel(m_dbHnd->getLastRecordsModel());
}

void MainWindow::on_rb_show1k_clicked() {

    m_dbHnd->setShowRecCounter(ui->rb_show1k->text().toInt());
    applyAndFitModel(m_dbHnd->getLastRecordsModel());
}

void MainWindow::on_tabs_currentChanged(int index) {

    if (index == 0) {
        applyAndFitModel(m_dbHnd->getLastRecordsModel());
    }
    if (index == 1) {
        fillComboIDs();
    }
}

void MainWindow::showEvent(QShowEvent *event) {

    Q_UNUSED(event);
    startup();
}

void MainWindow::resizeEvent(QResizeEvent *event) {

    QMainWindow::resizeEvent(event);
    fitModelToView();
}

void MainWindow::on_btn_refresh_clicked() {

    applyAndFitModel(m_dbHnd->getLastRecordsModel());
}

void MainWindow::on_btn_addRecord_clicked() {

    fillComboIDs();

    m_insertRecWindow->setModal(true);
    m_insertRecWindow->exec();
}

void MainWindow::setUniqueIDsToCombo(QStringList names) {

    ui->combo_deviceId->clear();
    ui->combo_deviceId->addItems(names);
}
