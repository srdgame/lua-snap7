
#include "module_inc.h"
#include "module_enums.hpp"
#include "module_types.hpp"
#include "module_client.hpp"
//#include "module_server.hpp"

namespace lua_module {
	sol::table open_module(sol::this_state L) {
		sol::state_view lua(L);
		sol::table module = lua.create_table();

		reg_module_enums(module);
		reg_module_types(module);
		reg_module_client(module);
		//reg_module_server(module);

		module.set_function("CliErrorText", CliErrorText);
		module.set_function("SrvErrorText", SrvErrorText);
		module.set_function("ParErrorText", ParErrorText);
		module.set_function("SrvEventText", SrvEventText);

		return module;
	}
}

extern "C" int luaopen_snap7(lua_State *L) {
	return sol::stack::call_lua(L, 1, lua_module::open_module);
}
