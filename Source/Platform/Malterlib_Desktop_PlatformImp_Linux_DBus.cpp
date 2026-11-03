// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <Mib/Core/Core>
#include "Malterlib_Desktop_PlatformImp_Linux_DBus.h"

extern "C"
{
#include <dbus/dbus.h>
}

namespace NMib::NDBus
{
	DMibImpErrorClassImplement(CDBusException);

	struct CDBusLibrary final : public NMib::CDynamicLibraryUtility
	{
		constexpr CDBusLibrary()
			: NMib::CDynamicLibraryUtility(NMib::NStr::gc_Str<"libdbus-1.so,libdbus-1.so.3">, EDLFlag_NoThrow)
		{
		}

		decltype(&dbus_message_new_method_call) m_fDBusMessageNewMethodCall = nullptr;
		decltype(&dbus_message_new_method_return) m_fDBusMessageNewMethodReturn = nullptr;
		decltype(&dbus_message_new_signal) m_fDBusMessageNewSignal = nullptr;
		decltype(&dbus_message_new_error) m_fDBusMessageNewError = nullptr;
		decltype(&dbus_message_unref) m_fDBusMessageUnref = nullptr;
		decltype(&dbus_message_copy) m_fDBusMessageCopy = nullptr;
		decltype(&dbus_message_get_type) m_fDBusMessageGetType = nullptr;
		decltype(&dbus_message_iter_init_append) m_fDBusMessageIterInitAppend = nullptr;
		decltype(&dbus_message_iter_append_basic) m_fDBusMessageIterAppendBasic = nullptr;
		decltype(&dbus_message_iter_open_container) m_fDBusMessageIterOpenContainer = nullptr;
		decltype(&dbus_message_iter_append_fixed_array) m_fDBusMessageIterAppendFixedArray = nullptr;
		decltype(&dbus_message_iter_close_container) m_fDBusMessageIterCloseContainer = nullptr;
		decltype(&dbus_message_iter_init) m_fDBusMessageIterInit = nullptr;
		decltype(&dbus_message_iter_get_arg_type) m_fDBusMessageIterGetArgType = nullptr;
		decltype(&dbus_message_iter_get_basic) m_fDBusMessageIterGetBasic = nullptr;
		decltype(&dbus_message_iter_next) m_fDBusMessageIterNext = nullptr;
		decltype(&dbus_message_iter_get_element_type) m_fDBusMessageIterGetElementType = nullptr;
		decltype(&dbus_message_iter_get_fixed_array) m_fDBusMessageIterGetFixedArray = nullptr;
		decltype(&dbus_message_iter_recurse) m_fDBusMessageIterRecurse = nullptr;
		decltype(&dbus_message_iter_has_next) m_fDBusMessageIterHasNext = nullptr;
		decltype(&dbus_message_set_serial) m_fDBusMessageSetSerial = nullptr;
		decltype(&dbus_error_init) m_fDBusErrorInit = nullptr;
		decltype(&dbus_error_free) m_fDBusErrorFree = nullptr;
		decltype(&dbus_error_is_set) m_fDBusErrorIsSet = nullptr;
		decltype(&dbus_move_error) m_fDBusMoveError = nullptr;
		decltype(&dbus_connection_open) m_fDBusConnectionOpen = nullptr;
		decltype(&dbus_connection_open_private) m_fDBusConnectionOpenPrivate = nullptr;
		decltype(&dbus_connection_send_with_reply_and_block) m_fDBusConnectionSendWithReplyAndBlock = nullptr;
		decltype(&dbus_connection_get_is_connected) m_fDBusConnectionGetIsConnected = nullptr;
		decltype(&dbus_connection_close) m_fDBusConnectionClose = nullptr;
		decltype(&dbus_connection_unref) m_fDBusConnectionUnref = nullptr;
		decltype(&dbus_bus_get) m_fDBusBusGet = nullptr;
		decltype(&dbus_bus_add_match) m_fDBusBusAddMatch = nullptr;
		decltype(&dbus_connection_read_write) m_fDBusConnectionReadWrite = nullptr;
		decltype(&dbus_connection_pop_message) m_fDBusConnectionPopMessage = nullptr;
		decltype(&dbus_message_get_interface) m_fDBusMessageGetInterface = nullptr;
		decltype(&dbus_message_get_member) m_fDBusMessageGetMember = nullptr;
		decltype(&dbus_message_get_path) m_fDBusMessageGetPath = nullptr;
		decltype(&dbus_connection_get_unix_fd) m_fDBusConnectionGetUnixFD = nullptr;
		decltype(&dbus_connection_dispatch) m_fDBusConnectionDispatch = nullptr;

	protected:
		void fp_ClearSymbols() override
		{
			m_fDBusMessageNewMethodCall = nullptr;
			m_fDBusMessageNewMethodReturn = nullptr;
			m_fDBusMessageNewSignal = nullptr;
			m_fDBusMessageNewError = nullptr;
			m_fDBusMessageUnref = nullptr;
			m_fDBusMessageCopy = nullptr;
			m_fDBusMessageGetType = nullptr;
			m_fDBusMessageIterInitAppend = nullptr;
			m_fDBusMessageIterAppendBasic = nullptr;
			m_fDBusMessageIterOpenContainer = nullptr;
			m_fDBusMessageIterAppendFixedArray = nullptr;
			m_fDBusMessageIterCloseContainer = nullptr;
			m_fDBusMessageIterInit = nullptr;
			m_fDBusMessageIterGetArgType = nullptr;
			m_fDBusMessageIterGetBasic = nullptr;
			m_fDBusMessageIterNext = nullptr;
			m_fDBusMessageIterGetElementType = nullptr;
			m_fDBusMessageIterGetFixedArray = nullptr;
			m_fDBusMessageIterRecurse = nullptr;
			m_fDBusMessageIterHasNext = nullptr;
			m_fDBusMessageSetSerial = nullptr;
			m_fDBusErrorInit = nullptr;
			m_fDBusErrorFree = nullptr;
			m_fDBusErrorIsSet = nullptr;
			m_fDBusMoveError = nullptr;
			m_fDBusConnectionOpen = nullptr;
			m_fDBusConnectionOpenPrivate = nullptr;
			m_fDBusConnectionSendWithReplyAndBlock = nullptr;
			m_fDBusConnectionGetIsConnected = nullptr;
			m_fDBusConnectionClose = nullptr;
			m_fDBusConnectionUnref = nullptr;
			m_fDBusBusGet = nullptr;
			m_fDBusBusAddMatch = nullptr;
			m_fDBusConnectionReadWrite = nullptr;
			m_fDBusConnectionPopMessage = nullptr;
			m_fDBusMessageGetInterface = nullptr;
			m_fDBusMessageGetMember = nullptr;
			m_fDBusMessageGetPath = nullptr;
			m_fDBusConnectionGetUnixFD = nullptr;
			m_fDBusConnectionDispatch = nullptr;
		}

