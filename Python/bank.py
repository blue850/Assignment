class Account:
    acclist={} #ex.1234:파이썬 

    def __init__(self,name,number,balance):
        self.__name=name
        self.__number=number
        self.__balance=balance
        self.__history=[]
        self.__history.append(('신규',self.__balance,self.__balance))
        Account.acclist[number]=self

    def print(name):
        print('계좌번호 : %d , 소유자 : %s , 잔액 = %d'%(name.__number,name.__name,name.__balance)) 
    
    def deposit(name,amount):
        name.__balance+=int(amount)
        name.__history.append(("입금",amount,name.__balance))

    def withdraw(self):
        number=int(input('계좌 번호를 입력하세요 : '))
        if (number in Account.acclist) == True:
                amount=int(input('출금하실 금액을 입력하세요 : '))
                if amount<=self.__balance:
                    self.__balance-=amount
                    self.__history.append(('출금',amount,self.__balance))
                    print('%d원이 출금되었습니다.'%amount)
        else: print('해당 계좌가 없습니다')

    def history(self):
        print('계좌번호 : %d , 소유자 : %s'%(self.__number,self.__name))
        for x in range(len(self.__history)):
            print(self.__history[x][0],'%10s'%self.__history[x][1],'원','\t잔액','%10s'%self.__history[x][2],'원')

 
menu="""========================
   SOOKMYUNG BANK ATM   
========================
1. 신규 계좌 생성
2. 잔액 조회
3. 입금
4. 출금
5. 거래 내역 조회
6. 종료
------------------------
선택 : """

while True:
    select=int(input(menu))

    if select==1: #신규계좌생성
        name=str(input('계좌 소유자 이름을 입력하세요: '))
        name1=name
        while True:
            number=int(input('생성할 계좌 번호를 입력하세요: '))
            if number in Account.acclist: 
                print('생성할 수 없는 계좌 번호입니다. 다시 입력하세요.')
            else: break
        amount=int(input('입금할 금액을 입력하세요 : '))
        name=Account(name,number,amount)
        print('\n[ 생성된 계좌 정보 ]\n계좌번호 : %d, 소유자: %s, 잔액 = %d'%(number,name1,amount))

    elif select==2: #잔액조회
        number=int(input('계좌 번호를 입력하세요 : '))
        if (number in Account.acclist) == True:
            Account.print(Account.acclist[number])
        else: print('해당 계좌가 없습니다')
        
    elif select==3: #입금
        number=int(input('계좌 번호를 입력하세요 : '))
        if (number in Account.acclist) == True:
            amount=int(input('입금하실 금액을 입력하세요 : '))
            Account.deposit(Account.acclist[number],amount)
            print('%d원이 입금되었습니다.'%amount)
        else: print('해당 계좌가 없습니다')

    elif select==4: #출금
        Account.withdraw(Account.acclist[number])
           
    elif select==5: #거래내역조회
        number=int(input('계좌 번호를 입력하세요 : '))
        if (number in Account.acclist) == True:
            Account.history(Account.acclist[number])
        else: print('해당 계좌가 없습니다')
        
    else: break