#!/bin/bash

DEFAULT_USERNAME="marcelo"
USERNAME="madias-m42"
HOSTNAME="madias-m42"

#__Before the script execution, the mannually execution of the commands bellow is a must__
# su root
# apt install sudo
# sudo groupadd user42
# sudo usermod -aG sudo $DEFAULT_USER
# sudo usermod -aG user42 $DEFAULT_USER
# reboot
#__END__

# Configure sudo
echo "Configuring Sudo rules"
sudo mkdir /var/log/sudo
echo 'Defaults    secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin”' | sudo EDITOR='tee -a' visudo
echo 'Defaults    passwd_tries = 3' | sudo EDITOR='tee -a' visudo
echo 'Defaults    badpass_message = "Wrong Password!"' | sudo EDITOR='tee -a' visudo
echo 'Defaults    logfile = "/var/log/sudo/sudo.log"' | sudo EDITOR='tee -a' visudo
echo 'Defaults    log_input, log_output' | sudo EDITOR='tee -a' visudo
echo 'Defaults    iolog_dir = "/var/log/sudo"' | sudo EDITOR='tee -a' visudo
echo 'Defaults    requiretty' | sudo EDITOR='tee -a' visudo

# Configure SSH
echo "Configuring SSH server"
sudo apt -y install openssh-server
sudo cat >> /etc/ssh/sshd_config << EOF
Port 4242
PermitRootLogin no
PasswordAuthentication yes
EOF

#Configure Firewall (UFW)
echo "Configuring UFW"
sudo apt -y install ufw
sudo ufw enable
sudo ufw allow 4242

#Configure User and Password Quality
echo "Configuring user and password quality..."
sed -i 's/PASS_MAX_DAYS 99999/PASS_MAX_DAYS 30/g' /etc/login.defs
sed -i 's/PASS_MIN_DAYS 2/PASS_MAX_DAYS 30/g' /etc/login.defs
sed -i 's/PASS_WARN_AGE 7/PASS_MAX_DAYS 30/g' /etc/login.defs
chage --mindays 2 --maxdays 30 --warndays 7 $DEFAULT_USERNAME
chage --mindays 2 --maxdays 30 --warndays 7 root
if ! grep $USERNAME /etc/passwd; then
	sudo useradd -m $USERNAME
fi

if ! grep sudo /etc/group | grep $USERNAME; then
	sudo usermod -aG sudo $USERNAME
fi

if ! grep user42 /etc/group | grep $USERNAME; then
	sudo usermod -aG user42 $USERNAME
fi
chsh -s /bin/bash/ $USERNAME
sudo apt -y install libpam-pwquality
sudo sed -i 's/password	requisite			pam_pwquality.so retry=3/password	requisite		pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 lcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root/g' /etc/pam.d/common-password

#Change Hostname
echo "Changing Hostname..."
hostnamectl set-hostname $HOSTNAME
sed -i "s/127.0.1.1	debian/127.0.1.1	$HOSTNAME/g" /etc/hosts

#Install netstat
sudo apt -y install netstat

#Create monitoring.sh
touch /usr/local/bin/monitoring.sh
chmod 777 /usr/local/bin/monitoring.sh
cat >> /usr/local/bin/monitoring.sh << 'EOF'
#!/bin/bash

ARCH=$(uname -a)
CORE=$(lscpu | grep 'per socket' | awk '{print $4}')
THREADS=$(nproc)
U_RAM=$(free --mega | grep Mem | awk '{print $3}')
T_RAM=$(free --mega | grep Mem | awk '{print $2}')
RAM_USAGE=$(free --mega | grep Mem | awk '{printf "%.2f%%", $3/$2*100}')
U_DISK=$(df | grep root | awk '{printf "%.0f", $3/1000}')
T_DISK=$(df -h | grep root | awk '{printf "%.0f", $2}')
DISK_USAGE=$(df -h | grep root | awk '{printf "%d%%", $5}')
FREE_CPU=$(vmstat 1 1| tail -1 | awk '{printf $15}')
U_CPU=$(expr 100 - $FREE_CPU)
CPU_LOAD=$(printf "%.1f%%" $U_CPU)
LAST_BOOT=$(uptime -s | rev | cut -d':' -f2- | rev)
LVM=$(if lsblk | grep -q "lvm"; then echo "yes"; else echo "no"; fi)
TCP_CONN=$(netstat -an | grep ESTAB | wc -l)
USER_LOG_COUNT=$(who | wc -l)
IP_VF=$(hostname -I)
MAC=$(cat /sys/class/net/*/address | awk 'NR==1')
SUDO_CMD_COUNT=$(cat /var/log/sudo/sudo.log | wc -l )

wall "
	#Architecture: $ARCH
	#CPU physical : $CORE
	#vCPU : $THREADS
	#Memory Usage: $U_RAM/${T_RAM}MB ($RAM_USAGE)
	#Disk Usage: $U_DISK/${T_DISK}Gb ($DISK_USAGE)
	#CPU load: $CPU_LOAD
	#Last boot: $LAST_BOOT
	#LVM use: $LVM
	#Connections TCP : $TCP_CONN
	#User log: $USER_LOG_COUNT
	#Network: IP $IP_VF ($MAC)
	#Sudo: $SUDO_CMD_COUNT cmd
"
EOF
touch /usr/local/bin/sleep.sh
chmod 777 /usr/local/bin/sleep.sh
cat >> /usr/local/bin/sleep.sh << 'EOF'
#!/bin/bash

TMP=$(uptime -s | cut -d ":" -f 2)
MIN=$((TMP%10))
SEC=$(uptime -s | cut -d ":" -f 3)

sleep  ${MIN}m ${SEC}s

/usr/local/bin/monitoring.sh
EOF
{ crontab -l -u root; echo '*/10 * * * * /usr/local/bin/sleep.sh'; } | crontab -u root -

#_____After the Script execution, don't forget to run the fallowing commands:___
#ssh-keygen -t rsa
#passwd $USERNAME
#passwd root
