// Loader.cpp: Definiert die exportierten Funktionen für die DLL-Anwendung.
//

#include "stdafx.h"
#include <PlutoBridge.h>

namespace Loader
{
	void Startup()
	{
		PlutoBridge::Startup();
	}
}