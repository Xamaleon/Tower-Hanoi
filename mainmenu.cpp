#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QCloseEvent>
MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Меню");
}

MainMenu::~MainMenu()
{
    if(win)
        delete win;

    delete ui;
}

void MainMenu::on_NewGame_clicked()
{
    QStringList str = ui->PlayerName->text().split(" ");
    if(str.indexOf("")){
        this->close();
        win = new MainWindow(ui->PlayerName->text(), this);
        win->show();
    }
}










