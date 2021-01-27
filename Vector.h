//Data Structure Vector

#ifndef __VECTOR_H
#define __VECTOR_H

#include <cassert>
#include <iostream>

using namespace std;
template <typename T>

class Vector{
	private:
       //Attributes
	   T* storage;
       unsigned int sz;
	   unsigned int capacity;

	   // Resize vector size
	   void resize(){
	       T* newStorage = new T[capacity * 2];
	       for(unsigned int i = 0; i < sz; i++){
	           newStorage[i] = storage[i];
	       }
	       delete [] storage;
	       storage = newStorage;
	       capacity = capacity * 2;
	   }
	public:
	   // Default Constructor
       Vector(): storage(new T[capacity]), sz(0), capacity(5) {}

       // Configured constructor
	   Vector(unsigned int size, T e): storage(new T[size]), sz(size), capacity(size) {
	       if (sz > 0){
               for (int i = 0; i < sz; ++i) {
                   storage[i] = e;
               }
	       }
	   }
	   
	   //Destructor
	   ~Vector(){ delete []  storage; }
	   
	   // Allows to work with the vector like an array (vectorName[position])
	   const T& operator[](unsigned int p) const{ return at(p); }
	   
	   //Returns vector size
	   unsigned int size() const{ return sz; }
	   
	   // Evaluates if the vector is empty
	   bool isEmpty(){ return sz == 0; }

	   // Inserts an element into the next vector position
	   void push_back(T e){
	       if(sz == capacity){
	           resize();
	       }
	       storage[sz] = e;
	       sz++;
	   }

       // Inserts an element into the first vector position
	   void push_front(T e){
	       if(sz == capacity){
	           resize();
	       }

	       T* newStorage = new T[capacity];
           newStorage[0] = e;

           sz++;

           for(unsigned int i = 1; i < sz; i++){
               newStorage[i] = storage[i - 1];
           }

           delete [] storage;
           storage = newStorage;
	   }

	   // Removes the element into the position p from de vector
	   void remove(unsigned int p){
	       assert(!isEmpty());
	       for(unsigned int i = p; i < sz; i++){
	           storage[i] = storage[i+1];
	       }
	       sz--;
	   }

       // Removes the element e from the vector, only if e is into the vector
       void removeElement(const T& e){
	       assert(find(e));
	       unsigned int s = sz;
	       for(unsigned int i = 0; s == sz; i++){
	           if (storage[i] == e){
	               for (unsigned int j = i; j < sz; j++){
	                   storage[j] = storage[j + 1];
	               }
	               sz--;
	           }
	       }
	   }

	   // Removes the element into the last vector position
	   void pop_back(){
	       assert(!isEmpty());
	       sz--;
	   }

	   // Removes the element into the first vector position
	   void pop_front(){
	       assert(!isEmpty());
	       for(unsigned int i=0; i<sz-1;i++){
	           storage[i] = storage[i+1];
	       }
	       sz--;
	   }

	   // Rotates the vector b positions
	   void rotate(unsigned int b){
	       for(unsigned int i = 0; i < b; i++){
	           push_back(storage[0]);
	           pop_front();
	       }
	   }

	   // Evaluates if a number e is into the vector
		bool find(T e)const{
	       for(unsigned int i = 0; i<sz; i++){
	           if(storage[i] == e){
	               return true;
	           }
	       }
	       return false;
	    }
	   
	   // Returns the element into the first vector position
	   T front(){
	       assert(!isEmpty());
	       return storage[0];
	   }
	   
	   // Returns the element into the last vector position
	   T back(){
	       assert(!isEmpty());
	       return storage[sz-1];
	   }
	   
	   // Returns the element into the position p from the vector
	   T& at(unsigned int p) const{
	       assert(p >= 0 && p < sz);
	       return storage[p];
	   }
	   
	   // Swaps the elements into x and y positions from the vector
       void swap(unsigned int x, unsigned int y){
	       assert(!isEmpty() && x>=0 && x<sz && y>=0 && y<sz);
	       T help = storage[x];
	       storage[x] = storage[y];
	       storage[y] = help;
	   }
	   
	   // Prints the vector
	   void printVector(){
	       if(!isEmpty()){
	           cout << "\n[";
	           for(int i = 0; i < sz-1; i++){
	               cout<<at(i) <<", ";
	           }
	           cout << at(sz-1) << "]\n";
	       }
	       else cout<<"\n[ ]\n";
	   }
	
	   // Makes a Binary search into the vector
	   int binarySearch(T x){ return binarySearch(0, sz - 1, x); }

    private:
       // Private Binary search
       int binarySearch(int l, int r, T x){
	       assert(sz > 0);
	       if(r >= l){
	           int mid = l + (r-l)/2;
	           if(storage[mid] == x){
	               return mid;
	           }
	           if(storage[mid] > x){
	               return binarySearch(l, mid - 1, x);
	           }
	           return binarySearch(mid + 1, r, x);
	       }
	       return -1;
	   }
};
#endif
