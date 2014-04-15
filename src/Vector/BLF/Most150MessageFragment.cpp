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

#include "Most150MessageFragment.h"

namespace Vector {
namespace BLF {

Most150MessageFragment::Most150MessageFragment() :
    ObjectHeader2(),
    channel(),
    dummy1(),
    ackNack(),
    validMask(),
    sourceAdr(),
    destAdr(),
    pAck(),
    cAck(),
    priority(),
    pIndex(),
    crc(),
    dataLen(),
    dataLenAnnounced(),
    firstDataLen(),
    firstData(nullptr)
{
}

Most150MessageFragment::~Most150MessageFragment()
{
    delete[] firstData;
    firstData = nullptr;
}

char * Most150MessageFragment::parse(char * buffer)
{
    size_t size;

    // previous data
    buffer = ObjectHeader2::parse(buffer);

#if 0
    // channel
    size = sizeof(channel);
    memcpy((char *) &channel, buffer, size);
    buffer += size;
#else
    // @todo
#endif

    return buffer;
}

size_t Most150MessageFragment::calculateObjectSize()
{
    size_t size =
            ObjectHeader2::calculateObjectSize() +
            sizeof(channel) +
            sizeof(dummy1) +
            sizeof(ackNack) +
            sizeof(validMask) +
            sizeof(sourceAdr) +
            sizeof(destAdr) +
            sizeof(pAck) +
            sizeof(cAck) +
            sizeof(priority) +
            sizeof(pIndex) +
            sizeof(crc) +
            sizeof(dataLen) +
            sizeof(dataLenAnnounced) +
            sizeof(firstDataLen) +
            firstDataLen;

    return size;
}

}
}
