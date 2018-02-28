//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

namespace controllers {
    namespace rotary {
        void spin(bool start) {
            if (!start) { }
        }
    }

    namespace horizontal {
        void move(bool start) {
            if (start) {
                // Use of undeclared identifier 'spin'; did you mean 'rotary::spin'?
//                spin(false); // location #1

                // No member named 'spin' in namespace 'controllers'; did you mean 'rotary::spin'?
//                controllers::spin(false);
                
                rotary::spin(false);
                
                // No member named 'spin' in namespace 'controllers::horizontal'; did you mean 'rotary::spin'?
//                horizontal::spin(false);
            }
        }
    }
}

int main(int argc, char **argv)
{
//    move(true); // location #2
    
//    controllers::horizontal::move(true);
    
    // Use of undeclared identifier 'horizontal'; did you mean 'controllers::horizontal'?
//    horizontal::move(true);
}
