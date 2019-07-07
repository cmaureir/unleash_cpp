import sys
from glob import glob

if sys.argv[1] == "r":
    a = glob("data/**", recursive=True)
else:
    a = glob("data/**", recursive=False)
l = list(a)
