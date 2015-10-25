#pragma once

#include <iostream>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Security::Cryptography;
using namespace System::IO;
using namespace System::Diagnostics;


namespace oPenTest {

	public ref class autoBase :  public System::ComponentModel::Component
	{
	public:
		autoBase(void)
		{
		}

		autoBase(System::ComponentModel::IContainer ^container)
		{
		}

		int scanDir(String ^path, int hashear, String ^ext);
		void toHexa( array<Byte>^array, String ^ path);



	protected:
		~autoBase()
		{
		}
	};
}
