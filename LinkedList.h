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

    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }
private:
    Node<T>* head_;
    int size_;
};