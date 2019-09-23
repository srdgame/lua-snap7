# OPCUA 基础类型

## 目录
* [TS7Tag](#ts7tag)
* [TS7DataItem](#ts7dataitem)
* [TS7BlocksList](#ts7blockslist)
* [TS7BlockInfo](#ts7blockinfo)
* [TS7OrderCode](#ts7ordercode)
* [TS7CpuInfo](#ts7cpuinfo)
* [TS7CpInfo](#ts7cpinfo)
* [SZL_HEADER](#szl_header)
* [TS7SZL](#ts7szl)
* [TS7SZLList](#ts7szllist)
* [TS7Protection](#ts7protection)
* [UserData](#userdata)
* [IntData](#intdata)

### TS7Tag

Snap7 数据点对象

#### 构造函数

默认的构造函数

#### 成员变量

* Area (int) <br> 数据区域
* DBNumber (int) <br> 数据区编号
* Start (int) <br> 数据开始地址
* Size (int) <br> 数据长度
* WordLen (int) <br> 字长

#### 成员方法

N/A

### TS7DataItem

数据项对象

#### 构造函数

默认的构造函数

#### 成员变量

* Area (int) <br> 数据区域
* WordLen (int) <br> 字长
* Result (int) <br> 数据项结果
* DBNumber (int) <br> 数据区编号
* Start (int) <br> 数据开始地址
* Amount (int) <br> 数据数量
* pdata (user data | void*) <br> 数据

#### 成员方法

N/A


### TS7BlocksList

数据块列表

#### 构造函数

默认的构造函数


#### 成员变量

* OBCount (int) <br> OB块数量
* FBCount (int) <br> FB块数量
* FCCount (int) <br> FCC块数量
* SFBCount (int) <br> SFB块数量
* SFCCount (int) <br> SFC块数量
* DBCount (int) <br> DB块数量
* SDBCount (int) <br> SDB块数量

#### 成员方法

N/A


### TS7BlockInfo

数据块信息

#### 构造函数

默认的构造函数

#### 成员变量

* BlkType (int) <br> 块类型
* BlkNumber (int) <br> 块序号
* BlkLang (int) <br> 块语言
* BlkFlags (int) <br> 块标志
* MC7Size (int) <br> 真实数据长度(bytes)
* LoadSize (int) <br> 内存加载大小
* LocalData (int) <br> 本地数据
* SBBLength (int) <br> SBB 长度
* CheckSum (int) <br> 校验码
* Version (int) <br> 版本
* CodeDate (char[11]) <br> 代码日期
* IntfDate (char[11]) <br> 接口日期
* Author (char[9]) <br> 作者
* Family (char[9]) <br> Family
* Header (char[9]) <br> 头信息

#### 成员方法

N/A


### TS7OrderCode

#### 构造函数

默认的构造函数

#### 成员变量

* Code (char[21]) <br> 代码名称
* V1 (uint8_t)
* V2 (uint8_t)
* V3 (uint8_t)

#### 成员方法

N/A


### TS7CpuInfo

CPU信息

#### 构造函数

默认的构造函数

#### 成员变量

* ModudeTypeName (char[33]) <br> 模块类型名称
* SerialNumber (char[25]) <br> 序列号
* ASName (char[25]) <br> AS名称
* Copyright (char[27]) <br> Copyright信息
* ModuleName (char[25]) <br> 模块名称

#### 成员方法

N/A


### TS7CpInfo

#### 构造函数

默认的构造函数

#### 成员变量

* MaxPduLength (int) <br> 最大PDU长度
* MaxConnections (int) <br> 最大连接数量
* MaxMpiRate (int) <br> 最大MPI比率
* MaxBusRate (int) <br> 最大BUS比率

#### 成员方法

N/A


### SZL_HEADER

#### 构造函数

默认的构造函数

#### 成员变量

* LENGTHDR (uint16_t) <br> 头部长度
* N_DR (uint16_t) <br> N-DR

#### 成员方法

N/A


### TS7SZL

SZL 数据

#### 构造函数

默认的构造函数

#### 成员变量

* Header (SZL_HEADER) <br> 头信息
* Data (char[0x4000 - 4]) <br> 数据
* Size (readonly size_t) <br> 数据长度

#### 成员方法

N/A


### TS7SZLList

SZL 数据链表

#### 构造函数

默认的构造函数

#### 成员变量

* Header (SZL_HEADER) <br> 头信息
* Data (uing16_t[0x2000 - 2]) <br> 数据

#### 成员方法

N/A


### TS7Protection

#### 构造函数

默认的构造函数

#### 成员变量

* sch_schal (uint16_t)
* sch_par (uint16_t)
* sch_rel (uint16_t)
* bart_sch (uint16_t)
* anl_sch (uint16_t)

#### 成员方法

N/A


### UserData

#### 构造函数

* new(length | integer)
构造指定长度的C用户数据

* new(data | string, length | integer)
构造指定长度的C用户数据，数据从指定的字符串获取

#### 成员变量

* data <br> 获取C数据对象(不可被lua解析使用)

#### 成员方法

* str(size | integer)

将数据转化成为字符串数据，从而使用lua进行数据处理。 指定数据长度。

``` lua
	local str = data:str(16)
```


### IntData

#### 构造函数

* new(number)
构造C语言int数据对象

#### 成员变量

* ptr <br> 获取int数据指针
* value <br> 获取整数数值

#### 成员方法

N/A
