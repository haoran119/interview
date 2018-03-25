//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Rate {
public:
    Rate(double rate) : m_rate(rate), m_total(rate) {}  // inialization
    
    bool keep() {
//        cout << m_total << " ";

        if (m_total < 1 - 1e-10) {  // pay attention to the double precision control. Actually 1 is 0.999...9 in memory.
            m_total += m_rate;
            return false;
        } else {    // reset the rate
            m_total = m_total - 1 + m_rate;
            return true;
        }
    }

private:
    double m_rate, m_total;
};

int main()
{
    vector<Rate>    myRates{Rate(0.3), Rate(0.25)};
    
    /*
     0 0 0 1 0 0 1 0 0 1 0 0 0 1 0 0 1 0 0 1
     0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1
     */
    for (auto & myRate : myRates) {
        for (int i = 0; i < 20; i ++) {
            if (myRate.keep())
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}
