import sys
import re

if len(sys.argv) < 2:
    sys.exit("arg")

if re.match(r"^.*\.txt$", sys.argv[1], re.I) is None:
    sys.exit("ext")

try:
    f = open(sys.argv[1], "r")
except IOError:
    sys.exit("open")

ri = re.compile(r"(\b[a-zA-Z]+\b)\s+\1")

for l in f:
    match = ri.search(l)
    if match is not None:
        print("Poklapanje: %s\n Grupe: %s" %(match.group(), match.groups()))
        print("Linija bez ponavljanja: %s" %(ri.sub(match.group(1), l)))

f.close()

try:
    f = open(sys.argv[1], "r")
    data = f.read()
except IOError:
    sys.exit("open2")

for m in ri.finditer(data):
    print(m.group())

f.close()
