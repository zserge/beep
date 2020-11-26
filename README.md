# beep

Beep is a minimal cross-platform sound playback library. All it does is beeping at the given frequency for the given duration of time.

* Good old C89 code with globals.
* Very small, ~100 lines of code for all platforms.
* Easy to use, API is a single blocking function.
* Uses ALSA on Linux, CoreAudio on macOS and Beep() WINAPI function on Windows.

The API is the following:

```c
int beep(int frequency, int duration);
```

Frequency is in Hz, duration is in milliseconds. To convert note index into a frequency use the following formula: `440 * pow(2, ((note - 49) / 12))`.

There is a also a `beep` utility which shows how the API can be used.

If you found an issue or would like to propose a feature - PRs are welcome as long as they are small and simple!

Code is distributed under MIT license, feel free to use in commercial projects.
