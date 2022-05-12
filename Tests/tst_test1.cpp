#include <QtTest>
#include "../Headers/Process.h"
#include "../Headers/Exceptions/ProcessInvalidException.h"

class Test1 : public QObject
{
    Q_OBJECT

public:
    Test1();
    ~Test1();

private slots:
    void test_CreateProcess1();
    void test_CreateProcess2();
    void test_CreateProcess3();
    void test_CreateProcess4();
    void test_CreateProcess5();
    void test_CreateProcess6();
    void test_CreateProcess7();
    void test_CreateProcess8();
};

Test1::Test1()
{

}

Test1::~Test1()
{

}


void Test1::test_CreateProcess1(){
     QVERIFY_EXCEPTION_THROWN(Process(2, -3, -3,-2), ProcessInvalidException);
}

void Test1::test_CreateProcess2(){
     QVERIFY_EXCEPTION_THROWN(Process(2, -3, -3, 2), ProcessInvalidException);
}

void Test1::test_CreateProcess3(){
     QVERIFY_EXCEPTION_THROWN(Process(2, -3, 5, -2), ProcessInvalidException);
}

void Test1::test_CreateProcess4(){
     QVERIFY_EXCEPTION_THROWN(Process(2, -3, 1, 9), ProcessInvalidException);
}

void Test1::test_CreateProcess5(){
     QVERIFY_EXCEPTION_THROWN(Process(2, 7, -3, -2), ProcessInvalidException);
}

void Test1::test_CreateProcess6(){
     QVERIFY_EXCEPTION_THROWN(Process(2, 3, -3, 5), ProcessInvalidException);
}

void Test1::test_CreateProcess7(){
    QVERIFY_EXCEPTION_THROWN(Process(2, 2, 4, -2), ProcessInvalidException);
}

void Test1::test_CreateProcess8(){
    try{
        Process(2, 2, 4, 2);
    } catch(ProcessInvalidException){
        QCOMPARE(1, 0);
    }
}
QTEST_APPLESS_MAIN(Test1)

#include "tst_test1.moc"
