import multiprocessing
import time
import os
 
global datalist
datalist=['+++'] 

def adddata():
    datalist.append(1)
    datalist.append(2)
    datalist.append(3)
    print("Child",os.getpid(),datalist)
 
 
if __name__=="__main__":
    p=multiprocessing.Process(target=adddata,args=())
    p.start()
    p.join()
    datalist.append("a")
    datalist.append("b")
    datalist.append("c")
    print("Father",os.getpid(),datalist)


