import sys
import re

if len(sys.argv) < 2:
    sys.exit("argumenti")

# re.I - ignore case rezim
match = re.match(r'^.*\.txt$', sys.argv[1], re.I)

if match is None:
    sys.exit("ekstenzija")
else:
    print("ok")

try:
    f = open(sys.argv[1], 'r')
except IOError:
    sys.exit("open")

for l in f:
    print(l, end="")

f.close()
