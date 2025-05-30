#include "alcoholproduct.h"

AlcoholProduct::AlcoholProduct() {}

AlcoholProduct::AlcoholProduct(int id, QString name, QString brand, QString category, int volume_ml,
                               double price, bool in_stock, QString description, QString supplier)
    : id(id), name(name), brand(brand), category(category), volume_ml(volume_ml), price(price),
    in_stock(in_stock), description(description), supplier(supplier) {}

AlcoholProduct AlcoholProduct::fromJson(const QByteArray &jsonData) {
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if (!doc.isObject()) throw std::runtime_error("Invalid JSON");

    QJsonObject obj = doc.object();
    return AlcoholProduct(
        obj["id"].toInt(),
        obj["name"].toString(),
        obj["brand"].toString(),
        obj["category"].toString(),
        obj["volume_ml"].toInt(),
        obj["price"].toDouble(),
        obj["in_stock"].toBool(),
        obj["description"].toString(),
        obj["supplier"].toString()
        );
}

QDebug operator<<(QDebug dbg, const AlcoholProduct &p) {
    dbg.nospace() << "AlcoholProduct("
                  << "id: " << p.id
                  << ", name: " << p.name
                  << ", brand: " << p.brand
                  << ", category: " << p.category
                  << ", volume_ml: " << p.volume_ml
                  << ", price: " << p.price
                  << ", in_stock: " << p.in_stock
                  << ", description: " << p.description
                  << ", supplier: " << p.supplier
                  << ")";
    return dbg.space();
}
