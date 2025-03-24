# return the first factor of number.
# return 1 if no factor exists
def factor(n):
     i = 2

     while i <= n//2:
       if n % i == 0:
          return i
       i += 1

     return 1

# main
n = int(input())
print(factor(n))

