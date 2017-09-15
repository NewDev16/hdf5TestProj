#include "GoogleRequester.h"

#include <QNetworkRequest>
#include <QUrl>
#include <QImage>
#include <QNetworkReply>
#include <QByteArray>
#include <QPixmap>
#include <QImageWriter>


GoogleRequester::GoogleRequester(QObject* parent)
    :QNetworkAccessManager(parent)
    ,sateliteImagery(new QImage)
    ,url("https://maps.googleapis.com/maps/api/staticmap?maptype=satellite&center=37.530101,38.600062&zoom=14&size=640x400&key=AIzaSyCQMXK-DU6E4a1ZTdgREGmFvPyl74rQloU")
{
    create();
}

void GoogleRequester::setUrl(const QString &u){
    url = u;
}

void GoogleRequester::sendRequest(){
    auto reply = this->get(QNetworkRequest(QUrl("https://maps.googleapis.com/maps/api/staticmap?maptype=satellite&center=37.530101,38.600062&zoom=14&size=640x400&key=AIzaSyCQMXK-DU6E4a1ZTdgREGmFvPyl74rQloU")));
    this->setNetworkAccessible(QNetworkAccessManager::Accessible);

    qDebug() << reply->bytesAvailable();
    qDebug() << reply->errorString();

    QByteArray downloadedData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(downloadedData);

    QImageWriter writer;
    writer.setFileName(tr("testImage.png"));
    writer.write(pixmap.toImage());

    reply->deleteLater();
}



void GoogleRequester::create(){
    connect(this,SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

//never called because of missing moc files ! ;)
void GoogleRequester::replyFinished(QNetworkReply *reply){
    qDebug() << reply;
}
