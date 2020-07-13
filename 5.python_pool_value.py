from multiprocessing import Pool, Value
from time import sleep

counter = None

def init(args):
    global counter
    counter = args

def analyze_data(args):
    global counter
    with counter.get_lock():
        counter.value += 1
    print counter.value
    return args * 10

if __name__ == '__main__':
    counter = Value('i', 0)
    inputs = [1, 2, 3, 4]

    p = Pool(initializer = init, initargs = (counter, ))
    i = p.map_async(analyze_data, inputs, chunksize = 1)
    i.wait()
    print i.get()
