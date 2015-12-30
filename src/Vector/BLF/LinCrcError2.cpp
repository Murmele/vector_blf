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

#include "LinCrcError2.h"

#include <cstring>

namespace Vector {
namespace BLF {

LinCrcError2::LinCrcError2() :
    ObjectHeader(),
    LinDatabyteTimestampEvent(),
    data(),
    crc(),
    dir(),
    fsmId(),
    fsmState(),
    simulated(),
    reserved1(),
    respBaudrate(),
    reserved2(),
    exactHeaderBaudrate(),
    earlyStopbitOffset(),
    earlyStopbitOffsetResponse()
{
    objectType = ObjectType::LIN_CRC_ERROR2;
}

char * LinCrcError2::read(char * buffer)
{
    size_t size;

    // preceding data
    buffer = ObjectHeader::read(buffer);
    buffer = LinDatabyteTimestampEvent::read(buffer);

    // data
    size = sizeof(data);
    memcpy((void *) &data, buffer, size);
    buffer += size;

    // crc
    size = sizeof(crc);
    memcpy((void *) &crc, buffer, size);
    buffer += size;

    // dir
    size = sizeof(dir);
    memcpy((void *) &dir, buffer, size);
    buffer += size;

    // fsmId
    size = sizeof(fsmId);
    memcpy((void *) &fsmId, buffer, size);
    buffer += size;

    // fsmState
    size = sizeof(fsmState);
    memcpy((void *) &fsmState, buffer, size);
    buffer += size;

    // simulated
    size = sizeof(simulated);
    memcpy((void *) &simulated, buffer, size);
    buffer += size;

    // reserved1
    size = sizeof(reserved1);
    memcpy((void *) &reserved1, buffer, size);
    buffer += size;

    // respBaudrate
    size = sizeof(respBaudrate);
    memcpy((void *) &respBaudrate, buffer, size);
    buffer += size;

    // reserved2
    size = sizeof(reserved2);
    memcpy((void *) &reserved2, buffer, size);
    buffer += size;

    // exactHeaderBaudrate
    size = sizeof(exactHeaderBaudrate);
    memcpy((void *) &exactHeaderBaudrate, buffer, size);
    buffer += size;

    // earlyStopbitOffset
    size = sizeof(earlyStopbitOffset);
    memcpy((void *) &earlyStopbitOffset, buffer, size);
    buffer += size;

    // earlyStopbitOffsetResponse
    size = sizeof(earlyStopbitOffsetResponse);
    memcpy((void *) &earlyStopbitOffsetResponse, buffer, size);
    buffer += size;

    return buffer;
}

char * LinCrcError2::write(char * buffer)
{
    size_t size;

    // preceding data
    buffer = ObjectHeader::write(buffer);
    buffer = LinDatabyteTimestampEvent::write(buffer);

    // data
    size = sizeof(data);
    memcpy(buffer, (void *) &data, size);
    buffer += size;

    // crc
    size = sizeof(crc);
    memcpy(buffer, (void *) &crc, size);
    buffer += size;

    // dir
    size = sizeof(dir);
    memcpy(buffer, (void *) &dir, size);
    buffer += size;

    // fsmId
    size = sizeof(fsmId);
    memcpy(buffer, (void *) &fsmId, size);
    buffer += size;

    // fsmState
    size = sizeof(fsmState);
    memcpy(buffer, (void *) &fsmState, size);
    buffer += size;

    // simulated
    size = sizeof(simulated);
    memcpy(buffer, (void *) &simulated, size);
    buffer += size;

    // reserved1
    size = sizeof(reserved1);
    memcpy(buffer, (void *) &reserved1, size);
    buffer += size;

    // respBaudrate
    size = sizeof(respBaudrate);
    memcpy(buffer, (void *) &respBaudrate, size);
    buffer += size;

    // reserved2
    size = sizeof(reserved2);
    memcpy(buffer, (void *) &reserved2, size);
    buffer += size;

    // exactHeaderBaudrate
    size = sizeof(exactHeaderBaudrate);
    memcpy(buffer, (void *) &exactHeaderBaudrate, size);
    buffer += size;

    // earlyStopbitOffset
    size = sizeof(earlyStopbitOffset);
    memcpy(buffer, (void *) &earlyStopbitOffset, size);
    buffer += size;

    // earlyStopbitOffsetResponse
    size = sizeof(earlyStopbitOffsetResponse);
    memcpy(buffer, (void *) &earlyStopbitOffsetResponse, size);
    buffer += size;

    return buffer;
}

size_t LinCrcError2::calculateObjectSize()
{
    size_t size =
        ObjectHeader::calculateObjectSize() +
        LinDatabyteTimestampEvent::calculateObjectSize() +
        sizeof(data) +
        sizeof(crc) +
        sizeof(dir) +
        sizeof(fsmId) +
        sizeof(fsmState) +
        sizeof(simulated) +
        sizeof(reserved1) +
        sizeof(respBaudrate) +
        sizeof(reserved2) +
        sizeof(exactHeaderBaudrate) +
        sizeof(earlyStopbitOffset) +
        sizeof(earlyStopbitOffsetResponse);

    return size;
}

}
}
