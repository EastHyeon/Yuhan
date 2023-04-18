lunch = ['맵고', '안 맵고', ['따듯한','차가운',['빵','밥','면','떡']]]
print(lunch[2][2])
print(lunch[0], lunch[2][0], lunch[2][2][2])
lunch[2][1] = '시원한'
print(lunch)
del lunch[2][2][3]
print(lunch)
print(lunch[0], lunch[2][0], lunch[2][2][2])

menu = ['한식', '양식', '중식', '일식']
print(menu.index('양식'))
menu.insert(3, '태국식')
print(menu)
menu.sort()
print(menu)
menu.pop()
print(menu)

aespa = ('next', 'level', ('제껴라', ('la', 'ha', (2,3,6))))

print(aespa[0], aespa[1])
print(aespa[2][0]*aespa[2][1][2][1])
print(aespa[2][1][0]*aespa[2][1][2][2], aespa[2][1][1]*aespa[2][1][2][0])
print(aespa[2][1][0]*aespa[2][1][2][2])
print(aespa[2][1][0]*aespa[2][1][2][2])

a = set(['hello'])
b = set([1, 2, 3])
print(a)
print(b)
a.add('world')
b.update([4,5,6])
print(a)
print(b)
b.remove(6)
print(b)

a = set(['짜파게티', '짜파구리', '너구리'])
b = set(['신라면', '너구리', '진라면'])

print(a&b)
print(a|b)

a = True
b = False
c = 'abc'
d = 123
e = [1,2,3]
f = (1,2,3)
print(type(a))
print(type(b))
print(type(c))
print(type(d))
print(type(e))
print(type(f))

print(bool(1==1))
print(bool(2<1))
print(bool(2+3<4))
print(bool('월요일 좋아'))
print(bool(' '))
print(bool())
print(bool(0))

isHungry = 0

if isHungry:
    print("배고파")
else:
    print("안배고파")

subscriber = 1250000
print("구독자 수는", subscriber, "입니다")

if subscriber >= 1000000:
    print("골드버튼 받음 야호")
else:
    print("그런거 없음")

height = 130

if height >= 130:
    print("입장하세요.")
else:
    print("내년에 오세요.")

worldcup = "입장하세요." if height >= 130 else "입장할 수 없습니다."
print(worldcup)
goldbutton = "골드을 버튼을 신청하세요." if subscriber >= 1000000 else "구독자 수가 부족합니다."
print(goldbutton)

msg = "구독자 수가 부족합니다."
if subscriber >= 1000000:
    msg = "골드버튼을 신청하세요"
elif subscriber >= 100000:
    msg = "실버버튼을 신청하세요"    

print(msg)

score = 80

if score >= 95:
    print("A+")
elif score >= 90:
    printf("A")
elif score >= 80:
    print("B")
elif score >= 60:
    print("C")
else:
    print("F")

avocado = True
cart = ["milk"]

if avocado :
    cart.extend(["abocado"]*6)

print(cart)

a = 0

while a <= 10 :
    print(a)
    a = a + 1


currentSubscriber = 990000


# while currentSubscriber <= 1000000 :
#     print(currentSubscriber)
#     currentSubscriber = currentSubscriber + 1

hole = 0
cup = ['flag']

while hole <= 18 :
    if 'ball' in cup :
        hole = hole + 1
        print(hole, "홀 입니다.")
    else :
        cup.append("ball")

menu = ["한식", "양식", "중식", "일식"]

for food in menu:
    print(food)

a = 2
num = [1, 2, 3, 4, 5, 6, 7, 8, 9]

for i in num:
    print(a, "x", i, "=", a*i)

result = 0
for i in range(1, 600):
    result = result + i
    print(result)

for i in range(2,10):
    for j in range(1, 10):
        print(i, "x", j, "=", j * i)

# -여기까지 시험범위
# 다음주 화요일 시험 (필기)