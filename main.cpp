#include <iostream>
//#include <windows.>

using namespace std;

void welcome() {
    cout << "\033[1;35m";
    cout << "Лабораторна робота 3. Дослідження процесу побудови умовних виразів та розгалужень в Асемблері.\n";
    cout << "\033[1;36m";
    cout << "Завдання 1. Реалізацію if/else\n";
    cout << "\033[1;35m";
    cout << "Парафіло Яна. КБ-22 \n";
    cout << "\033[0m";
}
int main() {
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    welcome();
    signed char A, B, C;
    int result;

    // Введення змінних
    cout << "Введіть A: ";
    cin >> A;
    cout << "Введіть B: ";
    cin >> B;
    cout << "Введіть C: ";
    cin >> C;

    __asm {
        // Перевіряємо умову (A >= 7)
        mov al, A
        cmp al, 7
        jl check_C  // Якщо A < 7, переходимо до перевірки C

        // Перевіряємо умову (B <= 3)
        mov al, B
        cmp al, 3
        jg check_C  // Якщо B > 3, переходимо до перевірки C

        // Якщо (A >= 7) і (B <= 3) виконується → встановлюємо EAX = 30
        mov eax, 30
        jmp end_if

    check_C:
        // Перевіряємо умову (C == 10)
        mov al, C
        cmp al, 10
        je set_result  // Якщо C == 10 → встановлюємо EAX = 30

        // Якщо жодна умова не виконана → встановлюємо EAX = -30
        mov eax, -30
        jmp end_if

    set_result:
        mov eax, 30

    end_if:
        mov result, eax
    }

    // Виведення результату
    cout << "Значення EAX: " << result << endl;

    cout << "\033[1;35m" << "\nДякую за використання програми!\n\tПарафіло Яна КБ-22" << "\033[0m" << endl;
    return 0;
}