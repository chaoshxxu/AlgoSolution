from itertools import groupby

if __name__ == '__main__':
    k = int(raw_input())
    s = raw_input()

    stucked_keys = set(s)
    for char, group in groupby(s):
        l = len(list(group))
        if l % k != 0 and char in stucked_keys:
            stucked_keys.remove(char)

    _ = ''
    for c in s:
        if c in stucked_keys and c not in _:
            _ += c
    print _

    for stucked_key in stucked_keys:
        s = s.replace(stucked_key * k, stucked_key)
    print s
