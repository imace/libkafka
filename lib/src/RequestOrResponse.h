//////////////////////////////////////////////////////////////////
//                                                              //
// libkafka - C/C++ client for Apache Kafka v0.8+               //
//                                                              //
// David Tompkins -- 8/8/2013                                   //
// http://dt.org/                                               //
//                                                              //
// Copyright (c) 2013 by David Tompkins.                        //
//                                                              //
//////////////////////////////////////////////////////////////////
//                                                              //
// This program is free software; you can redistribute it       //
// and/or modify it under the terms of the GNU General Public   //
// License as published by the Free Software Foundation.        //
//                                                              //
// This program is distributed in the hope that it will be      //
// useful, but WITHOUT ANY WARRANTY; without even the implied   //
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR      //
// PURPOSE. See the GNU General Public License for more details //
//                                                              //
// You should have received a copy of the GNU General Public    //
// License along with this program; if not, write to the Free   //
// Software Foundation, Inc., 59 Temple Place, Suite 330,       //
// Boston, MA 02111-1307 USA                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef REQUESTORRESPONSE_H
#define REQUESTORRESPONSE_H

#include <string>
#include <Debug.h>
#include <Packet.h>
#include <WireFormatter.h>
#include <PacketWriter.h>

namespace LibKafka {

class RequestOrResponse : public WireFormatter, public PacketWriter
{
  public:

    RequestOrResponse();
    RequestOrResponse(unsigned char *buffer, bool releaseBuffer = false);
    ~RequestOrResponse();

    int size(bool includeProtocolSizeFieldLength = true) const;

    unsigned char* toWireFormat(bool updatePacketSize = true);
    int getWireFormatSize(bool includePacketSize = true);
};

std::ostream& operator<< (std::ostream& os, const RequestOrResponse& r);

}; // namespace LibKafka

#endif
