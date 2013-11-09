//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: This uses the pre-processor to create a constant
// You could also use "const static" to make a constant, as in Java.
// Notice, however, that START_SIZE is NOT a variable! Instead, any
// place that the pre-processor sees "START_SIZE" it will replace it with
// 10 ... so this is like a global "find and replace".
#define START_SIZE 10

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this ArrayQueue() method belongs to the
// ArrayQueue<T> class.
	
template <class T>
ArrayQueue<T>::ArrayQueue(){
	backingArray = new T[START_SIZE];
	backingArraySize = START_SIZE;

	numItems = 0;
	front = 0; 
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	delete[] backingArray;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){

	if (numItems == backingArraySize) {
		grow();
	}
		
	int end = (front+numItems) % backingArraySize;
	backingArray[end] = toAdd;
	numItems++;
}

template <class T>
T ArrayQueue<T>::remove(){
	if (numItems == 0) {
		throw (std::string) "Remove call was improper!";
	}
	
	T x = backingArray[front];
	front = (front + 1) % backingArraySize;

	numItems--;
	
	return x;
	
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	int size = backingArraySize*2;

	if (backingArraySize == 0)
		size = 1;

	T* b = new T[size];

	if (b == NULL)
		throw (std::string) "Array is Null!";

	for (int k = 0; k < numItems; k++){
		b[k] = backingArray[(front+k) % backingArraySize];
		}

	delete[] backingArray;
	backingArray = b;
	backingArraySize = backingArraySize*2;

	front = 0;

}


