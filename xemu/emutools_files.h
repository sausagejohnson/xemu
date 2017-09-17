/* Xemu - Somewhat lame emulation (running on Linux/Unix/Windows/OSX, utilizing
   SDL2) of some 8 bit machines, including the Commodore LCD and Commodore 65
   and some Mega-65 features as well.
   Copyright (C)2016,2017 LGB (Gábor Lénárt) <lgblgblgb@gmail.com>

   The goal of emutools.c is to provide a relative simple solution
   for relative simple emulators using SDL2.

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

#ifndef __XEMU_COMMON_EMUTOOLS_FILES_H_INCLUDED
#define __XEMU_COMMON_EMUTOOLS_FILES_H_INCLUDED

extern void *xemu_load_buffer_p;
extern char xemu_load_filepath[PATH_MAX];

extern int xemu_load_file ( const char *filename, void *store_to, int min_size, int max_size, const char *cry );
extern int xemu_open_file ( const char *filename, int mode, int *mode2, char *filepath_back );
extern ssize_t xemu_safe_read ( int fd, void *buffer, size_t length );
extern ssize_t xemu_safe_write ( int fd, const void *buffer, size_t length );

#if defined(HAVE_XEMU_INSTALLER) && !defined(HAVE_XEMU_EXEC_API)
#define HAVE_XEMU_EXEC_API
#endif

#ifdef HAVE_XEMU_EXEC_API
#define XEMUEXEC_STILL_RUNNING 259
#ifdef _WIN32
typedef void* xemuexec_process_t;
#else
typedef int xemuexec_process_t;
#endif
extern xemuexec_process_t xemuexec_run ( char *const args[] );
extern int xemuexec_check_status ( xemuexec_process_t pid, int wait );
#endif

#endif