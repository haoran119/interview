//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>

class Course {
    static int  classCount = 0; // Non-const static data member must be initialized out of line
    std::string courseName {"CS101"};
    int         room = 100;
    int quizzes[5] {0, 0, 0, 0, 0};

public:
    Course( ) {};
    Course(int a) : room(a) {}
    Course (std::string b) : courseName(b), room(200) {}
    Course(double d) : Course( static_cast<int>(d) ) {}
};

int main ()
{
    Course course1{};
    Course course2{300};
    Course course3{"EnglishlOl"};
    Course course4{3.14};

    return 0;
}
