//
// Created by Radu on 3/25/2022.
//

#include "DynamicVector.h"

DynamicVector::DynamicVector(int capacity) {
    this->elements = new TElem[capacity];
    this->length = 0;
    this->capacity = capacity;
}

int DynamicVector::add(TElem element) {
    if(find(element) != -1)
        return 1;

    if(this->length == this->capacity){
        TElem* aux = new TElem[this->capacity * 2];
        for(int i = 0; i < this->length;i++, aux[i] = this->elements[i]);
        delete[] this->elements;
        this->elements = aux;
        this->capacity *= 2;
    }

    this->elements[this->length++] = element;
    return 0;
}

int DynamicVector::find(TElem element) {
    for(int i = 0; i<this->length;i++){
        if(this->elements[i] == element)
            return i;
    }
    return -1;
}

int DynamicVector::remove(int index) {
    if(index < 0 || index >= this->length)
        return 1;
    this->length--;
    for(int i = index; i < this->length; i++){
        this->elements[i] = this->elements[i+1];
    }
    return 1;
}

int DynamicVector::size() const{
    return this->length;
}

int DynamicVector::modify(TElem element, int index) const {
    if(index < 0 || index >= this->length)
        return 1;
    this->elements[index] = element;
    return 0;
}

