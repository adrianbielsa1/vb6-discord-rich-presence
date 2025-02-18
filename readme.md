# vb6-discord-rich-presence

A small wrapper written in C++ to interact with Discord's Rich Presence functionality from an old language.

This DLL requires that end-users (and you) install the Visual C++ Redistributable x86 package (not the x64 one).
Most end users will have the redistributable already installed, but it's useful to prevent errors on fresh Windows installs.

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
cmake --build build --config Release
```

**NOTE:** It's important to use CMake's `-A Win32` flag because VB6 isn't able to use 64 bits DLLs.  \
I also suggest generating release builds (`--config Release`) since it lowers the number of dependencies the DLL
requires by not including debug DLLs.

### Testing

Move the .dll file generated after building (either at `build/Debug` or `build/Release`) to the `tests` folder.
Then, open the VB6 project, compile the executable, and click run.
If you wish to run it from the IDE you might need to move the .dll to `System32`.

### Credits

Thanks to [@Sarevokoveras](https://github.com/Sarevokoveras) for testing the library & providing insights on its dependencies in debug & release build configurations.
