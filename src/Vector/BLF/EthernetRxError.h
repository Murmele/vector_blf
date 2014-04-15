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

#pragma once

#include "platform.h"

#include "VectorTypes.h"
#include "ObjectHeader.h"

#include "vector_blf_export.h"

namespace Vector {
namespace BLF {

/**
 * @brief ETHERNET_RX_ERROR
 *
 * Ethernet RX error frame.
 */
class VECTOR_BLF_EXPORT EthernetRxError : public ObjectHeader
{
public:
    EthernetRxError();
    virtual ~EthernetRxError();

    virtual char * parse(char * buffer);

    /**
     * @brief Length of this structure
     *
     * Length of this structure, without
     * sizeof(ObjectHeader) and without raw data
     * length
     */
    WORD structLength;

    /**
     * The channel of the frame.
     */
    WORD channel;

    /**
     * Direction flag
     */
    enumclass Dir : WORD {
        Rx = 0,
        Tx = 1,
        TxRq = 2
    } dir;

    /**
     * @brief Frame Check Sum
     *
     * Ethernet frame checksum.
     */
    DWORD fcs;

    /**
     * @brief Number of valid raw ethernet data bytes
     *
     * Number of valid raw ethernet data bytes, starting
     * with Target MAC ID.
     */
    WORD frameDataLength;

    /**
     * Error code
     *
     * - 1: Data Length Error
     * - 2: Invalid CRC
     * - 3: Invalid Data received
     * - 4: Collision detected
     */
    DWORD error;

    /**
     * @brief Raw Ethernet frame data
     *
     * Raw Ethernet frame data.
     * Max 1522 data bytes per frame.
     */
    BYTE * frameData;
};

}
}
