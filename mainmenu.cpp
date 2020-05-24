#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Меню");
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_NewGame_clicked()
{
    QStringList str = ui->PlayerName->text().split(" ");
    if(str.indexOf("")){
        win = new MainWindow(ui->PlayerName->text(), this);
        this->close();
        win->show();
    }
}
