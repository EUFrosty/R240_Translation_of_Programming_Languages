import sys
import re

def obradi_stranice(dat):
    if dat in obradjene_datoteke:
        return

    obradjene_datoteke.append(dat)

    try:
        with open(dat, "r") as f:
            podaci = f.read()
    except IOError:
        sys.exit("open")

    ri = re.compile(r'<a\s+href\s*=\s*"([^"]+)"\s*>(.*?)</a>', re.S | re.I)

    for m in ri.finditer(podaci):
        url = m.group(1)
        ime = m.group(2)

        if url in statistika:
            statistika[url] += 1
        else:
            statistika[url] = 1

        obradi_stranice(url)

if len(sys.argv)>1:
    pocetna = sys.argv[1]
else:
    pocetna = 'index.html'

obradjene_datoteke = []
statistika = {}

obradi_stranice(pocetna)

for k, v in statistika.items():
    print(k, v)
