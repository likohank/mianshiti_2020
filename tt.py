# _*_ coding:utf-8 _*_

from multiprocessing import Pool
import os,sys
import time


def add_part(part):
    print(part)
    result = 0
    try:
        for value in range(part[0], part[1] + 1):
            result += value
    except Exception as e:
        print("Some ting error")
        print(str(e))
    return result


def main():
    pool = Pool(processes=2)
    part_result = (pool.map(add_part, [[0, 500000000], [500000001, 1000000000]]))
    print(000)
    pool.close()
    print(123)
    pool.join()
    print(part_result)   # [125000000250000000, 375000000250000000]
    add_result = 0
    for i in part_result:
        print(i)
        add_result += i
    print("结果为:", add_result)


if __name__ == '__main__':
    main()
