#include <iostream>
#include <print>

// найти середину списка 

struct Node {
    int data_;
    Node* next;

    Node(int value) : data_{ value }, next{ nullptr } {} // конструктор от одного аргумента
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head{ nullptr } {} // конструктор по умолчанию

    void push_front(int val) {
        Node* newnode = new Node{ val };
        newnode->next = head;
        head = newnode;
    }

    void push_back(int val) {
        Node* newnode = new Node{ val };
        if (!head) {
            head = newnode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }

        current->next = newnode;
    }

    void print_list() {
        Node* current = head;

        while (current) {
            std::cout << current->data_ << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }

    ~LinkedList(){ // деструктор для освобождения памяти, начиная с головы.
        while (head){
            Node * tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    int size(){
        int res{0};
        Node* current = head;

        while (current->next != nullptr){
            current = current->next;
            res++;
        }

        return res;
    }

    int find_mid(){
        Node * slow = head;
        Node * fast = head;

        while (fast != nullptr && fast->next != nullptr){
            //std::println("{} {}", slow -> data_, fast -> data_);
            fast = fast->next->next;
            slow = slow -> next;
        }

        return slow->data_;
    }

    void deleteNode(int val){
        Node * tmp = new Node{0};
        tmp -> next = head;

        Node *prev = tmp;
        Node * current = head;

        while (current){
            if (current->data_ == val){
                prev -> next = current->next;
            } else{
                prev = current;
            }

            current = current ->next;
        }
    }
};

int main() {
    int val;
    std::cin >> val;
    LinkedList list{};

    int tmp;
    while (std::cin >> tmp){
        list.push_back(tmp);
    }

    std::cout << "Before:" << std::endl;
    list.print_list();

    std::cout << "After deleting:" << std::endl;
    list.deleteNode(val);
    list.print_list();
    
}