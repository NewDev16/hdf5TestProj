#ifndef GOOGLEREQUESTER_H
#define GOOGLEREQUESTER_H

#include <QNetworkAccessManager>

class QString;
class QImage;

class GoogleRequester:public QNetworkAccessManager
{
    Q_OBJECT
public:
    GoogleRequester(QObject* parent = 0);

    void setUrl(const QString& u);

    void sendRequest();

private:
    QString url;

    QImage* sateliteImagery;

    void create();

public slots:
    void replyFinished(QNetworkReply* reply);



};

#endif // GOOGLEREQUESTER_H
