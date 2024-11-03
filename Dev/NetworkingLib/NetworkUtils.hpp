#pragma once

namespace Network
{
    enum class AddressFamily : int32_t
    {
		/* The address family is unspecified. */
		UNSPECIFIED = 0, 
		
		/* The Internet Protocol version 4 (IPv4) address family. */
		INET = 2,

		/* The IPX / SPX address family.
		 * This address family is only supported if the NWLink IPX / SPX NetBIOS Compatible Transport protocol is installed.
		 * This address family is not supported on Windows Vista and later. */
		IPX = 6,

		/* The AppleTalk address family.
		 * This address family is only supported if the AppleTalk protocol is installed.
		 * This address family is not supported on Windows Vista and later. */
		APPLETALK = 16,
		
		/* The NetBIOS address family. 
		 * This address family is only supported if the Windows Sockets provider for NetBIOS is installed.
		 * The Windows Sockets provider for NetBIOS is supported on 32 - bit versions of Windows.This provider is installed by default on 32 - bit versions of Windows.
		 * The Windows Sockets provider for NetBIOS is not supported on 64 - bit versions of windows including Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003, or Windows XP.
		 * The Windows Sockets provider for NetBIOS only supports sockets where the type parameter is set to SOCK_DGRAM.
		 * The Windows Sockets provider for NetBIOS is not directly related to the NetBIOS programming interface.The NetBIOS programming interface is not supported on Windows Vista, Windows Server 2008, and later. */
		NETBIOS = 17,
		
		/* The Internet Protocol version 6 (IPv6) address family. */
		INET6 = 23,
		
		/* The Infrared Data Association(IrDA) address family.
		 * This address family is only supported if the computer has an infrared port and driver installed. */
		IRDA = 26,
		
		/* The Bluetooth address family.
		 * This address family is supported on Windows XP with SP2 or later if the computer has a Bluetooth adapter and driver installed. */
		BTH = 32,
    };

	enum class SocketType : int32_t
	{
		/* A socket type that provides sequenced, reliable, two - way, connection - based byte streams with an OOB data transmission mechanism.
		 * This socket type uses the Transmission Control Protocol (TCP) for the Internet address family (AF_INET or AF_INET6). */
		STREAM = 1,

		/* A socket type that supports datagrams, which are connectionless, unreliable buffers of a fixed (typically small) maximum length. 
		 * This socket type uses the User Datagram Protocol (UDP) for the Internet address family (AF_INET or AF_INET6). */
		DGRAM = 2,

		/* A socket type that provides a raw socket that allows an application to manipulate the next upper-layer protocol header.
		 * To manipulate the IPv4 header, the IP_HDRINCL socket option must be set on the socket. 
		 * To manipulate the IPv6 header, the IPV6_HDRINCL socket option must be set on the socket. */
		RAW = 3,

		/* A socket type that provides a reliable message datagram.
		 * An example of this type is the Pragmatic General Multicast (PGM) multicast protocol implementation in Windows, often referred to as reliable multicast programming.
		 * (https://learn.microsoft.com/en-us/windows/desktop/WinSock/reliable-multicast-programming--pgm-)
		 * This type value is only supported if the Reliable Multicast Protocol is installed.*/
		RDM = 4,

		/* A socket type that provides a pseudo-stream packet based on datagrams. */
		SEQPACKET = 5,
	};

	enum class Protocol : int32_t
	{
		/* The Internet Control Message Protocol (ICMP).
		 * This is a possible value when the af parameter is AF_UNSPEC, AF_INET, or AF_INET6 and the type parameter is SOCK_RAW or unspecified.
		 * This protocol value is supported on Windows XP and later. */
		IP_ICMP = 1,
		
		/* The Internet Group Management Protocol (IGMP).
		 * This is a possible value when the af parameter is AF_UNSPEC, AF_INET, or AF_INET6 and the type parameter is SOCK_RAW or unspecified.
		 * This protocol value is supported on Windows XP and later. */
		IP_IGMP = 2,
		
		/* The Bluetooth Radio Frequency Communications (Bluetooth RFCOMM) protocol.
		 * This is a possible value when the af parameter is AF_BTH and the type parameter is SOCK_STREAM.
		 * This protocol value is supported on Windows XP with SP2 or later. */
		BTH_RFCOMM = 3,
		
		/* The Transmission Control Protocol (TCP).
		 * This is a possible value when the af parameter is AF_INET or AF_INET6 and the type parameter is SOCK_STREAM. */
		IP_TCP = 6,
		
		/* The User Datagram Protocol (UDP).
		 * This is a possible value when the af parameter is AF_INET or AF_INET6 and the type parameter is SOCK_DGRAM. */
		IP_UDP = 17,

		/* The Internet Control Message Protocol Version 6 (ICMPv6).
		 * This is a possible value when the af parameter is AF_UNSPEC, AF_INET, or AF_INET6 and the type parameter is SOCK_RAW or unspecified.
		 * This protocol value is supported on Windows XP and later. */
		IP_ICMPV6 = 58,

		/* The PGM protocol for reliable multicast.
		 * This is a possible value when the af parameter is AF_INET and the type parameter is SOCK_RDM.On the Windows SDK released for Windows Vista and later, this protocol is also called IPPROTO_PGM.
		 * This protocol value is only supported if the Reliable Multicast Protocol is installed. */
		IP_RM = 113,
	};
}
