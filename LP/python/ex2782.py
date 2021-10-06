n = int(input())
nums = input().split()
escadinhas = 1
for i in range(n):
    nums[i] = int(nums[i])
if n == 1:
    print(escadinhas)
else:
    anterior = nums[0] - nums[1]
    for i in range(n):
        if i >= 2:
            atual = nums[i - 1] - nums[i]
            if atual != anterior:
                anterior = atual
                escadinhas += 1
    print(escadinhas)