		void fp_FetchSymbols() override
		{
			fp_Fetch(m_fDBusMessageNewMethodCall, "dbus_message_new_method_call");
			fp_Fetch(m_fDBusMessageNewMethodReturn, "dbus_message_new_method_return");
			fp_Fetch(m_fDBusMessageNewSignal, "dbus_message_new_signal");
			fp_Fetch(m_fDBusMessageNewError, "dbus_message_new_error");
			fp_Fetch(m_fDBusMessageUnref, "dbus_message_unref");
			fp_Fetch(m_fDBusMessageCopy, "dbus_message_copy");
			fp_Fetch(m_fDBusMessageGetType, "dbus_message_get_type");
			fp_Fetch(m_fDBusMessageIterInitAppend, "dbus_message_iter_init_append");
			fp_Fetch(m_fDBusMessageIterAppendBasic, "dbus_message_iter_append_basic");
			fp_Fetch(m_fDBusMessageIterOpenContainer, "dbus_message_iter_open_container");
			fp_Fetch(m_fDBusMessageIterAppendFixedArray, "dbus_message_iter_append_fixed_array");
			fp_Fetch(m_fDBusMessageIterCloseContainer, "dbus_message_iter_close_container");
			fp_Fetch(m_fDBusMessageIterInit, "dbus_message_iter_init");
			fp_Fetch(m_fDBusMessageIterGetArgType, "dbus_message_iter_get_arg_type");
			fp_Fetch(m_fDBusMessageIterGetBasic, "dbus_message_iter_get_basic");
			fp_Fetch(m_fDBusMessageIterNext, "dbus_message_iter_next");
			fp_Fetch(m_fDBusMessageIterGetElementType, "dbus_message_iter_get_element_type");
			fp_Fetch(m_fDBusMessageIterGetFixedArray, "dbus_message_iter_get_fixed_array");
			fp_Fetch(m_fDBusMessageIterRecurse, "dbus_message_iter_recurse");
			fp_Fetch(m_fDBusMessageIterHasNext, "dbus_message_iter_has_next");
			fp_Fetch(m_fDBusMessageSetSerial, "dbus_message_set_serial");
			fp_Fetch(m_fDBusErrorInit, "dbus_error_init");
			fp_Fetch(m_fDBusErrorFree, "dbus_error_free");
			fp_Fetch(m_fDBusErrorIsSet, "dbus_error_is_set");
			fp_Fetch(m_fDBusMoveError, "dbus_move_error");
			fp_Fetch(m_fDBusConnectionOpen, "dbus_connection_open");
			fp_Fetch(m_fDBusConnectionOpenPrivate, "dbus_connection_open_private");
			fp_Fetch(m_fDBusConnectionSendWithReplyAndBlock, "dbus_connection_send_with_reply_and_block");
			fp_Fetch(m_fDBusConnectionGetIsConnected, "dbus_connection_get_is_connected");
			fp_Fetch(m_fDBusConnectionClose, "dbus_connection_close");
			fp_Fetch(m_fDBusConnectionUnref, "dbus_connection_unref");
			fp_Fetch(m_fDBusBusGet, "dbus_bus_get");
			fp_Fetch(m_fDBusBusAddMatch, "dbus_bus_add_match");
			fp_Fetch(m_fDBusConnectionReadWrite, "dbus_connection_read_write");
			fp_Fetch(m_fDBusConnectionPopMessage, "dbus_connection_pop_message");
			fp_Fetch(m_fDBusMessageGetInterface, "dbus_message_get_interface");
			fp_Fetch(m_fDBusMessageGetMember, "dbus_message_get_member");
			fp_Fetch(m_fDBusMessageGetPath, "dbus_message_get_path");
			fp_Fetch(m_fDBusConnectionGetUnixFD, "dbus_connection_get_unix_fd");
			fp_Fetch(m_fDBusConnectionDispatch, "dbus_connection_dispatch");
		}
	};

	//
	// CMessage
	//

	CMessage::CMessage(CSystem &_System)
		: mp_Lib(*_System.mp_pLib)
		, mp_pMsg(nullptr)
	{
	}

	// New method call message. _Type MUST == EMessageType_Method
	CMessage::CMessage(EMessageType _Type, char const *_pService, char const *_pPath, char const *_pInterface, char const *_pMethod, CSystem &_System)
		: mp_Lib(*_System.mp_pLib)
		, mp_pMsg(nullptr)
	{
		if (_Type != EMessageType_Method)
			DMibDBusError("Incorrect message constructor used.");

		mp_pMsg = mp_Lib.m_fDBusMessageNewMethodCall(_pService, _pPath, _pInterface, _pMethod);

		if (!mp_pMsg)
			DMibDBusError("Failed to create new method call message.");
	}

