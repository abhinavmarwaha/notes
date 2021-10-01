# System wide TOR

* Applications can still learn your computer's hostname, MAC address, serial number, timezone, etc. and those with root privileges can disable the firewall entirely.
*  In other words, transparent torification with iptables protects against accidental connections and DNS leaks by misconfigured software, it is not sufficient to protect against malware or software with serious security vulnerabilities.

### Packages

* tor
* nyx - cli monitor
* torsocks - run commands over tor

### Setup up system-wide proxy

```
systemctl enable tor.service
```

Transparent Torification

configure your system to use 127.0.0.1 as its DNS server 

### Configuration

```
/etc/tor/torrc
```

/etc/iptables/iptables.rules

```
*nat
:PREROUTING ACCEPT [6:2126]
:INPUT ACCEPT [0:0]
:OUTPUT ACCEPT [17:6239]
:POSTROUTING ACCEPT [6:408]

-A PREROUTING ! -i lo -p udp -m udp --dport 53 -j REDIRECT --to-ports 5353
-A PREROUTING ! -i lo -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -j REDIRECT --to-ports 9040
-A OUTPUT -o lo -j RETURN
--ipv4 -A OUTPUT -d 192.168.0.0/16 -j RETURN
-A OUTPUT -m owner --uid-owner "tor" -j RETURN
-A OUTPUT -p udp -m udp --dport 53 -j REDIRECT --to-ports 5353
-A OUTPUT -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -j REDIRECT --to-ports 9040
COMMIT

*filter
:INPUT DROP [0:0]
:FORWARD DROP [0:0]
:OUTPUT DROP [0:0]

-A INPUT -i lo -j ACCEPT
-A INPUT -p icmp -j ACCEPT
-A INPUT -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT
--ipv4 -A INPUT -p tcp -j REJECT --reject-with tcp-reset
--ipv4 -A INPUT -p udp -j REJECT --reject-with icmp-port-unreachable
--ipv4 -A INPUT -j REJECT --reject-with icmp-proto-unreachable
--ipv6 -A INPUT -j REJECT
--ipv4 -A OUTPUT -d 127.0.0.0/8 -j ACCEPT
--ipv4 -A OUTPUT -d 192.168.0.0/16 -j ACCEPT
--ipv6 -A OUTPUT -d ::1/8 -j ACCEPT
-A OUTPUT -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT
-A OUTPUT -m owner --uid-owner "tor" -j ACCEPT
--ipv4 -A OUTPUT -j REJECT --reject-with icmp-port-unreachable
--ipv6 -A OUTPUT -j REJECT
COMMIT
```

**TorDNS** 

```
DNSPort 53
AutomapHostsOnResolve 1
AutomapHostsSuffixes .exit,.onion
ControlPort 9051
```

##### Whonix, or TorVM (over qubesOS)

virtualized torification applications

##### Amnesic solution like Tails

# Terminal

* Terminator

```
CTRL+SHIFT+O – Horizontal Split
CTRL+SHIFT+E – Vertical Split
```

* Tmux 

```
CTRL+B & C -> new session
CTRL+B & <SESSION-NUMBER> -> switch to session
```

* ZSH
* oh my zsh

# Automatic macchanger configuration

```
/etc/NetworkManager/conf.d/wifi_rand_mac.conf

wifi.scan-rand-mac-address=yes
ethernet.cloned-mac-address=random
wifi.cloned-mac-address=stable
```

### Tools

* BURP suite
* Wireshark
* nmap + zenmap
* docker
* gnu-netcat -> swiss army networking tool
* metasploit
* shodan -> iot search engine
* wpscan
* weevely -> remote shell
* Veil-framework -> obsfcucate exploits // use py2exe
* sqlmap -> sql injection
* routersploit -> embedded system exploitation
* recon-ng
* rainbowcrack, johnthereaper
* exploitdb -> find exploits
* honeypot -> http://canarytokens.org/generate
* theHarvester, OSRFramework, dmitry -> OSINT
* https://gtfobins.github.io/ -> linux privelage escalation
* Evil-Droid, apkwash -> embedding payloads into apk's
* Quasar -> window's RAT
* Windows Credentials Editor (WCE) -> post exploitation.
* LaZagne, Empire -> post exploitation
* maltego -> open source intelligence and graphical link analysis tool 

### BlackArch

* smikims-arpspoof

### Other relevent packages

* yay -> AUR helper
* python
* git
* macchanger
* wine -> run windows applications
* snapd -> snap store

### Languages

* ruby / rvm
* python pip
* java
* go