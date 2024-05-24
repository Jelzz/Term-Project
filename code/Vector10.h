#ifndef VECTOR10_H__
#define VECTOR10_H__

class Vector10 {
public:
  // Constructor. Initialize all private members here. Set all array values to
  // zero.
  Vector10();

  // Deconstructor. You don't need to add anything here.
  ~Vector10();

  // get an index return the value of array at that index
  int value_at(int index);

  // puts value in the last empty spot of array (back). Returns false if the
  // array is already full. Return true if the push was successful. The data in
  // the array should be contiguous starting at index zero.
  bool push_back(int value);

  // return the number of empty spaces left in the array. E.g. when the Vector10
  // is first initialized this should be 10; when it is completely full this
  // returns 0.
  int count_empty();

  // Search for the given value in the array and returns true if value is in the
  // array, and false otherwise.
  bool search(int value);

  // Remove data from the array at the given index, and 'shift' values at higher
  // indices if needed. For example, if we have values [100, 200, 300, 400] and
  // we are asked to remove index 1 (the 200), the vector will then be [100,
  // 300, 400] - the 300 and 400 have both shifted down by one index so the
  // array data is packed from the left, starting at index 0.
  //
  // If the requested index is not in the range of valid data locations then
  // function returns false. Otherwise it removes the value and returns true.
  bool remove(int index);

  // you can add more public member variables and member functions here if you
  // need

private:
  int arr[10];
  // you can add add more private member variables and member functions here if
  // you need
};

#endif // VECTOR10_H__
