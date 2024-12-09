# vb6-discord-rich-presence

A small wrapper written in C++ to interact with Discord's Rich Presence functionality from old languages.

### Building

First, generate the required Makefiles:
```
mkdir build
cd build
cmake -A Win32 ..
cd ..
```
Then compile the library:
```
cmake --build build
```

**NOTE:** It's important to use CMake's `-A Win32` flag because VB6 isn't able to use 64 bits DLLs.

### Testing

Move the .dll file generated after building (either at `build/Debug` or `build/Release`) to the `tests` folder.
Then, open the VB6 project, compile the executable, and click run.
If you wish to run it from the IDE you might need to move the .dll to `System32`.
