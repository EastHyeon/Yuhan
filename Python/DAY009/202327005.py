'''
tall = 129
if tall >= 130 :
    worldcup = "입장하세요"
else :
    worldcup = "입장 불가능 하세요."
print(worldcup)
    
subscriber = 1000000
if subscriber >= 1000000 :
    reward = "골드버튼"
elif subscriber >= 100000 :
    reward = "실버버튼"
else :
    reward = "받을 수 있는 버튼이 없습니다."
print(reward)

a = 0
while ( a <= 10 ) :
    print(a)
    a = a + 1
    
subscriber = 990000
while subscriber <= 1000000 :
    print(subscriber)
    subscriber = subscriber + 1

sum = 0
num = 0
while sum < 600 :
    sum = sum + 1
    num = num + sum
    print(sum, num)
'''
    
menu = ['한식', '양식', '중식', '일식']
for food in menu : 
    print(food)

for a in range(2, 10) :
    for y in range(1, 10) :
        print(a, "x", y, "=", a * y)
    
result = 0    
for i in range(1, 600) : 
    result += i
    # result = result + i
print(result)