#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    toggleTables(false);

    users$.subscribeOnce([this](QList<User> users) { updateTableUI(); });
    QObject::connect(&userService, &UserService::listLoaded, this, &MainWindow::onUserLoad);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::toggleTables(bool show) {
    QGroupBox* groups[] = {
        ui->address,
        ui->company,
        ui->user
    };

    for (int i = 0; i < 3; ++i) {
        auto group = groups[i];
        if (show) {
            group->show();
        } else {
            group->hide();
        }
    }
}

void MainWindow::updateTableUI() {
    toggleTables(true);
    delete ui->loading_label;

    auto users = users$.getValue();
    if (users.empty()) {
        return;
    }

    auto rows = users.size();
    if (rows == 0) {
        return;
    }
    
    auto table = ui->user_table;
    table->setRowCount(rows);

    for (int i = 0; i < rows; ++i) {
        auto& user = users[i];

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
        auto& address = users[i].address;

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

    for (int i = 0; i < rows; ++i) {
        auto& company = users[i].company;

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

void MainWindow::onUserLoad(bool success) {
    if (success) {
        users$.next(userService.getUsers());
    }
}
