import multiprocessing as mp
import time

def f(x):
    print(x)
    time.sleep(2)
    print("%s end" % str(x))

if __name__ == '__main__':
    pool = mp.Pool(processes=2)
    pool.apply_async(f, 1)
    pool.apply_async(f, 2)
    pool.close()
    print("main_wait")
    pool.join()
    print("main_end")
