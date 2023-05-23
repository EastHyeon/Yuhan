'''

def print_hello(name):

    print("소환사의 협곡에 오신 것을 환영합니다.")

    print(name + "님 어서오세요.")

    print("30초 후, 전투가 시작됩니다.")

    print("미니언 생성까지 30초 남았습니다.")


name = input("사용자 이름을 입력하세요: ")

print_hello(name)


def gugu(num):

    for i in range(1, 9):

        print(num, "x", i, "=", int(num) * i)


num = input("숫자를 입력하세요: ")


def get_sum(start, end):

    sum = 0

    for i in range(start, end+1):

        sum += i

    print(start,"부터",end,"의 합계는",sum)


get_sum(19, 100)



def get_tier(name, ranking):
    if(ranking <= 300):
        print("챌린저")
    elif (300 < ranking <= 1700):
        print("그랜드마스터")
    elif (1700 < ranking <= 3600):
        print("마스터")
    elif (3600 < ranking <= 134000):
        print("다이아몬드")
    elif (134000 < ranking <= 670000):
        print("플래티넘")
    elif (670000 < ranking <= 1840000):
        print("골드")
    elif (1840000 < ranking <= 3030000):
        print("실버")
    elif (3030000 < ranking <= 3600000):
        print("브론즈")
    else:
        print("아이언")

name = input("이름을 입력하세요: ")
ranking = int(input("순위를 입력하세요: "))
get_tier(name, ranking)

def judge(num):
    if num % 2 == 0:
        print("이것은 짝수")
        return
    print("이것은 홀수")

num = int(input("정수를 입력하세요"))
judge(num)

import turtle

value = int(input("길이를 입력하세요: "))

t = turtle.Turtle()
t.shape("turtle")

def draw_square(distance):
    for i in range(0, 4):
        turtle.forward(distance)
        turtle.right(90)

draw_square(value)

def add(num1, num2):
    return num1 + num2

print(add(1, 2))


calorie = 0
def calculrate_calories(w, t):
    global calorie
    calorie = int(w * t * 0.14)
    return calorie

weight = int(input("체중을 입력하세요: "))
run_time = int(input("달리기 시간을 입력하세요(분): "))
print("소모한 칼로리는", str(calculrate_calories(weight, run_time))+"kal 입니다.")

print(calorie)
'''

w = int(input("체중을 입력하세요: "))
h = int(input("키를 입력하세요.: "))

def calculrate_bmi(weight, height):
    global bmi
    bmi = weight / height / height * 10000
    if(25 <= bmi):
        print("당신의 BMI는 {:.1f}이고, 비만입니다".format(bmi))
    elif(23 <= bmi < 25):
        print("당신의 BMI는 {:.1f}이고, 과체중입니다".format(bmi))
    elif(18.5 <= bmi < 23):
        print("당신의 BMI는 {:.1f}이고, 정상체중입니다".format(bmi))
    else:
        print("당신의 BMI는 {:.1f}이고, 저체중입니다".format(bmi))

calculrate_bmi(w, h)
print(bmi)
