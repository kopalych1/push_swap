from random import sample
from sys import argv
ARRAY_MIN = 0
ARRAY_MAX = 2001
N_ELEMENTS = int(argv[1]) if len(argv) > 1 else 100

print(" ".join(str(_) for _ in sample(range(max(-N_ELEMENTS, ARRAY_MIN), min(N_ELEMENTS, ARRAY_MAX)), N_ELEMENTS)))