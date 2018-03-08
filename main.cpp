#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <limits>
#include "list.hpp"
using namespace ForwardListName;
using namespace std;

auto menu(ForwardList &, bool) -> void;

int main(int argc, char *argv[]) {
  ForwardList list;

  int n = 1;
  bool empty = true;

  if (argc == 1) {
    list.change_color(RED);
    cout << "Список пуст" << endl;
    empty = false;
    menu(list, empty);
  }

  if (argc == 2) {
    empty = true;
    string nach = argv[1], nachconst = nach;
    int j = 1, tmp = 0;

    for (int i = 0; i < strlen(nachconst.c_str()); i++) {
      if (nach[i] == ',') {
        j++;
      }
    }
    int *Mass = new int[j];

    j = 0;

    Mass[j] = atoi(nach.c_str());
    ++j;

    for (int i = 0; i < strlen(nachconst.c_str()); i++) {
      if (nach[0] != ',') {
        nach.erase(0, 1);
      } else {
        nach.erase(0, 1);
        Mass[j] = atoi(nach.c_str());
        j++;
      }
    }

    for (int i = 0; i < j; i++) {
      list.insert(Mass[i]);
    }

    menu(list, empty);

    delete[] Mass;

  } else {
    empty = true;
    for (int i = 1; i < argc; i++) {
      ++n;
    }

    int *Mass = new int[n];

    for (int i = 1; i < n; i++) {
      Mass[i] = atoi(argv[i]);
    }
    for (int i = 1; i < n; i++) {
      list.insert(Mass[i]);
    }
    menu(list, empty);

    delete[] Mass;
  }
}

auto menu(ForwardList &list, bool empty) -> void {
  int choise;
  string exit1;
  while (1) {
    list.change_color(CYAN);
    cout << "Выберите одну из операций: " << endl;
    cout << "1. Распечатать список " << endl;
    cout << "2. Добавить элементы в список " << endl;
    cout << "3. Удалить элемент " << endl;
    cout << "4. Найти позиции элементов" << endl;
    cout << "5. Заменить элемент на другой" << endl;
    cout << "6. Отсортировать элементы списка" << endl;
    cout << "7. Завершить работу программы" << endl;
    list.change_color(GREEN);
    cin >> choise;

    if ((empty == false) && (choise == 2)) empty = true;

    if ((empty == false) && (choise != 2) && (choise != 7)) {
      list.change_color(RED);
      cout << "Список пуст" << endl;
    }

    else {
      switch (choise) {
        case 1: {
          list.change_color(BLUE);
          list.print();
          std::cout << endl;
        } break;
        case 2: {
          string values, valuesconst;
          int k = 1;
          list.change_color(CYAN);
          cout << "Введите элементы: ";
          list.change_color(GREEN);
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          getline(cin, values);
          valuesconst = values;

          for (int i = 0; i < strlen(valuesconst.c_str()); i++) {
            if (values[i] == ' ') {
              ++k;
            }
          }

          int *Massiv = new int[k];

          k = 0;

          Massiv[k] = atoi(values.c_str());
          ++k;

          for (int i = 0; i < strlen(valuesconst.c_str()); i++) {
            if (values[0] != ' ') {
              values.erase(0, 1);
            } else {
              values.erase(0, 1);
              Massiv[k] = atoi(values.c_str());
              ++k;
            }
          }

          for (int i = 0; i < k; i++) {
            list.insert(Massiv[i]);
          }
          delete[] Massiv;
        } break;
        case 3: {
          int value;
          list.change_color(CYAN);
          cout << "Введите значение элемента: ";
          list.change_color(GREEN);
          cin >> value;
          list.change_color(RED);
          list.Remove(value);
        } break;
        // case 4:break;
        // case 5:break;
        // case 6:break;
        case 7: {
          list.change_color(RED);
          cout << "Вы уверены, что хотите выйти?(yes|no)" << endl;
          list.change_color(GREEN);
          cin >> exit1;
          if ((exit1 == "yes") || (exit1 == "YES") || (exit1 == "Yes") ||
              (exit1 == "y")) {
            cout << "До свидания !" << endl;
            exit(0);
          }
        } break;
      }
    }
  }
}
