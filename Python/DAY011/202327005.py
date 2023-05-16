import turtle

'''
turtle.shape('turtle')
i = 0
while i < 4:
    i += 1
    turtle.forward(100)
    turtle.left(90)

turtle.fillcolor("yellow")
turtle.begin_fill()
for i in range(0,5):
    turtle.forward(100)
    turtle.left(144)
turtle.end_fill()

turtle.fillcolor("orange")
turtle.begin_fill()
for i in range(0,6):
    turtle.forward(100)
    turtle.left(360/6)
turtle.end_fill()

for i in range(1,10):
    for j in range (0,4):
        turtle.forward(20*i)
        turtle.left(90)

j = 0
colours = ['red', 'blue', 'yellow','cyan']
for i in range(10):
    turtle.color(colours[j])
    turtle.circle(30)
    turtle.right(360/10)
    if (j > 2):
        j = 0
    j += 1

'''
turtle.speed(0)

# 육각형 그리기
coloursIndex = 0
colours = ['red', 'blue', 'yellow','cyan']
turtle.penup()
for i in range(1,14):
    turtle.begin_fill()
    for j in range(6):
        turtle.fillcolor(colours[coloursIndex])
        turtle.forward(150 - (10 * i))
        turtle.right(360/6)
    turtle.end_fill()
    turtle.right(30)
    coloursIndex += 1
    if coloursIndex > 3:
        coloursIndex = 0

# 빨간 달팽이 원 그리기
turtle.pendown()
turtle.color("red")
for i  in range(1, 100):
    turtle.circle(30+i)
    turtle.left(5)

# 올림픽 문양 그리기
turtle.pensize(5)
colorIndex2 = 0
colours2 = ['blue', 'black', 'red', 'yellow', 'green']
radius = 20
for i in range(3):
    turtle.pencolor(colours2[colorIndex2])
    turtle.circle(radius)
    turtle.penup()
    turtle.forward(radius+(radius/2)+20)
    turtle.pendown()
    colorIndex2 += 1
turtle.penup()
turtle.right(90)
turtle.forward(20)
turtle.right(90)
turtle.forward(((radius+(radius/2)+20)*4) - (((radius+(radius/2)+20)*4)/3+10))
turtle.pendown()
turtle.right(180)

for i in range(2):
    turtle.pencolor(colours2[colorIndex2])
    turtle.circle(radius)
    turtle.penup()
    turtle.forward(radius+(radius/2)+20)
    turtle.pendown()
    colorIndex2 += 1
turtle.pensize(2)

# 무지개 육각형
colorIndex3 = 0
colours3 = ['red', 'orange', 'yellow', 'green', 'blue', 'purple']
for i in range(40):
    for j in range(6):
        turtle.color(colours3[j])
        turtle.forward(i*5)
        turtle.right(360/6)
        colorIndex3 += 1
        turtle.right(5/6) 
    turtle.penup()
    turtle.right((360/6)*4)
    turtle.forward(5)
    turtle.right((360/6)*2)
    turtle.pendown()

# 체스판 그리기
colorIndex4 = 0
colours4 = ['red', 'green']
colorflag = True
for o in range(6):
    for i in range(6):
        turtle.color(colours4[colorIndex4])
        turtle.begin_fill()
        for j in range(4):
            turtle.forward(200/7)
            turtle.right(90)
        turtle.end_fill()
        colorIndex4 += 1
        if colorIndex4 > 1:
            colorIndex4 = 0
        turtle.forward((200/7))
    turtle.right(90)
    turtle.forward(200/7)
    turtle.right(90)
    turtle.forward(200/7*6)
    turtle.right(180)
    if colorflag == True:
        colorflag = False
        colorIndex4 = 1
    else:
        colorIndex4 = 0
        colorflag = True