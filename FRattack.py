from sympy import symbols, Poly, gcd, mod_inverse
from sympy.ntheory.modular import crt

def franklin_reiter(C1, C2, e, N, a, b):
    X = symbols('X')

    g1 = Poly((a*X + b)**e - C1, X, modulus=N)
    g2 = Poly(X**e - C2, X, modulus=N)

    G = gcd(g1, g2)

    roots = G.all_roots()
    if not roots:
        raise ValueError("No common root found — attack failed.")

    m = int(roots[0])
    
    try:
        return bytes.fromhex(hex(m)[2:]).decode()
    except Exception:
        return m  
    

N = 2534669
e = 3

a = 2
b = 5

m2 = 95
m1 = a * m2 + b

C1 = pow(m1, e, N)
C2 = pow(m2, e, N)

msg = franklin_reiter(C1, C2, e, N, a, b)
print("Recovered message:", msg)

