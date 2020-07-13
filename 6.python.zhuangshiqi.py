import time

def decorator(func):
    def handle_time(*args,**kwargs):
        start = time.time()

        func()

        end = time.time()
        print(end-start)

    return handle_time


@decorator
def func():
    time.sleep(0.8)

func()


##########################  类方法的函数装饰器
def decorator_class(func):
    def handle_time(me_instance):
        start = time.time()
        func(me_instance)
        end = time.time()
        print end-start
    return handle_time


class Method(object):

    @decorator_class
    def func(self):
        time.sleep(1.1)


p1 = Method()
p1.func()


######################### 类装饰器
class Decorator(object):
    def __init__(self, f):
        self.f = f
    def __call__(self):
        print("decorator start")
        self.f()
        print("decorator end")

@Decorator
def func():
    print("func")

func()


p = Decorator(func)   ####### p是类Decorator 的一个实例
p()                   ####### 实现了 __call__() 方法后， p 可以被调用


######################### python 装饰器库 functools
from functools imporpt wraps
def decorator(func):
    @wraps(func)
    def inner_function():
        pass
    return inner_function

@decrator
def func():
    pass

print( func.__name__ )



