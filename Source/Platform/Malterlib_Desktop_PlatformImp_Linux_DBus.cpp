// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include <Mib/Core/Core>
#include "Malterlib_Desktop_PlatformImp_Linux_DBus.h"

namespace NMib
{

	namespace NDBus
	{

		DMibDefineDynamicLibraryClass(CDBusLibrary, NMib::EDLFlag_NoThrow | NMib::EDLFlag_NoAutoLoad, "libdbus-1.so,libdbus-1.so.3"
										,	dbus_message_new_method_call
										,	dbus_message_new_method_return
										,	dbus_message_new_signal
										,	dbus_message_new_error
										,	dbus_message_unref
										,	dbus_message_copy
										,	dbus_message_get_type
										,	dbus_message_iter_init_append
										,	dbus_message_iter_append_basic
										,	dbus_message_iter_open_container
										,	dbus_message_iter_append_fixed_array
										,	dbus_message_iter_close_container
										,	dbus_message_iter_init
										,	dbus_message_iter_get_arg_type
										,	dbus_message_iter_get_basic
										,	dbus_message_iter_next
										,	dbus_message_iter_get_element_type
										,	dbus_message_iter_get_fixed_array
										,	dbus_message_iter_recurse
									  	,	dbus_message_iter_has_next
									  	,	dbus_message_set_serial 	// Only used for test code.
									  	,	dbus_error_init
									  	, 	dbus_error_free
									  	,	dbus_error_is_set
									  	,	dbus_move_error
										,	dbus_connection_open
										,	dbus_connection_open_private
										,	dbus_connection_send_with_reply_and_block
										,	dbus_connection_get_is_connected
										,	dbus_connection_close
										,	dbus_connection_unref
										,	dbus_bus_get
									);

		// 
		// CMessage
		//

		CMessage::CMessage(CSystem& _System)
			: mp_Lib(*_System.mp_pLib)
			, mp_pMsg(nullptr)
		{

		}

		// New method call message. _Type MUST == EMessageType_Method
		CMessage::CMessage(		EMessageType _Type
							,	char const* _pService
							,	char const* _pPath
							,	char const* _pInterface
							,	char const* _pMethod
							, 	CSystem& _System)
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
		CMessage::CMessage(		EMessageType _Type
							,	CMessage& _InReplyTo
							, 	CSystem& _System)
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
		CMessage::CMessage(		EMessageType _Type
							,	char const* _pPath
							,	char const* _pInterface
							,	char const* _pName
							, 	CSystem& _System)
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
		CMessage::CMessage(		EMessageType _Type
							,	CMessage& _InReplyTo
							,	char const* _pErrorName
							, 	char const* _pErrorMessage
							, 	CSystem& _System)
			: mp_Lib(*_System.mp_pLib)
			, mp_pMsg(nullptr)
		{
			if (_Type != EMessageType_Error)
				DMibDBusError("Incorrect message constructor used.");

			mp_pMsg = mp_Lib.dbus_message_new_error(_InReplyTo.mp_pMsg, _pErrorName, _pErrorMessage);

			if (!mp_pMsg)
				DMibDBusError("Failed to create new error message.");
		}

		CMessage::CMessage(CMessage const& _ToCopy)
			: mp_Lib(_ToCopy.mp_Lib)
			, mp_pMsg(nullptr)			
		{
			mp_pMsg = mp_Lib.dbus_message_copy( const_cast<DBusMessage*>(_ToCopy.mp_pMsg) );

			if (!mp_pMsg)
				DMibDBusError("Failed to copy message.");
		}

		CMessage::CMessage(CMessage&& _ToMove)
			: mp_Lib(_ToMove.mp_Lib)
			, mp_pMsg(_ToMove.mp_pMsg)
		{
			_ToMove.mp_pMsg = nullptr;
		}

		CMessage::CMessage(DBusMessage* _pMsg, CSystem& _System)
			: mp_Lib(*_System.mp_pLib)
			, mp_pMsg(_pMsg)
		{
		}

