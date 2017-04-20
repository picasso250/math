# 一元一次方程

def solve():
    pass

def _is_symbol(s):
    return type(s) == str
def _is_num(s):
    return type(s) != str

def get_sign_of_symbol(a):
    if len(a) == 0:
        print("not valid symbol")
        return True
    return a[0] != '-'

def abs_symbol(a):
    if len(a) == 0:
        print("not valid symbol")
        return True
    if a[0] == '-':
        return a[1:]
    return a

def negtive_symbol(a):
    if get_sign_of_symbol(a) == True:
        return "-"+a
    return abs_symbol(a)

def get_sign(a):
    if _is_symbol(a):
        return get_sign_of_symbol(a)
    else:
        return a >= 0
    
def div_repr_abs(a,b):
    if _is_num(b) and b == 0:
        print("div by 0")
        return ""
    s = ""
    if _is_symbol(a):
        s += abs_symbol(a)
    else:
        s += str(abs(a))
    s += "/"
    if _is_symbol(b):
        s += abs_symbol(b)
    else:
        s += str(abs(b))     
    return s

def solve_1x1p_step1(a,b):
    print(a,end="")
    if not _is_symbol(a):
        print(" * ",end="")
    print("x + ",end="")
    if _is_num(b) and b < 0:
        print("(",b,")",end="")
    if _is_symbol(b) and get_sign_of_symbol(b) == False:
        print("(",b,")",end="")
    else:
        print(b,end="")
    print(" = 0")

def solve_1x1p_step2(a,b):
    print(a,end="")
    if not _is_symbol(a):
        print(" * ",end="")
    print("x = ",end="")
    if _is_num(b):
        print(-b)
    else:
        print(negtive_symbol(b))

def solve_1x1p_step3(a,b):
    print("x = ",end="")

    s = True # 符号
    if get_sign(a) == False:
        s = not s
    if get_sign(b) == False:
        s = not s
    s = not s
    if not s:
        print("-",end="")

    print(div_repr_abs(a,b))

def solve_1x1p_(a,b):
    if _is_num(a) and a == 0:
        print("a is 0")
        return
    solve_1x1p_step1(a,b)
    solve_1x1p_step2(a,b)
    solve_1x1p_step3(a,b)

def solve_1x2p_(a,b):
    print("(sqrt(a) * x )^2 + 2 *　sqrt(a)* 1/2*b * x + (1/2*b)^2 - (1/2*b)^2 + c = 0")
    print("")
    
# 一元一次
def solve_1x1p(eq, var):
    a = 0
    b = 4
    solve_1x1p_(a,b)
    pass


#solve_1x2p("ax^2+bx+c=0","x")

solve_1x1p("ax^2+bx+c=0","x")