	// New method return message. _Type MUST == EMessageType_MethodReturn
	CMessage::CMessage(EMessageType _Type, CMessage &_InReplyTo, CSystem &_System)
		: mp_Lib(*_System.mp_pLib)
		, mp_pMsg(nullptr)
	{
		if (_Type != EMessageType_MethodReturn)
			DMibDBusError("Incorrect message constructor used.");

		mp_pMsg = mp_Lib.m_fDBusMessageNewMethodReturn(_InReplyTo.mp_pMsg);

		if (!mp_pMsg)
			DMibDBusError("Failed to create new method return call message.");
	}

	// New signal message. _Type MUST == EMessageType_Signal
	CMessage::CMessage(EMessageType _Type, char const *_pPath, char const *_pInterface, char const *_pName, CSystem &_System)
		: mp_Lib(*_System.mp_pLib)
		, mp_pMsg(nullptr)
	{
		if (_Type != EMessageType_Signal)
			DMibDBusError("Incorrect message constructor used.");

		mp_pMsg = mp_Lib.m_fDBusMessageNewSignal(_pPath, _pInterface, _pName);

		if (!mp_pMsg)
			DMibDBusError("Failed to create new signal message.");
	}

	// New error message. _Type MUST == EMessageType_Error
	CMessage::CMessage(EMessageType _Type, CMessage &_InReplyTo, char const *_pErrorName, char const *_pErrorMessage, CSystem &_System)
		: mp_Lib(*_System.mp_pLib)
		, mp_pMsg(nullptr)
	{
		if (_Type != EMessageType_Error)
			DMibDBusError("Incorrect message constructor used.");

		mp_pMsg = mp_Lib.m_fDBusMessageNewError(_InReplyTo.mp_pMsg, _pErrorName, _pErrorMessage);

		if (!mp_pMsg)
			DMibDBusError("Failed to create new error message.");
	}

	CMessage::CMessage(CMessage const &_ToCopy)
		: mp_Lib(_ToCopy.mp_Lib)
		, mp_pMsg(nullptr)
	{
		mp_pMsg = mp_Lib.m_fDBusMessageCopy(const_cast<DBusMessage *>(_ToCopy.mp_pMsg));

		if (!mp_pMsg)
			DMibDBusError("Failed to copy message.");
	}

	CMessage::CMessage(CMessage &&_ToMove)
		: mp_Lib(_ToMove.mp_Lib)
		, mp_pMsg(_ToMove.mp_pMsg)
	{
		_ToMove.mp_pMsg = nullptr;
	}

	CMessage::CMessage(DBusMessage *_pMsg, CSystem &_System)
		: mp_Lib(*_System.mp_pLib)
		, mp_pMsg(_pMsg)
	{
	}

	CMessage::CMessage(DBusMessage *_pMsg, CDBusLibrary &_Lib)
		: mp_Lib(_Lib)
		, mp_pMsg(_pMsg)
	{
	}

	CMessage::~CMessage()
	{
		if (mp_pMsg)
			mp_Lib.m_fDBusMessageUnref(mp_pMsg);
	}

	CMessage &CMessage::operator = (CMessage &_ToCopy)
	{
		if (mp_pMsg)
			mp_Lib.m_fDBusMessageUnref(mp_pMsg);

		if (_ToCopy.mp_pMsg)
		{
			mp_pMsg = mp_Lib.m_fDBusMessageCopy(const_cast<DBusMessage *>(_ToCopy.mp_pMsg));
			if (!mp_pMsg)
				DMibDBusError("Failed to copy message.");
		}
		else
			mp_pMsg = nullptr;

		return *this;
	}

	CMessage &CMessage::operator = (CMessage &&_ToMove)
	{
		if (mp_pMsg)
			mp_Lib.m_fDBusMessageUnref(mp_pMsg);

		mp_pMsg = _ToMove.mp_pMsg;
		_ToMove.mp_pMsg = nullptr;

		return *this;
	}

	EMessageType CMessage::f_GetType() const
	{
		if (!mp_pMsg)
			return EMessageType_Unknown;

		switch (mp_Lib.m_fDBusMessageGetType(mp_pMsg))
		{
		case DBUS_MESSAGE_TYPE_METHOD_CALL: return EMessageType_Method;
		case DBUS_MESSAGE_TYPE_METHOD_RETURN: return EMessageType_MethodReturn;
		case DBUS_MESSAGE_TYPE_ERROR: return EMessageType_Error;
		case DBUS_MESSAGE_TYPE_SIGNAL: return EMessageType_Signal;
		default: return EMessageType_Unknown;
		}
	}

	void CMessage::f_SetSerial(uint32 _Serial) // Only used for testing.
	{
		if (mp_pMsg)
			mp_Lib.m_fDBusMessageSetSerial(mp_pMsg, _Serial);
	}

	char const *CMessage::f_GetInterface() const
	{
		if (!mp_pMsg)
			return nullptr;
		return mp_Lib.m_fDBusMessageGetInterface(mp_pMsg);
	}

	char const *CMessage::f_GetMember() const
	{
		if (!mp_pMsg)
			return nullptr;
		return mp_Lib.m_fDBusMessageGetMember(mp_pMsg);
	}

	char const *CMessage::f_GetPath() const
	{
		if (!mp_pMsg)
			return nullptr;
		return mp_Lib.m_fDBusMessageGetPath(mp_pMsg);
	}

	//
	// CMessageWriter
	//

	struct CMessageWriter::CInternal
	{
		CInternal(CMessage &_Message)
			: m_Lib(_Message.mp_Lib)
		{
		}

		CDBusLibrary &m_Lib;
		DBusMessageIter m_Iter;
	};

	CMessageWriter::CMessageWriter(CMessage &_Message)
		: mp_pInternal(fg_Construct(_Message))
	{
		mp_pInternal->m_Lib.m_fDBusMessageIterInitAppend(_Message.mp_pMsg, &mp_pInternal->m_Iter);
	}

