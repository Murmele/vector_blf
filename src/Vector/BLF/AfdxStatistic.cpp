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

#include "AfdxStatistic.h"

namespace Vector {
namespace BLF {

AfdxStatistic::AfdxStatistic() :
    ObjectHeader(),
    channel(),
    flags(),
    rxPacketCount(),
    rxByteCount(),
    txPacketCount(),
    txByteCount(),
    collisionCount(),
    errorCount(),
    statDroppedRedundantPacketCount(),
    statRedundantErrorPacketCount(),
    statIntegrityErrorPacketCount(),
    statAvrgPeriodMsec(),
    statAvrgJitterMysec(),
    vlid(),
    statDuration()
{
    objectType = ObjectType::AFDX_STATISTIC;
}

void AfdxStatistic::read(AbstractFile & is)
{
    ObjectHeader::read(is);
    is.read(reinterpret_cast<char *>(&channel), sizeof(channel));
    is.read(reinterpret_cast<char *>(&flags), sizeof(flags));
    is.read(reinterpret_cast<char *>(&rxPacketCount), sizeof(rxPacketCount));
    is.read(reinterpret_cast<char *>(&rxByteCount), sizeof(rxByteCount));
    is.read(reinterpret_cast<char *>(&txPacketCount), sizeof(txPacketCount));
    is.read(reinterpret_cast<char *>(&txByteCount), sizeof(txByteCount));
    is.read(reinterpret_cast<char *>(&collisionCount), sizeof(collisionCount));
    is.read(reinterpret_cast<char *>(&errorCount), sizeof(errorCount));
    is.read(reinterpret_cast<char *>(&statDroppedRedundantPacketCount), sizeof(statDroppedRedundantPacketCount));
    is.read(reinterpret_cast<char *>(&statRedundantErrorPacketCount), sizeof(statRedundantErrorPacketCount));
    is.read(reinterpret_cast<char *>(&statIntegrityErrorPacketCount), sizeof(statIntegrityErrorPacketCount));
    is.read(reinterpret_cast<char *>(&statAvrgPeriodMsec), sizeof(statAvrgPeriodMsec));
    is.read(reinterpret_cast<char *>(&statAvrgJitterMysec), sizeof(statAvrgJitterMysec));
    is.read(reinterpret_cast<char *>(&vlid), sizeof(vlid));
    is.read(reinterpret_cast<char *>(&statDuration), sizeof(statDuration));
}

void AfdxStatistic::write(AbstractFile & os)
{
    ObjectHeader::write(os);
    os.write(reinterpret_cast<char *>(&channel), sizeof(channel));
    os.write(reinterpret_cast<char *>(&flags), sizeof(flags));
    os.write(reinterpret_cast<char *>(&rxPacketCount), sizeof(rxPacketCount));
    os.write(reinterpret_cast<char *>(&rxByteCount), sizeof(rxByteCount));
    os.write(reinterpret_cast<char *>(&txPacketCount), sizeof(txPacketCount));
    os.write(reinterpret_cast<char *>(&txByteCount), sizeof(txByteCount));
    os.write(reinterpret_cast<char *>(&collisionCount), sizeof(collisionCount));
    os.write(reinterpret_cast<char *>(&errorCount), sizeof(errorCount));
    os.write(reinterpret_cast<char *>(&statDroppedRedundantPacketCount), sizeof(statDroppedRedundantPacketCount));
    os.write(reinterpret_cast<char *>(&statRedundantErrorPacketCount), sizeof(statRedundantErrorPacketCount));
    os.write(reinterpret_cast<char *>(&statIntegrityErrorPacketCount), sizeof(statIntegrityErrorPacketCount));
    os.write(reinterpret_cast<char *>(&statAvrgPeriodMsec), sizeof(statAvrgPeriodMsec));
    os.write(reinterpret_cast<char *>(&statAvrgJitterMysec), sizeof(statAvrgJitterMysec));
    os.write(reinterpret_cast<char *>(&vlid), sizeof(vlid));
    os.write(reinterpret_cast<char *>(&statDuration), sizeof(statDuration));
}

size_t AfdxStatistic::calculateObjectSize()
{
    size_t size =
        ObjectHeader::calculateObjectSize() +
        sizeof(channel) +
        sizeof(flags) +
        sizeof(rxPacketCount) +
        sizeof(rxByteCount) +
        sizeof(txPacketCount) +
        sizeof(txByteCount) +
        sizeof(collisionCount) +
        sizeof(errorCount) +
        sizeof(statDroppedRedundantPacketCount) +
        sizeof(statRedundantErrorPacketCount) +
        sizeof(statIntegrityErrorPacketCount) +
        sizeof(statAvrgPeriodMsec) +
        sizeof(statAvrgJitterMysec) +
        sizeof(vlid) +
        sizeof(statDuration);

    return size;
}

}
}
