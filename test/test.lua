local s7 = require 'snap7'
local basexx = require 'basexx'

local client = s7.TS7Client.new()
assert(client)
--print(client)
--print(client:Connected())

--print(client:Connect())
print("Connect:\t", client:ConnectTo("127.0.0.1", 0, 2))
--[[
print(client:LastError())
print(client:Connected())
]]--

-- TODO:
--print(client:GetPlcDateTime())

local oc = s7.TS7OrderCode.new()
assert(0 == client:GetOrderCode(oc))
print('*OrderCode\nCode\t', oc.Code, '\nVersion:\t', oc.V1, oc.V2, oc.V3)
local cpuinfo = s7.TS7CpuInfo.new()
assert(0 == client:GetCpuInfo(cpuinfo))
print('*CpuInfo\nModuleTypeName:\t', cpuinfo.ModuleTypeName, '\nSerialNumber:\t', cpuinfo.SerialNumber)

local cpinfo = s7.TS7CpInfo.new()
assert(0 == client:GetCpInfo(cpinfo))
print("*CpInfo\nMaxPduLength", cpinfo.MaxPduLength)

print('*PlcStatus:\t', client:PlcStatus())

local szl = s7.TS7SZL.new()
local size = s7.IntData.new(szl.Size)
assert(0 == client:ReadSZL(0x0011, 0x0000, szl, size.ptr))
print("ReadSZL\nHeader->LENTHDR:\t", szl.Header.LENTHDR, "\nHeader->N_DR:\t", szl.Header.N_DR, "\nSize:\t", size.value)
print("Dump:", basexx.to_hex(szl.Data:sub(1, size.value - 4)))


local data = s7.UserData.new(65536)
local size = s7.IntData.new(65536)
local ret = client:Upload(s7.S7BlockType.SDB, 0, data.data, size.ptr)
print("Upload:", ret, size.value)
if ret ~= 0 then
	print(s7.CliErrorText(ret))
end

local items = {}
local datas = {}
local item = s7.TS7DataItem.new()
local data = s7.UserData.new(16)
item.Area = s7.S7AreaID.MK
item.WordLen = s7.S7WordLen.Byte
item.DBNumber = 0
item.Start = 0
item.Amount = 16
item.pdata = data.data
items[#items + 1] = item
datas[#datas + 1] = data

local item = s7.TS7DataItem.new()
local data = s7.UserData.new(16)
item.Area = s7.S7AreaID.PE
item.WordLen = s7.S7WordLen.Byte
item.DBNumber = 0
item.Start = 0
item.Amount = 16
item.pdata = data.data
items[#items + 1] = item
datas[#datas + 1] = data

local item = s7.TS7DataItem.new()
local data = s7.UserData.new(16)
item.Area = s7.S7AreaID.PA
item.WordLen = s7.S7WordLen.Byte
item.DBNumber = 0
item.Start = 0
item.Amount = 16
item.pdata = data.data
items[#items + 1] = item
datas[#datas + 1] = data

local item = s7.TS7DataItem.new()
local data = s7.UserData.new(8)
item.Area = s7.S7AreaID.TM
item.WordLen = s7.S7WordLen.Timer
item.DBNumber = 0
item.Start = 0
item.Amount = 8
item.pdata = data.data
items[#items + 1] = item
datas[#datas + 1] = data

local item = s7.TS7DataItem.new()
local data = s7.UserData.new(8)
item.Area = s7.S7AreaID.CT
item.WordLen = s7.S7WordLen.Counter
item.DBNumber = 0
item.Start = 0
item.Amount = 8
item.pdata = data.data
items[#items + 1] = item
datas[#datas + 1] = data

for i, v in ipairs(items) do
	print("Item"..i, v.Result)
	print(basexx.to_hex(datas[i]:str(16)))
end

local ret = client:ReadMultiVars(items, 5)
print('ReadMultiVars', ret)

for i, v in ipairs(items) do
	print("Item"..i, v.Result)
	if v.Result == 0 then
		print(basexx.to_hex(datas[i]:str(16)))
	end
end

print(client:Disconnect())
print(client:LastError())
print(client:Connected())

