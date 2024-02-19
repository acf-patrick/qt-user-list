#include "userservice.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QNetworkRequest>

UserService::UserService() {
    QUrl url("https://jsonplaceholder.typicode.com/users");
    auto& manager = networkAccessManager;

    QObject::connect(&manager, &QNetworkAccessManager::finished, this, &UserService::onRequestReply);
    manager.get(QNetworkRequest(url));
}

void UserService::onRequestReply(QNetworkReply* res) {
    if (res->error() == QNetworkReply::NetworkError::NoError) {
        QJsonParseError parseResult;
        auto jsonDoc = QJsonDocument::fromJson(res->readAll(), &parseResult);

        if (parseResult.error == QJsonParseError::NoError) {
            auto jsonArray = jsonDoc.array();

            for (auto item : jsonArray) {
                auto jsonUser = item.toObject();
                User user;

                user.id = jsonUser[tr("id")].toInt();
                user.email = jsonUser[tr("email")].toString();
                user.name = jsonUser[tr("name")].toString();
                user.username = jsonUser[tr("username")].toString();
                user.phone = jsonUser[tr("phone")].toString();
                user.website = jsonUser[tr("website")].toString();

                auto jsonAddress = jsonUser[tr("address")].toObject();
                user.address.userId = user.id;
                user.address.street = jsonAddress[tr("street")].toString();
                user.address.city = jsonAddress[tr("city")].toString();
                user.address.suite = jsonAddress[tr("suite")].toString();
                user.address.zipcode = jsonAddress[tr("zipcode")].toString();

                auto jsonCompany = jsonUser[tr("company")].toObject();
                user.company.userId = user.id;
                user.company.catchPhrase = jsonCompany[tr("catchPhrase")].toString();
                user.company.name = jsonCompany[tr("name")].toString();
                user.company.bs = jsonCompany[tr("bs")].toString();

                users.push_back(user);
            }
        } else {
            qDebug() << "Response parse error : " << parseResult.errorString();
        }

        emit listLoaded(true);
    } else {
        qDebug() << "Error : " << res->errorString();
        emit listLoaded(false);
    }
}

QList<User> UserService::getUsers() const {
    return users;
}