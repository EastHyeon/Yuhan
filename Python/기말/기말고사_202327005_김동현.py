import csv
import turtle
import tkinter as tk

#문제 1
print("202327005 김동현")

#문제 2
height = int(input("당신의 키를 입력하세요."))

if height >= 130:
    print("입장 가능합니다.")
else:
    print("입장할 수 없습니다.")

#문제 3
frame = 1
while frame <= 10:
    print("현재 위치는 {0} 프레임, 1번째 공입니다.".format(frame))
    print("현재 위치는 {0} 프레임, 2번째 공입니다.".format(frame))
    frame = frame + 1

#문제 4
num = int(input("정수를 입력하세요: "))
for i in range(1, 10):
    print("{0}*{1} = {2}".format(num, i, i*num))

#문제 5

f = open('vegetable.csv', 'w', newline='')
wr = csv.writer(f)
wr.writerow(['당근', 400])
wr.writerow(['고구마', 550])
wr.writerow(['감자', 500])
wr.writerow(['양파', 250])
f.close()

f = open('vegetable.csv', 'r')
rdr = csv.reader(f)

name = input("채소의 이름을 입력하세요. ")
weight = int(input("채소의 무게를 입력하세요. "))

for line in rdr:
    if line[0] == name:
        print("{0}의 100그램당 가격은 {1}원이고,".format(line[0], line[1]))
        print("총 무게는 {0}그램으로 {1}원 입니다.".format(weight, int(int(line[1]) / 100 * weight)))
f.close()

#문제 6
#red & green 체스판
turtle.penup()
turtle.goto(-400, 0)
turtle.pendown()
turtle.speed(0)
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


# 노란 스마일
turtle.penup()
turtle.goto(-100, -170)
turtle.pendown()
turtle.color('yellow')
turtle.begin_fill()
turtle.circle(90)
turtle.end_fill()
turtle.penup()
turtle.color('black')

turtle.left(90)
turtle.forward(110)
turtle.left(90)
turtle.forward(35)
turtle.pendown()
turtle.begin_fill()
turtle.circle(10)
turtle.end_fill()
turtle.penup()
turtle.left(90)
turtle.forward(20)
turtle.left(90)
turtle.forward(35 * 2)
turtle.pendown()
turtle.begin_fill()
turtle.circle(10)
turtle.end_fill()

turtle.penup()
turtle.right(70)
turtle.forward(30)
turtle.right(30)
turtle.pendown()
turtle.pensize(10)

turtle.right(30)

turtle.circle(-60, 100)

# 무지개 6각형 스파이럴
turtle.penup()
turtle.goto(100, -80)
turtle.pendown()

turtle.pensize(1)

colorIndex3 = 0
colours3 = ['red', 'orange', 'yellow', 'green', 'blue', 'purple']
for i in range(20):
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

# 보노보노 얼굴
bonobono = turtle.Turtle()

bonobono.pensize(2)

bonobono.speed(0)

bonobono.penup()
bonobono.goto(0, -100)
bonobono.pendown()
bonobono.color("black")
bonobono.begin_fill()
bonobono.circle(100)
bonobono.color("skyblue")
bonobono.end_fill()

bonobono.color("black")
bonobono.penup()
bonobono.goto(-60, 20)
bonobono.pendown()
bonobono.begin_fill()
bonobono.circle(5)
bonobono.end_fill()

bonobono.penup()
bonobono.goto(60, 20)
bonobono.pendown()
bonobono.begin_fill()
bonobono.circle(5)
bonobono.end_fill()

bonobono.penup()
bonobono.goto(10, -10)
bonobono.pendown()
bonobono.color("black")
bonobono.begin_fill()
bonobono.left(360)
for i in range(2):
    bonobono.circle(-30, 90)
    bonobono.circle(-20, 90)
bonobono.color("white")
bonobono.end_fill()

bonobono.penup()
bonobono.goto(-10, -10)
bonobono.pendown()
bonobono.color("black")
bonobono.begin_fill()
bonobono.left(180)
for i in range(2):
    bonobono.circle(30, 90)
    bonobono.circle(20, 90)
bonobono.color("white")
bonobono.end_fill()

bonobono.penup()
bonobono.goto(0, -4)
bonobono.pendown()
bonobono.color("black")
bonobono.begin_fill()
bonobono.circle(13)
bonobono.end_fill()

bonobono.speed(1)

bonobono.penup()
bonobono.goto(-25, -22)
bonobono.pendown()
bonobono.color("black")
bonobono.setheading(180 - 20)
bonobono.forward(50)

bonobono.penup()
bonobono.goto(-30, -32)
bonobono.pendown()
bonobono.color("black")
bonobono.setheading(180)
bonobono.forward(50)

