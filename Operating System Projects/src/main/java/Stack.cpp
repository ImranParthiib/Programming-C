#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Node class for singly linked list
class Node
{
public:
    Job job;
    Node *next;

    Node(Job job)
    {
        this->job = job;
        next = nullptr;
    }
};

// Scheduler interface
class Scheduler
{
public:
    virtual void enqueue(Job job) = 0;
    virtual Job dequeue() = 0;
};

// Stack implementation with singly linked list
class Stack : public Scheduler
{
private:
    Node *top;
    File sourceFile;

public:
    Stack()
    {
        top = nullptr;
    }

    Stack(File sourceFile)
    {
        this->sourceFile = sourceFile;
        top = nullptr;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    Node *peek()
    {
        if (isEmpty())
            throw runtime_error("StackUnderFlow");
        return top;
    }

    void enqueue(Job job)
    {
        Node *newest = new Node(job);
        if (isEmpty())
            top = newest;
        else
        {
            newest->next = top;
            top = newest;
        }
    }

    Job dequeue()
    {
        if (isEmpty())
            throw runtime_error("StackUnderflow");
        Job data = top->job;
        Node *temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    string getRemainingProcesses()
    {
        Node *trav = top;
        string rem;
        if (isEmpty())
            return "";
        else
        {
            while (trav != nullptr)
            {
                rem += to_string(trav->job.processID) + " ";
                trav = trav->next;
            }
        }
        return rem;
    }

    void allocateCPU(Job job)
    {
        try
        {
            ifstream file(sourceFile);
            string line;
            while (getline(file, line))
            {
                // Perform processing on each line of the source file
            }

            string remProcesses = getRemainingProcesses();
            // Further processing using the remaining processes
        }
        catch (exception &ex)
        {
            cout << "IO Error" << endl;
            return;
        }
    }
};
