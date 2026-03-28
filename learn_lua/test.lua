#!/usr/bin/env luajit

local mod = require("mod")
-- The require is acting like:
-- local mod = (function ()
	-- <contents of mod.lua>
-- end)()

-- mod = M in mod.lua
mod.sayHello()
-- mod.sayMyname() -- local function only exist in mod.lua

-- require only run file once at most
local a = require("lua_2/mod2")
local b = require("lua_2/mod2")
if a == b then
	print("a is b")
end

-- dofile run as many times as we put it and take the file extension
dofile("lua_2/mod2.lua")
dofile("lua_2/mod2.lua")

-- loadfile is same as dofile, but only load it not running it
f = loadfile("lau_2/mod2.lua")

g = load("print(343)")
g()
