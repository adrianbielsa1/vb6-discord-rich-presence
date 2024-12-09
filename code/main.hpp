#pragma once

#include "types.hpp"

extern "C" __declspec(dllexport) void __stdcall ab1_discord_initialize(ab1::VB6String clientID);
extern "C" __declspec(dllexport) void __stdcall ab1_discord_release();

extern "C" __declspec(dllexport) void __stdcall ab1_discord_presence_set(ab1::VB6String state, ab1::VB6String details);
extern "C" __declspec(dllexport) void __stdcall ab1_discord_presence_clear();
