#!/usr/bin/env luajit

local M = {}

local function sayMyname()
	print("Hrunkner")
end

function M.sayHello()
	print("Why hello there")
	sayMyname()
end

return M
