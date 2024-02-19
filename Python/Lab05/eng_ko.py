def print_menu():
    print('========영한사전========')
    print('1. 단어 추가')
    print('2. 단어 조회/수정')
    print('3. 단어 삭제')
    print('4. 전체 단어 출력')
    print('5. 종료')
    print('========================')

def add_words(list):
    print()
    while True:
        word=input('단어를 입력하세요. 종료=[Enter] : ')
        if word=="":
            break
        else: 
            if (word in list)==True:
                print('이미 존재하는 단어입니다')
            else:  
                mean=input('뜻을 입력하세요: ')
                list[word]=mean

def correct_words(list):
    print()
    word=input('조회할 단어를 입력하세요. 종료=[Enter] : ')
    if (word in list)==False:
        print(word,'은(는) 사전에 존재하지 않습니다.')
    else:
        print('단어 :',word)
        print('뜻:',list[word])
        while True:
            correct=input('수정하시겠습니까(y/n) : ')
            if correct=='y':
                print('단어:',word)
                mean=input('뜻: ')
                list[word]=mean
                print('수정되었습니다')
                break
            elif correct=='n':
                break
            else:
                print('잘못된 입력입니다.')

def delete_words(list):
    print()
    word=input('삭제할 단어를 입력하세요. 종료=[Enter] : ')
    if (word in list)==False: 
        print(word,'은(는) 사전에 존재하지 않습니다.')
    else:
        del list[word]
        print(word,'가 삭제되었습니다.')

def print_words():
    print()
    for word in list:
        print('%-15s'%word,list[word])

list={}
print_menu()
while True:
    menu=int(input('선택 : '))
    if menu==1:
        add_words(list)
    elif menu==2:
        correct_words(list)
    elif menu==3:
        delete_words(list)
    elif menu==4:
        print_words()
    elif menu==5:
        print('프로그램을 종료합니다.')
        break
    else:
        print('메뉴를 다시 선택해주세요.')
    print_menu()
