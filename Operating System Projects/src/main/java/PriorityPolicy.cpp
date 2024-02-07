#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class Job;
class Node;

class Scheduler
{
public:
    virtual bool isEmpty() = 0;
    virtual void enqueue(Job *job) = 0;
    virtual Job *dequeue() = 0;
    virtual void allocateCPU(Job *job) = 0;
    virtual void enqueueAtHead(Job *job) = 0;
    virtual Node *peek() = 0;
};

class PriorityPolicy : public Scheduler
{
    std::ifstream sourceFile;
    Node *head;
    Node *tail;

public:
    PriorityPolicy(const std::string &sourceFileName) : head(nullptr), tail(nullptr)
    {
        sourceFile.open(sourceFileName);
    }

    bool isEmpty() override { return head == nullptr; }

    void enqueue(Job *job) override
    {
        Node *newNode = new Node(job);
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    Job *dequeue() override
    {
        if (isEmpty())
        {
            return nullptr;
        }
        else
        {
            Job *tempJob = head->job;
            Node *temp = head;
            head = head->next;
            delete temp;
            tempJob->waitTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - tempJob->startTime;
            return tempJob;
        }
    }

    void allocateCPU(Job *job) override
    {
        try
        {
            std::string str;
            while (std::getline(sourceFile, str))
            {
            }

            std::string remProcesses = getRemainingProcesses();
        }
        catch (std::exception &ex)
        {
            std::cout << "IO Error" << std::endl;
            return;
        }
    }

    void enqueueAtHead(Job *job) override
    {
        Node *newNode = new Node(job);
        if (isEmpty())
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    Node *peek() override
    {
        return head;
    }

    std::string getRemainingProcesses()
    {
        Node *trav = head;
        std::string rem;
        if (isEmpty())
            return "";
        else
        {
            while (trav != nullptr)
            {
                rem += trav->job->processID + " ";
                trav = trav->next;
            }
        }
        return rem;
    }
};

class Job
{
public:
    long burstTime;
    long arrivalTime;
    std::string processID;
    long startTime;
    long endTime;
    long waitTime;
    int lastRemainingBurst;
    int pBarValue;
    int priority;

    Job(const std::string &processID, long arrivalTime, long burstTime, long startTime)
        : processID(processID), arrivalTime(arrivalTime), burstTime(burstTime), startTime(startTime),
          lastRemainingBurst(static_cast<int>(burstTime)), pBarValue(0) {}
};

class Node
{
public:
    Node *next;
    Job *job;

    Node(Job *job) : job(job), next(nullptr) {}
};
