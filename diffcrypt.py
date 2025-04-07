import random
from collections import Counter

SBOX = [0xE, 0x4, 0xD, 0x1,
        0x2, 0xF, 0xB, 0x8,
        0x3, 0xA, 0x6, 0xC,
        0x5, 0x9, 0x0, 0x7]

SECRET_KEY = random.randint(0, 15)

def encryption_oracle(pt):
    return SBOX[pt ^ SECRET_KEY]


def differential_attack(samples):
    best_overall = []
    
    print("🕵️ Trying multiple ΔP values...")
    for delta_p in range(1, 16): 
        key_stats = []

        for key_guess in range(16):
            counter = Counter()

            for _ in range(samples):
                pt = random.randint(0, 15)
                pt2 = pt ^ delta_p

                ct1 = SBOX[pt ^ key_guess]
                ct2 = SBOX[pt2 ^ key_guess]

                delta_c = ct1 ^ ct2
                counter[delta_c] += 1

            most_common_delta, count = counter.most_common(1)[0]
            key_stats.append((delta_p, key_guess, most_common_delta, count))

        key_stats.sort(key=lambda x: -x[3])  
        best_overall.append(key_stats[0])   

    # find strongest key candidate overall
    best_overall.sort(key=lambda x: -x[3])
    return best_overall

results = differential_attack(samples=3000)

print("\n🎯 Ranked key candidates (best ΔP and key guesses):")
for delta_p, key, delta_c, count in results:
    print(f"ΔP: {delta_p:X}, Key Guess: {key:X}, ΔC: {delta_c:X}, Count: {count}")

print(f"\n🔑 Actual Secret Key was: {SECRET_KEY:X}")
