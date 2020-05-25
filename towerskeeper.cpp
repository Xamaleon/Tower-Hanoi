#include "towerskeeper.h"
#include <mainwindow.h>
#include <QMessageBox>
#include <QApplication>

TowersKeeper::TowersKeeper(QGraphicsScene * scene)
{
    this->scene = scene;


    for(int i = 0; i < 3; i++)
        towers.push_back(new std::stack<Shape*>());


    towers.at(0)->push(new Shape(bigger, Pos(1,1), Qt::red));
    scene->addItem(towers.at(0)->top());

    towers.at(0)->push(new Shape(middle, Pos(2,1), Qt::blue));
    scene->addItem(towers.at(0)->top());

    towers.at(0)->push(new Shape(little, Pos(3,1), Qt::green));
    scene->addItem(towers.at(0)->top());
}

TowersKeeper::~TowersKeeper()
{
    for(auto tower : towers)
    {
        while(tower->size())
        {
            delete tower->top();
            tower->pop();
        }
    }
}

bool TowersKeeper::isEndGame()
{
    if(towers.at(1)->size() == 3 || towers.at(2)->size() == 3){
        return true;
    }
    return false;
}



std::vector<std::stack<Shape *> *> TowersKeeper::vector()
{
    return towers;
}




bool TowersKeeper::move(Number from, Number to)
{
    std::stack<Shape*> * src = towers.at(from);
    std::stack<Shape*> * dst = towers.at(to);

    if(src->empty() || dst->size() >= 3)
        return false;
    else if(!dst->empty()){
        if(dst->top()->size() == little || src->top()->size() == bigger)
            return false;
    }

    dst->push(src->top());
    src->pop();

    dst->top()->move(Pos(dst->size(), to+1));

    return true;
}
