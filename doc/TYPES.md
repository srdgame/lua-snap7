# OPCUA Types

## Contents
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

#### Constructor
Default public constructor

#### Member variables

* Area (int)
* DBNumber (int)
* Start (int)
* Size (int)
* WordLen (int)

#### Methods

N/A


### TS7DataItem

#### Constructor
Default public constructor

#### Member variables

* Area (int)
* WordLen (int)
* Result (int)
* DBNumber (int)
* Start (int)
* Amount (int)
* pdata (user data | void*)

#### Methods

N/A


### TS7BlocksList

#### Constructor
Default public constructor

#### Member variables

* OBCount (int)
* FBCount (int)
* FCCount (int)
* SFBCount (int)
* SFCCount (int)
* DBCount (int)
* SDBCount (int)

#### Methods

N/A


### TS7BlockInfo

#### Constructor
Default public constructor

#### Member variables

* BlkType (int)
* BlkNumber (int)
* BlkLang (int)
* BlkFlags (int)
* MC7Size (int)
* LoadSize (int)
* LocalData (int)
* SBBLength (int)
* CheckSum (int)
* Version (int)
* CodeDate (char[11])
* IntfDate (char[11])
* Author (char[9])
* Family (char[9])
* Header (char[9])

#### Methods

N/A


### TS7OrderCode

#### Constructor
Default public constructor

#### Member variables

* Code (char[21])
* V1 (uint8_t)
* V2 (uint8_t)
* V3 (uint8_t)

#### Methods

N/A


### TS7CpuInfo

#### Constructor
Default public constructor

#### Member variables

* ModudeTypeName (char[33])
* SerialNumber (char[25])
* ASName (char[25])
* Copyright (char[27])
* ModuleName (char[25])

#### Methods

N/A


### TS7CpInfo

#### Constructor
Default public constructor

#### Member variables

* MaxPduLength (int)
* MaxConnections (int)
* MaxMpiRate (int)
* MaxBusRate (int)

#### Methods

N/A


### SZL_HEADER

#### Constructor
Default public constructor

#### Member variables

* LENGTHDR (uint16_t)
* N_DR (uint16_t)

#### Methods

N/A


### TS7SZL

#### Constructor
Default public constructor

#### Member variables

* Header (SZL_HEADER)
* Data (char[0x4000 - 4])
* Size (readonly size_t)

#### Methods

N/A


### TS7SZLList

#### Constructor
Default public constructor

#### Member variables

* Header (SZL_HEADER)
* Data (uing16_t[0x2000 - 2])

#### Methods

N/A


### TS7Protection

#### Constructor
Default public constructor

#### Member variables

* sch_schal (uint16_t)
* sch_par (uint16_t)
* sch_rel (uint16_t)
* bart_sch (uint16_t)
* anl_sch (uint16_t)

#### Methods

N/A


### UserData

#### Constructor

* new(number)
Create new user data object with required length.

* new(string, int)
Create new user data object with string context and specified length.

#### Member variables

* data (user data | void *)
* str (string | readonly)

#### Methods

N/A


### IntData

#### Constructor

* new(number)
Create new integer object default value.

#### Member variables

* ptr (integer pointer | int *)
* value (integer | readonly)

#### Methods

N/A
