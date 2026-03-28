#!/usr/bin/env luajit

-- A table can have a metatable that gives the table operator-overloadish
-- behaviours.
f1 = {a = 1, b = 2}
f2 = {a = 2, b = 3}
-- This will fail
-- s = f1 + f2

metafraction = {}

function metafraction.__add(f1, f2)
	sum = {}
	sum.b = f1.b * f2.b
	sum.a = f1.a * f2.b + f2.a * f1.b
	return sum
end

setmetatable(f1, metafraction)
setmetatable(f2, metafraction)

s = f1 + f2
print(s.a)
print(s.b)


defaultFavs = {animal = "gru", food = "donuts"}
myFavs = {food = "pizza"}
-- add myFavs.animal from defaultFavs, but not the food, as it is defined
setmetatable(myFavs, {__index = defaultFavs}) 
eatenBy = myFavs.animal
print(eatenBy)
print(myFavs.food)
