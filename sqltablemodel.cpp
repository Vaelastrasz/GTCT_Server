#include "sqltablemodel.h"

SqlTableModel::SqlTableModel(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db) {

    m_limit = -1;
}

int SqlTableModel::limit() const {

    return m_limit;
}

void SqlTableModel::setLimit(int newLimit) {

    if(newLimit > 0) {
        m_limit = newLimit;
    }
}

bool SqlTableModel::addNewRecord(DeviceRecord* rec) {

    QSqlRecord newRecord = record();
    newRecord.setValue("uniqueId", rec->uniqueId);
    newRecord.setValue("uniqueName", rec->uniqueName);
    newRecord.setValue("carNumber", rec->carNumber);
    newRecord.setValue("logFileName", rec->logFileName);
    newRecord.setValue("lastOpenDate", QDateTime::currentDateTime());
    newRecord.setValue("lastCloseDate", QDateTime::currentDateTime());
    newRecord.setValue("isNowOpen", rec->isNowOpen);

    if (insertRecord(rowCount(), newRecord)) {
        qDebug() << "New record inserted";
        return true;
    }

    return false;
}

QString SqlTableModel::selectStatement() const {

    QString query = QSqlTableModel::selectStatement();
    if(m_limit > 0)
        query += QString(" LIMIT %1").arg(m_limit);
    return query;
}
