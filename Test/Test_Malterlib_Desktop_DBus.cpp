// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include <Mib/Core/Core>

#include <Mib/Desktop/DBus>

using namespace NMib;

namespace
{

	class CDBus_Tests : public NMib::NTest::CTest
	{
	public:

		void f_DoTests()
		{
			NDBus::CSystem DBus;
			DBus.f_ReadyForUse();
			
			if (!DBus.f_IsOK())
				return; // Not supported on this system

			DMibTestSuite("System")
			{
				DMibTest(DMibExpr(DBus.f_IsOK()) == DMibExpr(true))(ETest_FailAndStop);
			};

			DMibTestSuite("Message_Method")
			{
				NDBus::CMessage Msg(NDBus::EMessageType_Method, "com.malterlib.service", "/modules/test", "com.malterlib.test", "testMethod", DBus);
			};

			DMibTestSuite("Message_MethodReturn")
			{
				NDBus::CMessage Msg1(NDBus::EMessageType_Method, "com.malterlib.service", "/modules/test", "com.malterlib.test", "testMethod", DBus);
				Msg1.f_SetSerial(100);
				NDBus::CMessage Msg2(NDBus::EMessageType_MethodReturn, Msg1, DBus);
			};

			DMibTestSuite("Message_Signal")
			{
				NDBus::CMessage Msg(NDBus::EMessageType_Signal, "/modules/test", "com.malterlib.test", "testSignal", DBus);
			};

			DMibTestSuite("Message_Error")
			{
				NDBus::CMessage Msg1(NDBus::EMessageType_Method, "com.malterlib.service", "/modules/test", "com.malterlib.test", "testMethod", DBus);
				Msg1.f_SetSerial(100);
				NDBus::CMessage Msg2(NDBus::EMessageType_Error, Msg1, "com.malterlib.error", "TestErrorMessage", DBus);
			};

			DMibTestSuite("MessageWriter_AppendArg")
			{
				NDBus::CMessage Msg(NDBus::EMessageType_Method, "com.malterlib.service", "/modules/test", "com.malterlib.test", "testMethod", DBus);

				NDBus::CMessageWriter Writer(Msg);

				NContainer::CByteVector lBytes;
				lBytes.f_SetLen(32);
				NMemory::fg_MemClear(lBytes.f_GetArray(), 32);

				NContainer::TCVector<NStr::CStr> lStrings;
				lStrings.f_Insert("One");
				lStrings.f_Insert("Two");

				NStr::CStr StringVar("X");

				DMibTest(DMibExpr(Writer.f_AppendArg((uint8)0)) == DMibExpr(true))(ETest_FailAndStop);				
				DMibTest(DMibExpr(Writer.f_AppendArg((int16)1)) == DMibExpr(true))(ETest_FailAndStop);				
				DMibTest(DMibExpr(Writer.f_AppendArg((uint16)2)) == DMibExpr(true))(ETest_FailAndStop);				
				DMibTest(DMibExpr(Writer.f_AppendArg((int32)3)) == DMibExpr(true))(ETest_FailAndStop);				
				DMibTest(DMibExpr(Writer.f_AppendArg((uint32)4)) == DMibExpr(true))(ETest_FailAndStop);				
				DMibTest(DMibExpr(Writer.f_AppendArg((int64)5)) == DMibExpr(true))(ETest_FailAndStop);				
				DMibTest(DMibExpr(Writer.f_AppendArg((uint64)6)) == DMibExpr(true))(ETest_FailAndStop);				
				DMibTest(DMibExpr(Writer.f_AppendArg(StringVar)) == DMibExpr(true))(ETest_FailAndStop);				
				DMibTest(DMibExpr(Writer.f_AppendArg(false)) == DMibExpr(true))(ETest_FailAndStop);				
				DMibTest(DMibExpr(Writer.f_AppendArg(lBytes)) == DMibExpr(true))(ETest_FailAndStop);
				DMibTest(DMibExpr(Writer.f_AppendArg(lStrings)) == DMibExpr(true))(ETest_FailAndStop);
			};

			DMibTestSuite("MessageWriter_AppendArgs")
			{
				NDBus::CMessage Msg(NDBus::EMessageType_Method, "com.malterlib.service", "/modules/test", "com.malterlib.test", "testMethod", DBus);

				NDBus::CMessageWriter Writer(Msg);

				NContainer::CByteVector lBytes;
				lBytes.f_SetLen(32);
				NMemory::fg_MemClear(lBytes.f_GetArray(), 32);

				NContainer::TCVector<NStr::CStr> lStrings;
				lStrings.f_Insert("One");
				lStrings.f_Insert("Two");

				bool bRet = Writer.f_AppendArgs(
										(uint8)0
									,	(int16)1
									,	(uint16)2
									, 	(int32)3
									,	(uint32)4
									,	(int64)5
									,	(uint64)6
									,	NStr::CStr("X")
									,	false
									, 	lBytes
									,	lStrings);

				DMibTest(DMibExpr(bRet) == DMibExpr(true));
			};

			DMibTestSuite("MessageReader_PopArg")
			{
				NDBus::CMessage Msg(NDBus::EMessageType_Method, "com.malterlib.service", "/modules/test", "com.malterlib.test", "testMethod", DBus);

				{
					NDBus::CMessageWriter Writer(Msg);

					NContainer::CByteVector lBytes;
					lBytes.f_SetLen(32);
					NMemory::fg_MemClear(lBytes.f_GetArray(), 32);

					NContainer::TCVector<NStr::CStr> lStrings;
					lStrings.f_Insert("One");
					lStrings.f_Insert("Two");

					bool bRet = Writer.f_AppendArgs(
											(uint8)0
										,	(int16)1
										,	(uint16)2
										, 	(int32)3
										,	(uint32)4
										,	(int64)5
										,	(uint64)6
										,	NStr::CStr("X")
										,	false
										, 	lBytes
										,	lStrings);

					DMibTest(DMibExpr(bRet) == DMibExpr(true));
				}

				{
					NDBus::CMessageReader Reader(Msg);

					DMibTest(DMibExpr(Reader.f_ArgAvailable()) == DMibExpr(true));

					uint8 UInt8Var = 100;
					int16 Int16Var = 100;
					uint16 UInt16Var = 100;
					int32 Int32Var = 100;
					uint32 UInt32Var = 100;
					int64 Int64Var = 100;
					uint64 UInt64Var = 100;
					NStr::CStr StringVar = "Y";
					bool bBoolVar = true;
					NContainer::CByteVector lBytesVar;
					NContainer::TCVector<NStr::CStr> lStringsVar;

					DMibTest(DMibExpr(Reader.f_PopArg(UInt8Var)) == DMibExpr(true))(ETest_FailAndStop);				
					DMibTest(DMibExpr(Reader.f_PopArg(Int16Var)) == DMibExpr(true))(ETest_FailAndStop);				
					DMibTest(DMibExpr(Reader.f_PopArg(UInt16Var)) == DMibExpr(true))(ETest_FailAndStop);				
					DMibTest(DMibExpr(Reader.f_PopArg(Int32Var)) == DMibExpr(true))(ETest_FailAndStop);				
					DMibTest(DMibExpr(Reader.f_PopArg(UInt32Var)) == DMibExpr(true))(ETest_FailAndStop);				
					DMibTest(DMibExpr(Reader.f_PopArg(Int64Var)) == DMibExpr(true))(ETest_FailAndStop);				
					DMibTest(DMibExpr(Reader.f_PopArg(UInt64Var)) == DMibExpr(true))(ETest_FailAndStop);				
					DMibTest(DMibExpr(Reader.f_PopArg(StringVar)) == DMibExpr(true))(ETest_FailAndStop);				
					DMibTest(DMibExpr(Reader.f_PopArg(bBoolVar)) == DMibExpr(true))(ETest_FailAndStop);				
					DMibTest(DMibExpr(Reader.f_PopArg(lBytesVar)) == DMibExpr(true))(ETest_FailAndStop);
					DMibTest(DMibExpr(Reader.f_PopArg(lStringsVar)) == DMibExpr(true))(ETest_FailAndStop);

					DMibTest(DMibExpr(UInt8Var) == DMibExpr(0));
					DMibTest(DMibExpr(Int16Var) == DMibExpr(1));
					DMibTest(DMibExpr(UInt16Var) == DMibExpr(2));
					DMibTest(DMibExpr(Int32Var) == DMibExpr(3));
					DMibTest(DMibExpr(UInt32Var) == DMibExpr(4));
					DMibTest(DMibExpr(Int64Var) == DMibExpr(5));
					DMibTest(DMibExpr(UInt64Var) == DMibExpr(6));
					DMibTest(DMibExpr(StringVar) == DMibExpr(NStr::CStr("X")));
					DMibTest(DMibExpr(bBoolVar) == DMibExpr(false));
					{
						NContainer::CByteVector lExpectedBytes;
						lExpectedBytes.f_SetLen(32);
						NMemory::fg_MemClear(lExpectedBytes.f_GetArray(), 32);
						DMibTest(DMibExpr(lBytesVar) == DMibExpr(lExpectedBytes));
					}
					{
						NContainer::TCVector<NStr::CStr> lExpectedStrings;
						lExpectedStrings.f_Insert("One");
						lExpectedStrings.f_Insert("Two");						
						DMibTest(DMibExpr(lStringsVar) == DMibExpr(lExpectedStrings));
					}
					
					DMibTest(DMibExpr(Reader.f_ArgAvailable()) == DMibExpr(false));

					bool bRet3 = Reader.f_PopArgs( UInt32Var );

					DMibTest(DMibExpr(bRet3) == DMibExpr(false));
				}
			};

			DMibTestSuite("MessageReader_PopArgs")
			{
				NDBus::CMessage Msg(NDBus::EMessageType_Method, "com.malterlib.service", "/modules/test", "com.malterlib.test", "testMethod", DBus);

				{
					NDBus::CMessageWriter Writer(Msg);

					NContainer::CByteVector lBytes;
					lBytes.f_SetLen(32);
					NMemory::fg_MemClear(lBytes.f_GetArray(), 32);

					NContainer::TCVector<NStr::CStr> lStrings;
					lStrings.f_Insert("One");
					lStrings.f_Insert("Two");

					bool bRet = Writer.f_AppendArgs(
											(uint8)0
										,	(int16)1
										,	(uint16)2
										, 	(int32)3
										,	(uint32)4
										,	(int64)5
										,	(uint64)6
										,	NStr::CStr("X")
										,	false
										, 	lBytes
										,	lStrings);

					DMibTest(DMibExpr(bRet) == DMibExpr(true));
				}

				{
					NDBus::CMessageReader Reader(Msg);

					DMibTest(DMibExpr(Reader.f_ArgAvailable()) == DMibExpr(true));

					uint8 UInt8Var = 100;
					int16 Int16Var = 100;
					uint16 UInt16Var = 100;
					int32 Int32Var = 100;
					uint32 UInt32Var = 100;
					int64 Int64Var = 100;
					uint64 UInt64Var = 100;
					NStr::CStr StringVar = "Y";
					bool bBoolVar = true;
					NContainer::CByteVector lBytesVar;
					NContainer::TCVector<NStr::CStr> lStringsVar;

					bool bRet2 = Reader.f_PopArgs(
												UInt8Var
											,	Int16Var
											,	UInt16Var
											,	Int32Var
											,	UInt32Var
											,	Int64Var
											,	UInt64Var
											,	StringVar
											,	bBoolVar
											,	lBytesVar
											,	lStringsVar );

					DMibTest(DMibExpr(bRet2) == DMibExpr(true)) (ETest_FailAndStop);
					DMibTest(DMibExpr(UInt8Var) == DMibExpr(0));
					DMibTest(DMibExpr(Int16Var) == DMibExpr(1));
					DMibTest(DMibExpr(UInt16Var) == DMibExpr(2));
					DMibTest(DMibExpr(Int32Var) == DMibExpr(3));
					DMibTest(DMibExpr(UInt32Var) == DMibExpr(4));
					DMibTest(DMibExpr(Int64Var) == DMibExpr(5));
					DMibTest(DMibExpr(UInt64Var) == DMibExpr(6));
					DMibTest(DMibExpr(StringVar) == DMibExpr(NStr::CStr("X")));
					DMibTest(DMibExpr(bBoolVar) == DMibExpr(false));
					{
						NContainer::CByteVector lExpectedBytes;
						lExpectedBytes.f_SetLen(32);
						NMemory::fg_MemClear(lExpectedBytes.f_GetArray(), 32);
						DMibTest(DMibExpr(lBytesVar) == DMibExpr(lExpectedBytes));
					}

					{
						NContainer::TCVector<NStr::CStr> lExpectedStrings;
						lExpectedStrings.f_Insert("One");
						lExpectedStrings.f_Insert("Two");						
						DMibTest(DMibExpr(lStringsVar) == DMibExpr(lExpectedStrings));
					}

					DMibTest(DMibExpr(Reader.f_ArgAvailable()) == DMibExpr(false));

					bool bRet3 = Reader.f_PopArgs( UInt32Var );

					DMibTest(DMibExpr(bRet3) == DMibExpr(false));
				}
			};

			DMibTestSuite("Connection")
			{
				NDBus::CMessage Msg(	NDBus::EMessageType_Method
									,	"org.freedesktop.DBus"
									,	"/"
									,	"org.freedesktop.DBus"
									, 	"GetId"
									,	DBus);

				NDBus::CConnection Connection(DBus);

				bool bOpened = Connection.f_Open(NDBus::EDBusBus_Session);

				DMibTest(DMibExpr(bOpened) == DMibExpr(true)) (ETest_FailAndStop);

				NDBus::CMessage Reply(DBus);

				bool bSentAndReceived = Connection.f_BlockingSendWithReply(Msg, Reply);
				
				DMibTest(DMibExpr(bSentAndReceived) == DMibExpr(true)) (ETest_FailAndStop);

				
				{
					NDBus::CMessageReader Reader(Reply);

					DMibTest(DMibExpr(Reader.f_ArgAvailable()) == DMibExpr(true));

					NStr::CStr IDString;

					Reader.f_PopArgs(IDString);

					DMibTest(DMibExpr(IDString.f_IsEmpty()) == DMibExpr(false));
				}

				bool bClosed = Connection.f_Close();
				
				DMibTest(DMibExpr(bClosed) == DMibExpr(true));

			};

		}
			
	};

	DMibTestRegister(CDBus_Tests, Malterlib::Desktop);
}
