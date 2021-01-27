//
// Created by Carlos Daniel on 27/01/2021.
//

#include <iostream>
#include "Vector.h"

int main(){
    Vector<int> numbers;

    // Inserting data into the vector
    for (int i = 1; i <= 20; ++i) {
        numbers.push_back(i);
    }

    // Printing the vector
    numbers.printVector();
    cout << "Vector size: "<<numbers.size()<<"\n";

    // Making pop_back and pop_front to the vector
    numbers.pop_back();
    numbers.pop_front();

    // Printing the vector
    numbers.printVector();
    cout << "Vector size: "<<numbers.size()<<"\n";

    // Removing data from the vector
    int i = 1;
    while (i <= 10){
        numbers.pop_back();
        i++;
    }

    // Printing the vector
    numbers.printVector();
    cout << "Vector size: "<<numbers.size()<<"\n";

    // Defining a configured vector
    Vector<int> numbers2(20, 1);

    // Printing the configured vector
    numbers2.printVector();
    cout << "Vector size: "<<numbers2.size()<<"\n";
}
