import sys
import re

poruka = "danas je divan dan "
match = re.match(r"(\w+\s+)(\w+\s+)*", poruka)

if match is not None:
    print(match.group())
    print(match.groups())
    print(match.group(1))
    print(match.group(2))
    print(match.group(0))
else:
    print("Nema poklapanja")

m = re.search(r"\bd[a-z]+", poruka, re.I)
ofset = 0

if m is not None:
    print(m.group())
    print(poruka[m.start(): m.end()])
    ofset = m.end() - 1

m = re.search(r"\bd[a-z]+", poruka[ofset : ], re.I)

if m is not None:
    print(m.group())

m = re.findall(r"\bd[a-z]+", poruka, re.I)
print(m)

np = poruka.replace("danas", "sutra")
print(np)
