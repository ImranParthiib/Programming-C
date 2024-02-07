#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <chrono>
#include <thread>

struct Job
{
    int processID;
    long long startTime;
    long long waitTime;
};

struct Node
{
    Job job;
    Node *next;

    Node(Job job) : job(job), next(nullptr) {}
};

class FCFSPolicy
{
    std::ifstream sourceFile;
    Node *head;
    Node *tail;

public:
    FCFSPolicy(const std::string &sourceFilePath)
    {
        sourceFile.open(sourceFilePath);
        if (!sourceFile.is_open())
        {
            throw std::runtime_error("Failed to open source file");
        }
        head = tail = nullptr;
    }

    ~FCFSPolicy()
    {
        sourceFile.close();
        clearQueue();
    }

    bool isEmpty() const { return head == nullptr; }

    void enqueue(const Job &job)
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

    Job dequeue()
    {
        if (isEmpty())
        {
            return Job(); // Return an empty Job if the queue is empty
        }
        else
        {
            Job tempJob = head->job;
            Node *tempNode = head;
            head = head->next;
            delete tempNode;
            tempJob.waitTime = std::chrono::high_resolution_clock::now().time_since_epoch().count() - tempJob.startTime;
            return tempJob;
        }
    }

    void allocateCPU(Job &job)
    {
        try
        {
            std::string line;
            while (std::getline(sourceFile, line))
            {
                // Process the line
            }

            std::string remProcesses = getRemainingProcesses();
        }
        catch (const std::exception &ex)
        {
            std::cout << "IO Error" << std::endl;
            return;
        }
    }

    void enqueueAtHead(const Job &job)
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

    Node *peek() const
    {
        return head;
    }

    std::string getRemainingProcesses() const
    {
        Node *trav = head;
        std::string rem;
        if (isEmpty())
        {
            return "";
        }
        else
        {
            while (trav != nullptr)
            {
                rem += std::to_string(trav->job.processID) + " ";
                trav = trav->next;
            }
        }
        return rem;
    }

    void clearQueue()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
    }
};

int main()
{
    FCFSPolicy fcfsPolicy("source.txt");

    // Test the FCFSPolicy class
    Job job1 = {1, std::chrono::high_resolution_clock::now().time_since_epoch().count(), 0};
    Job job2 = {2, std::chrono::high_resolution_clock::now().time_since_epoch().count(), 0};

    fcfsPolicy.enqueue(job1);
    fcfsPolicy.enqueue(job2);

    Job dequeuedJob = fcfsPolicy.dequeue();
    std::cout << "Dequeued Job: " << dequeuedJob.processID << std::endl;

    std::cout << "Remaining Processes: " << fcfsPolicy.getRemainingProcesses() << std::endl;

    return 0;
}
