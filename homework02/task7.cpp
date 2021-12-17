int circleFunc(int n) {
    int r_2 = 0;

    for (int d = 1; d <= n; d += 2)
    {
        if (n % d == 0)
            r_2 += d % 4 == 1 ? 1 : -1;
    }
    return r_2 * 4;
}


void f() {
    int R, n = 1;
    std::cout << "Enter R: ";
    std::cin >> R;

    for (int i = 1; i <= R * R; i++)
    {
        n += circleFunc(i);
    }
    std::cout << n << std::endl;
}
int main() {
    f();
    return 0;
}
