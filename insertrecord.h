#ifndef INSERTRECORD_H
#define INSERTRECORD_H

#include <QDialog>
#include "globalscope.h"

namespace Ui {
class InsertRecord;
}

class InsertRecord : public QDialog
{
    Q_OBJECT

public:
    explicit InsertRecord(QWidget *parent = 0);
    ~InsertRecord();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

signals:
    void insertNewRecord(DeviceRecord*);

protected:
    void clearAllEdit();

private:
    Ui::InsertRecord *ui;
};

#endif // INSERTRECORD_H
