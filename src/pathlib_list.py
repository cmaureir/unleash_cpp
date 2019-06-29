#!/bin/env python
from pathlib import Path

a = list(Path("data").glob("**/*"))
print(len(a))
