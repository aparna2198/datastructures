# -*- coding: utf-8 -*-
"""
Created on Thu Jul 16 16:59:11 2020

@author: APARNA
"""


def add(x,y):
    return x+y
def sub(x,y):
    return x-y
def mul(x,y):
    return x*y
def div(x,y):
    if y==0:
        raise ValueError('can not divide by zero')
        