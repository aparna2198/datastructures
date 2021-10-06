# -*- coding: utf-8 -*-
"""
Created on Fri Jul 17 15:07:51 2020

@author: APARNA
"""


import unittest
import list1

class TestList1(unittest.TestCase):
    def test_insert(self):
        self.assertEqual(list1.insert(25),[25])
        self.assertEqual(list1.insert(2),[25,2])
        self.assertEqual(list1.insert('t'),[25,2,'t'])
    def test_remove(self):
        self.assertEqual(list1.remove(25),[2,'t'])
        # self.assertEqual(list1.remove('c'),"val is not present")
    # def test_delete(self):
    #          self.assertEqual(list1.delete(0),['t'])
    # # def test_find(self):
    # #     self.assertEqual(list1.find('t'),0)
    #     # self.assertEqual(list1.find(32),"not found")
        
if __name__=='__main__':
    unittest.main()