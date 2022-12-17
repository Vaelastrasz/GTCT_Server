#ifndef LOGGER_H
#define LOGGER_H

#include "globalscope.h"
#include <QTextBrowser>

enum LogLevel {
    llInformation,
    llDebug,
    llError,
    llSuccess
};

class Logger
{
private:
    Logger() {}
    Logger(const Logger*) = delete;
    void operator =(const Logger&) = delete;
    virtual ~Logger();

    QTextBrowser* m_textWidget;
    QFile m_logFile;
    static Logger* m_instance;

public:
    static Logger* getInstance();
    bool setLogFile(QString filePath);
    bool setLogBrowser(QWidget* widget);
    void addToFileLog(QString message, LogLevel logLvl);
    void addToLog(QString message, LogLevel logLvl);
};



#endif // LOGGER_H
