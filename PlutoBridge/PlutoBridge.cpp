// PlutoBridge.cpp: Definiert die exportierten Funktionen für die DLL-Anwendung.
//

#include "stdafx.h"
#include <sio_client.h>
void OnSay(Entity* Entity, Team* team, char* message)
{
	if(!Network::Client.opened())
		return;

	sio::message::list args;

	args.push("Key");
	args.push("Servername");

	char buffer[128];
	sprintf_s(buffer, "%s::%s", Entity->Shared.Client->Session.Clientstate.Name, message);
	args.push(buffer);

	Network::Client.socket()->emit("chat_message", args);
}

namespace PlutoBridge
{
	void Startup()
	{
		Network::Client.connect("http://127.0.0.1:3000");
		
		HookManager::InstallOnSay(OnSay);
	}
}
