# 0~15, '0' ~ 'f'
def numOfOnes(n):
    cnt = 0
    while n > 0:
        cnt += n & 1
        n >>= 1
    return cnt


def minBitFlips(n, m):
    return numOfOnes(n ^ m)


def hexchar(n):
    if n < 10:
        return chr(ord('0') + n)
    else:
        return chr(ord('a') + (n - 10))


def toHex(n):
    if n == 0:
        return '0'

    hexstr = ""
    while n > 0 or (n < 0 and len(hexstr) < 8):
        hexstr = hexchar(n & 0xF) + hexstr
        n >>= 4

    return hexstr


if __name__ == '__main__':
    print(numOfOnes(16))
    print(numOfOnes(7))
    print(numOfOnes(1234567))
    print(minBitFlips(10, 7))
    print(minBitFlips(2, 4))
    print(toHex(26))
    print(toHex(54321))
    print(toHex(0))
    print(toHex(-1))
    print(toHex(-26))
