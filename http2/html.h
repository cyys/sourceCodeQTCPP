#ifndef HTML_H
#define HTML_H

#include <QObject>
#include<QFile>

class QNetworkReply;
class QNetworkAccessManager;
class Html : public QObject
{
    Q_OBJECT
public:
    explicit Html(QObject *parent = 0);
    void startRequest(QString url="http://www.baidu.com");
    void accessmanager(QString url="http://www.baidu.com");
    ~Html();

public slots:
    void replyFinished(QNetworkReply*);

    void httpFinished();
    void httpReadyRead();
    void updateDataProgress(qint64 ,qint64);
private:
    QNetworkAccessManager *manager;
    QNetworkReply * reply;
    QFile file;
};

#endif // HTML_H
