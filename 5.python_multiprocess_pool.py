# _*_ coding:utf-8 _*_
# Pool_map

####### https://www.biaodianfu.com/python-multi-thread-and-multi-process.html

from multiprocessing import Pool
import os,sys
import time

def test(i):
    print(i)

if __name__ == "__main__":
    lists = range(1000)
    pool = Pool(8)
    pool.map(test,lists)
    pool.close()
    pool.join()


###############################   apply_async 

def add_part(part):
    result = 0
    for value in range(part[0], part[1] + 1):
        result += value
    return result


if __name__ == '__main__':
    part_result = []
    pool = Pool(processes=2)
    for i in [[0, 500000000], [500000001, 1000000000]]:
        part_result.append(pool.apply_async(add_part, args=(i,)))
    pool.close()
    pool.join()

    add_result = 0
    for index, value in enumerate(part_result):   #将数组变化为  [ (下标,元素),()..  ]
        print("第%s个进程的结果为%s" % (index, value.get()))
        add_result += value.get()
    print("结果为", add_result)


###############################  map
if __name__ == '__main__':
    pool = Pool(processes=2)
    part_result = (pool.map(add_part, [[0, 500000000], [500000001, 1000000000]]))
    pool.close()
    pool.join()
    print(part_result)   # [125000000250000000, 375000000250000000]
    add_result = 0
    for i in part_result:
        print(i)
        add_result += i
    print("结果为:", add_result)



