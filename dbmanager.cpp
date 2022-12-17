#include "dbmanager.h"

DBManager::DBManager() : m_showRecCounter(0),
  m_db(QSqlDatabase::addDatabase("QSQLITE")) {

    if (QFile::exists(DBCurrentPath)) {
        m_db.setDatabaseName(DBCurrentPath);
    }

    if (!m_db.open()) {
        qDebug() << TEXT("Error: the connection to the database failed");
    } else {
        qDebug() << TEXT("Database: conection ok");
    }

    m_currentModel = new SqlTableModel(this, m_db);
    m_currentModel->setTable("GTCTGeneral");
    m_currentModel->setEditStrategy(QSqlTableModel::OnRowChange);
    m_currentModel->setLimit(showRecCounter());
    m_currentModel->sort(4, Qt::DescendingOrder); //sort by date desc
}

DBManager::~DBManager() {

    if (m_db.isOpen()) {
        m_db.close();
    }
    if (m_currentModel) {
        delete m_currentModel;
    }
}

int DBManager::showRecCounter() const {

    return m_showRecCounter;
}

void DBManager::setShowRecCounter(int showRecCounter) {

    m_showRecCounter = showRecCounter;
}

QSqlTableModel* DBManager::getLastRecordsModel() {

    m_currentModel->setLimit(m_showRecCounter);
    if (m_currentModel->select()) {
        return m_currentModel;
    } else {
        qDebug() << "Error selecting values";
        return nullptr;
    }
}

void DBManager::addNewRecord(DeviceRecord *rec) {

    m_currentModel->addNewRecord(rec);
}

void DBManager::processDevicesIDRequest() {

    QStringList ids;
    for (int idx = 0; idx < m_currentModel->rowCount(); idx++) {
        QString currentName = m_currentModel->record(idx).value("uniqueId").toString();
        if (!ids.contains(currentName)) {
            ids.append(currentName);
        }
    }

    emit sendDevicesID(ids);
}
