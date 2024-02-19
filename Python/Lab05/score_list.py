list=[]

while True:
    score=input('숫자를 입력해주세요. 종료=[Enter] : ')
    if score=="":
        break
    else: list.append(int(score))

if list==[]:
    print('숫자가 존재하지 않습니다.')
else:
    list.sort(reverse=False)
    if len(list)%2==0: 
        mid=(list[len(list)//2]+list[len(list)//2-1])/2
    else: 
        mid=list[len(list)//2]

    print(list)
    print('최대값:',list[len(list)-1])
    print('최소값:',list[0])
    print('중간값:',mid)
