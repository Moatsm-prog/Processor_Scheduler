#include <QtTest>
#include "../Headers/Process.h"
#include "../Headers/Algorithms/Algorithm.h"
#include "../Headers/Algorithms/RoundRobin.h"
#include "../Headers/Exceptions/ProcessInvalidException.h"
#include "../Headers/Exceptions/QuantumInvalidException.h"

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
    void test_RoundRobin_valid();
    void test_RoundRobin_invalid1();
    void test_RoundRobin_invalid2();
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

void Test1::test_RoundRobin_valid(){
     std::vector<Process> processes;
     Process p1 = Process(1 , 0.0 , 5.0);
     Process p2 = Process(2 , 3.0 , 5.0);
     Process p3 = Process(3 , 5.0 , 2.0);
     processes.push_back(p1);
     processes.push_back(p2);
     processes.push_back(p3);
     Algorithm *algo;
     TimeLine scheduler;
     algo = new RoundRobin();
     scheduler = algo->applyAlgorithm(processes, 2.0);
     TimeLine result;
     result.addProcess(p1 , 0.0 , 2.0);
     result.addProcess(p1 , 2.0 , 4.0);
     result.addProcess(p2 , 4.0 , 6.0);
     result.addProcess(p1 , 6.0 , 7.0);
     result.addProcess(p3, 7.0 , 9.0);
     result.addProcess(p2 , 9.0 , 11.0);
     result.addProcess(p2 , 11.0 , 12.0);
     bool actual = scheduler.equal(result);
     QCOMPARE(actual , 1);

}

void Test1::test_RoundRobin_invalid1(){
     std::vector<Process> processes;
     Process p1 = Process(1 , 0.0 , 5.0);
     Process p2 = Process(2 , 3.0 , 5.0);
     Process p3 = Process(3 , 5.0 , 2.0);
     processes.push_back(p1);
     processes.push_back(p2);
     processes.push_back(p3);
     Algorithm *algo;
     TimeLine scheduler;
     algo = new RoundRobin();
     QVERIFY_EXCEPTION_THROWN(algo->applyAlgorithm(processes, -2.0), QuantumInvalidException);

}

void Test1::test_RoundRobin_invalid2(){
     std::vector<Process> processes;
     Process p1 = Process(1 , 0.0 , 5.0);
     Process p2 = Process(2 , 3.0 , 5.0);
     Process p3 = Process(3 , 5.0 , 2.0);
     processes.push_back(p1);
     processes.push_back(p2);
     processes.push_back(p3);
     Algorithm *algo;
     TimeLine scheduler;
     algo = new RoundRobin();
     QVERIFY_EXCEPTION_THROWN(algo->applyAlgorithm(processes, 0.0), QuantumInvalidException);

}

QTEST_APPLESS_MAIN(Test1)

#include "tst_test1.moc"
