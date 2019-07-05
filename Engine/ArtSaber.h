#pragma once
#include"Graphics.h"
#include "Colors.h"

class ArtSaber
{
public:
	ArtSaber() = default;
	void SaberHiltLeft(int x, int y, Graphics& gfx);
	void SaberHiltRight(int x, int y, Graphics& gfx);
	void SaberLeft(int x, int y, Color* c, Graphics& gfx);
	void SaberRight(int x, int y, Color* c, Graphics& gfx);
	void SaberFront(int x, int y, Color* c, Graphics& gfx);
};

