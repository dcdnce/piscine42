cat /etc/passwd | grep -v '#' | sed -n 'n;p' | rev | awk -F':' '{print $7}' | sort -r | awk -v a=$FT_LINE1 -v b=$FT_LINE2 'NR==a,NR==b' | tr '\n' '=' | sed 's/=/, /g' | sed 's/..$/./g' | tr -d '\n'
