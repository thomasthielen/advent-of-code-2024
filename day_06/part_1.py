from enum import Enum

with open('input.txt') as f:
    input = f.readlines()
    
class Direction(Enum):
    UP = 1
    RIGHT = 2
    DOWN = 3
    LEFT = 4
    
dir = Direction.UP
r = -1
c = -1
m = list() 
    
for i, line in enumerate(input):
    m.append(list(line.rstrip()))
    if '^' in line:
        r = i
        c = line.find('^')

sum = 0
while(True):
    if m[r][c] == '.' or m[r][c] == '^':
        sum += 1
    m[r][c] = 'X'
    match dir:
        case Direction.UP:
            if r == 0:
                break
            if m[r-1][c] == '#':
                dir = Direction.RIGHT
            else:
                r -= 1
        case Direction.RIGHT:
            if c == len(m[c]) - 1:
                break
            if m[r][c+1] == '#':
                dir = Direction.DOWN
            else:
                c += 1
        case Direction.DOWN:
            if r == len(m) - 1:
                break
            if m[r+1][c] == '#':
                dir = Direction.LEFT
            else:
                r += 1
        case Direction.LEFT:
            if c == 0:
                break
            if m[r][c-1] == '#':
                dir = Direction.UP
            else:
                c -= 1
    
print(sum)