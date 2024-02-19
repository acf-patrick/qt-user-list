#ifndef USERSERVICE_H
#define USERSERVICE_H

#include <QNetworkReply>
#include <QNetworkAccessManager>

struct UserAddress {
    int userId;
    QString street;
    QString city;
    QString suite;
    QString zipcode;

    enum Column {
        STREET = 1,
        SUITE,
        CITY,
        ZIPCODE
    };
};

struct UserCompany {
    int userId;
    QString name;
    QString catchPhrase;
    QString bs;

    enum Column {
        NAME = 1,
        CATCH_PHRASE,
        BS
    };
};

struct User {
    int id;
    QString name;
    QString username;
    QString email;
    QString phone;
    QString website;
    UserAddress address;
    UserCompany company;

    enum Column {
        NAME = 1,
        USERNAME,
        EMAIL,
        PHONE,
        WEBSITE
    };
};

class UserService: public QObject {
    Q_OBJECT

public:
    UserService();

    QList<User> getUsers() const;

signals:
    void listLoaded(bool success);

private slots:
    void onRequestReply(QNetworkReply*);

private:
    QList<User> users;

    QNetworkAccessManager networkAccessManager;
};

#endif // USERSERVICE_H
