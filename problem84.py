import random

Rolls = 1000000
GO = 0
JAIL = 10
G2J = 30
ALL = 40

stats = [0] * 40

CC = [2, 17, 33]
CC_ptr = 0
CC_jump = [0, 10]

CH = [7, 22, 36]
CH_ptr = 0
CH_jump = [0, 10, 11, 24, 39, 5]

Card = 16

pos = GO

DICE = 4

def chance():
    global CH_ptr
    global pos
    if CH_ptr < 6:
        pos = CH_jump[CH_ptr]
    elif CH_ptr in [6, 7]:
        if pos == 7:
            pos = 15
        elif pos == 22:
            pos = 25
        elif pos == 36:
            pos = 5
    elif CH_ptr == 8:
        if pos == 22:
            pos = 28
        else:
            pos = 12
    elif CH_ptr == 9:
        pos -= 3

    CH_ptr = (CH_ptr + 1) % Card


def cc():
    global CC_ptr
    global pos
    if CC_ptr < 2:
        pos = CC_jump[CC_ptr]
    CC_ptr = (CC_ptr + 1) % Card


def game():
    global pos
    double = 0
    for t in range(Rolls):
        diceA = random.randint(1, DICE)
        diceB = random.randint(1, DICE)

        if diceA == diceB:
            double += 1
        else:
            double = 0

        if double == 3:
            double = 0
            pos = JAIL
        else:
            pos = (pos + diceA + diceB) % ALL

            if pos in CH:
                chance()
            if pos in CC:
                cc()
            if pos == G2J:
                pos = JAIL

        stats[pos] += 1


def show_result():
    lst = list(enumerate(stats))
    lst.sort(reverse = True, key = (lambda tuple: tuple[1]))
    for (i, t) in lst:
        print(i, t)
    ans = str(lst[0][0]) + str(lst[1][0]) + str(lst[2][0])
    print(ans)




game()
show_result()