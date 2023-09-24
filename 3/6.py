import sys
import re

if len(sys.argv) < 2:
    sys.exit("arg")

if re.match(r"^.+\.html$", sys.argv[1], re.I) is None:
    sys.exit("ext")

try:
    with open(sys.argv[1], "r") as r:
        data = f.read()
except IOError:
    sys.exit("open")

ri = re.compile(r"<tr>"
+ r"\s*<td>\s*(?P<ime>[A-Z][a-z]+(\s+[A-Z][a-z]+)+)\s*<td>"
+ r"\s*<td>\s*(?P<prakticni>\d[1-9]\d\|100)\s*</td>"
+ r"\s*<td>\s*(?P<usmeni>\d[1-9]\d\|100)\s*</td>"
+ r"\s*</tr>", re.S)

studenti = []
poeni = []


for m in ri.finditer(data):
    #print(m.group(ime))
    #print(m.group(prakticni))
    #print(m.group(usmeni))
    studenti.append(m.group("ime"))
    poeni.append((int(m.group("prakticni")) + int(m.group("usmeni"))) / 2)

parovi = sorted(zip(poeni,studenti))
parovi.reverse()

for p,s in parovi:
    print(s, p)
