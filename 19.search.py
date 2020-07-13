def search(seq,number,lower,upper):
    if lower == upper:
        assert number == seq[upper]
        return upper;
    else:
        middle = (lower+upper)//2
        if(number>seq[middle]):
            return search(seq,number,middle+1,upper)
        else:
            return search(seq,number,lower,middler-1)
