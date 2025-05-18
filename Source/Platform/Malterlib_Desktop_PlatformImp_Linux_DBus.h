// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

/*
	File:			DBus utility interface

	Author:			Michael Wynne

	Contents:		NDBus:
						CMessage
						CMessageReader
						CMessageWriter
						CError
						CConnection
						CSystem

						CDBusException
						DMibDBusError

	Comments:		You should know how DBus works before using this:
						https://en.wikipedia.org/wiki/D-Bus

					You should use the spec & api ref as reference when fixing this:
						Spec: http://dbus.freedesktop.org/doc/dbus-specification.html
						libdbus: http://dbus.freedesktop.org/doc/api/html/

					The following C++ types are mapped to dbus argument types:
						uint8				DBUS_TYPE_BYTE
						int16				DBUS_TYPE_INT16
						uint16				DBUS_TYPE_UINT16
						int32				DBUS_TYPE_INT32
						uint32				DBUS_TYPE_UINT32
						int64				DBUS_TYPE_INT64
						uint64				DBUS_TYPE_UINT64
						bool				DBUS_TYPE_BOOLEAN
						CStr				DBUS_TYPE_STRING
						CByteVector		DBUS_TYPE_ARRAY of DBUS_TYPE_BYTE
						TCVector<CStr>		DBUS_TYPE_ARRAY of DBUS_TYPE_STRING

					The DBus exception CDBusException is only thrown when some bad stuff does down.

					TODO: The other types, including variant.
					TODO: A proper message loop. Only blocking methods supported atm.
					TODO: Registering to receive requests.

	Usage:

			Also see Test_DBus.cpp for working example code.

			// Sub system setup
			NDBus::CSystem DBus;

			if (!DBus.f_IsOK())
				return; // Could not load dbus dynamic lib.

			// Message creation
			NDBus::CMessage Msg
				(
					NDBus::EMessageType_Method
					, "com.malterlib.service"
					, "/modules/test"
					, "com.malterlib.test"
					, "testMethod"
					, DBus
				)
			;

			// Writing a message
			{
				NDBus::CMessageWriter Writer(Msg);

				CByteVector lBytes;
				...

				if (!Writer.f_AppendArgs( (uint32)1, CStr("Str"),  false, lBytes))
				{
					// Error
				}
			}

			NDBus::CMessage Reply;

			NDBus::CConnection Conn(DBus);
			if (!Conn.f_Open("com.malterlib.target"))
			{
				// Error
				// Use Conn.f_GetLastError();
			}

			if (!Conn.f_BlockingSendWithReply(Msg, Reply, gc_DefaultTimeout))
			{
				// Error
				// Use Conn.f_GetLastError();
			}

			// Reading a message
			{
				NDBus::CMessageReader Reader(Reply);

				// Assuming we get back what we sent out.
				uint32 UInt32Var;
				CStr StringVar;
				bool bBoolVar;
				CByteVector lBytesVar;

				if (!Reader.f_PopArgs( UInt32Var, StringVar, bBoolVar, lBytesVar))
				{
					// Error
				}
			}
*/
#pragma once

#include <Mib/Core/Core>
#include <Mib/Core/DynamicLibrary>

extern "C"
{
	#include "dbus/dbus.h" // TODO: Hide completely?
}

#define DMibDBusError(_Msg) DMibImpError(CDBusException, _Msg);

namespace NMib::NDBus
{
	DMibImpErrorClassDefine(CDBusException, NException::CException);

	struct CDBusLibrary;

	enum EMessageType
	{
			EMessageType_Unknown
		,	EMessageType_Method
		,	EMessageType_MethodReturn
		,	EMessageType_Signal
		,	EMessageType_Error
	};

	class CMessageWriter;
	class CMessageReader;
	class CError;
	class CConnection;
	class CSystem;

	class CMessage
	{
	private:
		CDBusLibrary& mp_Lib;
		DBusMessage* mp_pMsg;

		friend CMessageReader;
		friend CMessageWriter;
		friend CConnection;

		CMessage(DBusMessage* _pMsg, CSystem& _System);
		CMessage(DBusMessage* _pMsg, CDBusLibrary& _Lib);

