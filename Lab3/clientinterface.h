#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QUrl>
#include "alcoholproduct.h"

class ClientInterface
{
public:
    // Singleton
    static ClientInterface* existing_object;
    static ClientInterface* getInstance() {
        QString root_url = "http://localhost/api/";
        if(existing_object == nullptr) {
            existing_object = new ClientInterface(root_url);
        }
        return existing_object;
    }

    static void removeInstance() {
        if(existing_object)
            delete existing_object;
        existing_object = nullptr;
    }

    AlcoholProduct GetAlcoholProduct(int id);
    QList<AlcoholProduct> GetAlcoholProducts();
    AlcoholProduct CreateAlcoholProduct();
    AlcoholProduct UpdateAlcoholProduct(int id);
    bool DeleteAlcoholProduct(int id);

private:
    ClientInterface(QString& root_url);
    QNetworkAccessManager* m_client = nullptr;
    QString m_root_url;
};

#endif // CLIENTINTERFACE_H
