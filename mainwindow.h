#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <shape.h>
#include <QStack>
#include <qserializer.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QString playerName = "undefined", QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exit_triggered();

    void on_firstToSecond_clicked();

    void on_firstToThird_clicked();

    void on_secondToFirst_clicked();

    void on_secondToThird_clicked();

    void on_thirdToFirst_clicked();

    void on_thirdToSecond_clicked();

private:
    class MainMenu *menu;
    class TowersKeeper * towers;

    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    void MessageInfo();

};
#endif // MAINWINDOW_H
