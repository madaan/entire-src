#sg
'''
Given n points (x_i, y_i) such that (0, 0) and (x_i, y_i) define a square grid,
this program draws n circles such that i th circle fits in the ith grid
'''

class Point:
    def __init__(self, x=None, y=None):
        if(x is None):
            self.x = 0
        else:
            self.x = x
        if(y is None):
            self.y = 0
        else:
            self.y = y

    '''
    Finds distance of Point a from the current point
    '''
    def distance(self, a):
        import math
        hdiff = abs(a.y - self.y)
        wdiff = abs(a.x - self.x)
        return math.sqrt(hdiff * hdiff + wdiff * wdiff)


class Circle:
    color = 0
    def __init__(self, center, radius):
        self.center = center
        self.radius = radius

    '''Factory method:Takes a lower left and bottom up point and returns a circle'''
    @staticmethod
    def circleFromGrid(ll, ru):
        if(ru.x < 0 and ru.y < 0):
            quad = 3
        elif(ru.x < 0 and ru.y > 0):
            quad = 2
        elif(ru.x > 0 and ru.y < 0):
            quad = 4
        elif(ru.x > 0 and ru.y > 0):
            quad = 1
        if(ru.x < 0):
            ru.x = -ru.x
        if(ru.y < 0):
            ru.y = -ru.y
        
        height = ru.y - ll.y
        width = ru.x - ll.x
        center = Point(ll.x + height / 2, ll.y +  width / 2)
        radius = width / 2
        if(quad == 4):
            center.y = -center.y
        elif(quad == 3):
            center.x = -center.x
            center.y = -center.y
        elif(quad == 2):
            center.x = -center.x
        return Circle(center, radius)

    '''
    Draws a circle given a point on the canvas
    if drawBB is true, additionally draw a bounding box
    '''
    def draw(self, canvas, offset = Point(0, 0), drawBB=False):
        #create bounding box
        outlineColor = Circle.color + 1
        Circle.color = Circle.color + 1
        x0 = self.center.x - self.radius + offset.x
        y0 = self.center.y + self.radius + offset.y
        x1 = self.center.x + self.radius + offset.x
        y1 = self.center.y - self.radius + offset.y
        import random
        r = lambda: random.randint(0,255)
        color = "#%02X%02X%02X" % (r(),r(),r())
        canvas.create_oval(x0, y0, x1, y1, outline=color, width = 2)
        if(drawBB):
            canvas.create_rectangle(x0, y0, x1, y1)

    '''
    Tests whether a point p is inside this circle
    '''
    def checkInside(self, p):
        return self.center.distance(p) <= self.radius

class Util:
    '''Returns the grid points read from a file 
    as a list'''
    @staticmethod
    def readPoints(fileName):
        points = []
        for line in open(fileName, 'r'):
            coords = line.split(" ")
            points.append(Point(int(coords[0]), int(coords[1])))
        return points


if __name__ == '__main__':
    import sys
    from Tkinter import *
    master = Tk()
    pointsFile = sys.argv[1]
    gridPoints = Util.readPoints(pointsFile)
    circles = []
    for gridPoint in gridPoints:
        circles.append(Circle.circleFromGrid(Point(0, 0), gridPoint))

    w = Canvas(master, width=1000, height=600, background = "#ffffff")
    for circle in circles:
        circle.draw(w, Point(500, 300), drawBB = True)

    points_in_circle = 0
    for gridPoint in gridPoints:
        for circle in circles:
            if(circle.checkInside(gridPoint)):
                points_in_circle = points_in_circle + 1
                break

    
    points_text = "Grid points inside some circle : %d" % points_in_circle
    lbl = Label(master, text = points_text)
    lbl.pack()
    w.pack(fill=BOTH, expand=1)
    master.mainloop()
    print points_in_circle
