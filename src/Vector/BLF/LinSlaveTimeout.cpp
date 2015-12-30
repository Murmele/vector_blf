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

#include "LinSlaveTimeout.h"

#include <cstring>

namespace Vector {
namespace BLF {

LinSlaveTimeout::LinSlaveTimeout() :
    ObjectHeader(),
    channel(),
    slaveId(),
    stateId(),
    followStateId()
{
    objectType = ObjectType::LIN_SLV_TIMEOUT;
}

char * LinSlaveTimeout::read(char * buffer)
{
    size_t size;

    // preceding data
    buffer = ObjectHeader::read(buffer);

    // channel
    size = sizeof(channel);
    memcpy((void *) &channel, buffer, size);
    buffer += size;

    // slaveId
    size = sizeof(slaveId);
    memcpy((void *) &slaveId, buffer, size);
    buffer += size;

    // stateId
    size = sizeof(stateId);
    memcpy((void *) &stateId, buffer, size);
    buffer += size;

    // followStateId
    size = sizeof(followStateId);
    memcpy((void *) &followStateId, buffer, size);
    buffer += size;

    return buffer;
}

char * LinSlaveTimeout::write(char * buffer)
{
    size_t size;

    // preceding data
    buffer = ObjectHeader::write(buffer);

    // channel
    size = sizeof(channel);
    memcpy(buffer, (void *) &channel, size);
    buffer += size;

    // slaveId
    size = sizeof(slaveId);
    memcpy(buffer, (void *) &slaveId, size);
    buffer += size;

    // stateId
    size = sizeof(stateId);
    memcpy(buffer, (void *) &stateId, size);
    buffer += size;

    // followStateId
    size = sizeof(followStateId);
    memcpy(buffer, (void *) &followStateId, size);
    buffer += size;

    return buffer;
}

size_t LinSlaveTimeout::calculateObjectSize()
{
    size_t size =
        ObjectHeader::calculateObjectSize() +
        sizeof(channel) +
        sizeof(slaveId) +
        sizeof(stateId) +
        sizeof(followStateId);

    return size;
}

}
}
