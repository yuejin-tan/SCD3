#ifndef WINAUTHORIATION_H
#define WINAUTHORIATION_H

#include <QtCore/QObject>

class winAuthoriation: public QObject
{
    Q_OBJECT
public:
    explicit winAuthoriation(QObject* parent = nullptr);

    bool checkAuthor();

    QByteArray getRegID();

public:
    QByteArray RegID;

signals:

};

#endif // WINAUTHORIATION_H
