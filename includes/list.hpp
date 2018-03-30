enum col { BLUE, GREEN, WHITE, RED, CYAN };
namespace ForwardListName {
struct Node {
  int data;
  Node* next;
};

class ForwardList {
  Node* first;

 public:
  ForwardList() : first{nullptr}{};

  auto insert(int value) -> void;
  
  auto Add(Node*& curr, int val) -> void;

  auto Remove(int value) -> bool;

  auto print() const -> void;

  auto item_position(int val) -> bool;

  auto item_replacement(int item_position, int val) -> bool;

  auto items_sort() -> void;

  ~ForwardList();
};
}
