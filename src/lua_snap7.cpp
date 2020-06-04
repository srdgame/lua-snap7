
#include "module_inc.h"

#define SNAP7_VERSION 1.41

namespace lua_module {
	void reg_module_enums(sol::table& module);
	void reg_module_types(sol::table& module);
	void reg_module_client(sol::table& module);
	void reg_module_server(sol::table& module);
	sol::table open_module(sol::this_state L) {
		sol::state_view lua(L);
		sol::table module = lua.create_table();

		reg_module_enums(module);
		reg_module_types(module);
		reg_module_client(module);
		reg_module_server(module);

		module.set_function("CliErrorText", [](int err) { return CliErrorText(err); });
		module.set_function("SrvErrorText", [](int err) { return SrvErrorText(err); });
		module.set_function("ParErrorText", [](int err) { return ParErrorText(err); });
		module.set_function("SrvEventText", [](TSrvEvent *Event) { return SrvEventText(Event); });

		/**
		 * Module version
		 */
		module["VERSION"] = SNAP7_VERSION;

		return module;
	}
}

extern "C" int luaopen_snap7(lua_State *L) {
	return sol::stack::call_lua(L, 1, lua_module::open_module);
}
