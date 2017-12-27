#ifndef MP_H
#define MP_H
#include<QProcess>
#include<QString>
#include <QObject>

class Mp : public QObject
{
    Q_OBJECT
public:
     Mp(QObject *parent = 0);
     void run(QString name,QStringList args,int model);
private:
    QProcess myPross;

//signals:

private slots:
        void showResult();
        void showState(QProcess::ProcessState state);
        void showError(QProcess::ProcessError error);
private slots:
        void showFinish(int exitCode, QProcess::ExitStatus exitStatus);
};

#endif // MP_H
