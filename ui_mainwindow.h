/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "loadinglabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *user;
    QGridLayout *gridLayout;
    QTableWidget *user_table;
    QGroupBox *address;
    QGridLayout *gridLayout_2;
    QTableWidget *user_address_table;
    QGroupBox *company;
    QGridLayout *gridLayout_3;
    QTableWidget *user_company_table;
    LoadingLabel *loading_label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(735, 693);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("QHeaderView::section {\n"
"	background: rgb(125, 125, 125);\n"
"	color: white;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        user = new QGroupBox(centralwidget);
        user->setObjectName(QString::fromUtf8("user"));
        gridLayout = new QGridLayout(user);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        user_table = new QTableWidget(user);
        if (user_table->columnCount() < 6)
            user_table->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        user_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        user_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        user_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        user_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        user_table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        user_table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        user_table->setObjectName(QString::fromUtf8("user_table"));
        user_table->setEnabled(true);
        user_table->setSelectionBehavior(QAbstractItemView::SelectRows);
        user_table->setSortingEnabled(true);
        user_table->horizontalHeader()->setVisible(true);
        user_table->horizontalHeader()->setStretchLastSection(true);
        user_table->verticalHeader()->setVisible(false);
        user_table->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(user_table, 0, 0, 1, 1);


        verticalLayout->addWidget(user);

        address = new QGroupBox(centralwidget);
        address->setObjectName(QString::fromUtf8("address"));
        gridLayout_2 = new QGridLayout(address);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        user_address_table = new QTableWidget(address);
        if (user_address_table->columnCount() < 5)
            user_address_table->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        user_address_table->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        user_address_table->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        user_address_table->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        user_address_table->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        user_address_table->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        user_address_table->setObjectName(QString::fromUtf8("user_address_table"));
        user_address_table->setFont(font);
        user_address_table->setSelectionBehavior(QAbstractItemView::SelectRows);
        user_address_table->setSortingEnabled(true);
        user_address_table->horizontalHeader()->setStretchLastSection(true);
        user_address_table->verticalHeader()->setVisible(false);
        user_address_table->verticalHeader()->setStretchLastSection(false);

        gridLayout_2->addWidget(user_address_table, 0, 0, 1, 1);


        verticalLayout->addWidget(address);

        company = new QGroupBox(centralwidget);
        company->setObjectName(QString::fromUtf8("company"));
        gridLayout_3 = new QGridLayout(company);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        user_company_table = new QTableWidget(company);
        if (user_company_table->columnCount() < 4)
            user_company_table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        user_company_table->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        user_company_table->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        user_company_table->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        user_company_table->setHorizontalHeaderItem(3, __qtablewidgetitem14);
        user_company_table->setObjectName(QString::fromUtf8("user_company_table"));
        user_company_table->setSelectionBehavior(QAbstractItemView::SelectRows);
        user_company_table->setSortingEnabled(true);
        user_company_table->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        user_company_table->horizontalHeader()->setStretchLastSection(true);
        user_company_table->verticalHeader()->setVisible(false);
        user_company_table->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        user_company_table->verticalHeader()->setStretchLastSection(false);

        gridLayout_3->addWidget(user_company_table, 0, 0, 1, 1);


        verticalLayout->addWidget(company);

        loading_label = new LoadingLabel(centralwidget);
        loading_label->setObjectName(QString::fromUtf8("loading_label"));
        QFont font1;
        font1.setPointSize(24);
        loading_label->setFont(font1);
        loading_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(loading_label);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        user->setTitle(QCoreApplication::translate("MainWindow", "User", nullptr));
        QTableWidgetItem *___qtablewidgetitem = user_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = user_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = user_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = user_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = user_table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = user_table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Website", nullptr));
        address->setTitle(QCoreApplication::translate("MainWindow", "Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = user_address_table->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "User ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = user_address_table->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Street", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = user_address_table->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Suite", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = user_address_table->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "City", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = user_address_table->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Zipcode", nullptr));
        company->setTitle(QCoreApplication::translate("MainWindow", "Company", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = user_company_table->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "User ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = user_company_table->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = user_company_table->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Catch phrase", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = user_company_table->horizontalHeaderItem(3);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "BS", nullptr));
        loading_label->setText(QCoreApplication::translate("MainWindow", "Loading.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
