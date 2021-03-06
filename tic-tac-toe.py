import re
def board(row1,row2,row3):
    print(row1[0],'|',row1[1],'|',row1[2])
    print('---------')
    print(row2[0],'|',row2[1],'|',row2[2])
    print('---------')
    print(row3[0],'|',row3[1],'|',row3[2])

def input_to_row(integer, str1):
    global r1,r2,r3

    if integer in range(1,4):
        r1[integer-1]=str1
    elif integer in range(4,7):
        r2[integer-4]=str1
    else:
        r3[integer-7]=str1

def who_won(row1,row2,row3):
    global dic
    key_list = list(dic.keys())
    val_list = list(dic.values())
    #check rows
    if row1 == ['O']*3 or row1 == ['X']*3:
        position = val_list.index(row1[0])
        print('Congrats ',key_list[position],' Won!!')
        return True
    elif row2 == ['O']*3 or row2 == ['X']*3:
        position = val_list.index(row2[0])
        print('Congrats ',key_list[position],' Won!!')
        return True
    elif row3 == ['O']*3 or row3 == ['X']*3:
        position = val_list.index(row3[0])
        print('Congrats ',key_list[position],' Won!!')
        return True
    #check columns
    for i in range(0,3):
        if row1[i] == row2[i] == row3[i]:
            position = val_list.index(row2[i])
            print('Congrats ',key_list[position],' Won!!')
            return True
    #check diagonals
    if row1[0]==row2[1]==row3[2]:
        position = val_list.index(row2[1])
        print('Congrats ',key_list[position],' Won!!')
        return True
    elif row1[2]==row2[1]==row3[0]:
        position = val_list.index(row2[1])
        print('Congrats ',key_list[position],' Won!!')
        return True
    else:
        return False
    

r1 = ['1','2','3']
r2 = ['4','5','6']
r3 = ['7','8','9']

board(r1,r2,r3)
print("""\n RULES FOR TIC-TAC-TOE

1. The game is played on a grid that's 3 squares by 3 squares.

2. You are alphabet X, your friend is alphabet O. Players take turns putting their marks in empty squares.

3. Input the number where you want to put your mark.

4. The first player to get 3 of their marks in a row (up, down, across, or diagonally) is the winner.

5. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.""")
x = 0
name_check = 1
num_format = re.compile(r'^\-?[1-9][0-9]*$')
playerA = str(input('Enter your name playerA: ')).capitalize()
playerB = str(input('Enter your name playerB: ')).capitalize()
if playerB == playerA:
    name_check =0
while name_check ==0:
    playerB = str(input('PlayerA already chose that name, choose another name playerB: ')).capitalize()
    if playerA != playerB:
        name_check = 1
while x==0:
    userA = str(input(f'{playerA} choose between X or O: ')).capitalize()
    if userA=='X' or userA=='O':
        x=1
if userA == 'X':
    userB = 'O'
else:
    userB = 'X'
print(f'{playerA} is',userA)
print(f'{playerB} is',userB)
dic = {playerA: userA,playerB: userB}
a = 1
b = 0
defined_set = set(range(1,10))
check_set = set()
while defined_set!=check_set:
    if a==1:
        choice = input(f'Enter your choice {playerA}: ')
        it_is = re.match(num_format,choice)
        if not it_is:
            print('You must put in a number!!')
        elif int(choice) not in range(1,10):
            print('Wrong choice')
        elif int(choice) in check_set:
            print(f'Cell already chosen by {playerB}')
        else:
            choice = int(choice)
            check_set.add(choice)
            input_to_row(choice, userA)
            board(r1,r2,r3)
            if who_won(r1,r2,r3):
                x = 0
                break
            a=0
            b=1
    else:
        choice = input(f'Enter your choice {playerB}: ')
        it_is = re.match(num_format,choice)
        if not it_is:
            print('You must put in a number!!')
        elif int(choice) not in range(1,10):
            print('Wrong choice')
        elif int(choice) in check_set:
            print(f'Cell already chosen by {playerA}')
        else:
            choice = int(choice)
            check_set.add(choice)
            input_to_row(choice, userB)
            board(r1,r2,r3)
            if who_won(r1,r2,r3):
                x = 0
                break
            a=1
            b=0
if x != 0:
    print('The match ended in a tie!!')