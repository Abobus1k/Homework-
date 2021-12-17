#include <iostream>


int main()
{
    std::cout << "Enter Height/2\n";
    int num;
    std::cin >> num;
    std::cout << "Enter amount\n";
    int amount;
    std::cin >> amount;

    for (int i = 1; i <= num; ++i)
    {
        for (int counter = 0; counter < amount + 1; ++counter)
        {
            for (int j = 0; j < num - i; j++) std::cout << " ";
            for (int k = 0; k < i * 2 - 1; k++) std::cout << "*";
            for (int j = 0; j < num - i; j++) std::cout << " ";
        }
        std::cout << std::endl;

    }

    for (int i=num-1; i >= 0; --i)
    {
        for (int counter = 0; counter < amount + 1; ++counter)
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
    }
    return 0;
}
