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

similarity_score = 0
for l in left:
    multiplicator = right.count(l)
    similarity_score += l * multiplicator

print('Similarity score =', similarity_score)