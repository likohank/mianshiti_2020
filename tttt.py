import os,sys
import multiprocessing

def process_file(filename, foo, bar, baz):
    print 123
    # do stuff that may fail and cause exception

if __name__ == '__main__':
    # setup code setting parameters foo, bar, and biz

    psize = multiprocessing.cpu_count()*2
    pool = multiprocessing.Pool(processes=psize)
    biz={}
    biz[1]=2

    map(lambda x: pool.apply_async(process_file, (x, foo, bar), dict(baz=biz)), sys.argv[1:])
    pool.close()
    pool.join()
