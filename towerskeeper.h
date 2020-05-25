#ifndef TOWERSKEEPER_H
#define TOWERSKEEPER_H
#include <QWidget>
#include <shape.h>
#include <QVector>
#include <QStack>
#include <vector>
#include <stack>
#include <mainwindow.h>
#include <QGraphicsScene>

class TowersKeeper : public QWidget
{
public:
    TowersKeeper(QGraphicsScene *scene);
    ~TowersKeeper();

    ///\brief Перемещает верхний элемент
    bool move(Number from, Number to);
    bool isEndGame();

    std::vector<std::stack<Shape*>*> vector();

private:
    std::vector<std::stack<Shape*>*> towers;
    QGraphicsScene * scene {nullptr};

};

#endif // TOWERSKEEPER_H
