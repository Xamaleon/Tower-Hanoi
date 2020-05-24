#ifndef MAINMENU_H
#define MAINMENU_H

#include "mainwindow.h"
#include <QWidget>

namespace Ui {
class MainMenu;
}
class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:

    void on_NewGame_clicked();

private:
    Ui::MainMenu *ui;
    MainWindow *win;
};

#endif // MAINMENU_H