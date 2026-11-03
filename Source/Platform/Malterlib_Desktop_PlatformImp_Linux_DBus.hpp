// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NDBus
{
	//
	// CMessageWriter Implementation
	//

	template <typename tf_CType>
	bool CMessageWriter::f_AppendArg(tf_CType const &_Arg)
	{
		static_assert(NTraits::cIsSame<tf_CType, void>, "This type is not supported");
		return false;
	}

	template <typename tf_CFirst, typename ...tfp_CArgs>
	bool CMessageWriter::f_AppendArgs(tf_CFirst const &_First, tfp_CArgs const & ...p_Args)
	{
		return f_AppendArg<tf_CFirst>(_First) && f_AppendArgs(p_Args...);
	}

	//
	// CMessageReader Implementation
	//

	template <typename tf_CType>
	bool CMessageReader::f_PopArg(tf_CType &o_Arg)
	{
		static_assert(NTraits::cIsSame<tf_CType, void>, "This type is not supported");
		return false;
	}

	template <typename tf_CFirst, typename ...tfp_CArgs>
	bool CMessageReader::f_PopArgs(tf_CFirst &o_First, tfp_CArgs & ...po_Args)
	{
		return f_PopArg(o_First) && f_PopArgs(po_Args...);
	}
}
