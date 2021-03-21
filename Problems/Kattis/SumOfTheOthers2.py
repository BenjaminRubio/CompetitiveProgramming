import sys
print('\n'.join([str(sum([int(x) for x in line.split()]) // 2) for line in sys.stdin]))