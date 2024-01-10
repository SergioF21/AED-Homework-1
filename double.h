//
// Created by sergi on 10/01/2024.
//

#ifndef HWLIST_DOUBLE_H
#define HWLIST_DOUBLE_H

#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class DoubleList : public List<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(){
            data = 0;
            next = NULL;
            prev = NULL;
        }

        Node(T value){
            data = value;
            next = NULL;
            prev = NULL;
        }

    };

private:
    Node* head;
    Node* tail;
    int nodes;

public:
    DoubleList() : List<T>() {
        head=nullptr;
        tail=nullptr;
        nodes =0;
    }

    ~DoubleList(){
        clear();
    }

    T front(){
        if (head != nullptr)
            return head->data;
        throw ("Empty List");
    }

    T back(){
        if (tail != nullptr)
            return tail->data;
        throw ("Empty List");
    }

    void push_front(T data){
        Node* item = new Node(data);
        item->prev = nullptr;
        item->next = head;

        if (is_empty()) {
            tail = item;
        } else {
            if(item!= nullptr)
                head->prev = item;
        }

        head = item;
        nodes++;
    }

    void push_back(T data){
        Node* item = new Node(data);
        item->next = nullptr;
        item->prev = tail;

        if (is_empty()) {
            head = item;
        } else {
            tail->next = item;
        }

        tail = item;
        nodes++;
    }

    T pop_front(){
        if (!is_empty()) {
            T temp = head->data;

            Node* tempNode = head;
            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }

            delete tempNode;
            nodes--;
            return temp;
        } else {
            throw ("Empty List");
        }
    }

    T pop_back(){
        if (!is_empty()) {
            T temp = tail->data;

            Node* tempNode = tail;
            tail = tail->prev;

            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }

            delete tempNode;
            nodes--;
            return temp;
        } else {
            throw ("Empty List");
        }
    }

    void insert(T data, int pos){
        if (pos <= nodes && pos >= 0) {
            Node* node = new Node(data);

            if (pos == 0) {
                node->next = head;
                node->prev = nullptr;
                if (head != nullptr) {
                    head->prev = node;
                }
                head = node;
            } else {
                Node* temp = head;
                for (int i = 0; i < pos - 1; i++) {
                    temp = temp->next;
                }
                node->next = temp->next;
                node->prev = temp;
                if (temp->next != nullptr) {
                    temp->next->prev = node;
                }
                temp->next = node;
            }

            nodes++;
        } else {
            throw ("Error: Invalid position");
        }
    }

    void remove(int pos) {
        if (pos < nodes && pos >= 0) {
            if (pos == 0) {
                pop_front();
            } else if (pos == nodes - 1) {
                pop_back();
            } else {
                Node* temp = head;
                int count = 0;

                while (count < pos) {
                    temp = temp->next;
                    count++;
                }

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                delete temp;
                nodes--;
            }
        } else {
            throw ("Error: Invalid position");
        }
    }

    T& operator[](int pos){
        if (pos < nodes) {
            Node* temp = head;
            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }
            return temp->data;
        } else {
            throw ("Error: Invalid position");
        }
    }

    bool is_empty(){
        return nodes == 0;
    }

    int size(){
        return nodes;
    }

    void clear(){
        while (!is_empty()) {
            pop_back();
        }
    }

    void sort() {
        if(head == nullptr || head->next == nullptr)
            return;

        Node* current = head;
        Node* index = nullptr;
        T temp;

        while(current != nullptr) {
            index = current->next;
            while(index != nullptr) {
                if(current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }

    bool is_sorted(){
        if(head == nullptr || head->next == nullptr)
            return true;

        Node* temp = head;
        while(temp->next != nullptr){
            if(temp->data > temp->next->data){
                return false;
            }

            temp = temp->next;
        }
        return true;
    }

    void reverse(){
        Node* temp = head;

        while (temp != nullptr) {
            Node* nextNode = temp->next;
            temp->next = temp->prev;
            temp->prev = nextNode;
            temp = nextNode;
        }

        Node* tempHead = head;
        head = tail;
        tail = tempHead;
    }

    std::string name(){
        return "DoubleList";
    }

};


#endif //HWLIST_DOUBLE_H
