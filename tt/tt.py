#import os

###################装饰器

def deco_para(parameter):
    print('enter deco_para')

    def deco_func(func):
        print('enter deco_func')

        def wrapper(*args, **kwargs):
            print('enter wrapper')
            print(parameter)
            print('---wrapper: before func---')
            func(*args, **kwargs)
            print('---wrapper: after func---')

        return wrapper

    return deco_func

@deco_para(123)
def foo():
    print('---foo---')


if __name__ == '__main__':
    deco_func = deco_para(123)  # 接收参数123
    wrapper = deco_func(foo)  # 接收函数foo
    foo = wrapper  # 重命名
    foo()  # 执行foo


#enter deco_para
#enter deco_func
#--start--
#enter wrapper
#123
#---wrapper: before func---
#---foo---
#---wrapper: after func---



if __name__ == '__main__':
    deco_func = deco_para(123)  # 接收参数123
    wrapper = deco_func(foo)  # 接收函数foo
    foo = wrapper  # 重命名
    foo()  # 执行foo


#enter deco_para
#enter deco_func
#enter deco_para
#enter deco_func
#enter wrapper
#123
#---wrapper: before func---
#enter wrapper
#123
#---wrapper: before func---
#---foo---
#---wrapper: after func---
#---wrapper: after func---

###########################################################
#    https://www.jianshu.com/p/2ffb2a0d2b4c
###########################################################


# /usr/bin/env Python3
# -*- encoding:UTF-8 -*-

@wraps 函数
 
from functools import wraps
 
def sum_add(*args1): #我们要给我们的装饰器decorator，带上参数
    def decorator(func):
        @wraps(func) #加上这句，原函数func被decorator作用后，函数性质不变
        def my_sum(*args2): #注意，参数要和原函数保持一致，真正实行扩展功能的是外层的装饰器
            my_s = 0
            for n in args1:
                my_s = my_s +n #这个是我们新加的求和结果
            return func(*args2) + my_s #这个，我们在原求和函数的结果上再加上s，并返回这个值
        return my_sum #返回my_sum函数，该函数扩展原函数的功能
    return decorator  #返回我们的装饰器
 
@sum_add(10,20) #启用装饰器 对sum函数进行功能扩展 
def sum(*args):
    s = 0
    for n in args:
        s = s+n
    return s
print(sum(1,2,3,4,5))
print(sum.__name__)


###################################################

# 偏函数

# /usr/bin/env Python3
# -*- encoding:UTF-8 -*-
import  functools 
def mod(m,*,key=2):
 return m % key == 0
mod_to_2 = functools.partial(mod,key=2)
print('A__3___使用原函数的默认关键字参数对2进行求余：')
print(mod(3))                           #对2进行求余-- 原函数 使用默认参数
print('B__3___使用偏函数对2进行求余：')
print(mod_to_2(3))                      #对2进行求余-- 新函数 --偏函数产生
mod_to_5 = functools.partial(mod,key=5) 
print('C__25___使用原函数的关键字参数对5进行求余：')
print(mod(25,key=5))                    #对5进行求余 -- 原函数
print('D__25___使用偏函数对5进行求余：')
print(mod_to_5(25))                     #对5进行求余 -- 新函数--偏函数产生