	CMessageWriter::~CMessageWriter()
	{
	}

	template <>
	bool CMessageWriter::f_AppendArg<uint8>(uint8 const &_Value)
	{
		char Value = _Value;

		return mp_pInternal->m_Lib.m_fDBusMessageIterAppendBasic(&mp_pInternal->m_Iter, DBUS_TYPE_BYTE, &Value) ? true : false;
	}

	template <>
	bool CMessageWriter::f_AppendArg<int16>(int16 const &_Value)
	{
		dbus_int16_t Value = _Value;

		return mp_pInternal->m_Lib.m_fDBusMessageIterAppendBasic(&mp_pInternal->m_Iter, DBUS_TYPE_INT16, &Value) ? true : false;
	}

	template <>
	bool CMessageWriter::f_AppendArg<uint16>(uint16 const &_Value)
	{
		dbus_uint16_t Value = _Value;

		return mp_pInternal->m_Lib.m_fDBusMessageIterAppendBasic(&mp_pInternal->m_Iter, DBUS_TYPE_UINT16, &Value) ? true : false;
	}

	template <>
	bool CMessageWriter::f_AppendArg<int32>(int32 const &_Value)
	{
		dbus_int32_t Value = _Value;

		return mp_pInternal->m_Lib.m_fDBusMessageIterAppendBasic(&mp_pInternal->m_Iter, DBUS_TYPE_INT32, &Value) ? true : false;
	}

	template <>
	bool CMessageWriter::f_AppendArg<uint32>(uint32 const &_Value)
	{
		dbus_uint32_t Value = _Value;

		return mp_pInternal->m_Lib.m_fDBusMessageIterAppendBasic(&mp_pInternal->m_Iter, DBUS_TYPE_UINT32, &Value) ? true : false;
	}

	template <>
	bool CMessageWriter::f_AppendArg<int64>(int64 const &_Value)
	{
		dbus_int64_t Value = _Value;

		return mp_pInternal->m_Lib.m_fDBusMessageIterAppendBasic(&mp_pInternal->m_Iter, DBUS_TYPE_INT64, &Value) ? true : false;
	}

	template <>
	bool CMessageWriter::f_AppendArg<uint64>(uint64 const &_Value)
	{
		dbus_uint64_t Value = _Value;

		return mp_pInternal->m_Lib.m_fDBusMessageIterAppendBasic(&mp_pInternal->m_Iter, DBUS_TYPE_UINT64, &Value) ? true : false;
	}

	template <>
	bool CMessageWriter::f_AppendArg<char const *>(char const * const &_pValue)
	{
		// TODO: Encoding
		return mp_pInternal->m_Lib.m_fDBusMessageIterAppendBasic(&mp_pInternal->m_Iter, DBUS_TYPE_STRING, &_pValue) ? true : false;
	}

	template <>
	bool CMessageWriter::f_AppendArg<NStr::CStr>(NStr::CStr const &_Value)
	{
		// TODO: Encoding
		char const *pValue = _Value.f_GetStr();
		return mp_pInternal->m_Lib.m_fDBusMessageIterAppendBasic(&mp_pInternal->m_Iter, DBUS_TYPE_STRING, &pValue) ? true : false;
	}

	template <>
	bool CMessageWriter::f_AppendArg<NStr::CStrSecure>(NStr::CStrSecure const &_Value)
	{
		// TODO: Encoding
		char const *pValue = _Value.f_GetStr();
		return mp_pInternal->m_Lib.m_fDBusMessageIterAppendBasic(&mp_pInternal->m_Iter, DBUS_TYPE_STRING, &pValue) ? true : false;
	}

	template <>
	bool CMessageWriter::f_AppendArg<bool>(bool const &_bValue)
	{
		dbus_int32_t Value = _bValue;
		return mp_pInternal->m_Lib.m_fDBusMessageIterAppendBasic(&mp_pInternal->m_Iter, DBUS_TYPE_BOOLEAN, &Value) ? true : false;
	}

	template <>
	bool CMessageWriter::f_AppendArg<NContainer::CByteVector>(NContainer::CByteVector const &_Value)
	{
		char *pBytes = (char *)_Value.f_GetArray();
		dbus_uint32_t Len = _Value.f_GetLen();

		dbus_bool_t bRet;
		DBusMessageIter ArrayIter;

		bRet = mp_pInternal->m_Lib.m_fDBusMessageIterOpenContainer(&mp_pInternal->m_Iter, DBUS_TYPE_ARRAY, "y", &ArrayIter);
		if (bRet)
		{
			bRet = mp_pInternal->m_Lib.m_fDBusMessageIterAppendFixedArray(&ArrayIter, DBUS_TYPE_BYTE, &pBytes, Len);

			bRet = bRet && mp_pInternal->m_Lib.m_fDBusMessageIterCloseContainer(&mp_pInternal->m_Iter, &ArrayIter);
		}

		return bRet ? true : false;
	}

	template <>
	bool CMessageWriter::f_AppendArg<NContainer::TCVector<NStr::CStr>>(NContainer::TCVector<NStr::CStr> const &_Value)
	{
		dbus_bool_t bRet;
		DBusMessageIter ArrayIter;

		bRet = mp_pInternal->m_Lib.m_fDBusMessageIterOpenContainer(&mp_pInternal->m_Iter, DBUS_TYPE_ARRAY, "s", &ArrayIter);
		if (bRet)
		{
			for (auto iString = _Value.f_GetIterator(); iString && bRet; ++iString)
			{
				char const *pValue = (*iString).f_GetStr();
				bRet = bRet && (mp_pInternal->m_Lib.m_fDBusMessageIterAppendBasic(&ArrayIter, DBUS_TYPE_STRING, &pValue) ? true : false);
			}

			bRet = bRet && mp_pInternal->m_Lib.m_fDBusMessageIterCloseContainer(&mp_pInternal->m_Iter, &ArrayIter);
		}

		return bRet ? true : false;
	}

