#!/bin/env python
from myglob import glob
#print(len(glob("../data")))
for i in glob("../data")[:10]:
    print(i)
