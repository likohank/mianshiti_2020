import multiprocessing
 
def  func(num):
    num.value=True
 
if  __name__=="__main__":
    num=multiprocessing.Value("d",False)
    print(num.value)
 
    p=multiprocessing.Process(target=func,args=(num,))
    p.start()
    p.join()
 
    print(num.value)

