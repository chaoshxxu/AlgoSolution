from itertools import groupby

import collections

if __name__ == '__main__':
    k = int(raw_input())
    s = raw_input()

    stucked_keys = collections.OrderedDict()
    for c in s:
        stucked_keys[c] = 1

    for char, group in groupby(s):
        if len(list(group)) % k != 0 and char in stucked_keys:
            del stucked_keys[char]

    for key in stucked_keys:
        s = s.replace(key * k, key)

    print ''.join(stucked_keys)
    print s
