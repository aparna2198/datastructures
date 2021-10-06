# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

class stack:
    def __init__(self):
        self.items=[]
        
    def isempty(self):
        return self.items==[]
    def push(self,val):
        self.items.append(val)
    def pop(self):
        if(s.isempty()):
            print("no items to pop")
        else:
            return self.items.pop();
    def show(self):
        return self.items
        
s=stack();
while True:
    print("1:push the element")
    print("2:pop")
    print("3:print")
    print("4:break")
    do=int(input("choose the op-->"))
    if do==1:
        val=input("enter the value")
        s.push(val)
    elif do==2:
        print("popped ",s.pop())
    elif do==3:
        print("items are ->",s.show())
    else:
        break
        

