// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Malterlib_Desktop_Parser.h"

namespace NMib::NDesktop
{
	CDesktopFileParser::CDesktopFileParser(NStr::CStr const &_Identifier, NStr::CStr const &_Path)
		: mp_Identifier(_Identifier)
		, mp_Path(_Path)
	{

	}

	CDesktopFileParser::~CDesktopFileParser()
	{

	}

	void CDesktopFileParser::f_SetIconPath(NStr::CStr const &_IconPath)
	{
		mp_IconPath = _IconPath;
	}

	void CDesktopFileParser::f_SetExec(NStr::CStr const &_Exec)
	{
		mp_Exec = _Exec;
	}

	void CDesktopFileParser::f_SetCategories(NContainer::TCVector<NStr::CStr> const &_lCategories)
	{
		mp_lCategories = _lCategories;
	}

	void CDesktopFileParser::f_SetMimeTypes(NContainer::TCVector<NStr::CStr> const &_lMimeTypes)
	{
		mp_lMimeTypes = _lMimeTypes;
	}

	void CDesktopFileParser::f_SetActions(NContainer::TCVector<CDesktopAction> const &_lActions)
	{
		mp_lActions = _lActions;
	}

	void CDesktopFileParser::f_SetRecentItems(NContainer::TCVector<CDesktopAction> const &_lRecentItems)
	{
		mp_lRecentItems = _lRecentItems;
	}

	bool CDesktopFileParser::f_Parse(NContainer::TCVector<CDesktopGroup> &_Desktop)
	{
		if (!NFile::CFile::fs_FileExists(mp_Path))
			return false;

		NStr::CStr Contents;
		try
		{
			Contents = NFile::CFile::fs_ReadStringFromFile(NStr::CStr(mp_Path), true);
		}
		catch (NFile::CExceptionFile const&)
		{
			return false;
		}

		CDesktopGroup *pDesktopGroup = nullptr;
		while(!Contents.f_IsEmpty())
		{
			aint NewLinePos = Contents.f_Find("\n");
			if (NewLinePos == -1)
				break;

			NStr::CStr Line = Contents.f_Left(NewLinePos);
			Contents = Contents.f_Delete(0, NewLinePos+1);

			NStr::CStr Key;
			NStr::CStr Value;
			aint nParsed;

			(NStr::CStr::CParse("[{}]") >> Key).f_Parse(Line, nParsed);
			if (nParsed == 1)
			{
				_Desktop.f_Insert(CDesktopGroup());
				pDesktopGroup = &_Desktop.f_GetLast();
				pDesktopGroup->f_SetName(Key);
				continue;
			}

			(NStr::CStr::CParse("{}={}") >> Key >> Value).f_Parse(Line, nParsed);
			if (nParsed == 2 && pDesktopGroup)
				pDesktopGroup->f_SetValue(Key, Value);
		}

		return true;
	}

	void CDesktopFileParser::f_Write()
	{
		NContainer::TCVector<CDesktopGroup> lDesktopContents;

		// Desktop Entry
		{
			CDesktopGroup DesktopEntry;
			DesktopEntry.f_SetName("Desktop Entry");
			DesktopEntry.f_SetValue("Version", "1.0");
			DesktopEntry.f_SetValue("Type", "Application");
			DesktopEntry.f_SetValue("Terminal", "false");

			if (!mp_lMimeTypes.f_IsEmpty())
				DesktopEntry.f_SetValue("MimeType", mp_lMimeTypes);

			if (!mp_lCategories.f_IsEmpty())
				DesktopEntry.f_SetValue("Categories", mp_lCategories);

			NStr::CStr ProgramName = NMib::fg_GetSys()->f_GetProgramName();
			if (ProgramName.f_IsEmpty())
				ProgramName = NFile::CFile::fs_GetFile(NFile::CFile::fs_GetProgramPath());

			DesktopEntry.f_SetValue("Name", ProgramName);

			if (!mp_Exec.f_IsEmpty())
				DesktopEntry.f_SetValue("Exec", mp_Exec);
			else
				DesktopEntry.f_SetValue("Exec", NFile::CFile::fs_GetProgramPath());

			if (!mp_IconPath.f_IsEmpty())
				DesktopEntry.f_SetValue("Icon", mp_IconPath);

			{
				NContainer::TCVector<NStr::CStr> ConvertedActions;
				for(CDesktopAction const &TaskItem : mp_lActions)
					ConvertedActions.f_InsertLast(fsp_MakeValidAction(TaskItem.m_Description));
				for(CDesktopAction const &RecentItem : mp_lRecentItems)
					ConvertedActions.f_InsertLast(fsp_MakeValidAction(RecentItem.m_Description));
				if (!ConvertedActions.f_IsEmpty())
					DesktopEntry.f_SetValue("Actions", ConvertedActions);
			}

			lDesktopContents.f_InsertLast(DesktopEntry);
		}

		// Tasks
		for(CDesktopAction const &TaskItem : mp_lActions)
		{
			CDesktopGroup ItemEntry;
			ItemEntry.f_SetName(NStr::CStr::CFormat("Desktop Action {}") << fsp_MakeValidAction(TaskItem.m_Description));
			ItemEntry.f_SetValue("Name", TaskItem.m_Description);
			ItemEntry.f_SetValue("Exec", TaskItem.m_Exec);
			if (!TaskItem.m_ActionDescription.f_IsEmpty())
				ItemEntry.f_SetValue("X-Hansoft-ActionDescription", TaskItem.m_ActionDescription);
			ItemEntry.f_SetValue("X-Hansoft-TaskType", TaskItem.m_Type);
			lDesktopContents.f_InsertLast(ItemEntry);
		}

		// Recent items
		for(CDesktopAction const &RecentItem : mp_lRecentItems)
		{
			CDesktopGroup ItemEntry;
			ItemEntry.f_SetName(NStr::CStr::CFormat("Desktop Action {}") << fsp_MakeValidAction(RecentItem.m_Description));
			ItemEntry.f_SetValue("Name", RecentItem.m_Description);
			ItemEntry.f_SetValue("Exec", RecentItem.m_Exec);
			if (!RecentItem.m_ActionDescription.f_IsEmpty())
				ItemEntry.f_SetValue("X-Hansoft-ActionDescription", RecentItem.m_ActionDescription);
			ItemEntry.f_SetValue("X-Hansoft-RecentType", RecentItem.m_Type);
			lDesktopContents.f_InsertLast(ItemEntry);
		}

		NContainer::CByteVector Contents = fp_ExportContents(lDesktopContents);

		if (NFile::CFile::fs_FileExists(mp_Path) && NFile::CFile::fs_FileIsSame(Contents, mp_Path))
			return;

		try
		{
			NFile::CFile::fs_CreateDirectory(NFile::CFile::fs_GetPath(mp_Path));
			NFile::CFile::fs_WriteFile(Contents, mp_Path);

			NFile::EFileAttrib Attribs = NFile::CFile::fs_GetAttributes(mp_Path);
			Attribs |= NFile::EFileAttrib_Executable;
			NFile::CFile::fs_SetAttributes(mp_Path, Attribs);
		}
		catch (NFile::CExceptionFile const &Exception)
		{
			(void)Exception;
			DMibLog(Debug, "Unable to create desktop file: {}", Exception.f_GetErrorStr());
		}
	}

