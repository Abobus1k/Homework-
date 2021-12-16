#include <iostream>

int main() {
    int s_start, m_start, h_start, time_start;
    int s_end, m_end, h_end, time_end;
    std::cout << "enter h1, m1, s1: ";
    std::cin >> h_start >> m_start >> s_start;
    std::cout << "enter h2, m2, s2: ";
    std::cin >> h_end >> m_end >> s_end;
    time_start = h_start * 60 * 60 + m_start * 60 + s_start;
    time_end = h_end * 60 * 60 + m_end * 60 + s_end;
    int dif_time = time_end - time_start;
    int dif_time_h = dif_time / 3600;
    dif_time %= 3600;
    int dif_time_m = dif_time / 60;
    dif_time %= 60;
    std::cout << dif_time_h << " hour" << dif_time_m << " min" << dif_time << " sec" << '\n';
}