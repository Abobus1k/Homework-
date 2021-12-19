#include <iostream>
#include <string>

void swap(char& a, char& b)
{
    char temp;
    temp = b;
    b = a;
    a = temp;
}

std::string reverse_words(std::string str)
{
    int x = str.length();
    int pr = 0;
    int curr = 0;

    while (curr < x)
    {
        while (str[pr] == ' ')
            pr++;

        while (curr != x - 1 && str[curr + 1] != ' ')
            curr++;

        for (int i = pr; i < pr + (curr - pr + 1)/2; i++)
            swap(str[i], str[curr - (i - pr)]);

        pr = ++curr;
    }

    return str;
}
