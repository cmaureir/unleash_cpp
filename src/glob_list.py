#!/bin/env python
from glob import glob

a = glob("data/**", recursive=True)
print(len(a))
