# -*- coding: utf-8 -*-
"""
Created on Fri Jul 17 15:07:33 2020

@author: APARNA
"""

list1=[]

def insert(val):
    list1.append(val)
    return list1
def isempty():
    return list1==[]
def remove(val):
    if not isempty():
        list1.remove(val)
        return list1
    else:
        raise TypeError("val is not present")
def delete(i):
    if not isempty():
        del list1[i]
        return list1
    else:
        raise TypeError("List is empty")
def find(val):
    if val in list1:
        return list1.index(val)
    else:
        raise TypeError("not found")
# insert(25)
# print(list1)
# insert(2)
# print(list1)
# insert('t')
# print(list1)
# remove(25)
# print(list1)
# delete(0)
# print(list1)

    