		CMessage::CMessage(DBusMessage* _pMsg, CDBusLibrary& _Lib)
			: mp_Lib(_Lib)
			, mp_pMsg(_pMsg)
		{
		}


		CMessage::~CMessage()
		{
			if (mp_pMsg)
				mp_Lib.dbus_message_unref(mp_pMsg);
		}

		CMessage& CMessage::operator=(CMessage& _ToCopy)
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

		CMessage& CMessage::operator=(CMessage&& _ToMove)
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

		//
		// CMessageWriter
		//

		CMessageWriter::CMessageWriter(CMessage& _Message)
			: mp_Lib(_Message.mp_Lib)
		{
			mp_Lib.dbus_message_iter_init_append(_Message.mp_pMsg, &mp_Iter);
		}

		CMessageWriter::~CMessageWriter()
		{			
		}

		template<>
		bool CMessageWriter::f_AppendArg<uint8>(uint8  const& _Value)
		{
			char Value = _Value;

			return mp_Lib.dbus_message_iter_append_basic(&mp_Iter, DBUS_TYPE_BYTE, &Value) ? true : false;
		}


		template<>
		bool CMessageWriter::f_AppendArg<int16>(int16  const& _Value)
		{
			dbus_int16_t Value = _Value;

			return mp_Lib.dbus_message_iter_append_basic(&mp_Iter, DBUS_TYPE_INT16, &Value) ? true : false;
		}

		template<>
		bool CMessageWriter::f_AppendArg<uint16>(uint16  const& _Value)
		{
			dbus_uint16_t Value = _Value;

			return mp_Lib.dbus_message_iter_append_basic(&mp_Iter, DBUS_TYPE_UINT16, &Value) ? true : false;
		}

		template<>
		bool CMessageWriter::f_AppendArg<int32>(int32  const& _Value)
		{
			dbus_int32_t Value = _Value;

			return mp_Lib.dbus_message_iter_append_basic(&mp_Iter, DBUS_TYPE_INT32, &Value) ? true : false;
		}

		template<>
		bool CMessageWriter::f_AppendArg<uint32>(uint32  const& _Value)
		{
			dbus_uint32_t Value = _Value;

			return mp_Lib.dbus_message_iter_append_basic(&mp_Iter, DBUS_TYPE_UINT32, &Value) ? true : false;
		}


		template<>
		bool CMessageWriter::f_AppendArg<int64>(int64  const& _Value)
		{
			dbus_int64_t Value = _Value;

			return mp_Lib.dbus_message_iter_append_basic(&mp_Iter, DBUS_TYPE_INT64, &Value) ? true : false;
		}

		template<>
		bool CMessageWriter::f_AppendArg<uint64>(uint64  const& _Value)
		{
			dbus_uint64_t Value = _Value;

			return mp_Lib.dbus_message_iter_append_basic(&mp_Iter, DBUS_TYPE_UINT64, &Value) ? true : false;
		}

		template<>
		bool CMessageWriter::f_AppendArg<char const*>(char const* const& _Value)
		{
			// TODO: Encoding			
			return mp_Lib.dbus_message_iter_append_basic(&mp_Iter, DBUS_TYPE_STRING, &_Value) ? true : false;			
		}

		template<>
		bool CMessageWriter::f_AppendArg<NStr::CStr>(NStr::CStr const& _Value)
		{
			// TODO: Encoding			
			const char* pValue = _Value.f_GetStr();
			return mp_Lib.dbus_message_iter_append_basic(&mp_Iter, DBUS_TYPE_STRING, &pValue) ? true : false;
		}

		template<>
		bool CMessageWriter::f_AppendArg<NStr::CStrSecure>(NStr::CStrSecure const& _Value)
		{
			// TODO: Encoding			
			const char* pValue = _Value.f_GetStr();
			return mp_Lib.dbus_message_iter_append_basic(&mp_Iter, DBUS_TYPE_STRING, &pValue) ? true : false;
		}

