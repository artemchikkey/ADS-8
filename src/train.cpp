// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    countOp = 0;
    first = nullptr;
}

void Train::addCage(bool light) {
    Cage* newCage = new Cage;
    newCage->light = light; 
    if (first == nullptr) {
        first = newCage;
        first->next = first;
        first->prev = first;
    } else {
        Cage* lastCage = first->prev;
        lastCage->next = newCage;
        newCage->prev = lastCage;
        newCage->next = first;
        first->prev = newCage;
    }
}

int Train::getLength() {
    int length = 0;
    Cage* current = first;
    do {
        length++;
        current = current->next;
    } while (current != first);
    return length;
}

int Train::getOpCount() {
    return countOp;
}
