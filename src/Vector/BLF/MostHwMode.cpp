/*
 * Copyright (C) 2013 Tobias Lorenz.
 * Contact: tobias.lorenz@gmx.net
 *
 * This file is part of Tobias Lorenz's Toolkit.
 *
 * Commercial License Usage
 * Licensees holding valid commercial licenses may use this file in
 * accordance with the commercial license agreement provided with the
 * Software or, alternatively, in accordance with the terms contained in
 * a written agreement between you and Tobias Lorenz.
 *
 * GNU General Public License 3.0 Usage
 * Alternatively, this file may be used under the terms of the GNU
 * General Public License version 3.0 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPL included in the
 * packaging of this file.  Please review the following information to
 * ensure the GNU General Public License version 3.0 requirements will be
 * met: http://www.gnu.org/copyleft/gpl.html.
 */

#include "MostHwMode.h"

#include <cstring>

namespace Vector {
namespace BLF {

MostHwMode::MostHwMode() :
    ObjectHeader2(),
    channel(),
    reserved1(),
    hwMode(),
    hwModeMask()
{
    objectType = ObjectType::MOST_HWMODE;
}

char * MostHwMode::read(char * buffer)
{
    size_t size;

    // preceding data
    buffer = ObjectHeader2::read(buffer);

    // channel
    size = sizeof(channel);
    memcpy((void *) &channel, buffer, size);
    buffer += size;

    // reserved1
    size = sizeof(reserved1);
    memcpy((void *) &reserved1, buffer, size);
    buffer += size;

    // hwMode
    size = sizeof(hwMode);
    memcpy((void *) &hwMode, buffer, size);
    buffer += size;

    // hwModeMask
    size = sizeof(hwModeMask);
    memcpy((void *) &hwModeMask, buffer, size);
    buffer += size;

    return buffer;
}

char * MostHwMode::write(char * buffer)
{
    size_t size;

    // preceding data
    buffer = ObjectHeader2::write(buffer);

    // channel
    size = sizeof(channel);
    memcpy(buffer, (void *) &channel, size);
    buffer += size;

    // reserved1
    size = sizeof(reserved1);
    memcpy(buffer, (void *) &reserved1, size);
    buffer += size;

    // hwMode
    size = sizeof(hwMode);
    memcpy(buffer, (void *) &hwMode, size);
    buffer += size;

    // hwModeMask
    size = sizeof(hwModeMask);
    memcpy(buffer, (void *) &hwModeMask, size);
    buffer += size;

    return buffer;
}

size_t MostHwMode::calculateObjectSize()
{
    size_t size =
        ObjectHeader2::calculateObjectSize() +
        sizeof(channel) +
        sizeof(reserved1) +
        sizeof(hwMode) +
        sizeof(hwModeMask);

    return size;
}

}
}
