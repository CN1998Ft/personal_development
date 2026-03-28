#!/usr/bin/env luajit
num = 42

s = 'walternate'
t = "double-quotes are also fine"
u = [[ Double brackets
	start and end
	multi-line string.]]

t = nil -- lua has built-in garbage collector

while num < 50 do
	num = num + 1
	print(num)
	io.write(num .. "\n")
end

if num > 40 then
	print('over 40')
elseif s ~= 'walternate' then
	io.write('not over 40\n')
else
	thisIsGlobal = 5
	local line = io.read()

	print("Winter is comming," .. line)
end

foo = anUnkownVariable
print(foo) -- nil

aBoolValue = false

-- Only the nil and false are false; 0 and '' are both true
if not aBoolValue then print('it was false') end

-- a?b:c in c
ans = aBoolValue and "yes" or "no"
print(ans)


karlSum = 0
for i = 1, 100 do -- the range selection
	karlSum = karlSum + i
	print(karlSum)
end

fredSum = 0
for j = 100, 1, -1 do fredSum = fredSum + j end

repeat
	print("the way of the future")
	num = num - 1
until num == 0
