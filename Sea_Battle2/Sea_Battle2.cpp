// Sea_Battle2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
short box_size = 10;
short Line = 33;
void print_line() {
    for (int i = 0; i < Line; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

short Transformation(char z) {
    if (z == 'a' || z == 'A') return 0;
    if (z == 'b' || z == 'B') return 1;
    if (z == 'c' || z == 'C') return 2;
    if (z == 'd' || z == 'D') return 3;
    if (z == 'e' || z == 'E') return 4;
    if (z == 'f' || z == 'F') return 5;
    if (z == 'g' || z == 'G') return 6;
    if (z == 'h' || z == 'H') return 7;
    if (z == 'i' || z == 'I') return 8;
    if (z == 'j' || z == 'J') return 9;
    else return -1;
}

class Ships {
protected:
    bool* Ship;
    short Size;
    bool Condition;
public:
    Ships(short Size) {
        this->Size = Size;
        Ship = new bool[this->Size];
        Condition = true;
        for (short i = 0; i < this->Size; i++) {
            Ship[i] = false;
        }
        std::cout << "Ship " << this->Size << " deck created" << std::endl;
    }
    short get_size() {
        return Size;
    }
    bool* adress(short i) {
        return &Ship[i];
    }
    ~Ships() {
        delete[] Ship;
    }
};

class Sea_Battle {
private:
    bool*** Player_box;
    bool*** Comp_box;
    Ships Four_D_P = Ships(4);
    Ships Four_D_C = Ships(4);
    Ships Three_D_P1 = Ships(3);
    Ships Three_D_P2 = Ships(3);
    Ships Three_D_C1 = Ships(3);
    Ships Three_D_C2 = Ships(3);
    Ships Two_D_P1 = Ships(2);
    Ships Two_D_P2 = Ships(2);
    Ships Two_D_P3 = Ships(2);
    Ships Two_D_C1 = Ships(2);
    Ships Two_D_C2 = Ships(2);
    Ships Two_D_C3 = Ships(2);
    Ships Single_D_P1 = Ships(1);
    Ships Single_D_P2 = Ships(1);
    Ships Single_D_P3 = Ships(1);
    Ships Single_D_P4 = Ships(1);
    Ships Single_D_C1 = Ships(1);
    Ships Single_D_C2 = Ships(1);
    Ships Single_D_C3 = Ships(1);
    Ships Single_D_C4 = Ships(1);
public:
    Sea_Battle() {
        Player_box = new bool** [box_size];
        Comp_box = new bool** [box_size];
        for (short i = 0; i < box_size; i++) {
            Player_box[i] = new bool* [box_size];
            Comp_box[i] = new bool* [box_size];
        }
        for (short i = 0; i < box_size; i++) {
            for (short j = 0; j < box_size; j++) {
                Player_box[i][j] = nullptr;
                Comp_box[i][j] = nullptr;
            }
        }
    }

    void box_out() {
        print_line();
        std::cout << "|||A |B |C |D |E |F |G |H |I |J |\n";
        print_line();
        for (short i = 0; i < box_size; i++) {
            std::cout << i << " ";
            for (short j = 0; j < box_size; j++) {
                if (Player_box[i][j] == nullptr) {
                    std::cout << "|  ";
                }
                else {
                    std::cout << "|##";
                }
            }
            std::cout << "|\n";
            print_line();
        }
    }

    bool check_first(short x, short y, bool* object) {
        if (x == 0 && y == 0) {
            for (short i = x; i < x + 2; i++) {
                for (short j = y; j < y + 2; j++) {
                    if (Player_box[i][j] != nullptr && Player_box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
        if (x == 0 && y == 9) {
            for (short i = x; i < x + 2; i++) {
                for (short j = y - 1; j < y + 1; j++) {
                    if (Player_box[i][j] != nullptr && Player_box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
        if (x == 9 && y == 0) {
            for (short i = x - 1; i < x + 1; i++) {
                for (short j = y; j < y + 2; j++) {
                    if (Player_box[i][j] != nullptr && Player_box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
        if (x == 9 && y == 9) {
            for (short i = x - 1; i < x + 1; i++) {
                for (short j = y - 1; j < y + 1; j++) {
                    if (Player_box[i][j] != nullptr && Player_box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
        if (x == 0) {
            for (short i = x; i < x + 2; i++) {
                for (short j = y - 1; j < y + 2; j++) {
                    if (Player_box[i][j] != nullptr && Player_box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
        if (x == 9) {
            for (short i = x - 1; i < x + 1; i++) {
                for (short j = y - 1; j < y + 2; j++) {
                    if (Player_box[i][j] != nullptr && Player_box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
        if (y == 0) {
            for (short i = x - 1; i < x + 2; i++) {
                for (short j = y; j < y + 2; j++) {
                    if (Player_box[i][j] != nullptr && Player_box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
        if (y == 9) {
            for (short i = x - 1; i < x + 2; i++) {
                for (short j = y - 1; j < y + 1; j++) {
                    if (Player_box[i][j] != nullptr && Player_box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
        else {
            for (short i = x - 1; i < x + 2; i++) {
                for (short j = y - 1; j < y + 2; j++) {
                    if (Player_box[i][j] != nullptr && Player_box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
    }
    void check_up(short x, short y, bool* object, short size, bool* side) {
        short steps = size - 1;
        if (x + steps > 9) {
            *side = false;
            return;
        }
        else {

            for (short i = x + 1; i < x + size; i++) {
                if (!check_first(i, y, object)) {
                    *side = false;
                    return;
                }
                else {
                    *side = true;
                }
            }            
        }
    }

    void check_down(short x, short y, bool* object, short size, bool* side) {
        short steps = size - 1;
        if (x - steps < 0) {
            *side = false;
            return;
        }
        else {

            for (short i = x - 1; i < x - size; i--) {
                if (!check_first(i, y, object)) {
                    *side = false;
                    return;
                }
                else {
                    *side = true;
                }
            }
        }
    }

    void check_right(short x, short y, bool* object, short size, bool* side) {
        short steps = size - 1;
        if (y + steps > 9) {
            side = false;
            return;
        }
        else {

            for (short i = y + 1; i < y + size; i++) {
                if (!check_first(x, i, object)) {
                    *side = false;
                    return;
                }
                else {
                    *side = true;
                }
            }
        }
    }

    void check_left(short x, short y, bool* object, short size, bool* ) {
        short steps = size - 1;
        if (y - steps < 0) {
            return false;
        }
        else {

            for (short i = y - 1; i < y - size; i--) {
                if (!check_first(x, i, object)) {
                    return false;
                }
            }
            return true;
        }
    }

    void  Placement() {
        setlocale(LC_ALL, "Russian");
        bool up = false;
        bool down = false;
        bool right = false;
        bool left = false;
        /*bool* up_ref = &up;
        bool* down_ref = &down;
        bool* right_ref = &right;
        bool* left_ref = &left;*/
        short x = 0, y = 0;
        char z = ' ';
        char Ch = ' ';
        std::cout << "Установите четырех палубный корабль:\nВведите букву A - J - ";
        std::cin >> z;
        y = Transformation(z);
        if (y == -1) {
            while (y == -1) {
                std::cout << "Неверный ввод.\nВведите букву A - J - ";
                std::cin >> z;
                y = Transformation(z);
            }
        }
        std::cout << "Введите цифру 0 - 9 - ";
        std::cin >> x;
        Player_box[x][y] = Four_D_P.adress(0);
        check_up(x, y, Four_D_P.adress(0), Four_D_P.get_size(), &up);
        check_down(x, y, Four_D_P.adress(0), Four_D_P.get_size(), &down);
        check_left(x, y, Four_D_P.adress(0), Four_D_P.get_size(), &left);
        if (Ch == 'N' || Ch == 'n') {
            if (x < 7) {
                Player_box[x + 1][y] = Four_D_P.adress(1);
                Player_box[x + 2][y] = Four_D_P.adress(2);
                Player_box[x + 3][y] = Four_D_P.adress(3);
            }
            else {
                Player_box[x - 1][y] = Four_D_P.adress(1);
                Player_box[x - 2][y] = Four_D_P.adress(2);
                Player_box[x - 3][y] = Four_D_P.adress(3);
            }
        }
        if (Ch == 'Y' || Ch == 'y') {
            if (y < 7) {
                Player_box[x][y + 1] = Four_D_P.adress(1);
                Player_box[x][y + 2] = Four_D_P.adress(2);
                Player_box[x][y + 3] = Four_D_P.adress(3);
            }
            else {
                Player_box[x][y - 1] = Four_D_P.adress(1);
                Player_box[x][y - 2] = Four_D_P.adress(2);
                Player_box[x][y - 3] = Four_D_P.adress(3);
            }
        }
        box_out();
        std::cout << "Установите первый трех палубный корабль:\nВведите букву A - J - ";
        std::cin >> z;
        y = Transformation(z);
        if (y == -1) {
            while (y == -1) {
                std::cout << "Неверный ввод.\nВведите букву A - J - ";
                std::cin >> z;
                y = Transformation(z);
            }
        }
        std::cout << "Введите цифру 0 - 9 - ";
        std::cin >> x;
        if (!check(x, y, Three_D_P1.adress(0))) {
            while (!check(x, y, Three_D_P1.adress(0))) {
                std::cout << "Поле недоступно.\n";
                std::cout << "Установите первый трех палубный корабль:\nВведите букву A - J - ";
                std::cin >> z;
                y = Transformation(z);
                if (y == -1) {
                    while (y == -1) {
                        std::cout << "Неверный ввод.\nВведите букву A - J - ";
                        std::cin >> z;
                        y = Transformation(z);
                    }
                }
                std::cout << "Введите цифру 0 - 9 - ";
                std::cin >> x;
            }
        }
        Player_box[x][y] = Three_D_P1.adress(0);
        std::cout << "Установить по горизонтали?\nY - N - ";
        std::cin >> Ch;
        if (Ch == 'N' || Ch == 'n') {
            if (x < 8) {
                if (check(x + 1, y, Three_D_P1.adress(0)) && check(x + 2, y, Three_D_P1.adress(0))) {
                    Player_box[x + 1][y] = Three_D_P1.adress(1);
                    Player_box[x + 2][y] = Three_D_P1.adress(2);
                }

                else {
                    if ((check(x + 1, y, Three_D_P1.adress(0)) && check(x - 1, y, Three_D_P1.adress(0))) && x > 0) {
                        Player_box[x + 1][y] = Three_D_P1.adress(1);
                        Player_box[x - 1][y] = Three_D_P1.adress(2);
                    }
                    if ((check(x - 1, y, Three_D_P1.adress(0)) && check(x - 2, y, Three_D_P1.adress(0))) && x > 1) {
                        Player_box[x - 1][y] = Three_D_P1.adress(1);
                        Player_box[x - 2][y] = Three_D_P1.adress(2);
                    }
                    else {
                        std::cout << "Не возможно установить по вертикали";
                    }
                }
            }
            else {
                if (check(x - 1, y, Three_D_P1.adress(0)) && check(x - 2, y, Three_D_P1.adress(0)) && x == 9 ) {
                    Player_box[x - 1][y] = Three_D_P1.adress(1);
                    Player_box[x - 2][y] = Three_D_P1.adress(2);
                }
                if (check(x + 1, y, Three_D_P1.adress(0)) && check(x - 1, y, Three_D_P1.adress(0)) &&  x <= 8) {
                    Player_box[x + 1][y] = Three_D_P1.adress(1);
                    Player_box[x - 1][y] = Three_D_P1.adress(2);
                }
                else {
                    std::cout << "Не возможно установить по вертикали";
                }

            }
        }
    }

    ~Sea_Battle() {
        for (short i = 0; i < box_size; i++) {
            delete[] Player_box[i];
            delete[] Comp_box[i];
        }
        delete[] Player_box;
        delete[] Comp_box;
    }
};

int main()
{
    Sea_Battle A;
    A.box_out();
    A.Placement();
    A.box_out();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

