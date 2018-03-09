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

auto ForwardList::insert(int val) -> void { 
  Add(first, val);}

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
    else  del = false;
    
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
    } else break;
  }

  if (del == false){
    std::cout << "Элемент " << val << " отсутствует" << std::endl;
    del = true;
  }

  if (del_1) {
    if ((first->data == val) && (first->next == nullptr)) {
      std::cout << "Список пуст" << std::endl;
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
  if (first == nullptr){
          std::cout << "Список пуст"<< std::endl;
  }
	else{
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
ForwardList::~ForwardList() {
  while (first != nullptr) {
    Node *temp = first->next;
    delete first;
    first = temp;
  }
}
