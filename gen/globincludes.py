import sys
import os
from glob import glob

with open("./gen.cpp", "w") as f:
    for abspath in glob(f"{sys.argv[1]}/**/*.h", recursive=True):
        if os.path.basename(abspath).startswith("py"):
            continue

        relpath = os.path.relpath(abspath, sys.argv[1]).replace("\\", "/")
        print(relpath)
        f.write(f"#include <{relpath}>\n")
    