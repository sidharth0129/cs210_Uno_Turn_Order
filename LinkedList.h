//
// Created by sidha on 9/17/2026.
//

#pragma once
#include <iostream>
#include "Node.h"
#include "List.h"

template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr), size_(0) {}
    void addFront(T* value) override {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head_;
        head_ = newNode;
        ++size_;
    }
    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        delete doomed->data;
        delete doomed;
        --size_;
    }
    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) return true;
            current = current->next;
        }
        return false;
    }
    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void addAnywhere(int position, T* value) override {
        if (position == 0) {
            addFront(value);
            return;
        }

        // validity
        if (position < 0 || position > size_) {
            std::cout << "Invalid position" << std::endl;
            return;
        }

        Node<T>* current = head_;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        Node<T>* newNode = new Node<T>(value);

        newNode->next = current->next;
        current->next = newNode;
        ++size_;
    }

    void deleteAnywhere(int position) override {
        if (position == 0) {
            deleteFront();
            return;
        }

        // validity
        if (position < 0 || position >= size_) {
            std::cout << "Invalid position" << std::endl;
            return;
        }

        Node<T>* current = head_;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        Node<T>* doomed = current->next;
        current->next = doomed->next;

        delete doomed->data;
        delete doomed;
        --size_;
    }

    void reverse() override {
        Node<T>* prev = nullptr;
        Node<T>* current = head_;

        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head_ = prev;
    }
    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }

    void concat(List<T>* list2) override {
        LinkedList<T>* linked2 = dynamic_cast<LinkedList<T>*>(list2);

        if (linked2 == nullptr) {
            std::cout << "Invaalid types" << std::endl;
            return;
        }
        if (head_ == nullptr) {
            head_ = linked2->head_;
        } else {
            Node<T>* current = head_;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = linked2->head_;
        }
        size_ += linked2->size_;
        linked2->head_ = nullptr;
        linked2->size_ = 0;


    }


private:
    Node<T>* head_;
    int size_;
};