#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <random>
#include <ctime>

class Job
{
public:
    long long arrivalTime;
    long long startTime;
    long long waitTime;
    long long endTime;
    int priority;
    JProgressBar *progressBar;
    JLabel *burstTimeLabel;
    JLabel *waitTimeLabel;
};

class Scheduler
{
public:
    void enqueue(Job *job)
    {
        // Implementation of enqueue method
    }

    Job *

    dequeue()
    {
        // Implementation of dequeue method
        return nullptr;
    }

    Job *

    peek()
    {
        // Implementation of peek method
        return nullptr;
    }

    bool isEmpty()
    {
        // Implementation of isEmpty method
        return true;
    }
};

class MaxPriorityQueue
{
public:
    void insert(Job *job)
    {
        // Implementation of insert method
    }

    Job *

    extractMax()
    {
        // Implementation of extractMax method
        return nullptr;
    }

    Job *

    getMax()
    {
        // Implementation of getMax method
        return nullptr;
    }

    bool isEmpty()
    {
        // Implementation of isEmpty method
        return true;
    }
};

class ComputationThread
{
public:
    std::
        thread t;

    ComputationThread(Job *job, Scheduler *policy, JTextArea *textArea, JTextField *textField,
                      JProgressBar *progressBar, JLabel *burstTimeLabel)
    {
        // Implementation of constructor
    }

    void start()
    {
        // Implementation of start method
    }

    void join()
    {
        // Implementation of join method
    }
};

class CPUScheduler
{
public:
    Job *jobBatch;
    Scheduler *policy;
    JTextArea *textArea;
    JTextField *textField;
    JProgressBar **pbars;
    JLabel **burstTimes;
    ComputationThread **myThreads;
    JLabel **waitingTimes;
    JLabel **priorities;
    static int statusSum;

    CPUScheduler(Job *jobBatch, Scheduler *policy, JTextArea *textArea, JTextField *textField,
                 JProgressBar **pbars, JLabel **burstTimes, JLabel **waitingTimes, JLabel **priorities)
    {
        this->jobBatch = jobBatch;
        this->policy = policy;
        this->textArea = textArea;
        this->textField = textField;
        this->pbars = pbars;
        this->burstTimes = burstTimes;
        this->waitingTimes = waitingTimes;
        this->priorities = priorities;
        myThreads = new ComputationThread *[SchedulingGUI::NUM_OF_PROCESSES];
    }

