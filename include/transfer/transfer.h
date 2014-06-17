/*
 * Copyright 2014 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *   Charles Kerr <charles.kerr@canonical.com>
 */

#ifndef INDICATOR_TRANSFER_TRANSFER_H
#define INDICATOR_TRANSFER_TRANSFER_H

#include <core/property.h> // parent class

#include <gio/gio.h> // GIcon

#include <ctime> // time_t
#include <memory>
#include <string>
#include <vector>

namespace unity {
namespace indicator {
namespace transfer {

/**
 * \brief Plain Old Data Structure representing a single Transfer
 */
struct Transfer
{
  typedef enum { QUEUED, RUNNING, PAUSED, CANCELED,
                 HASHING, PROCESSING, FINISHED,
                 ERROR } State;
  State state = QUEUED;
  bool can_start() const { return state==QUEUED; }
  bool can_resume() const { return state==PAUSED || state==CANCELED || state==ERROR; }
  bool can_pause() const { return state==RUNNING || state==HASHING || state==PROCESSING; }
  bool can_cancel() const { return state!=FINISHED; }
  bool can_clear() const { return state==FINISHED; }

  // -1 == unknown
  int seconds_left = -1;

  time_t time_started = 0;

  // [0...1]
  float progress = 0.0;

  uint64_t speed_bps = 0;

  uint64_t total_size = 0;

  typedef std::string Id;
  Id id;
  std::string title;
  std::string app_icon;

  // meaningful iff state is ERROR
  std::string error_string;

  // meaningful iff state is FINISHED
  std::string local_path;
};
    
} // namespace transfer
} // namespace indicator
} // namespace unity

#endif // INDICATOR_TRANSFER_TRANSFER_H
