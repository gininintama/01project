#include "Position.h"

Position::~Position()
{
}

Position::Position(int x, int y):
    m_nX(x), m_nY(y)
{
}

Position::Position(const Position& pos)
{
    m_nX = pos.m_nX;
    m_nY = pos.m_nY;
}

void Position::setX(int x)
{
    m_nX = x;
}

void Position::setY(int y)
{
    m_nY = y;
}

int Position::getX()
{
    return m_nX;
}

int Position::getY()
{
    return m_nY;
}
