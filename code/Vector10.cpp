//  Vector10.cpp
//      This project creates a class that represents a vector data structure with size 10. 
//
//      The data structure includes methods to:
//        - Initialize the vector with values of 0
//        - Find the value at a particular index
//        - Add values to the end of the vector
//        - Count the empty spots in the vector
//        - Search for a value and confirm if it's in the vector or not
//        - Remove values from the vector
//
//  Author: Angelica Schira
//  CU ID: ansc5931
//  GitHub Username: Jelzz

#include "Vector10.h"

Vector10::Vector10() {
  for (int i = 0; i < arrSize; i++) {
    arr[i] = 0;
  }
}

Vector10::~Vector10() {
  // You don't need to add anything here
}

// Implement this function first, since all tests use it.
int Vector10::value_at(int index) {
  return arr[index];
}

// Implement this function second, since most tests use it.
bool Vector10::push_back(int value) {
  if (arrUsed < 10) {
    arr[arrUsed] = value;
    arrUsed += 1;
    return true;
  }
  return false;
}

int Vector10::count_empty() {
  return 10 - arrUsed;
}

bool Vector10::search(int value) {
  for (int i = 0; i < arrSize; i++) {
    if (arr[i] == value) {
      return true;
    }
  }
  return false;
}

bool Vector10::remove(int index) {
  if (arrUsed == 0) {
    return false;
  }
  else if (index > arrUsed - 1) {
    return false;
  }
  
  for (int i = index; i < arrUsed; i++) {
    arr[i] = arr[i+1];
  }
  arr[arrUsed - 1] = 0;
  arrUsed = arrUsed - 1;
  
  return true;
}