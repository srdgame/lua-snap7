
#include "module_inc.h"

namespace lua_module {

void reg_module_enums(sol::table& module) {
	module.new_enum("errLib",
		"INVALID_PARAM", errLibInvalidParam,
		"INVALID_OBJECT", errLibInvalidObject
	);
	module.new_enum("S7CpuStatus",
		"UNKNOWN", S7CpuStatusUnknown, // 0x00
		"RUN", S7CpuStatusRun, // 0x08
		"STOP", S7CpuStatusStop // 0x04
	);
	module.new_enum("S7ServerStatus",
		"STOPED", 0,
		"RUNNING", 1,
		"ERROR", 2
	);
	module.new_enum("S7IsoErrors",
		"CONNECT", errIsoConnect, // Connection error
		"DISCONNECT", errIsoDisconnect, // Disconnect error
		"INVALID_PDU", errIsoInvalidPDU, // Bad format
		"INVALID_DATASIZE", errIsoInvalidDataSize, // Bad Datasize passed to send/recv buffer is invalid
		"NULL_POINTER", errIsoNullPointer, // Null passed as pointer
		"SHORT_PACKET", errIsoShortPacket, // A short packet received
		"TOO_MANY_FRAGMENTS", errIsoTooManyFragments, // Too many packets without EoT flag
		"PDU_OVERFLOW", errIsoPduOverflow, // The sum of fragments data exceded maximum packet size
		"SEND_PACKET", errIsoSendPacket, // An error occurred during send
		"RECV_PACKET", errIsoRecvPacket, // An error occurred during recv
		"INVALID_PARAMS", errIsoInvalidParams, // Invalid TSAP params
		"RESVD_1", errIsoResvd_1, // Unassigned
		"RESVD_2", errIsoResvd_2, // Unassigned
		"RESVD_3", errIsoResvd_3, // Unassigned
		"RESVD_4", errIsoResvd_4 // Unassigned
	);
	module.new_enum("ParamList",
		"LOCAL_PORT", p_u16_LocalPort,
		"REMOTE_PORT", p_u16_RemotePort,
		"PING_TIMEOUT", p_i32_PingTimeout,
		"SEND_TIMEOUT", p_i32_SendTimeout,
		"RECV_TIMEOUT", p_i32_RecvTimeout,
		"WORK_INTERNAL", p_i32_WorkInterval,
		"SRC_REF", p_u16_SrcRef,
		"DST_REF", p_u16_DstRef,
		"SRC_TSAP", p_u16_SrcTSap,
		"PDU_REQUEST", p_i32_PDURequest,
		"MAX_CLIENTS", p_i32_MaxClients,
		"BSEND_TIMEOUT", p_i32_BSendTimeout,
		"BRECV_TIMEOUT", p_i32_BRecvTimeout,
		"RECOVERY_TIME", p_u32_RecoveryTime,
		"KEEP_ALIVE", p_u32_KeepAliveTime
	);

	module.new_enum("JobStatus",
		"COMPLETE", JobComplete,
		"PENDING", JobPending
	);

	module.new_enum("CliErrorCode",
		"NEGOTIATING_PDU", errNegotiatingPDU,
		"INVALID_PARAMS", errCliInvalidParams,
		"JOB_PENDING", errCliJobPending,
		"TOO_MANY_ITEMS", errCliTooManyItems,
		"INVALID_WORD_LEN", errCliInvalidWordLen,
		"PARTIAL_DATA_WRITTEN", errCliPartialDataWritten,
		"SIZE_OVER_PDU", errCliSizeOverPDU,
		"INVALID_PLC_ANSWER", errCliInvalidPlcAnswer,
		"ADDRESS_OUT_OF_RANGE", errCliAddressOutOfRange,
		"INVALID_TRANSPORT_SIZE", errCliInvalidTransportSize,
		"WRITE_DATA_SIZE_MISMATCH", errCliWriteDataSizeMismatch,
		"ITEM_NOT_AVAILABLE", errCliItemNotAvailable,
		"INVALID_VALUE", errCliInvalidValue,
		"CANNOT_START_PLC", errCliCannotStartPLC,
		"ALREADY_RUN", errCliAlreadyRun,
		"CANNOT_STOP_PLC", errCliCannotStopPLC,
		"CANNOT_COPY_RAM_TO_ROM", errCliCannotCopyRamToRom,
		"CANNOT_COMPRESS", errCliCannotCompress,
		"ALREADY_STOP", errCliAlreadyStop,
		"FUN_NOT_AVAILABLE", errCliFunNotAvailable,
		"UPLOAD_SEQUENCE_FAILED", errCliUploadSequenceFailed,
		"INVALID_DATA_SIZE_RECVD", errCliInvalidDataSizeRecvd,
		"INVALID_BLOCK_TYPE", errCliInvalidBlockType,
		"INVALID_BLOCK_NUMBER", errCliInvalidBlockNumber,
		"INVALID_BLOCK_SIZE", errCliInvalidBlockSize,
		"DOWNLOAD_SEQUENCE_FAILED", errCliDownloadSequenceFailed,
		"INSERT_REFUSED", errCliInsertRefused,
		"DELETE_REFUSED", errCliDeleteRefused,
		"NEED_PASSWORD", errCliNeedPassword,
		"INVALID_PASSWORD", errCliInvalidPassword,
		"NO_PASSWORD_TO_SET_OR_CLEAR", errCliNoPasswordToSetOrClear,
		"JOB_TIMEOUT", errCliJobTimeout,
		"PARTIAL_DATA_READ", errCliPartialDataRead,
		"BUFFER_TOO_SMALL", errCliBufferTooSmall,
		"FUNCTION_REFUSED", errCliFunctionRefused,
		"DESTROYING", errCliDestroying,
		"INVALID_PARAM_NUMBER", errCliInvalidParamNumber,
		"CANNOT_CHANGE_PARAM", errCliCannotChangeParam
	);

	module.new_enum("CliConnectionType",
		"PG", CONNTYPE_PG,
		"OP", CONNTYPE_OP,
		"BASIC", CONNTYPE_BASIC
	);

	module.new_enum("S7AreaID",
		"PE", S7AreaPE,
		"PA", S7AreaPA,
		"MK", S7AreaMK,
		"DB", S7AreaDB,
		"CT", S7AreaCT,
		"TM", S7AreaTM,
		"CT2", S7AreaCT2,
		"TM2", S7AreaTM2
	);

	module.new_enum("S7WordLen",
		"Bit", S7WLBit,
		"Byte", S7WLByte,
		"Word", S7WLWord,
		"DWord", S7WLDWord,
		"Real", S7WLReal,
		"Counter", S7WLCounter,
		"Timer", S7WLTimer,
		"Counter", S7WLCounter2,
		"Timer", S7WLTimer2
	);

	module.new_enum("S7BlockType",
		"OB", Block_OB,
		"DB", Block_DB,
		"SDB", Block_SDB,
		"FC", Block_FC,
		"SFC", Block_SFC,
		"FB", Block_FB,
		"SFB", Block_SFB
	);

	module.new_enum("S7SubBlockType",
		"OB", SubBlk_OB,
		"DB", SubBlk_DB,
		"SDB", SubBlk_SDB,
		"FC", SubBlk_FC,
		"SFC", SubBlk_SFC,
		"FB", SubBlk_FB,
		"SFB", SubBlk_SFB
	);

	module.new_enum("S7BlockLang",
		"AWL", BlockLangAWL,
		"KOP", BlockLangKOP,
		"FUP", BlockLangFUP,
		"SCL", BlockLangSCL,
		"DB", BlockLangDB,
		"GRAPH", BlockLangGRAPH
	);

	module.new_enum("S7SrvArea",
		"PE", srvAreaPE,
		"PA", srvAreaPA,
		"MK", srvAreaMK,
		"CT", srvAreaCT,
		"TM", srvAreaTM,
		"DB", srvAreaDB
	);
}

}
