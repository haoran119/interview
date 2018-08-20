# -*- coding: utf-8 -*-
"""
Created on Wed Aug 15 16:52:30 2018

@author: hao
"""

def myfun1(x):
      x.append(1)

def myfun2(x):
      x += [2]

def myfun3(x):
      x[-1] = 3

def myfun4(x):
      x = [4]

def myfun5(x):
      x = [5]
      return x

# create a list
mylist = [0]
print(mylist)     # [0]

# change list
myfun1(mylist)
print(mylist)     # [0, 1]

# change list
myfun2(mylist)
print(mylist)     # [0, 1, 2]

# change list
myfun3(mylist)
print(mylist)     # [0, 1, 3]

# did NOT change list
myfun4(mylist)
print(mylist)     # [0, 1, 3]

# return a new list
mylist = myfun5(mylist)
print(mylist)     # [5]


def myfun(x=[1,2]):
      x.append(3)
      return x

print(myfun())    # [1, 2, 3]

# result is not [1, 2, 3] coz x was changed
print(myfun())    # [1, 2, 3, 3]
