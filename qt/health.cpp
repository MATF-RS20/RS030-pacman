#include "health.h"


Health::Health(int hearts)
{
    health = hearts;

    setPlainText(QString("Health: ") + QString::number(health));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}


void Health::setHealth(int x)
{
    this->health = x;
}
