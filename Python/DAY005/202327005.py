print("{0}는 지구에서 {1}년 전에 멸종했다.".format("매머드", 4000))
name = "매머드"
year = 4000
print("{0}는 지구에서 {1}년 전에 멸종했다".format(name, year))
print("{name}는 지구에서 {year}년 전에 멸종했다.".format(name = "매머드", year = 4000))
print("{name}는 지구에서 %d년 전에 멸종했다.".format(name = "매머드") %(4000))
print("{0}는 {1}에서 {ago}년 전에 멸종했다.".format("매머드", "지구", ago=4000))

print("{0:<20}!".format("좌측정렬"))
print("{0:>20}!".format("우측정렬"))
print("{0:^20}!".format("중앙정렬"))

print("{0:!<20}".format("좌측공백채우기"))
print("{0:!>20}".format("우측공백채우기"))

print("{0:=^25}".format("안녕하세요"))
print("{0:>20}".format("앞의 공백은 다섯 칸입니다."))
print("{0:!^23}".format("우리 존재 파이팅"))

py = 3.141592

print("{0}".format(3.141592))
print("{0:f}".format(3.141592))

print("{0:0.2f}".format(3.141592))
print("{0:8.2f}".format(3.141592))
print("{0:8.3f}".format(3.141592))

py = 3.141592
print("0:12.2f".format(py))
k = 0.2525
print("{0}".format(k))
print("{0:6.2f}".format(k))
print("{0:6.1f}".format(k))

a = "oh my, oh my god 예상했어 나"
print(len(a))
print(a.count('o'))
print(a.count('m'))
c = "1234"
d = "5678"
print(c+d)
print(c)

print(",".join(c))

e = "calientacabezas"

print(len(e))
print(e.upper())

f = e.upper()

print(f)
print(f.lower())

print(e.count("a"))

monday = "   월요일 좋아   "
print(monday.lstrip())
print(monday.rstrip())
print(monday.strip())

print(monday.replace("월", "화"))
print(monday.replace("좋아", "싫어"))
print(len(monday))
print(monday.count("요"))

good = "월요일 좋아 화요일 좋아"
print(len(good))
print(good.split())
print(":".join(good))
print(good.count("요"))