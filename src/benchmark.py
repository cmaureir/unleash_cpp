#!/bin/env python

import time
from glob import glob
from pathlib import Path
from fastglob import glob as fglob

def benchmark(opt, recursive=False):
    print(f"{opt}: ", end="")
    start = time.time()

    if opt == "glob":
        files = glob("data", recursive=recursive)
    elif opt == "Path":
        if not recursive:
            s = "**"
        else:
            s = "**/*"

        files = Path("data").glob(s)
    elif opt == "fglob":
        files = fglob("data", recursive=recursive)

    l = list(files)
    print(time.time() - start)

print("Non recursive")
print("-" * 40)
benchmark("glob", recursive=False)
benchmark("Path", recursive=False)
benchmark("fglob", recursive=False)

print("Recursive")
print("-" * 40)
benchmark("glob", recursive=True)
benchmark("Path", recursive=True)
benchmark("fglob", recursive=True)
