#!/usr/bin/env luajit
function fib(n)
	if n < 2 then return 1 end
	return fib(n - 2) + fib(n-1)
end

x = fib(10)

function adder(x)
	-- The return function is created when adder is called
	-- and remembers the value of x
	print(x) -- returns 9, so the outer then inner.
	return function (y) return x+y end
end

a1 = adder(9)
a2 = adder(36)
print(a1(16))
print(a2(64))


x, y, z = 1,2,3,4 -- 4 is thrown away
print(x)
print(y)
print(z)

function bar(a,b,c)
	print(a,b,c)
	return 4, 8, 15, 16, 23, 42
end

x, y = bar("zaphod")
print(x)
print(y)


-- both way of creating function works
function f(x) return x * x end
f1 = function (x) return x * x end
print(f(10))
print(f1(10))


local function g(x) return math.sin(x) end
local g1; g1 = function (x) return math.sin(x) end
print(g(10))
print(g1(10))

print 'hello'
