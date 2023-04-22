#include "mainwindow.h"
#include "scopeform.h"

#include "stdio.h"
#include "QDebug"

#include <QtWidgets/QApplication>
#include <QtCore/QTranslator>

MainWindow* mainWinPtr;

static void appSetQssUtil(QString qssUrl)
{
    QFile file(qssUrl);
    if (!file.exists())
    {
        qDebug() << "Unable to set stylesheet, file not found!";
    }
    else
    {
        file.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&file);
        qApp->setStyleSheet(ts.readAll());
    }
}

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // info
    QCoreApplication::setOrganizationName("TYJ");
    QCoreApplication::setApplicationName("SCD3");
    QCoreApplication::setApplicationVersion(SCD_VERSION);

    // trans
    QTranslator t;
    t.load(QStringLiteral(":/translations/qt_zh_CN.qm"));
    a.installTranslator(&t);

    mainWinPtr = new MainWindow(nullptr);
    mainWinPtr->show();

    // style
    appSetQssUtil(QStringLiteral(":/style/style.qss"));

    // MainWindow w(nullptr);
    // w.show();

    int retVal = a.exec();
    delete mainWinPtr;
    return retVal;

    // return a.exec();
}
