# Chocolate Doom: Wii

A port of [Chocolate Doom](https://github.com/chocolate-doom/chocolate-doom) to the Wii. This is forked off of the 2.2.1 release.

**This is still in the early stages. It compiles, but a number of things (controls, WAD selection, configuration, etc) are not ready yet.**

**Doom is being worked on first, Hexen, Heretic and Strife will follow next.**

### TODO

* Controls. Nothing has been ported yet (code still assumes PC controls at the moment).
* Config/setup.
* WAD selection. Currently auto-scans for available IWADs.
* Save game selection tweaks for console-friendlyness.
* Hexen/Heretic/Strife

### Why

There are a couple other ports of Doom to the Wii, but they either include a number of mods / "enhancements", don't support the controller I want to use (GameCube controller), don't run at the TV resolution (240p) I want, or they blur the video buffer unnecessarily with some filter (either intentionally or not), or .... well, I could go on.

Basically, I wanted a port that:

* Is a _vanilla_ port of Doom. I want to play the same game I played in the 90's with all the same bugs and quirks intact. None of this bullshit with random arbitrary bugfixes, mods, "enhancements" or whatever else.
* Works with a GameCube controller. I don't want to have to plug in a USB keyboard or need to use batteries with a Wiimote + Classic Controller. Ugh.
* Can be played using a 240p resolution because I play all my retro games on a CRT TV. This probably goes against my "vanilla" requirement above as none of us played Doom this way in the 90's, but after seeing it recently for myself I instantly feel in love with the look and wanted to do it for myself. However, this should be optional and 2x scaled to 480p should also work for play on modern HDTVs.


### Building

You'll need [devkitPro](http://devkitpro.org/) of course. Make sure devkitPPC, libogc, and all of the [portlibs](http://devkitpro.org/wiki/portlibs) are installed (can be downloaded from [here](https://sourceforge.net/projects/devkitpro/files/portlibs/ppc/)).

Lastly you'll need my fork of [SDL-Wii](https://github.com/gered/sdl-wii) which for right now you will need to compile and install manually (`make && make install`).

Now a `chocolate-doom-wii.dol` can be built via `make -f Makefile.doom`.
