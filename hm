import math

def root(n, eps):
  sqrt_n = n/2
  while True:
    new_n = (sqrt_n + n/sqrt_n)/2
    if abs(new_n - sqrt_n) <= eps:
      break
    sqrt_n = new_n
  return sqrt_n


def sin(x, eps):
    result = 0
    n = 0
    term = x
    while abs(term) > eps:
      result += term
      n += 1
      sign = 1 if n % 2 == 0 else -1
      term = (x ** (2*n + 1)) / math.factorial(2*n + 1) * sign
    return [result,n]


def arctan(x, eps):
    result = 0
    n = 0
    term = x
    while abs(term) > eps:
        result += term
        n += 1
        sign = 1 if n % 2 == 0 else -1
        term = (x ** (2*n + 1)) / (2*n + 1) * sign
    return result

eps1 = 10**(-6)/1.8
eps2 = 10**(-6)/2.4
eps4 = 10**(-6)/3.0
eps3 = 1/(10**6*3)

def func(x):
  u = root(2*x+0.4,eps1)
  v = sin(math.pi/2-3*x-1,eps2)
  result = 0
  n = 0
  term = v[0]
  while u*abs(term) > eps3:
    result += term
    n +=1
    sign = 1 if n % 2 == 0 else -1
    term = (v[0] ** (2*n+1)) / (2*n+1) * sign
  return result*u

x_values = [0.01,0.015,0.02,0.025,0.03,0.035,0.04,0.045,0.05,0.055,0.06]
table = []
for x in x_values:
    y = func(x)
    z = math.sqrt(2*x+0.4)*math.atan(math.cos(3*x+1))
    e = abs(z-y)
    table.append((x, y, z, e))

for x, y, z, e in table:
    print(f"x = {x} \t f_exact = {z} \t f_approx = {y} \t error = {e}")
