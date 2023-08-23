#include <QtTest>
#include <QApplication>

// add necessary includes here
#include "../../RS030-pacman/qt/extern_variables.h"
#include "../../RS030-pacman/qt/health.h"
#include "../../RS030-pacman/qt/ghost.h"
#include "../../RS030-pacman/qt/pacmangame.h"

class unitTests : public QObject
{
    Q_OBJECT

public:
    unitTests();
    ~unitTests();

private:
    QApplication *app;

private slots:
    // Initializing and testing
    void initTestCase();
    void testGameInitialization();

    // Tests for class Health
    void testHealthConstructor();
    void testGetHealth();
    void testSetHealth();
    void testDecrease();

    // Tests for class Ghost
    void testGhostConstructor();
    void testGetX();
    void testGetY();
    void testSendToInitial();
    void testChooseRandomTimerStops();
    void testChooseRandomCheckRange();
    void testChooseRandomCheckDistribution();

};

unitTests::unitTests()
{

}

unitTests::~unitTests()
{

}

// For initializing extern variables
void unitTests::initTestCase()
{
    int argc = 0;
    char *argv[] = {nullptr};
    app = new QApplication(argc, argv);
    initializeVariables();
}

// For checking initialization
void unitTests::testGameInitialization()
{
    QVERIFY(game != nullptr);
}

// Testing Health class

void unitTests::testHealthConstructor()
{
    Health* health1 = new Health(3);
    QVERIFY(health1 != nullptr);

    Health* health2 = new Health(0);
    QVERIFY(health2 != nullptr);

    Health* health3 = new Health(-1);
    QVERIFY(health3 != nullptr);

    if (health1 != nullptr)
        delete (health1);
    if (health2 != nullptr)
        delete (health2);
    if (health3 != nullptr)
        delete (health3);
}

void unitTests::testGetHealth()
{
    Health* health1 = new Health(3);
    QCOMPARE(health1->getHealth(), 3);

    Health* health2 = new Health(0);
    QCOMPARE(health2->getHealth(), 0);

    Health* health3 = new Health(-1);
    QCOMPARE(health3->getHealth(), -1);

    if (health1 != nullptr)
        delete (health1);
    if (health2 != nullptr)
        delete (health2);
    if (health3 != nullptr)
        delete (health3);
}

void unitTests::testSetHealth()
{
    Health* health = new Health(3);

    QCOMPARE(health->getHealth(), 3);

    health->setHealth(5);
    QCOMPARE(health->getHealth(), 5);

    health->setHealth(0);
    QCOMPARE(health->getHealth(), 0);

    health->setHealth(-1);
    QCOMPARE(health->getHealth(), -1);

    if (health != nullptr)
        delete (health);
}

void unitTests::testDecrease()
{
    Health* health = new Health(3);

    health->decrease();
    QCOMPARE(health->getHealth(), 2);

    health->decrease();
    QCOMPARE(health->getHealth(), 1);

    health->decrease();
    QCOMPARE(health->getHealth(), 0);

    health->decrease();
    QCOMPARE(health->getHealth(), -1);

    health->decrease();
    QCOMPARE(health->getHealth(), -2);

    health->setHealth(122);
    health->decrease();
    QCOMPARE(health->getHealth(), 121);

    health->setHealth(-122);
    health->decrease();
    QCOMPARE(health->getHealth(), -123);

    if (health != nullptr)
        delete (health);
}

// Tests for class Ghost
void unitTests::testGhostConstructor()
{
    int x = 5;
    int y = 10;

    Ghost* ghost1 = new Ghost(x, y, 1);
    QVERIFY(ghost1 != nullptr);
    if (ghost1 != nullptr)
        delete (ghost1);

    Ghost* ghost2 = new Ghost(x, y , 4);
    QVERIFY(ghost2 != nullptr);
    if (ghost2 != nullptr)
        delete (ghost2);

    Ghost* ghost3 = new Ghost(x, y , -1);
    QVERIFY(ghost3 != nullptr);
    if (ghost3 != nullptr)
        delete (ghost3);

    Ghost* ghost4 = new Ghost(x, y, 0);
    QVERIFY(ghost4 != nullptr);
    if (ghost4 != nullptr)
        delete (ghost4);

    Ghost* ghost5 = new Ghost(x, y , 5);
    QVERIFY(ghost5 != nullptr);
    if (ghost5 != nullptr)
        delete (ghost5);
}

void unitTests::testGetX()
{
    int x1 = 5;
    int x2 = -5;
    int x3 = 0;
    int x4 = 1;
    int x5 = -1;
    int y = 10;
    int id = 1;

    Ghost* ghost1 = new Ghost(x1, y, id);
    QVERIFY(ghost1->getX() == x1);
    if (ghost1 != nullptr)
        delete (ghost1);

    Ghost* ghost2 = new Ghost(x2, y, id);
    QVERIFY(ghost2->getX() == x2);
    if (ghost2 != nullptr)
        delete (ghost2);

    Ghost* ghost3 = new Ghost(x3, y, id);
    QVERIFY(ghost3->getX() == x3);
    if (ghost3 != nullptr)
        delete (ghost3);

    Ghost* ghost4 = new Ghost(x4, y, id);
    QVERIFY(ghost4->getX() == x4);
    if (ghost4 != nullptr)
        delete (ghost4);

    Ghost* ghost5 = new Ghost(x5, y, id);
    QVERIFY(ghost5->getX() == x5);
    if (ghost5 != nullptr)
        delete (ghost5);
}

