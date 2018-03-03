//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

class Animal {
private:
    int position;
public:
    Animal() { position = 0; }
    void changePosition(int i) {
        position += i;
    }
};

class WalkingAnimal : virtual public Animal {
public:
    void move() { changePosition(2); }
};

class SwimmingAnimal : virtual public Animal {
public:
    void move() { changePosition(1); }
};

class Pengiun : public WalkingAnimal, public SwimmingAnimal {
public:
    void swim() {
        // insert code here
//        SwimmingAnimal.move(); // Use of undeclared identifier 'SwimmingAnimal'
        SwimmingAnimal::move();
        Animal::changePosition(2);
//        move(); // Member 'move' found in multiple base classes of different types
//        position += 2;  // 'position' is a private member of 'Animal'
    }
    void walk() {}
};

int main(int argc, char **argv)
{
    return 0;
}
