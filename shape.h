#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsItem>
#include <QBrush>

// центры осей башен
const int T1 = 120;
const int T2 = 470;
const int T3 = 820;

// положение горизонта
const int GROUND_Y = 425;
const int GROUND = GROUND_Y - 175;

// базовые множители высоты и ширины
const int BASE_HEIGHT = 30;
const int BASE_WIDTH = 80;


enum Number{
    FIRST = 0,
    SECOND,
    THIRD,
};

enum Size  {
    little = 1,
    middle = 2,
    bigger = 3,
};

///\brief Класс позиции, в конструктор можно передать строку и колонку - т.е. положение в башне и башню
///\details всю концепцию можно представить как таблицу в которой есть строки и колонки, в данном случае 3х3
class Pos
{
public:
    Pos(int row = 0, int col = 0);

    ///\brief Конструктор копирования
//    Pos(const Pos & p){
//        this->row = p.row;
//        this->col = p.col;
//    }

    int getX(Size size);
    int getY();

private:

    int row{0};
    int col{0};
};


///\brief Класс элемента, умеет перемещать себя
class Shape:public QGraphicsRectItem
{
public:

    Shape(Size size, Pos pos = Pos(), QBrush color = Qt::gray);

    ///\brief Перемещает элемент на выбранную позицию
    void move(Pos p);
    int size();

    inline Pos position(){ return pos; }
private:
    Size sizes;
    Pos pos;
};

#endif // SHAPE_H
