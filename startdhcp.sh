#!/bin/sh
kill `cat /var/run/dhcpd.pid`


/usr/sbin/dhcpd
#more /var/state/dhcp/dhcpd.leases
ps -ef | grep dhcpd*

