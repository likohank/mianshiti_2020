#coding=utf-8
import multiprocessing
import os
import time

def do(n) :
  #获取当前线程的名字
  name = multiprocessing.current_process().name
  for i in range(100):
      print(name,'starting')
      print("worker ", n)
      time.sleep(0.1)
  return 

if __name__ == '__main__' :
  numList = []

  for i in xrange(5) :
    p = multiprocessing.Process(target=do, args=(i,))
    numList.append(p)
    p.start()
  for p in numList:
    p.join()
  print("Process end.")
