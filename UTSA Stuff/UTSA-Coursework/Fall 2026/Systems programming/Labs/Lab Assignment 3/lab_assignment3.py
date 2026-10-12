import time

#Ivan E Garcia eaa108

def fibonacci_naive(n):
    if n <= 1:
        return n

    return fibonacci_naive(n - 2) + fibonacci_naive(n - 1)

def fibonacci_memo(n, memo={}):
    if n <= 1:
        return n
    if n in memo:
        return memo[n]
    memo[n] = fibonacci_memo(n - 2, memo) + fibonacci_memo(n - 1, memo)

    return memo[n]


start_time = time.time()
fibonacci_naive(40)
end_time = time.time()
elapsed_time = end_time - start_time

print("Naive time:", elapsed_time, "sec")


start_time = time.time()
fibonacci_memo(40)
end_time = time.time()
elapsed_time = end_time - start_time

print("Memo time :", elapsed_time, "sec")