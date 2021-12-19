using namespace std;

string reverseString(string str)
{
    int x = 0;
    int i = 0;
    char curr;
    x = str.length() - 1;
    while (i < x)
    {
        curr = str[i];
        str[i] = str[x];
        str[x] = curr;
        i++;
        x--;
    }
    return str;
}