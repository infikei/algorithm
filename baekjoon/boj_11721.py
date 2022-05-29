st = input()
st_print = []

for i in st:
    st_print.append(i)
    if len(st_print) == 10:
        print(*st_print, sep="")
        st_print.clear()

if len(st_print) > 0:
    print(*st_print, sep="")
