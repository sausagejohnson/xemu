/* Test-case for a very simple and inaccurate Commodore VIC-20 emulator using SDL2 library.
   Copyright (C)2016 LGB (Gábor Lénárt) <lgblgblgb@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

#ifndef __LGB_VIC6561_H_INCLUDED
#define __LGB_VIC6561_H_INCLUDED

/* Defines the X ("dotpos") and Y ("scanline") parameters of the visible (emulated) screen area */
#define SCREEN_FIRST_VISIBLE_SCANLINE	 28
#define SCREEN_LAST_VISIBLE_SCANLINE	311
#define SCREEN_FIRST_VISIBLE_DOTPOS	 38
#define SCREEN_LAST_VISIBLE_DOTPOS	261

/* Usual (X/Y) origin of the screen (left bottom corner) if VIC-I X/Y origin registers are zero */
// maybe SCANLINE ORIGIN is 38 ... I guess :)
//#define SCREEN_ORIGIN_SCANLINE	 38
//#define SCREEN_ORIGIN_DOTPOS		 12
#define SCREEN_ORIGIN_SCANLINE		  0
#define SCREEN_ORIGIN_DOTPOS		 12

#define LAST_SCANLINE			311
#define CYCLES_PER_SCANLINE		 71

extern Uint32 vic_palette[16];				// VIC palette with native SCREEN_FORMAT aware way. Must be initialized by the emulator
extern int scanline;					// scanline counter, must be maintained by the emulator, as increment, checking for all scanlines done, etc

extern Uint8 cpu_vic_reg_read ( int addr );
extern void cpu_vic_reg_write ( int addr, Uint8 data );
extern void vic_init ( Uint8 **lo8_pointers, Uint8 **hi4_pointers );
extern void vic_render_line ( void );
extern void vic_vsync ( int relock_texture );


#endif
