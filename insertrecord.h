#ifndef INSERTRECORD_H
#define INSERTRECORD_H

#include <QDialog>

namespace Ui {
class InsertRecord;
}

class InsertRecord : public QDialog
{
    Q_OBJECT

public:
    explicit InsertRecord(QWidget *parent = nullptr);
    ~InsertRecord();

private:
    Ui::InsertRecord *ui;
};

#endif // INSERTRECORD_H
