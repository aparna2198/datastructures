# -*- coding: utf-8 -*-
"""
Created on Thu Jul 16 15:10:04 2020

@author: APARNA
"""

# to create a single node
class Node:
    def __init__(self,val):
        self.left=None
        self.right=None
        self.v=val
        
        
class Tree:
    def __init__(self):
        self.root=None
    
    def getRoot(self):
        return self.root
    
    def add(self,val):
        if self.root is None:
            self.root=Node(val)
        else:
            self._add(val,self.root)
            
    def _add(self,val,node):
        if val<node.v:
            if node.left is not None:
             self._add(val,node.left)
            else:
                node.left=Node(val)
        else:
            if node.right is not None:
             self._add(val,node.right)
            else:
                node.right=Node(val)
    def find(self,val):
        if self.root is not None:
            return self._find(val,self.root)
    def _find(self,val,node):
        if val==node.v:
            print("found")
        elif val<node.v and node.left is not None:
            self._find(val,node.left)
        elif val<node.v and node.right is not None:
            self._find(val,node.right)
        else:
            print("not found")
            
    def deletetree(self):
        self.root=None
        print("tree is deleted")
        
    def printtree(self):
        if self.root is not None:
            print("tree values are show")
            self._printtree(self.root)
    def _printtree(self,node):
        if node is not None:
            self._printtree(node.left)
            print(str(node.v))
            self._printtree(node.right)
            
t=Tree()
while True:
    print("1 add elements")
    print("2 search")
    print("3 print tree")
    print("4 delete")
    choice=int(input("enter your choice:"))
    if choice ==1:
        val=int(input("enter the value:"))
        t.add(val)
    elif choice==2:
        val=int(input("enter the value:"))
        t.find(val)
    elif choice==3:
        t.printtree()
    elif choice==4:
        t.deletetree()
        break
    else:
        print("wrong choice")
   
                
    