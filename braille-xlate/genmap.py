



oldcode = """m = open('map.dat', 'r')
lines = m.readlines()
m.close()
tups = []
for i in range(len(lines)):
    tups.append((lines[i], i))
tups = sorted(tups, key = lambda x: x[0])
hdr = open("braillemap.h", "w")
hdr.write("#ifndef _braillemap_h\n")
hdr.write("#define _braillemap_h\n")
hdr.write("#include <stdint.h>\n")
hdr.write("const uint8_t _bmap[255] = { ")
where = 0
for i in range(255):
    if chr(i) == tups[where][0]:
        where += 1
        hdr.write(str(tups[where-1][0]) + ',')
    else:
        hdr.write("0,")
map(lambda x: hdr.write(str(x[1]) + ","), tups)
hdr.write(" };\n")
hdr.write("static inline uint8_t braille_lookup(char ch)\n")
hdr.write("{ return _bmap[ch]; }\n")
hdr.write("#endif // !defined(_braillemap_h")
hdr.close()"""
