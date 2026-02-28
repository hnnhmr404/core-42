This project has been created as part of the 42 curriculum by hbinti-d.

# Description
Born2beRoot is a project that will introduce student to the world of virtualization. Student will learn how to install a debian or rocky server (i choose debian). The project involves partitioning using encrypted LVM, ssh configuration, firewall setup, user and group management, strict password and sudo policies, and a monitoring script. The goal is to understand the basics of Linux system management and security.

# Instructions
1. Download debian.
2. Set up partition with encrypted LVM.
3. Set firewall, sudo policy and password policy.
4. Create a monitoring script.

## Operating system: Debian
I choose Debian because it is suitable for anyone who is new to system administration as it has minimal server installation.However, Debian packages may be older compared to Rocky.

## Partitioning 
check using: lsblk

NAME				MAJ:MIN	 RM  SIZE  RO  TYPE  MOUNTPOINTS
sda                       	  8:0     0    8G   0  disk
├─sda1                    	  8:1     0  833M   0  part  /boot
├─sda2                    	  8:2	  0    1K   0  part
└─sda5                    	  8:5	  0  7.2G   0  part
  └─sda5_crypt             	254:0     0  7.2G   0  crypt
    ├─hbinti-d42--vg-root       254:1     0  6.4G   0  lvm   /
    └─hbinti-d42--vg-swap_1     254:2     0  780M   0  lvm   [SWAP]
sr0				 11:0     1 1024M   0  rom

## Service installed
- SSH (port 4242, root login disabled)
- UFW firewall
- AppArmor enabled
- Cron (for monitoring script)

## Firewall
UFW only allows port 4242 when enable. it will refused other connection.

## Sudo policy
- 3 authentication attempts
- Custom error message
- All sudo actions logged in /var/log/sudo/
- TTY required
- Restricted secure path

## Password policy
- Minimum 10 characters
- Must include uppercase, lowercase, and a digit 
- No more than 3 identical consecutive characters
- Cannot contain the username
- Expires every 30 days
- Minimum 2 days between password changes
- 7-day warning before expiration
- At least 7 characters must differ from the previous password (except root)

## Monitoring Script
- OS and kernel information
- CPU (physical and virtual) usage
- RAM and disk usage
- Last boot time
- LVM status
- Active connections and users
- Network information
- Number of sudo commands executed

# Comparisons

## Debian vs Rocky Linux
Debian is easier and uses AppArmor. It focuses on stability and simplicity, while Rocky Linux is stricter and uses SELinux. It focuses on enterprise production and environments

## AppArmor vs SELinux
AppArmor is path-based and easier to setup while SELinux is label-based and more complex but stricter.

## UFW vs firewalld
UFW is straightfoward and rule-based while firewalld uses zones and provides more advanced control.

## VirtualBox vs UTM
VirtualBox is designed for cross-platform while UTM is mainly used on macOS.

# Resources
- Debian Handbook
- LUKS, LVM, SSH, UFW, and AppArmor documentation
- Youtube guide
- manual pages: pam, pwquality.conf
- https://noreply.gitbook.io/born2beroot

### Use of AI
- Conceptual explanations of system administration topics (VMs, SSH, LVM, encryption)
- Error messages causes clarification
- Linux commands and configuration files explaination
