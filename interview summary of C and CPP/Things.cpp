//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

class Thing {
public:
    void    doSomething() { cout << __func__ << endl; }
    Thing*    next;
};

class Things {
public:
    Things(Thing *myThing) : head(myThing), current(myThing) {}
    
    Thing*  First() {
        return head;
    }
    
    Thing*  Next() {
        current = current->next;
        return current;
    }
    
    bool OK() {
        if (current != nullptr)
            return true;
        else
            return false;
    }
    
private:
    Thing *head, *current;
};

int main()
{
    Thing*   myThing = new Thing;
    Things myThings(myThing);
    
    // This is how we do with class Things
    /*
     doSomething
     */
    for (Thing *ptr = myThings.First(); myThings.OK(); myThings.Next()) {
        ptr->doSomething();
    }
    
    return 0;
}