		template<>
		bool CMessageWriter::f_AppendArg<bool>(bool const& _Value)
		{
			dbus_int32_t Value = _Value;
			return mp_Lib.dbus_message_iter_append_basic(&mp_Iter, DBUS_TYPE_BOOLEAN, &Value) ? true : false;
		}

		template<>
		bool CMessageWriter::f_AppendArg<NContainer::CByteVector>(NContainer::CByteVector const& _Value)
		{
			char* pBytes = (char*)_Value.f_GetArray();
			dbus_uint32_t Len = _Value.f_GetLen();

			dbus_bool_t bRet;
			DBusMessageIter ArrayIter;

			bRet = mp_Lib.dbus_message_iter_open_container(&mp_Iter, DBUS_TYPE_ARRAY, "y", &ArrayIter);
			if (bRet)
			{				
				bRet = mp_Lib.dbus_message_iter_append_fixed_array(&ArrayIter, DBUS_TYPE_BYTE, &pBytes, Len);

				bRet = bRet &&  mp_Lib.dbus_message_iter_close_container(&mp_Iter, &ArrayIter);
			}

			return bRet ? true : false;
		}

		template<>
		bool CMessageWriter::f_AppendArg<NContainer::TCVector<NStr::CStr>>(NContainer::TCVector<NStr::CStr> const& _Value)
		{
			dbus_bool_t bRet;
			DBusMessageIter ArrayIter;

			bRet = mp_Lib.dbus_message_iter_open_container(&mp_Iter, DBUS_TYPE_ARRAY, "s", &ArrayIter);
			if (bRet)
			{

				for (auto StrIter = _Value.f_GetIterator()
					;StrIter && bRet
					;++StrIter)
				{
					const char* pValue = (*StrIter).f_GetStr();
					bRet = bRet && (mp_Lib.dbus_message_iter_append_basic(&ArrayIter, DBUS_TYPE_STRING, &pValue) ? true : false);
				}

				bRet = bRet &&  mp_Lib.dbus_message_iter_close_container(&mp_Iter, &ArrayIter);
			}

			return bRet ? true : false;
		}

		//
		// CMessageReader
		//

		CMessageReader::CMessageReader(CMessage const& _Message)
			: mp_Lib(_Message.mp_Lib)
		{
			mp_Lib.dbus_message_iter_init(_Message.mp_pMsg, &mp_Iter);
		}

		CMessageReader::~CMessageReader()
		{

		}

		template<>
		bool CMessageReader::f_PopArg<uint8>(uint8& _oValue)
		{
			if (mp_Lib.dbus_message_iter_get_arg_type(&mp_Iter) != DBUS_TYPE_BYTE)
				return false;

			char Value;
			mp_Lib.dbus_message_iter_get_basic(&mp_Iter, &Value);
			_oValue = (uint8)Value;

			mp_Lib.dbus_message_iter_next(&mp_Iter);

			return true;
		}

		template<>
		bool CMessageReader::f_PopArg<int16>(int16& _oValue)
		{
			if (mp_Lib.dbus_message_iter_get_arg_type(&mp_Iter) != DBUS_TYPE_INT16)
				return false;

			dbus_int16_t Value;
			mp_Lib.dbus_message_iter_get_basic(&mp_Iter, &Value);
			_oValue = Value;

			mp_Lib.dbus_message_iter_next(&mp_Iter);

			return true;
		}

		template<>
		bool CMessageReader::f_PopArg<uint16>(uint16& _oValue)
		{
			if (mp_Lib.dbus_message_iter_get_arg_type(&mp_Iter) != DBUS_TYPE_UINT16)
				return false;

			dbus_uint16_t Value;
			mp_Lib.dbus_message_iter_get_basic(&mp_Iter, &Value);
			_oValue = Value;

			mp_Lib.dbus_message_iter_next(&mp_Iter);

			return true;
		}

