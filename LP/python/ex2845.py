n = int(input())
maior = 0
nums = input().split()
for num in nums:
    num = int(num)
    if num > maior:
        maior = num
print(maior + 1)