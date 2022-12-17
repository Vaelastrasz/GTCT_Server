#include "insertrecord.h"
#include "ui_insertrecord.h"

InsertRecord::InsertRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertRecord)
{
    ui->setupUi(this);
}

InsertRecord::~InsertRecord()
{
    delete ui;
}
