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

#include "LinShortOrSlowResponse.h"

namespace Vector {
namespace BLF {

LinShortOrSlowResponse::LinShortOrSlowResponse() :
    ObjectHeader(),
    LinDatabyteTimestampEvent(),
    numberOfRespBytes(),
    respBytes(),
    slowResponse(),
    interruptedByBreak(),
    reserved()
{
    objectType = ObjectType::LIN_SHORT_OR_SLOW_RESPONSE;
}

void LinShortOrSlowResponse::read(AbstractFile & is)
{
    ObjectHeader::read(is);
    LinDatabyteTimestampEvent::read(is);
    is.read(reinterpret_cast<char *>(&numberOfRespBytes), sizeof(numberOfRespBytes));
    is.read(reinterpret_cast<char *>(respBytes.data()), respBytes.size());
    is.read(reinterpret_cast<char *>(&slowResponse), sizeof(slowResponse));
    is.read(reinterpret_cast<char *>(&interruptedByBreak), sizeof(interruptedByBreak));
    is.read(reinterpret_cast<char *>(&reserved), sizeof(reserved));
}

void LinShortOrSlowResponse::write(AbstractFile & os)
{
    ObjectHeader::write(os);
    LinDatabyteTimestampEvent::write(os);
    os.write(reinterpret_cast<char *>(&numberOfRespBytes), sizeof(numberOfRespBytes));
    os.write(reinterpret_cast<char *>(respBytes.data()), respBytes.size());
    os.write(reinterpret_cast<char *>(&slowResponse), sizeof(slowResponse));
    os.write(reinterpret_cast<char *>(&interruptedByBreak), sizeof(interruptedByBreak));
    os.write(reinterpret_cast<char *>(&reserved), sizeof(reserved));
}

size_t LinShortOrSlowResponse::calculateObjectSize()
{
    size_t size =
        ObjectHeader::calculateObjectSize() +
        LinDatabyteTimestampEvent::calculateObjectSize() +
        sizeof(numberOfRespBytes) +
        respBytes.size() +
        sizeof(slowResponse) +
        sizeof(interruptedByBreak) +
        sizeof(reserved);

    return size;
}

}
}
