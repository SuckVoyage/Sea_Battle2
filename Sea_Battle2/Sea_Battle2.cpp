// Sea_Battle2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <ctime>
#include <Windows.h>
short box_size = 10;
short Line = 33;
void print_line() {
    for (int i = 0; i < Line; i++) {
        std::cout << "-";
    }
    std::cout << "\t";
    for (int i = 0; i < Line; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

void sleep_out() {
    std::cout << ".";
    Sleep(500);
    std::cout << ".";
    Sleep(500);
    std::cout << ".";
    Sleep(500);
}


void print_line(short x) {
    if (x == 1) {
        for (int i = 0; i < Line * 2; i++) {
            std::cout << "-";
        }
        std::cout << std::endl;
    }
    else {
        for (int i = 0; i < Line; i++) {
            std::cout << "-";
        }
        std::cout << std::endl;
    }
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
char Transformation(short z) {
    if (z == 0) return 'A';
    if (z == 1) return 'B';
    if (z == 2) return 'C';
    if (z == 3) return 'D';
    if (z == 4) return 'E';
    if (z == 5) return 'F';
    if (z == 6) return 'G';
    if (z == 7) return 'H';
    if (z == 8) return 'I';
    if (z == 9) return 'J';
    else return -1;
}

void prefire(short y, short x) {
    char z = Transformation(y);
    std::cout << "\nВыстрел компьютера - \n";
    sleep_out();
    std::cout << "\n" << z << std::endl;
    sleep_out();
    std::cout << "\n" << x << std::endl;
    sleep_out();
    std::cout << std::endl;
}

struct Coord{
    short x;
    short y;
};

struct Sides {
    bool up;
    bool down;
    bool right;
    bool left;
    Sides() {
        up = false;
        down = false;
        right = false;
        left = false;
    }
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
    // Shoot возвращает:
    // 1 - если ранил
    // 2 - если убил
    // 3 - если уже было попадание
    // 0 - если координаты не относятся к этому кораблю
    short shoot(bool* coord) {
        for (short i = 0; i < size; i++) {
            if (coord == ship + i && ship[i]) {
                return 3;
            }
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
        std::cout << "Ship " << this->size << " deleted" << std::endl;
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
    bool complect_condition;
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
        complect_condition = false;
    }
    // Поиск конкретного корабля
    // 1 - если ранил
    // 2 - если убил
    // 3 - если повторное попадание
    // 0 - если мимо
    short shoot(bool* coord) {
        short kick = Single_D_1->shoot(coord);
        if (kick == 1 || kick == 2) {
            Hitting = Single_D_1;
            return kick;
        }
        if (kick == 3) {
            return kick;
        }
        else {
            kick = Single_D_2->shoot(coord);
            if (kick == 1 || kick == 2) {
                Hitting = Single_D_2;
                return kick;
            }
            if (kick == 3) {
                return kick;
            }
            else {
                kick = Single_D_3->shoot(coord);
                if (kick == 1 || kick == 2) {
                    Hitting = Single_D_3;
                    return kick;
                }
                if (kick == 3) {
                    return kick;
                }
                else {
                    kick = Single_D_4->shoot(coord);
                    if (kick == 1 || kick == 2) {
                        Hitting = Single_D_4;
                        return kick;
                    }
                    if (kick == 3) {
                        return kick;
                    }
                    else {
                        kick = Two_D_1->shoot(coord);
                        if (kick == 1 || kick == 2) {
                            Hitting = Two_D_1;
                            return kick;
                        }
                        if (kick == 3) {
                            return kick;
                        }
                        else {
                            kick = Two_D_2->shoot(coord);
                            if (kick == 1 || kick == 2) {
                                Hitting = Two_D_2;
                                return kick;
                            }
                            if (kick == 3) {
                                return kick;
                            }
                            else {
                                kick = Two_D_3->shoot(coord);
                                if (kick == 1 || kick == 2) {
                                    Hitting = Two_D_3;
                                    return kick;
                                }
                                if (kick == 3) {
                                    return kick;
                                }
                                else {
                                    kick = Three_D_1->shoot(coord);
                                    if (kick == 1 || kick == 2) {
                                        Hitting = Three_D_1;
                                        return kick;
                                    }
                                    if (kick == 3) {
                                        return kick;
                                    }
                                    else {
                                        kick = Three_D_2->shoot(coord);
                                        if (kick == 1 || kick == 2) {
                                            Hitting = Three_D_2;
                                            return kick;
                                        }
                                        if (kick == 3) {
                                            return kick;
                                        }
                                        else {
                                            kick = Three_D_2->shoot(coord);
                                            if (kick == 1 || kick == 2) {
                                                Hitting = Four_D;
                                                return kick;
                                            }
                                            if (kick == 3) {
                                                return kick;
                                            }
                                            else {
                                                kick = Four_D->shoot(coord);
                                                if (kick == 1 || kick == 2) {
                                                    Hitting = Four_D;
                                                    return kick;
                                                }
                                                if (kick == 3) {
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

    }
};

struct Ship_node {
    Ship* ship;
    Ship_node* next;
    
    Ship_node(short size) {
        ship = new Ship(size);
        next = nullptr;
    }
    ~Ship_node() {
        delete ship;
    }
};

struct Ship_list {
    Ship_node* first;
    Ship_node* last;
    Ship* Hitting;
    bool complect_condition;

    Ship_list() {
        first = nullptr;
        last = nullptr;
        Hitting = nullptr;
        complect_condition = false;
    }

    void Add_node(short size) {
        if (first == nullptr) {
            first = new Ship_node(size);
            last = first;
        }
        else {
            Ship_node *temp = new Ship_node(size);
            last->next = temp;
            last = temp;
        }
    }
    
    // Поиск конкретного корабля
    // 1 - если ранил
    // 2 - если убил
    // 3 - если повторное попадание
    // 0 - если мимо
    short shoot(bool* coord) {
        Ship_node* temp = first;
        while (temp->next != nullptr) {
            short kick = temp->ship->shoot(coord);
            if (kick == 1 || kick == 2) {
                Hitting = temp->ship;
                return kick;
            }
            if (kick == 3) {
                return kick;
            }
            else {
                temp = temp->next;
            }
        }
        short kick = temp->ship->shoot(coord);
        if (kick == 1 || kick == 2) {
            Hitting = temp->ship;
            return kick;
        }
        if (kick == 3) {
            sleep_out();
            std::cout << "\nУже было попадание\n";
            sleep_out();
            return kick;
        }
        else {
            sleep_out();
            std::cout << "\nМимо\n";
            sleep_out();
            return kick;
        }
    }

    ~Ship_list() {
        Ship_node* temp = first->next; 
        while (first != nullptr) {
            delete first;
            first = temp;
            if (first != nullptr) {
                temp = first->next;
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
    Ship_list gamer;
    Ship_list comp;
    // для хранения координат пораженного корабля
    Coord comp_seria[4];

    // для хранения состояния подбитого корабля
    // false - либо мимо либо корабль уничтожен
    // true - корабль ранен но не уничтожен
    bool comp_shoot;

    // отметка уже стреляли
    bool hit;

    Sides shoot_sides_first;
    Sides shoot_sides_last;
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
    Ship_list* Get_list_gamer () {
        return &gamer;
    }
    Ship_list* Get_list_comp() {
        return &comp;
    }

    void box_out() {
        std::cout << "\tВАШЕ ПОЛЕ\t\t\t\tПОЛЕ КОМПЬЮТЕРА\n\n|||A |B |C |D |E |F |G |H |I |J | \t|||A |B |C |D |E |F |G |H |I |J |\n";
        print_line();
        for (short i = 0; i < box_size; i++) {
            std::cout << i << " ";
            for (short j = 0; j < box_size; j++) {
                if (Player_box[i][j] == nullptr) {
                    std::cout << "|  ";
                }
                else {
                    if (!*Player_box[i][j]) {
                        std::cout << "|##";
                    }
                    else {
                        if (Player_box[i][j] != &hit) {
                            std::cout << "|**";
                        }
                        else std::cout << "|~~";
                    }
                }
            }
            std::cout << "|\t";
            std::cout << i << " ";
            for (short j = 0; j < box_size; j++) {
                if (Comp_box[i][j] == nullptr) {
                    std::cout << "|  ";
                }
                else {
                    if (!*Comp_box[i][j]) {
                        std::cout << "|  ";
                    }
                    else {
                        if (Comp_box[i][j] != &hit) {
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


    void box_out(bool *** box) {
        std::cout << "|||A |B |C |D |E |F |G |H |I |J |\n";
        print_line(2);
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
            print_line(2);
        }
    }

    // проверка направлений для выстрела компьютера
    void check_attack(bool*** box, short x, short y , Sides *side) {
        if (x == 0 && y == 0) {
            side->up = false;
            side->left = false;
            if (box[x + 1][y] != nullptr && *box[x + 1][y]) {
                side->down = false;
            }
            else {
                side->down = true;
            }
            if (box[x][y + 1] != nullptr && *box[x][y + 1]) {
                side->right = false;
            }
            else {
                side->right = true;
            }
            return;
        }
        if (x == 0 && y == 9) {
            side->up = false;
            side->right = false;
            if (box[x + 1][y] != nullptr && *box[x + 1][y]) {
                side->down = false;
            }
            else {
                side->down = true;
            }
            if (box[x][y - 1] != nullptr && *box[x][y - 1]) {
                side->left = false;
            }
            else {
                side->left = true;
            }
            return;
        }
        if (x == 9 && y == 0) {
            side->down = false;
            side->left = false;
            if (box[x - 1][y] != nullptr && *box[x - 1][y]) {
               side->up = false;
            }
            else {
                side->up = true;
            }
            if (box[x][y + 1] != nullptr && *box[x][y + 1]) {
                side->right = false;
            }
            else {
                side->right = true;
            }
            return;
        }
        if (x == 9 && y == 9) {
            side->down = false;
            side->right = false;
            if (box[x - 1][y] != nullptr && *box[x - 1][y]) {
                side->up = false;
            }
            else {
                side->up = true;
            }
            if (box[x][y - 1] != nullptr && *box[x][y - 1]) {
                side->left = false;
            }
            else {
                side->left = true;
            }
            return;
        }
        if (x == 0) {
            side->up = false;
            if (box[x + 1][y] != nullptr && *box[x + 1][y]) {
                side->down = false;
            }
            else {
                side->down = true;
            }
            if (box[x][y - 1] != nullptr && *box[x][y - 1]) {
                side->left = false;
            }
            else {
                side->left = true;
            }
            if (box[x][y + 1] != nullptr && *box[x][y + 1]) {
                side->right = false;
            }
            else {
                side->right = true;
            }
            return;
        }
        if (x == 9) {
            side->down = false;
            if (box[x - 1][y] != nullptr && *box[x - 1][y]) {
                side->up = false;
            }
            else {
                side->up = true;
            }
            if (box[x][y - 1] != nullptr && *box[x][y - 1]) {
                side->left = false;
            }
            else {
                side->left = true;
            }
            if (box[x][y + 1] != nullptr && *box[x][y + 1]) {
                side->right = false;
            }
            else {
                side->right = true;
            }
            return;
        }
        if (y == 0) {
            side->left = false;
            if (box[x + 1][y] != nullptr && *box[x + 1][y]) {
                side->down = false;
            }
            else {
                side->down = true;
            }
            if (box[x - 1][y] != nullptr && *box[x - 1][y]) {
                side->up = false;
            }
            else {
                side->up = true;
            }
            if (box[x][y + 1] != nullptr && *box[x][y + 1]) {
                side->right = false;
            }
            else {
                side->right = true;
            }
            return;
        }
        if (y == 9) {
            side->right = false;
            if (box[x + 1][y] != nullptr && *box[x + 1][y]) {
                side->down = false;
            }
            else {
                side->down = true;
            }
            if (box[x - 1][y] != nullptr && *box[x - 1][y]) {
                side->up = false;
            }
            else {
                side->up = true;
            }
            if (box[x][y - 1] != nullptr && *box[x][y - 1]) {
                side->left = false;
            }
            else {
                side->left = true;
            }
            return;
        }
        else {
            if (box[x + 1][y] != nullptr && *box[x + 1][y]) {
                side->down = false;
            }
            else {
                side->down = true;
            }
            if (box[x - 1][y] != nullptr && *box[x - 1][y]) {
                side->up = false;
            }
            else {
                side->up = true;
            }
            if (box[x][y - 1] != nullptr && *box[x][y - 1]) {
                side->left = false;
            }
            else {
                side->left = true;
            }
            if (box[x][y + 1] != nullptr && *box[x][y + 1]) {
                side->right = false;
            }
            else {
                side->right = true;
            }
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
    
    // Ручная расстановка кораблей игрока список
    void Placement(short a) {
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
        for (short i = 0, c = 4; i < 10; i++) {
            if (i == 1 || i == 3 || i == 6) {
                c -= 1;
            }
            std::cout << "Установите " << c << " палубный корабль:\nВведите букву A - J - ";
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
            gamer.Add_node(c);
            Check_sides(x, y, gamer.last->ship->adress(0), gamer.last->ship->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
            if (!up && !down && !right && !left) {
                while (!up && !down && !right && !left) {
                    std::cout << "Невозможно установить корабль!\nВведите букву A - J - ";
                    std::cin >> z;
                    y = Transformation(z);
                    std::cout << "Введите цифру 0 - 9 - ";
                    std::cin >> x;
                    Check_sides(x, y, gamer.last->ship->adress(0), gamer.last->ship->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
                }
            }
            gamer.last->ship->set_start(x, y);
            Player_box[x][y] = gamer.last->ship->adress(0);
            if (gamer.last->ship->get_size() > 1) {
                Check_sides(x, y, gamer.last->ship->adress(0), gamer.last->ship->get_size(), up_ref, down_ref, left_ref, right_ref, Player_box);
                Menu_placement(up, down, right, left);
                std::cin >> Ch;
                if ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
                    while ((!up && Ch == 1) || (!down && Ch == 2) || (!left && Ch == 3) || (!right && Ch == 4) || Ch < 1 || Ch > 4) {
                        std::cout << "Неверное направление\n- ";
                        std::cin >> Ch;
                    }
                }
                Placement_P(x, y, gamer.last->ship->get_size(), gamer.last->ship, Ch, Player_box);
            }
            else {
                gamer.last->ship->set_end(x, y);
            }
            box_out(Player_box);
        }
        gamer.complect_condition = true;
    }

    // Автоматическая расстановка любых кораблей список
    void Auto_placement(bool*** box, Ship_list* object) {
        srand(time(0));
        short x = rand() % 10;
        short y = rand() % 10;
        short Ch = 0;
        Sides sides;
        for (short i = 0, c = 4; i < 10; i++) {
            if (i == 1 || i == 3 || i == 6) {
                c -= 1;
            }
            object->Add_node(c);
            Check_sides(x, y, object->last->ship->adress(0), object->last->ship->get_size(), &sides.up, &sides.down, &sides.left, &sides.right, box);
            if (c > 1) {
                if (!sides.up && !sides.down && !sides.right && !sides.left) {
                    while (!sides.up && !sides.down && !sides.right && !sides.left) {
                        y += 1;
                        if (y > 9) {
                            y = 0;
                            x += 1;
                            if (x > 9) {
                                x = 0;
                            }
                        }
                        Check_sides(x, y, object->last->ship->adress(0), object->last->ship->get_size(), &sides.up, &sides.down, &sides.left, &sides.right, box);
                    }
                }
            }
            else {
                if (!sides.up) {
                    while (!sides.up) {
                        y += 1;
                        if (y > 9) {
                            y = 0;
                            x += 1;
                            if (x > 9) {
                                x = 0;
                            }
                        }
                        Check_sides(x, y, object->last->ship->adress(0), object->last->ship->get_size(), &sides.up, &sides.down, &sides.left, &sides.right, box);
                    }
                }
            }
            box[x][y] = object->last->ship->adress(0);
            object->last->ship->set_start(x, y);
            if (c > 1) {
                Ch = rand() % 4 + 1;
                if ((!sides.up && Ch == 1) || (!sides.down && Ch == 2) || (!sides.left && Ch == 3) || (!sides.right && Ch == 4) || Ch < 1 || Ch > 4) {
                    while ((!sides.up && Ch == 1) || (!sides.down && Ch == 2) || (!sides.left && Ch == 3) || (!sides.right && Ch == 4) || Ch < 1 || Ch > 4) {
                        Ch += 1;
                        if (Ch > 4) {
                            Ch = 1;
                        }
                    }
                }
                Placement_P(x, y, object->last->ship->get_size(), object->last->ship, Ch, box);
            }
            else {
                object->last->ship->set_end(x, y);
            }
        }
        object->complect_condition = true;
    }

    // Ручная расстановка кораблей игрока
    void  Placement() {
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
        player.complect_condition = true;
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
        object->complect_condition = true;
    }

    // для обведения уничтоженного корабля
    void after_kill(bool*** box,/* Ship_complect* object*/ short x, short y)
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
    void after_shoot(bool*** box, Ship_list* object, short x, short y) {
        if (!object->Hitting->get_condition()) {
            after_kill(box, /*object,*/ object->Hitting->get_start_x(), object->Hitting->get_start_y());
            if (object->Hitting->get_size() > 1) {
                after_kill(box,/* object,*/ object->Hitting->get_end_x(), object->Hitting->get_end_y());
            }
            return;
        }
        if (x == 0 && y == 0) {
            box[x + 1][y + 1] = &hit;
            return;
        }
        if (x == 0 && y == 9) {
            box[x + 1][y - 1] = &hit;
            return;

        }
        if (x == 9 && y == 0) {
            box[x - 1][y + 1] = &hit;
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

    // запрет ненужных сторон
    void lock_sides() {
        if (comp_seria[0].x == comp_seria[1].x) {
            shoot_sides_first.up = false;
            shoot_sides_first.down = false;
            shoot_sides_last.up = false;
            shoot_sides_last.down = false;
        }
        else {
            shoot_sides_first.right = false;
            shoot_sides_first.right = false;
            shoot_sides_last.left = false;
            shoot_sides_last.left = false;
        }
    }

    // Выстрел компьютера
    // возвращает
    // 0 - мимо
    // 1 - ранил
    // 2 - убил
    short computer_shoot(bool*** box, Ship_list* object) {
        static short seria = 0;
        short x = 0;
        short y = 0;
        if (!comp_shoot) {
            srand(time(0));
            x = rand() % 10;
            y = ((rand() % 10) * 1234567) % 10;
            // проверка на возможность стрелять в эту клетку
            if (box[x][y] != nullptr && *box[x][y]) {
                while (box[x][y] != nullptr && *box[x][y]) {
                    x += 1;
                    if (x > 9) {
                        y += 1;
                        x = 0;
                        if (y > 9) {
                            y = 0;
                        }
                    }
                }
            }
            prefire(y, x);
            short kick = object->shoot(box[x][y]);
            if (kick == 1) {
                comp_seria[seria].x = x;
                comp_seria[seria].y = y;
                comp_shoot = true;
                seria += 1;
                after_shoot(box, object, x, y);
                return 1;
            }
            if (kick == 2) {
                for (short i = 0; i < 4; i++) {
                    comp_seria[i].x = 0;
                    comp_seria[i].y = 0;
                }
                comp_shoot = false;
                seria = false;
                after_shoot(box, object, x, y);
                return 2;
            }
            else {
                box[x][y] = &hit;
                return 0;
            }

        }
        else {
            if (seria == 1) {
                check_attack(box, comp_seria[seria - 1].x, comp_seria[seria - 1].y, &shoot_sides_first);
                short choice = rand() % 4 + 1;
                if ((choice == 1 && !shoot_sides_first.up) || (choice == 2 && !shoot_sides_first.down) || (choice == 3 && !shoot_sides_first.right) || (choice == 4 && !shoot_sides_first.left)) {
                    while ((choice == 1 && !shoot_sides_first.up) || (choice == 2 && !shoot_sides_first.down) || (choice == 3 && !shoot_sides_first.right) || (choice == 4 && !shoot_sides_first.left)) {
                        choice += 1;
                        if (choice > 4) {
                            choice = 1;
                        }
                    }
                }
                if (choice == 1 && shoot_sides_first.up) {
                    x = comp_seria[seria - 1].x - 1;
                    y = comp_seria[seria - 1].y;
                }
                if (choice == 2 && shoot_sides_first.down) {
                    x = comp_seria[seria - 1].x + 1;
                    y = comp_seria[seria - 1].y;
                }
                if (choice == 3 && shoot_sides_first.right) {
                    x = comp_seria[seria - 1].x;
                    y = comp_seria[seria - 1].y + 1;
                }
                if (choice == 4 && shoot_sides_first.left) {
                    x = comp_seria[seria - 1].x;
                    y = comp_seria[seria - 1].y - 1;
                }
                prefire(y, x);
                short kick = object->shoot(box[x][y]);
                if (kick == 1) {
                    comp_seria[seria].x = x;
                    comp_seria[seria].y = y;
                    comp_shoot = true;
                    seria += 1;
                    after_shoot(box, object, x, y);
                    std::cout << "\nРанен\n";
                    return 1;
                }
                if (kick == 2) {
                    for (short i = 0; i < 4; i++) {
                        comp_seria[i].x = 0;
                        comp_seria[i].y = 0;
                    }
                    comp_shoot = false;
                    seria = false;
                    after_shoot(box, object, x, y);
                    std::cout << "\nУбит\n";
                    return 2;
                }
                else {
                    box[x][y] = &hit;
                    std::cout << "\nМимо\n";
                    return 0;
                }

            }
            if (seria > 1) {
                bool check = false;
                check_attack(box, comp_seria[seria - 1].x, comp_seria[seria - 1].y, &shoot_sides_last);
                lock_sides();
                if (!shoot_sides_last.down && !shoot_sides_last.left && !shoot_sides_last.right && !shoot_sides_last.up) {
                    check_attack(box, comp_seria[0].x, comp_seria[0].y, &shoot_sides_first);
                    lock_sides();
                    check = true;
                }
                if (check) {
                    short choice = rand() % 4 + 1;
                    if ((choice == 1 && !shoot_sides_first.up) || (choice == 2 && !shoot_sides_first.down) || (choice == 3 && !shoot_sides_first.right) || (choice == 4 && !shoot_sides_first.left)) {
                        while ((choice == 1 && !shoot_sides_first.up) || (choice == 2 && !shoot_sides_first.down) || (choice == 3 && !shoot_sides_first.right) || (choice == 4 && !shoot_sides_first.left)) {
                            choice += 1;
                            if (choice > 4) {
                                choice = 1;
                            }
                        }
                    }
                    if (choice == 1 && shoot_sides_first.up) {
                        x = comp_seria[0].x - 1;
                        y = comp_seria[0].y;
                    }
                    if (choice == 2 && shoot_sides_first.down) {
                        x = comp_seria[0].x + 1;
                        y = comp_seria[0].y;
                    }
                    if (choice == 3 && shoot_sides_first.right) {
                        x = comp_seria[0].x;
                        y = comp_seria[0].y + 1;
                    }
                    if (choice == 4 && shoot_sides_first.left) {
                        x = comp_seria[0].x;
                        y = comp_seria[0].y - 1;
                    }
                    prefire(y, x);
                    short kick = object->shoot(box[x][y]);
                    if (kick == 1) {
                        comp_seria[seria].x = x;
                        comp_seria[seria].y = y;
                        comp_shoot = true;
                        seria += 1;
                        after_shoot(box, object, x, y);
                        std::cout << "\nРанен\n";
                        return 1;
                    }
                    if (kick == 2) {
                        for (short i = 0; i < 4; i++) {
                            comp_seria[i].x = 0;
                            comp_seria[i].y = 0;
                        }
                        comp_shoot = false;
                        seria = false;
                        after_shoot(box, object, x, y);
                        std::cout << "\nУбит\n";
                        return 2;
                    }
                    else {
                        box[x][y] = &hit;
                        std::cout << "\nМимо\n";
                        return 0;
                    }
                }
                else {
                    short choice = rand() % 4 + 1;
                    if ((choice == 1 && !shoot_sides_last.up) || (choice == 2 && !shoot_sides_last.down) || (choice == 3 && !shoot_sides_last.right) || (choice == 4 && !shoot_sides_last.left)) {
                        while ((choice == 1 && !shoot_sides_last.up) || (choice == 2 && !shoot_sides_last.down) || (choice == 3 && !shoot_sides_last.right) || (choice == 4 && !shoot_sides_last.left)) {
                            choice += 1;
                            if (choice > 4) {
                                choice = 1;
                            }
                        }
                    }
                    if (choice == 1 && shoot_sides_last.up) {
                        x = comp_seria[seria - 1].x - 1;
                        y = comp_seria[seria - 1].y;
                    }
                    if (choice == 2 && shoot_sides_last.down) {
                        x = comp_seria[seria - 1].x + 1;
                        y = comp_seria[seria - 1].y;
                    }
                    if (choice == 3 && shoot_sides_last.right) {
                        x = comp_seria[seria - 1].x;
                        y = comp_seria[seria - 1].y + 1;
                    }
                    if (choice == 4 && shoot_sides_last.left) {
                        x = comp_seria[seria - 1].x;
                        y = comp_seria[seria - 1].y - 1;
                    }
                    prefire(y, x);
                    short kick = object->shoot(box[x][y]);
                    if (kick == 1) {
                        comp_seria[seria].x = x;
                        comp_seria[seria].y = y;
                        comp_shoot = true;
                        seria += 1;
                        after_shoot(box, object, x, y);
                        std::cout << "\nРанен\n";
                        return 1;
                    }
                    if (kick == 2) {
                        for (short i = 0; i < 4; i++) {
                            comp_seria[i].x = 0;
                            comp_seria[i].y = 0;
                        }
                        comp_shoot = false;
                        seria = false;
                        after_shoot(box, object, x, y);
                        std::cout << "\nУбит\n";
                        return 2;
                    }
                    else {
                        box[x][y] = &hit;
                        std::cout << "\nМимо\n";
                        return 0;
                    }
                }
            }
        }
    }

    // Выстрел
    // 0 - ранил
    // 1 - повторно попал в корабль 
    // 2 - или уже стрелял или рядом с уничтоженным кораблем
    // 3 - мимо
    // 4 - уничтожен
    short shoot(bool*** box, Ship_list* object, short x, char z) {
        short y = Transformation(z);
        short check = object->shoot(box[x][y]);
        if ((check == 1) && box[x][y] != &hit) {
            after_shoot(box, object, x, y);
            return 0;
        }
        if (check == 2 && box[x][y] != &hit) {
            after_shoot(box, object, x, y);
            return 4;
        }
        if (check == 3) {
            return 1;
        }
        if (box[x][y] == &hit) {
             return 2;
        }
        else {
            box[x][y] = &hit;
            return 3;
        }

    }

    void canc_placement(bool*** box, Ship_list* object) {
        Ship_node* temp = object->first->next;
        while (temp != nullptr) {
            delete object->first;
            object->first = temp;
            temp = object->first->next;
        }
        delete object->first;
        object->first = nullptr;
        object->last = nullptr;
        for (short i = 0; i < box_size; i++) {
            for (short j = 0; j < box_size; j++) {
                box[i][j] = nullptr;
            }
        }
    }

    void canc_placement(bool*** box, Ship_complect* object) {
        delete object->Four_D;
        delete object->Three_D_1;
        delete object->Three_D_2;
        delete object->Two_D_1;
        delete object->Two_D_2;
        delete object->Two_D_3;
        delete object->Single_D_1;
        delete object->Single_D_2;
        delete object->Single_D_3;
        delete object->Single_D_4;
        for (short i = 0; i < box_size; i++) {
            for (short j = 0; j < box_size; j++) {
                box[i][j] = nullptr;
            }
        }
    }

    bool check_condition(Ship_list* object) {
        Ship_node* temp = object->first;
        while (temp != nullptr) {
            if (temp->ship->check_condition()) {
                return false;
            }
            temp = temp->next;
        }       
            return true;
    }

    bool check_condition(Ship_complect* object) {
        if (object->Four_D->check_condition()) {
            return false;
        }
        else {
            if (object->Three_D_1->check_condition()) {
                return false;
            }
            else {
                if (object->Three_D_2->check_condition()) {
                    return false;
                }
                else {
                    if (object->Two_D_1->check_condition()) {
                        return false;
                    }
                    else {
                        if (object->Two_D_2->check_condition()) {
                            return false;
                        }
                        else {
                            if (object->Two_D_3->check_condition()) {
                                return false;
                            }
                            else {
                                if (object->Single_D_1->check_condition()) {
                                    return false;
                                }
                                else {
                                    if (object->Single_D_2->check_condition()) {
                                        return false;
                                    }
                                    else {
                                        if (object->Single_D_3->check_condition()) {
                                            return false;
                                        }
                                        else {
                                            if (object->Single_D_4->check_condition()) {
                                                return false;
                                            }
                                            else {
                                                return true;
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

    ~Sea_Battle() {
        /*if (player.complect_condition) {
            delete player.Four_D;
            delete player.Three_D_1;
            delete player.Three_D_2;
            delete player.Two_D_1;
            delete player.Two_D_2;
            delete player.Two_D_3;
            delete player.Single_D_1;
            delete player.Single_D_2;
            delete player.Single_D_3;
            delete player.Single_D_4;
        }
        if (computer.complect_condition) {
            delete computer.Four_D;
            delete computer.Three_D_1;
            delete computer.Three_D_2;
            delete computer.Two_D_1;
            delete computer.Two_D_2;
            delete computer.Two_D_3;
            delete computer.Single_D_1;
            delete computer.Single_D_2;
            delete computer.Single_D_3;
            delete computer.Single_D_4;
        }*/
        for (short i = 0; i < box_size; i++) {
            delete[] Player_box[i];
            delete[] Comp_box[i];
        }
        delete[] Player_box;
        delete[] Comp_box;
    }
};
short canc_choice(short x) {
    if (x > 2 || x < 1) {
        while (x > 2 || x < 1) {
            std::cout << "Неверный ввод!!!\n- ";
            std::cin >> x;
        }
    }
    return x;
}

void Main_menu() {
    print_line(1);
    std::cout << "|\t\t\t\tМеню\t\t\t\t |\n";
    print_line(1);
    std::cout << "|\t 1 - начать новую игру с автоматической расстановкой\t |\n";
    print_line(1);
    std::cout << "|\t 2 - самостоятельно расставить корабли\t\t\t |\n";
    print_line(1);
}

char shoot() {
    char y = ' ';
    std::cout << "Введите букву A - J\n- ";
    std::cin >> y;
    short z = Transformation(y);
    if (z > 9 || z < 0) {
        while (z > 9 || z < 0) {
            std::cout << "Неверный ввод\nВведите букву A - J\n- ";
            std::cin >> y;
            short z = Transformation(y);
            std::cout << z;
            if (z >= 0 && z <= 9) {
                break;
            }
        }
    }
    std::cout << "Введите цифру от 0 - 9\n- ";
    return y;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Sea_Battle Play;
    Main_menu();
    short choice = 0;
    std::cout << "- ";
    std::cin >> choice;
    choice = canc_choice(choice);
    if (choice == 1) {
        Play.Auto_placement(Play.Get_pl_box(), Play.Get_list_gamer());
        Play.box_out(Play.Get_pl_box());
        std::cout << "Оставить?\n1 - да\n2 - нет\n- ";
        std::cin >> choice;
        choice = canc_choice(choice);
        if (choice == 2) {
            while (choice == 2) {
                Play.canc_placement(Play.Get_pl_box(), Play.Get_list_gamer());
                Play.Auto_placement(Play.Get_pl_box(), Play.Get_list_gamer());
                Play.box_out(Play.Get_pl_box());
                std::cout << "Оставить?\n1 - да\n2 - нет\n- ";
                std::cin >> choice;
                choice = canc_choice(choice);
            }
        }
    }
    else {
        Play.box_out(Play.Get_pl_box());
        Play.Placement(1);
        Play.box_out(Play.Get_pl_box());
        std::cout << "Оставить?\n1 - да\n2 - нет\n- ";
        std::cin >> choice;
        choice = canc_choice(choice);
        if (choice == 2) {
            while (choice == 2) {
                Play.box_out(Play.Get_pl_box());
                Play.canc_placement(Play.Get_pl_box(), Play.Get_list_gamer());
                Play.Placement(1);
                Play.box_out(Play.Get_pl_box());
                std::cout << "Оставить?\n1 - да\n2 - нет\n- ";
                std::cin >> choice;
                choice = canc_choice(choice);
            }
        }
    }
    Play.Auto_placement(Play.Get_comp_box(), Play.Get_list_comp());
    short step = 0;
    while (!Play.check_condition(Play.Get_list_comp()) || !Play.check_condition(Play.Get_list_gamer())) {
        Sleep(1000);
        Play.box_out();
        short x;
        char y;
        y = shoot();
        std::cin >> x;
        if (x > 9 || x < 0) {
            while (x < 0 || x > 9) {
                std::cout << "Неверный ввод\nВведите цифру 0 - 9\n- ";
                std::cin >> x;
            }
        }
        short check = Play.shoot(Play.Get_comp_box(), Play.Get_list_comp(), x, y);
        while(check == 0 || check == 4) {
            if (check == 4) {
                if (Play.check_condition(Play.Get_list_comp())) {
                    std::cout << "\nВы победили!!!\nКолличество ходов - " << step << std::endl;
                    goto stop;
                }
            }
            Sleep(700);
            Play.box_out();
            y = shoot();
            std::cin >> x;
            if (x > 9 || x < 0) {
                while (x < 0 || x > 9) {
                    std::cout << "Неверный ввод\nВведите цифру 0 - 9\n- ";
                    std::cin >> x;
                }
            }
            check = Play.shoot(Play.Get_comp_box(), Play.Get_list_comp(), x, y);
        }
        if (!Play.check_condition(Play.Get_list_comp())) {
            Play.box_out();
            check = Play.computer_shoot(Play.Get_pl_box(), Play.Get_list_gamer());
            while (check == 1 || check == 2) {
                if (check == 2) {
                    if (Play.check_condition(Play.Get_list_gamer())) {
                        std::cout << "\nВы проиграли!!!\nКолличество ходов - " << step << std::endl ;
                        goto stop;
                    }
                }
                check = Play.computer_shoot(Play.Get_pl_box(), Play.Get_list_gamer());
                if (check != 1 && check != 2) {
                    break;
                }
            }
        }
        step += 1;
    }
    stop:
    return 0;

}
