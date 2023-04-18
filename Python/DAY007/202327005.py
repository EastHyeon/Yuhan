lunch = ['맵고', '안 맵고', ['따듯한','차가운',['빵','밥','면','떡']]]
print(lunch[2][2])
print(lunch[0], lunch[2][0], lunch[2][2][2])
lunch[2][1] = '시원한'
print(lunch)
del lunch[2][2][3]
print(lunch)
print(lunch[0], lunch[2][0], lunch[2][2][2])