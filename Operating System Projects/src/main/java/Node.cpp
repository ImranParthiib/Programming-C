class Job;

class Node
{
public:
    Node *next;
    Job *job;

    Node(Job *job) : job(job), next(nullptr) {}
};
