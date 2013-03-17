#!/bin/sh
echo "Mounting floppy..."

sudo mount -o loop ./los.img /mnt

echo "Copying kernels..."

strip ./kernel
sudo cp ./kernel /mnt/los

#echo "Copy init.lua"
#sudo cp ./init.lua /mnt/init.lua

echo "Unmounting floppy..."

sudo umount /mnt

