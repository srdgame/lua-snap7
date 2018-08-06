local s7 = require 'snap7'

local server = s7.TS7Server.new()
assert(server)
local ec = server:Start()
print("Start:\t", ec, s7.SrvErrorText(ec))

while true do
	print(server:ServerStatus(), server:GetCpuStatus(), server:ClientsCount())
	os.execute("sleep 1")
end
