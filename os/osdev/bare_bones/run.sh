#build os
./build.sh
./grub.sh

#quit use ESC + 2 then q + ENTER
qemu-system-i386 -curses -cdrom myos.iso
