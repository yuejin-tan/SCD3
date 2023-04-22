#include "winauthoriation.h"

#include <QtCore/QCryptographicHash>
#include <QtCore/QSettings>
#include <QtCore/QDebug>
#include <QtCore/QFile>

#include<openssl/rsa.h>
#include<openssl/pem.h>
#include<openssl/err.h>
#include<openssl/bio.h>
#include<openssl/evp.h>

static char pubKey[] = R"RSA_PUB(
-----BEGIN PUBLIC KEY-----
MIICIjANBgkqhkiG9w0BAQEFAAOCAg8AMIICCgKCAgEAwmU8fxHDNloWU77u0bUn
ROg6pBU5rlq56GLfST6+Oee51suGZK4gggm4S/Xf72RxEgVuKCFkZdexrecplhs8
ONJKDgkMJA8UlPXKuJ6rc7GL0ZftOjfqXg/FsCniJJ+GT9tllpZoDxiltmXAIx9z
+waqwJOKBblAgteukFkcIjHTQ99N2rIbfx3Gde3j+wyMHjxuilQF6DUpFmkuQ9Ae
yOriZwk2Y2Wf7/7tVnQTlNyBkRETHO9KBMzbAo5Bj81ajLBHk43eoPvZbMEd8Hgv
3cO0UhUXHly/vsSFMlJ29WdvL6ocVW0V0otaDUVWyiARjoET1GPHCJDWulR6kU9V
uA3ODES6u3uwvgtagtgSrDYgQF46fiJE0LciW1VWSSErzJEo9nDBOO8uWCOVjE4h
Vm2CULCuGRVZM7C05OTKKU4RB0c0srvdwip2GiW7COGe9R9uhLO9CrNOeuVR10Ah
bbqqXaxCGgvuychlEj17sbkJpgvDkGSQKUPqVShUgxDImmDIqex1X1HwOjH///dd
rvK1eonMQJhcKW+7kjTc+RIAS/y5417AmvMfHtOORO/kERtEUiSlFPZokQTVYdtC
pxSPFfXx0qutijoNqOsxraYGu+rDvrwY67UcnP1hXJZMMA71gn92sMO1oAXHPZ1F
MdduPO9TswxTgqhcxgRj0F0CAwEAAQ==
-----END PUBLIC KEY-----

)RSA_PUB";

static QByteArray RsaPubDecWrap(QByteArray data2Dec)
{
    QByteArray decrypt_text;
    BIO* keybio = BIO_new_mem_buf((unsigned char*)pubKey, -1);
    RSA* rsa = RSA_new();
    char* text = NULL;
    int len = 0;
    int ret = 0;

    // rsa = PEM_read_bio_RSAPublicKey(keybio, &rsa, NULL, NULL);
    rsa = PEM_read_bio_RSA_PUBKEY(keybio, &rsa, NULL, NULL);
    if (!rsa)
    {
        unsigned long err = ERR_get_error(); //获取错误号
        char err_msg[1024] = { 0 };
        ERR_error_string(err, err_msg);
        qDebug() << "Num:" << err << " : " << err_msg;

        goto end_RsaPubDecWrap;
    }

    len = RSA_size(rsa);
    text = new char[len + 1];
    memset(text, 0, len + 1);

    // 对密文进行解密
    ret = RSA_public_decrypt(data2Dec.length(), (const unsigned char*)data2Dec.data(), (unsigned char*)text, rsa, RSA_PKCS1_PADDING);
    if (ret >= 0) {
        decrypt_text = QByteArray(text, ret);
    }

end_RsaPubDecWrap:
    // 释放内存
    delete[] text;
    BIO_free_all(keybio);
    RSA_free(rsa);

    return decrypt_text;
}

winAuthoriation::winAuthoriation(QObject* parent)
    : QObject{ parent }
{
    // 指定注册表路径及格式
    static QSettings regedit1("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Cryptography", QSettings::NativeFormat);
    static QSettings regedit2("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\SQMClient", QSettings::NativeFormat);
    // 读取注册表
    QString id1 = regedit1.value("MachineGuid").toString();
    QString id2 = regedit2.value("MachineId").toString();

    QString idRaw = QStringLiteral("多电平上位机 签名验证 V1.0 @ Yj Tan: ") + id1 + id2;
    QCryptographicHash sha256Hash(QCryptographicHash::Sha256);
    QByteArray idData = idRaw.toUtf8();
    sha256Hash.addData(idData);
    RegID = sha256Hash.result();
}

bool winAuthoriation::checkAuthor()
{
    QFile file(QStringLiteral("license.txt"));
    if (!file.exists())
    {
        qDebug() << "license file not found";
        return false;
    }
    else
    {
        file.open(QFile::ReadOnly | QFile::Text);
        auto enc_ID_B64 = file.readAll();
        auto enc_ID = QByteArray::fromBase64(enc_ID_B64);
        auto dec_ID = RsaPubDecWrap(enc_ID);
        if (dec_ID != RegID)
        {
            qDebug() << "license file check fail";
            return false;
        }
    }
    return true;
}

QByteArray winAuthoriation::getRegID()
{
    return RegID;
}
