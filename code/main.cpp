#include <discord_rpc.h>

#include "main.hpp"

extern "C" __declspec(dllexport) void __stdcall ab1_discord_initialize(ab1::VB6String clientID) {
    auto handlers = DiscordEventHandlers {};

    Discord_Initialize(clientID, &handlers, 1, nullptr);
}

extern "C" __declspec(dllexport) void __stdcall ab1_discord_release() {
    Discord_Shutdown();
}

extern "C" __declspec(dllexport) void __stdcall ab1_discord_presence_set(ab1::VB6String state, ab1::VB6String details) {
    auto presence = DiscordRichPresence {};

    presence.state = state;
    presence.details = details;

    Discord_UpdatePresence(&presence);
}

extern "C" __declspec(dllexport) void __stdcall ab1_discord_presence_clear() {
    Discord_ClearPresence();
}
