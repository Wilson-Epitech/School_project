#!/bin/bash

red='\033[31m'
reset='\033[0m'
echo -e "${red}Script Installation Arch Linux ${reset}"
sleep 1
fdisk -l
echo -e "${red}Quel est le nom du disque ? (ex : /dev/sda) ${reset} "
read disk_label

## Création des partitions ##
cfdisk $disk_label
pvcreate /dev/sda2
vgcreate arch /dev/sda2

echo "${red}quel taille pour la partition root ?${reset}"
read root_size
lvcreate -L $root_size arch -n root

echo "${red}quel taille pour la partition home ?${reset}"
read home_size
lvcreate -L $home_size arch -n home

echo "${red}quel taille pour la partition boot ?${reset}"
read boot_size
lvcreate -L $boot_size arch -n boot

echo "${red}quel taille pour la partition swap ?${reset}"
read swap_size
lvcreate -L $swap_size arch -n swap

## FORMAT PARTITION ##
mkfs.ext2 /dev/mapper/arch-boot
mkfs.ext4 /dev/mapper/arch-root
mkfs.ext4 /dev/mapper/arch-home
mkfs.fat -F32 /dev/sda1
mkswap /dev/mapper/arch-swap
swapon /dev/mapper/arch-swap
sleep 1


## MONTER LES PARTITIONS ##
mount /dev/mapper/arch-root /mnt
mkdir /mnt/home
mkdir /mnt/boot
mount /dev/mapper/arch-home /mnt/home
mount /dev/mapper/arch-boot /mnt/boot
touch /mnt/rapport.txt
sleep 1
cp script_arch/mkinitcpio.conf /mnt/
echo "partition lvm creer + formatage + partition montée" > /mnt/rapport.txt

## INSTALLATION DU SYS MINIMUM ##
pacstrap -i /mnt base base-devel linux linux-firmware nano vim emacs sudo --noconfirm
echo "partition lvm creer + formatage + partition montée + install du sys" > /mnt/rapport.txt


## GENERER TABLE DE PARTITION ##
genfstab -U -p /mnt >> /mnt/etc/fstab
echo "partition lvm creer + formatage + partition montée + install du sys + table de partition génerer" > /mnt/rapport.txt

## /tp /mnt mdrr van de geek ##
arch-chroot /mnt

## SETUPE TIMEZONE... ##
cp /etc/locale.gen /etc/locale_backup.gen
echo fr_FR.UTF-8 UTF-8 > /etc/locale.gen
ln -sf /usr/share/zoneinfo/Europe/Paris /etc/localtime
hwclock --systohc --utc
date
sleep 1
echo "partition lvm creer + formatage + partition montée + install du sys + table de partition génerer" > rapport.txt

## NETWORK MANAGER ##
pacman -Sy networkmanager --noconfirm
systemctl enable NetworkManager
echo "partition lvm creer + formatage + partition montée + install du sys + table de partition génerer + networkmanager" > rapport.txt


## INSTALL GRUB ##
pacman -Sy grub efibootmgr --noconfirm
mkdir /boot/efi
mount /dev/sda1 /boot/efi
grub-install --target=x86_64-efi --bootloader-id=GRUB --efi-directory=/boot/efi --removable
grub-mkconfig -o /boot/grub/grub.cfg
echo "partition lvm creer + formatage + partition montée + install du sys + table de partition génerer + networkmanager + install grub" > rapport.txt

## INSTALL LVM2 ##
pacman -Sy lvm2 --noconfirm
mv /etc/mkinitcpio.conf /etc/mkinitcpio_backup.conf
cp mkinitcpio.conf /etc/
echo "partition lvm creer + formatage + partition montée + install du sys + table de partition génerer + networkmanager + install grub + modif lvm2 cpio.conf" > rapport.txt
exit
reboot

##if [ $disk_label = "/dev/sda" ];
##then
##    echo "carré au top"
##fi
##read name
##if [ &name = "wilson" ]; then
##    echo "carré"
##fi