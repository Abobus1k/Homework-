#include <iostream>

int main() {
    int h_start, min_start, sec_start, h_end, min_end, sec_end;
    std::cout << "¬ведите час начала процесса: ";
    std::cin >> h_start;
    std::cout << "¬ведите минуту начала процесса: ";
    std::cin >> min_start;
    std::cout << "¬ведите секунду начала процесса: ";
    std::cin >> sec_start;
    std::cout << "¬ведите час конца процесса: ";
    std::cin >> h_end;
    std::cout << "¬ведите минуту конца процесса: ";
    std::cin >> min_end;
    std::cout << "¬ведите секунду конца процесса: ";
    std::cin >> sec_end;

    if (min_start > min_end)
    {
        if (sec_start > sec_end)
        {
            std::cout << h_start - h_end << ":" << (60 + min_end) - min_start << ":" << (60 + sec_end) - sec_start << std::endl;
        }
        else {
            std::cout << h_start - h_end << ":" << (60 + min_end) - min_start << ":" << sec_end - sec_start << std::endl;
        }
    }
    else {
        if (sec_start > sec_end)
        {
            std::cout << h_start - h_end << ":" << min_end - min_start << ":" << (60 + sec_end) - sec_start << std::endl;
        }
        else {
            std::cout << h_start - h_end << ":" << min_end - min_start << ":" << sec_end - sec_start << std::endl;
        }
    }
    return 0;
}