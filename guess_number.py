import random

max_number = 2 << 10
min_number = 0


def avg(a, b): # 平均数，使得返回值在a和b两者之间
    return int((a+b)/2)


def smaller(guess):
    return avg(guess, min_number)


def bigger(guess):
    return avg(guess, max_number)


print("请在脑中想一个0-"+str(max_number)+"的整数（我能在12次之内猜中它）")
guess = random.randint(0, max_number)
a = None
while a != "是":
    a = input("是"+str(guess)+"吗？是/大了/小了？")

    if a == "大了":
        new_guess = smaller(guess)
        max_number = guess  # 别人告诉我们，我们的数字比较大，最大也不会超过我们刚才的guess
    elif a == "小了":  # 小了
        new_guess = bigger(guess)
        min_number = guess  # 别人告诉我们，我们的数字比较小，最小也不会小过我们刚才的guess

    if a != "是":
        guess = new_guess  # 现在我们有了新猜测，去问问他吧

print("猜出来了，是"+str(guess))
