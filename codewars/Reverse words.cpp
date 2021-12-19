std::string reverseString(std::string str) {
    int n = str.length();
    std::string reverse = "";
    for (int i = n - 1; i >= 0; --i)
    {
        reverse += str.at(i);
    }
    return reverse;
}

std::string reverse_words(std::string str)
{
    std::string s = "", word = "";
    int x = str.length();
    bool w = false;

    for (int i = 0; i < x; ++i)
    {
        int b = str.at(i);
        if (b != ' ') {
            word += str.at(i);
            w = true;
        }
        else {
            if (w) {
                w = false;
                s += reverseString(word);
                word = "";
            }
            s += str.at(i);
        }
    }
    if (w) {
        s += reverseString(word);
    }
    return s;
}