#include <QtTest>
#include "../Headers/Process.h"
#include "../Headers/Algorithms/Algorithm.h"
#include "../Headers/Algorithms/RoundRobin.h"
#include "../Headers/Exceptions/ProcessInvalidException.h"
#include "../Headers/Exceptions/QuantumInvalidException.h"
#include "../Headers/Algorithms/SJF_Preemptive.h"
#include "../Headers/Algorithms/Priority_Preemptive.h"
#include "../Headers/Algorithms/SJF_NonPreemptive.h"
#include "../Headers/Algorithms/Priority_NonPreemptive.h"
#include "../Headers/Algorithms/FCFS.h"

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
     void test_SJF_Preemptive_valid();
     void test_Priority_Preemptive_valid();
     void test_SJF_NonPreemptive_valid();
     void test_Priority_NonPreemptive_valid();
     void test_FCFS_valid();

     void test_FCFS_Paths();
     void test_CreateProcess_Paths();
     void test_addProcess_Paths();
};

Test1::Test1()
{
}

Test1::~Test1()
{
}

void Test1::test_CreateProcess1()
{
     QVERIFY_EXCEPTION_THROWN(Process(2, -3, -3, -2), ProcessInvalidException);
}

void Test1::test_CreateProcess2()
{
     QVERIFY_EXCEPTION_THROWN(Process(2, -3, -3, 2), ProcessInvalidException);
}

void Test1::test_CreateProcess3()
{
     QVERIFY_EXCEPTION_THROWN(Process(2, -3, 5, -2), ProcessInvalidException);
}

void Test1::test_CreateProcess4()
{
     QVERIFY_EXCEPTION_THROWN(Process(2, -3, 1, 9), ProcessInvalidException);
}

void Test1::test_CreateProcess5()
{
     QVERIFY_EXCEPTION_THROWN(Process(2, 7, -3, -2), ProcessInvalidException);
}

void Test1::test_CreateProcess6()
{
     QVERIFY_EXCEPTION_THROWN(Process(2, 3, -3, 5), ProcessInvalidException);
}

void Test1::test_CreateProcess7()
{
     QVERIFY_EXCEPTION_THROWN(Process(2, 2, 4, -2), ProcessInvalidException);
}

void Test1::test_CreateProcess8()
{
     try
     {
          Process(2, 2, 4, 2);
     }
     catch (ProcessInvalidException)
     {
          QCOMPARE(1, 0);
     }
}

void Test1::test_RoundRobin_valid()
{
     std::vector<Process> processes;
     Process p1 = Process(1, 0.0, 5.0);
     Process p2 = Process(2, 3.0, 5.0);
     Process p3 = Process(3, 5.0, 2.0);
     processes.push_back(p1);
     processes.push_back(p2);
     processes.push_back(p3);
     Algorithm *algo;
     TimeLine scheduler;
     algo = new RoundRobin();
     scheduler = algo->applyAlgorithm(processes, 2.0);
     TimeLine result;
     result.addProcess(p1, 0.0, 2.0);
     result.addProcess(p1, 2.0, 4.0);
     result.addProcess(p2, 4.0, 6.0);
     result.addProcess(p1, 6.0, 7.0);
     result.addProcess(p3, 7.0, 9.0);
     result.addProcess(p2, 9.0, 11.0);
     result.addProcess(p2, 11.0, 12.0);
     bool actual = scheduler.equal(result);
     QCOMPARE(actual, 1);
}

void Test1::test_RoundRobin_invalid1()
{
     std::vector<Process> processes;
     Process p1 = Process(1, 0.0, 5.0);
     Process p2 = Process(2, 3.0, 5.0);
     Process p3 = Process(3, 5.0, 2.0);
     processes.push_back(p1);
     processes.push_back(p2);
     processes.push_back(p3);
     Algorithm *algo;
     TimeLine scheduler;
     algo = new RoundRobin();
     QVERIFY_EXCEPTION_THROWN(algo->applyAlgorithm(processes, -2.0), QuantumInvalidException);
}

