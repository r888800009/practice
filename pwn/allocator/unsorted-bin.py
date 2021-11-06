import gdb
print('hi')
gdb.execute('start')
gdb.execute('c')
# gdb.execute('heap bin unsorted')
gdb.execute('heap bin')
