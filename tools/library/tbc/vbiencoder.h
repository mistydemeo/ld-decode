/************************************************************************

    vbiencoder.h

    ld-decode-tools TBC library
    Copyright (C) 2020 Simon Inns

    This file is part of ld-decode-tools.

    ld-decode-tools is free software: you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

************************************************************************/

#ifndef VBIENCODER_H
#define VBIENCODER_H

#include <QDebug>

class VbiEncoder
{
public:
    // VBI Metadata definition
    enum VbiDiscTypes {
        unknownDiscType,    // 0
        clv,                // 1
        cav                 // 2
    };

    // VBI Sound modes
    enum VbiSoundModes {
        stereo,                 // 0
        mono,                   // 1
        audioSubCarriersOff,    // 2
        bilingual,              // 3
        stereo_stereo,          // 4
        stereo_bilingual,       // 5
        crossChannelStereo,     // 6
        bilingual_bilingual,    // 7
        mono_dump,              // 8
        stereo_dump,            // 9
        bilingual_dump,         // 10
        futureUse               // 11
    };

    // Overall container struct for VBI information, with default values
    struct Vbi {
        VbiDiscTypes type = VbiDiscTypes::unknownDiscType;
        QString userCode = "";
        qint32 picNo = -1;
        qint32 chNo = -1;
        qint32 clvHr = -1;
        qint32 clvMin = -1;
        qint32 clvSec = -1;
        qint32 clvPicNo = -1;
        VbiSoundModes soundMode = VbiSoundModes::futureUse;
        VbiSoundModes soundModeAm2 = VbiSoundModes::futureUse;

        bool leadIn = false;
        bool leadOut = false;
        bool picStop = false;
        bool cx = false;
        bool size = false;
        bool side = false;
        bool teletext = false;
        bool dump = false;
        bool fm = false;
        bool digital = false;
        bool parity = false;
        bool copyAm2 = false;
        bool standardAm2 = false;
    };

    VbiEncoder();

    // Get methods
    void getRawVbiData(qint32& _vbi16_1, qint32& _vbi17_1, qint32& _vbi18_1,
               qint32& _vbi16_2, qint32& _vbi17_2, qint32& _vbi18_2);
    Vbi getVbiData();

    // Set methods
    void setVbiData(Vbi _vbi);

private:
    // Define the two fields of VBI data (3 lines each)
    qint32 vbi16_1, vbi17_1, vbi18_1;
    qint32 vbi16_2, vbi17_2, vbi18_2;

    // Define the VBI structure
    Vbi vbi;
};

#endif // VBIENCODER_H