	public:
		// Only to be used for replies.
		CMessage(CSystem& _System);

		// TODO: Move these into static methods?

		// New method call message. _Type MUST == EMessageType_Method
		CMessage
			(
				EMessageType _Type
				, char const *_pService
				, char const *_pPath
				, char const *_pInterface
				, char const *_pMethod
				, CSystem &_System
			)
		;

		// New method return message. _Type MUST == EMessageType_MethodReturn
		CMessage
			(
				EMessageType _Type
				, CMessage &_InReplyTo
				, CSystem &_System
			)
		;

		// New signal message. _Type MUST == EMessageType_Signal
		CMessage
			(
				EMessageType _Type
				, char const *_pPath
				, char const *_pInterface
				, char const *_pName
				, CSystem &_System
			)
		;

		// New error message. _Type MUST == EMessageType_Error
		CMessage
			(
				EMessageType _Type
				, CMessage &_InReplyTo
				, char const *_pErrorName
				, char const *_pErrorMessage
				, CSystem &_System
			)
		;

		CMessage(CMessage const& _ToCopy);
		CMessage(CMessage&& _ToMove);
		~CMessage();

		CMessage& operator=(CMessage& _ToCopy);
		CMessage& operator=(CMessage&& _ToMove);

		EMessageType f_GetType() const;

		void f_SetSerial(uint32 _Serial); // Only used for testing, to pretend to have been sent.

	};

	class CMessageWriter
	{
	private:
		CDBusLibrary& mp_Lib;
		DBusMessageIter mp_Iter;

	public:
		CMessageWriter(CMessage& _Message);
		~CMessageWriter();

		template<typename t_CType>
		bool f_AppendArg(t_CType const& _Arg);

		inline bool f_AppendArgs();

		template<typename t_CFirst, typename... Args>
		inline bool f_AppendArgs(t_CFirst const& _First, Args const& ... _Args);

	};

	class CMessageReader
	{
	private:
		CDBusLibrary& mp_Lib;
		DBusMessageIter mp_Iter;

	public:
		CMessageReader(CMessage const& _Message);
		~CMessageReader();

		template<typename t_CType>
		bool f_PopArg(t_CType& _oArg);

		inline bool f_PopArgs();

		template<typename t_CFirst, typename... Args>
		inline bool f_PopArgs(t_CFirst& _First, Args&... _Args);

		bool f_ArgAvailable();
	};

	class CError
	{
	private:
		CDBusLibrary& mp_Lib;
		DBusError mp_Error;

		friend CConnection;

		CError(CDBusLibrary& _Lib);

	public:
		CError(CSystem& _Sys);
		CError(CError const& _ToCopy) = delete;
		CError(CError&& _ToMove);
		~CError();

		CError& operator=(CError const& _ToCopy) = delete;
		CError& operator=(CError&& _ToMove);

		bool f_IsSet() const;
		char const*f_GetName() const;
		char const*f_GetMessage() const;

		void f_Clear();

		void f_Take(DBusError& _FromHere);
	};

	static int const gc_DefaultTimeout = -1;

	enum EDBusBus
	{
		EDBusBus_Session	// User specific bus
		,EDBusBus_System	// Machine specific bus
	};

	class CConnection
	{
	private:
		enum EFlag
		{
			EFlag_None = 0
			, EFlag_Private = DMibBit(0)
		};

	private:
		CDBusLibrary& mp_Lib;
		DBusConnection* mp_pConnection;
		EFlag mp_Flags;
		CError mp_LastError;

		friend CSystem;

	public:

		CConnection(CSystem& _Sys);
		~CConnection();

		CError const& f_GetLastError() const;

		bool f_Open(char const* _pAddress, bool _bPrivate = false); // You will probably not use this, and almost never with _bPrivate == true.
		bool f_Open(EDBusBus _Bus);
		bool f_Close();

		bool f_BlockingSendWithReply(CMessage& _Message, CMessage& _oReply, int _TimeoutMillis = gc_DefaultTimeout);

	};

	class CSystem
	{
	private:
		NThread::CMutual mp_LibLock;
		NStorage::TCUniquePointer<CDBusLibrary> mp_pLib;

