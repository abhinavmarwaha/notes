# Arch Installation

```
fdisk -l
cfdisk /dev/sda

/dev/sda1 - 1G - for /boot
/dev/sda2 - 5G - for root
/dev/sda3 - 1G - for swap -> make type to swap

mkfs.ext4 /dev/sda1
mkfs.ext4 /dev/sda2
mkswap /dev/sda3
swapon /dev/sda3

mount /dev/sda2 /mnt
mkdir /mnt/boot /mnt/var /mnt/home
mount /dev/sda1 /mnt/boot

pacman -Syy
pacstrap /mnt base base-devel linux linux-firmware nano dhcpcd net-tools grub

genfstab -U /mnt >> /mnt/etc/fstab
```

```
arch-chroot /mnt
nano /etc/locale.gen
<uncomment>
locale-gen
echo LANG=en_US.UTF-8 > /etc/locale.conf
export LANG=en_US.UTF-8
ln -s /usr/share/zoneinfo/America/New_York /etc/localtime

hwclock --systohc --utc
echo arindam-pc > /etc/hostname
systemctl enable dhcpcd
```

```
passwd root

useradd -m -g users -G main -s /bin/bash abhinav
passwd abhinav

nano /etc/sudoers

root ALL=(ALL) ALL
abhinav ALL=(ALL) ALL
```

```
grub-install /dev/sda
grub-mkconfig -o /boot/grub/grub.cfg
mkinitcpio -p linux
exit

umount /mnt/boot
umount /mnt
reboot
```

```
sudo pacman -S --needed xorg

sudo pacman -S --needed xfce4 parole ristretto thunar-archive-plugin thunar-media-tags-plugin xfce4-goodies file-roller network-manager-applet leafpad epdfview galculator lightdm lightdm-gtk-greeter lightdm-gtk-greeter-settings capitaine-cursors arc-gtk-theme xdg-user-dirs-gtk

systemctl enable lightdm
systemctl enable NetworkManager
reboot
```

### VmWare Tools

```
sudo pacman -S open-vm-tools
sudo pacman -Su xf86-input-vmmouse xf86-video-vmware mesa gtk2 gtkmm
sudo echo needs_root_rights=yes >> /etc/X11/Xwrapper.config
sudo systemctl enable vmtoolsd
sudo systemctl start vmtoolsd
```

##### Clipboard

vmx file 

```
isolation.tools.copy.disable = "FALSE"
isolation.tools.dnd.disable = "FALSE"
isolation.tools.paste.disable = "FALSE"
isolation.tools.hgfs.disable = "FALSE"
```

### Utils

```
pacman -S firefox-developer-edition yay
```

### Theming

Install from https://www.xfce-look.org/p/1327720/

```
XFCE themes are available at xfce-look.org. Xfwm themes are stored in /usr/share/themes/theme_name/xfwm4, and set in Settings > Window Manager. GTK themes are stored in /usr/share/themes/theme_name/gtk-2.0 and /usr/share/themes/theme_name/gtk-3.0 and are set in Settings > Appearance.
```

```
Move the extracted folder containing the icons to either ~/.icons or ~/.local/share/icons (user only) or to /usr/share/icons (systemwide).
Optional: run gtk-update-icon-cache -f -t ~/.icons/<theme_name> to update the icon cache.
Select the icon theme using the appropriate configuration tool for your desktop environment or window manager.
```

### Emacs