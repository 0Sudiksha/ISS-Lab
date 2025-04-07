from math import gcd

def fermat_test(n, a):
    if gcd(a, n) != 1:
        return False  
    return pow(a, n - 1, n) == 1  # Fermat's little theorem

print(fermat_test(91,80))
print(fermat_test(7,3))