    void run()
    {
        if (CalcSimulation::algo == "FCFS")
        {
            Job *arrivedJob;

            for (int i = 0; i < jobBatch.length; i++)
            {
                arrivedJob = jobBatch[i];
                policy->enqueue(arrivedJob);
            }

            int i = 0;
            while (!policy->isEmpty())
            {
                JProgressBar *pbar = pbars[i];
                JLabel *burstTime = burstTimes[i];
                long long arrivalTime = policy->peek()->arrivalTime;

                try
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(arrivalTime));
                }
                catch (const std::exception &e)
                {
                }

                Job *newJob = policy->dequeue();
                newJob->waitTime = std::chrono::high_resolution_clock::now().time_since_epoch().count() - newJob->startTime;
                int durationInS = static_cast<int>(std::chrono::nanoseconds(newJob->waitTime).count()) / 1000000000;
                newJob->waitTimeLabel->setText(std::to_string(durationInS) + "s");
                myThreads[i] = new ComputationThread(newJob, policy, textArea, textField, pbar, burstTime);
                myThreads[i]->start();
                i++;
            }
        }
        else if (CalcSimulation::algo == "Round Robin")
        {

            for (int i = 0; i < jobBatch.length; i++)
            {
                jobBatch[i]->progressBar = pbars[i];
                jobBatch[i]->burstTimeLabel = burstTimes[i];
                jobBatch[i]->waitTimeLabel = waitingTimes[i];
                policy->enqueue(jobBatch[i]);
            }

            int i = 0;
            while (!policy->isEmpty())
            {
                long long arrivalTime = policy->peek()->arrivalTime;
                try
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(arrivalTime));
                }
                catch (const std::exception &e)
                {
                }

                Job *newJob = policy->dequeue();
                newJob->waitTime = std::chrono::high_resolution_clock::now().time_since_epoch().count() - newJob->startTime;
                int durationInS = static_cast<int>(std::chrono::nanoseconds(newJob->waitTime).count()) / 1000000000;
                newJob->waitTimeLabel->setText(std::to_string(durationInS) + "s");
                myThreads[0] = new ComputationThread(newJob, policy, textArea, textField,
                                                     newJob->progressBar, newJob->burstTimeLabel);
                myThreads[0]->start();
                try
                {
                    myThreads[0]->join();
                }
                catch (const std::exception &ex)
                {
                }
            }

            for (int j = 1; j < SchedulingGUI::NUM_OF_PROCESSES; j++)
                myThreads[j] = new ComputationThread(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
        }
        else if (CalcSimulation::algo == "Priority Scheduling")
        {

            MaxPriorityQueue mp;
            MaxPriorityQueue tempmp;

            for (int i = 0; i < jobBatch.length; i++)
            {
                int priority = (std::rand() % 10) + 1;
                JProgressBar *pbar = pbars[i];
                JLabel *burstTime = burstTimes[i];
                jobBatch[i]->progressBar = pbar;
                jobBatch[i]->burstTimeLabel = burstTime;
                jobBatch[i]->priority = priority;
                jobBatch[i]->waitTimeLabel = waitingTimes[i];
                priorities[i]->setText(std::to_string(jobBatch[i]->priority));
                mp.insert(jobBatch[i]);
                tempmp.insert(jobBatch[i]);
            }

            while (!tempmp.isEmpty())
            {
                policy->enqueue(tempmp.extractMax());
            }

            while (!mp.isEmpty())
            {
                long long arrivalTime = mp.getMax()->arrivalTime;
                try
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(arrivalTime));
                }
                catch (const std::exception &e)
                {
                }

                Job *newJob = mp.extractMax();
                policy->dequeue();
                newJob->waitTime = std::chrono::high_resolution_clock::now().time_since_epoch().count() - newJob->startTime;
                int durationInS = static_cast<int>(std::chrono::nanoseconds(newJob->waitTime).count()) / 1000000000;
                newJob->waitTimeLabel->setText(std::to_string(durationInS) + "s");
                ComputationThread cpu = new ComputationThread(newJob, policy, textArea,
                                                              textField, newJob->progressBar, newJob->burstTimeLabel);
                cpu.start();

                try
                {
                    cpu.join();
                }
                catch (const std::exception &ex)
                {
                }
            }
        }
        else
        {
            MaxPriorityQueue tempmp;

            for (int i = 0; i < jobBatch.length; i++)
            {
                int priority = static_cast<int>(jobBatch[i]->burstTime);
                JProgressBar *pbar = pbars[i];
                JLabel *burstTime = burstTimes[i];
                jobBatch[i]->progressBar = pbar;
                jobBatch[i]->burstTimeLabel = burstTime;
                jobBatch[i]->priority = priority;
                jobBatch[i]->waitTimeLabel = waitingTimes[i];
                priorities[i]->setText(std::to_string(jobBatch[i]->priority));
                tempmp.insert(jobBatch[i]);
            }

            while (!tempmp.isEmpty())
            {
                policy->enqueue(tempmp.extractMax());
            }

            while (!policy->isEmpty())
            {
                long long arrivalTime = policy->peek()->arrivalTime;
                try
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(arrivalTime));
                }
                catch (const std::exception &e)
                {
                }

                Job *newJob = policy->dequeue();
                newJob->waitTime = std::chrono::high_resolution_clock::now().time_since_epoch().count() - newJob->startTime;
                int durationInS = static_cast<int>(std::chrono::nanoseconds(newJob->waitTime).count()) / 1000000000;
                newJob->waitTimeLabel->setText(std::to_string(durationInS) + "s");
                ComputationThread cpu = new ComputationThread(newJob, policy, textArea,
                                                              textField, newJob->progressBar, newJob->burstTimeLabel);
                cpu.start();

                try
                {
                    cpu.join();
                }
                catch (const std::exception &ex)
                {
                }
            }
        }

        std::cout << "GOT OUT" << std::endl;
        if (CalcSimulation::algo != "Priority Scheduling" &&
            CalcSimulation::algo != "Shortest Job First")
        {
            try
            {
                for (int j = 0; j < SchedulingGUI::NUM_OF_PROCESSES; j++)
                    myThreads[j]->join();
            }
            catch (const std::exception &ex)
            {
            }
        }

        textField->setText("Idle");
        textField->setForeground(Color::red);

        long long avgWaitTime = 0;
        long long avgTurnaroundTime = 0;
        long long totalExecutionTime = 0;

        for (int j = 0; j < jobBatch.length; j++)
        {
            avgWaitTime += jobBatch[j]->waitTime;
            avgTurnaroundTime += jobBatch[j]->endTime;
        }

        avgWaitTime /= jobBatch.length;
        avgWaitTime = std::chrono::nanoseconds(avgWaitTime).count() / 1000000000;
        CalcSimulation::avgWaitField->setText(std::to_string(avgWaitTime) + "s");

        avgTurnaroundTime = std::chrono::nanoseconds(avgTurnaroundTime / jobBatch.length).count() / 1000000000;
        CalcSimulation::avgServeField->setText(std::to_string(avgTurnaroundTime) + "s");

        totalExecutionTime = std::chrono::high_resolution_clock::now().time_since_epoch().count() - CalcSimulation::STRTTIME;
        totalExecutionTime = std::chrono::nanoseconds(totalExecutionTime).count() / 1000000000;
        CalcSimulation::totalExecField->setText(std::to_string(totalExecutionTime) + "s");
    }
};
