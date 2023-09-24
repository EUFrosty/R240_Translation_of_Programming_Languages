import sys
import re

if len(sys.argv) < 2:
    sys.exit("arg")

if re.match(r'^.+\.stn$', sys.argv[1], re.I) is None:
    sys.exit("exit")

try:
    with open(sys.argv[1], "r") as f:
        fajl = f.read()
except IOError:
    sys.exit("open")

ri = re.compile(r'{(.+?),\.NE\+([a-z]+):[1-9]+[a-z]}', re.I | re.S)

# for m in ri.finditer(fajl):
#     print(m.group(1), m.group(2))

noviTekst = ri.sub(r'<\2>\1</\2>', fajl)

# print(noviTekst)

try:
    with open(sys.argv[1][:-3] + "xml", "w") as fxml:
        fxml.write(noviTekst)
except IOError:
    sys.exit("open")

