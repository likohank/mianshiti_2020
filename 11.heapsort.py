def heapify(arr,n,i):
    largest = i
    l = i*2+1
    r = i*2+2

    if l<n and arr[i]<arr[l]:
        largest = l
    if r<n and arr[largest]<arr[r]:
        largest = r

    if largest != i:
        arr[i],arr[largest] = arr[largest],arr[i]
        heapify(arr,n,largest)


def heapSort(arr):
    n = len(arr)

    #建立大根堆
    for i in range(n,-1,-1):
        heapify(arr,n,i)

    #逐个取大根堆的 堆顶，放到当前堆的最后一位， 然后将堆长度-1
    for i in range(n-1,0,-1):
        arr[i],arr[0] = arr[0],arr[i]
        heapify(arr,i,0)
