// ap_Color.h: interface for the Color class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(Aggplus_COLOR_H__E1E9CE27_8A7F_4B37_94E2_E555FDF70A29__INCLUDED_)
#define Aggplus_COLOR_H__E1E9CE27_8A7F_4B37_94E2_E555FDF70A29__INCLUDED_

#include "ap_AggPlusEnums.h"
#include "include\agg_color_rgba.h"

namespace Aggplus
{

		class Color  
		{
		public:
				Color() { Argb = 0xFF000000; } //Black;
				//Color values are not premultiplied.
				Color(BYTE r, BYTE g, BYTE b) { Argb = MakeARGB(255, r, g, b); }
				Color(BYTE a, BYTE r, BYTE g, BYTE b) { Argb = MakeARGB(a, r, g, b); }
				Color(ARGB argb) { Argb = argb; }

				BYTE GetAlpha() const { return (BYTE) (Argb >> AlphaShift); }
				BYTE GetA() const { return GetAlpha(); }
				BYTE GetRed() const   { return (BYTE) (Argb >> RedShift); }
				BYTE GetR() const { return GetRed(); }
				BYTE GetGreen() const { return (BYTE) (Argb >> GreenShift); }
				BYTE GetG() const { return GetGreen(); }
				BYTE GetBlue() const { return (BYTE) (Argb >> BlueShift); }
				BYTE GetB() const { return GetBlue(); }

				ARGB GetValue() const { return Argb; }
				void SetValue(ARGB argb) { Argb = argb; }
				COLORREF ToCOLORREF() const { return RGB(GetRed(), GetGreen(), GetBlue()); }
				void SetFromCOLORREF(COLORREF rgb)		{	Argb = MakeARGB(255, GetRValue(rgb), GetGValue(rgb), GetBValue(rgb));		}
			 

		public:
		// Shift count and bit mask for A, R, G, B components
				enum
				{
					AlphaShift  = 24,
					RedShift    = 16,
					GreenShift  = 8,
					BlueShift   = 0
				};
				enum
				{
					AlphaMask   = 0xff000000,
					RedMask     = 0x00ff0000,
					GreenMask   = 0x0000ff00,
					BlueMask    = 0x000000ff
				};

				// Assemble A, R, G, B values into a 32-bit integer
				static ARGB MakeARGB(BYTE a, BYTE r, BYTE g, BYTE b)
				{
					return (((ARGB) (b) <<  BlueShift) |
						((ARGB) (g) << GreenShift) |
						((ARGB) (r) <<   RedShift) |
						((ARGB) (a) << AlphaShift));
				}

				//AGG converter
				inline agg::rgba8 GetAggColor() const { return(agg::rgba8(GetBlue(), GetGreen(), GetRed(), GetAlpha())); }
		
		protected:

				ARGB Argb;
		};

}

#endif // !defined(Aggplus_COLOR_H__E1E9CE27_8A7F_4B37_94E2_E555FDF70A29__INCLUDED_)
