#include <iostream>
inline int floor_number(int room, int section) {
    int x = room - section * (section + 1) * (2 * section + 1) / 6, mod = section + 1;
    return (x - 1) / mod + 1;
}

int main()
{
    int f = 1, r = 1, room;
    std::cout << "Enter number of room: ";
    std::cin >> room;

    if (room == 1) {
        std::cout << "Floor: 1, Number from left: 1" << std::endl;
        return 0;
    }

    while (r < room)
    {
        f += 1;
        r = f * (f + 1) * (2 * f + 1) / 6;
    }
    f -= 1;

    int floor_num = f * (f + 1) / 2 + floor_number(room, f);
    int room_num = (room - f * (f + 1) * (2 * f + 1) / 6 - 1) % (f + 1) + 1;

    std::cout << "floor: " << floor_num << ", number on the left : " << room_num << std::endl;
}