	void CDesktopFileParser::f_Write(NContainer::TCVector<CDesktopGroup> const &_Desktop, bool _bMakeExecutable)
	{
		NContainer::CByteVector Contents = fp_ExportContents(_Desktop);

		if (NFile::CFile::fs_FileExists(mp_Path) && NFile::CFile::fs_FileIsSame(Contents, mp_Path))
			return;

		try
		{
			NFile::CFile::fs_CreateDirectory(NFile::CFile::fs_GetPath(mp_Path));
			NFile::CFile::fs_WriteFile(Contents, mp_Path);

			if (_bMakeExecutable)
			{
				NFile::EFileAttrib Attribs = NFile::CFile::fs_GetAttributes(mp_Path);
				Attribs |= NFile::EFileAttrib_Executable;
				NFile::CFile::fs_SetAttributes(mp_Path, Attribs);
			}
		}
		catch (NFile::CExceptionFile const &Exception)
		{
			(void)Exception;
			DMibLog(Debug, "Unable to create desktop file: {}", Exception.f_GetErrorStr());
		}

	}

	NContainer::CByteVector CDesktopFileParser::fp_ExportContents(NContainer::TCVector<CDesktopGroup> const &_Desktop)
	{
		NContainer::CByteVector Contents;

		for(CDesktopGroup const &DesktopGroup : _Desktop)
		{
			NStr::CStr Entry = NStr::CStr::CFormat("[{}]\n") << DesktopGroup.m_Name;
			Contents.f_Insert((uint8*)Entry.f_GetStr(), Entry.f_GetLen());

			NContainer::TCMap<NStr::CStr, NStr::CStr>::CIteratorConst KeyValueIter = DesktopGroup.m_KeyValueMap.f_GetIterator();
			while (KeyValueIter)
			{
				NStr::CStr KeyValuePair = fsp_ConvertToDesktopFileEntry(KeyValueIter.f_GetKey(), *KeyValueIter);
				if (!KeyValuePair.f_IsEmpty())
					Contents.f_Insert((uint8*)KeyValuePair.f_GetStr(), KeyValuePair.f_GetLen());
				++KeyValueIter;
			}
			Contents.f_Insert('\n');
		}

		return Contents;
	}

	NStr::CStr CDesktopFileParser::fsp_ConvertToDesktopFileEntry(NStr::CStr const &_Key, NStr::CStr const &_Value)
	{
		if (_Key.f_IsEmpty() || _Value.f_IsEmpty())
		{
			DMibLog(Debug, "Key and Value cannot be empty! Key={}, Value={}", _Key, _Value);
			return "";
		}

		return NStr::CStr::CFormat("{}={}\n") << _Key << _Value;
	}

	NStr::CStr CDesktopFileParser::fsp_MakeValidAction(NStr::CStr const &_Action)
	{
		NStr::CStr Result;

		ch8 const *pChar = _Action.f_GetStr();
		while (*pChar)
		{
			if ((*pChar >= 'a' && *pChar <= 'z')
				|| (*pChar >= 'A' && *pChar <= 'Z')
				|| (*pChar >= '0' && *pChar <= '9')
				|| *pChar == '-')
					Result.f_AddChar(*pChar);
			++pChar;
		}

		return Result;
	}

	void CDesktopFileParser::CDesktopGroup::f_SetName(NStr::CStr const &_Name)
	{
		m_Name = _Name;
	}

	void CDesktopFileParser::CDesktopGroup::f_SetValue(NStr::CStr const &_Key, NStr::CStr const &_Value)
	{
		m_KeyValueMap[_Key] = _Value;		// Single values does not escape semicolon
	}

	void CDesktopFileParser::CDesktopGroup::f_SetValue(NStr::CStr const &_Key, NContainer::TCVector<NStr::CStr> const &_Values)
	{
		NStr::CStr Array;
		for (NStr::CStr const &Item : _Values)
			Array += Item.f_Replace(";", "\\;") + ";";

		m_KeyValueMap[_Key] = Array;
	}
}
