#!/usr/bin/env lua

local table_1 = { key_1 = "one", "two", "tree" }

print("--- pairs ---")
for i, v in pairs(table_1) do
	print(i, v)
end

print("--- ipairs ---")
for i, v in ipairs(table_1) do
	print(i, v)
end
