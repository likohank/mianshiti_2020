from multiprocessing.pool import ThreadPool
import time

def run_this(idx):
    print('hello {0}-1'.format(idx))
    time.sleep(1)
    print('hello {0}-2'.format(idx))

pool = ThreadPool(10)

for idx in range(10):
    pool.apply_async(run_this, [idx])

pool.close()
pool.join()

print "123"
