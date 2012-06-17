
echo "Mounting floppy..."

sh ./scripts/mount.sh

echo "Copying kernels..."

sudo cp ./kernel /mnt/

echo "Unmounting floppy..."

sh ./scripts/umount.sh
