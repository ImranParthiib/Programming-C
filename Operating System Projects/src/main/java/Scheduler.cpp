class Job;
class Node;

class Scheduler
{
public:
   virtual void allocateCPU(Job *job) = 0;
   virtual Job *dequeue() = 0;
   virtual void enqueue(Job *job) = 0;
   virtual std::string getRemainingProcesses() = 0;
   virtual bool isEmpty() = 0;
   virtual Node *peek() = 0;
};
