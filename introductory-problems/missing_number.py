n = int(input())
nums = [int(n) for n in input().split(" ")]
total = sum([i for i in range(1, n + 1)])
answer = total - sum(nums)
print(answer)
