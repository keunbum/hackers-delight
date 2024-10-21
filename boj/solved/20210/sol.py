import sys

alphaDict = {'A': 1, 'a': 2, 'B': 3, 'b': 4, 'C': 5, 'c': 6, 'D':7, 'd': 8, 'E': 9, 'e': 10, 'F': 11, 'f': 12, 'G': 13, 'g': 14, 'H': 15, 'h': 16, 'I': 17, 'i': 18, 'J': 19, 'j': 20, 'K': 21, 'k': 22, 'L': 23, 'l': 24, 'M': 25, 'm': 26, 'N': 27, 'n': 28, 'O': 29, 'o': 30, 'P': 31, 'p': 32, 'Q': 33, 'q': 34, 'R': 35, 'r':36, 'S': 37, 's': 38, 'T': 39, 't': 40, 'U': 41, 'u': 42, 'V': 43, 'v': 44, 'W': 45, 'w': 46, 'X': 47, 'x': 48, 'Y': 49, 'y': 50, 'Z': 51, 'z': 52}

def parse_filename(i, filename):
    result = [i]
    tmp = filename[0]
    if filename[0].isalpha():
        ex_type = 'alpha'
    else:
        ex_type = 'digit'

    for char in filename[1:]:
        if char.isalpha():
            type = 'alpha'
        else:
            type = 'digit'

        if ex_type == type:
            tmp += char
        else:
            if tmp.isdigit():
                tmp = int(tmp)
            result.append(tmp)
            tmp = char
            ex_type = type
    result.append(tmp)
    return result

def first_one_comes_first(str1, str2):

    first_one_comes_first = False
    second_one_comes_first = False

    str1 = str(str1)
    str2 = str(str2)

    if str1.isdigit() and str2.isdigit():
        if int(str1) < int(str2):
            first_one_comes_first = True
        else:
            second_one_comes_first = True
    elif str1.isalpha() and str2.isalpha():
        for s1, s2 in zip(str1, str2):
            if alphaDict[s1] < alphaDict[s2]:
                first_one_comes_first = True
                break
            elif alphaDict[s1] > alphaDict[s2]:
                second_one_comes_first = True
                break
            else:
                continue
    else:
        if str1.isalpha() and str2.isdigit():
            second_one_comes_first = True
        else:
            first_one_comes_first = True

    if first_one_comes_first == False and second_one_comes_first == False:
        if len(str1) < len(str2):
            first_one_comes_first = True
        else:
            second_one_comes_first = True

    if first_one_comes_first:
        return True
    elif second_one_comes_first:
        return False

def make_file_order(parsed_list):
    result = []
    m = len(parsed_list)

    for i in range(m):
        tmp_min_idx = i
        for j in range(i + 1, m):
            full_str2 = parsed_list[j]
            str1_len = len(parsed_list[tmp_min_idx]) - 1
            str2_len = len(parsed_list[j]) - 1
            str1 = parsed_list[tmp_min_idx][1:]
            str2 = parsed_list[j][1:]

            if str1_len <= str2_len:
                cnt = str1_len
            else:
                cnt = str2_len
            for p in range(cnt):
                if str1[p] != str2[p]:
                    if first_one_comes_first(str1[p], str2[p]) == True:
                        break
                    else:
                        tmp_min_idx = parsed_list.index(full_str2)
                        break
                else:
                    continue
        if i != tmp_min_idx:
            parsed_list[i], parsed_list[tmp_min_idx] = parsed_list[tmp_min_idx], parsed_list[i]

    for v in parsed_list:
        result.append(v[0])

    return result

n = int(input())
original_filenames = []
parsed_filenames = []
for i in range(n):
    filename = sys.stdin.readline().rstrip()
    original_filenames.append(filename)
    parsed_filenames.append(parse_filename(i, filename))
result = make_file_order(parsed_filenames)
for order in result:
    print(original_filenames[order])