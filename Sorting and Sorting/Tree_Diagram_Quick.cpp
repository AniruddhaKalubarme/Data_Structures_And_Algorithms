          Quick(arr, 0, 5)
             |
             |
             |-- partition(arr, 0, 5)
             |    |
             |    |-- pivot = 10
             |    |-- iCnt = 3
             |    |-- swap(arr[3], arr[0])
             |    |-- arr = {5, 11, 2, 10, 18, 6}
             |
             |-- Quick(arr, 0, 2)
             |    |
             |    |-- partition(arr, 0, 2)
             |    |    |
             |    |    |-- pivot = 5
             |    |    |-- iCnt = 2
             |    |    |-- swap(arr[2], arr[0])
             |    |    |-- arr = {2, 11, 5, 10, 18, 6}
             |    |
             |    |-- Quick(arr, 0, 1)
             |    |    |
             |    |    |-- partition(arr, 0, 1)
             |    |    |    |
             |    |    |    |-- pivot = 2
             |    |    |    |-- iCnt = 1
             |    |    |    |-- swap(arr[1], arr[0])
             |    |    |    |-- arr = {2, 2, 5, 10, 18, 6}
             |    |    |
             |    |    |-- Quick(arr, 0, 0)
             |    |    |    |
             |    |    |    |-- return (already sorted)
             |    |    |
             |    |    |-- Quick(arr, 2, 2)
             |    |    |    |
             |    |    |    |-- return (already sorted)
             |    |
             |    |-- Quick(arr, 3, 5)
             |         |
             |         |-- partition(arr, 3, 5)
             |         |    |
             |         |    |-- pivot = 10
             |         |    |-- iCnt = 2
             |         |    |-- swap(arr[5], arr[3])
             |         |    |-- arr = {2, 2, 5, 6, 18, 10}
             |         |
             |         |-- Quick(arr, 3, 4)
             |         |    |
             |         |    |-- partition(arr, 3, 4)
             |         |    |    |
             |         |    |    |-- pivot = 6
             |         |    |    |-- iCnt = 1
             |         |    |    |-- swap(arr[4], arr[3])
             |         |    |    |-- arr = {2, 2, 5, 6, 10, 18}
             |         |    |
             |         |    |-- Quick(arr, 3, 3)
             |         |    |    |
             |         |    |    |-- return (already sorted)
             |         |    |
             |         |    |-- Quick(arr, 4, 5)
             |         |    |    |
             |         |    |    |-- return (already sorted)

---------------------------------------------------------------------------------------------------------------


[69, 79, 97, 63, 56, 89, 52, 14, 21, 56, 85, 201]


Quick(arr, 0, 11) → [14, 21, 52, 56, 56, 63, 69, 201, 85, 79, 89, 97]
                /                                    \
Quick(arr, 0, 5) → [14, 21, 52, 56, 56, 63]        Quick(arr, 7, 11) → [97, 85, 79, 89, 201]
        /           \                                /                  \
   No Call     Quick(arr, 1, 5)            Quick(arr, 7, 10)     No Call
                     /      \                   /        \
               No Call    Quick(arr, 2, 5) Quick(arr, 7, 9)   No Call
                             /      \             /      \
                       No Call  Quick(arr, 3, 5) Quick(arr, 7, 8)  No Call
                                  /      \         /      \
                            No Call  Quick(arr, 4, 5) No Call Quick(arr, 8, 8)
                                        /      \
                                  No Call   Quick(arr, 5, 5)
                                            /      \
                                      No Call    No Call