void Test1::test_RoundRobin_invalid2()
{
     std::vector<Process> processes;
     Process p1 = Process(1, 0.0, 5.0);
     Process p2 = Process(2, 3.0, 5.0);
     Process p3 = Process(3, 5.0, 2.0);
     processes.push_back(p1);
     processes.push_back(p2);
     processes.push_back(p3);
     Algorithm *algo;
     TimeLine scheduler;
     algo = new RoundRobin();
     QVERIFY_EXCEPTION_THROWN(algo->applyAlgorithm(processes, 0.0), QuantumInvalidException);
}
void Test1::test_SJF_Preemptive_valid()
{
     std::vector<Process> processes;
     Process p1 = Process(1, 0.0, 6.0);
     Process p2 = Process(2, 1.0, 4.0);
     Process p3 = Process(3, 2.0, 2.0);
     Process p4 = Process(4, 3.0, 3.0);
     processes.push_back(p1);
     processes.push_back(p2);
     processes.push_back(p3);
     processes.push_back(p4);
     Algorithm *algo;
     TimeLine scheduler;
     algo = new SJF_Preemptive();
     scheduler = algo->applyAlgorithm(processes, 2.0);
     TimeLine result;
     result.addProcess(p1, 0.0, 1.0);
     result.addProcess(p2, 1.0, 2.0);
     result.addProcess(p3, 2.0, 4.0);
     result.addProcess(p2, 4.0, 7.0);
     result.addProcess(p4, 7.0, 10.0);
     result.addProcess(p1, 10.0, 15.0);
     bool actual = scheduler.equal(result);
     QCOMPARE(actual, 1);
}

void Test1::test_Priority_Preemptive_valid()
{
     std::vector<Process> processes;
     Process p1 = Process(1, 0.0, 4.0, 1);
     Process p2 = Process(2, 0.0, 3.0, 2);
     Process p3 = Process(3, 6.0, 7.0, 1);
     Process p4 = Process(4, 11.0, 4.0, 3);
     Process p5 = Process(5, 12.0, 2.0, 2);
     processes.push_back(p1);
     processes.push_back(p2);
     processes.push_back(p3);
     processes.push_back(p4);
     processes.push_back(p5);
     Algorithm *algo;
     TimeLine scheduler;
     algo = new Priority_Preemptive();
     scheduler = algo->applyAlgorithm(processes);
     TimeLine result;
     result.addProcess(p1, 0.0, 4.0);
     result.addProcess(p2, 4.0, 6.0);
     result.addProcess(p3, 6.0, 13.0);
     result.addProcess(p2, 13.0, 14.0);
     result.addProcess(p5, 14.0, 16.0);
     result.addProcess(p4, 16.0, 20.0);
     bool actual = scheduler.equal(result);
     QCOMPARE(actual, 1);
}

void Test1::test_SJF_NonPreemptive_valid()
{
     std::vector<Process> processes;
     Process p1 = Process(1, 2.0, 6.0);
     Process p2 = Process(2, 5.0, 2.0);
     Process p3 = Process(3, 1.0, 8.0);
     Process p4 = Process(4, 0.0, 3.0);
     Process p5 = Process(5, 4.0, 4.0);
     processes.push_back(p1);
     processes.push_back(p2);
     processes.push_back(p3);
     processes.push_back(p4);
     processes.push_back(p5);
     Algorithm *algo;
     TimeLine scheduler;
     algo = new SJF_NonPreemptive();
     scheduler = algo->applyAlgorithm(processes);
     TimeLine result;
     result.addProcess(p4, 0.0, 3.0);
     result.addProcess(p1, 3.0, 9.0);
     result.addProcess(p2, 9.0, 11.0);
     result.addProcess(p5, 11.0, 15.0);
     result.addProcess(p3, 15.0, 23.0);
     bool actual = scheduler.equal(result);
     QCOMPARE(actual, 1);
}

void Test1::test_Priority_NonPreemptive_valid()
{
     std::vector<Process> processes;
     Process p1 = Process(1, 0.0, 4.0, 1);
     Process p2 = Process(2, 0.0, 3.0, 2);
     Process p3 = Process(3, 6.0, 7.0, 1);
     Process p4 = Process(4, 11.0, 4.0, 3);
     Process p5 = Process(5, 12.0, 2.0, 2);
     processes.push_back(p1);
     processes.push_back(p2);
     processes.push_back(p3);
     processes.push_back(p4);
     processes.push_back(p5);
     Algorithm *algo;
     TimeLine scheduler;
     algo = new Priority_NonPreemptive();
     scheduler = algo->applyAlgorithm(processes);
     TimeLine result;
     result.addProcess(p1, 0.0, 4.0);
     result.addProcess(p2, 4.0, 7.0);
     result.addProcess(p3, 7.0, 14.0);
     result.addProcess(p5, 14.0, 16.0);
     result.addProcess(p4, 16.0, 20.0);
     bool actual = scheduler.equal(result);
     QCOMPARE(actual, 1);
}

