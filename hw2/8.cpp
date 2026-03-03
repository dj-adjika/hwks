#include <iostream>
#include <print>

// найти середину списка 

struct Node {
    int data_;
    Node* next;

    Node(int value) : data_{ value }, next{ nullptr } {} // конструктор от одного аргумента
};

class LinkedList {
public:
    Node* head;
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
};

void merge(LinkedList& l1, LinkedList& l2){
    Node* head; // результирующая голова
    if (l1.head->data_ <= l2.head->data_) {
        head = l1.head;
        l1.head = l1.head->next;
    } else {
        head = l2.head;
        l2.head = l2.head->next;
    }

    Node* curr1 = l1.head;
    Node* curr2 = l2.head;
    Node* tail = head;

    while(curr1 && curr2){
        if (curr1->data_<=curr2->data_){
            tail->next = curr1;
            tail = curr1;
            curr1 = curr1->next;
        } else {
            tail->next = curr2;
            tail = curr2;
            curr2 = curr2->next;
        }
    }

    if (curr1){
        tail->next = curr1;
    } else if (curr2){
        tail->next = curr2;
    }

    l1.head = head;
    l2.head = nullptr;
    }

int main() {
    int n1, n2;
    std::cin >> n1 >> n2;
    LinkedList list1{};
    LinkedList list2{};

    int tmp1{0};
    while (n1>0){
        std::cin >> tmp1;
        list1.push_back(tmp1);
        n1--;
    }

    int tmp2{0};
    while (n2>0){
        std::cin >> tmp2;
        list2.push_back(tmp2);
        n2--;
    }

    std::cout << "Before1:" << std::endl;
    list1.print_list();

    std::cout << "Before2:" << std::endl;
    list2.print_list();

    LinkedList&ref1 = list1;
    LinkedList&ref2 = list2;

    merge(ref1, ref2);

    std::cout << "After merge:" << std::endl;
    list1.print_list();
}