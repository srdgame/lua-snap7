#include <iomanip>
//#include <iostream>

#include "module_inc.h"

namespace lua_module {

/*
std::string toString(const UA_Guid& guid) {
	std::stringstream ss;
	ss << std::hex << std::setw(8) <<std::setfill('0')  << guid.data1;
	ss << std::hex << std::setw(4) <<std::setfill('0')  << guid.data2;
	ss << std::hex << std::setw(4) <<std::setfill('0')  << guid.data4;
	return ss.str();
}
*/

std::string TS7Tag_toString(const TS7Tag& tag) {
	std::stringstream ss;
	ss << "TS7Tag(Area=" << tag.Area;
	ss << ";DBNumber=" << tag.DBNumber;
	ss << ";Start=" << tag.Start;
	ss << ";Size=" << tag.Size;
	ss << ";WordLen=" << tag.WordLen << ")";
	return ss.str();
}

std::string TS7DataItem_toString(const TS7DataItem& tag) {
	std::stringstream ss;
	ss << "TS7DataItem(Area=" << tag.Area;
	ss << ";WordLen=" << tag.WordLen;
	ss << ";Result=" << tag.Result;
	ss << ";DBNumber=" << tag.DBNumber;
	ss << ";Start=" << tag.Start;
	ss << ";Amount=" << tag.Amount;
	ss << ";pdata=" << tag.pdata << ")";
	return ss.str();
}

#define MAP_CHAR_SIZE(TN, PN, SIZE) \
	#PN, sol::property([](TN& obj) { \
			char temp[SIZE + 1]; \
			memset(temp, 0, SIZE + 1); \
			memcpy(temp, obj.PN, SIZE); \
			return std::string(temp); \
		}, \
		[](TN& obj, const char* val) { \
			memcpy(obj.PN, val, SIZE); \
		})

#define MAP_DATA_SIZE(TN, PN, SIZE) \
	#PN, sol::property([](TN& obj) { \
			char temp[SIZE + 1]; \
			memset(temp, 0, SIZE + 1); \
			memcpy(temp, obj.PN, SIZE); \
			return std::string(temp, SIZE); \
		}, \
		[](TN& obj, const char* val) { \
			memcpy(obj.PN, val, SIZE); \
		})


