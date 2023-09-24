import sys
import re
import os

if len(sys.argv) > 1:
    homedir = sys.argv[1]

homedir = sys.argv[1]

#kljuc->indeks, vrednost->ime i prezime studenta
studenti = {}

putanja = os.path.join(homedir, 'indeks.txt')
try:
    with open(putanja, 'r') as f:
        for linija in f.readlines():
            if linija[-1] == '\n':
                linija = linija [:-1]

            m = re.match(r"^([A-Za-z ]+),\s*((m[mnvrlia]|a[aif])([01]\d|2[01])(00[1-9]|0[1-9]\d|[1-5]\d\d|600))$", linija)

            if m is not None:
                indeks = m.group(2)
                ime = m.group(1)
                studenti[indeks] = ime

except IOError:
    sys.exit("open");

print(studenti)

re_dir = re.compile(r"^((m[mnvrlia]|a[aif])([01]\d|2[01])(00[1-9]|0[1-9]\d|[1-5]\d\d|600))$")
re_file = re.compile(r"^(.*)\.(pas|c|cpp|java)$", re.I)

maxBrZad = 0
zadaci = {}

#kljuc -> (indeks, redBrZad)
#vrednost -> ekstenziju

for f in os.listdir(homedir):
    studDir = os.path.join(homedir, f)
    m = re_dir.match(f)
    if os.path.isdir(studDir) and m is not None and f in studenti:
        indeks = m.group(1)
        for sf in os.listdir(studDir):
            zadatak = os.path.join(studDir, sf)
            m = re_file.match(sf)
            if os.path.isfile(zadatak) and m is not None:

                zad = int(m.group(1))
                zadaci[(indeks, zad)] = m.group(2)
                if zad > maxBrZad:
                    maxBrZad = zad

for indeks,ime in studenti.items():
    print("\nIme: " + ime)
    for i in range(1, maxBrZad):
        if (indeks, i) in zadaci:
            print("\t" + str(i) + "." + zadaci[(indeks, i)])
        else:
            print("\t" + str(i) + ".-")
