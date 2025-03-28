/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

// This file is based on engines/wintermute/base/fonts/base_font_truetype.h/.cpp

#ifndef ZVISION_TRUETYPE_FONT_H
#define ZVISION_TRUETYPE_FONT_H

#include "graphics/font.h"
#include "graphics/pixelformat.h"

namespace Graphics {
struct Surface;
}

namespace ZVision {

struct FontStyle {
	const char *zorkFont;
	const char *fontBase;
	const char *liberationFontBase;
};

#define FONT_COUNT 9

class ZVision;

// Styled TTF
class StyledTTFont {
public:
	StyledTTFont(ZVision *engine);
	~StyledTTFont();

	enum {
		TTF_STYLE_BOLD = 0x01,
		TTF_STYLE_ITALIC = 0x02,
		TTF_STYLE_UNDERLINE = 0x04,
		TTF_STYLE_STRIKETHROUGH = 0x08,
		TTF_STYLE_SHARP = 0x10
	};

private:
	ZVision *_engine;
	Graphics::Font *_font;
	int _lineHeight;
	uint _style;
	Common::String _fontName;

public:
	bool loadFont(const Common::String &fontName, int32 point, uint style);

	int getFontHeight();
	int getMaxCharWidth();
	int getCharWidth(uint16 chr);
	int getKerningOffset(byte left, byte right);

	void drawChar(Graphics::Surface *dst, uint16 chr, int x, int y, uint32 color);

	void drawString(Graphics::Surface *dst, const Common::String &str, int x, int y, int w, uint32 color, Graphics::TextAlign align = Graphics::kTextAlignLeft);
	int getStringWidth(const Common::String &str);

	Graphics::Surface *renderSolidText(const Common::String &str, uint32 color);

	bool isLoaded() {
		return _font != NULL;
	};
};

} // End of namespace ZVision

#endif
