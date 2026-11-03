// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NDesktop
{
	struct CDesktopFileParser
	{
		CDesktopFileParser(NStr::CStr const &_Identifier, NStr::CStr const &_Path);
		~CDesktopFileParser();

		struct CDesktopAction
		{
			NStr::CStr m_Description;
			NStr::CStr m_ActionDescription;
			NStr::CStr m_Exec;
			NStr::CStr m_Type;
		};

		struct CDesktopGroup
		{
			NStr::CStr m_Name;
			NContainer::TCMap<NStr::CStr, NStr::CStr> m_KeyValueMap;

			void f_SetName(NStr::CStr const &_Name);
			void f_SetValue(NStr::CStr const &_Key, NStr::CStr const &_Value);
			void f_SetValue(NStr::CStr const &_Key, NContainer::TCVector<NStr::CStr> const &_Values);
		};

		void f_SetIconPath(NStr::CStr const &_IconPath);
		void f_SetExec(NStr::CStr const &_Exec);
		void f_SetCategories(NContainer::TCVector<NStr::CStr> const &_Categories);
		void f_SetMimeTypes(NContainer::TCVector<NStr::CStr> const &_MimeTypes);
		void f_SetActions(NContainer::TCVector<CDesktopAction> const &_Actions);
		void f_SetRecentItems(NContainer::TCVector<CDesktopAction> const &_RecentItems);

		bool f_Parse(NContainer::TCVector<CDesktopGroup> &_Desktop);
		void f_Write();
		void f_Write(NContainer::TCVector<CDesktopGroup> const &_Desktop, bool _bMakeExecutable);

	protected:
		NContainer::CByteVector fp_ExportContents(NContainer::TCVector<CDesktopGroup> const &_Desktop);
		static NStr::CStr fsp_ConvertToDesktopFileEntry(NStr::CStr const &_Key, NStr::CStr const &_Value);
		static NStr::CStr fsp_MakeValidAction(NStr::CStr const &_Action);

		NStr::CStr mp_Identifier;
		NStr::CStr mp_Path;
		NStr::CStr mp_IconPath;

		NStr::CStr mp_Exec;
		NContainer::TCVector<NStr::CStr> mp_Categories;
		NContainer::TCVector<NStr::CStr> mp_MimeTypes;
		NContainer::TCVector<CDesktopAction> mp_Actions;
		NContainer::TCVector<CDesktopAction> mp_RecentItems;
	};
}

#ifndef DMibPNoShortCuts
using namespace NMib::NDesktop;
#endif
