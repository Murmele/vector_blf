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

#include "MostReg.h"

namespace Vector {
namespace BLF {

MostReg::MostReg() :
    ObjectHeader2(),
    channel(),
    subType(),
    reserved(),
    handle(),
    offset(),
    chip(),
    regDataLen(),
    regData()
{
    objectType = ObjectType::MOST_REG;
}

void MostReg::read(AbstractFile & is)
{
    ObjectHeader2::read(is);
    is.read(reinterpret_cast<char *>(&channel), sizeof(channel));
    is.read(reinterpret_cast<char *>(&subType), sizeof(subType));
    is.read(reinterpret_cast<char *>(&reserved), sizeof(reserved));
    is.read(reinterpret_cast<char *>(&handle), sizeof(handle));
    is.read(reinterpret_cast<char *>(&offset), sizeof(offset));
    is.read(reinterpret_cast<char *>(&chip), sizeof(chip));
    is.read(reinterpret_cast<char *>(&regDataLen), sizeof(regDataLen));
    is.read(reinterpret_cast<char *>(regData.data()), regData.size());
}

void MostReg::write(AbstractFile & os)
{
    ObjectHeader2::write(os);
    os.write(reinterpret_cast<char *>(&channel), sizeof(channel));
    os.write(reinterpret_cast<char *>(&subType), sizeof(subType));
    os.write(reinterpret_cast<char *>(&reserved), sizeof(reserved));
    os.write(reinterpret_cast<char *>(&handle), sizeof(handle));
    os.write(reinterpret_cast<char *>(&offset), sizeof(offset));
    os.write(reinterpret_cast<char *>(&chip), sizeof(chip));
    os.write(reinterpret_cast<char *>(&regDataLen), sizeof(regDataLen));
    os.write(reinterpret_cast<char *>(regData.data()), regData.size());
}

size_t MostReg::calculateObjectSize()
{
    size_t size =
        ObjectHeader2::calculateObjectSize() +
        sizeof(channel) +
        sizeof(subType) +
        sizeof(reserved) +
        sizeof(handle) +
        sizeof(offset) +
        sizeof(chip) +
        sizeof(regDataLen) +
        regData.size();

    return size;
}

}
}
