def prefixes(s: str):
    prefix = ""
    yield prefix
    for _ in s:
        prefix += _
        yield prefix


def majorityelement(nums):
    hash = {}
    threshold = (len(nums) + 1) // 2
    for num in nums:
        if num in hash:
            hash[num] += 1
        else:
            hash[num] = 1
        if hash[num] >= threshold:
            return num
    # optional
    return None


def findprefix(num_strs: list[str]) -> bool:
    hash = set()
    for num_str in num_strs:
        if num_str not in hash:
            hash.add(num_str)
        else:
            return False

    # ensure uniqueness
    for num_str in num_strs:
        for prefix in prefixes(num_str):
            if prefix in hash and prefix != num_str:
                return False
    return True


if __name__ == '__main__':
    print(majorityelement([]))
    print(majorityelement([1]))
    print(majorityelement([2, 1]))
    print(majorityelement([2, 1, 1]))
    print(majorityelement([3, 3, 3, 2, 1, 3, 2, 1]))
    print(majorityelement([3, 3, 3, 2, 1, 3, 2, 1, 4]))
    print(findprefix(["112", "112", "01012345678"]))
    print(findprefix(["112", "119", "01012345678"]))
    print(findprefix(["112", "010", "01012345678"]))
