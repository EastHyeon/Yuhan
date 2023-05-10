'''
a = [55, 42, 76, 69, 23]

result = []

#출력만 함
for i in a:
    i = i + 20
    print(i)

for i in a:
    result.append(i + 20)
print(result)

for idx, val in enumerate(a):
    a[idx] = val + 20

print(a)


a = range(2, 12)
result = []
for i in a:
    result.append(i*8)

print(result)

a = range(2,12)
result = [i * 8 for i in a]

print(result)

result = [i + 5 for i in range(3,21)]
print(result)

name = input("이름을 입력하세요 : ")
print(name + "님 반갑습니다.")

a = int(input("a값을 입력하세요 : "))
b = int(input("b값을 입력하세요 : "))
print(a+b)

print("-------------------------------------")
print("택배 발송을 위한 정보를 입력하세요.")
print("받는 사람 : ")
print("주소 : ")
print("무게(g) : ")
print("-------------------------------------")

name = input("받는 사람 이름을 입력하세요 : ")
adress = input("주소를 입력하세요 : ")
weight = int(input("무게를 입력하세요 : "))

print("-------------------------------------")
print("받는 사람 :", name)
print("주소 :", adress)
print("배송비 :", int(weight * 500 / 100))
print("-------------------------------------")

hello, world = input("Hello World").split()

print(hello)
print(world)

a, b = input("두개의 숫자를 입력하세요 : ").split(',')
a = int(a)
b = int(b)

print("두 값을 더하면", a+b, "입니다.")

a,b = input("주민번호를 입력하세요 : ").split('-')
print(a)
print(b)

year = int(a[0:2])
age = 0

if b[0] == "1" or b[0] == "3":
    print("당신은 남자군요")
    year = yaer + 1900
elif b[0] == "2" or b[0] == "4":
    print("당신은 여자군요")
    year = year + 2000

age = 2022 - year + 1
print("당신의 나이는", age, "세입니다.")

name = input("이름을 입력하세요 : ")
a = input("주민번호 앞자리를 입력하세요 : ")
b = input("주민번호 뒷자리를 입력하세요 : ")
targetyear = int(input("계산할 연도를 입력해주세요 : "))
print("-----------------------------------------------")

age = 0

year = int(a[0:2])

if b[0] == "1" or b[0] == "3":
    gender = "남자"
elif b[0] == "2" or b[0] == "4":
    gender = "여자" 

if b[0] == "1" or b[0] == "2":
    year = year + 1900
elif b[0] == "3" or b[0] == "4":
    year = year + 2000

age = 2023 - year + 1

print(name+"님 안녕하세요!")
print("당신은 "+gender+"이고,")
print("현재 나이는 "+str(age)+"세 입니다.")
print(str(targetyear)+"년에는 "+str(targetyear - year + 1)+"세가 됩니다." )
'''

import turtle
import time
'''
turtle.shape('turtle')
turtle.forward(100)
turtle.left(90)
turtle.forward(100)
'''
'''
turtle.shape('turtle')
i = 0
while i < 4:
    i += 1
    turtle.forward(100)
    turtle.left(90)
'''
'''
turtle.shape('turtle')
turtle.pensize(10)
turtle.pencolor('skyblue')
turtle.fillcolor('green')
turtle.begin_fill()
for i in range(6):
    turtle.forward(100)
    turtle.left(360/6)
turtle.end_fill()
time.sleep(10)
'''
'''
turtle.speed(0)
turtle.bgcolor('black')
for i in range(3) :
    for colours in ["red", "magenta", "blue", "cyan", "green", "white"]:
        turtle.color(colours)
        turtle.pensize(2)
        turtle.circle(100)
        turtle.forward(15)
'''
turtle.speed(0)

turtle.fillcolor('yellow')
turtle.begin_fill()
for i in range(5):
    turtle.forward(100)
    turtle.left(144)
turtle.end_fill()

turtle.fillcolor('orange')
turtle.begin_fill()
for i in range(6):
    turtle.forward(100)
    turtle.left(360/6)
turtle.end_fill()


width = 6
for i in range(10):
    for j in range(4):
        turtle.forward(width)
        turtle.left(360/4)
    width += 6

a = int(360/20)
colours = ['red', 'blue', 'yellow','cyan']
j = 0
for i in range(a):
    turtle.color(colours[j])
    turtle.circle(50)
    turtle.right(20)
    j = j + 1
    if j > 3:
        j = 0