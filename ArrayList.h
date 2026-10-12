#pragma once
#include <iostream>
#include "List.h"

template <typename T>
class ArrayList : public List<T> {
public:
    ArrayList() : size_(0) {}

    void addFront(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        for (int i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }
        data_[0] = value;
        ++size_;
    }
    void deleteFront() override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        delete data_[0];
        for (int i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }
    bool search(T* value) const override {
        for (int i = 0; i < size_; ++i) {
            if (*data_[i] == *value) return true;
        }
        return false;
    }
    void print() const override {
        for (int i = 0; i < size_; ++i) {
            std::cout << *data_[i] << ",";
        }
        std::cout << std::endl;
    }
    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete data_[i];
        }
    }

    void addAnywhere(int position, T* value) override {
        if (position == 0) {
            addFront(value);
            return;
        }
        // validity checks
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is already full" << std::endl;
            return;
        }
        if (position < 0 || position > size_) {
            std::cout << "Invalid position" << std::endl;
            return;
        }

        for (int i = size_; i > position; --i) {
            data_[i] = data_[i - 1];
        }
        data_[position] = value;
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
        delete data_[position];
        for (int i = position; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    void reverse() override {
        for (int i = 0; i < size_ / 2; ++i) {
            T* temp = data_[i];
            data_[i] = data_[size_ - 1 - i];
            data_[size_ - 1 - i] = temp;
        }
    }

    void concat(List<T>* list2) override {
        ArrayList<T>* array2 = dynamic_cast<ArrayList<T>*>(list2);

        if (array2 == nullptr) {
            std::cout << "Invalid types" << std::endl;
            return;
        }

        if (size_ + array2->size_ > CAPACITY) {
            std::cout << "Not enough capacity" << std::endl;
            return;
        }

        for (int i = 0; i < array2->size_; ++i) {
            addAnywhere(size_, array2->data_[i]);
        }
        array2->size_ = 0;
    }

private:
    static const int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_;
    
};