		friend CMessage;
		friend CError;
		friend CConnection;

	public:
		CSystem();
		~CSystem();

		bool f_ReadyForUse();	// f_IsOK will never return true until this has been called and returned true.

		bool f_IsOK();

	};

	//
	// CMessageWriter Implementation
	//

	template<typename t_CType>
	bool CMessageWriter::f_AppendArg(t_CType const& _Arg)
	{
		static_assert(NTraits::cIsSame<t_CType, void>, "This type is not supported");
		return false;
	}

	template<>
	bool CMessageWriter::f_AppendArg<uint8>(uint8 const& _Value);

	template<>
	bool CMessageWriter::f_AppendArg<int16>(int16 const& _Value);

	template<>
	bool CMessageWriter::f_AppendArg<uint16>(uint16 const& _Value);

	template<>
	bool CMessageWriter::f_AppendArg<int32>(int32 const& _Value);

	template<>
	bool CMessageWriter::f_AppendArg<uint32>(uint32 const& _Value);

	template<>
	bool CMessageWriter::f_AppendArg<int64>(int64 const& _Value);

	template<>
	bool CMessageWriter::f_AppendArg<uint64>(uint64 const& _Value);

	template<>
	bool CMessageWriter::f_AppendArg<bool>(bool const& _Value);

	template<>
	bool CMessageWriter::f_AppendArg<char const*>(char const* const& _Value);

	template<>
	bool CMessageWriter::f_AppendArg<NStr::CStr>(NStr::CStr const& _Value);

	template<>
	bool CMessageWriter::f_AppendArg<NStr::CStrSecure>(NStr::CStrSecure const& _Value);

	template<>
	bool CMessageWriter::f_AppendArg<NContainer::CByteVector>(NContainer::CByteVector const& _Value);

	template<>
	bool CMessageWriter::f_AppendArg<NContainer::TCVector<NStr::CStr>>(NContainer::TCVector<NStr::CStr> const& _Value);

	bool CMessageWriter::f_AppendArgs()
	{
		return true;
	}

	template<typename t_CFirst, typename... Args>
	bool CMessageWriter::f_AppendArgs(t_CFirst const& _First, Args const& ... _Args)
	{
		return f_AppendArg<t_CFirst>(_First) && f_AppendArgs(_Args...);
	}

	//
	// CMessageReader Implementation
	//

	template<typename t_CType>
	bool CMessageReader::f_PopArg(t_CType& _oArg)
	{
		static_assert(NTraits::cIsSame<t_CType, void>, "This type is not supported");
		return false;
	}

	template<>
	bool CMessageReader::f_PopArg<uint8>(uint8& _oValue);

	template<>
	bool CMessageReader::f_PopArg<int16>(int16& _oValue);

	template<>
	bool CMessageReader::f_PopArg<uint16>(uint16& _oValue);

	template<>
	bool CMessageReader::f_PopArg<int32>(int32& _oValue);

	template<>
	bool CMessageReader::f_PopArg<uint32>(uint32& _oValue);

	template<>
	bool CMessageReader::f_PopArg<int64>(int64& _oValue);

	template<>
	bool CMessageReader::f_PopArg<uint64>(uint64& _oValue);

	template<>
	bool CMessageReader::f_PopArg<NStr::CStr>(NStr::CStr& _oValue);

	template<>
	bool CMessageReader::f_PopArg<NStr::CStrSecure>(NStr::CStrSecure& _oValue);

	template<>
	bool CMessageReader::f_PopArg<bool>(bool& _oValue);

	template<>
	bool CMessageReader::f_PopArg<NContainer::CByteVector>(NContainer::CByteVector& _oValue);

	template<>
	bool CMessageReader::f_PopArg<NContainer::TCVector<NStr::CStr>>(NContainer::TCVector<NStr::CStr>& _oValue);

	bool CMessageReader::f_PopArgs()
	{
		return true;
	}

	template<typename t_CFirst, typename... Args>
	bool CMessageReader::f_PopArgs(t_CFirst& _oFirst, Args&... _oArgs)
	{
		return f_PopArg(_oFirst) && f_PopArgs(_oArgs...);
	}
}
