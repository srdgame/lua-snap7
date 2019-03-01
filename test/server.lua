local s7 = require 'snap7'

local server = s7.TS7Server.new()
assert(server)

local db21 = s7.DBArea.new(512)
local db103 = s7.DBArea.new(1280)
local db3 = s7.DBArea.new(1024)

server:RegisterArea(s7.S7SrvArea.DB, 21, db21.data, db21.size)
server:RegisterArea(s7.S7SrvArea.DB, 103, db103.data, db103.size)
server:RegisterArea(s7.S7SrvArea.DB, 3, db3.data, db3.size)

local ec = server:Start()
print("Start:\t", ec, s7.SrvErrorText(ec))

while true do
	print(server:ServerStatus(), server:GetCpuStatus(), server:ClientsCount())
	os.execute("sleep 1")
end
