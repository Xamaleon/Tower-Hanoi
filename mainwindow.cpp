#include "mainwindow.h"
#include "mainmenu.h"
#include "towerskeeper.h"
#include "ui_mainwindow.h"
#include "QStack"
#include "QMessageBox"
#include "QString"
#include "QCloseEvent"

MainWindow::MainWindow(QString playerName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Ханойская башня");

    ui->lb_name->setText(playerName);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(ui->graphicsView->rect());

    // горизонтальная
    // вертикальная
    scene->addRect(QRectF(250, GROUND, 6, 180));
    scene->addRect(QRectF(T1, GROUND_Y, 260, 6));

    scene->addRect(QRectF(600, GROUND, 6, 180));
    scene->addRect(QRectF(T2, GROUND_Y, 260, 6));

    scene->addRect(QRectF(950, GROUND, 6, 180));
    scene->addRect(QRectF(T3, GROUND_Y, 260, 6));

    towers = new TowersKeeper(scene);

    menu = new MainMenu();
  //  connect(this, &MainWindow::showMenu, menu, &MainMenu::show);




}

MainWindow::~MainWindow()
{


    delete towers;
    if(menu) delete menu;
    delete ui;


}


void MainWindow::on_exit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_firstToSecond_clicked()
{
    if(towers->move(FIRST, SECOND)){
        ui->lb_point->setNum(ui->lb_point->text().toInt()+1);
    }
    MessageInfo();

}

void MainWindow::on_firstToThird_clicked()
{
    if(towers->move(FIRST, THIRD))
        ui->lb_point->setNum(ui->lb_point->text().toInt()+1);
    MessageInfo();
}

void MainWindow::on_secondToFirst_clicked()
{
    if(towers->move(SECOND, FIRST))
        ui->lb_point->setNum(ui->lb_point->text().toInt()+1);
}

void MainWindow::on_secondToThird_clicked()
{
    if(towers->move(SECOND, THIRD))
        ui->lb_point->setNum(ui->lb_point->text().toInt()+1);
    MessageInfo();
}

void MainWindow::on_thirdToFirst_clicked()
{
    if(towers->move(THIRD, FIRST))
        ui->lb_point->setNum(ui->lb_point->text().toInt()+1);
}

void MainWindow::on_thirdToSecond_clicked()
{
    if(towers->move(THIRD, SECOND))
        ui->lb_point->setNum(ui->lb_point->text().toInt()+1);
    MessageInfo();
}

void MainWindow::MessageInfo()
{
    if(towers->isEndGame()){
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Поздравляем!",QString(ui->lb_name->text()) + ", вы прошли игру.\nЖелаете начать новую игру?\n\nOK - Начать игру заново;\nClose - Вернуться в меню;",QMessageBox::Ok |QMessageBox::Close);
        if(reply == QMessageBox::Ok){



        }
        else {


        }
    }
}

