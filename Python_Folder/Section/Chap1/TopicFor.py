import turtle
import math

def isAngle(a, b, c):
    if (a + b > c) and (a + c > b) and (b + c > a):
        return True
    else:
        return False

def drawAngle(a, b, c):
    cosa = (b * b + c * c - a * a) / (2.0 * b * c)
    cosb = (a * a + c * c - b * b) / (2.0 * a * c)
    cosc = (a * a + b * b - c * c) / (2.0 * a * b)
    dega = math.acos(cosa) * 180 / math.pi
    degb = math.acos(cosb) * 180 / math.pi
    degc = math.acos(cosc) * 180 / math.pi
    p = (a + b + c) / 2.0
    area = math.sqrt(p * (p - a) * (p - b) * (p - c))
    myTurtle = turtle.Turtle()
    myScreen = turtle.Screen()
    myTurtle.penup()
    myTurtle.goto(-200, -200)
    myTurtle.pendown()
    myTurtle.pencolor("red")
    myTurtle.pensize(5)
    myTurtle.fd(a)
    myTurtle.left(180 - degc)
    myTurtle.fd(b)
    myTurtle.left(180 - dega)
    myTurtle.fd(c)
    myTurtle.penup()
    myTurtle.goto(-200 + a / 2, -220)
    myTurtle.pendown()
    myTurtle.write(str(area))
    myTurtle.penup()
    myTurtle.goto(600, -220)
    myScreen.exitonclick()

def drawStr():
    myTurtle = turtle.Turtle()
    myScreen = turtle.Screen()
    myTurtle.penup()
    myTurtle.goto(-100, 0)
    myTurtle.pendown()
    myTurtle.pencolor("red")
    myTurtle.pensize(5)
    myTurtle.write("It isn't an angle.")
    myTurtle.penup()
    myTurtle.goto(600, -220)
    myScreen.exitonclick()


def main():
    a = int(input("Please enter the side A: "))
    b = int(input("Please enter the side B: "))
    c = int(input("Please enter the side C: "))
    if isAngle(a, b, c) == True:
        drawAngle(a, b, c)
    else:
        drawStr()
if __name__ == '__main__':
    main()