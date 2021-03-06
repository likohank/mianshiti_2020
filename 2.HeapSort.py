import os,sys


def buildMaxHeap( arr):
    for i in range( int(len(arr)+1)/2 ,-1,-1):
        heapify(arr,i)

def heapify(arr,i):
    left = 2*i + 1
    right = 2*i + 2
    largest = i

    if left<arrLen and arr[left]>arr[largest]:
        largest = left
    if right<arrLen and arr[right]>arr[largest]:
        largest = right
    if largest != i:
        swap(arr,i,largest)
        heapify(arr,largest)


def swap(arr,i,j):
    arr[i],arr[j] = arr[j],arr[i]

def heapSort(arr):
    global arrLen
    arrLen = len(arr)
    buildMaxHeap(arr)

    for i in range( len(arr)-1 ,0, -1):
        swap(arr,0,i)
        arrLen -= 1
        heapify(arr,0)
    return arr

def main():
    arr=[5,2,7,3,6,1,4]
    bb=heapSort(arr)
    print bb

main()
