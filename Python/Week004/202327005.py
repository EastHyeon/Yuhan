'''
a = "사랑을 했다. 우리가 만나"

print("1. " + a[:2])
print("2. " + a[:6])
print("3. " + a[8:10])
print("4. " + a[12:])
print("5. " + a[6])

y = 2023
m = 3
d = 28
temp = 15.2
blossom = "벚꽃"
seoul = "서울 3월"
busan = "부산 3월"
ganleung = "강릉 3월"
jeju = "제주 3월"

print("오늘은 %d년 %d월 %d일입니다." %(y, m, d))
print("낮 기온은 %0.1f도이고 하늘은 흐립니다." %temp)
print("%s의 개화시기는 다음과 같습니다." %blossom)
print("%s 28일" %seoul)
print("%s 24일" %busan)
print("%s 31일" %ganleung)
print("%s 20일" %jeju)
'''

a = "2023328"
b = 15.2
c = "벚꽃"
d = "서울부산강릉제주"
e = "3월 "

print("오늘은 %s년 %s월 %s일입니다." %(a[:4], a[4:5], a[5:]))
print("낮 기온은 %0.1f도이고 하늘은 흐립니다." %b)
print("%s의 개화시기는 다음과 같습니다." %c)
print("%s %s28일" %(d[:2], e))
print("%s %s24일" %(d[2:4], e))
print("%s %s31일" %(d[4:6], e))
print("%s %s20일" %(d[6:], e))

food = "과자"
piece = 5

print("나는 피자를 {0}조각 먹을 수 있어".format(2))
print("나는 피자를 %c조각 먹을 수 있어" %"두")
print("나는 피자를 {0}조각 먹을 수 있어".format("두"))
print("나는 피자를 {0}조각 먹을 수 있어".format(piece))
print("나는 {0}를 {1}조각 먹을 수 있어".format("피자", piece))
print("나는 {0}를 {1}조각 먹을 수 있어".format(food, piece))
print("나는 {food}를 {piece}조각 먹을 수 있어".format(food="과자", piece="20"))
print("나는 {0}를 {piece}조각 먹을 수 있어".format("과자", piece="20"))

earth = "지구"
moon = "달"
length = 384000

print("{0}와 {1} 사이의 거리는 평균 {2}km입니다.".format("지구", "달", 384000))
print("{0}와 {1} 사이의 거리는 평균 {2}km입니다.".format(earth, moon, length))
print("{earth}와 {moon} 사이의 거리는 평균 {length}km입니다.".format(earth = "지구", moon = "달", length = 384000))
print("{0}와 {moon} 사이의 거리는 평균 {length}km입니다.".format("지구", moon = "달", length = 384000))

a = "2023328"
b = 15.2
c = "벚꽃"
d = "서울부산강릉제주"
e = "3월 "

print("오늘은 {0}년 {1}월 {2}일입니다.".format(a[:4], a[4:5], a[5:]))
print("낮 기온은 {0}도이고 하늘은 흐립니다.".format(b))
print("{0}의 개화시기는 다음과 같습니다.".format(c))
print("{0} {1}28일".format(d[:2], e))
print("{0} {1}24일".format(d[2:4], e))
print("{0} {1}31일".format(d[4:6], e))
print("{0} {1}20일".format(d[6:], e))

print("%10s!"%"어서와")
print("{0:<10}!".format("어서와"))
print("{0:>10}!".format("어서와"))
print("{0:!<20}".format("어서와"))
print("{0:-^19}".format("어서와"))

print("{0:=^19}".format("안녕하세요"))
print("제 이름은 {name}입니다.".format(name="김동현"))
print("{0:>21}".format("학번은 %d입니다."%202327005))
print("{0:>21}".format("반갑습니다."))