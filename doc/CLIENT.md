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

``` c
    int Connect();
```

* ConnectTo
> Connects a Client Object to a PLC.

``` c
    int ConnectTo(const char *RemAddress, int Rack, int Slot);
```

* SetConnectionParams
> Sets IP, Local and Remote TSAP

``` c
    int SetConnectionParams(const char *RemAddress, word LocalTSAP, word RemoteTSAP);
```

* SetConnectionType
> Set the connection type (PG/OP/S7 Basic)

``` c
    int SetConnectionType(word ConnectionType);
```

* Disconnect
> Disconnects a Client.

``` c
    int Disconnect();
```

* GetParam
> Reads an internal Client parameter.

``` c
    int GetParam(int ParamNumber, void *pValue);
```

* SetParam
> Writes an internal Client Parameter.

``` c
    int SetParam(int ParamNumber, void *pValue);
```

#### Data I/O Main functions

* ReadArea
> Reads a data area from a PLC.

``` c
    int ReadArea(int Area, int DBNumber, int Start, int Amount, int WordLen, void *pUsrData);
```

* WriteArea
> Writes a data area into a PLC.

``` c
    int WriteArea(int Area, int DBNumber, int Start, int Amount, int WordLen, void *pUsrData);
```

* ReadMultiVars
> Reads different kind of variables from a PLC simultaneously.

``` c
    int ReadMultiVars(PS7DataItem Item, int ItemsCount);
```

* WriteMultiVars
> Writes different kind of variables into a PLC simultaneously.

``` c
    int WriteMultiVars(PS7DataItem Item, int ItemsCount);
```

#### Data I/O Lean functions

* DBRead
> Reads a part of a DB from a PLC.

``` c
    int DBRead(int DBNumber, int Start, int Size, void *pUsrData);
```

* DBWrite
> Writes a part of a DB into a PLC.

``` c
    int DBWrite(int DBNumber, int Start, int Size, void *pUsrData);
```

* MBRead
> Reads a part of Merkers area from a PLC.

``` c
    int MBRead(int Start, int Size, void *pUsrData);
```

* MBWrite
> Writes a part of Merkers area into a PLC.

``` c
    int MBWrite(int Start, int Size, void *pUsrData);
```

* EBRead
> Reads a part of IPI area from a PLC.

``` c
    int EBRead(int Start, int Size, void *pUsrData);
```

* EBWrite
> Writes a part of IPI area into a PLC.

``` c
    int EBWrite(int Start, int Size, void *pUsrData);
```

* ABRead
> Reads a part of IPU area from a PLC.

``` c
    int ABRead(int Start, int Size, void *pUsrData);
```

* ABWrite
> Writes a part of IPU area into a PLC.

``` c
    int ABWrite(int Start, int Size, void *pUsrData);
```

* TMRead
> Reads timers from a PLC.

``` c
    int TMRead(int Start, int Amount, void *pUsrData);
```

* TMWrite
> Write timers into a PLC.

``` c
    int TMWrite(int Start, int Amount, void *pUsrData);
```

* CTRead
> Reads counters from a PLC.

``` c
    int CTRead(int Start, int Amount, void *pUsrData);
```

* CTWrite
> Write counters into a PLC.

``` c
    int CTWrite(int Start, int Amount, void *pUsrData);
```

#### Directory functions

* ListBlocks
> Returns the AG blocks amount divided by type.

``` c
    int ListBlocks(PS7BlocksList pUsrData);
```

* GetAgBlockInfo
> Returns detailed information about a block present in AG.

``` c
    int GetAgBlockInfo(int BlockType, int BlockNum, PS7BlockInfo pUsrData);
```

* GetPgBlockInfo
> Returns detailed information about a block loaded in memory.

``` c
    int GetPgBlockInfo(void *pBlock, PS7BlockInfo pUsrData, int Size);
```

* ListBlocksOfType
> Returns the AG blocks list of a given type.

``` c
    int ListBlocksOfType(int BlockType, TS7BlocksOfType *pUsrData, int *ItemsCount);
```

#### Blocks functions

* Upload
> Uploads a block from AG.

``` c
    int Upload(int BlockType, int BlockNum, void *pUsrData, int *Size);
```

* FullUpload
> Uploads a block from AG with Header and Footer infos.

``` c
    int FullUpload(int BlockType, int BlockNum, void *pUsrData, int *Size);
```

* Download
> Download a block into AG.

``` c
    int Download(int BlockNum, void *pUsrData, int Size);
```

* Delete
> Delete a block into AG.

``` c
    int Delete(int BlockType, int BlockNum);
```

* DBGet
> Uploads a DB from AG using DBRead.

``` c
    int DBGet(int DBNumber, void *pUsrData, int *Size);
```

* DBFill
> Fills a DB in AG with a given byte.

``` c
    int DBFill(int DBNumber, int FillChar);
```

#### Date/Time functions

* GetPlcDateTime
> Returns the PLC date/time.

``` c
    int GetPlcDateTime(tm *DateTime);
```

* SetPlcDateTime
> Sets the PLC date/time with a given value.

``` c
    int SetPlcDateTime(tm *DateTime);
```

* SetPlcSystemDateTime
> Sets the PLC date/time with the host (PC) date/time.

``` c
    int SetPlcSystemDateTime();
```

#### System Info functions

* GetOrderCode
> Returns the CPU order code.

``` c
    int GetOrderCode(PS7OrderCode pUsrData);
```

* GetCpuInfo
> Returns some information about the AG.

``` c
    int GetCpuInfo(PS7CpuInfo pUsrData);
```

* GetCpInfo
> Returns some information about the CP (communication processor).

``` c
    int GetCpInfo(PS7CpInfo pUsrData);
```

* ReadSZL
> Reads a partial list of given ID and Index.

``` c
	int ReadSZL(int ID, int Index, PS7SZL pUsrData, int *Size);
```

* ReadSZLList
> Reads the list of partial lists available in the CPU.

``` c
	int ReadSZLList(PS7SZLList pUsrData, int *ItemsCount);
```

#### Control functions

* PlcHotStart
> Puts the CPU in RUN mode performing an HOT START.

``` c
	int PlcHotStart();
```

* PlcColdStart
> Puts the CPU in RUN mode performing a COLD START.

``` c
	int PlcColdStart();
```

* PlcStop
> Puts the CPU in STOP mode.

``` c
	int PlcStop();
```

* CopyRamToRom
> Performs the Copy Ram to Rom action.

``` c
	int CopyRamToRom(int Timeout);
```

* Compress
> Performs the Compress action.

``` c
	int Compress(int Timeout);
```

#### Security functions

* GetProtection
> Gets the CPU protection level info.

``` c
	int GetProtection(PS7Protection pUsrData);
```

* SetSessionPassword
> Send the password to the PLC to meet its security level.

``` c
	int SetSessionPassword(char *Password);
```

* ClearSessionPassword
> Clears the password set for the current session (logout).

``` c
	int ClearSessionPassword();
```

#### Properties

* ExecTime
> Returns the last job execution time in milliseconds.

``` c
	int ExecTime();
```

* LastError
> Returns the last job result.

``` c
	int LastError();
```

* PDURequested
> Returns info about the PDU length (requested).

``` c
	int PDURequested();
```

* PDULength
> Returns info about the PDU length (negotiated).

``` c
	int PDULength();
```

* PlcStatus
> Returns the CPU status (running/stopped).

``` c
	int PlcStatus();
```

* Connected
> Returns the connection state.

``` c
	bool Connected();
```