void reg_module_types(sol::table& module) {
	module.new_usertype<TS7Tag>("TS7Tag",
		"__tostring", [](const TS7Tag& tag) { return TS7Tag_toString(tag); },
		"Area", &TS7Tag::Area,
		"DBNumber", &TS7Tag::DBNumber,
		"Start", &TS7Tag::Start,
		"Size", &TS7Tag::Size,
		"WordLen", &TS7Tag::WordLen
	);

	module.new_usertype<TS7DataItem>("TS7DataItem",
		"__tostring", [](const TS7DataItem& item) { return TS7DataItem_toString(item); },
		"Area", &TS7DataItem::Area,
		"WordLen", &TS7DataItem::WordLen,
		"Result", &TS7DataItem::Result,
		"DBNumber", &TS7DataItem::DBNumber,
		"Start", &TS7DataItem::Start,
		"Amount", &TS7DataItem::Amount,
		"pdata", &TS7DataItem::pdata
	);

	module.new_usertype<TS7BlocksList>("TS7BlocksList",
		"OBCount", &TS7BlocksList::OBCount,
		"FBCount", &TS7BlocksList::FBCount,
		"FCCount", &TS7BlocksList::FCCount,
		"SFBCount", &TS7BlocksList::SFBCount,
		"SFCCount", &TS7BlocksList::SFCCount,
		"DBCount", &TS7BlocksList::DBCount,
		"SDBCount", &TS7BlocksList::SDBCount
	);

	module.new_usertype<TS7BlockInfo>("TS7BlockInfo",
		"BlkType", &TS7BlockInfo::BlkType,
		"BlkNumber", &TS7BlockInfo::BlkNumber,
		"BlkLang", &TS7BlockInfo::BlkLang,
		"BlkFlags", &TS7BlockInfo::BlkFlags,
		"MC7Size", &TS7BlockInfo::MC7Size,
		"LoadSize", &TS7BlockInfo::LoadSize,
		"LocalData", &TS7BlockInfo::LocalData,
		"SBBLength", &TS7BlockInfo::SBBLength,
		"CheckSum", &TS7BlockInfo::CheckSum,
		"Version", &TS7BlockInfo::Version,
		MAP_CHAR_SIZE(TS7BlockInfo, CodeDate, 11),
		MAP_CHAR_SIZE(TS7BlockInfo, IntfDate, 11),
		MAP_CHAR_SIZE(TS7BlockInfo, Author, 9),
		MAP_CHAR_SIZE(TS7BlockInfo, Family, 9),
		MAP_CHAR_SIZE(TS7BlockInfo, Header, 9)
	);

	module.new_usertype<TS7OrderCode>("TS7OrderCode",
		MAP_CHAR_SIZE(TS7OrderCode, Code, 21),
		"V1", &TS7OrderCode::V1,
		"V2", &TS7OrderCode::V2,
		"V3", &TS7OrderCode::V3
	);

	module.new_usertype<TS7CpuInfo>("TS7CpuInfo",
		MAP_CHAR_SIZE(TS7CpuInfo, ModuleTypeName, 33),
		MAP_CHAR_SIZE(TS7CpuInfo, SerialNumber, 25),
		MAP_CHAR_SIZE(TS7CpuInfo, ASName, 25),
		MAP_CHAR_SIZE(TS7CpuInfo, Copyright, 27),
		MAP_CHAR_SIZE(TS7CpuInfo, ModuleName, 25)
	);

	module.new_usertype<TS7CpInfo>("TS7CpInfo",
		"MaxPduLength", &TS7CpInfo::MaxPduLengt,
		"MaxConnections", &TS7CpInfo::MaxConnections,
		"MaxMpiRate", &TS7CpInfo::MaxMpiRate,
		"MaxBusRate", &TS7CpInfo::MaxBusRate
	);

	module.new_usertype<SZL_HEADER>("SZL_HEADER",
		"LENTHDR", &SZL_HEADER::LENTHDR,
		"N_DR", &SZL_HEADER::N_DR
	);

	module.new_usertype<TS7SZL>("TS7SZL",
		"Header", &TS7SZL::Header,
		MAP_DATA_SIZE(TS7SZL, Data, 0x4000-4),
		"Size", sol::property(
			[](TS7SZL& obj) {
				return sizeof(obj);
			})
	);

	module.new_usertype<TS7SZLList>("TS7SZLList",
		"Header", &TS7SZLList::Header,
		MAP_DATA_SIZE(TS7SZLList, List, 0x2000-2)
	);

	module.new_usertype<TS7Protection>("TS7Protection",
		"sch_schal", &TS7Protection::sch_schal,
		"sch_par", &TS7Protection::sch_par,
		"sch_rel", &TS7Protection::sch_rel,
		"bart_sch", &TS7Protection::bart_sch,
		"anl_sch", &TS7Protection::anl_sch
	);

	struct UserData {
		void* data;
		UserData(int size) {
			data = malloc(sizeof(char) * size);
			memset(data, 0, size);
		}
		UserData(const char* src, int size) {
			data = malloc(sizeof(char) * (size + 1));
			memset(data, 0, size + 1);
			memcpy(data, src, size);
		}
		~UserData() {
			free(data);
		}
		std::string str(int size) {
			return std::string((char*)data, size);
		}
	private:
		UserData(const UserData& that);
		UserData& operator=(const UserData& that);
	};

	module.new_usertype<UserData>("UserData",
		sol::constructors<UserData(int), UserData(const char*, int)>(),
		"data", &UserData::data,
		"str", &UserData::str
	);

	struct IntData {
		int value;
		IntData(int val) : value(val) {
		}
		operator int* () {
			return &value;
		}
	};
	module.new_usertype<IntData>("IntData",
		sol::constructors<IntData(int)>(),
		"value", &IntData::value,
		"ptr", sol::property([](IntData& obj) { return &obj.value; })
	);

}

}
