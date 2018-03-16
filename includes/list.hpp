enum col { BLUE, GREEN, WHITE, RED, CYAN };
namespace ForwardListName {
struct Node {
  int data;
  Node* next;
};

class ForwardList {
  Node* first;
  
 auto Add(Node*& curr, int val) -> void; 

 public:
  ForwardList() { first = nullptr; }

  auto insert(int value) const -> void;

  auto change_color(int c) -> void;

  auto Remove(int value) -> bool;

  auto print() const -> void;

  auto item_position(int val) -> bool;

  auto item_replacement(int item_position, int val) -> bool;

  auto items_sort() -> void;

  ~ForwardList();
};
}
