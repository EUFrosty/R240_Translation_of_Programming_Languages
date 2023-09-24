egrep '^[A-Za-z][A-Za-z][A-Za-z][A-Za-z]+\b' /etc/group \
| sed -r 's/^(.+\b)([0-9]+)(\b.+)$/\2 \1\2\3/' \
| sort -V \
| sed -r 's/^[0-9]+ (.+\b[0-9]+\b.+)$/\1/' \
| perl -p -e 's/([aeiouAEIOU])(?=.*\b[0-9]+\b)/\1\1/g'