		template<>
		bool CMessageReader::f_PopArg<int32>(int32& _oValue)
		{
			if (mp_Lib.dbus_message_iter_get_arg_type(&mp_Iter) != DBUS_TYPE_INT32)
				return false;

			dbus_int32_t Value;
			mp_Lib.dbus_message_iter_get_basic(&mp_Iter, &Value);
			_oValue = Value;
			
			mp_Lib.dbus_message_iter_next(&mp_Iter);

			return true;
		}

		template<>
		bool CMessageReader::f_PopArg<uint32>(uint32& _oValue)
		{
			if (mp_Lib.dbus_message_iter_get_arg_type(&mp_Iter) != DBUS_TYPE_UINT32)
				return false;

			dbus_uint32_t Value;
			mp_Lib.dbus_message_iter_get_basic(&mp_Iter, &Value);
			_oValue = Value;

			mp_Lib.dbus_message_iter_next(&mp_Iter);

			return true;
		}


		template<>
		bool CMessageReader::f_PopArg<int64>(int64& _oValue)
		{
			if (mp_Lib.dbus_message_iter_get_arg_type(&mp_Iter) != DBUS_TYPE_INT64)
				return false;

			dbus_int64_t Value;
			mp_Lib.dbus_message_iter_get_basic(&mp_Iter, &Value);
			_oValue = Value;

			mp_Lib.dbus_message_iter_next(&mp_Iter);

			return true;
		}

		template<>
		bool CMessageReader::f_PopArg<uint64>(uint64& _oValue)
		{
			if (mp_Lib.dbus_message_iter_get_arg_type(&mp_Iter) != DBUS_TYPE_UINT64)
				return false;

			dbus_uint64_t Value;
			mp_Lib.dbus_message_iter_get_basic(&mp_Iter, &Value);
			_oValue = Value;

			mp_Lib.dbus_message_iter_next(&mp_Iter);

			return true;
		}

		template<>
		bool CMessageReader::f_PopArg<NStr::CStr>(NStr::CStr& _oValue)
		{
			// TODO: Encoding
			if (mp_Lib.dbus_message_iter_get_arg_type(&mp_Iter) != DBUS_TYPE_STRING)
				return false;

			char *pValue;
			mp_Lib.dbus_message_iter_get_basic(&mp_Iter, &pValue);
			_oValue = pValue;

			mp_Lib.dbus_message_iter_next(&mp_Iter);

			return true;
		}

		template<>
		bool CMessageReader::f_PopArg<NStr::CStrSecure>(NStr::CStrSecure& _oValue)
		{
			// TODO: Encoding
			if (mp_Lib.dbus_message_iter_get_arg_type(&mp_Iter) != DBUS_TYPE_STRING)
				return false;

			char *pValue;
			mp_Lib.dbus_message_iter_get_basic(&mp_Iter, &pValue);
			_oValue = pValue;

			mp_Lib.dbus_message_iter_next(&mp_Iter);

			return true;
		}

		template<>
		bool CMessageReader::f_PopArg<bool>(bool& _oValue)
		{
			if (mp_Lib.dbus_message_iter_get_arg_type(&mp_Iter) != DBUS_TYPE_BOOLEAN)
				return false;

			dbus_bool_t Value;
			mp_Lib.dbus_message_iter_get_basic(&mp_Iter, &Value);
			_oValue = Value;

			mp_Lib.dbus_message_iter_next(&mp_Iter);

			return true;
		}

		template<>
		bool CMessageReader::f_PopArg<NContainer::CByteVector>(NContainer::CByteVector& _oValue)
		{
			if (	mp_Lib.dbus_message_iter_get_arg_type(&mp_Iter) != DBUS_TYPE_ARRAY
				||	mp_Lib.dbus_message_iter_get_element_type(&mp_Iter) != DBUS_TYPE_BYTE)
				return false;

			DBusMessageIter ArrayIter;

			mp_Lib.dbus_message_iter_recurse(&mp_Iter, &ArrayIter);

			char* pBytes;
			int Len;

			mp_Lib.dbus_message_iter_get_fixed_array (&ArrayIter, &pBytes, &Len);

			_oValue.f_SetLen(Len);
			NMemory::fg_MemCopy(_oValue.f_GetArray(), pBytes, Len);

			mp_Lib.dbus_message_iter_next(&mp_Iter);

			return true;
		}

