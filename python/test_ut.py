# -*- coding: utf-8 -*-
"""
Created on Fri Jul 17 13:53:02 2020

@author: APARNA
"""


import unittest
import ut

class TestUt(unittest.TestCase):
    def test_add(self):
        self.assertEqual(ut.add(4,4),8)
        self.assertEqual(ut.add(4,-4),0)
        self.assertEqual(ut.add(-4,-4),-8)
    def test_sub(self):
         self.assertEqual(ut.sub(4,4),0)
         self.assertEqual(ut.sub(4,-4),8)
         self.assertEqual(ut.sub(-4,-4),0)
        
    
if __name__=='__main__':
    unittest.main()

