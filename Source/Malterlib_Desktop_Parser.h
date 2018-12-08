// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib::NDesktop
{
	class CDesktopFileParser
	{
	public:

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
		void f_SetCategories(NContainer::TCVector<NStr::CStr> const &_lCategories);
		void f_SetMimeTypes(NContainer::TCVector<NStr::CStr> const &_lMimeTypes);
		void f_SetActions(NContainer::TCVector<CDesktopAction> const &_lActions);
		void f_SetRecentItems(NContainer::TCVector<CDesktopAction> const &_lRecentItems);

		bool f_Parse(NContainer::TCVector<CDesktopGroup> &_Desktop);
		void f_Write();
		void f_Write(NContainer::TCVector<CDesktopGroup> const &_Desktop, bint _bMakeExecutable);

	protected:

		NContainer::CByteVector fp_ExportContents(NContainer::TCVector<CDesktopGroup> const &_Desktop);
		static NStr::CStr fsp_ConvertToDesktopFileEntry(NStr::CStr const &_Key, NStr::CStr const &_Value);
		static NStr::CStr fsp_MakeValidAction(NStr::CStr const &_Action);

		NStr::CStr mp_Identifier;
		NStr::CStr mp_Path;
		NStr::CStr mp_IconPath;

		NStr::CStr mp_Exec;
		NContainer::TCVector<NStr::CStr> mp_lCategories;
		NContainer::TCVector<NStr::CStr> mp_lMimeTypes;
		NContainer::TCVector<CDesktopAction> mp_lActions;
		NContainer::TCVector<CDesktopAction> mp_lRecentItems;
	};
}

#ifndef DMibPNoShortCuts
	using namespace NMib::NDesktop;
#endif
