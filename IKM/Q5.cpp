//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

class Bus {
protected:
    class Driver; // forward declarations

public:
    static Driver* createDriver() {
        return new Driver;
    }

//    friend void useBus();
    
private:
    int seats;
protected:
    class Driver {
    public:
        string  name;
    };
};

class DeriveDriver : public Bus {};

void useBus()
{
    Bus::Driver*    driver = Bus::createDriver(); // 'Driver' is a protected member of 'Bus'
//    DeriveDriver::Driver*    driver = Bus::createDriver(); // 'Driver' is a protected member of 'Bus'
    
    driver->name = "DRIVER";
}

int main(int argc, char* argv[])
{
    return 0;
}
