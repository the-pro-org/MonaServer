/* 
	Copyright 2013 Mona - mathieu.poux[a]gmail.com
 
	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License received along this program for more
	details (or else see http://www.gnu.org/licenses/).

	This file is a part of Mona.
*/

#pragma once

#include "Mona/Mona.h"
#include "Mona/UDPSender.h"
#include "Mona/RTMFP/RTMFP.h"

namespace Mona {

class RTMFPSender : public UDPSender, virtual Object {
public:
	RTMFPSender();
	
	RTMFPEngine		encoder;
	UInt32			farId;
	MemoryWriter	packet;

	bool			available() { return UDPSender::available() && packet.length() >= RTMFP_MIN_PACKET_SIZE; }

private:
	const UInt8*	begin(bool displaying) { return displaying ? (packet.begin() + 6) : packet.begin(); }
	UInt32			size(bool displaying) { return displaying ? (packet.length() - 6) : packet.length(); }
	
	bool			run(Exception& ex);

	UInt8			_buffer[RTMFP_PACKET_SEND_SIZE];
	
};



} // namespace Mona