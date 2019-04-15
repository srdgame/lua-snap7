#include <iostream>

#include "module_inc.h"

namespace lua_module {

void reg_module_client(sol::table& module) {
	module.new_usertype<TS7Client>("TS7Client",
		sol::constructors<TS7Client()>(),
		"Connect", &TS7Client::Connect,
		"ConnectTo", &TS7Client::ConnectTo,
		"SetConnectionParams", &TS7Client::SetConnectionParams,
		"SetConnectionType", &TS7Client::SetConnectionType,
		"Disconnect", &TS7Client::Disconnect,
		"GetParam", &TS7Client::GetParam,
		"SetParam", &TS7Client::SetParam,
		"ReadArea", &TS7Client::ReadArea,
		"WriteArea", &TS7Client::WriteArea,
		"ReadMultiVars", [](TS7Client& client, const sol::as_table_t<std::vector<TS7DataItem> > items, int count) {
			auto list = items.source;
			/*
			printf("ReadMultiVars[in wrapper] %d %s\n", list.size(), typeid(list[0]).name());
			int r = client.ReadMultiVars(&list[0], count);
			printf("ReadMultiVars[in wrapper] %d\n", r);
			return r;
			*/
			return client.ReadMultiVars(&list[0], count);
		},
		"WriteMultiVars", [](TS7Client& client, const sol::as_table_t<std::vector<TS7DataItem> > items, int count) {
			auto list = items.source;
			return client.WriteMultiVars(&list[0], count);
		},
		"DBRead", &TS7Client::DBRead,
		"DBWrite", &TS7Client::DBWrite,
		"MBRead", &TS7Client::MBRead,
		"MBWrite", &TS7Client::MBWrite,
		"EBRead", &TS7Client::EBRead,
		"EBWrite", &TS7Client::EBWrite,
		"ABRead", &TS7Client::ABRead,
		"ABWrite", &TS7Client::ABWrite,
		"TMRead", &TS7Client::TMRead,
		"TMWrite", &TS7Client::TMWrite,
		"CTRead", &TS7Client::CTRead,
		"CTWrite", &TS7Client::CTWrite,
		"TM2Read", &TS7Client::TM2Read,
		"TM2Write", &TS7Client::TM2Write,
		"CT2Read", &TS7Client::CT2Read,
		"CT2Write", &TS7Client::CT2Write,
		"ListBlocks", &TS7Client::ListBlocks,
		"GetAgBlockInfo", &TS7Client::GetAgBlockInfo,
		"GetPgBlockInfo", &TS7Client::GetPgBlockInfo,
		"ListBlocksOfType", &TS7Client::ListBlocksOfType,
		"Upload", &TS7Client::Upload,
		"FullUpload", &TS7Client::FullUpload,
		"Download", &TS7Client::Download,
		"Delete", &TS7Client::Delete,
		"DBGet", &TS7Client::DBGet,
		"DBFill", &TS7Client::DBFill,
		"GetPlcDateTime", &TS7Client::GetPlcDateTime,
		"SetPlcDateTime", &TS7Client::SetPlcDateTime,
		"SetPlcSystemDateTime", &TS7Client::SetPlcSystemDateTime,
		"GetOrderCode", &TS7Client::GetOrderCode,
		"GetCpuInfo", &TS7Client::GetCpuInfo,
		"GetCpInfo", &TS7Client::GetCpInfo,
		"ReadSZL", &TS7Client::ReadSZL,
		"ReadSZLList", &TS7Client::ReadSZLList,
		"PlcHotStart", &TS7Client::PlcHotStart,
		"PlcColdStart", &TS7Client::PlcColdStart,
		"PlcStop", &TS7Client::PlcStop,
		"CopyRamToRom", &TS7Client::CopyRamToRom,
		"Compress", &TS7Client::Compress,
		"GetProtection", &TS7Client::GetProtection,
		"SetSessionPassword", &TS7Client::SetSessionPassword,
		"ClearSessionPassword", &TS7Client::ClearSessionPassword,
		"ExecTime", &TS7Client::ExecTime,
		"LastError", &TS7Client::LastError,
		"PDURequested", &TS7Client::PDURequested,
		"PDULength", &TS7Client::PDULength,
		"PlcStatus", &TS7Client::PlcStatus,
		"Connected", &TS7Client::Connected /*,
		"SetAsCallback", &TS7Client::SetAsCallback,
		"CheckAsCompletion", &TS7Client::CheckAsCompletion,
		"WaitAsCompletion", &TS7Client::WaitAsCompletion,
		"AsReadArea", &TS7Client::AsReadArea,
		"AsWriteArea", &TS7Client::AsWriteArea,
		"AsListBlocksOfType", &TS7Client::AsListBlocksOfType,
		"AsReadSZL", &TS7Client::AsReadSZL,
		"AsReadSZLList", &TS7Client::AsReadSZLList,
		"AsUpload", &TS7Client::AsUpload,
		"AsFullUpload", &TS7Client::AsFullUpload,
		"AsDownload", &TS7Client::AsDownload,
		"AsCopyRamToRom", &TS7Client::AsCopyRamToRom,
		"AsCompress", &TS7Client::AsCompress,
		"AsDBRead", &TS7Client::AsDBRead,
		"AsDBWrite", &TS7Client::AsDBWrite,
		"AsMBRead", &TS7Client::AsMBRead,
		"AsMBWrite", &TS7Client::AsMBWrite,
		"AsEBRead", &TS7Client::AsEBRead,
		"AsEBWrite", &TS7Client::AsEBWrite,
		"AsABRead", &TS7Client::AsABRead,
		"AsABWrite", &TS7Client::AsABWrite,
		"AsTMRead", &TS7Client::AsTMRead,
		"AsTMWrite", &TS7Client::AsTMWrite,
		"AsCTRead", &TS7Client::AsCTRead,
		"AsCTWrite", &TS7Client::AsCTWrite,
		"AsTM2Read", &TS7Client::AsTM2Read,
		"AsTM2Write", &TS7Client::AsTM2Write,
		"AsCT2Read", &TS7Client::AsCT2Read,
		"AsCT2Write", &TS7Client::AsCT2Write,
		"AsDBGet", &TS7Client::AsDBGet,
		"AsDBFill", &TS7Client::AsDBFill
		*/
	);

}

}
