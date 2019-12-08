#ifndef TVAR_HPP
#define TVAR_HPP

template<typename T, typename Oblik, typename HitBox>
class Entity
{
public:
    Entity(T x, T y, Oblik shape, HitBox hbox)
        : _x(x)
        , _y(y)
        , _animation(shape)
        , _hitbox(hbox)
    {
        //TODO: postavljanje hitboxa u mapu i animacije na ekran
    }

    ~Entity()
    {
        // TODO: skidanje sa mape i brisanje
    }



private:
    T _x;
    T _y;
    Oblik _animation;
    HitBox _hitbox;
};

template<typename T, typename Oblik, typename HitBox>
class PacMan : public Entity< T, Oblik, HitBox>
{
public:
    /*
    PacMan(T x, T y, Oblik shape, HitBox hbox, char direction)
        : Entity(x, y, shape, hbox)
        , _direction(direction)
    {
        //TODO: postavljanje hitboxa u mapu i animacije na ekran
    }
    */

    void changeDirection()
    {}

private:
    char _direction;
};

template<typename T, typename Oblik, typename HitBox>
class Ghost : public Entity< T, Oblik, HitBox>
{
public:
    /*
    Ghost(T x, T y, Oblik shape, HitBox hbox, char direction)
        : Entity(x, y, shape, hbox)
        , _direction(direction)
    {
        //TODO: postavljanje hitboxa u mapu i animacije na ekran
    }
    */

    void changeDirection(PacMan<T,Oblik,HitBox> paxi)
    {
        // _direction = fjaZaSmer(paxi);
    }

    void changeToBlue()
    {
        // switchAnimation();
    }

private:
    char _direction;
};

template<typename T, typename Oblik, typename HitBox>
class Dot : public Entity< T, Oblik, HitBox>
{
public:
    /*
    Dot(T x, T y, Oblik shape, HitBox hbox, char direction)
        : Entity(x, y, shape, hbox)
        , _direction(direction)
    {
        //TODO: postavljanje hitboxa u mapu i animacije na ekran
    }
    */

    void changeToBigDot()
    {
        // promenaAnimacije();
        // timer na x sekundi posle kojih iskljucuje
        // signal duhovima - ghostsToBlue();
        // vracanjeAnimacije();
    }
};

#endif // TVAR_HPP
