#include "list.hpp"
#include <iostream>
using namespace ForwardListName;

auto ForwardList::Add(Node *&curr, int val) -> void {
  if (curr == nullptr)
    curr = new Node{val, nullptr};
  else {
    Add(curr->next, val);
  }
}

auto ForwardList::insert(int val) -> void { Add(first, val); }

auto ForwardList::change_color(int c) -> void {
#ifdef _WIN32
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
  switch (c) {
    case BLUE:  // blue color
#if defined(__gnu_linux__) || (defined(__APPLE__) && defined(__MACH__))
      std::cout << "\033[34m";
#endif
#ifdef _WIN32
      SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 3));
#endif
      break;
    case GREEN:  // green
#if defined(__gnu_linux__) || (defined(__APPLE__) && defined(__MACH__))
      std::cout << "\033[32m";
#endif
#ifdef _WIN32
      SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
#endif
      break;
    case WHITE:  // white
#if defined(__gnu_linux__) || (defined(__APPLE__) && defined(__MACH__))
      std::cout << "\033[39;49m";
#endif
#ifdef _WIN32
      SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
#endif
      break;
    case RED:  // red
#if defined(__gnu_linux__) || (defined(__APPLE__) && defined(__MACH__))
      std::cout << "\033[31m";
#endif
#ifdef _WIN32
      SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
#endif
      break;
    case CYAN:
#if defined(__gnu_linux__) || (defined(__APPLE__) && defined(__MACH__))
      std::cout << "\033[36m";
#endif
#ifdef _WIN32
      SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
#endif
  }
}

auto ForwardList::Remove(int val) -> bool {
  bool flag_remove = false;
  bool del = true;
  bool del_1 = false;

  Node *curr = first;
  Node *ptr = curr;

  if (curr->data == val) {
    del_1 = true;
    flag_remove = true;
  }
  // else  del = false;

  curr = curr->next;

  while (curr != nullptr) {
    if (flag_remove == false) {
      if (curr->data == val) {
        ptr->next = curr->next;
        delete curr;
        curr = ptr->next;
        flag_remove = true;
      } else {
        del = false;
        ptr = ptr->next;
        curr = curr->next;
      }
    } else {
      del = true;
      break;
    }
  }

  if (flag_remove == true) del = true;

  if (del == false) {
    std::cout << "Элемент " << val << " отсутствует" << std::endl;
    del = true;
  }

  if (del_1) {
    if ((first->data == val) && (first->next == nullptr)) {
      std::cout << "Список пуст" << std::endl;
      first = nullptr;
      return false;
    } else {
      curr = first->next;
      delete first;
      first = curr;
    }
  }

  return del;
}

auto ForwardList::print() -> void {
  if (first == nullptr) {
    std::cout << "Список пуст" << std::endl;
  } else {
    Node *curr = new Node{0, nullptr};
    curr = first;
    while (1) {
      if (curr != first) std::cout << " -> ";
      std::cout << curr->data << " ";
      if (curr->next == nullptr) break;
      curr = curr->next;
    }
  }
}

auto ForwardList::item_position(int val) -> bool {
  Node *curr = new Node{0, nullptr};
  curr = first;
  bool flag = true;
  int position = 0;
  while (curr != nullptr) {
    if (curr->data == val) {
      change_color(BLUE);
      std::cout << position << " ";
      ++position;
      curr = curr->next;
      flag = false;
    } else {
      curr = curr->next;
      ++position;
    }
  }
  if (flag) {
    change_color(RED);
    std::cout << "Элемент не найден";
  }
  std::cout << std::endl;
}

auto ForwardList::item_replacement(int item_position, int val) -> bool {
  Node *curr = new Node{0, nullptr};
  curr = first;
  bool flag = true;
  int position = 0;
  while (curr != nullptr) {
    if (position == item_position) {
      curr->data = val;
      flag = false;
      break;
    } else {
      curr = curr->next;
      ++position;
    }
  }
  if (flag) {
    change_color(RED);
    std::cout << "Элемент с позицией " << val << " не существует" << std::endl;
  }
}

auto ForwardList::items_sort() -> void {
  int k = 0;
  Node *curr = new Node{0, nullptr};
  curr = first;
  while (curr != nullptr) {
    ++k;
    curr = curr->next;
  }

  curr = first;

  int *Massiv = new int[k];

  k = 0;

  while (curr != nullptr) {
    Massiv[k] = curr->data;
    ++k;
    curr = curr->next;
  }

  for (unsigned int i = 0; i < k; ++i)
    for (unsigned int j = 0; j < k - 1; ++j) {
      if (Massiv[j] > Massiv[j + 1]) {
        int count = Massiv[j];
        Massiv[j] = Massiv[j + 1];
        Massiv[j + 1] = count;
      }
    }
  curr = first;
  k = 0;
  while (curr != nullptr) {
    curr->data = Massiv[k];
    ++k;
    curr = curr->next;
  }
  delete[] Massiv;
}

ForwardList::~ForwardList() {
  while (first != nullptr) {
    Node *temp = first->next;
    delete first;
    first = temp;
  }
}