bonobono.penup()
bonobono.goto(-25, -42)
bonobono.pendown()
bonobono.color("black")
bonobono.setheading(180 + 20)
bonobono.forward(50)

bonobono.penup()
bonobono.goto(25, -22)
bonobono.pendown()
bonobono.color("black")
bonobono.setheading(360+20)
bonobono.forward(50)

bonobono.penup()
bonobono.goto(30, -32)
bonobono.pendown()
bonobono.color("black")
bonobono.setheading(0)
bonobono.forward(50)

bonobono.penup()
bonobono.goto(25, -42)
bonobono.pendown()
bonobono.color("black")
bonobono.setheading(360-20)
bonobono.forward(50)

# 문제 7
def turtledraw(n = 4, color = "blue", size = 100):
    turtle.pendown()
    turtle.color(color)
    turtle.begin_fill()
    for i in range(0, n):
        turtle.forward(size)
        turtle.left(360 / n)
    turtle.end_fill()
turtledraw()
turtledraw(6, "black", 100)

# 문제 8
def primenum(start, end):
    primes = []
    count = 0

    for num in range(start, end + 1):
        if num > 1:
            for i in range(2, int(num ** 0.5) + 1):
                if num % i == 0:
                    break
            else:
                primes.append(num)
                count += 1

    print(f"{start}부터 {end}사이의 소수는 총 {count}개이며, 그 숫자는 다음과 같습니다:")
    for i in range(0, count):
        if(i >= count - 1):
            print("{0} ".format(primes[i]), end='')
        else:
            print("{0}, ".format(primes[i]), end='')
primenum(1, 20)


# 문제 9
filename = 'pythondata.csv'

total_count = 0
male_count = 0
female_count = 0
time_votes = {}
snack_votes = {}
kim_count = 0

file = open(filename, 'r')
reader = csv.reader(file)

next(reader)

for row in reader:
    name = row[0]
    gender = row[2]
    time = row[3]
    snack = row[5]

    total_count += 1
    if gender == '남자':
        male_count += 1
    else:
        female_count += 1

    if time in time_votes:
        time_votes[time] += 1
    else:
        time_votes[time] = 1

    if snack in snack_votes:
        snack_votes[snack] += 1
    else:
        snack_votes[snack] = 1

    if '김' in name[0]:
        kim_count += 1

file.close()

print("총 인원:", total_count)
print("남자 수:", male_count)
print("여자 수:", female_count)

max_time_votes = max(time_votes.values())
most_voted_time = [time for time, count in time_votes.items() if count == max_time_votes]
print("가장 많은 사람이 투표한 '등교에 걸리는 시간':", most_voted_time)

max_snack_votes = max(snack_votes.values())
most_voted_snack = [snack for snack, count in snack_votes.items() if count == max_snack_votes]
print("학생들이 가장 좋아하는 과자의 이름:", most_voted_snack)

print("김씨 인원 수:", kim_count)

# 문제 10

def draw_shape():
    num_sides = int(num_sides_entry.get())
    color = color_entry.get()
    size = int(size_entry.get())

    x = int(x_entry.get())
    y = int(y_entry.get())
    pen_size = int(pen_size_entry.get())

    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()

    turtle.pensize(pen_size)

    turtle.begin_fill()
    turtle.fillcolor(color)

    for _ in range(num_sides):
        turtle.forward(size)
        turtle.right(360 / num_sides)

    turtle.end_fill()

    turtle.done()

window = tk.Tk()
window.title("도형 그리기")

num_sides_label = tk.Label(window, text="몇 각형을 그릴까요?")
num_sides_label.pack()
num_sides_entry = tk.Entry(window)
num_sides_entry.pack()

color_label = tk.Label(window, text="무슨 색을 채울까요?")
color_label.pack()
color_entry = tk.Entry(window)
color_entry.pack()

size_label = tk.Label(window, text="크기를 입력하세요.")
size_label.pack()
size_entry = tk.Entry(window)
size_entry.pack()

x_label = tk.Label(window, text="x 좌표를 입력하세요.")
x_label.pack()
x_entry = tk.Entry(window)
x_entry.pack()

y_label = tk.Label(window, text="y 좌표를 입력하세요.")
y_label.pack()
y_entry = tk.Entry(window)
y_entry.pack()

pen_size_label = tk.Label(window, text="펜 사이즈를 입력하세요.")
pen_size_label.pack()
pen_size_entry = tk.Entry(window)
pen_size_entry.pack()

draw_button = tk.Button(window, text="그리기", command=draw_shape)
draw_button.pack()

window.mainloop()