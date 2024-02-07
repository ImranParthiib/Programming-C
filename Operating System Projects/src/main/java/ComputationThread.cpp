#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <chrono>
#include <atomic>
#include <condition_variable>

class Scheduler {
    // Implementation of the Scheduler class is not provided in the Java code.
    // You need to define it according to your requirements in C++.
};

class Job {
public:
    std::string processID;
    double burstTime;
    double lastRemainingBurst;
    double startTime;
    double endTime;
    int pBarValue;
};

class ComputationThread {
    Scheduler* policy;
    std::thread t;
    Job* job;
    std::mutex mtx;
    std::condition_variable cv;
    std::string textField;
    std::string readyQueue;
    int min;
    int max;
    int remainingBurstTime;
    std::atomic<bool> status;
    std::atomic<int> exceedTime;
    
public:
    ComputationThread(Job* job, Scheduler* policy, std::string readyQueue, std::string textField, 
                      int min, int max, int remainingBurstTime) :
        policy(policy), job(job), readyQueue(readyQueue), textField(textField),
        min(min), max(max), remainingBurstTime(remainingBurstTime), status(true), exceedTime(0) {}
    
    void assignJob(Job* job) {
        this->job = job;
    }
    
    void run() {
        policy->allocateCPU(job);
        
        if (CalcSimulation.algo == "FCFS" || CalcSimulation.algo == "Priority Scheduling" ||
            CalcSimulation.algo == "Shortest Job First") {
            pbar.setMinimum(min);
            pbar.setMaximum(max);
            pbar.setValue(0);
            
            std::string remProcesses = policy->getRemainingProcesses();
            readyQueue = remProcesses;

            for (int i = 0; i < max; i++) {
                pbar.setValue(i);
                try {
                    std::this_thread::sleep_for(std::chrono::milliseconds(50));
                    
                    {
                        std::lock_guard<std::mutex> lock(mtx);
                        textField = job->processID;
                    }
                } catch(const std::exception& ex) {}
                remainingBurstTime--;
                burstTime = std::to_string(remainingBurstTime) + "ms";
            }
            
            if (status) {
                CPUScheduler.statusSum++;
                std::cout << CPUScheduler.statusSum << std::endl;
            }
        } else if (CalcSimulation.algo == "Round Robin") {
            pbar.setMinimum(0);
            pbar.setMaximum(max);

            int remainingBurstTime = job->lastRemainingBurst; 
            int exceedTime = 0;
            
            std::string remProcesses = policy->getRemainingProcesses();
            readyQueue = remProcesses;
            
            for (int i = min; i < max; i++) {
                pbar.setValue(i);
                try {
                    std::this_thread::sleep_for(std::chrono::milliseconds(50));
                    
                    if (exceedTime == RoundRobinPolicy.TIME_QUANTUM - 1 && remainingBurstTime > 0) {
                        job->lastRemainingBurst = remainingBurstTime;
                        job->pBarValue = i;
                        policy->enqueue(job);
                        break;
                    }
                    
                    {
                        std::lock_guard<std::mutex> lock(mtx);
                        textField = job->processID;
                    }
                } catch(const std::exception& ex) {}
                remainingBurstTime--;
                burstTime = std::to_string(remainingBurstTime) + "ms";
                exceedTime++;
            }
            
            readyQueue = policy->getRemainingProcesses();
        } 
        
        job->endTime = std::chrono::high_resolution_clock::now().time_since_epoch().count() - job->startTime;
    }
};
