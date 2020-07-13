class BitMap():
    def __init__(self,max):
        self.size = int( (max+31-1) /31 )
        self.array = [0] * self.size

    def bitindex(self,num):
        return num%31

    def set(self,num):
        eleindex = (num//31)
        byteindex = self.bitindex(num)
        ele = self.array[eleindex]
        self.array[eleindex] = ele | (1<<byteindex)

    def exist(self,i):
        eleindex = (i//31)
        byteindex = self.bitindex(i)
        if self.array[eleindex] & (1<<byteindex):
            return True
        return False



