#include <iostream>
#include <vector>
#include <stdexcept>

class Job
{
public:
    std::string processID;
    int priority;
};

class MaxPriorityQueue
{
private:
    std::vector<Job> arr;

public:
    MaxPriorityQueue() {}

    int capacity() const
    {
        return arr.capacity();
    }

    int size() const
    {
        return arr.size();
    }

    bool isEmpty() const
    {
        return arr.empty();
    }

    void insert(const Job &job)
    {
        arr.push_back(job);
        bubbleUp(size() - 1);
    }

    Job extractMax()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Error: priority queue is empty");
        }
        Job max = arr.front();
        std::swap(arr.front(), arr.back());
        arr.pop_back();
        bubbleDown(0);
        return max;
    }

    Job getMax() const
    {
        if (isEmpty())
        {
            throw std::runtime_error("Error: priority queue is empty");
        }
        return arr.front();
    }

    bool contains(const Job &job) const
    {
        for (const Job &j : arr)
        {
            if (j.processID == job.processID)
            {
                return true;
            }
        }
        return false;
    }

    void removeAt(int index)
    {
        if (index < 0 || index >= size())
        {
            throw std::runtime_error("Error: invalid index");
        }
        std::swap(arr[index], arr.back());
        arr.pop_back();
        bubbleDown(index);
    }

    int getPriority(int index) const
    {
        if (index < 0 || index >= size())
        {
            throw std::runtime_error("Error: invalid index");
        }
        return arr[index].priority;
    }

private:
    void bubbleUp(int index)
    {
        int parent = (index - 1) / 2;
        while (index > 0 && arr[index].priority > arr[parent].priority)
        {
            std::swap(arr[index], arr[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void bubbleDown(int index)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size() && arr[leftChild].priority > arr[largest].priority)
        {
            largest = leftChild;
        }

        if (rightChild < size() && arr[rightChild].priority > arr[largest].priority)
        {
            largest = rightChild;
        }

        if (largest != index)
        {
            std::swap(arr[index], arr[largest]);
            bubbleDown(largest);
        }
    }
};

int main()
{
    // Example usage of the MaxPriorityQueue class
    MaxPriorityQueue mp;

    Job job1;
    job1.processID = "Process1";
    job1.priority = 10;
    mp.insert(job1);

    Job job2;
    job2.processID = "Process2";
    job2.priority = 5;
    mp.insert(job2);

    Job job3;
    job3.processID = "Process3";
    job3.priority = 8;
    mp.insert(job3);

    std::cout << "Max priority: " << mp.getMax().priority << std::endl;
    std::cout << "Extracted max: " << mp.extractMax().priority << std::endl;
    std::cout << "Max priority: " << mp.getMax().priority << std::endl;

    return 0;
}
