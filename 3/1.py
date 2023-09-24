import sys

if len(sys.argv) < 2:
    sys.exit("argumenti")

for arg in sys.argv:
    print(arg)

try:
    f = open(sys.argv[1], 'r')
except IOError:
    sys.exit("open")

for linija in f:
    print(linija, end="")

f.close()
