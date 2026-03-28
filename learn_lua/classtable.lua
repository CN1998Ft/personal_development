#!/usr/bin/env luajit

-- Class using table and metatables
Dog = {}

function Dog:new()
-- function Dog.new(self)
	newObject = {sound = "woof"}
	self.__index = self
	return setmetatable(newObject, self)
end

function Dog:makeSound()
	print("I say" .. self.sound)
end


mrDog = Dog:new()
mrDog:makeSound()
mrDog.makeSound(mrDog)

-- Inheritance
LoudDog = Dog:new()
function LoudDog:makeSound()
	s = self.sound .. ' '
	print(s .. s .. s)
end

seymour = LoudDog:new()
seymour:makeSound()

-- Subclass's new is the same as base's:
function LoudDog:new()
	newObject = {}
	self.__index = self
	return setmetatable(newObject, self)
end
