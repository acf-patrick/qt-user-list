#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "observable.h"
#include "userservice.h"

#include <QList>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onUserLoad(bool success);

private:
    void updateTableUI();

private:
    UserService userService;

    Observable<QList<User>> users$;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
