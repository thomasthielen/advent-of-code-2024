with open('test.txt') as f:
    input = f.readlines()
    
left = list()
right = list()

for line in input:
    numbers = line.split("   ")
    if (len(numbers) < 2):
        continue
    left.append(int(numbers[0]))
    right.append(int(numbers[1]))
    
left.sort()
right.sort()

total_distance = 0
for l, r in zip(left,right):
    total_distance += abs(l-r)
    
print('Total distance between lists =', total_distance)