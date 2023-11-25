def lcm(a, b):
    return (a * b) // gcd(a, b)

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def prime_factorization(n):
    if n <= 1:
        return []
    factors = []
    i = 2
    while i * i <= n:
        if n % i == 0:
            factors.append(i)
            n //= i
        else:
            i += 1
    if n > 1:
        factors.append(n)
    return factors

def find_other_number(n, gcd, lcm):
    other_number = lcm // n
    other_number_factors = prime_factorization(other_number)
    for factor in other_number_factors:
        if factor % gcd != 0:
            return other_number
    return -1

n = 1240
gcd = 20
lcm = 328600

other_number = find_other_number(n, gcd, lcm)
print(other_number)
