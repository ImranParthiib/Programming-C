#include <iostream>
#include <string>
#include <chrono>
#include <thread>

class TitleThread : public std::thread
{
private:
    std::string text;
    JLabel *label;
    long sleepTime;

public:
    TitleThread(std::string text, JLabel *label, long time)
    {
        this->text = text;
        this->label = label;
        sleepTime = time;
    }

    void run()
    {
        std::string str;
        for (int i = 0; i < text.length(); i++)
        {
            str += text[i];
            label->setText(str);
            try
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
            }
            catch (std::exception &ex)
            {
                // Handle InterruptedException
            }
        }
    }
};