		template<>
		bool CMessageReader::f_PopArg<NContainer::TCVector<NStr::CStr>>(NContainer::TCVector<NStr::CStr>& _oValue)
		{
			if (	mp_Lib.dbus_message_iter_get_arg_type(&mp_Iter) != DBUS_TYPE_ARRAY
				||	mp_Lib.dbus_message_iter_get_element_type(&mp_Iter) != DBUS_TYPE_STRING)
				return false;

			DBusMessageIter ArrayIter;

			mp_Lib.dbus_message_iter_recurse(&mp_Iter, &ArrayIter);

			char *pValue;

			while (mp_Lib.dbus_message_iter_get_arg_type(&ArrayIter) == DBUS_TYPE_STRING)
			{
				mp_Lib.dbus_message_iter_get_basic(&ArrayIter, &pValue);
				_oValue.f_Insert( NStr::CStr(pValue) );
				mp_Lib.dbus_message_iter_next(&ArrayIter);
			}

			mp_Lib.dbus_message_iter_next(&mp_Iter);

			return true;
		}

		bool CMessageReader::f_ArgAvailable()
		{
			return mp_Lib.dbus_message_iter_get_arg_type(&mp_Iter) != DBUS_TYPE_INVALID;;
		}

		//
		// CError
		//

		CError::CError(CSystem& _Sys)
			: mp_Lib(*_Sys.mp_pLib)
		{
			mp_Lib.dbus_error_init(&mp_Error);
		}

		CError::CError(CError&& _ToMove)
			: mp_Lib(_ToMove.mp_Lib)			
		{
			mp_Lib.dbus_error_init(&mp_Error);
			mp_Lib.dbus_move_error(&_ToMove.mp_Error, &mp_Error);
		}

		CError::CError(CDBusLibrary& _Lib)
			: mp_Lib(_Lib)
		{
			mp_Lib.dbus_error_init(&mp_Error);
		}

		CError::~CError()
		{
			mp_Lib.dbus_error_free(&mp_Error);
		}

		CError& CError::operator=(CError&& _ToMove)
		{
			mp_Lib.dbus_error_free(&mp_Error);
			mp_Lib.dbus_move_error(&_ToMove.mp_Error, &mp_Error);			
			return *this;
		}

		bool CError::f_IsSet() const
		{
			return mp_Lib.dbus_error_is_set( const_cast<DBusError*>(&mp_Error));
		}

		char const* CError::f_GetName() const
		{
			return mp_Error.name;
		}

		char const* CError::f_GetMessage() const
		{
			return mp_Error.message;
		}

		void CError::f_Clear()
		{
			mp_Lib.dbus_error_free(&mp_Error);
		}

		void CError::f_Take(DBusError& _FromHere)
		{
			mp_Lib.dbus_move_error(&_FromHere, &mp_Error);
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
				mp_pConnection = mp_Lib.dbus_connection_open(_pAddress, &Error.mp_Error);
			}
			else
			{
				mp_pConnection = mp_Lib.dbus_connection_open_private(_pAddress, &Error.mp_Error);
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

			mp_pConnection = mp_Lib.dbus_bus_get(BusType, &Error.mp_Error);

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

			DBusMessage* pReply = mp_Lib.dbus_connection_send_with_reply_and_block(
										mp_pConnection
									,	_Message.mp_pMsg
									, 	_TimeoutMillis
									,	&Error.mp_Error
				);

			if (!pReply)
			{
				mp_LastError = std::move(Error);
				return false;
			}

			_oReply = CMessage(pReply, mp_Lib);

			return true;
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

	} // Namespace NInternal

} // Namespace NMib
