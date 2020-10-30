import turtle
myTurtle = turtle.Turtle()
def kehe(n,size):
    if n==1:
        myTurtle.fd(size)
    else:
        for i in [0,60,-120,60]:
            myTurtle.left(i)
            kehe(n-1,size/3)
            
def start():
    myScreen = turtle.Screen()
    myTurtle.setheading(0)
    myTurtle.penup()
    myTurtle.fd(0)
    myTurtle.pendown()
    fact=5
    for i in [0,1,2]:
        myTurtle.right(120)
        kehe(fact,200)
    myScreen.exitonclick()
start()
