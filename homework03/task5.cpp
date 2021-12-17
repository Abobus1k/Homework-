#include <iostream>


int main()
{
    std::cout << "Enter Height/2 of rhomb: ";
    int num, i;
    std::cin >> num;
    std::cout << "Enter amount of rhombs: ";
    int amount;
    std::cin >> amount;

    for (i = 1; i <= num; ++i)
        {
            for (int counter = 0; counter < amount; ++counter)
            {
                for (int j = 0; j < num - i; j++) std::cout << " ";
                for (int k = 0; k < i * 2 - 1; k++) std::cout << "*";
                for (int j = 0; j < num - i; j++) std::cout << " ";
            }
                std::cout << std::endl;
           
        }
            
    i -= 2;
    for (; i >= 0; --i)
        {
            for (int counter = 0; counter < amount; ++counter)
            {
                for (int j = 0; j < num - i; ++j) std::cout << " ";
                for (int k = 0; k < i * 2 - 1; ++k) std::cout << "*";
                for (int j = 0; j < num - i; ++j) std::cout << " ";
            }
                std::cout << std::endl;
            
        }
    return 0;
    }
    }
    return 0;
}
