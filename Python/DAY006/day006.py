kitsch = "우리 우리만의 자유로운 nineteen's kitsch"

print(kitsch.upper())
print(len(kitsch))
print(kitsch.count("n"))
print("!".join(kitsch))

coke = "   코카콜라 맛있다   "

print(coke)
print(len(coke))

left = coke.lstrip()

print(len(left))

right = coke.rstrip()

print(len(coke))

a = []
b = [63, 57, 40, 17, 9]
c = ['가', '노', '누', '서', '수']
d = [63, 57, 17, '가', '수', '서']
e = [1, 2, ['63가', '57수',[3,4]]]

print(b[0])
print(b[3] + b[1])
print([c[4]])
print(c[0]*3)
print(d[2], d[5])
print(d[0] + d[1])
print(e[2])
print(e[2][0])
print(e[2][1])
print(e[2][2])
print(e[0], e[1], e[2][2][0], e[2][2][1])

list = [1, 2, ['a', 'b', ['오뚜기', '오징어']]]

print(list[2][2][1])

car = ['이', '차는', '이제', '제 겁니다.']
print(car)
print(car[2], car[3])
print(car[2:])
print(car[-2:])
print(car[3])
print(car[-1])

miss =['그립다 그리워']
print(miss*2)
print(miss*4)

num = [1, 2, 3, 4]
print(num)
num[3] = 5
print(num)

a = [1,2,3]
b = [4,5,6]

c = a+b

print(c)

listh = ['홍합', 8]
print(listh[0] * listh[1])

a = ['소', '돼지', '양']
print(a)
a.append('닭')
print(a)
a.append(['닭', '오리'])
print(a)

print(a[0],a[3],a[4][1])
print(a[4][1])
print(a[4][1:])

b = [21, 2, 17, 24, 8]
print(b)
b.sort()
print(b)

c = ['c', 'a', 't', 'd', 'o', 'g']
print(c)
c.sort()
print(c)

d = ['가', '라', '바', '사', '마', '다']
print(d)
d.sort()
print(d)
d.reverse()
print(d)

food = ['pizza', 'chiken', 'burger']
print(food.index('chiken'))
print(food.index('burger'))

food.insert(3, 'salad')
print(food)
print(food.index('salad'))
print(food)
food.insert(0, 'hotdog')
print(food)
food.insert(3, 'pizza')
print(food)
food.remove('salad')
print(food)
food.remove('pizza')
print(food)
food.remove('pizza')
print(food)

animal = ['강아지', '고양이', '고슴도치', '토끼']
print(animal)
print(animal.pop())
print(animal)
print(animal.pop(2))
print(animal)
print(animal.pop(0))
print(animal)

animal.insert(0, '물고기')
animal.insert(3, '강아지')
animal.insert(2, '강아지')
animal.insert(1, '햄스터')
print(animal)

print(animal.count('강아지'))
print(animal.count('고양이'))
print(animal.count('코끼리'))

print(animal)
print(animal.pop())
print(animal)

animal = ['소', '돼지', '양']

print(animal)
animal.extend(['닭', '오리'])
print(animal)
animal.extend(['토끼', '호랑이'])
print(animal)
animal.append(['까마귀', '코끼리'])
print(animal)
animal.append(['다람쥐', '기린'])
print(animal)

a = [1,2,3,4]
b = [5,6,7,8]
c = ['소']
a.extend(b)
print(a)

a.append(b)
print(a)

a.extend(c)
print(a)

#튜플 자료형 (const)
# a = (1,)
# b = (2, 3, 4, 5)
# c = (11, 22, 'a', 'b', 'c')
# d = (33, 44, ('d', 'e', 'f'))
# e = (2,3,4,5,('d','e','f',(4,5,6)))
# print(c[1])
# print(d[2][1])

# print(d[2][1]*b[3])

# print(c[0],c[1],c[2])
# print(c[-5],c[-4],c[-3])
# print(c[0], (c[0]*b[0]), c[-3])
# print(c[0:3])
# print(c[:-2])

# print(d[2][1:])
# print(d[2][1], d[2][2])
# print(d[-1][-2:])
# print(d[-1][-2], d[-1][-1])

# print(e[2]*e[4][3][2])
# print(e[2]*e[4][3][-1])
# print(e[2]*e[-1][-1][-1])

# print(a+b)
# print(b*2)

a = (2,4,8,"그립다 그리워", "왕밤빵", "홍합")
print(a[3]*a[0])
print(a[5]*a[2])
print(a[3]*a[0])
print(a[4]*a[1])
print(len(a))

#딕셔너리 키 : 밸류
pair = {'짜장면' : '탕수육', '떡볶이' : '튀김', '치킨' : '맥주'}

Menu = {'한식': ['된장찌개', '비빔밥', '감자전'], '중식' : ['마라탕', '가지튀김','양꼬치'], '일식' : ['초밥', '스시', '규동']}
print(pair)
pair['양꼬치'] = '칭따오'
print(pair)
pair['햄버거'] = '감자튀김'
print(pair)
pair['맥주'] = '치킨', '칭다오'
print(pair)

del pair['맥주']
print(pair)