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

		decltype(&dbus_message_new_method_call) dbus_message_new_method_call = nullptr;
		decltype(&dbus_message_new_method_return) dbus_message_new_method_return = nullptr;
		decltype(&dbus_message_new_signal) dbus_message_new_signal = nullptr;
		decltype(&dbus_message_new_error) dbus_message_new_error = nullptr;
		decltype(&dbus_message_unref) dbus_message_unref = nullptr;
		decltype(&dbus_message_copy) dbus_message_copy = nullptr;
		decltype(&dbus_message_get_type) dbus_message_get_type = nullptr;
		decltype(&dbus_message_iter_init_append) dbus_message_iter_init_append = nullptr;
		decltype(&dbus_message_iter_append_basic) dbus_message_iter_append_basic = nullptr;
		decltype(&dbus_message_iter_open_container) dbus_message_iter_open_container = nullptr;
		decltype(&dbus_message_iter_append_fixed_array) dbus_message_iter_append_fixed_array = nullptr;
		decltype(&dbus_message_iter_close_container) dbus_message_iter_close_container = nullptr;
		decltype(&dbus_message_iter_init) dbus_message_iter_init = nullptr;
		decltype(&dbus_message_iter_get_arg_type) dbus_message_iter_get_arg_type = nullptr;
		decltype(&dbus_message_iter_get_basic) dbus_message_iter_get_basic = nullptr;
		decltype(&dbus_message_iter_next) dbus_message_iter_next = nullptr;
		decltype(&dbus_message_iter_get_element_type) dbus_message_iter_get_element_type = nullptr;
		decltype(&dbus_message_iter_get_fixed_array) dbus_message_iter_get_fixed_array = nullptr;
		decltype(&dbus_message_iter_recurse) dbus_message_iter_recurse = nullptr;
		decltype(&dbus_message_iter_has_next) dbus_message_iter_has_next = nullptr;
		decltype(&dbus_message_set_serial) dbus_message_set_serial = nullptr;
		decltype(&dbus_error_init) dbus_error_init = nullptr;
		decltype(&dbus_error_free) dbus_error_free = nullptr;
		decltype(&dbus_error_is_set) dbus_error_is_set = nullptr;
		decltype(&dbus_move_error) dbus_move_error = nullptr;
		decltype(&dbus_connection_open) dbus_connection_open = nullptr;
		decltype(&dbus_connection_open_private) dbus_connection_open_private = nullptr;
		decltype(&dbus_connection_send_with_reply_and_block) dbus_connection_send_with_reply_and_block = nullptr;
		decltype(&dbus_connection_get_is_connected) dbus_connection_get_is_connected = nullptr;
		decltype(&dbus_connection_close) dbus_connection_close = nullptr;
		decltype(&dbus_connection_unref) dbus_connection_unref = nullptr;
		decltype(&dbus_bus_get) dbus_bus_get = nullptr;
		decltype(&dbus_bus_add_match) dbus_bus_add_match = nullptr;
		decltype(&dbus_connection_read_write) dbus_connection_read_write = nullptr;
		decltype(&dbus_connection_pop_message) dbus_connection_pop_message = nullptr;
		decltype(&dbus_message_get_interface) dbus_message_get_interface = nullptr;
		decltype(&dbus_message_get_member) dbus_message_get_member = nullptr;
		decltype(&dbus_message_get_path) dbus_message_get_path = nullptr;
		decltype(&dbus_connection_get_unix_fd) dbus_connection_get_unix_fd = nullptr;
		decltype(&dbus_connection_dispatch) dbus_connection_dispatch = nullptr;

	protected:
		void fp_ClearSymbols() override
		{
			dbus_message_new_method_call = nullptr;
			dbus_message_new_method_return = nullptr;
			dbus_message_new_signal = nullptr;
			dbus_message_new_error = nullptr;
			dbus_message_unref = nullptr;
			dbus_message_copy = nullptr;
			dbus_message_get_type = nullptr;
			dbus_message_iter_init_append = nullptr;
			dbus_message_iter_append_basic = nullptr;
			dbus_message_iter_open_container = nullptr;
			dbus_message_iter_append_fixed_array = nullptr;
			dbus_message_iter_close_container = nullptr;
			dbus_message_iter_init = nullptr;
			dbus_message_iter_get_arg_type = nullptr;
			dbus_message_iter_get_basic = nullptr;
			dbus_message_iter_next = nullptr;
			dbus_message_iter_get_element_type = nullptr;
			dbus_message_iter_get_fixed_array = nullptr;
			dbus_message_iter_recurse = nullptr;
			dbus_message_iter_has_next = nullptr;
			dbus_message_set_serial = nullptr;
			dbus_error_init = nullptr;
			dbus_error_free = nullptr;
			dbus_error_is_set = nullptr;
			dbus_move_error = nullptr;
			dbus_connection_open = nullptr;
			dbus_connection_open_private = nullptr;
			dbus_connection_send_with_reply_and_block = nullptr;
			dbus_connection_get_is_connected = nullptr;
			dbus_connection_close = nullptr;
			dbus_connection_unref = nullptr;
			dbus_bus_get = nullptr;
			dbus_bus_add_match = nullptr;
			dbus_connection_read_write = nullptr;
			dbus_connection_pop_message = nullptr;
			dbus_message_get_interface = nullptr;
			dbus_message_get_member = nullptr;
			dbus_message_get_path = nullptr;
			dbus_connection_get_unix_fd = nullptr;
			dbus_connection_dispatch = nullptr;
		}

		void fp_FetchSymbols() override
		{
			fp_Fetch(dbus_message_new_method_call, "dbus_message_new_method_call");
			fp_Fetch(dbus_message_new_method_return, "dbus_message_new_method_return");
			fp_Fetch(dbus_message_new_signal, "dbus_message_new_signal");
			fp_Fetch(dbus_message_new_error, "dbus_message_new_error");
			fp_Fetch(dbus_message_unref, "dbus_message_unref");
			fp_Fetch(dbus_message_copy, "dbus_message_copy");
			fp_Fetch(dbus_message_get_type, "dbus_message_get_type");
			fp_Fetch(dbus_message_iter_init_append, "dbus_message_iter_init_append");
			fp_Fetch(dbus_message_iter_append_basic, "dbus_message_iter_append_basic");
			fp_Fetch(dbus_message_iter_open_container, "dbus_message_iter_open_container");
			fp_Fetch(dbus_message_iter_append_fixed_array, "dbus_message_iter_append_fixed_array");
			fp_Fetch(dbus_message_iter_close_container, "dbus_message_iter_close_container");
			fp_Fetch(dbus_message_iter_init, "dbus_message_iter_init");
			fp_Fetch(dbus_message_iter_get_arg_type, "dbus_message_iter_get_arg_type");
			fp_Fetch(dbus_message_iter_get_basic, "dbus_message_iter_get_basic");
			fp_Fetch(dbus_message_iter_next, "dbus_message_iter_next");
			fp_Fetch(dbus_message_iter_get_element_type, "dbus_message_iter_get_element_type");
			fp_Fetch(dbus_message_iter_get_fixed_array, "dbus_message_iter_get_fixed_array");
			fp_Fetch(dbus_message_iter_recurse, "dbus_message_iter_recurse");
			fp_Fetch(dbus_message_iter_has_next, "dbus_message_iter_has_next");
			fp_Fetch(dbus_message_set_serial, "dbus_message_set_serial");
			fp_Fetch(dbus_error_init, "dbus_error_init");
			fp_Fetch(dbus_error_free, "dbus_error_free");
			fp_Fetch(dbus_error_is_set, "dbus_error_is_set");
			fp_Fetch(dbus_move_error, "dbus_move_error");
			fp_Fetch(dbus_connection_open, "dbus_connection_open");
			fp_Fetch(dbus_connection_open_private, "dbus_connection_open_private");
			fp_Fetch(dbus_connection_send_with_reply_and_block, "dbus_connection_send_with_reply_and_block");
			fp_Fetch(dbus_connection_get_is_connected, "dbus_connection_get_is_connected");
			fp_Fetch(dbus_connection_close, "dbus_connection_close");
			fp_Fetch(dbus_connection_unref, "dbus_connection_unref");
			fp_Fetch(dbus_bus_get, "dbus_bus_get");
			fp_Fetch(dbus_bus_add_match, "dbus_bus_add_match");
			fp_Fetch(dbus_connection_read_write, "dbus_connection_read_write");
			fp_Fetch(dbus_connection_pop_message, "dbus_connection_pop_message");
			fp_Fetch(dbus_message_get_interface, "dbus_message_get_interface");
			fp_Fetch(dbus_message_get_member, "dbus_message_get_member");
			fp_Fetch(dbus_message_get_path, "dbus_message_get_path");
			fp_Fetch(dbus_connection_get_unix_fd, "dbus_connection_get_unix_fd");
			fp_Fetch(dbus_connection_dispatch, "dbus_connection_dispatch");
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
	CMessage::CMessage
		(
			EMessageType _Type
			, char const *_pService
			, char const *_pPath
			, char const *_pInterface
			, char const *_pMethod
			, CSystem &_System
		)
		: mp_Lib(*_System.mp_pLib)
		, mp_pMsg(nullptr)
	{
		if (_Type != EMessageType_Method)
			DMibDBusError("Incorrect message constructor used.");

		mp_pMsg = mp_Lib.dbus_message_new_method_call(_pService, _pPath, _pInterface, _pMethod);

		if (!mp_pMsg)
			DMibDBusError("Failed to create new method call message.");
	}

	// New method return message. _Type MUST == EMessageType_MethodReturn
	CMessage::CMessage
		(
			EMessageType _Type
			, CMessage &_InReplyTo
			, CSystem &_System
		)
		: mp_Lib(*_System.mp_pLib)
		, mp_pMsg(nullptr)
	{
		if (_Type != EMessageType_MethodReturn)
			DMibDBusError("Incorrect message constructor used.");

		mp_pMsg = mp_Lib.dbus_message_new_method_return(_InReplyTo.mp_pMsg);

		if (!mp_pMsg)
			DMibDBusError("Failed to create new method return call message.");
	}

	// New signal message. _Type MUST == EMessageType_Signal
	CMessage::CMessage
		(
			EMessageType _Type
			, char const *_pPath
			, char const *_pInterface
			, char const *_pName
			, CSystem &_System
		)
		: mp_Lib(*_System.mp_pLib)
		, mp_pMsg(nullptr)
	{
		if (_Type != EMessageType_Signal)
			DMibDBusError("Incorrect message constructor used.");

		mp_pMsg = mp_Lib.dbus_message_new_signal(_pPath, _pInterface, _pName);

		if (!mp_pMsg)
			DMibDBusError("Failed to create new signal message.");
	}

	// New error message. _Type MUST == EMessageType_Error
	CMessage::CMessage
		(
			EMessageType _Type
			, CMessage &_InReplyTo
			, char const *_pErrorName
			, char const *_pErrorMessage
			, CSystem &_System
		)
		: mp_Lib(*_System.mp_pLib)
		, mp_pMsg(nullptr)
	{
		if (_Type != EMessageType_Error)
			DMibDBusError("Incorrect message constructor used.");

		mp_pMsg = mp_Lib.dbus_message_new_error(_InReplyTo.mp_pMsg, _pErrorName, _pErrorMessage);

		if (!mp_pMsg)
			DMibDBusError("Failed to create new error message.");
	}

	CMessage::CMessage(CMessage const &_ToCopy)
		: mp_Lib(_ToCopy.mp_Lib)
		, mp_pMsg(nullptr)
	{
		mp_pMsg = mp_Lib.dbus_message_copy( const_cast<DBusMessage*>(_ToCopy.mp_pMsg) );

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

	CMessage::CMessage(DBusMessage* _pMsg, CDBusLibrary &_Lib)
		: mp_Lib(_Lib)
		, mp_pMsg(_pMsg)
	{
	}


	CMessage::~CMessage()
	{
		if (mp_pMsg)
			mp_Lib.dbus_message_unref(mp_pMsg);
	}

	CMessage& CMessage::operator=(CMessage &_ToCopy)
	{
		if (mp_pMsg)
			mp_Lib.dbus_message_unref(mp_pMsg);

		if (_ToCopy.mp_pMsg)
		{
			mp_pMsg = mp_Lib.dbus_message_copy( const_cast<DBusMessage*>(_ToCopy.mp_pMsg) );
			if (!mp_pMsg)
				DMibDBusError("Failed to copy message.");
		}
		else
			mp_pMsg = nullptr;

		return *this;
	}

	CMessage& CMessage::operator=(CMessage &&_ToMove)
	{
		if (mp_pMsg)
			mp_Lib.dbus_message_unref(mp_pMsg);

		mp_pMsg = _ToMove.mp_pMsg;
		_ToMove.mp_pMsg = nullptr;

		return *this;
	}


	EMessageType CMessage::f_GetType() const
	{
		if (!mp_pMsg)
			return EMessageType_Unknown;

		switch(mp_Lib.dbus_message_get_type(mp_pMsg))
		{
			case DBUS_MESSAGE_TYPE_METHOD_CALL:
				return EMessageType_Method;
			case DBUS_MESSAGE_TYPE_METHOD_RETURN:
				return EMessageType_MethodReturn;
			case DBUS_MESSAGE_TYPE_ERROR:
				return EMessageType_Error;
			case DBUS_MESSAGE_TYPE_SIGNAL:
				return EMessageType_Signal;
			default:
				return EMessageType_Unknown;
		}
	}

	void CMessage::f_SetSerial(uint32 _Serial) // Only used for testing.
	{
		if (mp_pMsg)
			mp_Lib.dbus_message_set_serial(mp_pMsg, _Serial);
	}

	char const* CMessage::f_GetInterface() const
	{
		if (!mp_pMsg)
			return nullptr;
		return mp_Lib.dbus_message_get_interface(mp_pMsg);
	}

	char const* CMessage::f_GetMember() const
	{
		if (!mp_pMsg)
			return nullptr;
		return mp_Lib.dbus_message_get_member(mp_pMsg);
	}

	char const* CMessage::f_GetPath() const
	{
		if (!mp_pMsg)
			return nullptr;
		return mp_Lib.dbus_message_get_path(mp_pMsg);
	}

	//
	// CMessageWriter
	//

	struct CMessageWriter::CInternal
	{
		CInternal(CMessage &_Message)
			: mp_Lib(_Message.mp_Lib)
		{
		}

		CDBusLibrary &mp_Lib;
		DBusMessageIter mp_Iter;
	};

	CMessageWriter::CMessageWriter(CMessage& _Message)
		: mp_pInternal(fg_Construct(_Message))
	{
		mp_pInternal->mp_Lib.dbus_message_iter_init_append(_Message.mp_pMsg, &mp_pInternal->mp_Iter);
	}

	CMessageWriter::~CMessageWriter()
	{
	}

	template<>
	bool CMessageWriter::f_AppendArg<uint8>(uint8  const& _Value)
	{
		char Value = _Value;

		return mp_pInternal->mp_Lib.dbus_message_iter_append_basic(&mp_pInternal->mp_Iter, DBUS_TYPE_BYTE, &Value) ? true : false;
	}


	template<>
	bool CMessageWriter::f_AppendArg<int16>(int16  const& _Value)
	{
		dbus_int16_t Value = _Value;

		return mp_pInternal->mp_Lib.dbus_message_iter_append_basic(&mp_pInternal->mp_Iter, DBUS_TYPE_INT16, &Value) ? true : false;
	}

	template<>
	bool CMessageWriter::f_AppendArg<uint16>(uint16  const& _Value)
	{
		dbus_uint16_t Value = _Value;

		return mp_pInternal->mp_Lib.dbus_message_iter_append_basic(&mp_pInternal->mp_Iter, DBUS_TYPE_UINT16, &Value) ? true : false;
	}

	template<>
	bool CMessageWriter::f_AppendArg<int32>(int32  const& _Value)
	{
		dbus_int32_t Value = _Value;

		return mp_pInternal->mp_Lib.dbus_message_iter_append_basic(&mp_pInternal->mp_Iter, DBUS_TYPE_INT32, &Value) ? true : false;
	}

	template<>
	bool CMessageWriter::f_AppendArg<uint32>(uint32  const& _Value)
	{
		dbus_uint32_t Value = _Value;

		return mp_pInternal->mp_Lib.dbus_message_iter_append_basic(&mp_pInternal->mp_Iter, DBUS_TYPE_UINT32, &Value) ? true : false;
	}


	template<>
	bool CMessageWriter::f_AppendArg<int64>(int64  const& _Value)
	{
		dbus_int64_t Value = _Value;

		return mp_pInternal->mp_Lib.dbus_message_iter_append_basic(&mp_pInternal->mp_Iter, DBUS_TYPE_INT64, &Value) ? true : false;
	}

	template<>
	bool CMessageWriter::f_AppendArg<uint64>(uint64  const& _Value)
	{
		dbus_uint64_t Value = _Value;

		return mp_pInternal->mp_Lib.dbus_message_iter_append_basic(&mp_pInternal->mp_Iter, DBUS_TYPE_UINT64, &Value) ? true : false;
	}

	template<>
	bool CMessageWriter::f_AppendArg<char const*>(char const* const& _Value)
	{
		// TODO: Encoding
		return mp_pInternal->mp_Lib.dbus_message_iter_append_basic(&mp_pInternal->mp_Iter, DBUS_TYPE_STRING, &_Value) ? true : false;
	}

	template<>
	bool CMessageWriter::f_AppendArg<NStr::CStr>(NStr::CStr const& _Value)
	{
		// TODO: Encoding
		const char* pValue = _Value.f_GetStr();
		return mp_pInternal->mp_Lib.dbus_message_iter_append_basic(&mp_pInternal->mp_Iter, DBUS_TYPE_STRING, &pValue) ? true : false;
	}

	template<>
	bool CMessageWriter::f_AppendArg<NStr::CStrSecure>(NStr::CStrSecure const& _Value)
	{
		// TODO: Encoding
		const char* pValue = _Value.f_GetStr();
		return mp_pInternal->mp_Lib.dbus_message_iter_append_basic(&mp_pInternal->mp_Iter, DBUS_TYPE_STRING, &pValue) ? true : false;
	}

	template<>
	bool CMessageWriter::f_AppendArg<bool>(bool const& _Value)
	{
		dbus_int32_t Value = _Value;
		return mp_pInternal->mp_Lib.dbus_message_iter_append_basic(&mp_pInternal->mp_Iter, DBUS_TYPE_BOOLEAN, &Value) ? true : false;
	}

	template<>
	bool CMessageWriter::f_AppendArg<NContainer::CByteVector>(NContainer::CByteVector const& _Value)
	{
		char* pBytes = (char*)_Value.f_GetArray();
		dbus_uint32_t Len = _Value.f_GetLen();

		dbus_bool_t bRet;
		DBusMessageIter ArrayIter;

		bRet = mp_pInternal->mp_Lib.dbus_message_iter_open_container(&mp_pInternal->mp_Iter, DBUS_TYPE_ARRAY, "y", &ArrayIter);
		if (bRet)
		{
			bRet = mp_pInternal->mp_Lib.dbus_message_iter_append_fixed_array(&ArrayIter, DBUS_TYPE_BYTE, &pBytes, Len);

			bRet = bRet &&  mp_pInternal->mp_Lib.dbus_message_iter_close_container(&mp_pInternal->mp_Iter, &ArrayIter);
		}

		return bRet ? true : false;
	}

	template<>
	bool CMessageWriter::f_AppendArg<NContainer::TCVector<NStr::CStr>>(NContainer::TCVector<NStr::CStr> const& _Value)
	{
		dbus_bool_t bRet;
		DBusMessageIter ArrayIter;

		bRet = mp_pInternal->mp_Lib.dbus_message_iter_open_container(&mp_pInternal->mp_Iter, DBUS_TYPE_ARRAY, "s", &ArrayIter);
		if (bRet)
		{

			for (auto StrIter = _Value.f_GetIterator()
				;StrIter && bRet
				;++StrIter)
			{
				const char* pValue = (*StrIter).f_GetStr();
				bRet = bRet && (mp_pInternal->mp_Lib.dbus_message_iter_append_basic(&ArrayIter, DBUS_TYPE_STRING, &pValue) ? true : false);
			}

			bRet = bRet &&  mp_pInternal->mp_Lib.dbus_message_iter_close_container(&mp_pInternal->mp_Iter, &ArrayIter);
		}

		return bRet ? true : false;
	}

	//
	// CMessageReader
	//

	struct CMessageReader::CInternal
	{
		CInternal(CMessage const &_Message)
			: mp_Lib(_Message.mp_Lib)
		{
		}

		CDBusLibrary &mp_Lib;
		DBusMessageIter mp_Iter;
	};

	CMessageReader::CMessageReader(CMessage const& _Message)
		: mp_pInternal(fg_Construct(_Message))
	{
		mp_pInternal->mp_Lib.dbus_message_iter_init(_Message.mp_pMsg, &mp_pInternal->mp_Iter);
	}

	CMessageReader::~CMessageReader()
	{

	}

	template<>
	bool CMessageReader::f_PopArg<uint8>(uint8& _oValue)
	{
		if (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_BYTE)
			return false;

		char Value;
		mp_pInternal->mp_Lib.dbus_message_iter_get_basic(&mp_pInternal->mp_Iter, &Value);
		_oValue = (uint8)Value;

		mp_pInternal->mp_Lib.dbus_message_iter_next(&mp_pInternal->mp_Iter);

		return true;
	}

	template<>
	bool CMessageReader::f_PopArg<int16>(int16& _oValue)
	{
		if (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_INT16)
			return false;

		dbus_int16_t Value;
		mp_pInternal->mp_Lib.dbus_message_iter_get_basic(&mp_pInternal->mp_Iter, &Value);
		_oValue = Value;

		mp_pInternal->mp_Lib.dbus_message_iter_next(&mp_pInternal->mp_Iter);

		return true;
	}

	template<>
	bool CMessageReader::f_PopArg<uint16>(uint16& _oValue)
	{
		if (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_UINT16)
			return false;

		dbus_uint16_t Value;
		mp_pInternal->mp_Lib.dbus_message_iter_get_basic(&mp_pInternal->mp_Iter, &Value);
		_oValue = Value;

		mp_pInternal->mp_Lib.dbus_message_iter_next(&mp_pInternal->mp_Iter);

		return true;
	}

	template<>
	bool CMessageReader::f_PopArg<int32>(int32& _oValue)
	{
		if (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_INT32)
			return false;

		dbus_int32_t Value;
		mp_pInternal->mp_Lib.dbus_message_iter_get_basic(&mp_pInternal->mp_Iter, &Value);
		_oValue = Value;

		mp_pInternal->mp_Lib.dbus_message_iter_next(&mp_pInternal->mp_Iter);

		return true;
	}

	template<>
	bool CMessageReader::f_PopArg<uint32>(uint32& _oValue)
	{
		if (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_UINT32)
			return false;

		dbus_uint32_t Value;
		mp_pInternal->mp_Lib.dbus_message_iter_get_basic(&mp_pInternal->mp_Iter, &Value);
		_oValue = Value;

		mp_pInternal->mp_Lib.dbus_message_iter_next(&mp_pInternal->mp_Iter);

		return true;
	}


	template<>
	bool CMessageReader::f_PopArg<int64>(int64& _oValue)
	{
		if (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_INT64)
			return false;

		dbus_int64_t Value;
		mp_pInternal->mp_Lib.dbus_message_iter_get_basic(&mp_pInternal->mp_Iter, &Value);
		_oValue = Value;

		mp_pInternal->mp_Lib.dbus_message_iter_next(&mp_pInternal->mp_Iter);

		return true;
	}

	template<>
	bool CMessageReader::f_PopArg<uint64>(uint64& _oValue)
	{
		if (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_UINT64)
			return false;

		dbus_uint64_t Value;
		mp_pInternal->mp_Lib.dbus_message_iter_get_basic(&mp_pInternal->mp_Iter, &Value);
		_oValue = Value;

		mp_pInternal->mp_Lib.dbus_message_iter_next(&mp_pInternal->mp_Iter);

		return true;
	}

	template<>
	bool CMessageReader::f_PopArg<NStr::CStr>(NStr::CStr& _oValue)
	{
		// TODO: Encoding
		if (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_STRING)
			return false;

		char *pValue;
		mp_pInternal->mp_Lib.dbus_message_iter_get_basic(&mp_pInternal->mp_Iter, &pValue);
		_oValue = pValue;

		mp_pInternal->mp_Lib.dbus_message_iter_next(&mp_pInternal->mp_Iter);

		return true;
	}

	template<>
	bool CMessageReader::f_PopArg<NStr::CStrSecure>(NStr::CStrSecure& _oValue)
	{
		// TODO: Encoding
		if (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_STRING)
			return false;

		char *pValue;
		mp_pInternal->mp_Lib.dbus_message_iter_get_basic(&mp_pInternal->mp_Iter, &pValue);
		_oValue = pValue;

		mp_pInternal->mp_Lib.dbus_message_iter_next(&mp_pInternal->mp_Iter);

		return true;
	}

	template<>
	bool CMessageReader::f_PopArg<bool>(bool& _oValue)
	{
		if (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_BOOLEAN)
			return false;

		dbus_bool_t Value;
		mp_pInternal->mp_Lib.dbus_message_iter_get_basic(&mp_pInternal->mp_Iter, &Value);
		_oValue = Value;

		mp_pInternal->mp_Lib.dbus_message_iter_next(&mp_pInternal->mp_Iter);

		return true;
	}

	template<>
	bool CMessageReader::f_PopArg<NContainer::CByteVector>(NContainer::CByteVector& _oValue)
	{
		if (	mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_ARRAY
			||	mp_pInternal->mp_Lib.dbus_message_iter_get_element_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_BYTE)
			return false;

		DBusMessageIter ArrayIter;

		mp_pInternal->mp_Lib.dbus_message_iter_recurse(&mp_pInternal->mp_Iter, &ArrayIter);

		char* pBytes;
		int Len;

		mp_pInternal->mp_Lib.dbus_message_iter_get_fixed_array (&ArrayIter, &pBytes, &Len);

		_oValue.f_SetLen(Len);
		NMemory::fg_MemCopy(_oValue.f_GetArray(), pBytes, Len);

		mp_pInternal->mp_Lib.dbus_message_iter_next(&mp_pInternal->mp_Iter);

		return true;
	}

	template<>
	bool CMessageReader::f_PopArg<NContainer::TCVector<NStr::CStr>>(NContainer::TCVector<NStr::CStr>& _oValue)
	{
		if (	mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_ARRAY
			||	mp_pInternal->mp_Lib.dbus_message_iter_get_element_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_STRING)
			return false;

		DBusMessageIter ArrayIter;

		mp_pInternal->mp_Lib.dbus_message_iter_recurse(&mp_pInternal->mp_Iter, &ArrayIter);

		char *pValue;

		while (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&ArrayIter) == DBUS_TYPE_STRING)
		{
			mp_pInternal->mp_Lib.dbus_message_iter_get_basic(&ArrayIter, &pValue);
			_oValue.f_Insert( NStr::CStr(pValue) );
			mp_pInternal->mp_Lib.dbus_message_iter_next(&ArrayIter);
		}

		mp_pInternal->mp_Lib.dbus_message_iter_next(&mp_pInternal->mp_Iter);

		return true;
	}

	bool CMessageReader::f_ArgAvailable()
	{
		return mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_INVALID;;
	}

	namespace
	{
		// Helper to read a variant value from a sub-iterator positioned at a variant
		bool fg_ReadVariantValue(CDBusLibrary &_Lib, DBusMessageIter &_VariantIter, CDBusVariant &_oValue)
		{
			int Type = _Lib.dbus_message_iter_get_arg_type(&_VariantIter);

			switch (Type)
			{
				case DBUS_TYPE_BOOLEAN:
				{
					dbus_bool_t Value;
					_Lib.dbus_message_iter_get_basic(&_VariantIter, &Value);
					_oValue = (bool)Value;
					return true;
				}
				case DBUS_TYPE_BYTE:
				{
					char Value;
					_Lib.dbus_message_iter_get_basic(&_VariantIter, &Value);
					_oValue = (uint8)Value;
					return true;
				}
				case DBUS_TYPE_INT16:
				{
					dbus_int16_t Value;
					_Lib.dbus_message_iter_get_basic(&_VariantIter, &Value);
					_oValue = (int16)Value;
					return true;
				}
				case DBUS_TYPE_UINT16:
				{
					dbus_uint16_t Value;
					_Lib.dbus_message_iter_get_basic(&_VariantIter, &Value);
					_oValue = (uint16)Value;
					return true;
				}
				case DBUS_TYPE_INT32:
				{
					dbus_int32_t Value;
					_Lib.dbus_message_iter_get_basic(&_VariantIter, &Value);
					_oValue = (int32)Value;
					return true;
				}
				case DBUS_TYPE_UINT32:
				{
					dbus_uint32_t Value;
					_Lib.dbus_message_iter_get_basic(&_VariantIter, &Value);
					_oValue = (uint32)Value;
					return true;
				}
				case DBUS_TYPE_INT64:
				{
					dbus_int64_t Value;
					_Lib.dbus_message_iter_get_basic(&_VariantIter, &Value);
					_oValue = (int64)Value;
					return true;
				}
				case DBUS_TYPE_UINT64:
				{
					dbus_uint64_t Value;
					_Lib.dbus_message_iter_get_basic(&_VariantIter, &Value);
					_oValue = (uint64)Value;
					return true;
				}
				case DBUS_TYPE_DOUBLE:
				{
					double Value;
					_Lib.dbus_message_iter_get_basic(&_VariantIter, &Value);
					_oValue = (fp64)Value;
					return true;
				}
				case DBUS_TYPE_STRING:
				case DBUS_TYPE_OBJECT_PATH:
				{
					char *pValue;
					_Lib.dbus_message_iter_get_basic(&_VariantIter, &pValue);
					_oValue = NStr::CStr(pValue);
					return true;
				}
				default:
					// Unsupported variant type - store empty string as fallback
					_oValue = NStr::CStr();
					return true;
			}
		}

		// Helper to read a{sv} dict from a sub-iterator
		bool fg_ReadStringVariantDict(CDBusLibrary &_Lib, DBusMessageIter &_ArrayIter, CDBusStringVariantDict &_oDict)
		{
			_oDict.f_Clear();

			while (_Lib.dbus_message_iter_get_arg_type(&_ArrayIter) == DBUS_TYPE_DICT_ENTRY)
			{
				DBusMessageIter DictEntryIter;
				_Lib.dbus_message_iter_recurse(&_ArrayIter, &DictEntryIter);

				// Read key (string)
				if (_Lib.dbus_message_iter_get_arg_type(&DictEntryIter) != DBUS_TYPE_STRING)
					return false;

				char *pKey;
				_Lib.dbus_message_iter_get_basic(&DictEntryIter, &pKey);
				NStr::CStr Key(pKey);

				_Lib.dbus_message_iter_next(&DictEntryIter);

				// Read value (variant)
				if (_Lib.dbus_message_iter_get_arg_type(&DictEntryIter) != DBUS_TYPE_VARIANT)
					return false;

				DBusMessageIter VariantIter;
				_Lib.dbus_message_iter_recurse(&DictEntryIter, &VariantIter);

				CDBusVariant Value;
				if (!fg_ReadVariantValue(_Lib, VariantIter, Value))
					return false;

				_oDict[Key] = fg_Move(Value);

				_Lib.dbus_message_iter_next(&_ArrayIter);
			}

			return true;
		}
	}

	template<>
	bool CMessageReader::f_PopArg<CDBusVariant>(CDBusVariant& _oValue)
	{
		if (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_VARIANT)
			return false;

		DBusMessageIter VariantIter;
		mp_pInternal->mp_Lib.dbus_message_iter_recurse(&mp_pInternal->mp_Iter, &VariantIter);

		if (!fg_ReadVariantValue(mp_pInternal->mp_Lib, VariantIter, _oValue))
			return false;

		mp_pInternal->mp_Lib.dbus_message_iter_next(&mp_pInternal->mp_Iter);
		return true;
	}

	template<>
	bool CMessageReader::f_PopArg<CDBusStringVariantDict>(CDBusStringVariantDict& _oValue)
	{
		if (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_ARRAY)
			return false;

		DBusMessageIter ArrayIter;
		mp_pInternal->mp_Lib.dbus_message_iter_recurse(&mp_pInternal->mp_Iter, &ArrayIter);

		if (!fg_ReadStringVariantDict(mp_pInternal->mp_Lib, ArrayIter, _oValue))
			return false;

		mp_pInternal->mp_Lib.dbus_message_iter_next(&mp_pInternal->mp_Iter);
		return true;
	}

	template<>
	bool CMessageReader::f_PopArg<CDBusUInt64DictDict>(CDBusUInt64DictDict& _oValue)
	{
		if (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&mp_pInternal->mp_Iter) != DBUS_TYPE_ARRAY)
			return false;

		_oValue.f_Clear();

		DBusMessageIter ArrayIter;
		mp_pInternal->mp_Lib.dbus_message_iter_recurse(&mp_pInternal->mp_Iter, &ArrayIter);

		while (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&ArrayIter) == DBUS_TYPE_DICT_ENTRY)
		{
			DBusMessageIter DictEntryIter;
			mp_pInternal->mp_Lib.dbus_message_iter_recurse(&ArrayIter, &DictEntryIter);

			// Read key (uint64)
			if (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&DictEntryIter) != DBUS_TYPE_UINT64)
				return false;

			dbus_uint64_t Key;
			mp_pInternal->mp_Lib.dbus_message_iter_get_basic(&DictEntryIter, &Key);

			mp_pInternal->mp_Lib.dbus_message_iter_next(&DictEntryIter);

			// Read value (a{sv})
			if (mp_pInternal->mp_Lib.dbus_message_iter_get_arg_type(&DictEntryIter) != DBUS_TYPE_ARRAY)
				return false;

			DBusMessageIter InnerArrayIter;
			mp_pInternal->mp_Lib.dbus_message_iter_recurse(&DictEntryIter, &InnerArrayIter);

			CDBusStringVariantDict InnerDict;
			if (!fg_ReadStringVariantDict(mp_pInternal->mp_Lib, InnerArrayIter, InnerDict))
				return false;

			_oValue[Key] = fg_Move(InnerDict);

			mp_pInternal->mp_Lib.dbus_message_iter_next(&ArrayIter);
		}

		mp_pInternal->mp_Lib.dbus_message_iter_next(&mp_pInternal->mp_Iter);
		return true;
	}

	//
	// CError
	//

	struct CError::CInternal
	{
		CInternal(CDBusLibrary &_Lib)
			: mp_Lib(_Lib)
		{
		}

		CDBusLibrary &mp_Lib;
		DBusError mp_Error;
	};

	CError::CError(CSystem &_Sys)
		: mp_pInternal(fg_Construct(*_Sys.mp_pLib))
	{
		mp_pInternal->mp_Lib.dbus_error_init(&mp_pInternal->mp_Error);
	}

	CError::CError(CError &&_ToMove)
		: mp_pInternal(fg_Construct(_ToMove.mp_pInternal->mp_Lib))
	{
		mp_pInternal->mp_Lib.dbus_error_init(&mp_pInternal->mp_Error);
		mp_pInternal->mp_Lib.dbus_move_error(&_ToMove.mp_pInternal->mp_Error, &mp_pInternal->mp_Error);
	}

	CError::CError(CDBusLibrary &_Lib)
		: mp_pInternal(fg_Construct(_Lib))
	{
		mp_pInternal->mp_Lib.dbus_error_init(&mp_pInternal->mp_Error);
	}

	CError::~CError()
	{
		mp_pInternal->mp_Lib.dbus_error_free(&mp_pInternal->mp_Error);
	}

	CError& CError::operator=(CError&& _ToMove)
	{
		mp_pInternal->mp_Lib.dbus_error_free(&mp_pInternal->mp_Error);
		mp_pInternal->mp_Lib.dbus_move_error(&_ToMove.mp_pInternal->mp_Error, &mp_pInternal->mp_Error);
		return *this;
	}

	bool CError::f_IsSet() const
	{
		return mp_pInternal->mp_Lib.dbus_error_is_set(const_cast<DBusError*>(&mp_pInternal->mp_Error));
	}

	char const* CError::f_GetName() const
	{
		return mp_pInternal->mp_Error.name;
	}

	char const* CError::f_GetMessage() const
	{
		return mp_pInternal->mp_Error.message;
	}

	void CError::f_Clear()
	{
		mp_pInternal->mp_Lib.dbus_error_free(&mp_pInternal->mp_Error);
	}

	void CError::f_Take(DBusError& _FromHere)
	{
		mp_pInternal->mp_Lib.dbus_move_error(&_FromHere, &mp_pInternal->mp_Error);
	}

	//
	// CConnection
	//

	CConnection::CConnection(CSystem& _Sys)
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

	CError const& CConnection::f_GetLastError() const
	{
		return mp_LastError;
	}

	bool CConnection::f_Open(char const* _pAddress, bool _bPrivate)
	{
		if (mp_pConnection)
		{
			// Cannot open an already open connection.
			return false;
		}

		CError Error(mp_Lib);

		if (!_bPrivate)
		{
			mp_pConnection = mp_Lib.dbus_connection_open(_pAddress, &Error.mp_pInternal->mp_Error);
		}
		else
		{
			mp_pConnection = mp_Lib.dbus_connection_open_private(_pAddress, &Error.mp_pInternal->mp_Error);
		}

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
		switch(_Bus)
		{
			case EDBusBus_Session:
				BusType = DBUS_BUS_SESSION;
				break;
			case EDBusBus_System:
				BusType = DBUS_BUS_SYSTEM;
				break;
		};

		mp_pConnection = mp_Lib.dbus_bus_get(BusType, &Error.mp_pInternal->mp_Error);

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
			{
				mp_Lib.dbus_connection_close(mp_pConnection);
			}
			mp_Lib.dbus_connection_unref(mp_pConnection);
			mp_pConnection = nullptr;
			mp_Flags = EFlag_None;
		}
		return true;
	}

	bool CConnection::f_BlockingSendWithReply(CMessage& _Message, CMessage& _oReply, int _TimeoutMillis)
	{
		CError Error(mp_Lib);

		DBusMessage* pReply = mp_Lib.dbus_connection_send_with_reply_and_block
			(
				mp_pConnection
				, _Message.mp_pMsg
				, _TimeoutMillis
				, &Error.mp_pInternal->mp_Error
			)
		;

		if (!pReply)
		{
			mp_LastError = std::move(Error);
			return false;
		}

		_oReply = CMessage(pReply, mp_Lib);

		return true;
	}

	bool CConnection::f_AddMatch(char const* _pMatchRule)
	{
		if (!mp_pConnection)
			return false;

		CError Error(mp_Lib);
		mp_Lib.dbus_bus_add_match(mp_pConnection, _pMatchRule, &Error.mp_pInternal->mp_Error);

		if (Error.f_IsSet())
		{
			mp_LastError = std::move(Error);
			return false;
		}

		return true;
	}

	bool CConnection::f_BlockingPopMessage(CMessage& _oMessage, int _TimeoutMillis)
	{
		if (!mp_pConnection)
			return false;

		// Read and dispatch incoming messages, blocking until timeout
		if (!mp_Lib.dbus_connection_read_write(mp_pConnection, _TimeoutMillis))
		{
			// Connection closed
			return false;
		}

		// Pop the next message from the queue
		DBusMessage* pMsg = mp_Lib.dbus_connection_pop_message(mp_pConnection);
		if (!pMsg)
		{
			// No message available (timeout or only internal messages)
			return false;
		}

		_oMessage = CMessage(pMsg, mp_Lib);
		return true;
	}

	int CConnection::f_GetUnixFd() const
	{
		if (!mp_pConnection)
			return -1;

		int Fd = -1;
		if (!mp_Lib.dbus_connection_get_unix_fd(mp_pConnection, &Fd))
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

	bool CSystem::f_ReadyForUse()	// f_IsOK will never return true until this has been called and returned true.
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
