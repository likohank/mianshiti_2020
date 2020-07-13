void QuickSort(int a[],start,end){
    if(start>end)
        return;
    int key = a[start];
    int p1 = start;
    int p2 = end;

    while(p1<p2){
        while(p1<p2 && a[p2]>=key)
            --p2;
        a[p1] = a[p2];

        while(p1<p2 && a[p1]<=key)
            ++p1;
        a[p2] = a[p1];
    }
    a[p1] = key;

    QuickSort(a,start,p1-1);
    QuickSort(a,p1+1,end);
}


#######################################################################

def quick_sort(array,l,r):
    if l<r:
        q = partition(array,l,r)
        quick_sort(array,l,q-1)
        quick_sort(array,q+1,r)

def partition(array,l,r):
    x = array[r]
    i = l-1

    for j in range(l,r):
        if array[j]<=x:
            i+=1
            array[i],array[j] = array[j],array[i]
    array[i+1],array[r] = array[r],array[i+1]
    return i+1


#######################################################################

def quick_sort(array,l,r):
    if l<r:
        p = partition(array,l,r)
        quick_sort(array,l,p-1)
        quick_sort(array,p+1,r)

def partition(array,l,r):
    i = l - 1
    x = array[r]

    for j in range(l,r):
        if array[j] <= x:
            i += 1
            array[i],array[j] = array[j],array[i]
    array[r],array[i+1]= array[i+1],array[r]
    return i+1
