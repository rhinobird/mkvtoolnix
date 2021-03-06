/*
   mkvmerge -- utility for splicing together matroska files
   from component media subtypes

   Distributed under the GPL v2
   see the file COPYING for details
   or visit http://www.gnu.org/copyleft/gpl.html

   packet structure implementation

   Written by Moritz Bunkus <moritz@bunkus.org>.
*/

#include "common/common_pch.h"

#include "common/math.h"
#include "common/track_statistics.h"
#include "merge/cluster_helper.h"
#include "merge/output_control.h"
#include "merge/packet.h"

void
packet_t::normalize_timecodes() {
  // Normalize the timecodes according to the timecode scale.
  unmodified_assigned_timecode = assigned_timecode;
  unmodified_duration          = duration;
  timecode                     = RND_TIMECODE_SCALE(timecode);
  assigned_timecode            = RND_TIMECODE_SCALE(assigned_timecode);
  if (has_duration())
    duration                   = RND_TIMECODE_SCALE(duration);
  if (has_bref())
    bref                       = RND_TIMECODE_SCALE(bref);
  if (has_fref())
    fref                       = RND_TIMECODE_SCALE(fref);
}

void
packet_t::add_extensions(std::vector<packet_extension_cptr> const &new_extensions) {
  brng::copy(new_extensions, std::back_inserter(extensions));
}

void
packet_t::account(track_statistics_c &statistics)
  const {
  statistics.account(assigned_timecode, get_duration(), data->get_size());
}