	//
	// CMessageReader
	//

	struct CMessageReader::CInternal
	{
		CInternal(CMessage const &_Message)
			: m_Lib(_Message.mp_Lib)
		{
		}

		CDBusLibrary &m_Lib;
		DBusMessageIter m_Iter;
	};

	CMessageReader::CMessageReader(CMessage const &_Message)
		: mp_pInternal(fg_Construct(_Message))
	{
		mp_pInternal->m_Lib.m_fDBusMessageIterInit(_Message.mp_pMsg, &mp_pInternal->m_Iter);
	}

	CMessageReader::~CMessageReader()
	{
	}

	template <>
	bool CMessageReader::f_PopArg<uint8>(uint8 &o_Value)
	{
		if (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&mp_pInternal->m_Iter) != DBUS_TYPE_BYTE)
			return false;

		char Value;
		mp_pInternal->m_Lib.m_fDBusMessageIterGetBasic(&mp_pInternal->m_Iter, &Value);
		o_Value = (uint8)Value;

		mp_pInternal->m_Lib.m_fDBusMessageIterNext(&mp_pInternal->m_Iter);

		return true;
	}

	template <>
	bool CMessageReader::f_PopArg<int16>(int16 &o_Value)
	{
		if (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&mp_pInternal->m_Iter) != DBUS_TYPE_INT16)
			return false;

		dbus_int16_t Value;
		mp_pInternal->m_Lib.m_fDBusMessageIterGetBasic(&mp_pInternal->m_Iter, &Value);
		o_Value = Value;

		mp_pInternal->m_Lib.m_fDBusMessageIterNext(&mp_pInternal->m_Iter);

		return true;
	}

	template <>
	bool CMessageReader::f_PopArg<uint16>(uint16 &o_Value)
	{
		if (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&mp_pInternal->m_Iter) != DBUS_TYPE_UINT16)
			return false;

		dbus_uint16_t Value;
		mp_pInternal->m_Lib.m_fDBusMessageIterGetBasic(&mp_pInternal->m_Iter, &Value);
		o_Value = Value;

		mp_pInternal->m_Lib.m_fDBusMessageIterNext(&mp_pInternal->m_Iter);

		return true;
	}

	template <>
	bool CMessageReader::f_PopArg<int32>(int32 &o_Value)
	{
		if (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&mp_pInternal->m_Iter) != DBUS_TYPE_INT32)
			return false;

		dbus_int32_t Value;
		mp_pInternal->m_Lib.m_fDBusMessageIterGetBasic(&mp_pInternal->m_Iter, &Value);
		o_Value = Value;

		mp_pInternal->m_Lib.m_fDBusMessageIterNext(&mp_pInternal->m_Iter);

		return true;
	}

	template <>
	bool CMessageReader::f_PopArg<uint32>(uint32 &o_Value)
	{
		if (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&mp_pInternal->m_Iter) != DBUS_TYPE_UINT32)
			return false;

		dbus_uint32_t Value;
		mp_pInternal->m_Lib.m_fDBusMessageIterGetBasic(&mp_pInternal->m_Iter, &Value);
		o_Value = Value;

		mp_pInternal->m_Lib.m_fDBusMessageIterNext(&mp_pInternal->m_Iter);

		return true;
	}

	template <>
	bool CMessageReader::f_PopArg<int64>(int64 &o_Value)
	{
		if (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&mp_pInternal->m_Iter) != DBUS_TYPE_INT64)
			return false;

		dbus_int64_t Value;
		mp_pInternal->m_Lib.m_fDBusMessageIterGetBasic(&mp_pInternal->m_Iter, &Value);
		o_Value = Value;

		mp_pInternal->m_Lib.m_fDBusMessageIterNext(&mp_pInternal->m_Iter);

		return true;
	}

	template <>
	bool CMessageReader::f_PopArg<uint64>(uint64 &o_Value)
	{
		if (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&mp_pInternal->m_Iter) != DBUS_TYPE_UINT64)
			return false;

		dbus_uint64_t Value;
		mp_pInternal->m_Lib.m_fDBusMessageIterGetBasic(&mp_pInternal->m_Iter, &Value);
		o_Value = Value;

		mp_pInternal->m_Lib.m_fDBusMessageIterNext(&mp_pInternal->m_Iter);

		return true;
	}

	template <>
	bool CMessageReader::f_PopArg<NStr::CStr>(NStr::CStr &o_Value)
	{
		// TODO: Encoding
		if (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&mp_pInternal->m_Iter) != DBUS_TYPE_STRING)
			return false;

		char *pValue;
		mp_pInternal->m_Lib.m_fDBusMessageIterGetBasic(&mp_pInternal->m_Iter, &pValue);
		o_Value = pValue;

		mp_pInternal->m_Lib.m_fDBusMessageIterNext(&mp_pInternal->m_Iter);

		return true;
	}

	template <>
	bool CMessageReader::f_PopArg<NStr::CStrSecure>(NStr::CStrSecure &o_Value)
	{
		// TODO: Encoding
		if (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&mp_pInternal->m_Iter) != DBUS_TYPE_STRING)
			return false;

		char *pValue;
		mp_pInternal->m_Lib.m_fDBusMessageIterGetBasic(&mp_pInternal->m_Iter, &pValue);
		o_Value = pValue;

		mp_pInternal->m_Lib.m_fDBusMessageIterNext(&mp_pInternal->m_Iter);

		return true;
	}

	template <>
	bool CMessageReader::f_PopArg<bool>(bool &o_bValue)
	{
		if (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&mp_pInternal->m_Iter) != DBUS_TYPE_BOOLEAN)
			return false;

		dbus_bool_t Value;
		mp_pInternal->m_Lib.m_fDBusMessageIterGetBasic(&mp_pInternal->m_Iter, &Value);
		o_bValue = Value;

		mp_pInternal->m_Lib.m_fDBusMessageIterNext(&mp_pInternal->m_Iter);

		return true;
	}

	template <>
	bool CMessageReader::f_PopArg<NContainer::CByteVector>(NContainer::CByteVector &o_Value)
	{
		if
		(
			mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&mp_pInternal->m_Iter) != DBUS_TYPE_ARRAY
			|| mp_pInternal->m_Lib.m_fDBusMessageIterGetElementType(&mp_pInternal->m_Iter) != DBUS_TYPE_BYTE
		)
		{
			return false;
		}

		DBusMessageIter ArrayIter;

		mp_pInternal->m_Lib.m_fDBusMessageIterRecurse(&mp_pInternal->m_Iter, &ArrayIter);

		char *pBytes;
		int Len;

		mp_pInternal->m_Lib.m_fDBusMessageIterGetFixedArray(&ArrayIter, &pBytes, &Len);

		o_Value.f_SetLen(Len);
		NMemory::fg_MemCopy(o_Value.f_GetArray(), pBytes, Len);

		mp_pInternal->m_Lib.m_fDBusMessageIterNext(&mp_pInternal->m_Iter);

		return true;
	}

	template <>
	bool CMessageReader::f_PopArg<NContainer::TCVector<NStr::CStr>>(NContainer::TCVector<NStr::CStr> &o_Value)
	{
		if
		(
			mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&mp_pInternal->m_Iter) != DBUS_TYPE_ARRAY
			|| mp_pInternal->m_Lib.m_fDBusMessageIterGetElementType(&mp_pInternal->m_Iter) != DBUS_TYPE_STRING
		)
		{
			return false;
		}

		DBusMessageIter ArrayIter;

		mp_pInternal->m_Lib.m_fDBusMessageIterRecurse(&mp_pInternal->m_Iter, &ArrayIter);

		char *pValue;

		while (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&ArrayIter) == DBUS_TYPE_STRING)
		{
			mp_pInternal->m_Lib.m_fDBusMessageIterGetBasic(&ArrayIter, &pValue);
			o_Value.f_Insert(NStr::CStr(pValue));
			mp_pInternal->m_Lib.m_fDBusMessageIterNext(&ArrayIter);
		}

		mp_pInternal->m_Lib.m_fDBusMessageIterNext(&mp_pInternal->m_Iter);

		return true;
	}

	bool CMessageReader::f_ArgAvailable()
	{
		return mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&mp_pInternal->m_Iter) != DBUS_TYPE_INVALID;
	}

	namespace
	{
		// Helper to read a variant value from a sub-iterator positioned at a variant
		bool fg_ReadVariantValue(CDBusLibrary &_Lib, DBusMessageIter &_VariantIter, CDBusVariant &o_Value)
		{
			int Type = _Lib.m_fDBusMessageIterGetArgType(&_VariantIter);

			switch (Type)
			{
			case DBUS_TYPE_BOOLEAN:
				{
					dbus_bool_t Value;
					_Lib.m_fDBusMessageIterGetBasic(&_VariantIter, &Value);
					o_Value = (bool)Value;
					return true;
				}
			case DBUS_TYPE_BYTE:
				{
					char Value;
					_Lib.m_fDBusMessageIterGetBasic(&_VariantIter, &Value);
					o_Value = (uint8)Value;
					return true;
				}
			case DBUS_TYPE_INT16:
				{
					dbus_int16_t Value;
					_Lib.m_fDBusMessageIterGetBasic(&_VariantIter, &Value);
					o_Value = (int16)Value;
					return true;
				}
			case DBUS_TYPE_UINT16:
				{
					dbus_uint16_t Value;
					_Lib.m_fDBusMessageIterGetBasic(&_VariantIter, &Value);
					o_Value = (uint16)Value;
					return true;
				}
			case DBUS_TYPE_INT32:
				{
					dbus_int32_t Value;
					_Lib.m_fDBusMessageIterGetBasic(&_VariantIter, &Value);
					o_Value = (int32)Value;
					return true;
				}
			case DBUS_TYPE_UINT32:
				{
					dbus_uint32_t Value;
					_Lib.m_fDBusMessageIterGetBasic(&_VariantIter, &Value);
					o_Value = (uint32)Value;
					return true;
				}
			case DBUS_TYPE_INT64:
				{
					dbus_int64_t Value;
					_Lib.m_fDBusMessageIterGetBasic(&_VariantIter, &Value);
					o_Value = (int64)Value;
					return true;
				}
			case DBUS_TYPE_UINT64:
				{
					dbus_uint64_t Value;
					_Lib.m_fDBusMessageIterGetBasic(&_VariantIter, &Value);
					o_Value = (uint64)Value;
					return true;
				}
			case DBUS_TYPE_DOUBLE:
				{
					double Value;
					_Lib.m_fDBusMessageIterGetBasic(&_VariantIter, &Value);
					o_Value = (fp64)Value;
					return true;
				}
			case DBUS_TYPE_STRING:
			case DBUS_TYPE_OBJECT_PATH:
				{
					char *pValue;
					_Lib.m_fDBusMessageIterGetBasic(&_VariantIter, &pValue);
					o_Value = NStr::CStr(pValue);
					return true;
				}
			default:
				// Unsupported variant type - store empty string as fallback
				o_Value = NStr::CStr();
				return true;
			}
		}

		// Helper to read a{sv} dict from a sub-iterator
		bool fg_ReadStringVariantDict(CDBusLibrary &_Lib, DBusMessageIter &_ArrayIter, CDBusStringVariantDict &o_Dict)
		{
			o_Dict.f_Clear();

			while (_Lib.m_fDBusMessageIterGetArgType(&_ArrayIter) == DBUS_TYPE_DICT_ENTRY)
			{
				DBusMessageIter DictEntryIter;
				_Lib.m_fDBusMessageIterRecurse(&_ArrayIter, &DictEntryIter);

				// Read key (string)
				if (_Lib.m_fDBusMessageIterGetArgType(&DictEntryIter) != DBUS_TYPE_STRING)
					return false;

				char *pKey;
				_Lib.m_fDBusMessageIterGetBasic(&DictEntryIter, &pKey);
				NStr::CStr Key(pKey);

				_Lib.m_fDBusMessageIterNext(&DictEntryIter);

				// Read value (variant)
				if (_Lib.m_fDBusMessageIterGetArgType(&DictEntryIter) != DBUS_TYPE_VARIANT)
					return false;

				DBusMessageIter VariantIter;
				_Lib.m_fDBusMessageIterRecurse(&DictEntryIter, &VariantIter);

				CDBusVariant Value;
				if (!fg_ReadVariantValue(_Lib, VariantIter, Value))
					return false;

				o_Dict[Key] = fg_Move(Value);

				_Lib.m_fDBusMessageIterNext(&_ArrayIter);
			}

			return true;
		}
	}

	template <>
	bool CMessageReader::f_PopArg<CDBusVariant>(CDBusVariant &o_Value)
	{
		if (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&mp_pInternal->m_Iter) != DBUS_TYPE_VARIANT)
			return false;

		DBusMessageIter VariantIter;
		mp_pInternal->m_Lib.m_fDBusMessageIterRecurse(&mp_pInternal->m_Iter, &VariantIter);

		if (!fg_ReadVariantValue(mp_pInternal->m_Lib, VariantIter, o_Value))
			return false;

		mp_pInternal->m_Lib.m_fDBusMessageIterNext(&mp_pInternal->m_Iter);
		return true;
	}

	template <>
	bool CMessageReader::f_PopArg<CDBusStringVariantDict>(CDBusStringVariantDict &o_Value)
	{
		if (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&mp_pInternal->m_Iter) != DBUS_TYPE_ARRAY)
			return false;

		DBusMessageIter ArrayIter;
		mp_pInternal->m_Lib.m_fDBusMessageIterRecurse(&mp_pInternal->m_Iter, &ArrayIter);

		if (!fg_ReadStringVariantDict(mp_pInternal->m_Lib, ArrayIter, o_Value))
			return false;

		mp_pInternal->m_Lib.m_fDBusMessageIterNext(&mp_pInternal->m_Iter);
		return true;
	}

	template <>
	bool CMessageReader::f_PopArg<CDBusUInt64DictDict>(CDBusUInt64DictDict &o_Value)
	{
		if (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&mp_pInternal->m_Iter) != DBUS_TYPE_ARRAY)
			return false;

		o_Value.f_Clear();

		DBusMessageIter ArrayIter;
		mp_pInternal->m_Lib.m_fDBusMessageIterRecurse(&mp_pInternal->m_Iter, &ArrayIter);

		while (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&ArrayIter) == DBUS_TYPE_DICT_ENTRY)
		{
			DBusMessageIter DictEntryIter;
			mp_pInternal->m_Lib.m_fDBusMessageIterRecurse(&ArrayIter, &DictEntryIter);

			// Read key (uint64)
			if (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&DictEntryIter) != DBUS_TYPE_UINT64)
				return false;

			dbus_uint64_t Key;
			mp_pInternal->m_Lib.m_fDBusMessageIterGetBasic(&DictEntryIter, &Key);

			mp_pInternal->m_Lib.m_fDBusMessageIterNext(&DictEntryIter);

			// Read value (a{sv})
			if (mp_pInternal->m_Lib.m_fDBusMessageIterGetArgType(&DictEntryIter) != DBUS_TYPE_ARRAY)
				return false;

			DBusMessageIter InnerArrayIter;
			mp_pInternal->m_Lib.m_fDBusMessageIterRecurse(&DictEntryIter, &InnerArrayIter);

			CDBusStringVariantDict InnerDict;
			if (!fg_ReadStringVariantDict(mp_pInternal->m_Lib, InnerArrayIter, InnerDict))
				return false;

			o_Value[Key] = fg_Move(InnerDict);

			mp_pInternal->m_Lib.m_fDBusMessageIterNext(&ArrayIter);
		}

		mp_pInternal->m_Lib.m_fDBusMessageIterNext(&mp_pInternal->m_Iter);
		return true;
	}

	//
	// CError
	//

	struct CError::CInternal
	{
		CInternal(CDBusLibrary &_Lib)
			: m_Lib(_Lib)
		{
		}

		CDBusLibrary &m_Lib;
		DBusError m_Error;
	};

	CError::CError(CSystem &_Sys)
		: mp_pInternal(fg_Construct(*_Sys.mp_pLib))
	{
		mp_pInternal->m_Lib.m_fDBusErrorInit(&mp_pInternal->m_Error);
	}

	CError::CError(CError &&_ToMove)
		: mp_pInternal(fg_Construct(_ToMove.mp_pInternal->m_Lib))
	{
		mp_pInternal->m_Lib.m_fDBusErrorInit(&mp_pInternal->m_Error);
		mp_pInternal->m_Lib.m_fDBusMoveError(&_ToMove.mp_pInternal->m_Error, &mp_pInternal->m_Error);
	}

	CError::CError(CDBusLibrary &_Lib)
		: mp_pInternal(fg_Construct(_Lib))
	{
		mp_pInternal->m_Lib.m_fDBusErrorInit(&mp_pInternal->m_Error);
	}

	CError::~CError()
	{
		mp_pInternal->m_Lib.m_fDBusErrorFree(&mp_pInternal->m_Error);
	}

	CError &CError::operator = (CError &&_ToMove)
	{
		mp_pInternal->m_Lib.m_fDBusErrorFree(&mp_pInternal->m_Error);
		mp_pInternal->m_Lib.m_fDBusMoveError(&_ToMove.mp_pInternal->m_Error, &mp_pInternal->m_Error);
		return *this;
	}

	bool CError::f_IsSet() const
	{
		return mp_pInternal->m_Lib.m_fDBusErrorIsSet(const_cast<DBusError *>(&mp_pInternal->m_Error));
	}

	char const *CError::f_GetName() const
	{
		return mp_pInternal->m_Error.name;
	}

	char const *CError::f_GetMessage() const
	{
		return mp_pInternal->m_Error.message;
	}

	void CError::f_Clear()
	{
		mp_pInternal->m_Lib.m_fDBusErrorFree(&mp_pInternal->m_Error);
	}

	void CError::f_Take(DBusError &_FromHere)
	{
		mp_pInternal->m_Lib.m_fDBusMoveError(&_FromHere, &mp_pInternal->m_Error);
	}

	//
	// CConnection
	//

	CConnection::CConnection(CSystem &_Sys)
		: mp_Lib(*_Sys.mp_pLib)
		, mp_pConnection(nullptr)
		, mp_Flags(EFlag_None)
		, mp_LastError(_Sys)
	{
	}

	CConnection::~CConnection()
	{
		f_Close();
	}

	CError const &CConnection::f_GetLastError() const
	{
		return mp_LastError;
	}

	bool CConnection::f_Open(char const *_pAddress, bool _bPrivate)
	{
		if (mp_pConnection)
		{
			// Cannot open an already open connection.
			return false;
		}

		CError Error(mp_Lib);

		if (!_bPrivate)
			mp_pConnection = mp_Lib.m_fDBusConnectionOpen(_pAddress, &Error.mp_pInternal->m_Error);
		else
			mp_pConnection = mp_Lib.m_fDBusConnectionOpenPrivate(_pAddress, &Error.mp_pInternal->m_Error);

		if (!mp_pConnection)
		{
			mp_LastError = std::move(Error);
			return false;
		}

		mp_Flags = (_bPrivate ? EFlag_Private : EFlag_None);
		mp_LastError.f_Clear();

		return true;
	}

	bool CConnection::f_Open(EDBusBus _Bus)
	{
		if (mp_pConnection)
		{
			// Cannot open an already open connection.
			return false;
		}

		CError Error(mp_Lib);

		DBusBusType BusType = DBUS_BUS_SESSION;
		switch (_Bus)
		{
		case EDBusBus_Session: BusType = DBUS_BUS_SESSION; break;
		case EDBusBus_System: BusType = DBUS_BUS_SYSTEM; break;
		};

		mp_pConnection = mp_Lib.m_fDBusBusGet(BusType, &Error.mp_pInternal->m_Error);

		if (!mp_pConnection)
		{
			mp_LastError = std::move(Error);
			return false;
		}

		mp_Flags = EFlag_None;
		mp_LastError.f_Clear();

		return true;
	}

	bool CConnection::f_Close()
	{
		if (mp_pConnection)
		{
			if (mp_Flags & EFlag_Private)
				mp_Lib.m_fDBusConnectionClose(mp_pConnection);
			mp_Lib.m_fDBusConnectionUnref(mp_pConnection);
			mp_pConnection = nullptr;
			mp_Flags = EFlag_None;
		}
		return true;
	}

	bool CConnection::f_BlockingSendWithReply(CMessage &_Message, CMessage &o_Reply, int _TimeoutMillis)
	{
		CError Error(mp_Lib);

		DBusMessage *pReply = mp_Lib.m_fDBusConnectionSendWithReplyAndBlock(mp_pConnection, _Message.mp_pMsg, _TimeoutMillis, &Error.mp_pInternal->m_Error);

		if (!pReply)
		{
			mp_LastError = std::move(Error);
			return false;
		}

		o_Reply = CMessage(pReply, mp_Lib);

		return true;
	}

	bool CConnection::f_AddMatch(char const *_pMatchRule)
	{
		if (!mp_pConnection)
			return false;

		CError Error(mp_Lib);
		mp_Lib.m_fDBusBusAddMatch(mp_pConnection, _pMatchRule, &Error.mp_pInternal->m_Error);

		if (Error.f_IsSet())
		{
			mp_LastError = std::move(Error);
			return false;
		}

		return true;
	}

	bool CConnection::f_BlockingPopMessage(CMessage &o_Message, int _TimeoutMillis)
	{
		if (!mp_pConnection)
			return false;

		// Read and dispatch incoming messages, blocking until timeout
		if (!mp_Lib.m_fDBusConnectionReadWrite(mp_pConnection, _TimeoutMillis))
		{
			// Connection closed
			return false;
		}

		// Pop the next message from the queue
		DBusMessage *pMsg = mp_Lib.m_fDBusConnectionPopMessage(mp_pConnection);
		if (!pMsg)
		{
			// No message available (timeout or only internal messages)
			return false;
		}

		o_Message = CMessage(pMsg, mp_Lib);
		return true;
	}

	int CConnection::f_GetUnixFd() const
	{
		if (!mp_pConnection)
			return -1;

		int Fd = -1;
		if (!mp_Lib.m_fDBusConnectionGetUnixFD(mp_pConnection, &Fd))
			return -1;

		return Fd;
	}

	//
	// CSystem
	//

	CSystem::CSystem()
		: mp_pLib(new CDBusLibrary)
	{
	}

	CSystem::~CSystem()
	{
		DMibLock(mp_LibLock);
		mp_pLib->f_Unload();
	}

	bool CSystem::f_ReadyForUse() // f_IsOK will never return true until this has been called and returned true.
	{
		DMibLock(mp_LibLock);
		return mp_pLib->f_OK() || mp_pLib->f_Reload();
	}

	bool CSystem::f_IsOK()
	{
		DMibLock(mp_LibLock);
		if (!(mp_pLib && mp_pLib->f_OK()))
			return false;

		if (fg_GetSys()->f_GetEnvironmentVariable("DBUS_SESSION_BUS_ADDRESS").f_IsEmpty())
			return false;
		return true;
	}
}
