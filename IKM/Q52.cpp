//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

class Account {
public:
    void deposit(int);
};

int main(int argc, char **argv)
{
    Account *checking = new Account;
    checking->deposit(1000);
    
    Account myAccount;
    myAccount.deposit(1000);
    
    checking = &myAccount;
    
    checking->deposit(1000);
    delete checking;
    
    Account* saving = new Account;
    
    Account & rsav = *saving;
    rsav.deposit(2000);
    delete rsav; // Cannot delete expression of type 'Account'
    
    return 0;
}
