import sys

prelazi = {('ADE', 'a') : 'B', ('ADE', 'b') : 'C', ('ADE', 'c') : 'ADE',
           ('B', 'a') : 'G', ('B', 'b') : 'ADE', ('B', 'c') : 'G',
           ('C', 'a') : 'G', ('C', 'b') : 'G', ('C', 'c') : 'G'}

#dodali smo dodatno stanje za stanja iz kojih nema slikanja, tj stanje greske G

stanje = "ADE"
zavrsno = 'C'

while True:
    try:
        c = input()
        if (c!='a' and c!='b' and c!='c'):
            raise ValueError
    except EOFError:
        break
    except ValueError:
        sys.exit("alfabet")


    if prelazi.get((stanje, c)) is None:
        sys.exit("nije deo reci")
    stanje = prelazi.get((stanje,c))
    print("\t" + stanje)

if stanje == zavrsno:
    print("rec je deo jezika")
else:
    print("rec nije deo jezika")
