'''
print ("ㅋ"*5)
print ("ㅋㅋㅋㅋㅋ")

a = "PEN "
b = "PINEAPPLE "
c = "APPLE "
msg = a+b+c+a
print(msg)
print(len(a+b+c+a))

a = "가나다라마바사 아자차카타파하\n"
c = "오디오 기러기 토마토 스위스\n"
d = "액자 속의 사진 속의\n그 "
f = "홍합 "
g = "왕밤빵 "

print (a*2+c*2+"\n"+d+f*8+"\n"+d+g*8)

a = "Life is too short, You need python"

print(a)
print(a[12])
print(a[11])
print(a[19] + a[20] + a[21])
print(a[28]+a[29]+a[30]+a[31]+a[32]+a[33])
print(a[-6]+a[-5]+a[-4]+a[-3]+a[-2]+a[-1])
print(a[19:22])
print(a[23:27])

#28 이후 출력
print(a[28:]) 

#~17까지 출력
print(a[:17])

#too short
print(a[8:17])

print(a[-11:])
print(a[23:])

date = "20230321화요일"
print(date[:8])
print(date[8:])
print("yaer : " + date[0:4] + "\n" + "month : " + date[4:6] + "\n" + "day : " + date[6:8] + "\n" + "weather : " + date[8:112])
print("temp : 7.2")

grade = 2
print("나는 %d학년입니다"%grade)
print("나는 %s학년입니다."%"이")

grade = 1
print("나는 %d학년 입니다."%grade)
num = 202327005
a = "학번은"
b = "입니다"
print("%s %d%s."%(a, num, b))
'''

grade = 2
score = 3.8
percent = 20

print("나는 %d학년 입니다."%grade)
print("나는 %d학년입니다.\n%c년 학점은 %s입니다."%(grade,"작",score))
print("성적은 상위%d%%입니다."%percent)

name = "김동현"
min  = 70
metro = "지하철"

print("내 이름은 %s입니다.\n집에서 학교까지는 %d분 걸립니다.\n%d분 동안 %s을 타고 옵니다."%(name, min, min, metro))

print("%12s"%"안녕")

pi = 3.141592

print("%.2f"%pi)
print("%f"%pi)
print("%9.2f"%pi)