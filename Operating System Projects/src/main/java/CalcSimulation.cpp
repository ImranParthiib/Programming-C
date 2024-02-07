#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Job {
    int id;
    int burstTime;
    int priority;
    int waitingTime;
};

class CPUScheduler {
private:
    vector<Job> jobBatch;
    string algo;
    
public:
    CPUScheduler(vector<Job>& jobBatch, string algo) : jobBatch(jobBatch), algo(algo) {}
    
    void start() {
        if (algo == "FCFS") {
            // Implement FCFS scheduling
        } else if (algo == "Round Robin") {
            // Implement Round Robin scheduling
        } else if (algo == "Priority Scheduling") {
            // Implement Priority Scheduling
        } else {
            // Implement default case
        }
    }
};

int main() {
    vector<Job> jobBatch;
    int numOfJobs;
    string sourcePath;
    string algo;
    
    // Read input values from user or file
    
    // Create an instance of CalcSimulation
    CalcSimulation simulation(jobBatch, numOfJobs, sourcePath, algo);
    
    // Start the simulation
    simulation.start();
    
    return 0;
}
