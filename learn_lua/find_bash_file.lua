#!/usr/bin/env -S nvim -l
-- Author: Fengtao Zhang
-- Last Edit: 11/11/2026, 01:13 a.m.

---@param filename string the input filename
---@return boolean is_bash the condition to indicate whether file is bash
local function find_bash_file(filename)
	-- exceptional filenames
	---@type string[]
	local non_bash_filenames = { "makefile", "Makefile", "GNUmakefile", "configure" }
	---@type boolean
	local contains_non_bash_filename = vim.tbl_contains(non_bash_filenames, filename)

	---@type boolean
	local is_hidden_file = filename:match("^%.", 1) ~= nil

	---@type boolean
	local is_all_cap = filename:find("%l") == nil and filename == filename:upper()

	---@type boolean
	local is_config_file = filename:find("rc", -2) ~= nil or filename:match("^%u", 1) ~= nil

	-- final return boolean
	---@type boolean
	local is_bash = contains_non_bash_filename or is_hidden_file or is_all_cap or is_config_file
	is_bash = not is_bash

	return is_bash
end

local filenames = {
	".vimrc",
	"Makefile",
	".gitignore",
	"LICENSE",
	"README",
	"Brewfile",
	"configure",
	".bash_profile",
	".profile",
	"build",
}

for i, v in ipairs(filenames) do
	local state = find_bash_file(v)
	print(i, " : ", state)
end
