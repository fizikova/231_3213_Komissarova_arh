#include "clientinterface.h"
#include <QJsonArray>


ClientInterface* ClientInterface::existing_object = nullptr;

ClientInterface::ClientInterface(QString& root_url) {
    m_root_url = root_url;
    m_client = new QNetworkAccessManager();
}

AlcoholProduct ClientInterface::GetAlcoholProduct(int id) {
    QNetworkRequest request(QUrl(m_root_url + "alcoholproducts/" + QString::number(id)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *reply = m_client->get(request);
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    return AlcoholProduct::fromJson(reply->readAll());
}

QList<AlcoholProduct> ClientInterface::GetAlcoholProducts() {
    QNetworkRequest request(QUrl(m_root_url + "alcoholproducts/"));
    QNetworkReply* reply = m_client->get(request);
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QByteArray response = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(response);
    QJsonArray array = doc.array();

    QList<AlcoholProduct> result;
    for (const QJsonValue& value : array) {
        QJsonObject obj = value.toObject();
        result.append(AlcoholProduct::fromJson(QJsonDocument(obj).toJson()));
    }
    return result;
}

AlcoholProduct ClientInterface::CreateAlcoholProduct() {
    QJsonObject body;
    body["name"] = "Chardonnay";
    body["brand"] = "VinCo";
    body["category"] = "wine";
    body["volume_ml"] = 750;
    body["price"] = 899.99;
    body["in_stock"] = true;
    body["description"] = "Белое сухое вино";
    body["supplier"] = "Виноторг";

    QNetworkRequest request(QUrl(m_root_url + "alcoholproducts/"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply* reply = m_client->post(request, QJsonDocument(body).toJson());

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    return AlcoholProduct::fromJson(reply->readAll());
}

AlcoholProduct ClientInterface::UpdateAlcoholProduct(int id) {
    QJsonObject body;
    body["price"] = 999.99;
    body["in_stock"] = false;

    QNetworkRequest request(QUrl(m_root_url + "alcoholproducts/" + QString::number(id) + "/"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply* reply = m_client->sendCustomRequest(request, "PATCH", QJsonDocument(body).toJson());

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    return AlcoholProduct::fromJson(reply->readAll());
}

bool ClientInterface::DeleteAlcoholProduct(int id) {
    QNetworkRequest request(QUrl(m_root_url + "alcoholproducts/" + QString::number(id) + "/"));
    QNetworkReply* reply = m_client->deleteResource(request);
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    return reply->error() == QNetworkReply::NoError;
}

