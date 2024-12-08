from enum import Enum
import copy

with open('analyze.txt') as f: # instead of using 'input.txt', use 'analyze.txt' (pre-computed original path from part_1)
    input = f.readlines()
    
def check_loop(m,r,c,dir):
    visited = []
    while(True):
        visited.append((r,c,dir))
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
        if (r,c,dir) in visited:
            return True # guard got stuck in a loop
    return False # guard escaped

class Direction(Enum):
    UP = 1
    RIGHT = 2
    DOWN = 3
    LEFT = 4
    
# original coordinates of the '^'
r_origin = 70 
c_origin = 60
dir = Direction.UP
m = list() 
    
for i, line in enumerate(input):
    m.append(list(line.rstrip()))

sum = 0
for r_obstacle in range(0,len(m)):
    for c_obstacle in range(0,len(m[0])):
        if m[r_obstacle][c_obstacle] == '#' or m[r_obstacle][c_obstacle] == '^' or m[r_obstacle][c_obstacle] == '.':
            continue
        m_obstacle = copy.deepcopy(m)
        m_obstacle[r_obstacle][c_obstacle] = '#'
        sum += check_loop(m_obstacle, r_origin, c_origin, dir)
    
print(sum)