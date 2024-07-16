// Sea_Battle2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <ctime>
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

struct Coord{
    short x;
    short y;
};

class Ship {
protected:
    bool* ship;
    Coord start;
    Coord end;
    short size;
    bool condition;
public:
    Ship(short Size) {
        this->size = Size;
        ship = new bool[this->size];
        condition = true;
        start.x = 0;
        start.y = 0;
        end.x = 0;
        end.y = 0;
        for (short i = 0; i < this->size; i++) {
            ship[i] = false;
        }
        std::cout << "Ship " << this->size << " deck created" << std::endl;
    }
    
    bool get_condition() {
        return condition;
    }

    bool check_condition() {
        for (short i = 0; i < size; i++) {
            if (!ship[i]) {
                return true;
            }
        }
        return condition = false;
    }

    short shoot(bool* coord) {
        for (short i = 0; i < size; i++) {
            if (coord == ship + i && !ship[i]) {
                ship[i] = true;
                if (check_condition()) {
                    std::cout << "Ранил!\n";
                    return  1;
                }
                else {
                    std::cout << "Убил!!!\n";
                    return  2;
                }
            }
        }
        return 0;
    }

    short get_size() {
        return size;
    }

    bool* adress(short i) {
        return &ship[i];
    }
    
    void set_start(short x, short y) {
        start.x = x;
        start.y = y;
    }

    void set_end(short x, short y) {
        end.x = x;
        end.y = y;
    }

    short get_start_x() {
        return start.x;
    }

    short get_start_y() {
        return start.y;
    }

    short get_end_x() {
        return end.x;
    }

    short get_end_y() {
        return end.y;
    }

    ~Ship() {
        delete[] ship;
    }
};

