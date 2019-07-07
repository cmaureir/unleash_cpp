import time
from glob import glob
from pathlib import Path
from fastglob import glob as fglob
import subprocess

def benchmark(opt, recursive=False):
    print(f"{opt}: ", end="")
    r = "r" if recursive else "n"
    start = time.time()
    if opt == "glob":
        subprocess.call("python glob_list.py "+r, shell=True)
    elif opt == "Path":
        subprocess.call("python pathlib_list.py "+r, shell=True)
    elif opt == "fglob":
        subprocess.call("python fastglob_list.py "+r, shell=True)
    print(time.time() - start)

print("Non recursive")
benchmark("glob", recursive=False)
benchmark("Path", recursive=False)
benchmark("fglob", recursive=False)
print("-" * 40)
print()
print("Recursive")
benchmark("glob", recursive=True)
benchmark("Path", recursive=True)
benchmark("fglob", recursive=True)
print("-" * 40)
