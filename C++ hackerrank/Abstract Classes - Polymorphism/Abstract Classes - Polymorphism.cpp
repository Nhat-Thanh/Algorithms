#include <algorithm>
#include <iostream>
#include <map>
#include <string>

struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) : prev(p), next(n), key(k), value(val){};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache {

  protected:
    std::map<int, Node*> mp;                 //map the key to the node in the linked list
    int cp;                             //capacity
    Node* tail;                         // double linked list tail pointer
    Node* head;                         // double linked list head pointer
    virtual void set(int, int) = 0;     //set function
    virtual int get(int) = 0;           //get function
};

// My Code
class LRUCache : public Cache {
  private:
    int real_size;

  public:
    int static index;
    LRUCache(int);
    void set(int, int) override;
    int get(int) override;
};

int LRUCache::index = 0;

LRUCache::LRUCache(int cp) {
    this->cp = cp;
    real_size = 0;
    tail = nullptr;
    head = nullptr;
}

void LRUCache::set(int key, int val) {
    if (mp[key] == nullptr) {
        if (real_size >= cp) {
            Node* tmp = head;
            mp[head->key] = nullptr;
            head = head->next;
            delete tmp;
        } else {
            Node* n = new Node(key, val);
            mp[key] = n;
            if (head == nullptr) {
                head = n;
                tail = n;
            } else {
                tail->next = n;
                n->prev = tail;
                tail = n;
            }
            real_size += 1;
        }
    } else {
        mp[key]->value = val;
    }
}

int LRUCache::get(int key) {
    if (mp[key] != nullptr)
        return mp[key]->value;
    return -1;
}
// End My Code

int main() {
    int n, capacity, i;
    std::cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++) {
        std::string command;
        std::cin >> command;
        if (command == "get") {
            int key;
            std::cin >> key;
            std::cout << l.get(key) << '\n';
        } else if (command == "set") {
            int key, value;
            std::cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
