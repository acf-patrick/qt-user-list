#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(&userService, &UserService::listLoaded, this, &MainWindow::onUserLoad);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onUserLoad(bool success) {
    if (!success) {
        return;
    }

    auto rows = userService.userCount();
    if (rows == 0) {
        return;
    }

    auto table = ui->user_table;
    table->setRowCount(rows);

    for (int i = 0; i < rows; ++i) {
        auto user = userService.getUser(i).value();

        auto item = new QTableWidgetItem(QString::number(i));
        table->setItem(i, 0, item);

        item = new QTableWidgetItem(user.name);
        table->setItem(i, User::NAME, item);

        item = new QTableWidgetItem(user.username);
        table->setItem(i, User::USERNAME, item);

        item = new QTableWidgetItem(user.email);
        table->setItem(i, User::EMAIL, item);

        item = new QTableWidgetItem(user.phone);
        table->setItem(i, User::PHONE, item);

        item = new QTableWidgetItem(user.website);
        table->setItem(i, User::WEBSITE, item);
    }

    table = ui->user_address_table;
    table->setRowCount(rows);

    for (int i = 0; i < rows; ++i) {
        auto address = userService.getUserAddress(i).value();

        auto item = new QTableWidgetItem(QString::number(i));
        table->setItem(i, 0, item);

        item = new QTableWidgetItem(address.street);
        table->setItem(i, UserAddress::STREET, item);

        item = new QTableWidgetItem(address.suite);
        table->setItem(i, UserAddress::SUITE, item);

        item = new QTableWidgetItem(address.city);
        table->setItem(i, UserAddress::CITY, item);

        item = new QTableWidgetItem(address.zipcode);
        table->setItem(i, UserAddress::ZIPCODE, item);
    }

    table = ui->user_company_table;
    table->setRowCount(rows);

    for (int i  = 0; i < rows; ++i) {
        auto company = userService.getUserCompany(i).value();

        auto item = new QTableWidgetItem(QString::number(i));
        table->setItem(i, 0, item);

        item = new QTableWidgetItem(company.name);
        table->setItem(i, UserCompany::NAME, item);

        item = new QTableWidgetItem(company.catchPhrase);
        table->setItem(i, UserCompany::CATCH_PHRASE, item);

        item = new QTableWidgetItem(company.bs);
        table->setItem(i, UserCompany::BS, item);
    }
}
