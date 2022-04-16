#include "Process.h"
#include <vector>

using namespace std;

struct Entry {
        Process process;
        float start_time;
        float end_time;
};

class TimeLine {
private:
    vector<Entry> entries;
public:
    bool addProcess(Process p, float start_time, float end_time);

    void print();
};
