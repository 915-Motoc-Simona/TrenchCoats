//
// Created by Simona on 18.03.2021.
//
#pragma once
#define INITIAL_CAPACITY 100

template <class T>
class DYNAMIC_ARRAY {
    T *Array;
    int Capacity = INITIAL_CAPACITY;
    int Size;
public:
    // constructor init
    DYNAMIC_ARRAY() {
        Array = new T[Capacity];
        Size = 0;
    }

    ~DYNAMIC_ARRAY(){
        delete[] Array;
    }

    // append at the end
    void add(T Element) {
        if(Size == Capacity) {
            resize();
        }
        Array[Size] = Element;
        Size++;
    }

    // return -1 => invalid position
    // return 0 => OK
    int deleteAt(int Position) {
        if((Position > Size) || (Position < 0)) {
            return -1;
        }

        for(int i = Position; i <= Size; i++) {
            Array[i] = Array[i+1];
        }
        Size--;
        return 0;
    }

    // returns size of array
    int length() {
        return Size;
    }

    // doubles capacity if it has to and deletes reference to current array.
    void resize() {
        Capacity *= 2;
        T *newBlock = new T[Capacity];
        copy(newBlock);
        delete [] Array;
        Array = newBlock;

    }

    // copies original array into temp
    void copy(T newBlock[]) {
        for(int i = 0; i < Size; i++) {
            newBlock[i] = Array[i];
        }
    }

    // returns element in x position.
    T get(int position) {
        return Array[position];
    }

    void set(int position, T elem){
        Array[position] = elem;
    }

};
