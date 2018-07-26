#ifndef _VADNS_DNS_RFC1035_H_INCLUDED_
#define _VADNS_DNS_RFC1035_H_INCLUDED_

#include <compat/types.h>


/**
 * All the constants are defined according to IANA
 * See:
 *   https://www.iana.org/assignments/dns-parameters/dns-parameters.xhtml
 */

namespace dns {

struct Class {

    // Internet (IN) [RFC1035]
    constexpr static uint16 IN = 0x0001;

    // Chaos (CH) [D. Moon, "Chaosnet", A.I. Memo 628, Massachusetts Institute
    //             of Technology Artificial Intelligence Laboratory, June 1981.]
    constexpr static uint16 CH = 0x0003;

    // Hesiod (HS) [Dyer, S., and F. Hsu, "Hesiod", Project Athena Technical
    //              Plan - Name Service, April 1987.]
    constexpr static uint16 HS = 0x0004;

    // QCLASS NONE [RFC2136]
    constexpr static uint16 NONE = 0x00FE;

    // QCLASS * (ANY) [RFC1035]
    constexpr static uint16 ANY = 0x00FF;
};

struct RRType {

    // A: a host address [RFC1035]
    constexpr static uint16 A = 1;

    // NS: an authoritative name server [RFC1035]
    constexpr static uint16 NS = 2;

    // MD: a mail destination (OBSOLETE - use MX) [RFC1035]
    constexpr static uint16 MD = 3;

    // MF: a mail forwarder (OBSOLETE - use MX) [RFC1035]
    constexpr static uint16 MF = 4;

    // CNAME: the canonical name for an alias [RFC1035]
    constexpr static uint16 CNAME = 5;

    // SOA: marks the start of a zone of authority [RFC1035]
    constexpr static uint16 SOA = 6;
};

}

#endif  // _VADNS_DNS_RFC1035_H_INCLUDED_