struct Ship_complect {
    Ship* Four_D;
    Ship* Three_D_1;
    Ship* Three_D_2;
    Ship* Two_D_1;
    Ship* Two_D_2;
    Ship* Two_D_3;
    Ship* Single_D_1;
    Ship* Single_D_2;
    Ship* Single_D_3;
    Ship* Single_D_4;
    Ship* Hitting;
    Ship_complect() {
        Four_D = nullptr;
        Three_D_1 = nullptr;
        Three_D_2 = nullptr;
        Two_D_1 = nullptr;
        Two_D_2 = nullptr;
        Two_D_3 = nullptr;
        Single_D_1 = nullptr;
        Single_D_2 = nullptr;
        Single_D_3 = nullptr;
        Single_D_4 = nullptr;
        Hitting = nullptr;
    }
    // Поиск конкретного корабля
    short shoot(bool* coord) {
        short kick = Single_D_1->shoot(coord);
        if (kick == 1 || kick == 2) {
            Hitting = Single_D_1;
            return kick;
        }
        else {
            kick = Single_D_2->shoot(coord);
            if (kick == 1 || kick == 2) {
                Hitting = Single_D_2;
                return kick;
            }
            else {
                kick = Single_D_3->shoot(coord);
                if (kick == 1 || kick == 2) {
                    Hitting = Single_D_3;
                    return kick;
                }
                else {
                    kick = Single_D_4->shoot(coord);
                    if (kick == 1 || kick == 2) {
                        Hitting = Single_D_4;
                        return kick;
                    }
                    else {
                        kick = Two_D_1->shoot(coord);
                        if (kick == 1 || kick == 2) {
                            Hitting = Two_D_1;
                            return kick;
                        }
                        else {
                            kick = Two_D_2->shoot(coord);
                            if (kick == 1 || kick == 2) {
                                Hitting = Two_D_2;
                                return kick;
                            }
                            else {
                                kick = Two_D_3->shoot(coord);
                                if (kick == 1 || kick == 2) {
                                    Hitting = Two_D_3;
                                    return kick;
                                }
                                else {
                                    kick = Three_D_1->shoot(coord);
                                    if (kick == 1 || kick == 2) {
                                        Hitting = Three_D_1;
                                        return kick;
                                    }
                                    else {
                                        kick = Three_D_2->shoot(coord);
                                        if (kick == 1 || kick == 2) {
                                            Hitting = Three_D_2;
                                            return kick;
                                        }
                                        else {
                                            kick = Three_D_2->shoot(coord);
                                            if (kick == 1 || kick == 2) {
                                                Hitting = Four_D;
                                                return kick;
                                            }
                                            else {
                                                return kick;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    }
};

class Sea_Battle {
private:
    bool*** Player_box;
    bool*** Comp_box;
    Ship_complect player;
    Ship_complect computer;
    Coord comp_seria[4];
    bool comp_shoot;
    bool hit;
public:
    Sea_Battle() {
        comp_shoot = false;
        for (short i = 0; i < 4; i++) {
            comp_seria[i].x = 0;
            comp_seria[i].y = 0;
        }
        hit = true;
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
    Ship_complect* Get_complect_comp() {
        return &computer;
    }

    Ship_complect* Get_complect_pl() {
        return &player;
    }

    bool*** Get_pl_box() {
        return Player_box;
    }

    bool*** Get_comp_box() {
        return Comp_box;
    }

    void box_out(bool ***box) {
        print_line();
        std::cout << "|||A |B |C |D |E |F |G |H |I |J |\n";
        print_line();
        for (short i = 0; i < box_size; i++) {
            std::cout << i << " ";
            for (short j = 0; j < box_size; j++) {
                if (box[i][j] == nullptr) {
                    std::cout << "|  ";
                }
                else {
                    if (!*box[i][j]) {
                        std::cout << "|##";
                    }
                    else {
                        if (box[i][j] != &hit) {
                            std::cout << "|**";
                        }
                        else std::cout << "|~~";
                    }
                }
            }
            std::cout << "|\n";
            print_line();
        }
    }


    void check_attack(bool*** box, short x, short y ,bool *up, bool *down, bool *right, bool *left) {
        if (x == 0 && y == 0) {
            *up = false;
            *left = false;
            if (box[x - 1][y] == &hit) {
                *down = false;
            }
            else {
                *down = true;
            }
            if (box[x][y + 1] == &hit) {
                *right = false;
            }
            else {
                *right = true;
            }
            return;
        }
        if (x == 0 && y == 9) {
            *down = false;
            *left = false;
            if (box[x + 1][y] == &hit) {
                *up = false;
            }
            else {
                *up = true;
            }
            if (box[x][y + 1] == &hit) {
                *right = false;
            }
            else {
                *right = true;
            }
            return;
        }
        if (x == 9 && y == 0) {
            *up = false;
            *right = false;
            if (box[x - 1][y] == &hit) {
                *down = false;
            }
            else {
                *down = true;
            }
            if (box[x][y - 1] == &hit) {
                *left = false;
            }
            else {
                *left = true;
            }
            return;
        }
        if (x == 9 && y == 9) {
            *down = false;
            *right = false;
            if (box[x + 1][y] == &hit) {
                *up = false;
            }
            else {
                *up = true;
            }
            if (box[x][y - 1] == &hit) {
                *left = false;
            }
            else {
                *left = true;
            }
            return;
        }
        if (x == 0) {
            up = false;
        }

     }
    // Проверка одной клетки
    bool check_first(short x, short y, bool* object, bool*** box) {
        if (x == 0 && y == 0) {
            for (short i = x; i < x + 2; i++) {
                for (short j = y; j < y + 2; j++) {
                    if (box[i][j] != nullptr && box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
        if (x == 0 && y == 9) {
            for (short i = x; i < x + 2; i++) {
                for (short j = y - 1; j < y + 1; j++) {
                    if (box[i][j] != nullptr && box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
        if (x == 9 && y == 0) {
            for (short i = x - 1; i < x + 1; i++) {
                for (short j = y; j < y + 2; j++) {
                    if (box[i][j] != nullptr && box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
        if (x == 9 && y == 9) {
            for (short i = x - 1; i < x + 1; i++) {
                for (short j = y - 1; j < y + 1; j++) {
                    if (box[i][j] != nullptr && box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
        if (x == 0) {
            for (short i = x; i < x + 2; i++) {
                for (short j = y - 1; j < y + 2; j++) {
                    if (box[i][j] != nullptr && box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
        if (x == 9) {
            for (short i = x - 1; i < x + 1; i++) {
                for (short j = y - 1; j < y + 2; j++) {
                    if (box[i][j] != nullptr && box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
        if (y == 0) {
            for (short i = x - 1; i < x + 2; i++) {
                for (short j = y; j < y + 2; j++) {
                    if (box[i][j] != nullptr && box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
        if (y == 9) {
            for (short i = x - 1; i < x + 2; i++) {
                for (short j = y - 1; j < y + 1; j++) {
                    if (box[i][j] != nullptr && box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
        else {
            for (short i = x - 1; i < x + 2; i++) {
                for (short j = y - 1; j < y + 2; j++) {
                    if (box[i][j] != nullptr && box[i][j] != object) {
                        return false;
                    }
                }
            }
            return true;
        }
    }

    //Проверка направлений
    void check_down(short x, short y, bool* object, short size, bool* side, bool*** box) {
        short steps = size - 1;
        if (x + steps > 9) {
            *side = false;
            return;
        }
        else {

            for (short i = x; i < x + size; i++) {
                if (!check_first(i, y, object, box)) {
                    *side = false;
                    return;
                }
                else {
                    *side = true;
                }
            }            
        }
    }
    void check_up(short x, short y, bool* object, short size, bool* side, bool*** box) {
        short steps = size - 1;
        if (x - steps < 0) {
            *side = false;
            return;
        }
        else {

            for (short i = x; i > x - size; i--) {
                if (!check_first(i, y, object, box)) {
                    *side = false;
                    return;
                }
                else {
                    *side = true;
                }
            }
        }
    }
    void check_right(short x, short y, bool* object, short size, bool* side, bool*** box) {
        short steps = size - 1;
        if (y + steps > 9) {
            *side = false;
            return;
        }
        else {

            for (short i = y; i < y + size; i++) {
                if (!check_first(x, i, object, box)) {
                    *side = false;
                    return;
                }
                else {
                    *side = true;
                }
            }
        }
    }
    void check_left(short x, short y, bool* object, short size, bool* side, bool*** box) {
        short steps = size - 1;
        if (y - steps < 0) {
            *side = false;
            return;
        }
        else {
            for (short i = y; i > y - size; i--) {
                if (!check_first(x, i, object, box)) {
                    *side = false;
                    return;
                }
                else {
                    *side = true;
                }
            }        
        }
    }

    // Проверка сразу всех сторон
    void Check_sides(short x, short y, bool* object, short size, bool* up, bool* down, bool* left, bool *right, bool*** box) {
        if (size == 1) {
            check_up(x, y, object, size, up, box);
            return;
        }
        check_up(x, y, object, size, up, box);
        check_down(x, y, object, size, down, box);
        check_left(x, y, object, size, left, box);
        check_right(x, y, object, size, right, box);
    }


    void Menu_placement(bool up, bool down, bool right, bool left) {
        setlocale(LC_ALL, "Russian");
        std::cout << "Выберите направление:\n";
        {
            if (up) {
                std::cout << "1 - вверх\n";
            }
            else {
                std::cout << "1 - недоступно\n";
            }
        }
        {
            if (down) {
                std::cout << "2 - вниз\n";
            }
            else {
                std::cout << "2 - недоступно\n";
            }
        }
        {
            if (left) {
                std::cout << "3 - влево\n";
            }
            else {
                std::cout << "3 - недоступно\n";
            }
        }
        {
            if (right) {
                std::cout << "4 - вправо\n";
            }
            else {
                std::cout << "4 - недоступно\n";
            }
        }
        std::cout << "- ";
    }

    // Установка корабля в выбранном направлении
    void Placement_P(short x, short y, short size, Ship* object, short choice, bool *** box) {
        switch (choice) {
        case 1:
            for (int i = 1; i < size; i++) {
                box[x - i][y] = object->adress(i);
                object->set_end(x - i, y);
            }
            break;
        case 2:
            for (int i = 1; i < size; i++) {
                box[x + i][y] = object->adress(i);
                object->set_end(x + i, y);
            }
            break;
        case 3:
            for (int i = 1; i < size; i++) {
                box[x][y - i] = object->adress(i);
                object->set_end(x, y - i);
            }
            break;
        case 4:
            for (int i = 1; i < size; i++) {
                box[x][y + i] = object->adress(i);
                object->set_end(x, y + i);
            }
            break;
        }
    }
    
    // Ручная расстановка кораблей игрока
    void  Placement() {
        setlocale(LC_ALL, "Russian");
        bool up = false;
        bool down = false;
        bool right = false;
        bool left = false;
        bool* up_ref = &up;
        bool* down_ref = &down;
        bool* right_ref = &right;
        bool* left_ref = &left;
        short x = 0, y = 0;
        char z = ' ';
        short Ch = 0;
        std::cout << "Установите четырехпалубный корабль:\nВведите букву A - J - ";
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
        player.Four_D = new Ship(4);
        player.Four_D->set_start(x, y);
        Player_box[x][y] = player.Four_D->adress(0);
        Check_sides(x, y, player.Four_D->adress(0), player.Four_D->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
        Menu_placement(up, down, right, left);
        std::cin >> Ch;
        if ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
            while ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
                std::cout << "Неверное направление\n- ";
                std::cin >> Ch;
            }
        }
        Placement_P(x, y, player.Four_D->get_size(), player.Four_D, Ch, Player_box);
        box_out(Player_box);
        std::cout << "Установите первый трехпалубный корабль:\nВведите букву A - J - ";
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
        player.Three_D_1 = new Ship(3);
        Check_sides(x, y, player.Three_D_1->adress(0), player.Three_D_1->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
        if (!up && !down && !right && !left) {
            while (!up && !down && !right && !left) {
                std::cout << "Невозможно установить корабль!\nВведите букву A - J - ";
                std::cin >> z;
                y = Transformation(z);
                std::cout << "Введите цифру 0 - 9 - ";
                std::cin >> x;
                Check_sides(x, y, player.Three_D_1->adress(0), player.Three_D_1->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
            }
        }
        player.Three_D_1->set_start(x, y);
        Player_box[x][y] = player.Three_D_1->adress(0);
        Menu_placement(up, down, right, left);
        std::cin >> Ch;
        if ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
            while ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
                std::cout << "Неверное направление\n- ";
                std::cin >> Ch;
            }
        }        
        Placement_P(x, y, player.Three_D_1->get_size(), player.Three_D_1, Ch, Player_box);
        box_out(Player_box);
        std::cout << "Установите второй трехпалубный корабль:\nВведите букву A - J - ";
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
        player.Three_D_2 = new Ship(3);
        Check_sides(x, y, player.Three_D_2->adress(0), player.Three_D_2->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
        if (!up && !down && !right && !left) {
            while (!up && !down && !right && !left) {
                std::cout << "Невозможно установить корабль!\nВведите букву A - J - ";
                std::cin >> z;
                y = Transformation(z);
                std::cout << "Введите цифру 0 - 9 - ";
                std::cin >> x;
                Check_sides(x, y, player.Three_D_2->adress(0), player.Three_D_2->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
            }
        }
        player.Three_D_2->set_start(x, y);
        Player_box[x][y] = player.Three_D_2->adress(0);
        Menu_placement(up, down, right, left);
        std::cin >> Ch;
        if ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
            while ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
                std::cout << "Неверное направление\n- ";
                std::cin >> Ch;
            }
        }      
        Placement_P(x, y, player.Three_D_2->get_size(), player.Three_D_2, Ch, Player_box);
        box_out(Player_box);
        std::cout << "Установите первый двухпалубный корабль:\nВведите букву A - J - ";
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
        player.Two_D_1 = new Ship(2);
        Check_sides(x, y, player.Two_D_1->adress(0), player.Two_D_1->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
        if (!up && !down && !right && !left) {
            while (!up && !down && !right && !left) {
                std::cout << "Невозможно установить корабль!\nВведите букву A - J - ";
                std::cin >> z;
                y = Transformation(z);
                std::cout << "Введите цифру 0 - 9 - ";
                std::cin >> x;
                Check_sides(x, y, player.Two_D_1->adress(0), player.Two_D_1->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
            }
        }
        player.Two_D_1->set_start(x, y);
        Player_box[x][y] = player.Two_D_1->adress(0);
        Menu_placement(up, down, right, left);
        std::cin >> Ch;
        if ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
            while ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
                std::cout << "Неверное направление\n- ";
                std::cin >> Ch;
            }
        }
        Placement_P(x, y, player.Two_D_1->get_size(), player.Two_D_1, Ch, Player_box);
        box_out(Player_box);
        std::cout << "Установите второй двухпалубный корабль:\nВведите букву A - J - ";
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
        player.Two_D_2 = new Ship(2);
        Check_sides(x, y, player.Two_D_2->adress(0), player.Two_D_2->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
        if (!up && !down && !right && !left) {
            while (!up && !down && !right && !left) {
                std::cout << "Невозможно установить корабль!\nВведите букву A - J - ";
                std::cin >> z;
                y = Transformation(z);
                std::cout << "Введите цифру 0 - 9 - ";
                std::cin >> x;
                Check_sides(x, y, player.Two_D_2->adress(0), player.Two_D_2->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
            }
        }
        player.Two_D_2->set_start(x, y);
        Player_box[x][y] = player.Two_D_2->adress(0);
        Menu_placement(up, down, right, left);
        std::cin >> Ch;
        if ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
            while ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
                std::cout << "Неверное направление\n- ";
                std::cin >> Ch;
            }
        }
        Placement_P(x, y, player.Two_D_2->get_size(), player.Two_D_2, Ch, Player_box);
        box_out(Player_box);
        std::cout << "Установите третий двухпалубный корабль:\nВведите букву A - J - ";
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
        player.Two_D_3 = new Ship(2);
        Check_sides(x, y, player.Two_D_3->adress(0), player.Two_D_3->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
        if (!up && !down && !right && !left) {
            while (!up && !down && !right && !left) {
                std::cout << "Невозможно установить корабль!\nВведите букву A - J - ";
                std::cin >> z;
                y = Transformation(z);
                std::cout << "Введите цифру 0 - 9 - ";
                std::cin >> x;
                Check_sides(x, y, player.Two_D_3->adress(0), player.Two_D_3->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
            }
        }
        player.Two_D_3->set_start(x, y);
        Player_box[x][y] = player.Two_D_3->adress(0);
        Menu_placement(up, down, right, left);
        std::cin >> Ch;
        if ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
            while ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
                std::cout << "Неверное направление\n- ";
                std::cin >> Ch;
            }
        }
        Placement_P(x, y, player.Two_D_3->get_size(), player.Two_D_3, Ch, Player_box);
        box_out(Player_box);
        std::cout << "Установите первый однопалубный корабль:\nВведите букву A - J - ";
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
        player.Single_D_1 = new Ship(1);
        Check_sides(x, y, player.Single_D_1->adress(0), player.Single_D_1->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
        if (!up) {
            while (!up) {
                std::cout << "Невозможно установить корабль!\nВведите букву A - J - ";
                std::cin >> z;
                y = Transformation(z);
                std::cout << "Введите цифру 0 - 9 - ";
                std::cin >> x;
                Check_sides(x, y, player.Single_D_1->adress(0), player.Single_D_1->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
            }
        }
        player.Single_D_1->set_start(x, y);
        Player_box[x][y] = player.Single_D_1->adress(0);
        player.Single_D_1->set_end(x, y);
        box_out(Player_box);
        std::cout << "Установите второй однопалубный корабль:\nВведите букву A - J - ";
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
        player.Single_D_2 = new Ship(1);
        Check_sides(x, y, player.Single_D_2->adress(0), player.Single_D_2->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
        if (!up) {
            while (!up) {
                std::cout << "Невозможно установить корабль!\nВведите букву A - J - ";
                std::cin >> z;
                y = Transformation(z);
                std::cout << "Введите цифру 0 - 9 - ";
                std::cin >> x;
                Check_sides(x, y, player.Single_D_2->adress(0), player.Single_D_2->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
            }
        }
        player.Single_D_2->set_start(x, y);
        Player_box[x][y] = player.Single_D_2->adress(0);
        player.Single_D_2->set_end(x, y);
        box_out(Player_box);
        std::cout << "Установите третий однопалубный корабль:\nВведите букву A - J - ";
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
        player.Single_D_3 = new Ship(1);
        Check_sides(x, y, player.Single_D_3->adress(0), player.Single_D_3->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
        if (!up) {
            while (!up) {
                std::cout << "Невозможно установить корабль!\nВведите букву A - J - ";
                std::cin >> z;
                y = Transformation(z);
                std::cout << "Введите цифру 0 - 9 - ";
                std::cin >> x;
                Check_sides(x, y, player.Single_D_3->adress(0), player.Single_D_3->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
            }
        }
        player.Single_D_3->set_start(x, y);
        Player_box[x][y] = player.Single_D_3->adress(0);
        player.Single_D_3->set_end(x, y);
        box_out(Player_box);
        std::cout << "Установите четвертый однопалубный корабль:\nВведите букву A - J - ";
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
        player.Single_D_4 = new Ship(1);
        Check_sides(x, y, player.Single_D_4->adress(0), player.Single_D_4->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
        if (!up) {
            while (!up) {
                std::cout << "Невозможно установить корабль!\nВведите букву A - J - ";
                std::cin >> z;
                y = Transformation(z);
                std::cout << "Введите цифру 0 - 9 - ";
                std::cin >> x;
                Check_sides(x, y, player.Single_D_4->adress(0), player.Single_D_4->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
            }
        }
        player.Single_D_4->set_start(x, y);
        Player_box[x][y] = player.Single_D_4->adress(0);
        player.Single_D_4->set_end(x, y);
        box_out(Player_box);
    }


    // Автоматическая расстановка любых кораблей
    void Auto_placement(bool*** box, Ship_complect* object) { 
        srand(time(0));
        short x = rand() % 10;
        short y = rand() % 10;
        short Ch = 0;
        bool up = false;
        bool down = false;
        bool right = false;
        bool left = false;
        bool* up_ref = &up;
        bool* down_ref = &down;
        bool* right_ref = &right;
        bool* left_ref = &left;
        object->Four_D = new Ship(4);
        Check_sides(x, y, object->Four_D->adress(0), object->Four_D->get_size(), up_ref, down_ref, left_ref, right_ref, box);
        if (!up && !down && !right && !down) {
            while (!up && !down && !right && !down) {
                y += 1;
                if (y > 9) {
                    y = 0;
                    x += 1;
                    if (x > 9) {
                        x = 0;
                    }
                }
                Check_sides(x, y, object->Four_D->adress(0), object->Four_D->get_size(), up_ref, down_ref, left_ref, right_ref, box);
            }
        }  
        box[x][y] = object->Four_D->adress(0);
        object->Four_D->set_start(x, y);
        Ch = rand() % 4 + 1;
        if ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
            while ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4)) {
                Ch += 1;
                if (Ch > 4) {
                    Ch = 1;
                }
            }
        }
        Placement_P(x, y, object->Four_D->get_size(), object->Four_D, Ch, box);

        x = rand() % 10;
        y = rand() % 10;
        object->Three_D_1 = new Ship(3);
        Check_sides(x, y, object->Three_D_1->adress(0), object->Three_D_1->get_size(), up_ref, down_ref, left_ref, right_ref, box);
        if (!up && !down && !right && !down) {
            while (!up && !down && !right && !down) {
                y += 1;
                if (y > 9) {
                    y = 0;
                    x += 1;
                    if (x > 9) {
                        x = 0;
                    }
                }
                Check_sides(x, y, object->Three_D_1->adress(0), object->Three_D_1->get_size(), up_ref, down_ref, left_ref, right_ref, box);
            }
        }
        box[x][y] = object->Three_D_1->adress(0);
        object->Three_D_1->set_start(x, y);
        Ch = rand() % 4 + 1;
        if ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
            while ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
                Ch += 1;
                if (Ch > 4) {
                    Ch = 1;
                }
            }
        }
        Placement_P(x, y, object->Three_D_1->get_size(), object->Three_D_1, Ch, box);

        x = rand() % 10;
        y = rand() % 10;
        object->Three_D_2 = new Ship(3);
        Check_sides(x, y, object->Three_D_2->adress(0), object->Three_D_2->get_size(), up_ref, down_ref, left_ref, right_ref, box);
        if (!up && !down && !right && !down) {
            while (!up && !down && !right && !down) {
                y += 1;
                if (y > 9) {
                    y = 0;
                    x += 1;
                    if (x > 9) {
                        x = 0;
                    }
                }
                Check_sides(x, y, object->Three_D_2->adress(0), object->Three_D_2->get_size(), up_ref, down_ref, left_ref, right_ref, box);
            }
        }
        box[x][y] = object->Three_D_2->adress(0);
        object->Three_D_2->set_start(x, y);
        Ch = rand() % 4 + 1;
        if ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
            while ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
                Ch += 1;
                if (Ch > 4) {
                    Ch = 1;
                }
            }
        }
        Placement_P(x, y, object->Three_D_2->get_size(), object->Three_D_2, Ch, box);

        x = rand() % 10;
        y = rand() % 10;
        object->Two_D_1 = new Ship(2);
        Check_sides(x, y, object->Two_D_1->adress(0), object->Two_D_1->get_size(), up_ref, down_ref, left_ref, right_ref, box);
        if (!up && !down && !right && !down) {
            while (!up && !down && !right && !down) {
                y += 1;
                if (y > 9) {
                    y = 0;
                    x += 1;
                    if (x > 9) {
                        x = 0;
                    }
                }
                Check_sides(x, y, object->Two_D_1->adress(0), object->Two_D_1->get_size(), up_ref, down_ref, left_ref, right_ref, box);
            }
        }
        box[x][y] = object->Two_D_1->adress(0);
        object->Two_D_1->set_start(x, y);
        Ch = rand() % 4 + 1;
        if ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
            while ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
                Ch += 1;
                if (Ch > 4) {
                    Ch = 1;
                }
            }
        }
        Placement_P(x, y, object->Two_D_1->get_size(), object->Two_D_1, Ch, box);

        x = rand() % 10;
        y = rand() % 10;
        object->Two_D_2 = new Ship(2);
        Check_sides(x, y, object->Two_D_2->adress(0), object->Two_D_2->get_size(), up_ref, down_ref, left_ref, right_ref, box);
        if (!up && !down && !right && !down) {
            while (!up && !down && !right && !down) {
                y += 1;
                if (y > 9) {
                    y = 0;
                    x += 1;
                    if (x > 9) {
                        x = 0;
                    }
                }
                Check_sides(x, y, object->Two_D_2->adress(0), object->Two_D_2->get_size(), up_ref, down_ref, left_ref, right_ref, box);
            }
        }
        box[x][y] = object->Two_D_2->adress(0);
        object->Two_D_2->set_start(x, y);
        Ch = rand() % 4 + 1;
        if ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
            while ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
                Ch += 1;
                if (Ch > 4) {
                    Ch = 1;
                }
            }
        }
        Placement_P(x, y, object->Two_D_2->get_size(), object->Two_D_2, Ch, box);

        x = rand() % 10;
        y = rand() % 10;
        object->Two_D_3 = new Ship(2);
        Check_sides(x, y, object->Two_D_3->adress(0), object->Two_D_3->get_size(), up_ref, down_ref, left_ref, right_ref, box);
        if (!up && !down && !right && !down) {
            while (!up && !down && !right && !down) {
                y += 1;
                if (y > 9) {
                    y = 0;
                    x += 1;
                    if (x > 9) {
                        x = 0;
                    }
                }
                Check_sides(x, y, object->Two_D_3->adress(0), object->Two_D_3->get_size(), up_ref, down_ref, left_ref, right_ref, box);
            }
        }
        box[x][y] = object->Two_D_3->adress(0);
        object->Two_D_3->set_start(x, y);
        Ch = rand() % 4 + 1;
        if ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
            while ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
                Ch += 1;
                if (Ch > 4) {
                    Ch = 1;
                }
            }
        }
        Placement_P(x, y, object->Two_D_3->get_size(), object->Two_D_3, Ch, box);

        x = rand() % 10;
        y = rand() % 10;
        object->Single_D_1 = new Ship(1);
        Check_sides(x, y, object->Single_D_1->adress(0), object->Single_D_1->get_size(), up_ref, down_ref, left_ref, right_ref, box);
        if (!up) {
            while (!up) {
                y += 1;
                if (y > 9) {
                    y = 0;
                    x += 1;
                    if (x > 9) {
                        x = 0;
                    }
                }
                Check_sides(x, y, object->Single_D_1->adress(0), object->Single_D_1->get_size(), up_ref, down_ref, left_ref, right_ref, box);
            }
        }
        box[x][y] = object->Single_D_1->adress(0);
        object->Single_D_1->set_start(x, y);
        object->Single_D_1->set_end(x, y);

        x = rand() % 10;
        y = rand() % 10;
        object->Single_D_2 = new Ship(1);
        Check_sides(x, y, object->Single_D_2->adress(0), object->Single_D_2->get_size(), up_ref, down_ref, left_ref, right_ref, box);
        if (!up) {
            while (!up) {
                y += 1;
                if (y > 9) {
                    y = 0;
                    x += 1;
                    if (x > 9) {
                        x = 0;
                    }
                }
                Check_sides(x, y, object->Single_D_2->adress(0), object->Single_D_2->get_size(), up_ref, down_ref, left_ref, right_ref, box);
            }
        }
        box[x][y] = object->Single_D_2->adress(0);
        object->Single_D_2->set_start(x, y);
        object->Single_D_2->set_end(x, y);

        x = rand() % 10;
        y = rand() % 10;
        object->Single_D_3 = new Ship(1);
        Check_sides(x, y, object->Single_D_3->adress(0), object->Single_D_3->get_size(), up_ref, down_ref, left_ref, right_ref, box);
        if (!up) {
            while (!up) {
                y += 1;
                if (y > 9) {
                    y = 0;
                    x += 1;
                    if (x > 9) {
                        x = 0;
                    }
                }
                Check_sides(x, y, object->Single_D_3->adress(0), object->Single_D_3->get_size(), up_ref, down_ref, left_ref, right_ref, box);
            }
        }
        box[x][y] = object->Single_D_3->adress(0);
        object->Single_D_3->set_start(x, y);
        object->Single_D_3->set_end(x, y);

        x = rand() % 10;
        y = rand() % 10;
        object->Single_D_4 = new Ship(1);
        Check_sides(x, y, object->Single_D_4->adress(0), object->Single_D_4->get_size(), up_ref, down_ref, left_ref, right_ref, box);
        if (!up) {
            while (!up) {
                y += 1;
                if (y > 9) {
                    y = 0;
                    x += 1;
                    if (x > 9) {
                        x = 0;
                    }
                }
                Check_sides(x, y, object->Single_D_4->adress(0), object->Single_D_4->get_size(), up_ref, down_ref, left_ref, right_ref, box);
            }
        }
        box[x][y] = object->Single_D_4->adress(0);
        object->Single_D_4->set_start(x, y);
        object->Single_D_4->set_end(x, y);
    }

    // для обведения уничтоженного корабля
    void after_kill(bool*** box, Ship_complect* object, short x, short y)
    {
        if (x == 0 && y == 0) {
            for (short i = x; i < x + 2; i++) {
                for (short j = y; j < y + 2; j++) {
                    if (box[i][j] == nullptr) {
                        box[i][j] = &hit;
                    }
                }
            }
            return;
        }
        if (x == 0 && y == 9) {
            for (short i = x; i < x + 2; i++) {
                for (short j = y - 1; j < y + 1; j++) {
                    if (box[i][j] == nullptr) {
                        box[i][j] = &hit;
                    }
                }
            }
            return;
        }
        if (x == 9 && y == 0) {
            for (short i = x - 1; i < x + 1; i++) {
                for (short j = y; j < y + 2; j++) {
                    if (box[i][j] == nullptr) {
                        box[i][j] = &hit;
                    }
                }
            }
            return;
        }
        if (x == 9 && y == 9) {
            for (short i = x - 1; i < x + 1; i++) {
                for (short j = y - 1; j < y + 1; j++) {
                    if (box[i][j] == nullptr) {
                        box[i][j] = &hit;
                    }
                }
            }
            return;
        }
        if (x == 0) {
            for (short i = x; i < x + 2; i++) {
                for (short j = y - 1; j < y + 2; j++) {
                    if (box[i][j] == nullptr) {
                        box[i][j] = &hit;
                    }
                }
            }
            return;
        }
        if (x == 9) {
            for (short i = x - 1; i < x + 1; i++) {
                for (short j = y - 1; j < y + 2; j++) {
                    if (box[i][j] == nullptr) {
                        box[i][j] = &hit;
                    }
                }
            }
            return;
        }
        if (y == 0) {
            for (short i = x - 1; i < x + 2; i++) {
                for (short j = y; j < y + 2; j++) {
                    if (box[i][j] == nullptr) {
                        box[i][j] = &hit;
                    }
                }
            }
            return;
        }
        if (y == 9) {
            for (short i = x - 1; i < x + 2; i++) {
                for (short j = y - 1; j < y + 1; j++) {
                    if (box[i][j] == nullptr) {
                        box[i][j] = &hit;
                    }
                }
            }
            return;
        }
        else {
            for (short i = x - 1; i < x + 2; i++) {
                for (short j = y - 1; j < y + 2; j++) {
                    if (box[i][j] == nullptr) {
                        box[i][j] = &hit;
                    }
                }
            }
            return;
        }
    }
    
    // для обведения подбитой клетки
    void after_shoot(bool*** box, Ship_complect* object, short x, short y) {
        if (!object->Hitting->get_condition()) {
            after_kill(box, object, object->Hitting->get_start_x(), object->Hitting->get_start_y());
            if (object->Hitting->get_size() > 1) {
                after_kill(box, object, object->Hitting->get_end_x(), object->Hitting->get_end_y());
            }
            return;
        }
        if (x == 0 && y == 0) {
            box[x + 1][y + 1] = &hit;
            return;
        }
        if (x == 0 && y == 9) {
            box[x - 1][y + 1] = &hit;
            return;

        }
        if (x == 9 && y == 0) {
            box[x + 1][y - 1] = &hit;
            return;
        }
        if (x == 9 && y == 9) {
            box[x - 1][y - 1] = &hit;
            return;
        }
        if (x == 0) {
            box[x + 1][y + 1] = &hit;
            box[x + 1][y - 1] = &hit;
            return;
        }
        if (x == 9) {
            box[x - 1][y + 1] = &hit;
            box[x - 1][y - 1] = &hit;
            return;
        }
        if (y == 0) {
            box[x + 1][y + 1] = &hit;
            box[x - 1][y + 1] = &hit;
            return;
        }
        if (x == 9) {
            box[x + 1][y - 1] = &hit;
            box[x - 1][y - 1] = &hit;
            return;
        }
        else {
            box[x + 1][y + 1] = &hit;
            box[x + 1][y - 1] = &hit;
            box[x - 1][y + 1] = &hit;
            box[x - 1][y - 1] = &hit;
            return;
        }
    }

    bool computer_shoot(bool*** box, Ship_complect* object) {
        static short seria = 0;
        short x;
        short y;
        if (!comp_shoot) {
            srand(time(0));
            x = rand() % 10;
            y = ((rand() % 10) * 1234567) % 10;
            short kick = object->shoot(box[x][y]);
            static short seria = 0;
            if (kick == 1) {
                comp_seria[seria].x = x;
                comp_seria[seria].y = y;
                comp_shoot = true;
                seria += 1;
            }
            return true;
        }
        else{
            if (seria == 1)
                bool up;
        }
        
        

    }

    // Выстрел
    short shoot(bool*** box, Ship_complect* object, short x, char z) {
        short y = Transformation(z);
        short check = object->shoot(box[x][y]);
        if ((check == 1 || check == 2) && box[x][y] != &hit) {
            after_shoot(box, object, x, y);
            return 0;
        }
        if (*box[x][y] && box[x][y] != &hit) {
            std::cout << "Уже уничтожен\n";
            return 1;
        }
        if (box[x][y] == &hit) {
            std::cout << "Рядом с кораблем\n";
            return 2;
        }
        else {
            box[x][y] = &hit;
            std::cout << "Мимо...\n";
            return 3;
        }
    }

    ~Sea_Battle() {
        delete[] player.Four_D;
        delete[] player.Three_D_1;
        delete[] player.Three_D_2;
        delete[] player.Two_D_1;
        delete[] player.Two_D_2;
        delete[] player.Two_D_3;
        delete[] player.Single_D_1;
        delete[] player.Single_D_2;
        delete[] player.Single_D_3;
        delete[] player.Single_D_4;
        delete[] computer.Four_D;
        delete[] computer.Three_D_1;
        delete[] computer.Three_D_2;
        delete[] computer.Two_D_1;
        delete[] computer.Two_D_2;
        delete[] computer.Two_D_3;
        delete[] computer.Single_D_1;
        delete[] computer.Single_D_2;
        delete[] computer.Single_D_3;
        delete[] computer.Single_D_4;
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
    Sea_Battle Play;
    std::cout << "Size" << sizeof(Play) << std::endl;
    Play.Auto_placement(Play.Get_pl_box(), Play.Get_complect_pl());
    std::cout << "Size" << sizeof(Play) << std::endl;
    Play.box_out(Play.Get_pl_box());
    setlocale(LC_ALL, "Russian");
    for (short i = 0; i < 5; i++) {
        char z;
        short x;
        std::cout << "Введите букву A - J - ";
        std::cin >> z;
        std::cout << "Введите цифру 0 - 9 - ";
        std::cin >> x;
        Play.shoot(Play.Get_pl_box(), Play.Get_complect_pl(), x, z);
        Play.box_out(Play.Get_pl_box());
    }
    

}
