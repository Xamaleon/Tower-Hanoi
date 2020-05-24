#include "shape.h"

Pos::Pos(int row, int col)
{
    this->row = row;
    this->col = col;
}

int Pos::getX(Size size){
    int towerCenter = col == 1? T1: col == 2? T2: T3;
    return 130 + towerCenter - size * BASE_WIDTH / 2;
}

int Pos::getY(){
    return GROUND_Y - BASE_HEIGHT * row;
}

Shape::Shape(Size size, Pos pos, QBrush color)
{
    this->sizes = size;
    this->setBrush(color);
    this->setRect(0,0, size * BASE_WIDTH, BASE_HEIGHT);
    move(pos);
}

void Shape::move(Pos p)
{
    pos = p;
    this->setPos(pos.getX(sizes), pos.getY());
}

int Shape::size()
{
    return sizes;
}
