# Snap7 Client class

More function description read from [here](http://snap7.sourceforge.net/snap7_api_ref.html)


## Constructors

Default constructor function

## Member Variables

N/A

## Methods

#### Connection functions

* Connect
> Connects a Client Object to a PLC with implicit parameters.

_function prototype_
``` c
    int Connect();
```

* ConnectTo
> Connects a Client Object to a PLC.

_function prototype_
``` c
    int ConnectTo(const char *RemAddress, int Rack, int Slot);
```

* SetConnectionParams
> Sets IP, Local and Remote TSAP

_function prototype_
``` c
    int SetConnectionParams(const char *RemAddress, word LocalTSAP, word RemoteTSAP);
```

* SetConnectionType
> Set the connection type (PG/OP/S7 Basic)

_function prototype_
``` c
    int SetConnectionType(word ConnectionType);
```

* Disconnect
> Disconnects a Client.

_function prototype_
``` c
    int Disconnect();
```

* GetParam
> Reads an internal Client parameter.

_function prototype_
``` c
    int GetParam(int ParamNumber, void *pValue);
```

* SetParam
> Writes an internal Client Parameter.

_function prototype_
``` c
    int SetParam(int ParamNumber, void *pValue);
```

#### Data I/O Main functions

* ReadArea
> Reads a data area from a PLC.

_function prototype_
``` c
    int ReadArea(int Area, int DBNumber, int Start, int Amount, int WordLen, void *pUsrData);
```

* WriteArea
> Writes a data area into a PLC.

_function prototype_
``` c
    int WriteArea(int Area, int DBNumber, int Start, int Amount, int WordLen, void *pUsrData);
```

* ReadMultiVars
> Reads different kind of variables from a PLC simultaneously.

_function prototype_
``` c
    int ReadMultiVars(PS7DataItem Item, int ItemsCount);
```

* WriteMultiVars
> Writes different kind of variables into a PLC simultaneously.

_function prototype_
``` c
    int WriteMultiVars(PS7DataItem Item, int ItemsCount);
```

#### Data I/O Lean functions

* DBRead
> Reads a part of a DB from a PLC.

_function prototype_
``` c
    int DBRead(int DBNumber, int Start, int Size, void *pUsrData);
```

* DBWrite
> Writes a part of a DB into a PLC.

_function prototype_
``` c
    int DBWrite(int DBNumber, int Start, int Size, void *pUsrData);
```

* MBRead
> Reads a part of Merkers area from a PLC.

_function prototype_
``` c
    int MBRead(int Start, int Size, void *pUsrData);
```

* MBWrite
> Writes a part of Merkers area into a PLC.

_function prototype_
``` c
    int MBWrite(int Start, int Size, void *pUsrData);
```

* EBRead
> Reads a part of IPI area from a PLC.

_function prototype_
``` c
    int EBRead(int Start, int Size, void *pUsrData);
```

* EBWrite
> Writes a part of IPI area into a PLC.

_function prototype_
``` c
    int EBWrite(int Start, int Size, void *pUsrData);
```

* ABRead
> Reads a part of IPU area from a PLC.

_function prototype_
``` c
    int ABRead(int Start, int Size, void *pUsrData);
```

* ABWrite
> Writes a part of IPU area into a PLC.

_function prototype_
``` c
    int ABWrite(int Start, int Size, void *pUsrData);
```

* TMRead
> Reads timers from a PLC.

_function prototype_
``` c
    int TMRead(int Start, int Amount, void *pUsrData);
```

* TMWrite
> Write timers into a PLC.

_function prototype_
``` c
    int TMWrite(int Start, int Amount, void *pUsrData);
```

* CTRead
> Reads counters from a PLC.

_function prototype_
``` c
    int CTRead(int Start, int Amount, void *pUsrData);
```

* CTWrite
> Write counters into a PLC.

_function prototype_
``` c
    int CTWrite(int Start, int Amount, void *pUsrData);
```

#### Directory functions

* ListBlocks
> Returns the AG blocks amount divided by type.

_function prototype_
``` c
    int ListBlocks(PS7BlocksList pUsrData);
```

* GetAgBlockInfo
> Returns detailed information about a block present in AG.

_function prototype_
``` c
    int GetAgBlockInfo(int BlockType, int BlockNum, PS7BlockInfo pUsrData);
```

* GetPgBlockInfo
> Returns detailed information about a block loaded in memory.

_function prototype_
``` c
    int GetPgBlockInfo(void *pBlock, PS7BlockInfo pUsrData, int Size);
```

* ListBlocksOfType
> Returns the AG blocks list of a given type.

_function prototype_
``` c
    int ListBlocksOfType(int BlockType, TS7BlocksOfType *pUsrData, int *ItemsCount);
```

#### Blocks functions

* Upload
> Uploads a block from AG.

_function prototype_
``` c
    int Upload(int BlockType, int BlockNum, void *pUsrData, int *Size);
```

* FullUpload
> Uploads a block from AG with Header and Footer infos.

_function prototype_
``` c
    int FullUpload(int BlockType, int BlockNum, void *pUsrData, int *Size);
```

* Download
> Download a block into AG.

_function prototype_
``` c
    int Download(int BlockNum, void *pUsrData, int Size);
```

* Delete
> Delete a block into AG.

_function prototype_
``` c
    int Delete(int BlockType, int BlockNum);
```

* DBGet
> Uploads a DB from AG using DBRead.

_function prototype_
``` c
    int DBGet(int DBNumber, void *pUsrData, int *Size);
```

* DBFill
> Fills a DB in AG with a given byte.

_function prototype_
``` c
    int DBFill(int DBNumber, int FillChar);
```

#### Date/Time functions

* GetPlcDateTime
> Returns the PLC date/time.

_function prototype_
``` c
    int GetPlcDateTime(tm *DateTime);
```

* SetPlcDateTime
> Sets the PLC date/time with a given value.

_function prototype_
``` c
    int SetPlcDateTime(tm *DateTime);
```

* SetPlcSystemDateTime
> Sets the PLC date/time with the host (PC) date/time.

_function prototype_
``` c
    int SetPlcSystemDateTime();
```

#### System Info functions

* GetOrderCode
> Returns the CPU order code.

_function prototype_
``` c
    int GetOrderCode(PS7OrderCode pUsrData);
```

* GetCpuInfo
> Returns some information about the AG.

_function prototype_
``` c
    int GetCpuInfo(PS7CpuInfo pUsrData);
```

* GetCpInfo
> Returns some information about the CP (communication processor).

_function prototype_
``` c
    int GetCpInfo(PS7CpInfo pUsrData);
```

* ReadSZL
> Reads a partial list of given ID and Index.

_function prototype_
``` c
	int ReadSZL(int ID, int Index, PS7SZL pUsrData, int *Size);
```

* ReadSZLList
> Reads the list of partial lists available in the CPU.

_function prototype_
``` c
	int ReadSZLList(PS7SZLList pUsrData, int *ItemsCount);
```

#### Control functions

* PlcHotStart
> Puts the CPU in RUN mode performing an HOT START.

_function prototype_
``` c
	int PlcHotStart();
```

* PlcColdStart
> Puts the CPU in RUN mode performing a COLD START.

_function prototype_
``` c
	int PlcColdStart();
```

* PlcStop
> Puts the CPU in STOP mode.

_function prototype_
``` c
	int PlcStop();
```

* CopyRamToRom
> Performs the Copy Ram to Rom action.

_function prototype_
``` c
	int CopyRamToRom(int Timeout);
```

* Compress
> Performs the Compress action.

_function prototype_
``` c
	int Compress(int Timeout);
```

#### Security functions

* GetProtection
> Gets the CPU protection level info.

_function prototype_
``` c
	int GetProtection(PS7Protection pUsrData);
```

* SetSessionPassword
> Send the password to the PLC to meet its security level.

_function prototype_
``` c
	int SetSessionPassword(char *Password);
```

* ClearSessionPassword
> Clears the password set for the current session (logout).

_function prototype_
``` c
	int ClearSessionPassword();
```

#### Properties

* ExecTime
> Returns the last job execution time in milliseconds.

_function prototype_
``` c
	int ExecTime();
```

* LastError
> Returns the last job result.

_function prototype_
``` c
	int LastError();
```

* PDURequested
> Returns info about the PDU length (requested).

_function prototype_
``` c
	int PDURequested();
```

* PDULength
> Returns info about the PDU length (negotiated).

_function prototype_
``` c
	int PDULength();
```

* PlcStatus
> Returns the CPU status (running/stopped).

_function prototype_
``` c
	int PlcStatus();
```

* Connected
> Returns the connection state.

_function prototype_
``` c
	bool Connected();
```

