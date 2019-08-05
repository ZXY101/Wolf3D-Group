Wolf-3D

Wolf-3D is a group project made by zxy101, Rubzy0422 and Nick-OC97.

compiling Wolf is always fun ..
if you are running a linux system make sure you have these dependencies installed
libfreetype6-dev make gcc pkg-config libx11-dev libxext-dev libasound2-dev libpulse-dev

Ubuntu / Raspberry Pi:
sudo apt-get install libfreetype6-dev make gcc pkg-config libx11-dev libxext-dev libasound2-dev libpulse-dev

Arch: 
sudo pacman -S libfreetype6-dev make gcc pkg-config libx11-dev libxext-dev libasound2-dev libpulse-dev


if you have brew installed on your mac there is no need to install brew with make
Installing:
	MAC on 42:
		make Brew;make pkg-config;make SDL
	Arch:
		make SDL
	Ubuntu:
		make SDL
	Raspberry Pi:
		make SDL


please note Wolf-3d is being tested and perfected on Mac and Ubuntu 18.04
have fun !