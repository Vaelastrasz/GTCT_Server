#include "insertrecord.h"
#include "ui_insertrecord.h"

InsertRecord::InsertRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertRecord) {

    ui->setupUi(this);
    this->setWindowTitle("Add new device");
}

InsertRecord::~InsertRecord() {

    delete ui;
}

void InsertRecord::on_buttonBox_accepted() {

    DeviceRecord* newRec = new DeviceRecord;
    newRec->uniqueId = ui->edit_uniqueId->text().toInt();
    newRec->uniqueName = ui->edit_uniqueName->text();
    newRec->carNumber = ui->edit_carNumber->text();
    newRec->logFileName = ui->edit_logFileName->text();
    newRec->lastOpenDate = ui->edit_lastOpenDate->dateTime();
    newRec->lastCloseDate = ui->edit_lastCloseDate->dateTime();
    newRec->isNowOpen = ui->check_isNowOpen->isChecked();
    emit insertNewRecord(newRec);

    clearAllEdit();
    delete newRec;
}

void InsertRecord::on_buttonBox_rejected() {

    clearAllEdit();
}

void InsertRecord::clearAllEdit() {

    ui->edit_uniqueId->clear();
    ui->edit_uniqueName->clear();
    ui->edit_carNumber->clear();
    ui->edit_logFileName->clear();

    ui->edit_lastOpenDate->clear();
    ui->edit_lastCloseDate->clear();
    ui->check_isNowOpen->setChecked(false);
}
