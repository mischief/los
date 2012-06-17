
sudo vnconfig vnd0 ./floppyfs.img || exit 1
sudo mount -t ext2fs /dev/vnd0i /mnt || exit 1
