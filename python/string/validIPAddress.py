#!/usr/bin/env python3
#coding=utf-8
import re
from ipaddress import ip_address, IPv4Address
'''leetcode issue 468'''

class Solution:
    #def validIPAddress(self, IP: str) -> str:
        #try:
        #    return "IPv4" if(type(ip_address(IP)) == IPv4Address) else "IPv6"
        #except ValueError:
        #    return "Neither"
    chunk_IPv4 = r'([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])'
    patten_IPv4 = re.compile(r'^(' + chunk_IPv4 + r'\.){3}' + chunk_IPv4 + r'$')

    chunk_IPv6 = r'([0-9a-fA-F]{1,4})'
    patten_IPv6 = re.compile(r'^(' + chunk_IPv6 + r'\:){7}' + chunk_IPv6 + r'$')

    def validIPAddress(self, IP: str) -> str:
        if '.' in IP:
            return "IPv4" if self.patten_IPv4.match(IP) else "Neither"
        if ':' in IP:
            return "IPv6" if self.patten_IPv6.match(IP) else "Neither"
        return "Neither"
