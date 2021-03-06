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

#ifndef INDICATOR_TRANSFER_VIEW_H
#define INDICATOR_TRANSFER_VIEW_H

#include <memory> // std::shared_ptr

namespace unity {
namespace indicator {
namespace transfer {

class Controller;
class Model;

/**
 * \brief Featureless View base class
 */
class View
{
public:
    virtual ~View();
    virtual void set_controller(const std::shared_ptr<Controller>&) =0;
    virtual void set_model(const std::shared_ptr<Model>&) =0;
};

} // namespace transfer
} // namespace indicator
} // namespace unity

#endif // INDICATOR_TRANSFER_VIEW_H