void Test1::test_FCFS_valid()
{
     std::vector<Process> processes;
     Process p1 = Process(1, 2.0, 6.0);
     Process p2 = Process(2, 5.0, 2.0);
     Process p3 = Process(3, 1.0, 8.0);
     Process p4 = Process(4, 0.0, 3.0);
     Process p5 = Process(5, 4.0, 4.0);
     processes.push_back(p1);
     processes.push_back(p2);
     processes.push_back(p3);
     processes.push_back(p4);
     processes.push_back(p5);
     Algorithm *algo = new FCFS();
     TimeLine scheduler;
     scheduler = algo->applyAlgorithm(processes);
     TimeLine result;
     result.addProcess(p4, 0.0, 3.0);
     result.addProcess(p3, 3.0, 11.0);
     result.addProcess(p1, 11.0, 17.0);
     result.addProcess(p5, 17.0, 21.0);
     result.addProcess(p2, 21.0, 23.0);
     bool actual = scheduler.equal(result);
     QCOMPARE(actual, 1);
}

void Test1::test_FCFS_Paths()
{
     Algorithm *algo = new FCFS();
     
     // Test No Processes Added
     std::vector<Process> processes;
     TimeLine scheduler;
     scheduler = algo->applyAlgorithm(processes);
     TimeLine result;
     bool actual = scheduler.equal(result);
     QCOMPARE(actual, 1);

     // Test i == 0
     std::vector<Process> processes1;
     Process p1 = Process(1, 2.0, 6.0);
     processes1.push_back(p1);
     TimeLine scheduler1;
     scheduler1 = algo->applyAlgorithm(processes1);
     TimeLine result1;
     result1.addProcess(p1, 2, 8);
     actual = scheduler1.equal(result1);
     QCOMPARE(actual, 1);

     // Test i > 0
     std::vector<Process> processes2;
     p1 = Process(1, 2.0, 6.0);
     Process p2 = Process(1, 6, 2);
     processes2.push_back(p1);
     processes2.push_back(p2);
     TimeLine scheduler2;
     scheduler2 = algo->applyAlgorithm(processes2);
     TimeLine result2;
     result2.addProcess(p1, 2, 8);
     result2.addProcess(p2, 8, 10);
     actual = scheduler2.equal(result2);
     QCOMPARE(actual, 1);
}

void Test1::test_CreateProcess_Paths()
{
     // Test Arrival_time < 0;
     QVERIFY_EXCEPTION_THROWN(Process(2, -3, 3, 2), ProcessInvalidException);

     // Test Burst_time > 0;
     QVERIFY_EXCEPTION_THROWN(Process(2, 3, -10, 2), ProcessInvalidException);

     // Test Priority < 0;
     QVERIFY_EXCEPTION_THROWN(Process(2, 3, 3, -2), ProcessInvalidException);

     // Valid Process
     try {
          Process(2, 2, 4, 2);
          QCOMPARE(1, 1);
     }
     catch (ProcessInvalidException) {
          QCOMPARE(1, 0);
     }
}

void Test1::test_addProcess_Paths()
{
     // endTime < startTime
     Process p1 = Process(1, 2.0, 6.0);
     TimeLine tl;
     QCOMPARE(tl.addProcess(p1, 2, 1), 0);
     
     // Empty Entries Entries
     Process p2 = Process(1, 2.0, 6.0);
     TimeLine tl2;
     QCOMPARE(tl2.addProcess(p2, 2, 8), 1);
     
     // Test Start_time < lastE.getEndTime()
     Process p3 = Process(1, 2.0, 6.0);
     QCOMPARE(tl2.addProcess(p3, 7, 13), 0);
}

QTEST_APPLESS_MAIN(Test1)

#include "tst_test1.moc"
