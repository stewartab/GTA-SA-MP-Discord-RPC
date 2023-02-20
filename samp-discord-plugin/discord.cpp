#include "discord.h"

namespace Discord
{
	static void ready(const DiscordUser* request) {}

	static void errored(int errorCode, const char* message) {}

	static void disconnected(int errorCode, const char* message) {}

	static void joinGame(const char* joinSecret) {}

	static void spectateGame(const char* spectateSecret) {}

	static void joinRequest(const DiscordUser* request) {}

	void initialize()
	{
		DiscordEventHandlers handlers = { 0 };
		handlers.ready = ready;
		handlers.errored = errored;
		handlers.disconnected = disconnected;
		handlers.joinGame = joinGame;
		handlers.spectateGame = spectateGame;
		handlers.joinRequest = joinRequest;
		//Discord_Initialize("925671356899672124", &handlers, 1, nullptr); // Everyone
		Discord_Initialize("1077112927481507850", &handlers, 1, nullptr); // My RPC Token
		/*Discord_Initialize("416719211960991756", &handlers, 1, nullptr);*/
		Discord_ClearPresence();
	}

	void update(const time_t time, const char* state, const char* details, const char* image, const char* imageDetails, const char* infoDetails)
	{
		DiscordRichPresence discordPresence = { 0 };
		discordPresence.state = state;
		discordPresence.details = details;
		discordPresence.startTimestamp = time;
		discordPresence.largeImageKey = "canary-large";
		discordPresence.largeImageText = imageDetails;
		discordPresence.smallImageKey = "ptb-small";
		discordPresence.smallImageText = "samp";
		Discord_UpdatePresence(&discordPresence);
	}
}
