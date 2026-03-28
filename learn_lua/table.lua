#!/usr/bin/env luajit

-- Table is the only compound data structure in lua
-- Use as dictionary / map
t = {key1 = "value1", key2 = false}

print(t.key1)
t.newKey = {}
print(t.newKey)
t.key2 = nil
print(t.key2) -- remove key2 from table t
print(t.key23)

-- key literally take any value, except nil value
u = {['@!#'] = 'qbert', [{}] = 1729, [6.28] = 'tau'}
print(u['@!#'])
print(u[{}]) -- nil
print(u[6.28])

function h(x) print(x.key1) end
h{key1 = 'Sonmi~451'}

-- table iteration
for key, value in pairs(u) do
	print(key, val)
end

-- _G is a special table
print(_G['_G'] == _G)

-- use table as a list
v = {"value", "value2", 1.21, "gigawatts"}
for i = 1, #v do
	print(v[i]) -- lua starts with 1 indexing
end
