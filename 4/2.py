import sys
import re

opcijaAutor = False
opcijaGodina = False
opcijaIzdavac = False
opcijaCena = False

naslovKnjige = None

if len(sys.argv) < 2:
    sys.exit("arg")

for arg in sys.argv[2:]:
    if arg[0] == "-":
        if arg[1] == "a":
            opcijaAutor = True
        if arg[1] == "c":
            opcijaCena = True
        if arg[1] == "g":
            opcijaGodina = True
        if arg[1] == "i":
            opcijaIzdavac = True
    else:
        naslovKnjige = arg

if re.match(r'^.+\.xml$', sys.argv[1], re.I) is None:
    sys.exit("ext")

try:
    with open(sys.argv[1], "r") as f:
        fajl = f.read()
except IOError:
    sys.exit("open")

ri = re.compile (r'<knjiga\s+rbr\s*=\s*"(?P<rbr>[0-9]+)"\s*>'
                 + r'(?=.*?<naslov>\s*(?P<naslov>.*?)\s*</naslov>)'
                 + r'(?=.*?<autor>\s*(?P<autor>[A-Z][a-z]+(\s+[A-Z][a-z]+)+)\s*</autor>)'
                 + r'(?=.*?<godina_izdanja>\s*(?P<godina>[1-9][0-9]*?)\s*</godina_izdanja>)'
                 + r'(?=.*?<izdavac>\s*(?P<izdavac>.*?)\s*</izdavac>)'
                 + r'(?=.*?<cena\s+valuta\s*=\s*"(?P<valuta>(eur|rsd))"\s*>\s*(?P<cena>[0-9]+?)\s*</cena>)'
                 + r'.*?'
                 + r'</knjiga>', re.S)

biblioteka = {}

for m in ri.finditer(fajl):
    rbr = m.group("rbr")
    naslov = m.group("naslov")
    autor = m.group("autor")
    godina = m.group("godina")
    izdavac = m.group("izdavac")
    cena = m.group("cena")
    valuta = m.group("valuta")

    biblioteka[rbr] = [naslov, autor, godina, izdavac, cena, valuta]

vrednosti = None
for k, v in biblioteka.items():
    if naslovKnjige == v[0]:
        vrednosti = v[1:]
        break

if vrednosti is None:
    print("Nema knjige")

if opcijaAutor:
    print(vrednosti[0])
if opcijaGodina:
    print(vrednosti[1])
if opcijaIzdavac:
    print(vrednosti[2])
if opcijaCena:
    print(vrednosti[3], vrednosti[4])

if (opcijaAutor or opcijaCena or opcijaGodina or opcijaIzdavac) == False:
    for v in vrednosti:
        print(v)
