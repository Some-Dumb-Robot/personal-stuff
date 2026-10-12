# Ivan E Garcia, eaa108


main_array = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
def binary_search(array,val):
    left = 0
    right = len(array) - 1

    while left <= right:
        # find and check middle
        middle = (left + right) // 2
        if array[middle] == val:
            return middle

        #check left and right to see where to change values
        elif array[middle] < val:
            left = middle + 1
        else:
            right = middle - 1

    return middle

print(binary_search(main_array, 3))
print(binary_search(main_array, 7))
print(binary_search(main_array, 11))
print(binary_search(main_array, 20))