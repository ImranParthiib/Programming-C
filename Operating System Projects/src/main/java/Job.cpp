#include <string>
#include <chrono>
#include <thread>
#include <iostream>

class Job
{
public:
    long long burstTime;
    long long arrivalTime;
    std::string processID;
    long long startTime;
    long long endTime;
    long long waitTime;
    // Assuming JProgressBar and JLabel have similar equivalents in C++
    // You may need to replace them with appropriate UI components
    // JProgressBar progressBar;
    // JLabel burstTimeLabel;
    int lastRemainingBurst;
    // Assuming JLabel has a similar equivalent in C++
    // You may need to replace it with an appropriate UI component
    // JLabel waitTimeLabel;
    int pBarValue;
    int priority;

    Job(const std::string &processID, long long arrivalTime, long long burstTime, long long startTime)
    {
        this->processID = processID;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->startTime = startTime;
        lastRemainingBurst = static_cast<int>(burstTime);
    }
};

int main()
{
    // Example usage of the Job class
    Job job1("Process1", std::chrono::high_resolution_clock::now().time_since_epoch().count(), 1000, 0);
    std::cout << "Process ID: " << job1.processID << std::endl;

    return 0;
}
