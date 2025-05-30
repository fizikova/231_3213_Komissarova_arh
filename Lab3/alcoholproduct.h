#ifndef ALCOHOLPRODUCT_H
#define ALCOHOLPRODUCT_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

class AlcoholProduct
{
public:
    AlcoholProduct();
    AlcoholProduct(int id, QString name, QString brand, QString category, int volume_ml, double price,
                   bool in_stock, QString description, QString supplier);

    static AlcoholProduct fromJson(const QByteArray &jsonData);

    friend QDebug operator<<(QDebug dbg, const AlcoholProduct &p);

private:
    int id;
    QString name;
    QString brand;
    QString category;
    int volume_ml;
    double price;
    bool in_stock;
    QString description;
    QString supplier;
};

#endif // ALCOHOLPRODUCT_H
