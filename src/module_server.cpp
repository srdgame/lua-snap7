#include <iostream>

#include "module_inc.h"

namespace lua_module {

void reg_module_server(sol::table& module) {
	module.new_usertype<TS7Server>("TS7Server",
		sol::constructors<TS7Server()>(),
		// Control
		"Start", &TS7Server::Start,
		"StartTo", &TS7Server::StartTo,
		"Stop", &TS7Server::Stop,
		"GetParam", &TS7Server::GetParam,
		"SetParam", &TS7Server::SetParam,
		// Events
		//"SetEventsCallback", &TS7Server::SetEventsCallback, //int SetEventsCallback(pfn_SrvCallBack PCallBack, void *UsrPtr);
		//"SetReadEventsCallback", &TS7Server::SetReadEventsCallback, //int SetReadEventsCallback(pfn_SrvCallBack PCallBack, void *UsrPtr);
		//"SetRWAreaCallback", &TS7Server::SetRWAreaCallback, //int SetRWAreaCallback(pfn_RWAreaCallBack PCallBack, void *UsrPtr);
		"PickEvent", &TS7Server::PickEvent, //bool PickEvent(TSrvEvent *pEvent);
		"ClearEvents", &TS7Server::ClearEvents, //void ClearEvents();
		"GetEventsMask", &TS7Server::GetEventsMask, //longword GetEventsMask();
		"GetLogMask", &TS7Server::GetLogMask, //longword GetLogMask();
		"SetEventsMask", &TS7Server::SetEventsMask, //void SetEventsMask(longword Mask);
		"SetLogMask", &TS7Server::SetLogMask, //void SetLogMask(longword Mask);
		// Resources
		"RegisterArea", &TS7Server::RegisterArea, //int RegisterArea(int AreaCode, word Index, void *pUsrData, word Size);
		"UnregisterArea", &TS7Server::UnregisterArea, //int UnregisterArea(int AreaCode, word Index);
		"LockArea", &TS7Server::LockArea, //int LockArea(int AreaCode, word Index);
		"UnlockArea", &TS7Server::UnlockArea, //int UnlockArea(int AreaCode, word Index);
		// Properties
		"ServerStatus", &TS7Server::ServerStatus, //int ServerStatus();
		"GetCpuStatus", &TS7Server::GetCpuStatus, //int GetCpuStatus();
		"SetCpuStatus", &TS7Server::SetCpuStatus, //int SetCpuStatus(int Status);
		"ClientsCount", &TS7Server::ClientsCount //int ClientsCount();
	);
}

}
