/*
   mkvmerge -- utility for splicing together matroska files
   from component media subtypes

   Distributed under the GPL
   see the file COPYING for details
   or visit http://www.gnu.org/copyleft/gpl.html

   some hacks that the author might want to use

   Written by Moritz Bunkus <moritz@bunkus.org>.
*/

#ifndef __MTX_COMMON_HACKS_H
#define __MTX_COMMON_HACKS_H

#include "common/os.h"

#include <string>

// Some hacks that are configurable via command line but which should ONLY!
// be used by the author.
#define ENGAGE_SPACE_AFTER_CHAPTERS          0
#define ENGAGE_NO_CHAPTERS_IN_META_SEEK      1
#define ENGAGE_NO_META_SEEK                  2
#define ENGAGE_LACING_XIPH                   3
#define ENGAGE_LACING_EBML                   4
#define ENGAGE_NATIVE_MPEG4                  5
#define ENGAGE_NO_VARIABLE_DATA              6
#define ENGAGE_FORCE_PASSTHROUGH_PACKETIZER  7
#define ENGAGE_WRITE_HEADERS_TWICE           8
#define ENGAGE_ALLOW_AVC_IN_VFW_MODE         9
#define ENGAGE_KEEP_BITSTREAM_AR_INFO       10
#define ENGAGE_NO_SIMPLE_BLOCKS             11
#define ENGAGE_OLD_AAC_CODECID              12
#define ENGAGE_USE_CODEC_STATE_ONLY         13
#define ENGAGE_ENABLE_TIMECODE_WARNING      14
#define ENGAGE_MERGE_TRUEHD_FRAMES          15
#define ENGAGE_REMOVE_BITSTREAM_AR_INFO     16
#define ENGAGE_VOBSUB_SUBPIC_STOP_CMDS      17
#define ENGAGE_MAX_IDX                      ENGAGE_VOBSUB_SUBPIC_STOP_CMDS

void MTX_DLL_API engage_hacks(const std::string &hacks);
bool MTX_DLL_API hack_engaged(unsigned int id);

#endif // __MTX_COMMON_HACKS_H
