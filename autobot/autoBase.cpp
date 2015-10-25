#include "StdAfx.h"
#include "autoBase.h"

using namespace autobot;

/**
******************************************************
* @file autoBase.cpp
* @brief Clase base para el proyecto
* @author oPen syLar - opensylar@develsecurity.com.ve
* @version 0.1
* @date Octubre de 2015
*
*
*******************************************************/

void autoBase::toHexa( array<Byte>^array, String ^ path)
{

   int register i;

   for ( i = 0; i < array->Length; i++ )
   {
	   Console::Write( String::Format( "{0:X2}", array[i]));
   }

   Console::WriteLine(" " + path);
}

int autoBase::scanDir(String ^path, int hashear, String ^ext)
{

	System::Diagnostics pilla;

	try
	{
		array<System::String ^> ^ret = Directory::GetDirectories(path);	
		array<System::String ^> ^retFiles;
		int register i, a;
		SHA256 ^ mySHA256 = SHA256Managed::Create();
		array<Byte>^ hash;

		for(i=0; i<ret->Length; i++)
		{
			retFiles = Directory::GetFiles(ret->GetValue(i)->ToString());

			for(a=0;a<retFiles->Length; a++)
			{
				if(hashear==1)
				{
					FileStream ^ fStream = File::OpenRead(retFiles->GetValue(a)->ToString());
					hash = mySHA256->ComputeHash(fStream);
					toHexa(hash, retFiles->GetValue(a)->ToString());
					fStream->Close();
				}
			}
			scanDir(ret->GetValue(i)->ToString(), hashear, ext);

		}
	}

	catch(System::Exception ^e)
	{
		Console::WriteLine("[+] ERROR [scanDir] :: " + e->Message);
		Console::ReadLine();
	}

	return 0;
}