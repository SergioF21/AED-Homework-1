//
// Created by sergi on 10/01/2024.
//

#ifndef HWLIST_FORWARD_H
#define HWLIST_FORWARD_H


#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
private:
    struct Node {
        T data;
        Node* next;

        Node(){
            data = NULL;
            next = NULL;
        }

        Node(T value){
            data = value;
            next = NULL;
        }

        void killSelf(){
            delete this;
        }
    };

private:
    Node* head;
    int nodes;

public:
    ForwardList() : List<T>() {
        head = nullptr;
        nodes = 0;
    }

    ~ForwardList(){
        //TODO
        clear();
    }

    T front() override {
        if (head == nullptr)
            throw("Lista vacia");
        return head->data;
    };

    T back() override {
        if (head == nullptr) {    throw("Lista vacia");  }
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }

    void push_front(T data) override {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
        nodes++;
    };

    void push_back(T data) override {
        Node* nval = new Node(data);
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next=nval;
        nodes++;
    }

    T pop_front() override {
        if(head == nullptr){
            throw("Lista vacia");
        }
        Node* temp = head;
        head = head->next;
        T val = temp->data;
        delete temp;
        nodes--;
        return val;
    }

    T pop_back() override{
        if(head == nullptr){
            throw("Lista vacia");
        }
        Node* temp = head;
        Node* prev = nullptr;
        while(temp->next != nullptr){
            prev = temp;
            temp = temp->next;
        }
        T val = temp->data;
        delete temp;
        prev->next = nullptr;
        nodes--;
        return val;
    };

    void insert(T data, int pos) override {
        if(pos > nodes){
            throw("Posicion invalida");
        }
        Node* temp = head;
        Node* prev = nullptr;
        for(int i = 0; i < pos; i++){
            prev = temp;
            temp = temp->next;
        }
        Node* nval = new Node(data);
        nval->next = temp;
        prev->next = nval;
        nodes++;
    };

    void remove(int pos) override{
        // del: es el nodo a eliminar
        Node* del = head;
        Node* prev = nullptr;

        // Buscar el nodo a eliminar y mantener un puntero al nodo anterior
        while (del && del->data != pos) {
            prev = del;
            del = del->next;
        }

        // Si el nodo a eliminar no se encuentra, simplemente salir
        if (!del) {
            return;
        }

        // Actualizar los punteros para eliminar el nodo
        if (!prev) {
            // El nodo a eliminar es el primero en la lista
            head = del->next;
        } else {
            // El nodo a eliminar no es el primero
            prev->next = del->next;
        }

        // Liberar memoria del nodo eliminado
        delete del;
    };

    T& operator[](int pos) override{
        Node* temp = head;
        for(int i=0;i<pos;i++){
            temp=temp->next;
        }
        return temp->data;
    }

    bool is_empty() override{
        return (nodes == 0);
    }

    int size() override{
        return nodes;
    }

    void clear() override{
        while (head != nullptr){
            pop_front();
        }
    }

    void sort() override{
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

    bool is_sorted() override{
        if(head == nullptr || head->next == nullptr)
            return true;

        Node* temp = head;
        while(temp->next != nullptr){
            if(temp->data > temp->next->data)
                return false;

            temp = temp->next;
        }

        return true;
    }

    void reverse() override{
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        Node* next_node;

        while (current != nullptr) {
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }

        head = prev;
    }

    std::string name() override{
        return "ForwardList";
    }

};

#endif //HWLIST_FORWARD_H
