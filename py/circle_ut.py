#sg
'''A suite of unit tests for the Circle class'''
from circles import Point
from circles import Circle
import unittest

class TestCircles(unittest.TestCase):
    def setUp(self):
        self.p1 = Point(-30, 30)
        self.p2 = Point(40, 40)
        self.p3 = Point(-40, 40)
        self.p4 = Point(-40, -40)
        self.o = Point(0, 0)
        self.circle1 = Circle.circleFromGrid(self.o, self.p1)
        self.circle2 = Circle.circleFromGrid(self.o, self.p2)

    def test_isInside(self):
        import math
        self.assertEqual(self.circle2.center.x, -20)
        self.assertEqual(self.circle2.center.y, 20)
        self.assertEqual(self.circle2.radius, 20)
        self.p1 = Point(-30, 30)
        self.assertEqual(self.p1.distance(Point(-20, 20)), math.sqrt(200))

if __name__ == '__main__':
    unittest.main()


