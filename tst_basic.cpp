#include <QtTest>
#include <QCoreApplication>
#include <QString>

// add necessary includes here

class Basic : public QObject
{
    Q_OBJECT

public:
    Basic();
    ~Basic();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case1_data();

};

Basic::Basic()
{

}

Basic::~Basic()
{

}

void Basic::initTestCase()
{

}

void Basic::cleanupTestCase()
{

}

void Basic::test_case1()
{
    QFETCH(QString, string);
    QFETCH(double, result);

    QCOMPARE(string.toDouble(), result);
}

void Basic::test_case1_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<double>("result");

    QTest::newRow("point") << "42.01" << 42.01;
    QTest::newRow("virgule") << "42,01" << 0.0;
    QTest::newRow("integer")  << "42" << 42.0;
    QTest::newRow("invalid") << "coin coin" << 0.0;
}

QTEST_MAIN(Basic)

#include "tst_basic.moc"
