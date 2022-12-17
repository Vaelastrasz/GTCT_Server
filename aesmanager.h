#ifndef AESMANAGER_H
#define AESMANAGER_H

#include "globalscope.h"
#include <openssl/engine.h>
#include <openssl/pem.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

class AESManager : public QObject
{
    Q_OBJECT
public:
    AESManager();
    ~AESManager();
    void startup();
    QByteArray encryptAES(QByteArray passphrase, QByteArray &data);
    QByteArray decryptAES(QByteArray passphrase, QByteArray &data);
    QByteArray randomBytes(int size);
    QByteArray m_iv;
    QByteArray m_key;
};

#endif // AESMANAGER_H
