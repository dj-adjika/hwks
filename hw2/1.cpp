#include <iostream>
#include <print>

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

    void reverse_list() {
        Node* prev{0};
        Node* current = head;

        while (current) {
            Node* next = current->next;
            current -> next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    ~LinkedList() { // деструктор для освобождения памяти, начиная с головы.
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};

int main() {
    LinkedList list{};

    int tmp;
    while (std::cin >> tmp){
        list.push_back(tmp);
    }

    std::cout << "Before:" << std::endl;
    list.print_list();

    std::cout << "Reverse:" << std::endl;
    list.reverse_list();
    list.print_list();
}