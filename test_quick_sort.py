import os,sys

def quick_sort(array,l,r):
    if l<r:
        p = partition(array,l,r)
        quick_sort(array,l,p-1)
        quick_sort(array,p+1,r)

def partition(array,l,r):
    mid = array[r]
    i = l-1

    for j in range(l,r):
        if array[j]<=mid:
            i+=1
            if i!= j:
                array[i],array[j] = array[j],array[i]
    array[i+1],array[r] =  array[r],array[i+1]
    return i+1

aa = [4,1,7,3,5,3,9,2,1,3,2,0,7,4,9,6]
quick_sort(aa,0,len(aa)-1)

print aa