void unitTests::testGetY()
{
    int y1 = 5;
    int y2 = -5;
    int y3 = 0;
    int y4 = 1;
    int y5 = -1;
    int x = 10;
    int id = 1;

    Ghost* ghost1 = new Ghost(x, y1, id);
    QVERIFY(ghost1->getY() == y1);
    if (ghost1 != nullptr)
        delete (ghost1);

    Ghost* ghost2 = new Ghost(x, y2, id);
    QVERIFY(ghost2->getY() == y2);
    if (ghost2 != nullptr)
        delete (ghost2);

    Ghost* ghost3 = new Ghost(x, y3, id);
    QVERIFY(ghost3->getY() == y3);
    if (ghost3 != nullptr)
        delete (ghost3);

    Ghost* ghost4 = new Ghost(x, y4, id);
    QVERIFY(ghost4->getY() == y4);
    if (ghost4 != nullptr)
        delete (ghost4);

    Ghost* ghost5 = new Ghost(x, y5, id);
    QVERIFY(ghost5->getY() == y5);
    if (ghost5 != nullptr)
        delete (ghost5);
}

void unitTests::testSendToInitial()
{
    int firstX = 5;
    int firstY = 10;
    int id = 1;

    int newX = 15;
    int newY = 20;

    Ghost* ghost = new Ghost(firstX, firstY, id);

    ghost->setX(newX);
    ghost->setY(newY);

    QCOMPARE(ghost->getX(), newX);
    QCOMPARE(ghost->getY(), newY);

    ghost->sendToInitial();

    QCOMPARE(ghost->getX(), firstX);
    QCOMPARE(ghost->getY(), firstY);

}

void unitTests::testChooseRandomTimerStops()
{
    int x = 5;
    int y = 10;
    int id = 1;

    int map = 1;
    int health = 3;
    int src = 0;

    int flagState = 1;

    Ghost* ghost = new Ghost(x, y, id);
    PacmanGame* pacgame = new PacmanGame(map, health, src);
    pacgame->flag = flagState;
    game->game1 = pacgame;

    // Check if the timer is active
    QVERIFY(ghost->getTimer()->isActive() == true);

    ghost->chooseRandom();

    // Check if the timer is stopped
    QVERIFY(ghost->getTimer()->isActive() == false);

    if (ghost != nullptr)
        delete(ghost);
    if (pacgame != nullptr)
        delete(pacgame);
}

void unitTests::testChooseRandomCheckRange()
{
    int x = 5;
    int y = 10;
    int id = 1;

    int map = 1;
    int health = 3;
    int src = 0;

    int flagState = 0;

    int numDirections = 5;

    Ghost* ghost = new Ghost(x, y, id);
    PacmanGame* pacgame = new PacmanGame(map, health, src);
    pacgame->flag = flagState;
    game->game1 = pacgame;

    const int numIterations = 10000;
    bool isValidRange = true;

    for (int i = 0; i < numIterations; i++)
    {
        ghost->chooseRandom();
        int generatedValue = ghost->getNextDirection();

        // Check if the generated value is outside the expected range
        if (generatedValue < 0 || generatedValue > numDirections)
        {
            isValidRange = false;
            break;
        }
    }

    QVERIFY(isValidRange);

    if (ghost != nullptr)
        delete(ghost);
    if (pacgame != nullptr)
        delete(pacgame);
}

void unitTests::testChooseRandomCheckDistribution()
{
    int x = 5;
    int y = 10;
    int id = 1;

    int map = 1;
    int health = 3;
    int src = 0;

    int flagState = 0;

    int numDirections = 5;

    Ghost* ghost = new Ghost(x, y, id);
    PacmanGame* pacgame = new PacmanGame(map, health, src);
    pacgame->flag = flagState;
    game->game1 = pacgame;

    // Map for counting all generated numbers
    std::unordered_map<int, int> countMap;

    const int numIterations = 100000;
    for (int i = 0; i < numIterations; i++) {
        ghost->chooseRandom();
        countMap[ghost->getNextDirection()]++;
    }

    // Checking distribution
    const double expectedProbability = 1.0 / numDirections;
    const double tolerance = 0.05;
    for (int num = 0; num < numDirections; num++) {
        const double actualProbability = static_cast<double>(countMap[num]) / numIterations;
        QVERIFY(qAbs(actualProbability - expectedProbability) < tolerance);
    }

    if (ghost != nullptr)
        delete(ghost);
    if (pacgame != nullptr)
        delete(pacgame);
}

QTEST_APPLESS_MAIN(unitTests)

#include "tst_unittests.moc"
